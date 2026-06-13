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
    void setSourceFile(std::string path) { sourceFilePath_ = std::move(path); }
    void setDebugSymbols(bool enabled) { debugSymbols_ = enabled; }
    void setCrossTarget(std::string target) { crossTarget_ = std::move(target); }

private:
    const ProgramNode& program_;
    const SemanticResult& semantic_;
    std::string runtimeDir_;
    std::string sourceFilePath_;
    bool debugSymbols_ = true;
    std::string crossTarget_ = "native";
    mutable std::unordered_set<std::string> linkLibraries_;

    mutable const FunctionNode* currentFunction_ = nullptr;
    mutable bool inTest_ = false;

    void emitHeader(std::ostream& out) const;
    void emitRecords(std::ostream& out) const;
    void emitEnums(std::ostream& out) const;
    void emitInterfaces(std::ostream& out) const;
    void emitClasses(std::ostream& out) const;
    void emitModules(std::ostream& out) const;
    void emitGlobalFunctions(std::ostream& out) const;
    void emitExterns(std::ostream& out) const;
    void emitTests(std::ostream& out) const;
    void emitMain(std::ostream& out) const;

    void emitClass(std::ostream& out, const ClassNode& cls) const;
    void emitFunction(std::ostream& out, const FunctionNode& func,
                      const ClassInfo* ownerClass, int indentLevel) const;
    void emitStatement(std::ostream& out, const StatementNode& stmt, int indent,
                       const ClassInfo* ownerClass) const;
    void emitExpression(std::ostream& out, const ExpressionNode& expr,
                        const ClassInfo* ownerClass) const;

    std::string resolveVariableType(const std::string& name) const;
    AfrType inferExpressionAfrType(const ExpressionNode& expr) const;
    std::string inferExpressionType(const ExpressionNode& expr) const;
    std::string classPrefix(const ClassInfo* ownerClass) const;

    void emitLineDirective(std::ostream& out, const ASTNode& node, int indentLevel) const;
    static void indent(std::ostream& out, int level);
    static std::string escapeString(const std::string& s);
    static std::string paramList(const FunctionNode& func);
    static std::string functionReturnCpp(const FunctionNode& func);
    static std::string resultTypeAlias(const std::string& innerTypeName);
    static std::string sanitizeTestName(const std::string& name);
    static std::string ffiTypeToCpp(const std::string& typeName);
    static std::string compilerForTarget(const std::string& target);
    static std::string linkFlagForLibrary(const std::string& library);
    static void collectLinkLibrary(const std::string& library,
                                   std::unordered_set<std::string>& libs);

    bool usesStdlibModule(const std::string& name) const;
    void emitStdlibFunction(std::ostream& out, const std::string& moduleName,
                            const FunctionNode& func, int indentLevel) const;
};

} // namespace afrilang
