#include "afrilang/codegen.hpp"

#include <cstdlib>
#include <fstream>
#include <sstream>

namespace afrilang {

CodeGenerator::CodeGenerator(const ProgramNode& program, const SemanticResult& semantic)
    : program_(program), semantic_(semantic) {}

std::string CodeGenerator::generate() const {
    std::ostringstream out;
    generate(out);
    return out.str();
}

void CodeGenerator::generate(std::ostream& out) const {
    emitHeader(out);
    emitClasses(out);
    emitGlobalFunctions(out);
    emitMain(out);
}

void CodeGenerator::emitHeader(std::ostream& out) const {
    out << "// Code généré par le compilateur AFRILANG\n";
    out << "// Ne pas modifier manuellement\n\n";
    out << "#include <iostream>\n";
    out << "#include <string>\n\n";
}

void CodeGenerator::emitClasses(std::ostream& out) const {
    for (const auto& cls : program_.classes) {
        out << "class " << cls->name;
        if (!cls->baseClassName.empty()) {
            out << " : public " << cls->baseClassName;
        }
        out << " {\npublic:\n";

        for (const auto& method : cls->methods) {
            const std::string returnCpp = method->returnTypeName.empty()
                ? "void"
                : typeFromName(method->returnTypeName).toCpp();

            out << "    virtual " << returnCpp << " " << method->name
                << "(" << paramList(*method) << ")";

            if (!cls->baseClassName.empty()) {
                auto baseIt = semantic_.classes.find(cls->baseClassName);
                if (baseIt != semantic_.classes.end() &&
                    baseIt->second.methods.count(method->name)) {
                    out << " override";
                }
            }

            out << " {\n";
            for (const auto& stmt : method->body) {
                emitStatement(out, *stmt, 2);
            }
            out << "    }\n\n";
        }

        out << "};\n\n";
    }
}

std::string CodeGenerator::paramList(const FunctionNode& func) {
    std::ostringstream out;
    for (std::size_t i = 0; i < func.parameters.size(); ++i) {
        if (i > 0) out << ", ";
        const auto& param = func.parameters[i];
        out << typeFromName(param.typeName).toCpp() << " " << param.name;
    }
    return out.str();
}

void CodeGenerator::emitGlobalFunctions(std::ostream& out) const {
    for (const auto& func : program_.functions) {
        const std::string returnCpp = func->returnTypeName.empty()
            ? "void"
            : typeFromName(func->returnTypeName).toCpp();

        out << returnCpp << " " << func->name << "(" << paramList(*func) << ") {\n";
        for (const auto& stmt : func->body) {
            emitStatement(out, *stmt, 1);
        }
        out << "}\n\n";
    }
}

void CodeGenerator::emitMain(std::ostream& out) const {
    out << "int main() {\n";

    for (const auto& stmt : program_.statements) {
        emitStatement(out, *stmt, 1);
    }

    out << "    return 0;\n";
    out << "}\n";
}

void CodeGenerator::emitStatement(std::ostream& out, const StatementNode& stmt, int indentLevel) const {
    indent(out, indentLevel);

    if (const auto* say = dynamic_cast<const SayStatementNode*>(&stmt)) {
        out << "std::cout << ";
        emitExpression(out, *say->value);
        out << " << std::endl;\n";
        return;
    }

    if (const auto* assign = dynamic_cast<const AssignStatementNode*>(&stmt)) {
        if (const auto* newExpr = dynamic_cast<const NewExpressionNode*>(assign->value.get())) {
            out << newExpr->className << " " << assign->name << ";\n";
            return;
        }

        const std::string typeCpp = inferExpressionType(*assign->value);
        out << typeCpp << " " << assign->name << " = ";
        emitExpression(out, *assign->value);
        out << ";\n";
        return;
    }

    if (const auto* ret = dynamic_cast<const ReturnStatementNode*>(&stmt)) {
        out << "return ";
        emitExpression(out, *ret->value);
        out << ";\n";
        return;
    }

    if (const auto* ifStmt = dynamic_cast<const IfStatementNode*>(&stmt)) {
        out << "if (";
        emitExpression(out, *ifStmt->condition);
        out << ") {\n";
        for (const auto& bodyStmt : ifStmt->body) {
            emitStatement(out, *bodyStmt, indentLevel + 1);
        }
        indent(out, indentLevel);
        out << "}\n";
        return;
    }

    if (const auto* repeat = dynamic_cast<const RepeatStatementNode*>(&stmt)) {
        out << "for (int _i = 0; _i < static_cast<int>(";
        emitExpression(out, *repeat->count);
        out << "); ++_i) {\n";
        for (const auto& bodyStmt : repeat->body) {
            emitStatement(out, *bodyStmt, indentLevel + 1);
        }
        indent(out, indentLevel);
        out << "}\n";
        return;
    }

    if (const auto* exprStmt = dynamic_cast<const ExpressionStatementNode*>(&stmt)) {
        emitExpression(out, *exprStmt->expression);
        out << ";\n";
        return;
    }
}

void CodeGenerator::emitExpression(std::ostream& out, const ExpressionNode& expr) const {
    if (const auto* str = dynamic_cast<const StringLiteralNode*>(&expr)) {
        out << '"' << escapeString(str->value) << '"';
        return;
    }

    if (const auto* num = dynamic_cast<const NumberLiteralNode*>(&expr)) {
        if (num->value == static_cast<int>(num->value)) {
            out << static_cast<int>(num->value);
        } else {
            out << num->value;
        }
        return;
    }

    if (const auto* id = dynamic_cast<const IdentifierNode*>(&expr)) {
        out << id->name;
        return;
    }

    if (const auto* bin = dynamic_cast<const BinaryOpNode*>(&expr)) {
        if (bin->op == "+") {
            const auto* leftStr = dynamic_cast<const StringLiteralNode*>(bin->left.get());
            const auto* rightStr = dynamic_cast<const StringLiteralNode*>(bin->right.get());
            if (leftStr || rightStr) {
                out << "(";
                emitExpression(out, *bin->left);
                out << " + ";
                emitExpression(out, *bin->right);
                out << ")";
                return;
            }
        }
        out << "(";
        emitExpression(out, *bin->left);
        out << " " << bin->op << " ";
        emitExpression(out, *bin->right);
        out << ")";
        return;
    }

    if (const auto* unary = dynamic_cast<const UnaryOpNode*>(&expr)) {
        out << unary->op;
        emitExpression(out, *unary->operand);
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

    if (const auto* member = dynamic_cast<const MemberAccessNode*>(&expr)) {
        emitExpression(out, *member->object);
        out << "." << member->member;
        return;
    }

    if (const auto* newExpr = dynamic_cast<const NewExpressionNode*>(&expr)) {
        out << newExpr->className << "()";
        return;
    }
}

std::string CodeGenerator::inferExpressionType(const ExpressionNode& expr) const {
    if (dynamic_cast<const StringLiteralNode*>(&expr)) return "std::string";
    if (dynamic_cast<const NumberLiteralNode*>(&expr)) return "double";

    if (const auto* newExpr = dynamic_cast<const NewExpressionNode*>(&expr)) {
        return newExpr->className;
    }

    if (const auto* id = dynamic_cast<const IdentifierNode*>(&expr)) {
        return resolveVariableType(id->name);
    }

    if (const auto* bin = dynamic_cast<const BinaryOpNode*>(&expr)) {
        if (bin->op == "+") {
            if (dynamic_cast<const StringLiteralNode*>(bin->left.get()) ||
                dynamic_cast<const StringLiteralNode*>(bin->right.get())) {
                return "std::string";
            }
        }
        return "double";
    }

    return "auto";
}

std::string CodeGenerator::resolveVariableType(const std::string& name) const {
    auto it = semantic_.globalVariables.find(name);
    if (it != semantic_.globalVariables.end()) {
        return it->second.toCpp();
    }
    return "auto";
}

void CodeGenerator::indent(std::ostream& out, int level) {
    for (int i = 0; i < level; ++i) {
        out << "    ";
    }
}

std::string CodeGenerator::escapeString(const std::string& s) {
    std::string result;
    result.reserve(s.size());
    for (char c : s) {
        switch (c) {
            case '"':  result += "\\\""; break;
            case '\\': result += "\\\\"; break;
            case '\n': result += "\\n";  break;
            case '\t': result += "\\t";  break;
            default:   result += c;        break;
        }
    }
    return result;
}

bool CodeGenerator::compileToExecutable(const std::string& outputPath,
                                        const std::string& executablePath) const {
    {
        std::ofstream file(outputPath);
        if (!file) return false;
        generate(file);
    }

    const std::string command =
        "g++ -std=c++17 -O2 -Wall -Wextra -o \"" + executablePath +
        "\" \"" + outputPath + "\" 2>&1";

    const int result = std::system(command.c_str());
    return result == 0;
}

} // namespace afrilang
