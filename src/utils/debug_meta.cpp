#include "afrilang/debug_meta.hpp"

#include <fstream>

namespace afrilang {

namespace {

std::string jsonEscape(const std::string& s) {
    std::string out;
    out.reserve(s.size());
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

} // namespace

void writeDebugMetadata(const std::string& path, const SemanticResult& semantic,
                        const std::string& sourceFile) {
    std::ofstream out(path);
    if (!out) return;

    out << "{\n";
    out << "  \"source\": \"" << jsonEscape(sourceFile) << "\",\n";
    out << "  \"variables\": [\n";

    bool first = true;
    for (const auto& [name, type] : semantic.globalVariables) {
        if (!first) out << ",\n";
        first = false;
        out << "    {\"name\":\"" << jsonEscape(name) << "\",\"type\":\""
            << jsonEscape(type.toTypeName()) << "\"}";
    }

    out << "\n  ]\n}\n";
}

} // namespace afrilang
