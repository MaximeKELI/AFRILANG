#pragma once

#include "afrilang/ast.hpp"
#include "afrilang/semantic.hpp"

#include <ostream>
#include <string>

namespace afrilang {

class CodeGenerator {
public:
    CodeGenerator(const ProgramNode& program, const SemanticResult& semantic);

    void generate(std::ostream& out) const;
    std::string generate() const;

    bool compileToExecutable(const std::string& outputPath,
                             const std::string& executablePath) const;

private:
    const ProgramNode& program_;
    const SemanticResult& semantic_;

    void emitHeader(std::ostream& out) const;
    void emitClasses(std::ostream& out) const;
    void emitGlobalFunctions(std::ostream& out) const;
    void emitMain(std::ostream& out) const;

    void emitStatement(std::ostream& out, const StatementNode& stmt, int indent) const;
    void emitExpression(std::ostream& out, const ExpressionNode& expr) const;

    std::string resolveVariableType(const std::string& name) const;
    std::string inferExpressionType(const ExpressionNode& expr) const;

    static void indent(std::ostream& out, int level);
    static std::string escapeString(const std::string& s);
    static std::string paramList(const FunctionNode& func);
};

} // namespace afrilang
