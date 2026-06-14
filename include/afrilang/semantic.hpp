#pragma once

#include "afrilang/ast.hpp"
#include "afrilang/diagnostics.hpp"
#include "afrilang/types.hpp"

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace afrilang {

struct MethodSignature {
    std::string name;
    std::vector<std::string> typeParams;
    std::vector<AfrType> paramTypes;
    AfrType returnType;
    std::size_t requiredParamCount = 0;
    bool isConstructor = false;
    bool returnsResult = false;
    bool isExtern = false;
    bool isStatic = false;
    bool isAbstract = false;
    bool isFinal = false;
    bool isAsync = false;
    std::string externLibrary;
    bool modulePrivate = false;
    bool isOperator = false;
    std::string operatorSymbol;
};

struct FieldInfo {
    std::string name;
    AfrType type;
    FieldVisibility visibility = FieldVisibility::Public;
    bool isStatic = false;
};

struct PropertyInfo {
    std::string name;
    AfrType type;
    FieldVisibility visibility = FieldVisibility::Public;
};

struct ClassInfo {
    std::string name;
    std::string baseClass;
    bool isAbstract = false;
    bool isFinal = false;
    bool modulePrivate = false;
    std::vector<std::string> interfaceNames;
    std::vector<std::string> typeParams;
    std::unordered_map<std::string, FieldInfo> fields;
    std::unordered_map<std::string, PropertyInfo> properties;
    std::unordered_map<std::string, MethodSignature> methods;
    std::unordered_map<std::string, MethodSignature> operators;
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

struct InterfaceInfo {
    std::string name;
    std::unordered_map<std::string, MethodSignature> methods;
};

struct EnumCaseInfo {
    std::string name;
    std::vector<std::pair<std::string, AfrType>> fields;
};

struct EnumInfo {
    std::string name;
    std::unordered_map<std::string, EnumCaseInfo> cases;
};

struct SemanticResult {
    std::unordered_map<std::string, AfrType> globalVariables;
    std::unordered_set<std::string> constVariables;
    std::unordered_map<std::string, ClassInfo> classes;
    std::unordered_map<std::string, InterfaceInfo> interfaces;
    std::unordered_map<std::string, RecordInfo> records;
    std::unordered_map<std::string, EnumInfo> enums;
    std::unordered_map<std::string, MethodSignature> functions;
    std::unordered_map<std::string, ModuleInfo> modules;
    std::unordered_set<std::string> usedModules;
    bool usesAsync = false;
    bool usesUi = false;
    std::vector<LintWarning> warnings;
};

class SemanticAnalyzer {
public:
    SemanticAnalyzer(const ProgramNode& program,
                     const SourceManager* sources = nullptr,
                     std::string currentFile = "");

    SemanticResult analyze();

private:
    const ProgramNode& program_;
    const SourceManager* sources_;
    std::string currentFile_;
    std::string currentModuleName_;
    SemanticResult result_;
    int loopDepth_ = 0;
    int asyncContextDepth_ = 0;
    const ClassInfo* currentClass_ = nullptr;
    std::unordered_set<std::string> constVariables_;

    void registerRecords();
    void registerEnums();
    void registerInterfaces();
    void registerClasses();
    void registerModules();
    void registerExterns();
    void analyzeProgram();
    void analyzeClass(const ClassNode& cls);
    void analyzeTest(const TestNode& test);
    void analyzeRecord(const RecordNode& record);
    void analyzeModule(const ModuleNode& module);
    void analyzeGlobalFunction(const FunctionNode& func);
    void analyzeFunctionBody(const FunctionNode& func, const ClassInfo* ownerClass);

    void analyzeStatement(const StatementNode& stmt,
                          std::unordered_map<std::string, AfrType>& scope,
                          bool isGlobalScope);
    AfrType analyzeExpression(const ExpressionNode& expr,
                              const std::unordered_map<std::string, AfrType>& scope);
    AfrType inferReturnTypeFromBlock(
        const std::vector<std::unique_ptr<StatementNode>>& body,
        const std::unordered_map<std::string, AfrType>& scope,
        const ASTNode& at);

    bool isNumeric(const AfrType& type) const;
    bool isBoolean(const AfrType& type) const;
    bool isAssignable(const AfrType& target, const AfrType& value) const;
    bool isConcreteTypeName(const std::string& name) const;

    const ClassInfo* findClass(const std::string& name) const;
    const RecordInfo* findRecord(const std::string& name) const;
    const FieldInfo* findField(const ClassInfo& cls, const std::string& fieldName) const;
    const FieldInfo* findFieldWithOwner(const ClassInfo& cls, const std::string& fieldName,
                                        const ClassInfo*& ownerClass) const;
    const PropertyInfo* findProperty(const ClassInfo& cls, const std::string& name) const;
    bool canAccessField(const FieldInfo& field, const ClassInfo& ownerClass,
                        const ClassInfo* accessingClass) const;
    bool isSubclassOf(const std::string& derived, const std::string& base) const;
    bool implementsInterface(const std::string& className, const std::string& ifaceName) const;
    bool signaturesCompatible(const MethodSignature& required, const MethodSignature& impl) const;
    MethodSignature* findMethod(const std::string& className, const std::string& methodName);
    const MethodSignature* findMethod(const std::string& className,
                                      const std::string& methodName) const;
    const MethodSignature* findOperator(const std::string& className,
                                        const std::string& opSymbol) const;
    const MethodSignature* findFunction(const std::string& name) const;
    const EnumInfo* findEnum(const std::string& name) const;
    AfrType resolveTypeName(const std::string& name) const;
    AfrType resolveTypeForGeneric(const std::string& name,
                                  const std::vector<std::string>& typeParams) const;
    AfrType resolveFunctionReturnType(const FunctionNode& func) const;
    AfrType resolveFunctionReturnTypeWithParams(
        const FunctionNode& func, const std::vector<std::string>& typeParams) const;
    AfrType substituteType(AfrType type,
                           const std::unordered_map<std::string, AfrType>& subst) const;
    std::unordered_map<std::string, AfrType> inferGenericSubst(
        const MethodSignature& sig,
        const std::vector<AfrType>& argTypes,
        const ASTNode& at) const;

    std::vector<std::string> activeTypeParams_;

    [[noreturn]] void error(const std::string& message, int line = 0, int column = 0) const;
    [[noreturn]] void errorAt(const ASTNode& node, const std::string& message,
                              const std::vector<std::string>& nameHints = {}) const;
};

} // namespace afrilang
