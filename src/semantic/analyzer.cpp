#include "afrilang/semantic.hpp"

#include "afrilang/error.hpp"

#include <algorithm>
#include <functional>
#include <sstream>

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

AfrType lambdaExpressionType(const LambdaExpressionNode& lambda) {
    std::ostringstream params;
    for (std::size_t i = 0; i < lambda.parameters.size(); ++i) {
        if (i > 0) params << ", ";
        params << lambda.parameters[i].typeName;
    }
    return AfrType::functionType(params.str(), lambda.returnTypeName);
}

AfrType inferReturnTypeFromBlockImpl(
    const std::vector<std::unique_ptr<StatementNode>>& body,
    const std::unordered_map<std::string, AfrType>& scope,
    const ASTNode& at,
    const std::function<AfrType(const ExpressionNode&,
                                const std::unordered_map<std::string, AfrType>&)>& analyzeExpr,
    const std::function<void(const ASTNode&, const std::string&)>& reportError) {
    AfrType result;
    bool found = false;
    for (const auto& stmt : body) {
        if (const auto* ret = dynamic_cast<const ReturnStatementNode*>(stmt.get())) {
            if (!ret->value) {
                reportError(at, "return avec valeur attendu");
            }
            AfrType retType = analyzeExpr(*ret->value, scope);
            if (found && result.kind != retType.kind) {
                reportError(at, "Types de retour incohérents dans le bloc");
            }
            result = retType;
            found = true;
        }
    }
    if (!found) {
        reportError(at, "Au moins un 'return' attendu");
    }
    return result;
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

AfrType SemanticAnalyzer::resolveFunctionReturnTypeWithParams(
    const FunctionNode& func, const std::vector<std::string>& typeParams) const {
    AfrType inner;
    if (func.returnTypeName.empty()) {
        inner = AfrType::voidType();
    } else {
        inner = resolveTypeForGeneric(func.returnTypeName, typeParams);
    }
    if (func.returnsResult) inner = AfrType::resultType(inner);
    if (func.isAsync) return AfrType::taskType(inner);
    return inner;
}

AfrType SemanticAnalyzer::resolveFunctionReturnType(const FunctionNode& func) const {
    return resolveFunctionReturnTypeWithParams(func, func.typeParams);
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
            fi.visibility = FieldVisibility::Public;
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
                fi.visibility = FieldVisibility::Public;
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
        info.isAbstract = cls->isAbstract;
        info.isFinal = cls->isFinal;
        info.typeParams = cls->typeParams;

        for (const auto& field : cls->fields) {
            FieldInfo fi;
            fi.name = field.name;
            fi.type = cls->typeParams.empty()
                ? typeFromName(field.typeName)
                : resolveTypeForGeneric(field.typeName, cls->typeParams);
            fi.visibility = field.visibility;
            fi.isStatic = field.isStatic;
            info.fields[field.name] = std::move(fi);
        }

        for (const auto& prop : cls->properties) {
            PropertyInfo pi;
            pi.name = prop.name;
            pi.type = cls->typeParams.empty()
                ? typeFromName(prop.typeName)
                : resolveTypeForGeneric(prop.typeName, cls->typeParams);
            pi.visibility = prop.visibility;
            info.properties[prop.name] = std::move(pi);
        }

        for (const auto& method : cls->methods) {
            MethodSignature sig;
            sig.name = method->name;
            sig.isConstructor = (method->name == "init");
            sig.returnsResult = method->returnsResult;
            sig.isStatic = method->isStatic;
            sig.isAbstract = method->isAbstract;
            sig.isFinal = method->isFinal;
            sig.isAsync = method->isAsync;
            sig.typeParams = cls->typeParams.empty()
                ? method->typeParams
                : cls->typeParams;

            const std::vector<std::string>& tparams = sig.typeParams;
            sig.returnType = resolveFunctionReturnTypeWithParams(*method, tparams);
            if (method->isAsync) result_.usesAsync = true;

            for (const auto& param : method->parameters) {
                sig.paramTypes.push_back(resolveTypeForGeneric(param.typeName, tparams));
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
            } else if (result_.classes.at(cls->baseClassName).isFinal) {
                errorAt(*cls, "La classe '" + cls->baseClassName + "' est final et ne peut être étendue");
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
            info.isAbstract = cls->isAbstract;
            for (const auto& field : cls->fields) {
                FieldInfo fi;
                fi.name = field.name;
                fi.type = typeFromName(field.typeName);
                fi.visibility = field.visibility;
                fi.isStatic = field.isStatic;
                info.fields[field.name] = std::move(fi);
            }
            for (const auto& method : cls->methods) {
                MethodSignature sig;
                sig.name = method->name;
                sig.isConstructor = (method->name == "init");
                sig.returnType = resolveFunctionReturnType(*method);
                sig.returnsResult = method->returnsResult;
                sig.isStatic = method->isStatic;
                sig.isAbstract = method->isAbstract;
                sig.isAsync = method->isAsync;
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
            sig.isAsync = func->isAsync;
            if (func->isAsync) result_.usesAsync = true;
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

    const int savedAsync = asyncContextDepth_;
    asyncContextDepth_ = 1;
    for (const auto& stmt : program_.statements) {
        analyzeStatement(*stmt, scope, true);
    }
    asyncContextDepth_ = savedAsync;
}

void SemanticAnalyzer::analyzeRecord(const RecordNode& record) {
    (void)record;
}

void SemanticAnalyzer::analyzeModule(const ModuleNode& module) {
    const bool isStdlib = (module.name == "io" || module.name == "json" ||
                           module.name == "fs" || module.name == "http" ||
                           module.name == "str" || module.name == "logging" ||
                           module.name == "math" || module.name == "chrono" ||
                           module.name == "re" || module.name == "collections" ||
                           module.name == "async");

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
    sig.isAsync = func.isAsync;
    if (func.isAsync) result_.usesAsync = true;
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
        if (method->isAbstract) continue;
        analyzeFunctionBody(*method, currentClass_);
    }

    currentClass_ = savedClass;
}

void SemanticAnalyzer::analyzeTest(const TestNode& test) {
    const int savedAsync = asyncContextDepth_;
    asyncContextDepth_ = 1;
    std::unordered_map<std::string, AfrType> scope;
    for (const auto& stmt : test.body) {
        analyzeStatement(*stmt, scope, false);
    }
    asyncContextDepth_ = savedAsync;
}

void SemanticAnalyzer::analyzeFunctionBody(const FunctionNode& func, const ClassInfo* ownerClass) {
    std::unordered_map<std::string, AfrType> scope;
    activeTypeParams_ = func.typeParams;
    if (activeTypeParams_.empty() && ownerClass && !ownerClass->typeParams.empty()) {
        activeTypeParams_ = ownerClass->typeParams;
    }

    const int savedAsync = asyncContextDepth_;
    if (func.isAsync) {
        ++asyncContextDepth_;
        result_.usesAsync = true;
    }
    constVariables_.clear();

    if (ownerClass) {
        const ClassInfo* cls = ownerClass;
        while (cls) {
            for (const auto& [name, field] : cls->fields) {
                if (!field.isStatic && !scope.count(name)) {
                    scope[name] = field.type;
                }
            }
            if (cls->baseClass.empty()) break;
            cls = findClass(cls->baseClass);
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
    asyncContextDepth_ = savedAsync;

    const bool implicitAsyncVoid = func.isAsync && func.returnTypeName.empty();
    if (!implicitAsyncVoid && declaredReturn.kind != TypeKind::Void && !hasReturn &&
        func.name != "init" && !func.body.empty()) {
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
            AfrType elemType;
            if (!assign->typeName.empty()) {
                AfrType declared = typeFromName(assign->typeName);
                if (declared.kind == TypeKind::List) {
                    elemType = declared.listElementType();
                }
            }
            if (elemType.kind == TypeKind::Void && !list->elements.empty()) {
                elemType = analyzeExpression(*list->elements[0], scope);
            }
            if (!list->elements.empty() && elemType.kind != TypeKind::Void) {
                for (std::size_t i = 0; i < list->elements.size(); ++i) {
                    AfrType t = analyzeExpression(*list->elements[i], scope);
                    if (!isAssignable(elemType, t)) {
                        errorAt(*assign, "Types incohérents dans la liste");
                    }
                }
                valueType = AfrType::listType(elemType);
            } else if (!list->elements.empty()) {
                AfrType firstType = analyzeExpression(*list->elements[0], scope);
                valueType = AfrType::listType(firstType);
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
                const ClassInfo* ownerClass = currentClass_;
                const FieldInfo* field = findFieldWithOwner(*currentClass_, member->member, ownerClass);
                if (field) {
                    if (!canAccessField(*field, *ownerClass, currentClass_)) {
                        errorAt(*set, "Champ '" + member->member + "' inaccessible");
                    }
                    if (!isAssignable(field->type, valueType)) {
                        errorAt(*set, "Type incompatible pour le champ '" + member->member + "'");
                    }
                    return;
                }
                if (const PropertyInfo* prop = findProperty(*currentClass_, member->member)) {
                    if (prop->visibility != FieldVisibility::Public) {
                        errorAt(*set, "Propriété '" + member->member + "' inaccessible");
                    }
                    if (!isAssignable(prop->type, valueType)) {
                        errorAt(*set, "Type incompatible pour la propriété '" + member->member + "'");
                    }
                    return;
                }
                errorAt(*set, "Champ '" + member->member + "' introuvable");
                return;
            }

            if (const auto* classId = dynamic_cast<const IdentifierNode*>(member->object.get())) {
                if (result_.classes.count(classId->name)) {
                    const ClassInfo* cls = findClass(classId->name);
                    const FieldInfo* field = findField(*cls, member->member);
                    if (!field || !field->isStatic) {
                        errorAt(*set, "Champ statique '" + member->member + "' introuvable");
                    }
                    if (field->visibility != FieldVisibility::Public) {
                        errorAt(*set, "Champ statique '" + member->member + "' inaccessible");
                    }
                    if (!isAssignable(field->type, valueType)) {
                        errorAt(*set, "Type incompatible pour le champ '" + member->member + "'");
                    }
                    return;
                }
            }

            AfrType objectType = analyzeExpression(*member->object, scope);
            if (objectType.kind != TypeKind::Class) {
                errorAt(*set, "Assignation de champ sur un type non objet");
            }
            const ClassInfo* cls = findClass(objectType.className);
            const ClassInfo* ownerClass = cls;
            const FieldInfo* field = findFieldWithOwner(*cls, member->member, ownerClass);
            if (field) {
                if (field->isStatic) {
                    errorAt(*set, "Utilisez " + cls->name + "." + member->member + " pour un champ statique");
                }
                if (!canAccessField(*field, *ownerClass, currentClass_)) {
                    errorAt(*set, "Champ '" + member->member + "' inaccessible");
                }
                if (!isAssignable(field->type, valueType)) {
                    errorAt(*set, "Type incompatible pour le champ '" + member->member + "'");
                }
                return;
            }
            if (const PropertyInfo* prop = findProperty(*cls, member->member)) {
                if (prop->visibility != FieldVisibility::Public) {
                    errorAt(*set, "Propriété '" + member->member + "' inaccessible");
                }
                if (!isAssignable(prop->type, valueType)) {
                    errorAt(*set, "Type incompatible pour la propriété '" + member->member + "'");
                }
                return;
            }
            errorAt(*set, "Champ '" + member->member + "' introuvable");
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

AfrType SemanticAnalyzer::inferReturnTypeFromBlock(
    const std::vector<std::unique_ptr<StatementNode>>& body,
    const std::unordered_map<std::string, AfrType>& scope,
    const ASTNode& at) {
    return inferReturnTypeFromBlockImpl(
        body, scope, at,
        [this](const ExpressionNode& e, const std::unordered_map<std::string, AfrType>& s) {
            return analyzeExpression(e, s);
        },
        [this](const ASTNode& node, const std::string& msg) { errorAt(node, msg); });
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

    if (dynamic_cast<const SuperExpressionNode*>(&expr)) {
        if (!currentClass_) {
            errorAt(expr, "'super' utilisé en dehors d'une méthode");
        }
        if (currentClass_->baseClass.empty()) {
            errorAt(expr, "'super' utilisé sans classe de base");
        }
        return AfrType::classType(currentClass_->baseClass);
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

        if (result_.classes.count(id->name)) {
            return AfrType::classType(id->name);
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
            if (isAssignable(elemType, t)) continue;
            if (elemType.kind == TypeKind::Class && t.kind == TypeKind::Class) {
                if (isSubclassOf(t.className, elemType.className)) continue;
                if (isSubclassOf(elemType.className, t.className)) {
                    elemType = t;
                    continue;
                }
                const ClassInfo* cls = findClass(elemType.className);
                bool merged = false;
                while (cls && !cls->baseClass.empty()) {
                    if (isSubclassOf(t.className, cls->baseClass)) {
                        elemType = AfrType::classType(cls->baseClass);
                        merged = true;
                        break;
                    }
                    cls = findClass(cls->baseClass);
                }
                if (merged) continue;
            }
            errorAt(expr, "Types incohérents dans la liste");
        }
        const_cast<ListLiteralNode*>(list)->elementTypeName = elemType.toTypeName();
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

    if (const auto* mapEach = dynamic_cast<const MapEachExpressionNode*>(&expr)) {
        AfrType listType = analyzeExpression(*mapEach->list, scope);
        if (listType.kind != TypeKind::List) {
            errorAt(expr, "'map each' requiert une liste");
        }
        AfrType elemType = listType.listElementType();
        if (elemType.kind != TypeKind::Number && elemType.kind != TypeKind::Text) {
            errorAt(expr, "'map each' supporte listes de number ou text");
        }

        auto* mutableNode = const_cast<MapEachExpressionNode*>(mapEach);
        mutableNode->elementTypeName = elemType.toTypeName();

        std::unordered_map<std::string, AfrType> bodyScope = scope;
        bodyScope[mapEach->itemName] = elemType;
        for (const auto& stmt : mapEach->body) {
            analyzeStatement(*stmt, bodyScope, false);
        }
        AfrType resultElem = inferReturnTypeFromBlock(mapEach->body, bodyScope, expr);
        mutableNode->resultElementTypeName = resultElem.toTypeName();
        return AfrType::listType(resultElem);
    }

    if (const auto* flatMapEach = dynamic_cast<const FlatMapEachExpressionNode*>(&expr)) {
        AfrType listType = analyzeExpression(*flatMapEach->list, scope);
        if (listType.kind != TypeKind::List) {
            errorAt(expr, "'flatMap each' requiert une liste");
        }
        AfrType elemType = listType.listElementType();
        if (elemType.kind != TypeKind::Number && elemType.kind != TypeKind::Text) {
            errorAt(expr, "'flatMap each' supporte listes de number ou text");
        }

        auto* mutableNode = const_cast<FlatMapEachExpressionNode*>(flatMapEach);
        mutableNode->elementTypeName = elemType.toTypeName();

        std::unordered_map<std::string, AfrType> bodyScope = scope;
        bodyScope[flatMapEach->itemName] = elemType;
        for (const auto& stmt : flatMapEach->body) {
            analyzeStatement(*stmt, bodyScope, false);
        }
        AfrType returnedList = inferReturnTypeFromBlock(flatMapEach->body, bodyScope, expr);
        if (returnedList.kind != TypeKind::List) {
            errorAt(expr, "Le corps de 'flatMap each' doit retourner une liste");
        }
        AfrType resultElem = returnedList.listElementType();
        mutableNode->resultElementTypeName = resultElem.toTypeName();
        return AfrType::listType(resultElem);
    }

    if (const auto* filterEach = dynamic_cast<const FilterEachExpressionNode*>(&expr)) {
        AfrType listType = analyzeExpression(*filterEach->list, scope);
        if (listType.kind != TypeKind::List) {
            errorAt(expr, "'filter each' requiert une liste");
        }
        AfrType elemType = listType.listElementType();
        if (elemType.kind != TypeKind::Number && elemType.kind != TypeKind::Text) {
            errorAt(expr, "'filter each' supporte listes de number ou text");
        }

        const_cast<FilterEachExpressionNode*>(filterEach)->elementTypeName =
            elemType.toTypeName();

        std::unordered_map<std::string, AfrType> condScope = scope;
        condScope[filterEach->itemName] = elemType;
        AfrType condType = analyzeExpression(*filterEach->condition, condScope);
        if (condType.kind != TypeKind::Bool) {
            errorAt(expr, "La condition de 'filter each' doit être un booléen");
        }
        return listType;
    }

    if (const auto* reduce = dynamic_cast<const ReduceExpressionNode*>(&expr)) {
        AfrType listType = analyzeExpression(*reduce->list, scope);
        if (listType.kind != TypeKind::List) {
            errorAt(expr, "'reduce' requiert une liste");
        }
        AfrType elemType = listType.listElementType();
        if (elemType.kind != TypeKind::Number && elemType.kind != TypeKind::Text) {
            errorAt(expr, "'reduce' supporte listes de number ou text");
        }

        AfrType initialType = analyzeExpression(*reduce->initial, scope);
        if (elemType.kind == TypeKind::Number && initialType.kind != TypeKind::Number) {
            errorAt(expr, "La valeur initiale de 'reduce' sur number doit être un number");
        }
        if (elemType.kind == TypeKind::Text && initialType.kind != TypeKind::Text) {
            errorAt(expr, "La valeur initiale de 'reduce' sur text doit être un text");
        }

        const_cast<ReduceExpressionNode*>(reduce)->elementTypeName = elemType.toTypeName();
        const_cast<ReduceExpressionNode*>(reduce)->resultTypeName = initialType.toTypeName();

        std::unordered_map<std::string, AfrType> bodyScope = scope;
        bodyScope[reduce->accName] = initialType;
        bodyScope[reduce->itemName] = elemType;
        for (const auto& stmt : reduce->body) {
            analyzeStatement(*stmt, bodyScope, false);
        }
        AfrType resultType = inferReturnTypeFromBlock(reduce->body, bodyScope, expr);
        if (!isAssignable(initialType, resultType)) {
            errorAt(expr, "Le type de retour de 'reduce' doit correspondre à la valeur initiale");
        }
        return initialType;
    }

    if (const auto* awaitExpr = dynamic_cast<const AwaitExpressionNode*>(&expr)) {
        if (asyncContextDepth_ <= 0) {
            errorAt(expr, "'await' n'est autorisé que dans une fonction async ou au niveau global");
        }
        AfrType taskType = analyzeExpression(*awaitExpr->value, scope);
        if (taskType.kind != TypeKind::Task) {
            errorAt(expr, "'await' requiert une expression de type task");
        }
        result_.usesAsync = true;
        return taskType.taskInnerType();
    }

    if (const auto* lambda = dynamic_cast<const LambdaExpressionNode*>(&expr)) {
        std::unordered_map<std::string, AfrType> lambdaScope = scope;
        for (const auto& param : lambda->parameters) {
            lambdaScope[param.name] = typeFromName(param.typeName);
        }
        for (const auto& stmt : lambda->body) {
            analyzeStatement(*stmt, lambdaScope, false);
        }
        if (lambda->returnTypeName.empty()) {
            errorAt(expr, "Une lambda doit déclarer un type de retour (returns ...)");
        }
        return lambdaExpressionType(*lambda);
    }

    if (const auto* call = dynamic_cast<const CallExpressionNode*>(&expr)) {
        if (const auto* newExpr = dynamic_cast<const NewExpressionNode*>(call->callee.get())) {
            if (!result_.classes.count(newExpr->className)) {
                errorAt(expr, "Classe '" + newExpr->className + "' introuvable");
            }
            const ClassInfo& clsInfo = result_.classes.at(newExpr->className);
            if (clsInfo.isAbstract) {
                errorAt(expr, "Impossible d'instancier la classe abstraite '" + newExpr->className + "'");
            }
            std::unordered_map<std::string, AfrType> subst;
            if (!clsInfo.typeParams.empty()) {
                if (newExpr->typeArgs.size() != clsInfo.typeParams.size()) {
                    errorAt(expr, "Classe générique '" + newExpr->className + "' attend " +
                          std::to_string(clsInfo.typeParams.size()) + " argument(s) de type");
                }
                for (std::size_t i = 0; i < clsInfo.typeParams.size(); ++i) {
                    subst[clsInfo.typeParams[i]] = typeFromName(newExpr->typeArgs[i]);
                }
            } else if (!newExpr->typeArgs.empty()) {
                errorAt(expr, "Classe '" + newExpr->className + "' n'est pas générique");
            }
            const MethodSignature* initSig = findMethod(newExpr->className, "init");
            if (initSig) {
                if (call->arguments.size() < initSig->requiredParamCount ||
                    call->arguments.size() > initSig->paramTypes.size()) {
                    errorAt(expr, "Constructeur 'init' de '" + newExpr->className +
                          "' attend entre " + std::to_string(initSig->requiredParamCount) +
                          " et " + std::to_string(initSig->paramTypes.size()) +
                          " argument(s), reçu " + std::to_string(call->arguments.size()));
                }
                for (std::size_t i = 0; i < call->arguments.size(); ++i) {
                    AfrType argType = analyzeExpression(*call->arguments[i], scope);
                    AfrType paramType = subst.empty()
                        ? initSig->paramTypes[i]
                        : substituteType(initSig->paramTypes[i], subst);
                    if (!isAssignable(paramType, argType)) {
                        errorAt(expr, "Type incompatible pour l'argument " +
                              std::to_string(i + 1) + " du constructeur");
                    }
                }
            } else if (!call->arguments.empty()) {
                errorAt(expr, "Classe '" + newExpr->className + "' n'a pas de constructeur 'init'");
            }
            return AfrType::classType(newExpr->className);
        }

        if (dynamic_cast<const SuperExpressionNode*>(call->callee.get())) {
            if (!currentClass_) {
                errorAt(expr, "'super(...)' utilisé en dehors d'une méthode");
            }
            if (currentClass_->baseClass.empty()) {
                errorAt(expr, "'super(...)' sans classe de base");
            }
            const MethodSignature* initSig = findMethod(currentClass_->baseClass, "init");
            if (initSig) {
                if (call->arguments.size() < initSig->requiredParamCount ||
                    call->arguments.size() > initSig->paramTypes.size()) {
                    errorAt(expr, "Constructeur parent attend entre " +
                          std::to_string(initSig->requiredParamCount) + " et " +
                          std::to_string(initSig->paramTypes.size()) + " argument(s)");
                }
                for (std::size_t i = 0; i < call->arguments.size(); ++i) {
                    AfrType argType = analyzeExpression(*call->arguments[i], scope);
                    if (!isAssignable(initSig->paramTypes[i], argType)) {
                        errorAt(expr, "Type incompatible pour l'argument " +
                              std::to_string(i + 1) + " de super(...)");
                    }
                }
            } else if (!call->arguments.empty()) {
                errorAt(expr, "La classe de base n'a pas de constructeur 'init'");
            }
            return AfrType::voidType();
        }

        if (const auto* member = dynamic_cast<const MemberAccessNode*>(call->callee.get())) {
            if (dynamic_cast<const SuperExpressionNode*>(member->object.get())) {
                if (!currentClass_) {
                    errorAt(expr, "'super' utilisé en dehors d'une méthode");
                }
                if (currentClass_->baseClass.empty()) {
                    errorAt(expr, "'super' sans classe de base");
                }
                const MethodSignature* sig = findMethod(currentClass_->baseClass, member->member);
                if (!sig) {
                    errorAt(expr, "Méthode '" + member->member + "' introuvable dans la classe de base");
                }
                if (call->arguments.size() < sig->requiredParamCount ||
                    call->arguments.size() > sig->paramTypes.size()) {
                    errorAt(expr, "Méthode parente '" + member->member + "' : nombre d'arguments incorrect");
                }
                for (std::size_t i = 0; i < call->arguments.size(); ++i) {
                    AfrType argType = analyzeExpression(*call->arguments[i], scope);
                    if (!isAssignable(sig->paramTypes[i], argType)) {
                        errorAt(expr, "Type incompatible pour l'argument " + std::to_string(i + 1));
                    }
                }
                return sig->returnType;
            }

            if (const auto* classId = dynamic_cast<const IdentifierNode*>(member->object.get())) {
                if (result_.classes.count(classId->name) &&
                    !scope.count(classId->name) &&
                    result_.globalVariables.find(classId->name) == result_.globalVariables.end()) {
                    const MethodSignature* sig = findMethod(classId->name, member->member);
                    if (!sig || !sig->isStatic) {
                        errorAt(expr, "Méthode statique '" + member->member + "' introuvable dans '" +
                              classId->name + "'");
                    }
                    if (call->arguments.size() < sig->requiredParamCount ||
                        call->arguments.size() > sig->paramTypes.size()) {
                        errorAt(expr, "Méthode statique '" + member->member + "' : nombre d'arguments incorrect");
                    }
                    for (std::size_t i = 0; i < call->arguments.size(); ++i) {
                        AfrType argType = analyzeExpression(*call->arguments[i], scope);
                        if (!isAssignable(sig->paramTypes[i], argType)) {
                            errorAt(expr, "Type incompatible pour l'argument " + std::to_string(i + 1));
                        }
                    }
                    return sig->returnType;
                }
            }

            AfrType objectType = analyzeExpression(*member->object, scope);

            if (objectType.kind != TypeKind::Class) {
                errorAt(expr, "Appel de méthode sur un type non objet");
            }

            const MethodSignature* sig = findMethod(objectType.className, member->member);
            if (!sig) {
                errorAt(expr, "Méthode '" + member->member + "' introuvable dans '" + objectType.className + "'");
            }
            if (sig->isStatic) {
                errorAt(expr, "Utilisez " + objectType.className + "." + member->member +
                      " pour une méthode statique");
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
            AfrType fnValueType;
            bool isFunctionValue = false;

            const auto scopeIt = scope.find(id->name);
            if (scopeIt != scope.end() && scopeIt->second.kind == TypeKind::Function) {
                fnValueType = scopeIt->second;
                isFunctionValue = true;
            } else {
                const auto globalIt = result_.globalVariables.find(id->name);
                if (globalIt != result_.globalVariables.end() &&
                    globalIt->second.kind == TypeKind::Function) {
                    fnValueType = globalIt->second;
                    isFunctionValue = true;
                }
            }

            if (isFunctionValue) {
                const auto paramTypes = fnValueType.functionParamTypeNames();
                if (call->arguments.size() != paramTypes.size()) {
                    errorAt(expr, "Appel de fonction attend " +
                          std::to_string(paramTypes.size()) + " argument(s), reçu " +
                          std::to_string(call->arguments.size()));
                }
                for (std::size_t i = 0; i < call->arguments.size(); ++i) {
                    const AfrType argType = analyzeExpression(*call->arguments[i], scope);
                    if (!isAssignable(typeFromName(paramTypes[i]), argType)) {
                        errorAt(expr, "Type incompatible pour l'argument " +
                              std::to_string(i + 1));
                    }
                }
                return fnValueType.functionReturnType();
            }

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

        if (dynamic_cast<const LambdaExpressionNode*>(call->callee.get())) {
            const AfrType fnValueType = analyzeExpression(*call->callee, scope);
            const auto paramTypes = fnValueType.functionParamTypeNames();
            if (call->arguments.size() != paramTypes.size()) {
                errorAt(expr, "Appel de lambda attend " +
                      std::to_string(paramTypes.size()) + " argument(s), reçu " +
                      std::to_string(call->arguments.size()));
            }
            for (std::size_t i = 0; i < call->arguments.size(); ++i) {
                const AfrType argType = analyzeExpression(*call->arguments[i], scope);
                if (!isAssignable(typeFromName(paramTypes[i]), argType)) {
                    errorAt(expr, "Type incompatible pour l'argument " +
                          std::to_string(i + 1));
                }
            }
            return fnValueType.functionReturnType();
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
            if (const auto* classId = dynamic_cast<const IdentifierNode*>(member->object.get())) {
                if (result_.classes.count(classId->name) &&
                    !scope.count(classId->name) &&
                    result_.globalVariables.find(classId->name) == result_.globalVariables.end()) {
                    const ClassInfo* cls = findClass(classId->name);
                    const FieldInfo* field = findField(*cls, member->member);
                    if (!field || !field->isStatic) {
                        errorAt(expr, "Champ statique '" + member->member + "' introuvable");
                    }
                    if (field->visibility != FieldVisibility::Public) {
                        errorAt(expr, "Champ statique '" + member->member + "' inaccessible");
                    }
                    return field->type;
                }
            }

            const ClassInfo* cls = findClass(objectType.className);
            const ClassInfo* ownerClass = cls;
            const FieldInfo* field = findFieldWithOwner(*cls, member->member, ownerClass);
            if (field) {
                if (field->isStatic) {
                    errorAt(expr, "Utilisez " + cls->name + "." + member->member +
                          " pour un champ statique");
                }
                if (!canAccessField(*field, *ownerClass, currentClass_)) {
                    errorAt(expr, "Champ '" + member->member + "' inaccessible");
                }
                return field->type;
            }

            if (const PropertyInfo* prop = findProperty(*cls, member->member)) {
                if (prop->visibility != FieldVisibility::Public) {
                    errorAt(expr, "Propriété '" + member->member + "' inaccessible");
                }
                return prop->type;
            }

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
        if (result_.classes.at(newExpr->className).isAbstract) {
            errorAt(expr, "Impossible d'instancier la classe abstraite '" + newExpr->className + "'");
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
        return target.className == value.className ||
               isSubclassOf(value.className, target.className);
    }
    if (target.kind == TypeKind::Record && value.kind == TypeKind::Record) {
        return target.recordName == value.recordName;
    }
    if (target.kind == TypeKind::List && value.kind == TypeKind::List) {
        if (!isConcreteTypeName(target.listElementTypeName)) return true;
        return isAssignable(target.listElementType(), value.listElementType());
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
    if (target.kind == TypeKind::Function && value.kind == TypeKind::Function) {
        return target.className == value.className &&
               target.listElementTypeName == value.listElementTypeName;
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

const FieldInfo* SemanticAnalyzer::findFieldWithOwner(const ClassInfo& cls,
                                                      const std::string& fieldName,
                                                      const ClassInfo*& ownerClass) const {
    auto it = cls.fields.find(fieldName);
    if (it != cls.fields.end()) {
        ownerClass = &cls;
        return &it->second;
    }
    if (!cls.baseClass.empty()) {
        const ClassInfo* base = findClass(cls.baseClass);
        if (base) return findFieldWithOwner(*base, fieldName, ownerClass);
    }
    return nullptr;
}

const PropertyInfo* SemanticAnalyzer::findProperty(const ClassInfo& cls,
                                                   const std::string& name) const {
    const auto it = cls.properties.find(name);
    if (it != cls.properties.end()) return &it->second;
    if (!cls.baseClass.empty()) {
        const ClassInfo* base = findClass(cls.baseClass);
        if (base) return findProperty(*base, name);
    }
    return nullptr;
}

bool SemanticAnalyzer::isSubclassOf(const std::string& derived, const std::string& base) const {
    if (derived == base) return true;
    const ClassInfo* cls = findClass(derived);
    while (cls && !cls->baseClass.empty()) {
        if (cls->baseClass == base) return true;
        cls = findClass(cls->baseClass);
    }
    return false;
}

bool SemanticAnalyzer::canAccessField(const FieldInfo& field, const ClassInfo& ownerClass,
                                      const ClassInfo* accessingClass) const {
    if (field.visibility == FieldVisibility::Public) return true;
    if (!accessingClass) return false;
    if (field.visibility == FieldVisibility::Private) {
        return accessingClass->name == ownerClass.name;
    }
    if (accessingClass->name == ownerClass.name) return true;
    return isSubclassOf(accessingClass->name, ownerClass.name);
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
