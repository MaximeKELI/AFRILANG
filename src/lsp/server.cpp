#include "afrilang/lsp.hpp"

#include "afrilang/diagnostics.hpp"
#include "afrilang/formatter.hpp"
#include "afrilang/semantic.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace afrilang {

static const std::vector<std::string> kKeywords = {
    "class", "function", "end", "create", "if", "then", "else", "say",
    "while", "do", "repeat", "times", "for", "each", "in", "return",
    "interface", "implements", "test", "assert", "error", "extends",
    "returns", "module", "use", "import", "record", "field", "number",
    "text", "bool", "list", "true", "false", "stop", "skip",
    "explain", "expliquer", "dire", "si", "alors", "sinon", "fin"
};

static std::string jsonEscape(const std::string& s) {
    std::string out;
    out.reserve(s.size());
    for (char c : s) {
        switch (c) {
            case '"':  out += "\\\""; break;
            case '\\': out += "\\\\"; break;
            case '\n': out += "\\n"; break;
            case '\r': out += "\\r"; break;
            case '\t': out += "\\t"; break;
            default:   out += c; break;
        }
    }
    return out;
}

static std::string jsonGetString(const std::string& json, const std::string& key) {
    const std::string needle = "\"" + key + "\":\"";
    const auto pos = json.find(needle);
    if (pos == std::string::npos) return {};

    std::size_t i = pos + needle.size();
    std::string value;
    while (i < json.size()) {
        if (json[i] == '\\' && i + 1 < json.size()) {
            value += json[i + 1];
            i += 2;
            continue;
        }
        if (json[i] == '"') break;
        value += json[i++];
    }
    return value;
}

static std::string uriToPath(const std::string& uri) {
    const std::string prefix = "file://";
    if (uri.rfind(prefix, 0) == 0) {
        return uri.substr(prefix.size());
    }
    return uri;
}

static std::string readMessage() {
    std::string line;
    if (!std::getline(std::cin, line)) return {};
    const auto pos = line.find("Content-Length:");
    if (pos == std::string::npos) return {};
    int length = std::stoi(line.substr(pos + 15));
    std::getline(std::cin, line);
    std::string body(length, '\0');
    std::cin.read(body.data(), length);
    return body;
}

static void sendMessage(const std::string& body) {
    std::cout << "Content-Length: " << body.size() << "\r\n\r\n" << body;
    std::cout.flush();
}

static void sendResponse(int id, const std::string& result) {
    std::ostringstream out;
    out << "{\"jsonrpc\":\"2.0\",\"id\":" << id << ",\"result\":" << result << "}";
    sendMessage(out.str());
}

static void publishDiagnostics(const std::string& uri, const std::string& source) {
    std::vector<std::string> diags;
    const std::string path = uriToPath(uri);

    try {
        SourceManager sources;
        sources.addFile(path.empty() ? "<buffer>" : path, source);
        auto program = parseSourceProgram(source, path.empty() ? "<buffer>" : path, &sources);
        SemanticAnalyzer analyzer(*program, &sources, path.empty() ? "<buffer>" : path);
        analyzer.analyze();
    } catch (const CompileError& e) {
        std::ostringstream item;
        item << "{\"range\":{\"start\":{\"line\":" << std::max(0, e.line() - 1)
             << ",\"character\":" << std::max(0, e.column() - 1)
             << "},\"end\":{\"line\":" << std::max(0, e.line() - 1)
             << ",\"character\":" << std::max(0, e.column()) << "}},"
             << "\"severity\":1,\"source\":\"afrilang\","
             << "\"message\":\"" << jsonEscape(e.what()) << "\"}";
        diags.push_back(item.str());
    }

    std::ostringstream params;
    params << "{\"uri\":\"" << jsonEscape(uri) << "\",\"diagnostics\":[";
    for (std::size_t i = 0; i < diags.size(); ++i) {
        if (i > 0) params << ',';
        params << diags[i];
    }
    params << "]}";

    std::ostringstream msg;
    msg << "{\"jsonrpc\":\"2.0\",\"method\":\"textDocument/publishDiagnostics\","
        << "\"params\":" << params.str() << "}";
    sendMessage(msg.str());
}

static std::string completionItems() {
    std::ostringstream out;
    out << "[";
    for (std::size_t i = 0; i < kKeywords.size(); ++i) {
        if (i > 0) out << ',';
        out << "{\"label\":\"" << kKeywords[i]
            << "\",\"kind\":14,\"detail\":\"mot-clé AFRILANG\"}";
    }
    out << "]";
    return out.str();
}

static int extractId(const std::string& body) {
    const auto idPos = body.find("\"id\":");
    if (idPos == std::string::npos) return 0;
    return std::stoi(body.substr(idPos + 5));
}

int runLspServer() {
    while (true) {
        const std::string body = readMessage();
        if (body.empty()) break;

        if (body.find("\"method\":\"initialize\"") != std::string::npos) {
            sendResponse(extractId(body),
                "{\"capabilities\":{\"textDocumentSync\":1,"
                "\"completionProvider\":{\"triggerCharacters\":[\".\",\" \"]}}}");
        } else if (body.find("\"method\":\"initialized\"") != std::string::npos) {
            // no response
        } else if (body.find("\"method\":\"textDocument/didOpen\"") != std::string::npos ||
                   body.find("\"method\":\"textDocument/didChange\"") != std::string::npos) {
            const std::string uri = jsonGetString(body, "uri");
            std::string text = jsonGetString(body, "text");
            if (text.empty()) {
                const auto textPos = body.find("\"text\":\"");
                if (textPos != std::string::npos) {
                    text = jsonGetString(body.substr(textPos), "text");
                }
            }
            publishDiagnostics(uri.empty() ? "file://<buffer>" : uri, text);
        } else if (body.find("\"method\":\"textDocument/completion\"") != std::string::npos) {
            sendResponse(extractId(body),
                "{\"isIncomplete\":false,\"items\":" + completionItems() + "}");
        } else if (body.find("\"method\":\"shutdown\"") != std::string::npos) {
            sendResponse(extractId(body), "null");
            break;
        }
    }
    return 0;
}

} // namespace afrilang
