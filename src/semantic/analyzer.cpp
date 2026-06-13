#include "afrilang/semantic.hpp"

#include "afrilang/error.hpp"

namespace afrilang {

SemanticAnalyzer::SemanticAnalyzer(const ProgramNode& program,
                                   const SourceManager* sources,
                                   std::string currentFile)
    : program_(program)
    , sources_(sources)
    , currentFile_(std::move(currentFile)) {}

SemanticResult SemanticAnalyzer::analyze() {
    registerRecords();
    registerInterfaces();
    registerClasses();
    registerModules();
    analyzeProgram();
    return result_;
}

static AfrType resolveFunctionReturnType(const FunctionNode& func) {
    if (func.returnTypeName.empty()) return AfrType::voidType();
    AfrType inner = typeFromName(func.returnTypeName);
    return func.returnsResult ? AfrType::resultType(inner) : inner;
}

void SemanticAnalyzer::registerInterfaces() {
    for (const auto& iface : program_.interfaces) {
        if (result_.interfaces.count(iface->name)) {
            errorAt(*iface, "Interface '" + iface->name + "' déjà définie");
        }

        InterfaceInfo info;
        info.name = iface->name;

        for (const auto& method : iface->methods) {
            MethodSignature sig;
            sig.name = method->name;
            sig.returnType = resolveFunctionReturnType(*method);
            sig.returnsResult = method->returnsResult;
            for (const auto& param : method->parameters) {
                sig.paramTypes.push_back(typeFromName(param.typeName));
            }
            info.methods[method->name] = std::move(sig);
        }

        result_.interfaces[iface->name] = std::move(info);
    }
}

void SemanticAnalyzer::registerRecords() {
    for (const auto& record : program_.records) {
        if (result_.records.count(record->name)) {
            errorAt(*record, "Record '" + record->name + "' déjà défini");
        }

        RecordInfo info;
        info.name = record->name;
        for (const auto& field : record->fields) {
            FieldInfo fi;
            fi.name = field.name;
            fi.type = typeFromName(field.typeName);
            fi.isPublic = true;
            info.fields[field.name] = std::move(fi);
        }
        result_.records[record->name] = std::move(info);
    }

    for (const auto& module : program_.modules) {
        for (const auto& record : module->records) {
            if (result_.records.count(record->name)) {
                errorAt(*record, "Record '" + record->name + "' déjà défini");
            }
            RecordInfo info;
            info.name = record->name;
            for (const auto& field : record->fields) {
                FieldInfo fi;
                fi.name = field.name;
                fi.type = typeFromName(field.typeName);
                fi.isPublic = true;
                info.fields[field.name] = std::move(fi);
            }
            result_.records[record->name] = std::move(info);
            result_.modules[module->name].records[record->name] = result_.records.at(record->name);
        }
    }
}

void SemanticAnalyzer::registerClasses() {
    for (const auto& cls : program_.classes) {
        if (result_.classes.count(cls->name)) {
            errorAt(*cls, "Classe '" + cls->name + "' déjà définie");
        }

        ClassInfo info;
        info.name = cls->name;
        info.baseClass = cls->baseClassName;

        for (const auto& field : cls->fields) {
            FieldInfo fi;
            fi.name = field.name;
            fi.type = typeFromName(field.typeName);
            fi.isPublic = field.isPublic;
            info.fields[field.name] = std::move(fi);
        }

        for (const auto& method : cls->methods) {
            MethodSignature sig;
            sig.name = method->name;
            sig.isConstructor = (method->name == "init");
            sig.returnType = resolveFunctionReturnType(*method);
            sig.returnsResult = method->returnsResult;

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
                errorAt(*cls, "Classe de base '" + cls->baseClassName + "' introuvable pour '" + cls->name + "'");
            }
        }
    }

    for (const auto& module : program_.modules) {
        ModuleInfo modInfo;
        modInfo.name = module->name;
        if (result_.modules.count(module->name)) {
            modInfo.records = result_.modules[module->name].records;
        }

        for (const auto& cls : module->classes) {
            if (result_.classes.count(cls->name)) {
                errorAt(*cls, "Classe '" + cls->name + "' déjà définie");
            }
            ClassInfo info;
            info.name = cls->name;
            info.baseClass = cls->baseClassName;
            for (const auto& field : cls->fields) {
                FieldInfo fi;
                fi.name = field.name;
                fi.type = typeFromName(field.typeName);
                fi.isPublic = field.isPublic;
                info.fields[field.name] = std::move(fi);
            }
            for (const auto& method : cls->methods) {
                MethodSignature sig;
                sig.name = method->name;
                sig.isConstructor = (method->name == "init");
                sig.returnType = resolveFunctionReturnType(*method);
                sig.returnsResult = method->returnsResult;
                for (const auto& param : method->parameters) {
                    sig.paramTypes.push_back(typeFromName(param.typeName));
                }
                info.methods[method->name] = std::move(sig);
            }
            result_.classes[cls->name] = info;
            modInfo.classes[cls->name] = info;
        }

        for (const auto& func : module->functions) {
            MethodSignature sig;
            sig.name = func->name;
            sig.returnType = resolveFunctionReturnType(*func);
            sig.returnsResult = func->returnsResult;
            for (const auto& param : func->parameters) {
                sig.paramTypes.push_back(typeFromName(param.typeName));
            }
            modInfo.functions[func->name] = sig;
        }

        for (const auto& record : module->records) {
            modInfo.records[record->name] = result_.records.at(record->name);
        }

        result_.modules[module->name] = std::move(modInfo);
    }
}

void SemanticAnalyzer::registerModules() {
    for (const auto& module : program_.modules) {
        if (result_.modules.count(module->name) && result_.modules[module->name].name.empty()) {
            // already registered
        }
    }
}

void SemanticAnalyzer::analyzeProgram() {
    for (const auto& record : program_.records) {
        analyzeRecord(*record);
    }

    for (const auto& cls : program_.classes) {
        analyzeClass(*cls);
    }

    for (const auto& module : program_.modules) {
        analyzeModule(*module);
    }

    for (const auto& func : program_.functions) {
        analyzeGlobalFunction(*func);
    }

    for (const auto& test : program_.tests) {
        analyzeTest(*test);
    }

    std::unordered_map<std::string, AfrType> scope;
    for (const auto& stmt : program_.statements) {
        analyzeStatement(*stmt, scope, true);
    }
}

void SemanticAnalyzer::analyzeRecord(const RecordNode& record) {
    (void)record;
}

void SemanticAnalyzer::analyzeModule(const ModuleNode& module) {
    const bool isStdlib = (module.name == "io" || module.name == "json");

    for (const auto& cls : module.classes) {
        analyzeClass(*cls);
    }
    if (isStdlib) return;

    for (const auto& func : module.functions) {
        analyzeFunctionBody(*func, nullptr);
    }
}

void SemanticAnalyzer::analyzeGlobalFunction(const FunctionNode& func) {
    if (result_.functions.count(func.name)) {
        errorAt(func, "Fonction '" + func.name + "' déjà définie");
    }

    MethodSignature sig;
    sig.name = func.name;
    sig.returnType = resolveFunctionReturnType(func);
    sig.returnsResult = func.returnsResult;
    for (const auto& param : func.parameters) {
        sig.paramTypes.push_back(typeFromName(param.typeName));
    }
    result_.functions[func.name] = sig;

    analyzeFunctionBody(func, nullptr);
}

void SemanticAnalyzer::analyzeClass(const ClassNode& cls) {
    for (const auto& ifaceName : cls.interfaceNames) {
        if (!result_.interfaces.count(ifaceName)) {
            errorAt(cls, "Interface '" + ifaceName + "' introuvable");
        }
        const InterfaceInfo& iface = result_.interfaces.at(ifaceName);
        for (const auto& [methodName, sig] : iface.methods) {
            const MethodSignature* impl = findMethod(cls.name, methodName);
            if (!impl) {
                errorAt(cls, "Classe '" + cls.name + "' n'implémente pas '" +
                          methodName + "' de l'interface '" + ifaceName + "'");
            }
        }
    }

    const ClassInfo* savedClass = currentClass_;
    currentClass_ = &result_.classes.at(cls.name);

    for (const auto& method : cls.methods) {
        analyzeFunctionBody(*method, currentClass_);
    }

    currentClass_ = savedClass;
}

void SemanticAnalyzer::analyzeTest(const TestNode& test) {
    std::unordered_map<std::string, AfrType> scope;
    for (const auto& stmt : test.body) {
        analyzeStatement(*stmt, scope, false);
    }
}

void SemanticAnalyzer::analyzeFunctionBody(const FunctionNode& func, const ClassInfo* ownerClass) {
    std::unordered_map<std::string, AfrType> scope;

    if (ownerClass) {
        for (const auto& [name, field] : ownerClass->fields) {
            scope[name] = field.type;
        }
    }

    for (const auto& param : func.parameters) {
        scope[param.name] = typeFromName(param.typeName);
    }

    AfrType declaredReturn = resolveFunctionReturnType(func);

    bool hasReturn = func.name == "init";
    const ClassInfo* savedClass = currentClass_;
    if (ownerClass) currentClass_ = ownerClass;

    for (const auto& stmt : func.body) {
        if (dynamic_cast<const ReturnStatementNode*>(stmt.get())) {
            hasReturn = true;
        }
        analyzeStatement(*stmt, scope, false);
    }

    if (ownerClass) currentClass_ = savedClass;

    if (declaredReturn.kind != TypeKind::Void && !hasReturn && func.name != "init") {
        errorAt(func, "Fonction '" + func.name + "' déclare un retour '" +
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
                errorAt(*assign, "Classe '" + newExpr->className + "' introuvable");
            }
            valueType = AfrType::classType(newExpr->className);
        }

        if (dynamic_cast<const EmptyListNode*>(assign->value.get())) {
            const auto* empty = static_cast<const EmptyListNode*>(assign->value.get());
            valueType = AfrType::listType(typeFromName(empty->elementTypeName));
        }

        if (dynamic_cast<const ListLiteralNode*>(assign->value.get())) {
            const auto* list = static_cast<const ListLiteralNode*>(assign->value.get());
            if (!list->elements.empty()) {
                AfrType elemType = analyzeExpression(*list->elements[0], scope);
                valueType = AfrType::listType(elemType);
            } else if (!assign->typeName.empty()) {
                AfrType declared = typeFromName(assign->typeName);
                if (declared.kind == TypeKind::List) {
                    valueType = declared;
                } else {
                    errorAt(*assign, "Impossible d'inférer le type d'une liste vide");
                }
            } else {
                errorAt(*assign, "Impossible d'inférer le type d'une liste vide");
            }
        }

        if (!assign->typeName.empty()) {
            AfrType declared = typeFromName(assign->typeName);
            if (!isAssignable(declared, valueType)) {
                errorAt(*assign, "Type incompatible pour '" + assign->name + "'");
            }
            valueType = declared;
        }

        scope[assign->name] = valueType;
        if (isGlobalScope) {
            result_.globalVariables[assign->name] = valueType;
        }
        return;
    }

    if (const auto* set = dynamic_cast<const SetStatementNode*>(&stmt)) {
        AfrType valueType = analyzeExpression(*set->value, scope);

        if (const auto* id = dynamic_cast<const IdentifierNode*>(set->target.get())) {
            auto it = scope.find(id->name);
            if (it == scope.end()) {
                auto globalIt = result_.globalVariables.find(id->name);
                if (globalIt == result_.globalVariables.end()) {
                    errorAt(*set, "Variable '" + id->name + "' non déclarée");
                }
                if (!isAssignable(globalIt->second, valueType)) {
                    errorAt(*set, "Type incompatible pour '" + id->name + "'");
                }
            } else {
                if (!isAssignable(it->second, valueType)) {
                    errorAt(*set, "Type incompatible pour '" + id->name + "'");
                }
            }
            return;
        }

        if (const auto* member = dynamic_cast<const MemberAccessNode*>(set->target.get())) {
            if (dynamic_cast<const ThisExpressionNode*>(member->object.get())) {
                if (!currentClass_) {
                    errorAt(*set, "'this' utilisé en dehors d'une méthode");
                }
                const FieldInfo* field = findField(*currentClass_, member->member);
                if (!field) {
                    errorAt(*set, "Champ '" + member->member + "' introuvable");
                }
                if (!isAssignable(field->type, valueType)) {
                    errorAt(*set, "Type incompatible pour le champ '" + member->member + "'");
                }
                return;
            }

            AfrType objectType = analyzeExpression(*member->object, scope);
            if (objectType.kind != TypeKind::Class) {
                errorAt(*set, "Assignation de champ sur un type non objet");
            }
            const ClassInfo* cls = findClass(objectType.className);
            const FieldInfo* field = findField(*cls, member->member);
            if (!field) {
                errorAt(*set, "Champ '" + member->member + "' introuvable");
            }
            if (!field->isPublic) {
                errorAt(*set, "Champ privé '" + member->member + "' inaccessible");
            }
            if (!isAssignable(field->type, valueType)) {
                errorAt(*set, "Type incompatible pour le champ '" + member->member + "'");
            }
            return;
        }

        errorAt(*set, "Cible d'assignation invalide");
    }

    if (const auto* idxAssign = dynamic_cast<const IndexAssignStatementNode*>(&stmt)) {
        AfrType listType = analyzeExpression(*idxAssign->object, scope);
        if (listType.kind != TypeKind::List) {
            errorAt(*idxAssign, "Indexation sur un type non-liste");
        }
        AfrType indexType = analyzeExpression(*idxAssign->index, scope);
        if (!isNumeric(indexType)) {
            errorAt(*idxAssign, "L'index doit être un nombre");
        }
        AfrType valueType = analyzeExpression(*idxAssign->value, scope);
        if (!isAssignable(listType.listElementType(), valueType)) {
            errorAt(*idxAssign, "Type incompatible pour l'élément de la liste");
        }
        return;
    }

    if (const auto* addTo = dynamic_cast<const AddToListStatementNode*>(&stmt)) {
        AfrType listType = analyzeExpression(*addTo->list, scope);
        if (listType.kind != TypeKind::List) {
            errorAt(*addTo, "La cible de 'add ... to' doit être une liste");
        }
        AfrType valueType = analyzeExpression(*addTo->value, scope);
        if (!isAssignable(listType.listElementType(), valueType)) {
            errorAt(*addTo, "Type incompatible pour l'élément à ajouter");
        }
        return;
    }

    if (const auto* ask = dynamic_cast<const AskStatementNode*>(&stmt)) {
        analyzeExpression(*ask->prompt, scope);
        scope[ask->variableName] = AfrType::text();
        if (isGlobalScope) {
            result_.globalVariables[ask->variableName] = AfrType::text();
        }
        return;
    }

    if (const auto* use = dynamic_cast<const UseStatementNode*>(&stmt)) {
        if (!result_.modules.count(use->moduleName)) {
            errorAt(*use, "Module '" + use->moduleName + "' introuvable");
        }
        result_.usedModules.insert(use->moduleName);
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
        for (const auto& bodyStmt : ifStmt->thenBody) {
            analyzeStatement(*bodyStmt, scope, isGlobalScope);
        }
        for (const auto& bodyStmt : ifStmt->elseBody) {
            analyzeStatement(*bodyStmt, scope, isGlobalScope);
        }
        return;
    }

    if (const auto* whileStmt = dynamic_cast<const WhileStatementNode*>(&stmt)) {
        analyzeExpression(*whileStmt->condition, scope);
        ++loopDepth_;
        for (const auto& bodyStmt : whileStmt->body) {
            analyzeStatement(*bodyStmt, scope, isGlobalScope);
        }
        --loopDepth_;
        return;
    }

    if (const auto* repeat = dynamic_cast<const RepeatStatementNode*>(&stmt)) {
        AfrType countType = analyzeExpression(*repeat->count, scope);
        if (countType.kind != TypeKind::Number) {
            errorAt(*repeat, "Le compteur de 'repeat' doit être un nombre");
        }
        ++loopDepth_;
        for (const auto& bodyStmt : repeat->body) {
            analyzeStatement(*bodyStmt, scope, isGlobalScope);
        }
        --loopDepth_;
        return;
    }

    if (const auto* forEach = dynamic_cast<const ForEachStatementNode*>(&stmt)) {
        AfrType listType = analyzeExpression(*forEach->list, scope);
        if (listType.kind != TypeKind::List) {
            errorAt(*forEach, "La cible de 'for each' doit être une liste");
        }
        scope[forEach->itemName] = listType.listElementType();
        ++loopDepth_;
        for (const auto& bodyStmt : forEach->body) {
            analyzeStatement(*bodyStmt, scope, isGlobalScope);
        }
        scope.erase(forEach->itemName);
        --loopDepth_;
        return;
    }

    if (const auto* brk = dynamic_cast<const BreakStatementNode*>(&stmt)) {
        if (loopDepth_ == 0) {
            errorAt(*brk, "'stop' en dehors d'une boucle");
        }
        return;
    }

    if (const auto* cont = dynamic_cast<const ContinueStatementNode*>(&stmt)) {
        if (loopDepth_ == 0) {
            errorAt(*cont, "'skip' en dehors d'une boucle");
        }
        return;
    }

    if (const auto* exprStmt = dynamic_cast<const ExpressionStatementNode*>(&stmt)) {
        analyzeExpression(*exprStmt->expression, scope);
        return;
    }

    if (const auto* assertStmt = dynamic_cast<const AssertStatementNode*>(&stmt)) {
        AfrType condType = analyzeExpression(*assertStmt->condition, scope);
        if (condType.kind != TypeKind::Bool && condType.kind != TypeKind::Number) {
            errorAt(*assertStmt, "La condition de 'assert' doit être booléenne ou numérique");
        }
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

    if (const auto* boolean = dynamic_cast<const BoolLiteralNode*>(&expr)) {
        (void)boolean;
        return AfrType::boolType();
    }

    if (const auto* thisExpr = dynamic_cast<const ThisExpressionNode*>(&expr)) {
        (void)thisExpr;
        if (!currentClass_) {
            errorAt(expr, "'this' utilisé en dehors d'une méthode");
        }
        return AfrType::classType(currentClass_->name);
    }

    if (const auto* id = dynamic_cast<const IdentifierNode*>(&expr)) {
        auto it = scope.find(id->name);
        if (it != scope.end()) return it->second;

        auto globalIt = result_.globalVariables.find(id->name);
        if (globalIt != result_.globalVariables.end()) return globalIt->second;

        if (result_.records.count(id->name)) {
            return AfrType::recordType(id->name);
        }

        for (const auto& [modName, mod] : result_.modules) {
            if (result_.usedModules.count(modName) && mod.functions.count(id->name)) {
                return mod.functions.at(id->name).returnType;
            }
        }

        std::vector<std::string> hints;
        for (const auto& [name, _] : scope) hints.push_back(name);
        for (const auto& [name, _] : result_.globalVariables) hints.push_back(name);
        errorAt(expr, "Variable '" + id->name + "' non déclarée", hints);
    }

    if (const auto* bin = dynamic_cast<const BinaryOpNode*>(&expr)) {
        AfrType left = analyzeExpression(*bin->left, scope);
        AfrType right = analyzeExpression(*bin->right, scope);

        if (bin->op == "&&" || bin->op == "||") {
            return AfrType::boolType();
        }

        if (bin->op == ">" || bin->op == "<" || bin->op == "==" || bin->op == "!=") {
            return AfrType::boolType();
        }

        if (bin->op == "+" && left.kind == TypeKind::Text && right.kind == TypeKind::Text) {
            return AfrType::text();
        }

        if (isNumeric(left) && isNumeric(right)) {
            return AfrType::number();
        }

        errorAt(expr, "Opération incompatible entre types pour l'opérateur '" + bin->op + "'");
    }

    if (const auto* unary = dynamic_cast<const UnaryOpNode*>(&expr)) {
        AfrType operand = analyzeExpression(*unary->operand, scope);
        if (unary->op == "-") {
            if (!isNumeric(operand)) errorAt(expr, "Opérateur '-' requiert un nombre");
            return AfrType::number();
        }
        if (unary->op == "!") {
            return AfrType::boolType();
        }
        return AfrType::boolType();
    }

    if (const auto* list = dynamic_cast<const ListLiteralNode*>(&expr)) {
        if (list->elements.empty()) {
            errorAt(expr, "Impossible d'inférer le type d'une liste vide");
        }
        AfrType elemType = analyzeExpression(*list->elements[0], scope);
        for (std::size_t i = 1; i < list->elements.size(); ++i) {
            AfrType t = analyzeExpression(*list->elements[i], scope);
            if (!isAssignable(elemType, t)) {
                errorAt(expr, "Types incohérents dans la liste");
            }
        }
        return AfrType::listType(elemType);
    }

    if (const auto* empty = dynamic_cast<const EmptyListNode*>(&expr)) {
        return AfrType::listType(typeFromName(empty->elementTypeName));
    }

    if (const auto* index = dynamic_cast<const IndexExpressionNode*>(&expr)) {
        AfrType objectType = analyzeExpression(*index->object, scope);
        if (objectType.kind != TypeKind::List) {
            errorAt(expr, "Indexation sur un type non-liste");
        }
        AfrType indexType = analyzeExpression(*index->index, scope);
        if (!isNumeric(indexType)) {
            errorAt(expr, "L'index doit être un nombre");
        }
        return objectType.listElementType();
    }

    if (const auto* length = dynamic_cast<const LengthExpressionNode*>(&expr)) {
        AfrType objectType = analyzeExpression(*length->object, scope);
        if (objectType.kind != TypeKind::List) {
            errorAt(expr, "'length of' requiert une liste");
        }
        return AfrType::number();
    }

    if (const auto* call = dynamic_cast<const CallExpressionNode*>(&expr)) {
        if (const auto* member = dynamic_cast<const MemberAccessNode*>(call->callee.get())) {
            AfrType objectType = analyzeExpression(*member->object, scope);

            if (objectType.kind != TypeKind::Class) {
                errorAt(expr, "Appel de méthode sur un type non objet");
            }

            const MethodSignature* sig = findMethod(objectType.className, member->member);
            if (!sig) {
                errorAt(expr, "Méthode '" + member->member + "' introuvable dans '" + objectType.className + "'");
            }

            if (call->arguments.size() != sig->paramTypes.size()) {
                errorAt(expr, "Méthode '" + member->member + "' attend " +
                      std::to_string(sig->paramTypes.size()) + " argument(s), reçu " +
                      std::to_string(call->arguments.size()));
            }

            for (std::size_t i = 0; i < call->arguments.size(); ++i) {
                AfrType argType = analyzeExpression(*call->arguments[i], scope);
                if (!isAssignable(sig->paramTypes[i], argType)) {
                    errorAt(expr, "Type incompatible pour l'argument " + std::to_string(i + 1) +
                          " de '" + member->member + "'");
                }
            }

            return sig->returnType;
        }

        if (const auto* id = dynamic_cast<const IdentifierNode*>(call->callee.get())) {
            const MethodSignature* sig = findFunction(id->name);
            if (!sig) {
                for (const auto& [modName, mod] : result_.modules) {
                    if (result_.usedModules.count(modName) && mod.functions.count(id->name)) {
                        sig = &mod.functions.at(id->name);
                        break;
                    }
                }
            }
            if (!sig) {
                errorAt(expr, "Fonction '" + id->name + "' introuvable");
            }

            if (call->arguments.size() != sig->paramTypes.size()) {
                errorAt(expr, "Fonction '" + id->name + "' attend " +
                      std::to_string(sig->paramTypes.size()) + " argument(s), reçu " +
                      std::to_string(call->arguments.size()));
            }

            for (std::size_t i = 0; i < call->arguments.size(); ++i) {
                AfrType argType = analyzeExpression(*call->arguments[i], scope);
                if (!isAssignable(sig->paramTypes[i], argType)) {
                    errorAt(expr, "Type incompatible pour l'argument " + std::to_string(i + 1) +
                          " de '" + id->name + "'");
                }
            }

            return sig->returnType;
        }

        errorAt(expr, "Appel de fonction invalide");
    }

    if (const auto* member = dynamic_cast<const MemberAccessNode*>(&expr)) {
        AfrType objectType = analyzeExpression(*member->object, scope);

        if (objectType.kind == TypeKind::Result) {
            if (member->member == "value") return objectType.resultInnerType();
            if (member->member == "message") return AfrType::text();
            errorAt(expr, "Membre '" + member->member + "' introuvable sur un Result");
        }

        if (objectType.kind == TypeKind::Class) {
            const FieldInfo* field = findField(*findClass(objectType.className), member->member);
            if (field) return field->type;

            if (findMethod(objectType.className, member->member)) {
                return AfrType::voidType();
            }
            errorAt(expr, "Membre '" + member->member + "' introuvable dans '" + objectType.className + "'");
        }

        errorAt(expr, "Accès membre sur un type non objet");
    }

    if (const auto* newExpr = dynamic_cast<const NewExpressionNode*>(&expr)) {
        if (!result_.classes.count(newExpr->className)) {
            errorAt(expr, "Classe '" + newExpr->className + "' introuvable");
        }
        return AfrType::classType(newExpr->className);
    }

    return AfrType::voidType();
}

bool SemanticAnalyzer::isNumeric(const AfrType& type) const {
    return type.kind == TypeKind::Number;
}

bool SemanticAnalyzer::isBoolean(const AfrType& type) const {
    return type.kind == TypeKind::Bool;
}

bool SemanticAnalyzer::isAssignable(const AfrType& target, const AfrType& value) const {
    if (target == value) return true;
    if (target.kind == TypeKind::Number && value.kind == TypeKind::Number) return true;
    if (target.kind == TypeKind::Text && value.kind == TypeKind::Text) return true;
    if (target.kind == TypeKind::Bool && value.kind == TypeKind::Bool) return true;
    if (target.kind == TypeKind::Class && value.kind == TypeKind::Class) {
        return target.className == value.className;
    }
    if (target.kind == TypeKind::Record && value.kind == TypeKind::Record) {
        return target.recordName == value.recordName;
    }
    if (target.kind == TypeKind::List && value.kind == TypeKind::List) {
        return target.listElementTypeName == value.listElementTypeName;
    }
    return false;
}

const ClassInfo* SemanticAnalyzer::findClass(const std::string& name) const {
    auto it = result_.classes.find(name);
    return it != result_.classes.end() ? &it->second : nullptr;
}

const RecordInfo* SemanticAnalyzer::findRecord(const std::string& name) const {
    auto it = result_.records.find(name);
    return it != result_.records.end() ? &it->second : nullptr;
}

const FieldInfo* SemanticAnalyzer::findField(const ClassInfo& cls, const std::string& fieldName) const {
    auto it = cls.fields.find(fieldName);
    if (it != cls.fields.end()) return &it->second;

    if (!cls.baseClass.empty()) {
        const ClassInfo* base = findClass(cls.baseClass);
        if (base) return findField(*base, fieldName);
    }
    return nullptr;
}

const MethodSignature* SemanticAnalyzer::findFunction(const std::string& name) const {
    auto it = result_.functions.find(name);
    return it != result_.functions.end() ? &it->second : nullptr;
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

[[noreturn]] void SemanticAnalyzer::errorAt(const ASTNode& node, const std::string& message,
                                            const std::vector<std::string>& nameHints) const {
    std::string snippet;
    if (sources_) {
        if (const SourceFile* file = sources_->getFile(currentFile_)) {
            snippet = file->lineAt(node.loc.line);
        }
    }

    std::vector<std::string> sug;
    if (!nameHints.empty()) {
        std::string badName;
        const auto q1 = message.find('\'');
        const auto q2 = message.find('\'', q1 + 1);
        if (q1 != std::string::npos && q2 != std::string::npos) {
            badName = message.substr(q1 + 1, q2 - q1 - 1);
        }
        sug = findSimilarNames(badName, nameHints);
    }

    throw CompileError(message, node.loc.line, node.loc.column,
                       currentFile_, snippet, sug);
}

} // namespace afrilang
