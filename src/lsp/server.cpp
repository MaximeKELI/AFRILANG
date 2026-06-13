#include "afrilang/lsp.hpp"

#include "afrilang/cli.hpp"
#include "afrilang/compiler.hpp"
#include "afrilang/diagnostics.hpp"
#include "afrilang/formatter.hpp"
#include "afrilang/semantic.hpp"

#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

namespace fs = std::filesystem;

namespace afrilang {

static std::unordered_map<std::string, std::string> g_documents;

static const std::vector<std::string> kKeywords = {
    "class", "function", "end", "create", "if", "then", "else", "say",
    "while", "do", "repeat", "times", "for", "each", "in", "return",
    "interface", "implements", "test", "assert", "error", "extends",
    "returns", "module", "use", "import", "record", "field", "number",
    "text", "bool", "list", "true", "false", "stop", "skip", "nothing",
    "enum", "case", "match", "default", "with", "defined", "ask", "into",
    "new", "public", "private", "protected", "empty", "of", "at", "to", "from", "step",
    "const", "map", "filter", "reduce", "flatMap", "where",
    "try", "catch", "raise", "final", "abstract", "static", "property", "destroy",
    "super", "explain", "yes", "no", "is", "greater", "than", "less", "equal",
    "and", "or", "not", "set", "this", "add", "length", "extern"
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

static std::string jsonGetString(const std::string& json, const std::string& key,
                                 std::size_t from = 0) {
    const std::string needle = "\"" + key + "\":\"";
    const auto pos = json.find(needle, from);
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

static std::string documentUri(const std::string& body) {
    return jsonGetString(body, "uri");
}

static std::string extractDocumentText(const std::string& body) {
    const auto changesPos = body.find("\"contentChanges\"");
    if (changesPos != std::string::npos) {
        const std::string text = jsonGetString(body, "text", changesPos);
        if (!text.empty()) return text;
    }
    return jsonGetString(body, "text");
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

// Diagnostics are published by the VS Code extension via `afrilang check`
// (same path as the CLI). The LSP handles completion and formatting only.

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

static std::string formatDocument(const std::string& uri, const std::string& source) {
    const std::string path = uriToPath(uri);
    try {
        SourceManager sources;
        sources.addFile(path.empty() ? "<buffer>" : path, source);
        auto program = parseSourceProgram(source, path.empty() ? "<buffer>" : path, &sources);
        Formatter formatter(*program);
        const std::string formatted = formatter.format();
        if (formatted == source) return "[]";

        int endLine = 0;
        int endChar = 0;
        for (char c : source) {
            if (c == '\n') {
                ++endLine;
                endChar = 0;
            } else {
                ++endChar;
            }
        }

        std::ostringstream out;
        out << "[{\"range\":{\"start\":{\"line\":0,\"character\":0},"
            << "\"end\":{\"line\":" << endLine << ",\"character\":" << endChar << "}},"
            << "\"newText\":\"" << jsonEscape(formatted) << "\"}]";
        return out.str();
    } catch (const CompileError&) {
        return "[]";
    }
}

static int extractId(const std::string& body) {
    const auto idPos = body.find("\"id\":");
    if (idPos == std::string::npos) return 0;
    std::size_t i = idPos + 5;
    while (i < body.size() && (body[i] == ' ' || body[i] == '\t')) ++i;
    int id = 0;
    while (i < body.size() && body[i] >= '0' && body[i] <= '9') {
        id = id * 10 + (body[i] - '0');
        ++i;
    }
    return id;
}

static void updateDocument(const std::string& uri, const std::string& text) {
    if (uri.empty()) return;
    g_documents[uri] = text;
}

int runLspServer() {
    while (true) {
        const std::string body = readMessage();
        if (body.empty()) break;

        if (body.find("\"method\":\"initialize\"") != std::string::npos) {
            sendResponse(extractId(body),
                "{\"capabilities\":{"
                "\"textDocumentSync\":1,"
                "\"completionProvider\":{\"triggerCharacters\":[\".\",\" \"]},"
                "\"documentFormattingProvider\":true"
                "},"
                "\"serverInfo\":{\"name\":\"afrilang-lsp\",\"version\":\"0.3.6\"}"
                "}");
        } else if (body.find("\"method\":\"initialized\"") != std::string::npos) {
            // notification, no response
        } else if (body.find("\"method\":\"textDocument/didOpen\"") != std::string::npos) {
            const std::string uri = documentUri(body);
            updateDocument(uri, extractDocumentText(body));
        } else if (body.find("\"method\":\"textDocument/didChange\"") != std::string::npos) {
            const std::string uri = documentUri(body);
            updateDocument(uri, extractDocumentText(body));
        } else if (body.find("\"method\":\"textDocument/didClose\"") != std::string::npos) {
            g_documents.erase(documentUri(body));
        } else if (body.find("\"method\":\"textDocument/completion\"") != std::string::npos) {
            sendResponse(extractId(body),
                "{\"isIncomplete\":false,\"items\":" + completionItems() + "}");
        } else if (body.find("\"method\":\"textDocument/formatting\"") != std::string::npos) {
            const std::string uri = documentUri(body);
            const auto it = g_documents.find(uri);
            const std::string edits = it != g_documents.end()
                ? formatDocument(uri, it->second)
                : "[]";
            sendResponse(extractId(body), edits);
        } else if (body.find("\"method\":\"shutdown\"") != std::string::npos) {
            sendResponse(extractId(body), "null");
        } else if (body.find("\"method\":\"exit\"") != std::string::npos) {
            break;
        }
    }
    return 0;
}

} // namespace afrilang
