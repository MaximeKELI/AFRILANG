#include "afrilang/semantic.hpp"

#include "afrilang/error.hpp"

namespace afrilang {

SemanticAnalyzer::SemanticAnalyzer(const ProgramNode& program) : program_(program) {}

SemanticResult SemanticAnalyzer::analyze() {
    registerClasses();
    analyzeProgram();
    return result_;
}

void SemanticAnalyzer::registerClasses() {
    for (const auto& cls : program_.classes) {
        if (result_.classes.count(cls->name)) {
            error("Classe '" + cls->name + "' déjà définie");
        }

        ClassInfo info;
        info.name = cls->name;
        info.baseClass = cls->baseClassName;

        for (const auto& method : cls->methods) {
            MethodSignature sig;
            sig.name = method->name;
            sig.returnType = method->returnTypeName.empty()
                ? AfrType::voidType()
                : typeFromName(method->returnTypeName);

            for (const auto& param : method->parameters) {
                sig.paramTypes.push_back(typeFromName(param.typeName));
            }

            info.methods[method->name] = std::move(sig);
        }

        result_.classes[cls->name] = std::move(info);
    }

    for (const auto& cls : program_.classes) {
        if (!cls->baseClassName.empty()) {
            if (!result_.classes.count(cls->baseClassName)) {
                error("Classe de base '" + cls->baseClassName + "' introuvable pour '" + cls->name + "'");
            }
        }
    }
}

void SemanticAnalyzer::analyzeProgram() {
    for (const auto& cls : program_.classes) {
        analyzeClass(*cls);
    }

    for (const auto& func : program_.functions) {
        analyzeGlobalFunction(*func);
    }

    std::unordered_map<std::string, AfrType> scope;
    for (const auto& stmt : program_.statements) {
        analyzeStatement(*stmt, scope, true);
    }
}

void SemanticAnalyzer::analyzeGlobalFunction(const FunctionNode& func) {
    if (result_.functions.count(func.name)) {
        error("Fonction '" + func.name + "' déjà définie");
    }

    MethodSignature sig;
    sig.name = func.name;
    sig.returnType = func.returnTypeName.empty()
        ? AfrType::voidType()
        : typeFromName(func.returnTypeName);
    for (const auto& param : func.parameters) {
        sig.paramTypes.push_back(typeFromName(param.typeName));
    }
    result_.functions[func.name] = sig;

    analyzeFunctionBody(func, nullptr);
}

void SemanticAnalyzer::analyzeClass(const ClassNode& cls) {
    for (const auto& method : cls.methods) {
        analyzeFunctionBody(*method, &result_.classes.at(cls.name));
    }
}

void SemanticAnalyzer::analyzeFunctionBody(const FunctionNode& func, const ClassInfo* ownerClass) {
    std::unordered_map<std::string, AfrType> scope;

    for (const auto& param : func.parameters) {
        scope[param.name] = typeFromName(param.typeName);
    }

    AfrType declaredReturn = func.returnTypeName.empty()
        ? AfrType::voidType()
        : typeFromName(func.returnTypeName);

    bool hasReturn = false;

    for (const auto& stmt : func.body) {
        if (dynamic_cast<const ReturnStatementNode*>(stmt.get())) {
            hasReturn = true;
        }
        analyzeStatement(*stmt, scope, false);
    }

    if (declaredReturn.kind != TypeKind::Void && !hasReturn) {
        error("Fonction '" + func.name + "' déclare un retour '" +
              func.returnTypeName + "' mais ne contient pas de 'return'");
    }

    (void)ownerClass;
}

void SemanticAnalyzer::analyzeStatement(const StatementNode& stmt,
                                        std::unordered_map<std::string, AfrType>& scope,
                                        bool isGlobalScope) {
    if (const auto* assign = dynamic_cast<const AssignStatementNode*>(&stmt)) {
        AfrType valueType = analyzeExpression(*assign->value, scope);

        if (dynamic_cast<const NewExpressionNode*>(assign->value.get())) {
            const auto* newExpr = static_cast<const NewExpressionNode*>(assign->value.get());
            if (!result_.classes.count(newExpr->className)) {
                error("Classe '" + newExpr->className + "' introuvable");
            }
            valueType = AfrType::classType(newExpr->className);
        }

        scope[assign->name] = valueType;
        if (isGlobalScope) {
            result_.globalVariables[assign->name] = valueType;
        }
        return;
    }

    if (const auto* say = dynamic_cast<const SayStatementNode*>(&stmt)) {
        analyzeExpression(*say->value, scope);
        return;
    }

    if (const auto* ret = dynamic_cast<const ReturnStatementNode*>(&stmt)) {
        analyzeExpression(*ret->value, scope);
        return;
    }

    if (const auto* ifStmt = dynamic_cast<const IfStatementNode*>(&stmt)) {
        analyzeExpression(*ifStmt->condition, scope);
        for (const auto& bodyStmt : ifStmt->body) {
            analyzeStatement(*bodyStmt, scope, isGlobalScope);
        }
        return;
    }

    if (const auto* repeat = dynamic_cast<const RepeatStatementNode*>(&stmt)) {
        AfrType countType = analyzeExpression(*repeat->count, scope);
        if (countType.kind != TypeKind::Number) {
            error("Le compteur de 'repeat' doit être un nombre");
        }
        for (const auto& bodyStmt : repeat->body) {
            analyzeStatement(*bodyStmt, scope, isGlobalScope);
        }
        return;
    }

    if (const auto* exprStmt = dynamic_cast<const ExpressionStatementNode*>(&stmt)) {
        analyzeExpression(*exprStmt->expression, scope);
        return;
    }
}

AfrType SemanticAnalyzer::analyzeExpression(const ExpressionNode& expr,
                                            const std::unordered_map<std::string, AfrType>& scope) {
    if (const auto* str = dynamic_cast<const StringLiteralNode*>(&expr)) {
        (void)str;
        return AfrType::text();
    }

    if (const auto* num = dynamic_cast<const NumberLiteralNode*>(&expr)) {
        (void)num;
        return AfrType::number();
    }

    if (const auto* id = dynamic_cast<const IdentifierNode*>(&expr)) {
        auto it = scope.find(id->name);
        if (it != scope.end()) return it->second;

        auto globalIt = result_.globalVariables.find(id->name);
        if (globalIt != result_.globalVariables.end()) return globalIt->second;

        error("Variable '" + id->name + "' non déclarée");
    }

    if (const auto* bin = dynamic_cast<const BinaryOpNode*>(&expr)) {
        AfrType left = analyzeExpression(*bin->left, scope);
        AfrType right = analyzeExpression(*bin->right, scope);

        if (bin->op == "&&" || bin->op == "||") {
            return AfrType::number();
        }

        if (bin->op == "+" && left.kind == TypeKind::Text && right.kind == TypeKind::Text) {
            return AfrType::text();
        }

        if (isNumeric(left) && isNumeric(right)) {
            return AfrType::number();
        }

        error("Opération incompatible entre types pour l'opérateur '" + bin->op + "'");
    }

    if (const auto* unary = dynamic_cast<const UnaryOpNode*>(&expr)) {
        AfrType operand = analyzeExpression(*unary->operand, scope);
        if (unary->op == "-") {
            if (!isNumeric(operand)) error("Opérateur '-' requiert un nombre");
            return AfrType::number();
        }
        return AfrType::number();
    }

    if (const auto* call = dynamic_cast<const CallExpressionNode*>(&expr)) {
        if (const auto* member = dynamic_cast<const MemberAccessNode*>(call->callee.get())) {
            AfrType objectType = analyzeExpression(*member->object, scope);

            if (objectType.kind != TypeKind::Class) {
                error("Appel de méthode sur un type non objet");
            }

            const MethodSignature* sig = findMethod(objectType.className, member->member);
            if (!sig) {
                error("Méthode '" + member->member + "' introuvable dans '" + objectType.className + "'");
            }

            if (call->arguments.size() != sig->paramTypes.size()) {
                error("Méthode '" + member->member + "' attend " +
                      std::to_string(sig->paramTypes.size()) + " argument(s), reçu " +
                      std::to_string(call->arguments.size()));
            }

            for (std::size_t i = 0; i < call->arguments.size(); ++i) {
                AfrType argType = analyzeExpression(*call->arguments[i], scope);
                if (!isAssignable(sig->paramTypes[i], argType)) {
                    error("Type incompatible pour l'argument " + std::to_string(i + 1) +
                          " de '" + member->member + "'");
                }
            }

            return sig->returnType;
        }

        if (const auto* id = dynamic_cast<const IdentifierNode*>(call->callee.get())) {
            auto fnIt = result_.functions.find(id->name);
            if (fnIt == result_.functions.end()) {
                error("Fonction '" + id->name + "' introuvable");
            }

            const MethodSignature& sig = fnIt->second;
            if (call->arguments.size() != sig.paramTypes.size()) {
                error("Fonction '" + id->name + "' attend " +
                      std::to_string(sig.paramTypes.size()) + " argument(s), reçu " +
                      std::to_string(call->arguments.size()));
            }

            for (std::size_t i = 0; i < call->arguments.size(); ++i) {
                AfrType argType = analyzeExpression(*call->arguments[i], scope);
                if (!isAssignable(sig.paramTypes[i], argType)) {
                    error("Type incompatible pour l'argument " + std::to_string(i + 1) +
                          " de '" + id->name + "'");
                }
            }

            return sig.returnType;
        }

        error("Appel de fonction invalide");
    }

    if (const auto* member = dynamic_cast<const MemberAccessNode*>(&expr)) {
        AfrType objectType = analyzeExpression(*member->object, scope);
        if (objectType.kind != TypeKind::Class) {
            error("Accès membre sur un type non objet");
        }
        if (!findMethod(objectType.className, member->member)) {
            error("Membre '" + member->member + "' introuvable dans '" + objectType.className + "'");
        }
        return AfrType::voidType();
    }

    if (const auto* newExpr = dynamic_cast<const NewExpressionNode*>(&expr)) {
        if (!result_.classes.count(newExpr->className)) {
            error("Classe '" + newExpr->className + "' introuvable");
        }
        return AfrType::classType(newExpr->className);
    }

    return AfrType::voidType();
}

bool SemanticAnalyzer::isNumeric(const AfrType& type) const {
    return type.kind == TypeKind::Number;
}

bool SemanticAnalyzer::isAssignable(const AfrType& target, const AfrType& value) const {
    if (target == value) return true;
    if (target.kind == TypeKind::Number && value.kind == TypeKind::Number) return true;
    if (target.kind == TypeKind::Text && value.kind == TypeKind::Text) return true;
    if (target.kind == TypeKind::Class && value.kind == TypeKind::Class) {
        return target.className == value.className;
    }
    return false;
}

const ClassInfo* SemanticAnalyzer::findClass(const std::string& name) const {
    auto it = result_.classes.find(name);
    return it != result_.classes.end() ? &it->second : nullptr;
}

const MethodSignature* SemanticAnalyzer::findMethod(const std::string& className,
                                                    const std::string& methodName) const {
    const ClassInfo* cls = findClass(className);
    while (cls) {
        auto it = cls->methods.find(methodName);
        if (it != cls->methods.end()) return &it->second;

        if (cls->baseClass.empty()) break;
        cls = findClass(cls->baseClass);
    }
    return nullptr;
}

MethodSignature* SemanticAnalyzer::findMethod(const std::string& className,
                                              const std::string& methodName) {
    return const_cast<MethodSignature*>(
        static_cast<const SemanticAnalyzer*>(this)->findMethod(className, methodName));
}

[[noreturn]] void SemanticAnalyzer::error(const std::string& message, int line, int column) const {
    throw CompileError(message, line, column);
}

} // namespace afrilang
