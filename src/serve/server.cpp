#include "afrilang/serve.hpp"

#include "afrilang/cli.hpp"
#include "afrilang/codegen.hpp"
#include "afrilang/formatter.hpp"
#include "afrilang/sandbox.hpp"
#include "afrilang/security.hpp"
#include "afrilang/semantic.hpp"
#include "afrilang/target.hpp"

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cctype>
#include <ctime>
#include <cstring>
#include <random>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

namespace fs = std::filesystem;

namespace afrilang {

namespace {

struct RateBucket {
    int count = 0;
    std::time_t windowStart = 0;
};

std::unordered_map<std::string, RateBucket> g_rateLimits;

bool checkRateLimit(const std::string& clientIp) {
    const auto limits = securityLimits(SecurityContext::NetworkServe);
    const std::time_t now = std::time(nullptr);
    RateBucket& bucket = g_rateLimits[clientIp];
    if (now - bucket.windowStart >= 60) {
        bucket.count = 0;
        bucket.windowStart = now;
    }
    ++bucket.count;
    return bucket.count <= limits.maxServeRequestsPerMinute;
}

std::string clientIpString(const sockaddr_in& addr) {
    char buf[INET_ADDRSTRLEN] = {};
    inet_ntop(AF_INET, &addr.sin_addr, buf, sizeof(buf));
    return buf;
}

struct WasmSession {
    fs::path jsPath;
    fs::path wasmPath;
    std::time_t created = 0;
};

std::unordered_map<std::string, WasmSession> g_wasmSessions;

std::string newWasmSessionId() {
    static std::mt19937 rng(static_cast<unsigned>(std::time(nullptr)));
    std::uniform_int_distribution<int> dist(0, 15);
    std::string id;
    id.reserve(16);
    for (int i = 0; i < 16; ++i) {
        id += "0123456789abcdef"[dist(rng)];
    }
    return id;
}

void cleanupWasmSessions() {
    const std::time_t now = std::time(nullptr);
    for (auto it = g_wasmSessions.begin(); it != g_wasmSessions.end();) {
        if (now - it->second.created > 600) {
            fs::remove(it->second.jsPath);
            fs::remove(it->second.wasmPath);
            it = g_wasmSessions.erase(it);
        } else {
            ++it;
        }
    }
    while (g_wasmSessions.size() > 16) {
        auto it = g_wasmSessions.begin();
        fs::remove(it->second.jsPath);
        fs::remove(it->second.wasmPath);
        g_wasmSessions.erase(it);
    }
}

} // namespace

static std::string urlDecode(const std::string& value) {
    std::string out;
    for (std::size_t i = 0; i < value.size(); ++i) {
        if (value[i] == '%' && i + 2 < value.size()) {
            out += static_cast<char>(std::strtol((value.substr(i + 1, 2)).c_str(), nullptr, 16));
            i += 2;
        } else if (value[i] == '+') {
            out += ' ';
        } else {
            out += value[i];
        }
    }
    return out;
}

static std::string jsonGetSource(const std::string& body) {
    const auto key = body.find("\"source\"");
    if (key == std::string::npos) return {};
    const auto colon = body.find(':', key);
    const auto quote = body.find('"', colon);
    if (quote == std::string::npos) return {};
    std::string value;
    for (std::size_t i = quote + 1; i < body.size(); ++i) {
        if (body[i] == '\\' && i + 1 < body.size()) {
            char c = body[i + 1];
            if (c == 'n') value += '\n';
            else if (c == 't') value += '\t';
            else if (c == '"') value += '"';
            else if (c == '\\') value += '\\';
            else value += c;
            ++i;
            continue;
        }
        if (body[i] == '"') break;
        value += body[i];
    }
    return value;
}

static std::string jsonEscape(const std::string& s) {
    std::string out;
    for (char c : s) {
        switch (c) {
            case '"': out += "\\\""; break;
            case '\\': out += "\\\\"; break;
            case '\n': out += "\\n"; break;
            case '\r': out += "\\r"; break;
            case '\t': out += "\\t"; break;
            default: out += c; break;
        }
    }
    return out;
}

static std::size_t parseContentLength(const std::string& headers) {
    const std::string key = "content-length:";
    std::istringstream stream(headers);
    std::string line;
    while (std::getline(stream, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();
        std::string lower = line;
        for (char& c : lower) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        if (lower.rfind(key, 0) == 0) {
            return static_cast<std::size_t>(std::stoul(lower.substr(key.size())));
        }
    }
    return 0;
}

static std::string readRequestBody(int client, const std::string& headers,
                                   const std::string& initialBody) {
    const std::size_t maxBody = securityLimits(SecurityContext::NetworkServe).maxServeBodyBytes;
    const std::size_t contentLength = parseContentLength(headers);
    if (contentLength > maxBody) {
        securityViolation("Corps HTTP trop volumineux (max " + std::to_string(maxBody) + ")");
    }

    std::string body = initialBody;
    while (body.size() < contentLength) {
        char buffer[4096];
        const std::size_t remaining = contentLength - body.size();
        const std::size_t chunk = std::min(remaining, sizeof(buffer));
        const ssize_t n = recv(client, buffer, chunk, 0);
        if (n <= 0) break;
        body.append(buffer, static_cast<std::size_t>(n));
        if (body.size() > maxBody) {
            securityViolation("Corps HTTP trop volumineux");
        }
    }
    return body;
}

static std::string runSource(const std::string& source, const std::string& crossTarget) {
    validateSourceContent(source, "playground", SecurityContext::NetworkServe);

    const std::string sessionPath = secureTempPath("playground.afr");
    const std::string cppPath = secureTempPath("playground.generated.cpp");
    const bool wasmBuild = isWasmTarget(crossTarget);
    const std::string exePath = wasmBuild
        ? secureTempPath("playground.js")
        : secureTempPath("playground.bin");

    try {
        SourceManager sources;
        sources.addFile(sessionPath, source);
        auto program = parseSourceProgram(source, sessionPath, &sources);
        SemanticAnalyzer analyzer(*program, &sources, sessionPath);
        const SemanticResult semantic = analyzer.analyze();

        CodeGenerator codegen(*program, semantic);
        codegen.setRuntimeDir((fs::path(detectAfrilangRoot()) / "runtime").string());
        codegen.setSourceFile(sessionPath);
        codegen.setCrossTarget(normalizeCrossTarget(crossTarget));

        if (!codegen.compileToExecutable(cppPath, exePath)) {
            const char* compiler = wasmBuild ? "em++" : "g++";
            return "{\"ok\":false,\"output\":\"Erreur de compilation " +
                   std::string(compiler) +
                   (wasmBuild ? " (installez Emscripten)" : "") +
                   "\",\"exitCode\":1}";
        }

        const auto limits = securityLimits(SecurityContext::NetworkServe);
        ProcessConfig config;
        config.timeoutSeconds = limits.execTimeoutSeconds;
        config.maxMemoryMb = limits.maxMemoryMb;
        config.maxCpuSeconds = limits.maxCpuSeconds;
        config.maxOutputBytes = limits.maxOutputBytes;
        config.limitProcessCount = true;

        const ExecResult exec = wasmBuild
            ? execSandboxed("node", {exePath}, config)
            : execSandboxed(exePath, {}, config);

        std::ostringstream json;
        json << "{\"ok\":" << (exec.exitCode == 0 && !exec.timedOut ? "true" : "false")
             << ",\"output\":\"" << jsonEscape(exec.output);
        if (exec.timedOut) {
            json << "\\n[timeout: exécution limitée à " << limits.execTimeoutSeconds << "s]";
        }
        if (exec.outputTruncated) {
            json << "\\n[sortie tronquée]";
        }
        json << "\",\"exitCode\":" << exec.exitCode << "}";
        return json.str();
    } catch (const CompileError& e) {
        return "{\"ok\":false,\"output\":\"" + jsonEscape(e.format()) + "\",\"exitCode\":1}";
    }
}

static std::string buildWasmForBrowser(const std::string& source) {
    validateSourceContent(source, "playground wasm", SecurityContext::NetworkServe);
    cleanupWasmSessions();

    const std::string id = newWasmSessionId();
    const std::string sessionPath = secureTempPath("wasm_" + id + ".afr");
    const std::string cppPath = secureTempPath("wasm_" + id + ".cpp");
    const std::string jsPath = secureTempPath("wasm_" + id + ".js");

    try {
        SourceManager sources;
        sources.addFile(sessionPath, source);
        auto program = parseSourceProgram(source, sessionPath, &sources);
        SemanticAnalyzer analyzer(*program, &sources, sessionPath);
        const SemanticResult semantic = analyzer.analyze();

        CodeGenerator codegen(*program, semantic);
        codegen.setRuntimeDir((fs::path(detectAfrilangRoot()) / "runtime").string());
        codegen.setSourceFile(sessionPath);
        codegen.setCrossTarget("wasm32");
        codegen.setWasmEnvironment("web");

        if (!codegen.compileToExecutable(cppPath, jsPath)) {
            return "{\"ok\":false,\"output\":\"Erreur de compilation em++ "
                   "(installez Emscripten)\",\"exitCode\":1}";
        }

        const fs::path wasmPath = fs::path(jsPath).replace_extension(".wasm");
        if (!fs::exists(wasmPath)) {
            return "{\"ok\":false,\"output\":\"Fichier .wasm introuvable après compilation\","
                   "\"exitCode\":1}";
        }

        g_wasmSessions[id] = WasmSession{jsPath, wasmPath, std::time(nullptr)};
        return "{\"ok\":true,\"id\":\"" + id + "\"}";
    } catch (const CompileError& e) {
        return "{\"ok\":false,\"output\":\"" + jsonEscape(e.format()) + "\",\"exitCode\":1}";
    }
}

static std::string formatSource(const std::string& source) {
    validateSourceContent(source, "playground fmt", SecurityContext::NetworkServe);
    const std::string sessionPath = secureTempPath("playground_fmt.afr");
    try {
        SourceManager sources;
        sources.addFile(sessionPath, source);
        auto program = parseSourceProgram(source, sessionPath, &sources);
        Formatter formatter(*program);
        const std::string formatted = formatter.format();
        return "{\"ok\":true,\"source\":\"" + jsonEscape(formatted) + "\"}";
    } catch (const CompileError& e) {
        return "{\"ok\":false,\"output\":\"" + jsonEscape(e.format()) + "\"}";
    }
}

static std::string contentTypeFor(const fs::path& path) {
    const std::string ext = path.extension().string();
    if (ext == ".html") return "text/html; charset=utf-8";
    if (ext == ".css") return "text/css; charset=utf-8";
    if (ext == ".js") return "application/javascript; charset=utf-8";
    if (ext == ".json") return "application/json; charset=utf-8";
    if (ext == ".svg") return "image/svg+xml";
    if (ext == ".wasm") return "application/wasm";
    if (ext == ".png") return "image/png";
    return "text/plain; charset=utf-8";
}

static std::string readFile(const fs::path& path) {
    std::ifstream in(path, std::ios::binary);
    if (!in) return {};
    std::ostringstream buffer;
    buffer << in.rdbuf();
    return buffer.str();
}

static void sendResponse(int client, int status, const std::string& contentType,
                         const std::string& body) {
    std::ostringstream response;
    response << "HTTP/1.1 " << status << " OK\r\n";
    response << "Content-Type: " << contentType << "\r\n";
    response << "Content-Length: " << body.size() << "\r\n";
    response << "X-Content-Type-Options: nosniff\r\n";
    response << "X-Frame-Options: DENY\r\n";
    response << "Content-Security-Policy: default-src 'self'; script-src 'self' 'unsafe-inline'; "
                "style-src 'self' 'unsafe-inline'\r\n";
    if (!allowPublicServe()) {
        response << "Access-Control-Allow-Origin: http://127.0.0.1\r\n";
    } else {
        response << "Access-Control-Allow-Origin: *\r\n";
    }
    response << "Connection: close\r\n\r\n";
    response << body;
    const std::string data = response.str();
    send(client, data.data(), data.size(), 0);
}

static void handleClient(int client, const fs::path& siteRoot, const std::string& clientIp) {
    if (!checkRateLimit(clientIp)) {
        sendResponse(client, 429, "application/json",
                     "{\"ok\":false,\"output\":\"Trop de requêtes — réessayez plus tard\","
                     "\"exitCode\":1}");
        return;
    }

    char buffer[8192];
    const ssize_t n = recv(client, buffer, sizeof(buffer) - 1, 0);
    if (n <= 0) return;
    buffer[n] = '\0';

    std::string request(buffer, static_cast<std::size_t>(n));
    const auto headerEnd = request.find("\r\n\r\n");
    const std::string headers = headerEnd != std::string::npos ? request.substr(0, headerEnd) : "";
    const std::string initialBody =
        headerEnd != std::string::npos ? request.substr(headerEnd + 4) : "";

    const auto lineEnd = request.find("\r\n");
    const std::string line = request.substr(0, lineEnd);
    const auto sp1 = line.find(' ');
    const auto sp2 = line.find(' ', sp1 + 1);
    if (sp1 == std::string::npos || sp2 == std::string::npos) return;

    const std::string method = line.substr(0, sp1);
    std::string path = urlDecode(line.substr(sp1 + 1, sp2 - sp1 - 1));

    if (method == "POST" && path == "/api/run") {
        try {
            const std::string body = readRequestBody(client, headers, initialBody);
            const std::string result = runSource(jsonGetSource(body), "native");
            sendResponse(client, 200, "application/json", result);
        } catch (const CompileError& e) {
            sendResponse(client, 413, "application/json",
                         "{\"ok\":false,\"output\":\"" + jsonEscape(e.format()) +
                             "\",\"exitCode\":1}");
        }
        return;
    }

    if (method == "POST" && path == "/api/run/wasm") {
        try {
            const std::string body = readRequestBody(client, headers, initialBody);
            const std::string result = runSource(jsonGetSource(body), "wasm32");
            sendResponse(client, 200, "application/json", result);
        } catch (const CompileError& e) {
            sendResponse(client, 413, "application/json",
                         "{\"ok\":false,\"output\":\"" + jsonEscape(e.format()) +
                             "\",\"exitCode\":1}");
        }
        return;
    }

    if (method == "POST" && path == "/api/fmt") {
        try {
            const std::string body = readRequestBody(client, headers, initialBody);
            const std::string result = formatSource(jsonGetSource(body));
            sendResponse(client, 200, "application/json", result);
        } catch (const CompileError& e) {
            sendResponse(client, 413, "application/json",
                         "{\"ok\":false,\"output\":\"" + jsonEscape(e.format()) + "\"}");
        }
        return;
    }

    if (method == "POST" && path == "/api/build/wasm") {
        try {
            const std::string body = readRequestBody(client, headers, initialBody);
            const std::string result = buildWasmForBrowser(jsonGetSource(body));
            sendResponse(client, 200, "application/json", result);
        } catch (const CompileError& e) {
            sendResponse(client, 413, "application/json",
                         "{\"ok\":false,\"output\":\"" + jsonEscape(e.format()) +
                             "\",\"exitCode\":1}");
        }
        return;
    }

    if (method == "GET" && path.rfind("/api/wasm/", 0) == 0) {
        const std::string rest = path.substr(10);
        const auto slash = rest.find('/');
        if (slash != std::string::npos) {
            const std::string id = rest.substr(0, slash);
            const std::string file = rest.substr(slash + 1);
            const auto it = g_wasmSessions.find(id);
            if (it != g_wasmSessions.end()) {
                fs::path filePath;
                if (file == "module.js") filePath = it->second.jsPath;
                else if (file == "module.wasm") filePath = it->second.wasmPath;
                if (!filePath.empty() && fs::exists(filePath)) {
                    sendResponse(client, 200, contentTypeFor(filePath), readFile(filePath));
                    return;
                }
            }
        }
        sendResponse(client, 404, "text/plain", "404 Not Found");
        return;
    }

    if (path == "/") path = "/index.html";
    const fs::path filePath = fs::weakly_canonical(siteRoot / path.substr(1));
    if (!isPathInsideRoot(fs::weakly_canonical(siteRoot).string(), filePath.string()) ||
        !fs::exists(filePath) || !fs::is_regular_file(filePath)) {
        sendResponse(client, 404, "text/plain", "404 Not Found");
        return;
    }

    sendResponse(client, 200, contentTypeFor(filePath), readFile(filePath));
}

int runHttpServer(int port, const std::string& siteRoot) {
    if (isSecureMode() && !allowNetworkServe()) {
        std::cerr << "Erreur: le serveur playground est désactivé en mode sécurisé.\n";
        std::cerr << "Définir AFRILANG_ALLOW_SERVE=1 pour l'activer (localhost uniquement).\n";
        return 1;
    }

    secureSandboxRoot();

    const int serverFd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverFd < 0) {
        std::cerr << "Erreur: impossible de créer le socket.\n";
        return 1;
    }

    int opt = 1;
    setsockopt(serverFd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(static_cast<uint16_t>(port));
    if (allowPublicServe()) {
        addr.sin_addr.s_addr = INADDR_ANY;
        std::cout << "ATTENTION: serveur exposé sur toutes les interfaces (AFRILANG_SERVE_PUBLIC=1).\n";
    } else {
        inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);
    }

    if (bind(serverFd, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) < 0) {
        std::cerr << "Erreur: bind sur le port " << port << ".\n";
        close(serverFd);
        cleanupSecureSandbox();
        return 1;
    }

    if (listen(serverFd, 8) < 0) {
        close(serverFd);
        cleanupSecureSandbox();
        return 1;
    }

    const char* bindHost = allowPublicServe() ? "0.0.0.0" : "127.0.0.1";
    std::cout << "AFRILANG playground: http://" << bindHost << ":" << port << "/\n";
    std::cout << "Appuyez sur Ctrl+C pour arrêter.\n";

    while (true) {
        sockaddr_in clientAddr{};
        socklen_t len = sizeof(clientAddr);
        const int client = accept(serverFd, reinterpret_cast<sockaddr*>(&clientAddr), &len);
        if (client < 0) continue;
        handleClient(client, siteRoot, clientIpString(clientAddr));
        close(client);
    }

    close(serverFd);
    cleanupSecureSandbox();
    return 0;
}

} // namespace afrilang
