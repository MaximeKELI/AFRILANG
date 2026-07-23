#include "afrilang/js_codegen.hpp"

#include "afrilang/compiler.hpp"
#include "afrilang/error.hpp"
#include "afrilang/semantic.hpp"

#include <sstream>

namespace afrilang {

namespace {

bool expressionSupported(const ExpressionNode& expr);

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
        if (const auto* forRange = dynamic_cast<const ForRangeStatementNode*>(stmt.get())) {
            if (!expressionSupported(*forRange->start) || !expressionSupported(*forRange->end)) {
                return false;
            }
            if (forRange->step && !expressionSupported(*forRange->step)) return false;
            if (!statementsSupported(forRange->body)) return false;
            continue;
        }
        if (const auto* forEach = dynamic_cast<const ForEachStatementNode*>(stmt.get())) {
            if (!expressionSupported(*forEach->list)) return false;
            if (!statementsSupported(forEach->body)) return false;
            continue;
        }
        if (const auto* macroCall = dynamic_cast<const MacroCallStatementNode*>(stmt.get())) {
            if (macroCall->expanded.empty()) return false;
            if (!statementsSupported(macroCall->expanded)) return false;
            continue;
        }
        if (const auto* ret = dynamic_cast<const ReturnStatementNode*>(stmt.get())) {
            if (ret->value && !expressionSupported(*ret->value)) return false;
            continue;
        }
        if (const auto* exprStmt = dynamic_cast<const ExpressionStatementNode*>(stmt.get())) {
            if (!exprStmt->expression || !expressionSupported(*exprStmt->expression)) return false;
            continue;
        }
        return false;
    }
    return true;
}

bool expressionSupported(const ExpressionNode& expr) {
    if (dynamic_cast<const StringLiteralNode*>(&expr)) return true;
    if (dynamic_cast<const NumberLiteralNode*>(&expr)) return true;
    if (dynamic_cast<const BoolLiteralNode*>(&expr)) return true;
    if (dynamic_cast<const IdentifierNode*>(&expr)) return true;
    if (const auto* bin = dynamic_cast<const BinaryOpNode*>(&expr)) {
        static const char* ops[] = {"+", "-", "*", "/", ">", "<", "==", "!=", "&&", "||",
                                    ">=", "<="};
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
    if (const auto* call = dynamic_cast<const CallExpressionNode*>(&expr)) {
        if (!expressionSupported(*call->callee)) return false;
        if (!call->typeArgs.empty()) return false;
        for (const auto& arg : call->arguments) {
            if (!expressionSupported(*arg)) return false;
        }
        return true;
    }
    if (const auto* list = dynamic_cast<const ListLiteralNode*>(&expr)) {
        for (const auto& elem : list->elements) {
            if (!expressionSupported(*elem)) return false;
        }
        return true;
    }
    if (const auto* mapLit = dynamic_cast<const MapLiteralNode*>(&expr)) {
        for (const auto& pair : mapLit->pairs) {
            if (!expressionSupported(*pair.key) || !expressionSupported(*pair.value)) return false;
        }
        return true;
    }
    if (dynamic_cast<const EmptyMapNode*>(&expr)) return true;
    if (const auto* index = dynamic_cast<const IndexExpressionNode*>(&expr)) {
        return expressionSupported(*index->object) && expressionSupported(*index->index);
    }
    return false;
}

} // namespace

std::string compileSourceToJavaScript(const std::string& source,
                                      const std::string& virtualPath) {
    Compiler compiler(virtualPath, ".");
    std::unique_ptr<ProgramNode> program = compiler.compileFromSource(source);
    SemanticAnalyzer analyzer(*program, &compiler.sources(), virtualPath);
    const SemanticResult semantic = analyzer.analyze();
    if (!supportsJavaScriptPlayground(*program, semantic)) {
        throw CompileError("JS playground: sous-ensemble non supporté "
                           "(pas d'imports/classes/async/UI ; fonctions OK)",
                           0, 0, virtualPath);
    }
    JsCodeGenerator gen(*program, semantic);
    return gen.generate();
}

bool supportsJavaScriptPlayground(const ProgramNode& program,
                                  const SemanticResult& semantic) {
    if (!program.imports.empty()) return false;
    if (!program.classes.empty() || !program.modules.empty()) return false;
    if (!program.enums.empty()) return false;
    if (!program.interfaces.empty() || !program.records.empty()) return false;
    if (!program.externs.empty() || !program.tests.empty()) return false;
    if (semantic.usesAsync || semantic.usesGenerators || semantic.usesUi) return false;
    for (const auto& func : program.functions) {
        if (func->isAsync || func->isGenerator || func->isOperator || func->isAbstract) {
            return false;
        }
        if (!statementsSupported(func->body)) return false;
    }
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
    for (const auto& func : program_.functions) {
        emitFunction(out, *func);
    }
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

void JsCodeGenerator::emitFunction(std::ostream& out, const FunctionNode& func) const {
    out << "function " << func.name << "(";
    for (std::size_t i = 0; i < func.parameters.size(); ++i) {
        if (i > 0) out << ", ";
        out << func.parameters[i].name;
    }
    out << ") {\n";
    for (const auto& stmt : func.body) {
        emitStatement(out, *stmt, 1);
    }
    out << "}\n";
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
        return;
    }
    if (const auto* call = dynamic_cast<const CallExpressionNode*>(&expr)) {
        emitExpression(out, *call->callee);
        out << "(";
        for (std::size_t i = 0; i < call->arguments.size(); ++i) {
            if (i > 0) out << ", ";
            emitExpression(out, *call->arguments[i]);
        }
        out << ")";
        return;
    }
    if (const auto* list = dynamic_cast<const ListLiteralNode*>(&expr)) {
        out << "[";
        for (std::size_t i = 0; i < list->elements.size(); ++i) {
            if (i > 0) out << ", ";
            emitExpression(out, *list->elements[i]);
        }
        out << "]";
        return;
    }
    if (const auto* mapLit = dynamic_cast<const MapLiteralNode*>(&expr)) {
        out << "({";
        for (std::size_t i = 0; i < mapLit->pairs.size(); ++i) {
            if (i > 0) out << ", ";
            out << "[";
            emitExpression(out, *mapLit->pairs[i].key);
            out << "]: ";
            emitExpression(out, *mapLit->pairs[i].value);
        }
        out << "})";
        return;
    }
    if (dynamic_cast<const EmptyMapNode*>(&expr)) {
        out << "({})";
        return;
    }
    if (const auto* index = dynamic_cast<const IndexExpressionNode*>(&expr)) {
        emitExpression(out, *index->object);
        out << "[";
        emitExpression(out, *index->index);
        out << "]";
        return;
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

    if (const auto* forRange = dynamic_cast<const ForRangeStatementNode*>(&stmt)) {
        out << "for (let " << forRange->varName << " = ";
        emitExpression(out, *forRange->start);
        out << "; " << forRange->varName << " <= ";
        emitExpression(out, *forRange->end);
        out << "; " << forRange->varName << " += ";
        if (forRange->step) {
            emitExpression(out, *forRange->step);
        } else {
            out << "1";
        }
        out << ") {\n";
        for (const auto& bodyStmt : forRange->body) {
            emitStatement(out, *bodyStmt, indentLevel + 1);
        }
        indent(out, indentLevel);
        out << "}\n";
        return;
    }

    if (const auto* forEach = dynamic_cast<const ForEachStatementNode*>(&stmt)) {
        if (!forEach->valueName.empty()) {
            out << "for (const [" << forEach->itemName << ", " << forEach->valueName
                << "] of Object.entries(";
            emitExpression(out, *forEach->list);
            out << ")) {\n";
        } else {
            out << "for (const " << forEach->itemName << " of ";
            emitExpression(out, *forEach->list);
            out << ") {\n";
        }
        for (const auto& bodyStmt : forEach->body) {
            emitStatement(out, *bodyStmt, indentLevel + 1);
        }
        indent(out, indentLevel);
        out << "}\n";
        return;
    }

    if (const auto* macroCall = dynamic_cast<const MacroCallStatementNode*>(&stmt)) {
        for (const auto& expanded : macroCall->expanded) {
            emitStatement(out, *expanded, indentLevel);
        }
        return;
    }

    if (const auto* ret = dynamic_cast<const ReturnStatementNode*>(&stmt)) {
        out << "return";
        if (ret->value) {
            out << " ";
            emitExpression(out, *ret->value);
        }
        out << ";\n";
        return;
    }

    if (const auto* exprStmt = dynamic_cast<const ExpressionStatementNode*>(&stmt)) {
        emitExpression(out, *exprStmt->expression);
        out << ";\n";
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
