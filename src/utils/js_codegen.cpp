#include "afrilang/js_codegen.hpp"

#include "afrilang/compiler.hpp"
#include "afrilang/error.hpp"
#include "afrilang/semantic.hpp"

#include <sstream>

namespace afrilang {

namespace {

bool expressionSupported(const ExpressionNode& expr) {
    if (dynamic_cast<const StringLiteralNode*>(&expr)) return true;
    if (dynamic_cast<const NumberLiteralNode*>(&expr)) return true;
    if (dynamic_cast<const BoolLiteralNode*>(&expr)) return true;
    if (dynamic_cast<const IdentifierNode*>(&expr)) return true;
    if (const auto* bin = dynamic_cast<const BinaryOpNode*>(&expr)) {
        static const char* ops[] = {"+", "-", "*", "/", ">", "<", "==", "!=", "&&", "||"};
        bool ok = false;
        for (const char* op : ops) {
            if (bin->op == op) ok = true;
        }
        return ok && expressionSupported(*bin->left) && expressionSupported(*bin->right);
    }
    if (const auto* unary = dynamic_cast<const UnaryOpNode*>(&expr)) {
        return (unary->op == "-" || unary->op == "not") &&
               expressionSupported(*unary->operand);
    }
    return false;
}

bool statementsSupported(const std::vector<std::unique_ptr<StatementNode>>& stmts) {
    for (const auto& stmt : stmts) {
        if (dynamic_cast<const SayStatementNode*>(stmt.get())) {
            const auto* say = dynamic_cast<const SayStatementNode*>(stmt.get());
            if (!expressionSupported(*say->value)) return false;
            continue;
        }
        if (const auto* assign = dynamic_cast<const AssignStatementNode*>(stmt.get())) {
            if (!assign->value || !expressionSupported(*assign->value)) return false;
            if (assign->value && dynamic_cast<const NewExpressionNode*>(assign->value.get())) {
                return false;
            }
            continue;
        }
        if (const auto* setStmt = dynamic_cast<const SetStatementNode*>(stmt.get())) {
            if (!setStmt->value || !expressionSupported(*setStmt->value)) return false;
            if (!dynamic_cast<const IdentifierNode*>(setStmt->target.get())) return false;
            continue;
        }
        if (const auto* ifStmt = dynamic_cast<const IfStatementNode*>(stmt.get())) {
            if (!expressionSupported(*ifStmt->condition)) return false;
            if (!statementsSupported(ifStmt->thenBody)) return false;
            if (!statementsSupported(ifStmt->elseBody)) return false;
            continue;
        }
        if (const auto* whileStmt = dynamic_cast<const WhileStatementNode*>(stmt.get())) {
            if (!expressionSupported(*whileStmt->condition)) return false;
            if (!statementsSupported(whileStmt->body)) return false;
            continue;
        }
        if (const auto* repeat = dynamic_cast<const RepeatStatementNode*>(stmt.get())) {
            if (!expressionSupported(*repeat->count)) return false;
            if (!statementsSupported(repeat->body)) return false;
            continue;
        }
        return false;
    }
    return true;
}

} // namespace

std::string compileSourceToJavaScript(const std::string& source,
                                      const std::string& virtualPath) {
    Compiler compiler(virtualPath, ".");
    std::unique_ptr<ProgramNode> program = compiler.compileFromSource(source);
    SemanticAnalyzer analyzer(*program, &compiler.sources(), virtualPath);
    const SemanticResult semantic = analyzer.analyze();
    if (!supportsJavaScriptPlayground(*program, semantic)) {
        throw CompileError(
            "Ce programme nécessite le compilateur natif (imports, classes, async, etc.)",
            0, 0, virtualPath, {}, {}, ErrorCode::TypeMismatch);
    }
    JsCodeGenerator gen(*program, semantic);
    return gen.generate();
}

bool supportsJavaScriptPlayground(const ProgramNode& program,
                                  const SemanticResult& semantic) {
    if (!program.imports.empty()) return false;
    if (!program.classes.empty() || !program.modules.empty()) return false;
    if (!program.enums.empty() || !program.functions.empty()) return false;
    if (!program.interfaces.empty() || !program.records.empty()) return false;
    if (!program.externs.empty() || !program.tests.empty()) return false;
    if (semantic.usesAsync || semantic.usesGenerators || semantic.usesUi) return false;
    return statementsSupported(program.statements);
}

JsCodeGenerator::JsCodeGenerator(const ProgramNode& program, const SemanticResult& semantic)
    : program_(program), semantic_(semantic) {}

std::string JsCodeGenerator::generate() const {
    std::ostringstream out;
    generate(out);
    return out.str();
}

void JsCodeGenerator::generate(std::ostream& out) const {
    out << "\"use strict\";\n";
    for (const auto& stmt : program_.statements) {
        emitStatement(out, *stmt, 0);
    }
}

void JsCodeGenerator::indent(std::ostream& out, int level) {
    for (int i = 0; i < level; ++i) out << "  ";
}

std::string JsCodeGenerator::escapeString(const std::string& s) {
    std::string result;
    result.reserve(s.size());
    for (char c : s) {
        switch (c) {
            case '"': result += "\\\""; break;
            case '\\': result += "\\\\"; break;
            case '\n': result += "\\n"; break;
            case '\r': result += "\\r"; break;
            case '\t': result += "\\t"; break;
            default: result += c; break;
        }
    }
    return result;
}

void JsCodeGenerator::emitExpression(std::ostream& out, const ExpressionNode& expr) const {
    if (const auto* str = dynamic_cast<const StringLiteralNode*>(&expr)) {
        out << "\"" << escapeString(str->value) << "\"";
        return;
    }
    if (const auto* num = dynamic_cast<const NumberLiteralNode*>(&expr)) {
        if (num->isInteger) {
            out << static_cast<long long>(num->value);
        } else {
            out << num->value;
        }
        return;
    }
    if (const auto* boolean = dynamic_cast<const BoolLiteralNode*>(&expr)) {
        out << (boolean->value ? "true" : "false");
        return;
    }
    if (const auto* id = dynamic_cast<const IdentifierNode*>(&expr)) {
        out << id->name;
        return;
    }
    if (const auto* unary = dynamic_cast<const UnaryOpNode*>(&expr)) {
        if (unary->op == "not") {
            out << "!";
        } else {
            out << unary->op;
        }
        emitExpression(out, *unary->operand);
        return;
    }
    if (const auto* bin = dynamic_cast<const BinaryOpNode*>(&expr)) {
        out << "(";
        emitExpression(out, *bin->left);
        out << " " << bin->op << " ";
        emitExpression(out, *bin->right);
        out << ")";
    }
}

void JsCodeGenerator::emitStatement(std::ostream& out, const StatementNode& stmt,
                                    int indentLevel) const {
    indent(out, indentLevel);

    if (const auto* say = dynamic_cast<const SayStatementNode*>(&stmt)) {
        out << "console.log(";
        emitExpression(out, *say->value);
        out << ");\n";
        return;
    }

    if (const auto* assign = dynamic_cast<const AssignStatementNode*>(&stmt)) {
        out << "let " << assign->name << " = ";
        emitExpression(out, *assign->value);
        out << ";\n";
        return;
    }

    if (const auto* setStmt = dynamic_cast<const SetStatementNode*>(&stmt)) {
        if (const auto* id = dynamic_cast<const IdentifierNode*>(setStmt->target.get())) {
            out << id->name << " = ";
            emitExpression(out, *setStmt->value);
            out << ";\n";
        }
        return;
    }

    if (const auto* ifStmt = dynamic_cast<const IfStatementNode*>(&stmt)) {
        out << "if (";
        emitExpression(out, *ifStmt->condition);
        out << ") {\n";
        for (const auto& bodyStmt : ifStmt->thenBody) {
            emitStatement(out, *bodyStmt, indentLevel + 1);
        }
        indent(out, indentLevel);
        out << "}";
        if (!ifStmt->elseBody.empty()) {
            out << " else {\n";
            for (const auto& bodyStmt : ifStmt->elseBody) {
                emitStatement(out, *bodyStmt, indentLevel + 1);
            }
            indent(out, indentLevel);
            out << "}";
        }
        out << "\n";
        return;
    }

    if (const auto* whileStmt = dynamic_cast<const WhileStatementNode*>(&stmt)) {
        out << "while (";
        emitExpression(out, *whileStmt->condition);
        out << ") {\n";
        for (const auto& bodyStmt : whileStmt->body) {
            emitStatement(out, *bodyStmt, indentLevel + 1);
        }
        indent(out, indentLevel);
        out << "}\n";
        return;
    }

    if (const auto* repeat = dynamic_cast<const RepeatStatementNode*>(&stmt)) {
        out << "for (let _i = 0; _i < ";
        emitExpression(out, *repeat->count);
        out << "; _i++) {\n";
        for (const auto& bodyStmt : repeat->body) {
            emitStatement(out, *bodyStmt, indentLevel + 1);
        }
        indent(out, indentLevel);
        out << "}\n";
    }
}

} // namespace afrilang
