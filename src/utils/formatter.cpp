#include "afrilang/formatter.hpp"

#include "afrilang/lexer.hpp"
#include "afrilang/parser.hpp"

#include <sstream>

namespace afrilang {

std::unique_ptr<ProgramNode> parseSourceProgram(const std::string& source,
                                                const std::string& virtualPath,
                                                SourceManager* sources) {
    Lexer lexer(source);
    Parser parser(lexer.tokenize());
    auto program = parser.parse();
    if (sources) {
        sources->addFile(virtualPath, source);
    }
    return program;
}

Formatter::Formatter(const ProgramNode& program) : program_(program) {}

std::string Formatter::format() const {
    std::ostringstream out;
    format(out);
    return out.str();
}

void Formatter::format(std::ostream& out) const {
    bool needBlank = false;

    for (const auto& importNode : program_.imports) {
        if (needBlank) out << "\n";
        out << "import \"" << importNode->path << "\"\n";
        needBlank = true;
    }

    for (const auto& iface : program_.interfaces) {
        if (needBlank) out << "\n";
        formatInterface(out, *iface);
        needBlank = true;
    }

    for (const auto& record : program_.records) {
        if (needBlank) out << "\n";
        formatRecord(out, *record);
        needBlank = true;
    }

    for (const auto& en : program_.enums) {
        if (needBlank) out << "\n";
        formatEnum(out, *en);
        needBlank = true;
    }

    for (const auto& cls : program_.classes) {
        if (needBlank) out << "\n";
        formatClass(out, *cls);
        needBlank = true;
    }

    for (const auto& module : program_.modules) {
        if (needBlank) out << "\n";
        formatModule(out, *module);
        needBlank = true;
    }

    for (const auto& func : program_.functions) {
        if (needBlank) out << "\n";
        formatFunction(out, *func);
        needBlank = true;
    }

    for (const auto& ext : program_.externs) {
        if (needBlank) out << "\n";
        writeIndent(out);
        out << "extern from \"" << ext->library << "\" function " << ext->name;
        formatParameters(out, ext->parameters);
        if (!ext->returnTypeName.empty()) {
            out << " returns ";
            formatType(out, ext->returnTypeName);
        }
        out << "\n";
        needBlank = true;
    }

    for (const auto& test : program_.tests) {
        if (needBlank) out << "\n";
        formatTest(out, *test);
        needBlank = true;
    }

    for (const auto& stmt : program_.statements) {
        if (needBlank) out << "\n";
        formatStatement(out, *stmt);
        needBlank = true;
    }
}

void Formatter::writeIndent(std::ostream& out) const {
    for (int i = 0; i < indent_; ++i) {
        out << "    ";
    }
}

void Formatter::writeln(std::ostream& out, const std::string& line) const {
    writeIndent(out);
    out << line << "\n";
}

void Formatter::formatType(std::ostream& out, const std::string& typeName) const {
    if (typeName.rfind("list ", 0) == 0) {
        out << "list ";
        formatType(out, typeName.substr(5));
        return;
    }
    out << typeName;
}

void Formatter::formatParameters(std::ostream& out,
                                 const std::vector<ParameterNode>& params) const {
    out << "(";
    for (std::size_t i = 0; i < params.size(); ++i) {
        if (i > 0) out << ", ";
        out << params[i].name << " ";
        formatType(out, params[i].typeName);
    }
    out << ")";
}

void Formatter::formatFunctionSignature(std::ostream& out, const FunctionNode& func,
                                        bool signatureOnly) const {
    out << "function " << func.name;
    if (!func.typeParams.empty()) {
        out << "<";
        for (std::size_t i = 0; i < func.typeParams.size(); ++i) {
            if (i > 0) out << ", ";
            out << func.typeParams[i];
        }
        out << ">";
    }
    formatParameters(out, func.parameters);
    if (!func.returnTypeName.empty()) {
        out << " returns ";
        formatType(out, func.returnTypeName);
        if (func.returnsResult) {
            out << " or error";
        }
    }
    if (!signatureOnly) {
        out << "\n";
    }
}

void Formatter::formatFunction(std::ostream& out, const FunctionNode& func,
                               bool signatureOnly) const {
    writeIndent(out);
    formatFunctionSignature(out, func, signatureOnly);
    if (signatureOnly) {
        out << "\n";
        return;
    }

    ++indent_;
    for (const auto& stmt : func.body) {
        formatStatement(out, *stmt);
    }
    --indent_;
    writeln(out, "end");
}

void Formatter::formatClass(std::ostream& out, const ClassNode& cls) const {
    writeIndent(out);
    out << "class " << cls.name;
    if (!cls.baseClassName.empty()) {
        out << " extends " << cls.baseClassName;
    }
    if (!cls.interfaceNames.empty()) {
        out << " implements " << cls.interfaceNames[0];
        for (std::size_t i = 1; i < cls.interfaceNames.size(); ++i) {
            out << ", " << cls.interfaceNames[i];
        }
    }
    out << "\n";

    ++indent_;
    for (const auto& field : cls.fields) {
        writeIndent(out);
        out << (field.visibility == FieldVisibility::Public ? "public"
              : field.visibility == FieldVisibility::Private ? "private"
              : "protected") << " field "
            << field.name << " ";
        formatType(out, field.typeName);
        out << "\n";
    }

    for (const auto& method : cls.methods) {
        formatFunction(out, *method);
    }
    --indent_;
    writeln(out, "end");
}

void Formatter::formatRecord(std::ostream& out, const RecordNode& record) const {
    writeln(out, "record " + record.name);
    ++indent_;
    for (const auto& field : record.fields) {
        writeIndent(out);
        out << "field " << field.name << " ";
        formatType(out, field.typeName);
        out << "\n";
    }
    --indent_;
    writeln(out, "end");
}

void Formatter::formatEnum(std::ostream& out, const EnumNode& en) const {
    writeln(out, "enum " + en.name);
    ++indent_;
    for (const auto& c : en.cases) {
        writeIndent(out);
        out << "case " << c.name;
        if (!c.fields.empty()) {
            out << " with";
            for (std::size_t i = 0; i < c.fields.size(); ++i) {
                out << " " << c.fields[i].name << " ";
                formatType(out, c.fields[i].typeName);
            }
        }
        out << "\n";
    }
    --indent_;
    writeln(out, "end");
}

void Formatter::formatInterface(std::ostream& out, const InterfaceNode& iface) const {
    writeln(out, "interface " + iface.name);
    ++indent_;
    for (const auto& method : iface.methods) {
        formatFunction(out, *method, true);
    }
    --indent_;
    writeln(out, "end");
}

void Formatter::formatModule(std::ostream& out, const ModuleNode& module) const {
    writeln(out, "module " + module.name);
    ++indent_;
    for (const auto& record : module.records) {
        formatRecord(out, *record);
    }
    for (const auto& cls : module.classes) {
        formatClass(out, *cls);
    }
    for (const auto& func : module.functions) {
        formatFunction(out, *func);
    }
    --indent_;
    writeln(out, "end");
}

void Formatter::formatTest(std::ostream& out, const TestNode& test) const {
    writeIndent(out);
    out << "test \"" << test.name << "\"\n";
    ++indent_;
    formatStatements(out, test.body);
    --indent_;
    writeln(out, "end");
}

void Formatter::formatStatements(std::ostream& out,
                                 const std::vector<std::unique_ptr<StatementNode>>& stmts) const {
    for (const auto& stmt : stmts) {
        formatStatement(out, *stmt);
    }
}

void Formatter::formatStatement(std::ostream& out, const StatementNode& stmt) const {
    if (const auto* explain = dynamic_cast<const ExplainStatementNode*>(&stmt)) {
        writeln(out, "explain");
        ++indent_;
        formatStatement(out, *explain->statement);
        --indent_;
        return;
    }

    if (const auto* say = dynamic_cast<const SayStatementNode*>(&stmt)) {
        writeIndent(out);
        out << "say ";
        formatExpression(out, *say->value);
        out << "\n";
        return;
    }

    if (const auto* assign = dynamic_cast<const AssignStatementNode*>(&stmt)) {
        writeIndent(out);
        out << "create " << assign->name;
        if (!assign->typeName.empty()) {
            out << " ";
            formatType(out, assign->typeName);
        }
        out << " = ";
        formatExpression(out, *assign->value);
        out << "\n";
        return;
    }

    if (const auto* setStmt = dynamic_cast<const SetStatementNode*>(&stmt)) {
        writeIndent(out);
        out << "set ";
        formatExpression(out, *setStmt->target);
        out << " = ";
        formatExpression(out, *setStmt->value);
        out << "\n";
        return;
    }

    if (const auto* idxAssign = dynamic_cast<const IndexAssignStatementNode*>(&stmt)) {
        writeIndent(out);
        formatExpression(out, *idxAssign->object);
        out << " at ";
        formatExpression(out, *idxAssign->index);
        out << " = ";
        formatExpression(out, *idxAssign->value);
        out << "\n";
        return;
    }

    if (const auto* addTo = dynamic_cast<const AddToListStatementNode*>(&stmt)) {
        writeIndent(out);
        out << "add ";
        formatExpression(out, *addTo->value);
        out << " to ";
        formatExpression(out, *addTo->list);
        out << "\n";
        return;
    }

    if (const auto* ask = dynamic_cast<const AskStatementNode*>(&stmt)) {
        writeIndent(out);
        out << "ask ";
        formatExpression(out, *ask->prompt);
        out << " into " << ask->variableName << "\n";
        return;
    }

    if (const auto* useStmt = dynamic_cast<const UseStatementNode*>(&stmt)) {
        writeln(out, "use " + useStmt->moduleName);
        return;
    }

    if (const auto* ret = dynamic_cast<const ReturnStatementNode*>(&stmt)) {
        writeIndent(out);
        out << "return";
        if (ret->isError) out << " error";
        out << " ";
        formatExpression(out, *ret->value);
        out << "\n";
        return;
    }

    if (const auto* assertStmt = dynamic_cast<const AssertStatementNode*>(&stmt)) {
        writeIndent(out);
        out << "assert ";
        formatExpression(out, *assertStmt->condition);
        out << "\n";
        return;
    }

    if (const auto* ifStmt = dynamic_cast<const IfStatementNode*>(&stmt)) {
        writeIndent(out);
        out << "if ";
        formatExpression(out, *ifStmt->condition);
        out << " then\n";
        ++indent_;
        formatStatements(out, ifStmt->thenBody);
        --indent_;
        if (!ifStmt->elseBody.empty()) {
            writeln(out, "else");
            ++indent_;
            formatStatements(out, ifStmt->elseBody);
            --indent_;
        }
        writeln(out, "end");
        return;
    }

    if (const auto* matchStmt = dynamic_cast<const MatchStatementNode*>(&stmt)) {
        writeIndent(out);
        out << "match ";
        formatExpression(out, *matchStmt->subject);
        out << "\n";
        ++indent_;
        for (const auto& arm : matchStmt->arms) {
            writeIndent(out);
            if (arm.isDefault) {
                out << "default\n";
            } else {
                out << "case " << arm.caseName << " then\n";
            }
            ++indent_;
            formatStatements(out, arm.body);
            --indent_;
            writeln(out, "end");
        }
        --indent_;
        writeln(out, "end");
        return;
    }

    if (const auto* whileStmt = dynamic_cast<const WhileStatementNode*>(&stmt)) {
        writeIndent(out);
        out << "while ";
        formatExpression(out, *whileStmt->condition);
        out << " do\n";
        ++indent_;
        formatStatements(out, whileStmt->body);
        --indent_;
        writeln(out, "end");
        return;
    }

    if (const auto* repeat = dynamic_cast<const RepeatStatementNode*>(&stmt)) {
        writeIndent(out);
        out << "repeat ";
        formatExpression(out, *repeat->count);
        out << " times\n";
        ++indent_;
        formatStatements(out, repeat->body);
        --indent_;
        writeln(out, "end");
        return;
    }

    if (const auto* forEach = dynamic_cast<const ForEachStatementNode*>(&stmt)) {
        writeIndent(out);
        out << "for each " << forEach->itemName << " in ";
        formatExpression(out, *forEach->list);
        out << " do\n";
        ++indent_;
        formatStatements(out, forEach->body);
        --indent_;
        writeln(out, "end");
        return;
    }

    if (dynamic_cast<const BreakStatementNode*>(&stmt)) {
        writeln(out, "stop");
        return;
    }

    if (dynamic_cast<const ContinueStatementNode*>(&stmt)) {
        writeln(out, "skip");
        return;
    }

    if (const auto* exprStmt = dynamic_cast<const ExpressionStatementNode*>(&stmt)) {
        writeIndent(out);
        formatExpression(out, *exprStmt->expression);
        out << "\n";
        return;
    }
}

void Formatter::formatExpression(std::ostream& out, const ExpressionNode& expr) const {
    if (const auto* str = dynamic_cast<const StringLiteralNode*>(&expr)) {
        out << '"' << str->value << '"';
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
        out << "this";
        return;
    }

    if (const auto* id = dynamic_cast<const IdentifierNode*>(&expr)) {
        out << id->name;
        return;
    }

    if (const auto* errCheck = dynamic_cast<const IsErrorCheckNode*>(&expr)) {
        formatExpression(out, *errCheck->value);
        out << " is error";
        return;
    }

    if (const auto* isDef = dynamic_cast<const IsDefinedCheckNode*>(&expr)) {
        formatExpression(out, *isDef->value);
        out << " is defined";
        return;
    }

    if (dynamic_cast<const NothingLiteralNode*>(&expr)) {
        out << "nothing";
        return;
    }

    if (const auto* enumCase = dynamic_cast<const EnumCaseExprNode*>(&expr)) {
        out << enumCase->enumName << "." << enumCase->caseName;
        if (!enumCase->arguments.empty()) {
            out << " with";
            for (const auto& arg : enumCase->arguments) {
                out << " ";
                formatExpression(out, *arg);
            }
        }
        return;
    }

    if (const auto* bin = dynamic_cast<const BinaryOpNode*>(&expr)) {
        if (bin->op == "&&") {
            formatExpression(out, *bin->left);
            out << " and ";
            formatExpression(out, *bin->right);
            return;
        }
        if (bin->op == "||") {
            formatExpression(out, *bin->left);
            out << " or ";
            formatExpression(out, *bin->right);
            return;
        }
        if (bin->op == ">") {
            formatExpression(out, *bin->left);
            out << " is greater than ";
            formatExpression(out, *bin->right);
            return;
        }
        if (bin->op == "<") {
            formatExpression(out, *bin->left);
            out << " is less than ";
            formatExpression(out, *bin->right);
            return;
        }
        if (bin->op == "==") {
            formatExpression(out, *bin->left);
            out << " is equal to ";
            formatExpression(out, *bin->right);
            return;
        }
        if (bin->op == "!=") {
            formatExpression(out, *bin->left);
            out << " is not equal to ";
            formatExpression(out, *bin->right);
            return;
        }

        formatExpression(out, *bin->left);
        out << " " << bin->op << " ";
        formatExpression(out, *bin->right);
        return;
    }

    if (const auto* unary = dynamic_cast<const UnaryOpNode*>(&expr)) {
        if (unary->op == "-") {
            out << "-";
            formatExpression(out, *unary->operand);
            return;
        }
        if (unary->op == "!") {
            out << "not ";
            formatExpression(out, *unary->operand);
            return;
        }
    }

    if (const auto* call = dynamic_cast<const CallExpressionNode*>(&expr)) {
        formatExpression(out, *call->callee);
        out << "(";
        for (std::size_t i = 0; i < call->arguments.size(); ++i) {
            if (i > 0) out << ", ";
            formatExpression(out, *call->arguments[i]);
        }
        out << ")";
        return;
    }

    if (const auto* member = dynamic_cast<const MemberAccessNode*>(&expr)) {
        formatExpression(out, *member->object);
        out << "." << member->member;
        return;
    }

    if (const auto* newExpr = dynamic_cast<const NewExpressionNode*>(&expr)) {
        out << "new " << newExpr->className;
        return;
    }

    if (const auto* list = dynamic_cast<const ListLiteralNode*>(&expr)) {
        out << "[";
        for (std::size_t i = 0; i < list->elements.size(); ++i) {
            if (i > 0) out << ", ";
            formatExpression(out, *list->elements[i]);
        }
        out << "]";
        return;
    }

    if (const auto* empty = dynamic_cast<const EmptyListNode*>(&expr)) {
        out << "empty list ";
        formatType(out, empty->elementTypeName);
        return;
    }

    if (const auto* index = dynamic_cast<const IndexExpressionNode*>(&expr)) {
        if (dynamic_cast<const IdentifierNode*>(index->object.get())) {
            formatExpression(out, *index->object);
            out << " at ";
            formatExpression(out, *index->index);
            return;
        }
        formatExpression(out, *index->object);
        out << "[";
        formatExpression(out, *index->index);
        out << "]";
        return;
    }

    if (const auto* length = dynamic_cast<const LengthExpressionNode*>(&expr)) {
        out << "length of ";
        formatExpression(out, *length->object);
        return;
    }

    out << "<expr>";
}

} // namespace afrilang
