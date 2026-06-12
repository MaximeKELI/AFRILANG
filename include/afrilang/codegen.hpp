#pragma once

#include "afrilang/ast.hpp"
#include "afrilang/semantic.hpp"

#include <ostream>
#include <string>
#include <unordered_set>

namespace afrilang {

class CodeGenerator {
public:
    CodeGenerator(const ProgramNode& program, const SemanticResult& semantic);

    void generate(std::ostream& out) const;
    std::string generate() const;

    bool compileToExecutable(const std::string& outputPath,
                             const std::string& executablePath) const;

    void setRuntimeDir(std::string dir) { runtimeDir_ = std::move(dir); }

private:
    const ProgramNode& program_;
    const SemanticResult& semantic_;
    std::string runtimeDir_;

    void emitHeader(std::ostream& out) const;
    void emitRecords(std::ostream& out) const;
    void emitClasses(std::ostream& out) const;
    void emitModules(std::ostream& out) const;
    void emitGlobalFunctions(std::ostream& out) const;
    void emitMain(std::ostream& out) const;

    void emitClass(std::ostream& out, const ClassNode& cls) const;
    void emitFunction(std::ostream& out, const FunctionNode& func,
                      const ClassInfo* ownerClass, int indentLevel) const;
    void emitStatement(std::ostream& out, const StatementNode& stmt, int indent,
                       const ClassInfo* ownerClass) const;
    void emitExpression(std::ostream& out, const ExpressionNode& expr,
                        const ClassInfo* ownerClass) const;

    std::string resolveVariableType(const std::string& name) const;
    std::string inferExpressionType(const ExpressionNode& expr) const;
    std::string classPrefix(const ClassInfo* ownerClass) const;

    static void indent(std::ostream& out, int level);
    static std::string escapeString(const std::string& s);
    static std::string paramList(const FunctionNode& func);

    bool usesStdlibModule(const std::string& name) const;
    void emitStdlibFunction(std::ostream& out, const std::string& moduleName,
                            const FunctionNode& func, int indentLevel) const;
};

} // namespace afrilang
