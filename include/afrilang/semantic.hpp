#pragma once

#include "afrilang/ast.hpp"
#include "afrilang/types.hpp"

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace afrilang {

struct MethodSignature {
    std::string name;
    std::vector<AfrType> paramTypes;
    AfrType returnType;
    bool isConstructor = false;
};

struct FieldInfo {
    std::string name;
    AfrType type;
    bool isPublic = true;
};

struct ClassInfo {
    std::string name;
    std::string baseClass;
    std::unordered_map<std::string, FieldInfo> fields;
    std::unordered_map<std::string, MethodSignature> methods;
};

struct RecordInfo {
    std::string name;
    std::unordered_map<std::string, FieldInfo> fields;
};

struct ModuleInfo {
    std::string name;
    std::unordered_map<std::string, MethodSignature> functions;
    std::unordered_map<std::string, ClassInfo> classes;
    std::unordered_map<std::string, RecordInfo> records;
};

struct SemanticResult {
    std::unordered_map<std::string, AfrType> globalVariables;
    std::unordered_map<std::string, ClassInfo> classes;
    std::unordered_map<std::string, RecordInfo> records;
    std::unordered_map<std::string, MethodSignature> functions;
    std::unordered_map<std::string, ModuleInfo> modules;
    std::unordered_set<std::string> usedModules;
};

class SemanticAnalyzer {
public:
    explicit SemanticAnalyzer(const ProgramNode& program);

    SemanticResult analyze();

private:
    const ProgramNode& program_;
    SemanticResult result_;
    int loopDepth_ = 0;
    const ClassInfo* currentClass_ = nullptr;

    void registerRecords();
    void registerClasses();
    void registerModules();
    void analyzeProgram();
    void analyzeClass(const ClassNode& cls);
    void analyzeRecord(const RecordNode& record);
    void analyzeModule(const ModuleNode& module);
    void analyzeGlobalFunction(const FunctionNode& func);
    void analyzeFunctionBody(const FunctionNode& func, const ClassInfo* ownerClass);

    void analyzeStatement(const StatementNode& stmt,
                          std::unordered_map<std::string, AfrType>& scope,
                          bool isGlobalScope);
    AfrType analyzeExpression(const ExpressionNode& expr,
                              const std::unordered_map<std::string, AfrType>& scope);

    bool isNumeric(const AfrType& type) const;
    bool isBoolean(const AfrType& type) const;
    bool isAssignable(const AfrType& target, const AfrType& value) const;

    const ClassInfo* findClass(const std::string& name) const;
    const RecordInfo* findRecord(const std::string& name) const;
    const FieldInfo* findField(const ClassInfo& cls, const std::string& fieldName) const;
    MethodSignature* findMethod(const std::string& className, const std::string& methodName);
    const MethodSignature* findMethod(const std::string& className,
                                      const std::string& methodName) const;
    const MethodSignature* findFunction(const std::string& name) const;

    [[noreturn]] void error(const std::string& message, int line = 0, int column = 0) const;
    [[noreturn]] void errorAt(const ASTNode& node, const std::string& message) const;
};

} // namespace afrilang
