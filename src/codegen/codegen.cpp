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
    emitRecords(out);
    emitClasses(out);
    emitModules(out);
    emitGlobalFunctions(out);
    emitMain(out);
}

void CodeGenerator::emitHeader(std::ostream& out) const {
    out << "// Code généré par le compilateur AFRILANG\n";
    out << "// Ne pas modifier manuellement\n\n";
    out << "#include <iostream>\n";
    out << "#include <string>\n";
    out << "#include <vector>\n";

    bool needsIo = false;
    bool needsJson = false;
    for (const auto& module : program_.modules) {
        if (module->name == "io") needsIo = true;
        if (module->name == "json") needsJson = true;
    }
    if (needsIo) out << "#include \"io.hpp\"\n";
    if (needsJson) out << "#include \"json.hpp\"\n";
    out << "\n";
}

void CodeGenerator::emitRecords(std::ostream& out) const {
    for (const auto& record : program_.records) {
        out << "struct " << record->name << " {\n";
        for (const auto& field : record->fields) {
            out << "    " << typeFromName(field.typeName).toCpp()
                << " " << field.name << ";\n";
        }
        out << "};\n\n";
    }

    for (const auto& module : program_.modules) {
        out << "namespace " << module->name << " {\n";
        for (const auto& record : module->records) {
            out << "struct " << record->name << " {\n";
            for (const auto& field : record->fields) {
                out << "    " << typeFromName(field.typeName).toCpp()
                    << " " << field.name << ";\n";
            }
            out << "};\n\n";
        }
        out << "} // namespace " << module->name << "\n\n";
    }
}

void CodeGenerator::emitClass(std::ostream& out, const ClassNode& cls) const {
    const ClassInfo* classInfo = nullptr;
    auto it = semantic_.classes.find(cls.name);
    if (it != semantic_.classes.end()) classInfo = &it->second;

    out << "class " << cls.name;
    if (!cls.baseClassName.empty()) {
        out << " : public " << cls.baseClassName;
    }
    out << " {\n";

    out << "public:\n";
    for (const auto& field : cls.fields) {
        out << "    " << typeFromName(field.typeName).toCpp()
            << " " << field.name << ";\n";
    }
    if (!cls.fields.empty()) out << "\n";

    const FunctionNode* constructor = nullptr;
    for (const auto& method : cls.methods) {
        if (method->name == "init") {
            constructor = method.get();
            break;
        }
    }

    if (constructor) {
        out << "    " << cls.name << "(" << paramList(*constructor) << ") {\n";
        for (const auto& stmt : constructor->body) {
            emitStatement(out, *stmt, 2, classInfo);
        }
        out << "    }\n\n";
    }

    for (const auto& method : cls.methods) {
        if (method->name == "init") continue;
        emitFunction(out, *method, classInfo, 1);
        out << "\n";
    }

    out << "};\n\n";
}

void CodeGenerator::emitClasses(std::ostream& out) const {
    for (const auto& cls : program_.classes) {
        emitClass(out, *cls);
    }
}

void CodeGenerator::emitModules(std::ostream& out) const {
    for (const auto& module : program_.modules) {
        out << "namespace " << module->name << " {\n";

        for (const auto& cls : module->classes) {
            const ClassInfo* classInfo = nullptr;
            auto it = semantic_.classes.find(cls->name);
            if (it != semantic_.classes.end()) classInfo = &it->second;

            out << "class " << cls->name;
            if (!cls->baseClassName.empty()) {
                out << " : public " << cls->baseClassName;
            }
            out << " {\npublic:\n";

            for (const auto& field : cls->fields) {
                out << "    " << typeFromName(field.typeName).toCpp()
                    << " " << field.name << ";\n";
            }
            if (!cls->fields.empty()) out << "\n";

            const FunctionNode* constructor = nullptr;
            for (const auto& method : cls->methods) {
                if (method->name == "init") constructor = method.get();
            }
            if (constructor) {
                out << "    " << cls->name << "(" << paramList(*constructor) << ") {\n";
                for (const auto& stmt : constructor->body) {
                    emitStatement(out, *stmt, 2, classInfo);
                }
                out << "    }\n\n";
            }

            for (const auto& method : cls->methods) {
                if (method->name == "init") continue;
                emitFunction(out, *method, classInfo, 1);
                out << "\n";
            }
            out << "};\n\n";
        }

        for (const auto& func : module->functions) {
            if (usesStdlibModule(module->name)) {
                emitStdlibFunction(out, module->name, *func, 1);
            } else {
                emitFunction(out, *func, nullptr, 1);
            }
            out << "\n";
        }

        out << "} // namespace " << module->name << "\n\n";
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

void CodeGenerator::emitFunction(std::ostream& out, const FunctionNode& func,
                                 const ClassInfo* ownerClass, int indentLevel) const {
    const std::string returnCpp = func.returnTypeName.empty()
        ? "void"
        : typeFromName(func.returnTypeName).toCpp();

    indent(out, indentLevel);
    if (ownerClass) {
        out << "virtual ";
    }
    out << returnCpp << " " << func.name << "(" << paramList(func) << ")";

    if (ownerClass && !ownerClass->baseClass.empty()) {
        auto baseIt = semantic_.classes.find(ownerClass->baseClass);
        if (baseIt != semantic_.classes.end() &&
            baseIt->second.methods.count(func.name)) {
            out << " override";
        }
    }

    out << " {\n";
    for (const auto& stmt : func.body) {
        emitStatement(out, *stmt, indentLevel + 1, ownerClass);
    }
    indent(out, indentLevel);
    out << "}\n";
}

void CodeGenerator::emitGlobalFunctions(std::ostream& out) const {
    for (const auto& func : program_.functions) {
        emitFunction(out, *func, nullptr, 0);
        out << "\n";
    }
}

void CodeGenerator::emitMain(std::ostream& out) const {
    for (const auto& modName : semantic_.usedModules) {
        out << "using namespace " << modName << ";\n";
    }
    if (!semantic_.usedModules.empty()) out << "\n";

    out << "int main() {\n";

    for (const auto& stmt : program_.statements) {
        emitStatement(out, *stmt, 1, nullptr);
    }

    out << "    return 0;\n";
    out << "}\n";
}

void CodeGenerator::emitStatement(std::ostream& out, const StatementNode& stmt, int indentLevel,
                                  const ClassInfo* ownerClass) const {
    indent(out, indentLevel);

    if (const auto* say = dynamic_cast<const SayStatementNode*>(&stmt)) {
        out << "std::cout << ";
        emitExpression(out, *say->value, ownerClass);
        out << " << std::endl;\n";
        return;
    }

    if (const auto* assign = dynamic_cast<const AssignStatementNode*>(&stmt)) {
        if (const auto* newExpr = dynamic_cast<const NewExpressionNode*>(assign->value.get())) {
            out << newExpr->className << " " << assign->name;
            const ClassInfo* clsInfo = nullptr;
            auto it = semantic_.classes.find(newExpr->className);
            if (it != semantic_.classes.end()) clsInfo = &it->second;

            const FunctionNode* initMethod = nullptr;
            for (const auto& cls : program_.classes) {
                if (cls->name == newExpr->className) {
                    for (const auto& m : cls->methods) {
                        if (m->name == "init") initMethod = m.get();
                    }
                }
            }
            if (!initMethod) {
                for (const auto& module : program_.modules) {
                    for (const auto& cls : module->classes) {
                        if (cls->name == newExpr->className) {
                            for (const auto& m : cls->methods) {
                                if (m->name == "init") initMethod = m.get();
                            }
                        }
                    }
                }
            }

            if (initMethod && !initMethod->parameters.empty()) {
                out << "(";
                for (std::size_t i = 0; i < initMethod->parameters.size(); ++i) {
                    if (i > 0) out << ", ";
                    out << typeFromName(initMethod->parameters[i].typeName).toCpp() << "{}";
                }
                out << ")";
            }
            out << ";\n";
            (void)clsInfo;
            return;
        }

        if (const auto* empty = dynamic_cast<const EmptyListNode*>(assign->value.get())) {
            out << "std::vector<" << typeFromName(empty->elementTypeName).toCpp()
                << "> " << assign->name << " = {};\n";
            return;
        }

        if (const auto* list = dynamic_cast<const ListLiteralNode*>(assign->value.get())) {
            std::string elemCpp;
            if (!assign->typeName.empty()) {
                AfrType t = typeFromName(assign->typeName);
                if (t.kind == TypeKind::List) elemCpp = t.listElementType().toCpp();
            }
            if (elemCpp.empty() && !list->elements.empty()) {
                elemCpp = inferExpressionType(*list->elements[0]);
            }
            out << "std::vector<" << elemCpp << "> " << assign->name << " = {";
            for (std::size_t i = 0; i < list->elements.size(); ++i) {
                if (i > 0) out << ", ";
                emitExpression(out, *list->elements[i], ownerClass);
            }
            out << "};\n";
            return;
        }

        std::string typeCpp;
        if (!assign->typeName.empty()) {
            typeCpp = typeFromName(assign->typeName).toCpp();
        } else {
            typeCpp = inferExpressionType(*assign->value);
        }
        out << typeCpp << " " << assign->name << " = ";
        emitExpression(out, *assign->value, ownerClass);
        out << ";\n";
        return;
    }

    if (const auto* set = dynamic_cast<const SetStatementNode*>(&stmt)) {
        emitExpression(out, *set->target, ownerClass);
        out << " = ";
        emitExpression(out, *set->value, ownerClass);
        out << ";\n";
        return;
    }

    if (const auto* idxAssign = dynamic_cast<const IndexAssignStatementNode*>(&stmt)) {
        emitExpression(out, *idxAssign->object, ownerClass);
        out << "[static_cast<size_t>(";
        emitExpression(out, *idxAssign->index, ownerClass);
        out << ")] = ";
        emitExpression(out, *idxAssign->value, ownerClass);
        out << ";\n";
        return;
    }

    if (const auto* addTo = dynamic_cast<const AddToListStatementNode*>(&stmt)) {
        emitExpression(out, *addTo->list, ownerClass);
        out << ".push_back(";
        emitExpression(out, *addTo->value, ownerClass);
        out << ");\n";
        return;
    }

    if (const auto* ask = dynamic_cast<const AskStatementNode*>(&stmt)) {
        out << "std::cout << ";
        emitExpression(out, *ask->prompt, ownerClass);
        out << ";\n";
        indent(out, indentLevel);
        out << "std::getline(std::cin, " << ask->variableName << ");\n";
        return;
    }

    if (dynamic_cast<const UseStatementNode*>(&stmt)) {
        return;
    }

    if (const auto* ret = dynamic_cast<const ReturnStatementNode*>(&stmt)) {
        out << "return ";
        emitExpression(out, *ret->value, ownerClass);
        out << ";\n";
        return;
    }

    if (const auto* ifStmt = dynamic_cast<const IfStatementNode*>(&stmt)) {
        out << "if (";
        emitExpression(out, *ifStmt->condition, ownerClass);
        out << ") {\n";
        for (const auto& bodyStmt : ifStmt->thenBody) {
            emitStatement(out, *bodyStmt, indentLevel + 1, ownerClass);
        }
        indent(out, indentLevel);
        out << "}";
        if (!ifStmt->elseBody.empty()) {
            out << " else {\n";
            for (const auto& bodyStmt : ifStmt->elseBody) {
                emitStatement(out, *bodyStmt, indentLevel + 1, ownerClass);
            }
            indent(out, indentLevel);
            out << "}";
        }
        out << "\n";
        return;
    }

    if (const auto* whileStmt = dynamic_cast<const WhileStatementNode*>(&stmt)) {
        out << "while (";
        emitExpression(out, *whileStmt->condition, ownerClass);
        out << ") {\n";
        for (const auto& bodyStmt : whileStmt->body) {
            emitStatement(out, *bodyStmt, indentLevel + 1, ownerClass);
        }
        indent(out, indentLevel);
        out << "}\n";
        return;
    }

    if (const auto* repeat = dynamic_cast<const RepeatStatementNode*>(&stmt)) {
        out << "for (int _i = 0; _i < static_cast<int>(";
        emitExpression(out, *repeat->count, ownerClass);
        out << "); ++_i) {\n";
        for (const auto& bodyStmt : repeat->body) {
            emitStatement(out, *bodyStmt, indentLevel + 1, ownerClass);
        }
        indent(out, indentLevel);
        out << "}\n";
        return;
    }

    if (const auto* forEach = dynamic_cast<const ForEachStatementNode*>(&stmt)) {
        out << "for (auto& " << forEach->itemName << " : ";
        emitExpression(out, *forEach->list, ownerClass);
        out << ") {\n";
        for (const auto& bodyStmt : forEach->body) {
            emitStatement(out, *bodyStmt, indentLevel + 1, ownerClass);
        }
        indent(out, indentLevel);
        out << "}\n";
        return;
    }

    if (dynamic_cast<const BreakStatementNode*>(&stmt)) {
        out << "break;\n";
        return;
    }

    if (dynamic_cast<const ContinueStatementNode*>(&stmt)) {
        out << "continue;\n";
        return;
    }

    if (const auto* exprStmt = dynamic_cast<const ExpressionStatementNode*>(&stmt)) {
        emitExpression(out, *exprStmt->expression, ownerClass);
        out << ";\n";
        return;
    }
}

void CodeGenerator::emitExpression(std::ostream& out, const ExpressionNode& expr,
                                     const ClassInfo* ownerClass) const {
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

    if (const auto* boolean = dynamic_cast<const BoolLiteralNode*>(&expr)) {
        out << (boolean->value ? "true" : "false");
        return;
    }

    if (dynamic_cast<const ThisExpressionNode*>(&expr)) {
        return;
    }

    if (const auto* id = dynamic_cast<const IdentifierNode*>(&expr)) {
        for (const auto& modName : semantic_.usedModules) {
            auto modIt = semantic_.modules.find(modName);
            if (modIt != semantic_.modules.end() && modIt->second.functions.count(id->name)) {
                out << modName << "::" << id->name;
                return;
            }
        }
        out << id->name;
        return;
    }

    if (const auto* bin = dynamic_cast<const BinaryOpNode*>(&expr)) {
        if (bin->op == "+") {
            const auto* leftStr = dynamic_cast<const StringLiteralNode*>(bin->left.get());
            const auto* rightStr = dynamic_cast<const StringLiteralNode*>(bin->right.get());
            if (leftStr || rightStr) {
                out << "(";
                emitExpression(out, *bin->left, ownerClass);
                out << " + ";
                emitExpression(out, *bin->right, ownerClass);
                out << ")";
                return;
            }
        }
        out << "(";
        emitExpression(out, *bin->left, ownerClass);
        out << " " << bin->op << " ";
        emitExpression(out, *bin->right, ownerClass);
        out << ")";
        return;
    }

    if (const auto* unary = dynamic_cast<const UnaryOpNode*>(&expr)) {
        out << unary->op;
        emitExpression(out, *unary->operand, ownerClass);
        return;
    }

    if (const auto* list = dynamic_cast<const ListLiteralNode*>(&expr)) {
        std::string elemCpp = list->elements.empty()
            ? "double"
            : inferExpressionType(*list->elements[0]);
        out << "std::vector<" << elemCpp << ">{";
        for (std::size_t i = 0; i < list->elements.size(); ++i) {
            if (i > 0) out << ", ";
            emitExpression(out, *list->elements[i], ownerClass);
        }
        out << "}";
        return;
    }

    if (const auto* empty = dynamic_cast<const EmptyListNode*>(&expr)) {
        out << "std::vector<" << typeFromName(empty->elementTypeName).toCpp() << ">()";
        return;
    }

    if (const auto* index = dynamic_cast<const IndexExpressionNode*>(&expr)) {
        emitExpression(out, *index->object, ownerClass);
        out << "[static_cast<size_t>(";
        emitExpression(out, *index->index, ownerClass);
        out << ")]";
        return;
    }

    if (const auto* length = dynamic_cast<const LengthExpressionNode*>(&expr)) {
        emitExpression(out, *length->object, ownerClass);
        out << ".size()";
        return;
    }

    if (const auto* call = dynamic_cast<const CallExpressionNode*>(&expr)) {
        emitExpression(out, *call->callee, ownerClass);
        out << "(";
        for (std::size_t i = 0; i < call->arguments.size(); ++i) {
            if (i > 0) out << ", ";
            emitExpression(out, *call->arguments[i], ownerClass);
        }
        out << ")";
        return;
    }

    if (const auto* member = dynamic_cast<const MemberAccessNode*>(&expr)) {
        if (dynamic_cast<const ThisExpressionNode*>(member->object.get())) {
            out << member->member;
        } else {
            emitExpression(out, *member->object, ownerClass);
            out << "." << member->member;
        }
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
    if (dynamic_cast<const BoolLiteralNode*>(&expr)) return "bool";

    if (const auto* newExpr = dynamic_cast<const NewExpressionNode*>(&expr)) {
        return newExpr->className;
    }

    if (const auto* empty = dynamic_cast<const EmptyListNode*>(&expr)) {
        return "std::vector<" + typeFromName(empty->elementTypeName).toCpp() + ">";
    }

    if (const auto* list = dynamic_cast<const ListLiteralNode*>(&expr)) {
        if (!list->elements.empty()) {
            return "std::vector<" + inferExpressionType(*list->elements[0]) + ">";
        }
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
        if (bin->op == ">" || bin->op == "<" || bin->op == "==" || bin->op == "!=" ||
            bin->op == "&&" || bin->op == "||") {
            return "bool";
        }
        return "double";
    }

    if (dynamic_cast<const LengthExpressionNode*>(&expr)) return "double";

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

bool CodeGenerator::usesStdlibModule(const std::string& name) const {
    return name == "io" || name == "json";
}

void CodeGenerator::emitStdlibFunction(std::ostream& out, const std::string& moduleName,
                                       const FunctionNode& func, int indentLevel) const {
    const std::string returnCpp = func.returnTypeName.empty()
        ? "void"
        : typeFromName(func.returnTypeName).toCpp();

    indent(out, indentLevel);
    out << returnCpp << " " << func.name << "(" << paramList(func) << ") {\n";
    indent(out, indentLevel + 1);

    const std::string rt = "afrilang::runtime::" + moduleName + "::" + func.name;

    if (func.name == "writeFile") {
        out << rt << "(path, content);\n";
    } else if (func.returnTypeName.empty()) {
        out << rt << "(";
        for (std::size_t i = 0; i < func.parameters.size(); ++i) {
            if (i > 0) out << ", ";
            out << func.parameters[i].name;
        }
        out << ");\n";
    } else {
        out << "return " << rt << "(";
        for (std::size_t i = 0; i < func.parameters.size(); ++i) {
            if (i > 0) out << ", ";
            out << func.parameters[i].name;
        }
        out << ");\n";
    }

    indent(out, indentLevel);
    out << "}\n";
}

bool CodeGenerator::compileToExecutable(const std::string& outputPath,
                                        const std::string& executablePath) const {
    {
        std::ofstream file(outputPath);
        if (!file) return false;
        generate(file);
    }

    std::string command =
        "g++ -std=c++17 -O2 -Wall -Wextra -o \"" + executablePath +
        "\" \"" + outputPath + "\"";

    if (!runtimeDir_.empty()) {
        command += " -I\"" + runtimeDir_ + "\"";
    }

    command += " 2>&1";

    const int result = std::system(command.c_str());
    return result == 0;
}

} // namespace afrilang
