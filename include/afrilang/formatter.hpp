#pragma once

#include "afrilang/ast.hpp"
#include "afrilang/diagnostics.hpp"

#include <ostream>
#include <string>

namespace afrilang {

class Formatter {
public:
    explicit Formatter(const ProgramNode& program);

    void format(std::ostream& out) const;
    std::string format() const;

private:
    const ProgramNode& program_;
    mutable int indent_ = 0;

    void writeIndent(std::ostream& out) const;
    void writeln(std::ostream& out, const std::string& line) const;
    void formatType(std::ostream& out, const std::string& typeName) const;
    void formatParameters(std::ostream& out, const std::vector<ParameterNode>& params) const;
    void formatFunctionSignature(std::ostream& out, const FunctionNode& func,
                                 bool signatureOnly) const;
    void formatFunction(std::ostream& out, const FunctionNode& func,
                        bool signatureOnly = false) const;
    void formatStatement(std::ostream& out, const StatementNode& stmt) const;
    void formatStatements(std::ostream& out,
                          const std::vector<std::unique_ptr<StatementNode>>& stmts) const;
    void formatExpression(std::ostream& out, const ExpressionNode& expr) const;
    void formatClass(std::ostream& out, const ClassNode& cls) const;
    void formatRecord(std::ostream& out, const RecordNode& record) const;
    void formatEnum(std::ostream& out, const EnumNode& en) const;
    void formatInterface(std::ostream& out, const InterfaceNode& iface) const;
    void formatModule(std::ostream& out, const ModuleNode& module) const;
    void formatTest(std::ostream& out, const TestNode& test) const;
};

std::unique_ptr<ProgramNode> parseSourceProgram(const std::string& source,
                                                const std::string& virtualPath,
                                                SourceManager* sources = nullptr);

} // namespace afrilang
