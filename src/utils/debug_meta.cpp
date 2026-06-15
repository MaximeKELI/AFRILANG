#include "afrilang/debug_meta.hpp"

#include <fstream>
#include <unordered_set>
#include <vector>

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

struct VarEntry {
    std::string name;
    std::string type;
    std::string scope;
    int line = 0;
};

void collectFromBlock(const std::vector<std::unique_ptr<StatementNode>>& stmts,
                      const std::string& scope,
                      std::vector<VarEntry>& out,
                      std::unordered_set<std::string>& seen) {
    for (const auto& stmt : stmts) {
        if (const auto* assign = dynamic_cast<const AssignStatementNode*>(stmt.get())) {
            const std::string key = scope + ":" + assign->name;
            if (seen.insert(key).second) {
                out.push_back({assign->name, assign->typeName, scope, stmt->loc.line});
            }
        }
        if (const auto* ifStmt = dynamic_cast<const IfStatementNode*>(stmt.get())) {
            collectFromBlock(ifStmt->thenBody, scope, out, seen);
            collectFromBlock(ifStmt->elseBody, scope, out, seen);
        }
        if (const auto* whileStmt = dynamic_cast<const WhileStatementNode*>(stmt.get())) {
            collectFromBlock(whileStmt->body, scope, out, seen);
        }
        if (const auto* repeat = dynamic_cast<const RepeatStatementNode*>(stmt.get())) {
            collectFromBlock(repeat->body, scope, out, seen);
        }
    }
}

void collectFunctionLocals(const FunctionNode& fn, std::vector<VarEntry>& out,
                           std::unordered_set<std::string>& seen) {
    for (const auto& param : fn.parameters) {
        const std::string key = fn.name + ":" + param.name;
        if (seen.insert(key).second) {
            out.push_back({param.name, param.typeName, fn.name, fn.loc.line});
        }
    }
    collectFromBlock(fn.body, fn.name, out, seen);
}

} // namespace

void writeDebugMetadata(const std::string& path, const ProgramNode& program,
                        const SemanticResult& semantic,
                        const std::string& sourceFile) {
    std::ofstream out(path);
    if (!out) return;

    std::vector<VarEntry> entries;
    std::unordered_set<std::string> seen;

    for (const auto& [name, type] : semantic.globalVariables) {
        const std::string key = "global:" + name;
        if (seen.insert(key).second) {
            entries.push_back({name, type.toTypeName(), "global", 0});
        }
    }

    collectFromBlock(program.statements, "global", entries, seen);

    for (const auto& fn : program.functions) {
        collectFunctionLocals(*fn, entries, seen);
    }
    for (const auto& mod : program.modules) {
        for (const auto& fn : mod->functions) {
            collectFunctionLocals(*fn, entries, seen);
        }
    }
    for (const auto& cls : program.classes) {
        for (const auto& fn : cls->methods) {
            collectFunctionLocals(*fn, entries, seen);
        }
    }

    out << "{\n";
    out << "  \"source\": \"" << jsonEscape(sourceFile) << "\",\n";
    out << "  \"variables\": [\n";

    for (std::size_t i = 0; i < entries.size(); ++i) {
        const auto& entry = entries[i];
        if (i > 0) out << ",\n";
        out << "    {\"name\":\"" << jsonEscape(entry.name) << "\",\"type\":\""
            << jsonEscape(entry.type) << "\",\"scope\":\""
            << jsonEscape(entry.scope) << "\"";
        if (entry.line > 0) {
            out << ",\"line\":" << entry.line;
        }
        out << "}";
    }

    out << "\n  ]\n}\n";
}

} // namespace afrilang
