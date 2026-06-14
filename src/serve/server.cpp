#include "afrilang/serve.hpp"

#include "afrilang/cli.hpp"
#include "afrilang/codegen.hpp"
#include "afrilang/formatter.hpp"
#include "afrilang/sandbox.hpp"
#include "afrilang/semantic.hpp"

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cctype>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace fs = std::filesystem;

namespace afrilang {

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

static std::string runSource(const std::string& source) {
    const std::string sessionPath = "/tmp/afrilang_playground.afr";
    const std::string cppPath = "/tmp/afrilang_playground.generated.cpp";
    const std::string exePath = "/tmp/afrilang_playground.bin";

    try {
        SourceManager sources;
        sources.addFile(sessionPath, source);
        auto program = parseSourceProgram(source, sessionPath, &sources);
        SemanticAnalyzer analyzer(*program, &sources, sessionPath);
        const SemanticResult semantic = analyzer.analyze();

        CodeGenerator codegen(*program, semantic);
        codegen.setRuntimeDir((fs::path(detectAfrilangRoot()) / "runtime").string());
        codegen.setSourceFile(sessionPath);

        if (!codegen.compileToExecutable(cppPath, exePath)) {
            return "{\"ok\":false,\"output\":\"Erreur de compilation g++\",\"exitCode\":1}";
        }

        const ExecResult exec = execWithTimeout(exePath, {}, 5);

        std::ostringstream json;
        json << "{\"ok\":" << (exec.exitCode == 0 && !exec.timedOut ? "true" : "false")
             << ",\"output\":\"" << jsonEscape(exec.output);
        if (exec.timedOut) {
            json << "\\n[timeout: exécution limitée à 5s]";
        }
        json << "\",\"exitCode\":" << exec.exitCode << "}";
        return json.str();
    } catch (const CompileError& e) {
        return "{\"ok\":false,\"output\":\"" + jsonEscape(e.format()) + "\",\"exitCode\":1}";
    }
}

static std::string formatSource(const std::string& source) {
    const std::string sessionPath = "/tmp/afrilang_playground.afr";
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
    response << "Access-Control-Allow-Origin: *\r\n";
    response << "Connection: close\r\n\r\n";
    response << body;
    const std::string data = response.str();
    send(client, data.data(), data.size(), 0);
}

static void handleClient(int client, const fs::path& siteRoot) {
    char buffer[8192];
    const ssize_t n = recv(client, buffer, sizeof(buffer) - 1, 0);
    if (n <= 0) return;
    buffer[n] = '\0';

    std::string request(buffer);
    const auto lineEnd = request.find("\r\n");
    const std::string line = request.substr(0, lineEnd);
    const auto sp1 = line.find(' ');
    const auto sp2 = line.find(' ', sp1 + 1);
    if (sp1 == std::string::npos || sp2 == std::string::npos) return;

    const std::string method = line.substr(0, sp1);
    std::string path = urlDecode(line.substr(sp1 + 1, sp2 - sp1 - 1));

    if (method == "POST" && path == "/api/run") {
        const auto bodyPos = request.find("\r\n\r\n");
        const std::string body = bodyPos != std::string::npos ? request.substr(bodyPos + 4) : "";
        const std::string result = runSource(jsonGetSource(body));
        sendResponse(client, 200, "application/json", result);
        return;
    }

    if (method == "POST" && path == "/api/fmt") {
        const auto bodyPos = request.find("\r\n\r\n");
        const std::string body = bodyPos != std::string::npos ? request.substr(bodyPos + 4) : "";
        const std::string result = formatSource(jsonGetSource(body));
        sendResponse(client, 200, "application/json", result);
        return;
    }

    if (path == "/") path = "/index.html";
    const fs::path filePath = siteRoot / path.substr(1);
    if (!fs::exists(filePath) || !fs::is_regular_file(filePath)) {
        sendResponse(client, 404, "text/plain", "404 Not Found");
        return;
    }

    sendResponse(client, 200, contentTypeFor(filePath), readFile(filePath));
}

int runHttpServer(int port, const std::string& siteRoot) {
    const int serverFd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverFd < 0) {
        std::cerr << "Erreur: impossible de créer le socket.\n";
        return 1;
    }

    int opt = 1;
    setsockopt(serverFd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(static_cast<uint16_t>(port));

    if (bind(serverFd, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) < 0) {
        std::cerr << "Erreur: bind sur le port " << port << ".\n";
        close(serverFd);
        return 1;
    }

    if (listen(serverFd, 8) < 0) {
        close(serverFd);
        return 1;
    }

    std::cout << "AFRILANG playground: http://localhost:" << port << "/\n";
    std::cout << "Appuyez sur Ctrl+C pour arrêter.\n";

    while (true) {
        sockaddr_in clientAddr{};
        socklen_t len = sizeof(clientAddr);
        const int client = accept(serverFd, reinterpret_cast<sockaddr*>(&clientAddr), &len);
        if (client < 0) continue;
        handleClient(client, siteRoot);
        close(client);
    }

    close(serverFd);
    return 0;
}

} // namespace afrilang
