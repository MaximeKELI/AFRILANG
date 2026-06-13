#include "afrilang/lsp.hpp"

#include "afrilang/compiler.hpp"
#include "afrilang/diagnostics.hpp"
#include "afrilang/lexer.hpp"
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
    "text", "bool", "list", "true", "false", "stop", "skip"
};

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

static void publishDiagnostics(const std::string& uri, const std::string& path,
                               const std::string& source) {
    std::vector<std::string> diags;

    try {
        Compiler compiler(path);
        auto program = compiler.compile();
        SemanticAnalyzer analyzer(*program, &compiler.sources(), path);
        analyzer.analyze();
    } catch (const CompileError& e) {
        std::ostringstream item;
        item << "{\"range\":{\"start\":{\"line\":" << std::max(0, e.line() - 1)
             << ",\"character\":" << std::max(0, e.column() - 1)
             << "},\"end\":{\"line\":" << std::max(0, e.line() - 1)
             << ",\"character\":" << std::max(0, e.column()) << "}},"
             << "\"severity\":1,\"source\":\"afrilang\","
             << "\"message\":\"" << e.format() << "\"}";
        diags.push_back(item.str());
    }

    std::ostringstream params;
    params << "{\"uri\":\"" << uri << "\",\"diagnostics\":[";
    for (std::size_t i = 0; i < diags.size(); ++i) {
        if (i > 0) params << ',';
        params << diags[i];
    }
    params << "]}";

    std::ostringstream msg;
    msg << "{\"jsonrpc\":\"2.0\",\"method\":\"textDocument/publishDiagnostics\","
        << "\"params\":" << params.str() << "}";
    sendMessage(msg.str());
    (void)source;
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

int runLspServer() {
    while (true) {
        const std::string body = readMessage();
        if (body.empty()) break;

        if (body.find("\"method\":\"initialize\"") != std::string::npos) {
            const auto idPos = body.find("\"id\":");
            int id = std::stoi(body.substr(idPos + 5));
            sendResponse(id,
                "{\"capabilities\":{\"textDocumentSync\":1,"
                "\"completionProvider\":{\"triggerCharacters\":[\".\",\" \"]}}}");
        } else if (body.find("\"method\":\"initialized\"") != std::string::npos) {
            // no response
        } else if (body.find("\"method\":\"textDocument/didOpen\"") != std::string::npos) {
            publishDiagnostics("file://", "", "");
        } else if (body.find("\"method\":\"textDocument/completion\"") != std::string::npos) {
            const auto idPos = body.find("\"id\":");
            int id = std::stoi(body.substr(idPos + 5));
            sendResponse(id, "{\"isIncomplete\":false,\"items\":" + completionItems() + "}");
        } else if (body.find("\"method\":\"shutdown\"") != std::string::npos) {
            const auto idPos = body.find("\"id\":");
            int id = std::stoi(body.substr(idPos + 5));
            sendResponse(id, "null");
            break;
        }
    }
    return 0;
}

} // namespace afrilang
