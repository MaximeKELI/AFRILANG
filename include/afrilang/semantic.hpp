#pragma once

#include "afrilang/ast.hpp"
#include "afrilang/types.hpp"

#include <string>
#include <unordered_map>
#include <vector>

namespace afrilang {

struct MethodSignature {
    std::string name;
    std::vector<AfrType> paramTypes;
    AfrType returnType;
};

struct ClassInfo {
    std::string name;
    std::string baseClass;
    std::unordered_map<std::string, MethodSignature> methods;
};

struct SemanticResult {
    std::unordered_map<std::string, AfrType> globalVariables;
    std::unordered_map<std::string, ClassInfo> classes;
    std::unordered_map<std::string, MethodSignature> functions;
};

class SemanticAnalyzer {
public:
    explicit SemanticAnalyzer(const ProgramNode& program);

    SemanticResult analyze();

private:
    const ProgramNode& program_;
    SemanticResult result_;

    void registerClasses();
    void analyzeProgram();
    void analyzeClass(const ClassNode& cls);
    void analyzeGlobalFunction(const FunctionNode& func);
    void analyzeFunctionBody(const FunctionNode& func, const ClassInfo* ownerClass);

    void analyzeStatement(const StatementNode& stmt,
                          std::unordered_map<std::string, AfrType>& scope,
                          bool isGlobalScope);
    AfrType analyzeExpression(const ExpressionNode& expr,
                              const std::unordered_map<std::string, AfrType>& scope);

    AfrType inferLiteralType(const ExpressionNode& expr) const;
    bool isNumeric(const AfrType& type) const;
    bool isAssignable(const AfrType& target, const AfrType& value) const;

    const ClassInfo* findClass(const std::string& name) const;
    MethodSignature* findMethod(const std::string& className, const std::string& methodName);
    const MethodSignature* findMethod(const std::string& className,
                                      const std::string& methodName) const;

    [[noreturn]] void error(const std::string& message, int line = 0, int column = 0) const;
};

} // namespace afrilang
