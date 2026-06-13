#include "afrilang/semantic.hpp"

#include "afrilang/error.hpp"

#include <algorithm>
#include <functional>

namespace afrilang {

namespace {

std::size_t countRequiredParams(const std::vector<ParameterNode>& params) {
    std::size_t required = params.size();
    for (auto it = params.rbegin(); it != params.rend(); ++it) {
        if (it->defaultValue) --required;
        else break;
    }
    return required;
}

bool isLiteralDefault(const ExpressionNode* expr) {
    return dynamic_cast<const StringLiteralNode*>(expr) ||
           dynamic_cast<const NumberLiteralNode*>(expr) ||
           dynamic_cast<const BoolLiteralNode*>(expr);
}

void validateFunctionDefaults(const FunctionNode& func,
                              const std::function<void(const std::string&)>& reportError) {
    bool seenDefault = false;
    for (const auto& param : func.parameters) {
        if (param.defaultValue) {
            if (!isLiteralDefault(param.defaultValue.get())) {
                reportError("Valeur par défaut du paramètre '" + param.name +
                            "' doit être un littéral (texte, nombre ou booléen)");
            }
            seenDefault = true;
        } else if (seenDefault) {
            reportError("Les paramètres par défaut doivent être en fin de liste");
        }
    }
}

} // namespace

SemanticAnalyzer::SemanticAnalyzer(const ProgramNode& program,
                                   const SourceManager* sources,
                                   std::string currentFile)
    : program_(program)
    , sources_(sources)
    , currentFile_(std::move(currentFile)) {}

SemanticResult SemanticAnalyzer::analyze() {
    registerRecords();
    registerEnums();
    registerInterfaces();
    registerClasses();
    registerModules();
    registerExterns();
    analyzeProgram();
    return result_;
}

AfrType SemanticAnalyzer::resolveFunctionReturnType(const FunctionNode& func) const {
    if (func.returnTypeName.empty()) return AfrType::voidType();
    AfrType inner = resolveTypeForGeneric(func.returnTypeName, func.typeParams);
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

void SemanticAnalyzer::registerEnums() {
    for (const auto& en : program_.enums) {
        if (result_.enums.count(en->name)) {
            errorAt(*en, "Enum '" + en->name + "' déjà définie");
        }

        EnumInfo info;
        info.name = en->name;
        for (const auto& c : en->cases) {
            if (info.cases.count(c.name)) {
                errorAt(*en, "Cas '" + c.name + "' dupliqué dans enum '" + en->name + "'");
            }
            EnumCaseInfo ci;
            ci.name = c.name;
            for (const auto& field : c.fields) {
                ci.fields.emplace_back(field.name, typeFromName(field.typeName));
            }
            info.cases[c.name] = std::move(ci);
        }
        result_.enums[en->name] = std::move(info);
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
            sig.requiredParamCount = countRequiredParams(method->parameters);
            validateFunctionDefaults(*method, [&](const std::string& msg) {
                errorAt(*method, msg);
            });

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
                sig.requiredParamCount = countRequiredParams(method->parameters);
                validateFunctionDefaults(*method, [&](const std::string& msg) {
                    errorAt(*method, msg);
                });
                info.methods[method->name] = std::move(sig);
            }
            result_.classes[cls->name] = info;
            modInfo.classes[cls->name] = info;
        }

        for (const auto& func : module->functions) {
            MethodSignature sig;
            sig.name = func->name;
            sig.typeParams = func->typeParams;
            sig.returnType = resolveFunctionReturnType(*func);
            sig.returnsResult = func->returnsResult;
            for (const auto& param : func->parameters) {
                sig.paramTypes.push_back(resolveTypeForGeneric(param.typeName, func->typeParams));
            }
            sig.requiredParamCount = countRequiredParams(func->parameters);
            validateFunctionDefaults(*func, [&](const std::string& msg) {
                errorAt(*func, msg);
            });
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

void SemanticAnalyzer::registerExterns() {
    for (const auto& ext : program_.externs) {
        if (result_.functions.count(ext->name)) {
            errorAt(*ext, "Fonction '" + ext->name + "' déjà déclarée");
        }

        MethodSignature sig;
        sig.name = ext->name;
        sig.isExtern = true;
        sig.externLibrary = ext->library;
        sig.returnType = ext->returnTypeName.empty()
            ? AfrType::voidType()
            : typeFromName(ext->returnTypeName);
        for (const auto& param : ext->parameters) {
            sig.paramTypes.push_back(typeFromName(param.typeName));
        }
        result_.functions[ext->name] = std::move(sig);
    }
}

void SemanticAnalyzer::analyzeProgram() {
    std::unordered_map<std::string, AfrType> scope;
    for (const auto& stmt : program_.statements) {
        if (dynamic_cast<const UseStatementNode*>(stmt.get())) {
            analyzeStatement(*stmt, scope, true);
        }
    }

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
    const bool isStdlib = (module.name == "io" || module.name == "json" ||
                           module.name == "fs" || module.name == "http" ||
                           module.name == "str" || module.name == "logging" ||
                           module.name == "math" || module.name == "chrono" ||
                           module.name == "re" || module.name == "collections");

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
    sig.typeParams = func.typeParams;
    sig.returnType = resolveFunctionReturnType(func);
    sig.returnsResult = func.returnsResult;
    for (const auto& param : func.parameters) {
        sig.paramTypes.push_back(resolveTypeForGeneric(param.typeName, func.typeParams));
    }
    sig.requiredParamCount = countRequiredParams(func.parameters);
    validateFunctionDefaults(func, [&](const std::string& msg) {
        errorAt(func, msg);
    });
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
    activeTypeParams_ = func.typeParams;
    constVariables_.clear();

    if (ownerClass) {
        for (const auto& [name, field] : ownerClass->fields) {
            scope[name] = field.type;
        }
    }

    for (const auto& param : func.parameters) {
        scope[param.name] = resolveTypeForGeneric(param.typeName, func.typeParams);
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

    activeTypeParams_.clear();

    if (declaredReturn.kind != TypeKind::Void && !hasReturn && func.name != "init") {
        errorAt(func, "Fonction '" + func.name + "' déclare un retour '" +
              func.returnTypeName + "' mais ne contient pas de 'return'");
    }

    (void)ownerClass;
}

void SemanticAnalyzer::analyzeStatement(const StatementNode& stmt,
                                        std::unordered_map<std::string, AfrType>& scope,
                                        bool isGlobalScope) {
    if (const auto* explain = dynamic_cast<const ExplainStatementNode*>(&stmt)) {
        analyzeStatement(*explain->statement, scope, isGlobalScope);
        return;
    }

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

        if (dynamic_cast<const MapLiteralNode*>(assign->value.get())) {
            const auto* mapLit = static_cast<const MapLiteralNode*>(assign->value.get());
            if (mapLit->pairs.empty()) {
                errorAt(*assign, "Impossible d'inférer le type d'une map vide");
            }
            AfrType keyType = analyzeExpression(*mapLit->pairs[0].key, scope);
            AfrType valType = analyzeExpression(*mapLit->pairs[0].value, scope);
            valueType = AfrType::mapType(keyType, valType);
        }

        if (dynamic_cast<const EmptyMapNode*>(assign->value.get())) {
            const auto* empty = static_cast<const EmptyMapNode*>(assign->value.get());
            valueType = AfrType::mapType(typeFromName(empty->keyTypeName),
                                         typeFromName(empty->valueTypeName));
        }

        if (dynamic_cast<const NothingLiteralNode*>(assign->value.get())) {
            if (assign->typeName.empty() || assign->typeName.back() != '?') {
                errorAt(*assign, "'nothing' requiert un type nullable (ex: text?)");
            }
            valueType = typeFromName(assign->typeName);
        }

        if (!assign->typeName.empty()) {
            AfrType declared = resolveTypeName(assign->typeName);
            if (!isAssignable(declared, valueType)) {
                errorAt(*assign, "Type incompatible pour '" + assign->name + "'");
            }
            valueType = declared;
        }

        scope[assign->name] = valueType;
        if (assign->isConst) {
            if (constVariables_.count(assign->name)) {
                errorAt(*assign, "Variable constante '" + assign->name + "' déjà déclarée");
            }
            constVariables_.insert(assign->name);
            if (isGlobalScope) {
                result_.constVariables.insert(assign->name);
            }
        }
        if (isGlobalScope) {
            result_.globalVariables[assign->name] = valueType;
        }
        return;
    }

    if (const auto* set = dynamic_cast<const SetStatementNode*>(&stmt)) {
        AfrType valueType = analyzeExpression(*set->value, scope);

        if (const auto* id = dynamic_cast<const IdentifierNode*>(set->target.get())) {
            if (constVariables_.count(id->name) || result_.constVariables.count(id->name)) {
                errorAt(*set, "Variable constante '" + id->name + "' ne peut pas être modifiée");
            }
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
        AfrType containerType = analyzeExpression(*idxAssign->object, scope);
        AfrType indexType = analyzeExpression(*idxAssign->index, scope);
        AfrType valueType = analyzeExpression(*idxAssign->value, scope);
        if (containerType.kind == TypeKind::List) {
            if (!isNumeric(indexType)) {
                errorAt(*idxAssign, "L'index doit être un nombre");
            }
            if (!isAssignable(containerType.listElementType(), valueType)) {
                errorAt(*idxAssign, "Type incompatible pour l'élément de la liste");
            }
            return;
        }
        if (containerType.kind == TypeKind::Map) {
            if (!isAssignable(containerType.mapKeyType(), indexType)) {
                errorAt(*idxAssign, "Type incompatible pour la clé de la map");
            }
            if (!isAssignable(containerType.mapValueType(), valueType)) {
                errorAt(*idxAssign, "Type incompatible pour la valeur de la map");
            }
            return;
        }
        errorAt(*idxAssign, "Indexation sur un type non-liste/non-map");
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
        AfrType containerType = analyzeExpression(*forEach->list, scope);
        if (containerType.kind == TypeKind::List) {
            if (!forEach->valueName.empty()) {
                errorAt(*forEach, "Deux variables dans 'for each' requièrent une map");
            }
            scope[forEach->itemName] = containerType.listElementType();
        } else if (containerType.kind == TypeKind::Map) {
            if (forEach->valueName.empty()) {
                errorAt(*forEach, "'for each key, value in map' requiert deux variables");
            }
            scope[forEach->itemName] = containerType.mapKeyType();
            scope[forEach->valueName] = containerType.mapValueType();
        } else {
            errorAt(*forEach, "La cible de 'for each' doit être une liste ou une map");
        }
        ++loopDepth_;
        for (const auto& bodyStmt : forEach->body) {
            analyzeStatement(*bodyStmt, scope, isGlobalScope);
        }
        scope.erase(forEach->itemName);
        if (!forEach->valueName.empty()) {
            scope.erase(forEach->valueName);
        }
        --loopDepth_;
        return;
    }

    if (const auto* forRange = dynamic_cast<const ForRangeStatementNode*>(&stmt)) {
        AfrType startType = analyzeExpression(*forRange->start, scope);
        AfrType endType = analyzeExpression(*forRange->end, scope);
        if (!isNumeric(startType) || !isNumeric(endType)) {
            errorAt(*forRange, "Boucle 'for from/to' requiert des bornes numériques");
        }
        if (forRange->step) {
            AfrType stepType = analyzeExpression(*forRange->step, scope);
            if (!isNumeric(stepType)) {
                errorAt(*forRange, "Le pas ('step') doit être numérique");
            }
        }

        scope[forRange->varName] = AfrType::number();
        ++loopDepth_;
        for (const auto& bodyStmt : forRange->body) {
            analyzeStatement(*bodyStmt, scope, isGlobalScope);
        }
        scope.erase(forRange->varName);
        --loopDepth_;
        return;
    }

    if (const auto* tryStmt = dynamic_cast<const TryStatementNode*>(&stmt)) {
        for (const auto& bodyStmt : tryStmt->tryBody) {
            analyzeStatement(*bodyStmt, scope, isGlobalScope);
        }
        scope[tryStmt->catchVarName] = AfrType::text();
        for (const auto& bodyStmt : tryStmt->catchBody) {
            analyzeStatement(*bodyStmt, scope, isGlobalScope);
        }
        scope.erase(tryStmt->catchVarName);
        return;
    }

    if (const auto* raiseStmt = dynamic_cast<const RaiseStatementNode*>(&stmt)) {
        AfrType msgType = analyzeExpression(*raiseStmt->message, scope);
        if (msgType.kind != TypeKind::Text) {
            errorAt(*raiseStmt, "'raise' requiert un message text");
        }
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

    if (const auto* matchStmt = dynamic_cast<const MatchStatementNode*>(&stmt)) {
        AfrType subjectType = analyzeExpression(*matchStmt->subject, scope);
        if (subjectType.kind != TypeKind::Enum) {
            errorAt(*matchStmt, "'match' requiert une valeur de type enum");
        }
        const EnumInfo* en = findEnum(subjectType.className);
        if (!en) errorAt(*matchStmt, "Enum '" + subjectType.className + "' introuvable");

        bool hasDefault = false;
        for (const auto& arm : matchStmt->arms) {
            if (arm.isDefault) {
                hasDefault = true;
                for (const auto& bodyStmt : arm.body) {
                    analyzeStatement(*bodyStmt, scope, isGlobalScope);
                }
                continue;
            }
            const auto caseIt = en->cases.find(arm.caseName);
            if (caseIt == en->cases.end()) {
                errorAt(*matchStmt, "Cas '" + arm.caseName + "' introuvable dans enum '" + en->name + "'");
            }
            auto armScope = scope;
            for (const auto& [fname, ftype] : caseIt->second.fields) {
                armScope[fname] = ftype;
            }
            for (const auto& bodyStmt : arm.body) {
                analyzeStatement(*bodyStmt, armScope, isGlobalScope);
            }
        }
        (void)hasDefault;
        return;
    }
}

AfrType SemanticAnalyzer::analyzeExpression(const ExpressionNode& expr,
                                            const std::unordered_map<std::string, AfrType>& scope) {
    if (const auto* str = dynamic_cast<const StringLiteralNode*>(&expr)) {
        (void)str;
        return AfrType::text();
    }

    if (const auto* interp = dynamic_cast<const InterpolatedStringNode*>(&expr)) {
        for (const auto& part : interp->parts) {
            analyzeExpression(*part, scope);
        }
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

    if (dynamic_cast<const NothingLiteralNode*>(&expr)) {
        return AfrType::optionalType(AfrType::number());
    }

    if (const auto* isDef = dynamic_cast<const IsDefinedCheckNode*>(&expr)) {
        AfrType valType = analyzeExpression(*isDef->value, scope);
        if (valType.kind != TypeKind::Optional) {
            errorAt(expr, "'is defined' requiert un type nullable (ex: text?)");
        }
        return AfrType::boolType();
    }

    if (const auto* isError = dynamic_cast<const IsErrorCheckNode*>(&expr)) {
        AfrType valType = analyzeExpression(*isError->value, scope);
        if (valType.kind != TypeKind::Result) {
            errorAt(expr, "'is error' requiert un type Result");
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

    if (const auto* mapLit = dynamic_cast<const MapLiteralNode*>(&expr)) {
        if (mapLit->pairs.empty()) {
            errorAt(expr, "Impossible d'inférer le type d'une map vide");
        }
        AfrType keyType = analyzeExpression(*mapLit->pairs[0].key, scope);
        AfrType valType = analyzeExpression(*mapLit->pairs[0].value, scope);
        for (std::size_t i = 1; i < mapLit->pairs.size(); ++i) {
            AfrType k = analyzeExpression(*mapLit->pairs[i].key, scope);
            AfrType v = analyzeExpression(*mapLit->pairs[i].value, scope);
            if (!isAssignable(keyType, k) || !isAssignable(valType, v)) {
                errorAt(expr, "Types incohérents dans la map");
            }
        }
        return AfrType::mapType(keyType, valType);
    }

    if (const auto* emptyMap = dynamic_cast<const EmptyMapNode*>(&expr)) {
        return AfrType::mapType(typeFromName(emptyMap->keyTypeName),
                                typeFromName(emptyMap->valueTypeName));
    }

    if (const auto* index = dynamic_cast<const IndexExpressionNode*>(&expr)) {
        AfrType objectType = analyzeExpression(*index->object, scope);
        AfrType indexType = analyzeExpression(*index->index, scope);
        if (objectType.kind == TypeKind::List) {
            if (!isNumeric(indexType)) {
                errorAt(expr, "L'index doit être un nombre");
            }
            return objectType.listElementType();
        }
        if (objectType.kind == TypeKind::Map) {
            if (!isAssignable(objectType.mapKeyType(), indexType)) {
                errorAt(expr, "Type incompatible pour la clé de la map");
            }
            return objectType.mapValueType();
        }
        errorAt(expr, "Indexation sur un type non-liste/non-map");
    }

    if (const auto* length = dynamic_cast<const LengthExpressionNode*>(&expr)) {
        AfrType objectType = analyzeExpression(*length->object, scope);
        if (objectType.kind != TypeKind::List && objectType.kind != TypeKind::Map) {
            errorAt(expr, "'length of' requiert une liste ou une map");
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

            if (call->arguments.size() < sig->requiredParamCount ||
                call->arguments.size() > sig->paramTypes.size()) {
                errorAt(expr, "Méthode '" + member->member + "' attend entre " +
                      std::to_string(sig->requiredParamCount) + " et " +
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

            if (call->arguments.size() < sig->requiredParamCount ||
                call->arguments.size() > sig->paramTypes.size()) {
                errorAt(expr, "Fonction '" + id->name + "' attend entre " +
                      std::to_string(sig->requiredParamCount) + " et " +
                      std::to_string(sig->paramTypes.size()) + " argument(s), reçu " +
                      std::to_string(call->arguments.size()));
            }

            std::vector<AfrType> argTypes;
            argTypes.reserve(call->arguments.size());
            for (const auto& arg : call->arguments) {
                argTypes.push_back(analyzeExpression(*arg, scope));
            }

            for (std::size_t i = 0; i < argTypes.size(); ++i) {
                if (!isAssignable(sig->paramTypes[i], argTypes[i])) {
                    errorAt(expr, "Type incompatible pour l'argument " + std::to_string(i + 1) +
                          " de '" + id->name + "'");
                }
            }

            if (!sig->typeParams.empty()) {
                const auto subst = inferGenericSubst(*sig, argTypes, expr);
                return substituteType(sig->returnType, subst);
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

        if (objectType.kind == TypeKind::Enum) {
            const EnumInfo* en = findEnum(objectType.className);
            if (en) {
                for (const auto& [_, c] : en->cases) {
                    for (const auto& [fname, ftype] : c.fields) {
                        if (fname == member->member) return ftype;
                    }
                }
            }
            errorAt(expr, "Champ '" + member->member + "' introuvable sur enum '" + objectType.className + "'");
        }

        errorAt(expr, "Accès membre sur un type non objet");
    }

    if (const auto* enumCase = dynamic_cast<const EnumCaseExprNode*>(&expr)) {
        const EnumInfo* en = findEnum(enumCase->enumName);
        if (!en) {
            errorAt(expr, "Enum '" + enumCase->enumName + "' introuvable");
        }
        const auto caseIt = en->cases.find(enumCase->caseName);
        if (caseIt == en->cases.end()) {
            errorAt(expr, "Cas '" + enumCase->caseName + "' introuvable dans enum '" + enumCase->enumName + "'");
        }
        if (caseIt->second.fields.size() != enumCase->arguments.size()) {
            errorAt(expr, "Le cas '" + enumCase->caseName + "' attend " +
                  std::to_string(caseIt->second.fields.size()) + " argument(s)");
        }
        for (std::size_t i = 0; i < enumCase->arguments.size(); ++i) {
            AfrType argType = analyzeExpression(*enumCase->arguments[i], scope);
            if (!isAssignable(caseIt->second.fields[i].second, argType)) {
                errorAt(expr, "Type incompatible pour l'argument du cas '" + enumCase->caseName + "'");
            }
        }
        return AfrType::enumType(enumCase->enumName);
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
    if (target.kind == TypeKind::TypeVar) return true;
    if (value.kind == TypeKind::TypeVar && target.kind == value.kind) {
        return target.className == value.className;
    }
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
        if (!isConcreteTypeName(target.listElementTypeName)) return true;
        return target.listElementTypeName == value.listElementTypeName;
    }
    if (target.kind == TypeKind::Map && value.kind == TypeKind::Map) {
        if (!isConcreteTypeName(target.className) || !isConcreteTypeName(target.listElementTypeName)) {
            return true;
        }
        return target.className == value.className &&
               target.listElementTypeName == value.listElementTypeName;
    }
    if (target.kind == TypeKind::Result && value.kind == TypeKind::Result) {
        return target.listElementTypeName == value.listElementTypeName;
    }
    if (target.kind == TypeKind::Optional && value.kind == TypeKind::Optional) {
        return target.listElementTypeName == value.listElementTypeName;
    }
    if (target.kind == TypeKind::Enum && value.kind == TypeKind::Enum) {
        return target.className == value.className;
    }
    return false;
}

bool SemanticAnalyzer::isConcreteTypeName(const std::string& name) const {
    if (name == "number" || name == "text" || name == "bool") return true;
    if (result_.classes.count(name) || result_.records.count(name) || result_.enums.count(name)) {
        return true;
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

const EnumInfo* SemanticAnalyzer::findEnum(const std::string& name) const {
    auto it = result_.enums.find(name);
    return it != result_.enums.end() ? &it->second : nullptr;
}

AfrType SemanticAnalyzer::resolveTypeName(const std::string& name) const {
    if (result_.enums.count(name)) return AfrType::enumType(name);
    if (result_.records.count(name)) return AfrType::recordType(name);
    return typeFromName(name);
}

AfrType SemanticAnalyzer::resolveTypeForGeneric(const std::string& name,
                                                const std::vector<std::string>& typeParams) const {
    for (const auto& tp : typeParams) {
        if (name == tp) return AfrType::typeVar(tp);
    }
    if (name.size() > 5 && name.rfind("list ", 0) == 0) {
        const std::string elem = name.substr(5);
        for (const auto& tp : typeParams) {
            if (elem == tp) return AfrType::listType(AfrType::typeVar(tp));
        }
    }
    if (!name.empty() && name.back() == '?') {
        const std::string inner = name.substr(0, name.size() - 1);
        for (const auto& tp : typeParams) {
            if (inner == tp) return AfrType::optionalType(AfrType::typeVar(tp));
        }
    }
    return resolveTypeName(name);
}

AfrType SemanticAnalyzer::substituteType(
    AfrType type, const std::unordered_map<std::string, AfrType>& subst) const {
    if (type.kind == TypeKind::TypeVar) {
        const auto it = subst.find(type.className);
        if (it != subst.end()) return it->second;
        return type;
    }
    if (type.kind == TypeKind::List) {
        AfrType elem = typeFromName(type.listElementTypeName);
        if (elem.kind == TypeKind::TypeVar) {
            const auto it = subst.find(elem.className);
            if (it != subst.end()) return AfrType::listType(it->second);
        }
    }
    if (type.kind == TypeKind::Optional) {
        AfrType inner = type.optionalInnerType();
        if (inner.kind == TypeKind::TypeVar) {
            const auto it = subst.find(inner.className);
            if (it != subst.end()) return AfrType::optionalType(it->second);
        }
    }
    if (type.kind == TypeKind::Result) {
        AfrType inner = type.resultInnerType();
        if (inner.kind == TypeKind::TypeVar) {
            const auto it = subst.find(inner.className);
            if (it != subst.end()) return AfrType::resultType(it->second);
        }
    }
    return type;
}

std::unordered_map<std::string, AfrType> SemanticAnalyzer::inferGenericSubst(
    const MethodSignature& sig,
    const std::vector<AfrType>& argTypes,
    const ASTNode& at) const {
    std::unordered_map<std::string, AfrType> subst;

    for (std::size_t i = 0; i < argTypes.size() && i < sig.paramTypes.size(); ++i) {
        const AfrType& paramType = sig.paramTypes[i];
        const AfrType& argType = argTypes[i];

        if (paramType.kind == TypeKind::TypeVar) {
            const auto it = subst.find(paramType.className);
            if (it == subst.end()) {
                subst[paramType.className] = argType;
            } else if (!isAssignable(it->second, argType)) {
                errorAt(at, "Types incompatibles pour le paramètre de type '" +
                      paramType.className + "'");
            }
        } else if (paramType.kind == TypeKind::List && argType.kind == TypeKind::List) {
            const std::string& elemName = paramType.listElementTypeName;
            if (std::find(sig.typeParams.begin(), sig.typeParams.end(), elemName) !=
                sig.typeParams.end()) {
                AfrType concreteElem = argType.listElementType();
                const auto it = subst.find(elemName);
                if (it == subst.end()) {
                    subst[elemName] = concreteElem;
                } else if (!isAssignable(it->second, concreteElem)) {
                    errorAt(at, "Types incompatibles pour le paramètre de type '" +
                          elemName + "'");
                }
            }
        }
    }

    return subst;
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
