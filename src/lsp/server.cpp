#include "afrilang/lsp.hpp"

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
    "class", "classe", "function", "fonction", "end", "fin", "create", "creer",
    "if", "si", "then", "alors", "else", "sinon", "say", "dire",
    "while", "tantque", "do", "faire", "repeat", "repeter", "times", "fois",
    "for", "pour", "each", "chaque", "in", "dans", "return", "retourner", "renvoyer",
    "interface", "implements", "implemente", "test", "tester", "assert", "verifier",
    "error", "erreur", "extends", "etend", "returns", "retourne",
    "module", "use", "utiliser", "import", "importer", "export", "exporter",
    "record", "enregistrement", "field", "champ", "number", "nombre",
    "text", "texte", "bool", "booleen", "list", "liste", "true", "vrai",
    "false", "faux", "yes", "oui", "no", "non", "stop", "arreter", "skip", "passer",
    "enum", "enumeration", "union", "case", "cas", "match", "associer",
    "default", "defaut", "with", "avec", "defined", "defini", "ask", "demander",
    "into", "en", "new", "nouveau", "public", "private", "prive", "protected", "protege",
    "empty", "vide", "of", "de", "at", "map", "carte", "filter", "filtrer",
    "reduce", "reduire", "flatMap", "aplatir", "where", "const", "constante",
    "try", "essayer", "catch", "attraper", "raise", "lever", "final", "fini",
    "abstract", "abstrait", "static", "statique", "property", "propriete",
    "destroy", "detruire", "async", "asynchrone", "await", "attendre", "task", "tache",
    "operator", "operateur", "extern", "externe", "from", "depuis", "explain", "expliquer",
    "super", "set", "definir", "this", "ceci", "nothing", "rien", "is", "est",
    "and", "et", "or", "ou", "not", "pas", "length", "longueur", "add", "ajouter"
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

static int jsonGetInt(const std::string& json, const std::string& key, int fallback = 0) {
    const std::string needle = "\"" + key + "\":";
    const auto pos = json.find(needle);
    if (pos == std::string::npos) return fallback;
    return std::stoi(json.substr(pos + needle.size()));
}

static std::string uriToPath(const std::string& uri) {
    const std::string prefix = "file://";
    if (uri.rfind(prefix, 0) == 0) return uri.substr(prefix.size());
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
    const int length = std::stoi(line.substr(pos + 15));
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

static void sendNotification(const std::string& method, const std::string& params) {
    std::ostringstream out;
    out << "{\"jsonrpc\":\"2.0\",\"method\":\"" << method << "\",\"params\":" << params << "}";
    sendMessage(out.str());
}

struct AnalysisResult {
    bool ok = true;
    std::vector<std::string> diagnosticJson;
    std::unordered_map<std::string, std::pair<int, int>> symbolLocations;
    std::unordered_map<std::string, std::string> symbolDocs;
};

static AnalysisResult analyzeDocument(const std::string& path, const std::string& source) {
    AnalysisResult result;
    try {
        SourceManager sources;
        sources.addFile(path.empty() ? "<buffer>" : path, source);
        auto program = parseSourceProgram(source, path.empty() ? "<buffer>" : path, &sources);
        SemanticAnalyzer analyzer(*program, &sources, path);
        const SemanticResult semantic = analyzer.analyze();

        for (const auto& [name, sig] : semantic.functions) {
            if (sig.isExtern) continue;
            result.symbolLocations[name] = {1, 0};
            result.symbolDocs[name] = "function " + name +
                (sig.returnType.kind != TypeKind::Void ? " → " + sig.returnType.toCpp() : "");
        }
        for (const auto& [name, cls] : semantic.classes) {
            result.symbolLocations[name] = {1, 0};
            result.symbolDocs[name] = "class " + name;
        }
        for (const auto& [name, en] : semantic.enums) {
            result.symbolLocations[name] = {1, 0};
            result.symbolDocs[name] = "enum " + name;
        }
        for (const auto& w : semantic.warnings) {
            std::ostringstream d;
            d << "{\"range\":{\"start\":{\"line\":" << std::max(0, w.line - 1)
              << ",\"character\":" << std::max(0, w.column - 1)
              << "},\"end\":{\"line\":" << std::max(0, w.line - 1)
              << ",\"character\":" << std::max(0, w.column) << "}},"
              << "\"severity\":2,\"source\":\"afrilang\",\"message\":\""
              << jsonEscape(w.message) << "\"}";
            result.diagnosticJson.push_back(d.str());
        }
    } catch (const CompileError& e) {
        result.ok = false;
        std::ostringstream d;
        d << "{\"range\":{\"start\":{\"line\":" << std::max(0, e.line() - 1)
          << ",\"character\":" << std::max(0, e.column() - 1)
          << "},\"end\":{\"line\":" << std::max(0, e.line() - 1)
          << ",\"character\":" << std::max(0, e.column()) << "}},"
          << "\"severity\":1,\"source\":\"afrilang\",\"code\":\""
          << errorCodeString(e.code()) << "\",\"message\":\""
          << jsonEscape(e.what()) << "\"}";
        result.diagnosticJson.push_back(d.str());
    }
    return result;
}

static void publishDiagnostics(const std::string& uri, const AnalysisResult& analysis) {
    std::ostringstream params;
    params << "{\"uri\":\"" << jsonEscape(uri) << "\",\"diagnostics\":[";
    for (std::size_t i = 0; i < analysis.diagnosticJson.size(); ++i) {
        if (i > 0) params << ',';
        params << analysis.diagnosticJson[i];
    }
    params << "]}";
    sendNotification("textDocument/publishDiagnostics", params.str());
}

static std::string completionItems(const AnalysisResult& analysis) {
    std::ostringstream out;
    out << "[";
    bool first = true;
    for (const auto& kw : kKeywords) {
        if (!first) out << ',';
        first = false;
        out << "{\"label\":\"" << kw << "\",\"kind\":14,\"detail\":\"keyword\"}";
    }
    for (const auto& [name, doc] : analysis.symbolDocs) {
        out << ",{\"label\":\"" << name << "\",\"kind\":3,\"detail\":\""
            << jsonEscape(doc) << "\"}";
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
        int endLine = 0, endChar = 0;
        for (char c : source) {
            if (c == '\n') { ++endLine; endChar = 0; } else { ++endChar; }
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
    if (!uri.empty()) g_documents[uri] = text;
}

static std::string wordAtPosition(const std::string& source, int line, int character) {
    std::istringstream stream(source);
    std::string current;
    for (int i = 0; i <= line && std::getline(stream, current); ++i) {}
    if (line < 0 || character < 0 || static_cast<std::size_t>(character) > current.size()) {
        return {};
    }
    int start = character;
    int end = character;
    while (start > 0 && (std::isalnum(static_cast<unsigned char>(current[start - 1])) ||
                         current[static_cast<std::size_t>(start - 1)] == '_')) {
        --start;
    }
    while (end < static_cast<int>(current.size()) &&
           (std::isalnum(static_cast<unsigned char>(current[static_cast<std::size_t>(end)])) ||
            current[static_cast<std::size_t>(end)] == '_')) {
        ++end;
    }
    return current.substr(static_cast<std::size_t>(start),
                          static_cast<std::size_t>(end - start));
}

int runLspServer() {
    std::unordered_map<std::string, AnalysisResult> analysisCache;

    while (true) {
        const std::string body = readMessage();
        if (body.empty()) break;

        if (body.find("\"method\":\"initialize\"") != std::string::npos) {
            sendResponse(extractId(body),
                "{\"capabilities\":{"
                "\"textDocumentSync\":1,"
                "\"completionProvider\":{\"triggerCharacters\":[\".\",\" \"]},"
                "\"documentFormattingProvider\":true,"
                "\"hoverProvider\":true,"
                "\"definitionProvider\":true"
                "},"
                "\"serverInfo\":{\"name\":\"afrilang-lsp\",\"version\":\"1.0.0\"}"
                "}");
        } else if (body.find("\"method\":\"initialized\"") != std::string::npos) {
        } else if (body.find("\"method\":\"textDocument/didOpen\"") != std::string::npos) {
            const std::string uri = documentUri(body);
            const std::string text = extractDocumentText(body);
            updateDocument(uri, text);
            analysisCache[uri] = analyzeDocument(uriToPath(uri), text);
            publishDiagnostics(uri, analysisCache[uri]);
        } else if (body.find("\"method\":\"textDocument/didChange\"") != std::string::npos) {
            const std::string uri = documentUri(body);
            const std::string text = extractDocumentText(body);
            updateDocument(uri, text);
            analysisCache[uri] = analyzeDocument(uriToPath(uri), text);
            publishDiagnostics(uri, analysisCache[uri]);
        } else if (body.find("\"method\":\"textDocument/didClose\"") != std::string::npos) {
            const std::string uri = documentUri(body);
            g_documents.erase(uri);
            analysisCache.erase(uri);
        } else if (body.find("\"method\":\"textDocument/completion\"") != std::string::npos) {
            const std::string uri = documentUri(body);
            const auto it = analysisCache.find(uri);
            const AnalysisResult analysis = it != analysisCache.end()
                ? it->second : AnalysisResult{};
            sendResponse(extractId(body),
                "{\"isIncomplete\":false,\"items\":" + completionItems(analysis) + "}");
        } else if (body.find("\"method\":\"textDocument/hover\"") != std::string::npos) {
            const std::string uri = documentUri(body);
            const auto docIt = g_documents.find(uri);
            const int line = jsonGetInt(body, "line");
            const int character = jsonGetInt(body, "character");
            std::string hover;
            if (docIt != g_documents.end()) {
                const std::string word = wordAtPosition(docIt->second, line, character);
                const auto cacheIt = analysisCache.find(uri);
                if (!word.empty() && cacheIt != analysisCache.end()) {
                    const auto symIt = cacheIt->second.symbolDocs.find(word);
                    if (symIt != cacheIt->second.symbolDocs.end()) hover = symIt->second;
                }
            }
            if (hover.empty()) {
                sendResponse(extractId(body), "null");
            } else {
                sendResponse(extractId(body),
                    "{\"contents\":{\"kind\":\"markdown\",\"value\":\"" +
                    jsonEscape(hover) + "\"}}");
            }
        } else if (body.find("\"method\":\"textDocument/definition\"") != std::string::npos) {
            const std::string uri = documentUri(body);
            sendResponse(extractId(body),
                "{\"uri\":\"" + jsonEscape(uri) +
                "\",\"range\":{\"start\":{\"line\":0,\"character\":0},"
                "\"end\":{\"line\":0,\"character\":1}}}");
        } else if (body.find("\"method\":\"textDocument/formatting\"") != std::string::npos) {
            const std::string uri = documentUri(body);
            const auto it = g_documents.find(uri);
            const std::string edits = it != g_documents.end()
                ? formatDocument(uri, it->second) : "[]";
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
