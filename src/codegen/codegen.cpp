#include "afrilang/codegen.hpp"

#include "afrilang/educational.hpp"

#include <cstdlib>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <algorithm>

namespace afrilang {

namespace {

std::string cppTypeFromAfrName(const std::string& typeName,
                               const std::vector<std::string>& typeParams) {
    const auto isParam = [&](const std::string& n) {
        return std::find(typeParams.begin(), typeParams.end(), n) != typeParams.end();
    };
    if (isParam(typeName)) return typeName;
    if (typeName.rfind("list ", 0) == 0) {
        const std::string elem = typeName.substr(5);
        if (isParam(elem)) return "std::vector<" + elem + ">";
    }
    if (!typeName.empty() && typeName.back() == '?') {
        const std::string inner = typeName.substr(0, typeName.size() - 1);
        if (isParam(inner)) return "std::optional<" + inner + ">";
    }
    return typeFromName(typeName).toCpp();
}

} // namespace

CodeGenerator::CodeGenerator(const ProgramNode& program, const SemanticResult& semantic)
    : program_(program), semantic_(semantic) {}

std::string CodeGenerator::generate() const {
    std::ostringstream out;
    generate(out);
    return out.str();
}

void CodeGenerator::generate(std::ostream& out) const {
    linkLibraries_.clear();
    emitHeader(out);
    emitExterns(out);
    emitRecords(out);
    emitEnums(out);
    emitInterfaces(out);
    emitClasses(out);
    emitModules(out);
    emitGlobalFunctions(out);
    emitTests(out);
    emitMain(out);
}

void CodeGenerator::emitHeader(std::ostream& out) const {
    out << "// Code généré par le compilateur AFRILANG\n";
    out << "// Ne pas modifier manuellement\n\n";
    out << "#include <iostream>\n";
    out << "#include <string>\n";
    out << "#include <vector>\n";
    out << "#include <unordered_map>\n";
    out << "#include <stdexcept>\n";
    out << "#include <functional>\n";

    bool needsOptional = false;
    for (const auto& [_, t] : semantic_.globalVariables) {
        if (t.kind == TypeKind::Optional) needsOptional = true;
    }
    if (!program_.enums.empty() || needsOptional) {
        out << "#include <optional>\n";
    }

    bool needsIo = false;
    bool needsJson = false;
    bool needsFs = false;
    bool needsHttp = false;
    bool needsStr = false;
    bool needsLog = false;
    bool needsMath = false;
    bool needsTime = false;
    bool needsRe = false;
    bool needsCollections = false;
    for (const auto& module : program_.modules) {
        if (module->name == "io") needsIo = true;
        if (module->name == "json") needsJson = true;
        if (module->name == "fs") needsFs = true;
        if (module->name == "http") needsHttp = true;
        if (module->name == "str") needsStr = true;
        if (module->name == "logging") needsLog = true;
        if (module->name == "math") needsMath = true;
        if (module->name == "chrono") needsTime = true;
        if (module->name == "re") needsRe = true;
        if (module->name == "collections") needsCollections = true;
    }
    if (needsIo) out << "#include \"io.hpp\"\n";
    if (needsJson) out << "#include \"json.hpp\"\n";
    if (needsFs) out << "#include \"fs.hpp\"\n";
    if (needsHttp) out << "#include \"http.hpp\"\n";
    if (needsStr) out << "#include \"str.hpp\"\n";
    if (needsLog) out << "#include \"log.hpp\"\n";
    if (needsMath) out << "#include \"math.hpp\"\n";
    if (needsTime) out << "#include \"time.hpp\"\n";
    if (needsRe) out << "#include \"re.hpp\"\n";
    if (needsCollections) out << "#include \"collections.hpp\"\n";
    out << "#include \"str.hpp\"\n";

    bool needsResult = false;
    for (const auto& func : program_.functions) {
        if (func->returnsResult) needsResult = true;
    }
    for (const auto& cls : program_.classes) {
        for (const auto& method : cls->methods) {
            if (method->returnsResult) needsResult = true;
        }
    }
    if (needsResult) out << "#include \"result.hpp\"\n";
    if (!program_.externs.empty()) {
        out << "#include <cmath>\n";
        out << "#include <cstring>\n";
    }
    out << "\n";
}

void CodeGenerator::emitExterns(std::ostream& out) const {
    for (const auto& ext : program_.externs) {
        collectLinkLibrary(ext->library, linkLibraries_);

        out << "extern \"C\" ";
        if (ext->returnTypeName.empty()) {
            out << "void ";
        } else {
            out << ffiTypeToCpp(ext->returnTypeName) << " ";
        }
        out << ext->name << "(";
        for (std::size_t i = 0; i < ext->parameters.size(); ++i) {
            if (i > 0) out << ", ";
            out << ffiTypeToCpp(ext->parameters[i].typeName) << " "
                << ext->parameters[i].name;
        }
        out << ");\n";
    }
    if (!program_.externs.empty()) out << "\n";
}

std::string CodeGenerator::ffiTypeToCpp(const std::string& typeName) {
    if (typeName == "number") return "double";
    if (typeName == "text") return "const char*";
    if (typeName == "pointer") return "void*";
    if (typeName == "bool") return "bool";
    return typeFromName(typeName).toCpp();
}

void CodeGenerator::collectLinkLibrary(const std::string& library,
                                       std::unordered_set<std::string>& libs) {
    const std::string flag = linkFlagForLibrary(library);
    if (!flag.empty()) libs.insert(flag);
}

std::string CodeGenerator::linkFlagForLibrary(const std::string& library) {
    if (library == "c" || library == "libc") return {};
    if (library == "m" || library == "libm") return "-lm";
    if (library == "pthread") return "-lpthread";
    if (library == "dl") return "-ldl";
    return "-l" + library;
}

std::string CodeGenerator::compilerForTarget(const std::string& target) {
    if (target == "linux-arm64") return "aarch64-linux-gnu-g++";
    if (target == "wasm32") return "em++";
    return "g++";
}

void CodeGenerator::emitRecords(std::ostream& out) const {
    for (const auto& record : program_.records) {
        out << "struct " << record->name << " {\n";
        for (const auto& field : record->fields) {
            out << "    " << typeFromName(field.typeName).toCpp()
                << " " << field.name << ";\n";
        }
        out << "};\n\n";
    }

    for (const auto& module : program_.modules) {
        out << "namespace " << module->name << " {\n";
        for (const auto& record : module->records) {
            out << "struct " << record->name << " {\n";
            for (const auto& field : record->fields) {
                out << "    " << typeFromName(field.typeName).toCpp()
                    << " " << field.name << ";\n";
            }
            out << "};\n\n";
        }
        out << "} // namespace " << module->name << "\n\n";
    }
}

void CodeGenerator::emitEnums(std::ostream& out) const {
    for (const auto& en : program_.enums) {
        const EnumInfo* info = nullptr;
        auto it = semantic_.enums.find(en->name);
        if (it != semantic_.enums.end()) info = &it->second;

        out << "struct " << en->name << " {\n";
        out << "    enum class Tag {";
        for (std::size_t i = 0; i < en->cases.size(); ++i) {
            if (i > 0) out << ',';
            out << " " << en->cases[i].name;
        }
        out << " };\n";
        out << "    Tag tag;\n";

        if (info) {
            std::unordered_set<std::string> emittedFields;
            for (const auto& [_, c] : info->cases) {
                for (const auto& [fname, ftype] : c.fields) {
                    if (emittedFields.count(fname)) continue;
                    emittedFields.insert(fname);
                    out << "    " << ftype.toCpp() << " " << fname << ";\n";
                }
            }
        }

        for (const auto& c : en->cases) {
            out << "    static " << en->name << " make_" << c.name << "(";
            if (info && info->cases.count(c.name)) {
                const auto& fields = info->cases.at(c.name).fields;
                for (std::size_t i = 0; i < fields.size(); ++i) {
                    if (i > 0) out << ", ";
                    out << fields[i].second.toCpp() << " " << fields[i].first;
                }
            }
            out << ") {\n";
            out << "        " << en->name << " v;\n";
            out << "        v.tag = Tag::" << c.name << ";\n";
            if (info && info->cases.count(c.name)) {
                for (const auto& [fname, _] : info->cases.at(c.name).fields) {
                    out << "        v." << fname << " = " << fname << ";\n";
                }
            }
            out << "        return v;\n";
            out << "    }\n";
        }

        out << "};\n\n";
    }
}

void CodeGenerator::emitClass(std::ostream& out, const ClassNode& cls) const {
    const ClassInfo* classInfo = nullptr;
    auto it = semantic_.classes.find(cls.name);
    if (it != semantic_.classes.end()) classInfo = &it->second;

    out << "class " << cls.name;
    bool firstBase = true;
    if (!cls.baseClassName.empty()) {
        out << " : public " << cls.baseClassName;
        firstBase = false;
    }
    for (const auto& iface : cls.interfaceNames) {
        out << (firstBase ? " : public " : ", public ") << iface;
        firstBase = false;
    }
    out << " {\n";

    out << "public:\n";
    for (const auto& field : cls.fields) {
        out << "    " << typeFromName(field.typeName).toCpp()
            << " " << field.name << ";\n";
    }
    if (!cls.fields.empty()) out << "\n";

    const FunctionNode* constructor = nullptr;
    for (const auto& method : cls.methods) {
        if (method->name == "init") {
            constructor = method.get();
            break;
        }
    }

    if (constructor) {
        out << "    " << cls.name << "(" << paramList(*constructor) << ") {\n";
        for (const auto& stmt : constructor->body) {
            emitStatement(out, *stmt, 2, classInfo);
        }
        out << "    }\n\n";
    }

    for (const auto& method : cls.methods) {
        if (method->name == "init") continue;
        emitFunction(out, *method, classInfo, 1);
        out << "\n";
    }

    out << "};\n\n";
}

void CodeGenerator::emitInterfaces(std::ostream& out) const {
    for (const auto& iface : program_.interfaces) {
        out << "class " << iface->name << " {\npublic:\n";
        out << "    virtual ~" << iface->name << "() = default;\n";
        for (const auto& method : iface->methods) {
            const std::string ret = functionReturnCpp(*method);
            out << "    virtual " << ret << " " << method->name
                << "(" << paramList(*method) << ") = 0;\n";
        }
        out << "};\n\n";
    }
}

void CodeGenerator::emitClasses(std::ostream& out) const {
    for (const auto& cls : program_.classes) {
        emitClass(out, *cls);
    }
}

void CodeGenerator::emitModules(std::ostream& out) const {
    for (const auto& module : program_.modules) {
        out << "namespace " << module->name << " {\n";

        for (const auto& cls : module->classes) {
            const ClassInfo* classInfo = nullptr;
            auto it = semantic_.classes.find(cls->name);
            if (it != semantic_.classes.end()) classInfo = &it->second;

            out << "class " << cls->name;
            if (!cls->baseClassName.empty()) {
                out << " : public " << cls->baseClassName;
            }
            out << " {\npublic:\n";

            for (const auto& field : cls->fields) {
                out << "    " << typeFromName(field.typeName).toCpp()
                    << " " << field.name << ";\n";
            }
            if (!cls->fields.empty()) out << "\n";

            const FunctionNode* constructor = nullptr;
            for (const auto& method : cls->methods) {
                if (method->name == "init") constructor = method.get();
            }
            if (constructor) {
                out << "    " << cls->name << "(" << paramList(*constructor) << ") {\n";
                for (const auto& stmt : constructor->body) {
                    emitStatement(out, *stmt, 2, classInfo);
                }
                out << "    }\n\n";
            }

            for (const auto& method : cls->methods) {
                if (method->name == "init") continue;
                emitFunction(out, *method, classInfo, 1);
                out << "\n";
            }
            out << "};\n\n";
        }

        for (const auto& func : module->functions) {
            if (usesStdlibModule(module->name)) {
                emitStdlibFunction(out, module->name, *func, 1);
            } else {
                emitFunction(out, *func, nullptr, 1);
            }
            out << "\n";
        }

        out << "} // namespace " << module->name << "\n\n";
    }
}

std::string CodeGenerator::paramList(const FunctionNode& func) {
    std::ostringstream out;
    for (std::size_t i = 0; i < func.parameters.size(); ++i) {
        if (i > 0) out << ", ";
        const auto& param = func.parameters[i];
        out << cppTypeFromAfrName(param.typeName, func.typeParams) << " " << param.name;
        if (param.defaultValue) {
            out << " = ";
            if (const auto* str = dynamic_cast<const StringLiteralNode*>(param.defaultValue.get())) {
                out << "\"" << escapeString(str->value) << "\"";
            } else if (const auto* num = dynamic_cast<const NumberLiteralNode*>(param.defaultValue.get())) {
                out << num->value;
            } else if (const auto* boolean = dynamic_cast<const BoolLiteralNode*>(param.defaultValue.get())) {
                out << (boolean->value ? "true" : "false");
            }
        }
    }
    return out.str();
}

void CodeGenerator::emitFunction(std::ostream& out, const FunctionNode& func,
                                 const ClassInfo* ownerClass, int indentLevel) const {
    const std::string returnCpp = functionReturnCpp(func);

    if (!func.typeParams.empty()) {
        indent(out, indentLevel);
        out << "template<typename";
        for (std::size_t i = 0; i < func.typeParams.size(); ++i) {
            if (i == 0) out << " ";
            else out << ", typename ";
            out << func.typeParams[i];
        }
        out << ">\n";
    }

    indent(out, indentLevel);
    if (ownerClass) {
        out << "virtual ";
    }
    out << returnCpp << " " << func.name << "(" << paramList(func) << ")";

    if (ownerClass) {
        bool shouldOverride = false;
        for (const auto& cls : program_.classes) {
            if (cls->name != ownerClass->name) continue;
            if (!cls->baseClassName.empty()) {
                auto baseIt = semantic_.classes.find(cls->baseClassName);
                if (baseIt != semantic_.classes.end() &&
                    baseIt->second.methods.count(func.name)) {
                    shouldOverride = true;
                }
            }
            for (const auto& iface : cls->interfaceNames) {
                auto iit = semantic_.interfaces.find(iface);
                if (iit != semantic_.interfaces.end() &&
                    iit->second.methods.count(func.name)) {
                    shouldOverride = true;
                }
            }
            break;
        }
        if (shouldOverride) out << " override";
    }

    out << " {\n";
    const FunctionNode* saved = currentFunction_;
    currentFunction_ = &func;
    for (const auto& stmt : func.body) {
        emitStatement(out, *stmt, indentLevel + 1, ownerClass);
    }
    currentFunction_ = saved;
    indent(out, indentLevel);
    out << "}\n";
}

void CodeGenerator::emitGlobalFunctions(std::ostream& out) const {
    for (const auto& func : program_.functions) {
        emitFunction(out, *func, nullptr, 0);
        out << "\n";
    }
}

void CodeGenerator::emitTests(std::ostream& out) const {
    if (program_.tests.empty()) return;

    out << "static int afr_tests_failed = 0;\n\n";

    for (const auto& test : program_.tests) {
        const std::string fn = "afr_test_" + sanitizeTestName(test->name);
        out << "void " << fn << "() {\n";
        bool saved = inTest_;
        inTest_ = true;
        for (const auto& stmt : test->body) {
            emitStatement(out, *stmt, 1, nullptr);
        }
        inTest_ = saved;
        out << "}\n\n";
    }
}

void CodeGenerator::emitMain(std::ostream& out) const {
    for (const auto& modName : semantic_.usedModules) {
        out << "using namespace " << modName << ";\n";
    }
    if (!semantic_.usedModules.empty()) out << "\n";

    out << "int main() {\n";

    for (const auto& stmt : program_.statements) {
        emitStatement(out, *stmt, 1, nullptr);
    }

    for (const auto& test : program_.tests) {
        out << "    " << "afr_test_" << sanitizeTestName(test->name) << "();\n";
    }

    if (!program_.tests.empty()) {
        out << "    if (afr_tests_failed > 0) return 1;\n";
    }

    out << "    return 0;\n";
    out << "}\n";
}

void CodeGenerator::emitStatement(std::ostream& out, const StatementNode& stmt, int indentLevel,
                                  const ClassInfo* ownerClass) const {
    emitLineDirective(out, stmt, indentLevel);
    indent(out, indentLevel);

    if (const auto* explain = dynamic_cast<const ExplainStatementNode*>(&stmt)) {
        const std::string text = explainStatement(*explain->statement);
        out << "std::cout << \"[explication] " << escapeString(text)
            << "\" << std::endl;\n";
        emitStatement(out, *explain->statement, indentLevel, ownerClass);
        return;
    }

    if (const auto* say = dynamic_cast<const SayStatementNode*>(&stmt)) {
        out << "std::cout << ";
        emitExpression(out, *say->value, ownerClass);
        out << " << std::endl;\n";
        return;
    }

    if (const auto* assign = dynamic_cast<const AssignStatementNode*>(&stmt)) {
        const std::string constPrefix = assign->isConst ? "const " : "";

        if (const auto* newExpr = dynamic_cast<const NewExpressionNode*>(assign->value.get())) {
            out << constPrefix << newExpr->className << " " << assign->name;
            const ClassInfo* clsInfo = nullptr;
            auto it = semantic_.classes.find(newExpr->className);
            if (it != semantic_.classes.end()) clsInfo = &it->second;

            const FunctionNode* initMethod = nullptr;
            for (const auto& cls : program_.classes) {
                if (cls->name == newExpr->className) {
                    for (const auto& m : cls->methods) {
                        if (m->name == "init") initMethod = m.get();
                    }
                }
            }
            if (!initMethod) {
                for (const auto& module : program_.modules) {
                    for (const auto& cls : module->classes) {
                        if (cls->name == newExpr->className) {
                            for (const auto& m : cls->methods) {
                                if (m->name == "init") initMethod = m.get();
                            }
                        }
                    }
                }
            }

            if (initMethod && !initMethod->parameters.empty()) {
                out << "(";
                for (std::size_t i = 0; i < initMethod->parameters.size(); ++i) {
                    if (i > 0) out << ", ";
                    out << typeFromName(initMethod->parameters[i].typeName).toCpp() << "{}";
                }
                out << ")";
            }
            out << ";\n";
            (void)clsInfo;
            return;
        }

        if (const auto* empty = dynamic_cast<const EmptyListNode*>(assign->value.get())) {
            out << constPrefix << "std::vector<" << typeFromName(empty->elementTypeName).toCpp()
                << "> " << assign->name << " = {};\n";
            return;
        }

        if (const auto* emptyMap = dynamic_cast<const EmptyMapNode*>(assign->value.get())) {
            out << constPrefix << "std::unordered_map<"
                << typeFromName(emptyMap->keyTypeName).toCpp() << ", "
                << typeFromName(emptyMap->valueTypeName).toCpp()
                << "> " << assign->name << " = {};\n";
            return;
        }

        if (const auto* mapLit = dynamic_cast<const MapLiteralNode*>(assign->value.get())) {
            std::string keyCpp;
            std::string valCpp;
            if (!assign->typeName.empty()) {
                AfrType t = typeFromName(assign->typeName);
                if (t.kind == TypeKind::Map) {
                    keyCpp = t.mapKeyType().toCpp();
                    valCpp = t.mapValueType().toCpp();
                }
            }
            if (keyCpp.empty() && !mapLit->pairs.empty()) {
                keyCpp = inferExpressionType(*mapLit->pairs[0].key);
                valCpp = inferExpressionType(*mapLit->pairs[0].value);
            }
            out << constPrefix << "std::unordered_map<" << keyCpp << ", " << valCpp << "> "
                << assign->name << " = {";
            for (std::size_t i = 0; i < mapLit->pairs.size(); ++i) {
                if (i > 0) out << ", ";
                out << "{";
                emitExpression(out, *mapLit->pairs[i].key, ownerClass);
                out << ", ";
                emitExpression(out, *mapLit->pairs[i].value, ownerClass);
                out << "}";
            }
            out << "};\n";
            return;
        }

        if (const auto* list = dynamic_cast<const ListLiteralNode*>(assign->value.get())) {
            std::string elemCpp;
            if (!assign->typeName.empty()) {
                AfrType t = typeFromName(assign->typeName);
                if (t.kind == TypeKind::List) elemCpp = t.listElementType().toCpp();
            }
            if (elemCpp.empty() && !list->elements.empty()) {
                elemCpp = inferExpressionType(*list->elements[0]);
            }
            out << constPrefix << "std::vector<" << elemCpp << "> " << assign->name << " = {";
            for (std::size_t i = 0; i < list->elements.size(); ++i) {
                if (i > 0) out << ", ";
                emitExpression(out, *list->elements[i], ownerClass);
            }
            out << "};\n";
            return;
        }

        std::string typeCpp;
        if (!assign->typeName.empty()) {
            typeCpp = typeFromName(assign->typeName).toCpp();
        } else {
            typeCpp = inferExpressionType(*assign->value);
        }
        out << constPrefix << typeCpp << " " << assign->name << " = ";
        emitExpression(out, *assign->value, ownerClass);
        out << ";\n";
        return;
    }

    if (const auto* set = dynamic_cast<const SetStatementNode*>(&stmt)) {
        emitExpression(out, *set->target, ownerClass);
        out << " = ";
        emitExpression(out, *set->value, ownerClass);
        out << ";\n";
        return;
    }

    if (const auto* idxAssign = dynamic_cast<const IndexAssignStatementNode*>(&stmt)) {
        const AfrType containerType = inferExpressionAfrType(*idxAssign->object);
        emitExpression(out, *idxAssign->object, ownerClass);
        out << "[";
        if (containerType.kind == TypeKind::List) {
            out << "static_cast<size_t>(";
            emitExpression(out, *idxAssign->index, ownerClass);
            out << ")";
        } else {
            emitExpression(out, *idxAssign->index, ownerClass);
        }
        out << "] = ";
        emitExpression(out, *idxAssign->value, ownerClass);
        out << ";\n";
        return;
    }

    if (const auto* addTo = dynamic_cast<const AddToListStatementNode*>(&stmt)) {
        emitExpression(out, *addTo->list, ownerClass);
        out << ".push_back(";
        emitExpression(out, *addTo->value, ownerClass);
        out << ");\n";
        return;
    }

    if (const auto* ask = dynamic_cast<const AskStatementNode*>(&stmt)) {
        out << "std::cout << ";
        emitExpression(out, *ask->prompt, ownerClass);
        out << ";\n";
        indent(out, indentLevel);
        out << "std::getline(std::cin, " << ask->variableName << ");\n";
        return;
    }

    if (dynamic_cast<const UseStatementNode*>(&stmt)) {
        return;
    }

    if (const auto* ret = dynamic_cast<const ReturnStatementNode*>(&stmt)) {
        if (ret->isError && currentFunction_ && currentFunction_->returnsResult) {
            const std::string alias = resultTypeAlias(currentFunction_->returnTypeName);
            out << alias << " _result;\n";
            indent(out, indentLevel);
            out << "_result.isError = true;\n";
            indent(out, indentLevel);
            out << "_result.message = ";
            emitExpression(out, *ret->value, ownerClass);
            out << ";\n";
            indent(out, indentLevel);
            out << "return _result;\n";
            return;
        }
        if (currentFunction_ && currentFunction_->returnsResult) {
            const std::string alias = resultTypeAlias(currentFunction_->returnTypeName);
            out << alias << " _result;\n";
            indent(out, indentLevel);
            out << "_result.value = ";
            emitExpression(out, *ret->value, ownerClass);
            out << ";\n";
            indent(out, indentLevel);
            out << "return _result;\n";
            return;
        }
        out << "return ";
        emitExpression(out, *ret->value, ownerClass);
        out << ";\n";
        return;
    }

    if (const auto* assertStmt = dynamic_cast<const AssertStatementNode*>(&stmt)) {
        out << "if (!(";
        emitExpression(out, *assertStmt->condition, ownerClass);
        out << ")) {\n";
        indent(out, indentLevel + 1);
        out << "std::cerr << \"ASSERT FAILED";
        if (!assertStmt->label.empty()) out << ": " << escapeString(assertStmt->label);
        out << "\" << std::endl;\n";
        indent(out, indentLevel + 1);
        if (inTest_) {
            out << "++afr_tests_failed;\n";
            indent(out, indentLevel + 1);
            out << "return;\n";
        } else {
            out << "std::exit(1);\n";
        }
        indent(out, indentLevel);
        out << "}\n";
        return;
    }

    if (const auto* matchStmt = dynamic_cast<const MatchStatementNode*>(&stmt)) {
        std::string enumName;
        if (const auto* id = dynamic_cast<const IdentifierNode*>(matchStmt->subject.get())) {
            auto vit = semantic_.globalVariables.find(id->name);
            if (vit != semantic_.globalVariables.end() &&
                vit->second.kind == TypeKind::Enum) {
                enumName = vit->second.className;
            }
        }
        if (enumName.empty()) {
            std::string cppType = inferExpressionType(*matchStmt->subject);
            enumName = cppType;
        }

        indent(out, indentLevel);
        out << "{\n";
        indent(out, indentLevel + 1);
        out << enumName << " _afr_match = ";
        emitExpression(out, *matchStmt->subject, ownerClass);
        out << ";\n";

        for (std::size_t i = 0; i < matchStmt->arms.size(); ++i) {
            const auto& arm = matchStmt->arms[i];
            indent(out, indentLevel + 1);
            if (arm.isDefault) {
                out << "else {\n";
            } else if (i == 0) {
                out << "if (_afr_match.tag == " << enumName << "::Tag::" << arm.caseName
                    << ") {\n";
            } else {
                out << "else if (_afr_match.tag == " << enumName << "::Tag::" << arm.caseName
                    << ") {\n";
            }
            for (const auto& bodyStmt : arm.body) {
                emitStatement(out, *bodyStmt, indentLevel + 2, ownerClass);
            }
            indent(out, indentLevel + 1);
            out << "}";
            if (i + 1 == matchStmt->arms.size()) out << "\n";
        }
        indent(out, indentLevel);
        out << "}\n";
        return;
    }

    if (const auto* ifStmt = dynamic_cast<const IfStatementNode*>(&stmt)) {
        out << "if (";
        emitExpression(out, *ifStmt->condition, ownerClass);
        out << ") {\n";
        for (const auto& bodyStmt : ifStmt->thenBody) {
            emitStatement(out, *bodyStmt, indentLevel + 1, ownerClass);
        }
        indent(out, indentLevel);
        out << "}";
        if (!ifStmt->elseBody.empty()) {
            out << " else {\n";
            for (const auto& bodyStmt : ifStmt->elseBody) {
                emitStatement(out, *bodyStmt, indentLevel + 1, ownerClass);
            }
            indent(out, indentLevel);
            out << "}";
        }
        out << "\n";
        return;
    }

    if (const auto* whileStmt = dynamic_cast<const WhileStatementNode*>(&stmt)) {
        out << "while (";
        emitExpression(out, *whileStmt->condition, ownerClass);
        out << ") {\n";
        for (const auto& bodyStmt : whileStmt->body) {
            emitStatement(out, *bodyStmt, indentLevel + 1, ownerClass);
        }
        indent(out, indentLevel);
        out << "}\n";
        return;
    }

    if (const auto* repeat = dynamic_cast<const RepeatStatementNode*>(&stmt)) {
        out << "for (int _i = 0; _i < static_cast<int>(";
        emitExpression(out, *repeat->count, ownerClass);
        out << "); ++_i) {\n";
        for (const auto& bodyStmt : repeat->body) {
            emitStatement(out, *bodyStmt, indentLevel + 1, ownerClass);
        }
        indent(out, indentLevel);
        out << "}\n";
        return;
    }

    if (const auto* forEach = dynamic_cast<const ForEachStatementNode*>(&stmt)) {
        const AfrType containerType = inferExpressionAfrType(*forEach->list);
        if (containerType.kind == TypeKind::Map && !forEach->valueName.empty()) {
            out << "for (auto& _afr_pair : ";
            emitExpression(out, *forEach->list, ownerClass);
            out << ") {\n";
            indent(out, indentLevel + 1);
            out << "auto& " << forEach->itemName << " = _afr_pair.first;\n";
            indent(out, indentLevel + 1);
            out << "auto& " << forEach->valueName << " = _afr_pair.second;\n";
        } else {
            out << "for (auto& " << forEach->itemName << " : ";
            emitExpression(out, *forEach->list, ownerClass);
            out << ") {\n";
        }
        for (const auto& bodyStmt : forEach->body) {
            emitStatement(out, *bodyStmt, indentLevel + 1, ownerClass);
        }
        indent(out, indentLevel);
        out << "}\n";
        return;
    }

    if (const auto* forRange = dynamic_cast<const ForRangeStatementNode*>(&stmt)) {
        out << "for (double " << forRange->varName << " = ";
        emitExpression(out, *forRange->start, ownerClass);
        out << "; " << forRange->varName << " <= ";
        emitExpression(out, *forRange->end, ownerClass);
        out << "; " << forRange->varName << " += ";
        if (forRange->step) {
            emitExpression(out, *forRange->step, ownerClass);
        } else {
            out << "1.0";
        }
        out << ") {\n";
        for (const auto& bodyStmt : forRange->body) {
            emitStatement(out, *bodyStmt, indentLevel + 1, ownerClass);
        }
        indent(out, indentLevel);
        out << "}\n";
        return;
    }

    if (const auto* tryStmt = dynamic_cast<const TryStatementNode*>(&stmt)) {
        out << "try {\n";
        for (const auto& bodyStmt : tryStmt->tryBody) {
            emitStatement(out, *bodyStmt, indentLevel + 1, ownerClass);
        }
        indent(out, indentLevel);
        out << "} catch (const std::exception& _afr_ex) {\n";
        indent(out, indentLevel + 1);
        out << "std::string " << tryStmt->catchVarName
            << " = _afr_ex.what();\n";
        for (const auto& bodyStmt : tryStmt->catchBody) {
            emitStatement(out, *bodyStmt, indentLevel + 1, ownerClass);
        }
        indent(out, indentLevel);
        out << "}\n";
        return;
    }

    if (const auto* raiseStmt = dynamic_cast<const RaiseStatementNode*>(&stmt)) {
        out << "throw std::runtime_error(";
        emitExpression(out, *raiseStmt->message, ownerClass);
        out << ");\n";
        return;
    }

    if (dynamic_cast<const BreakStatementNode*>(&stmt)) {
        out << "break;\n";
        return;
    }

    if (dynamic_cast<const ContinueStatementNode*>(&stmt)) {
        out << "continue;\n";
        return;
    }

    if (const auto* exprStmt = dynamic_cast<const ExpressionStatementNode*>(&stmt)) {
        emitExpression(out, *exprStmt->expression, ownerClass);
        out << ";\n";
        return;
    }
}

void CodeGenerator::emitExpression(std::ostream& out, const ExpressionNode& expr,
                                     const ClassInfo* ownerClass) const {
    if (const auto* str = dynamic_cast<const StringLiteralNode*>(&expr)) {
        out << '"' << escapeString(str->value) << '"';
        return;
    }

    if (const auto* interp = dynamic_cast<const InterpolatedStringNode*>(&expr)) {
        out << "afrilang::runtime::str::concat({";
        for (std::size_t i = 0; i < interp->parts.size(); ++i) {
            if (i > 0) out << ", ";
            out << "afrilang::runtime::str::toString(";
            emitExpression(out, *interp->parts[i], ownerClass);
            out << ")";
        }
        out << "})";
        return;
    }

    if (const auto* num = dynamic_cast<const NumberLiteralNode*>(&expr)) {
        if (num->value == static_cast<int>(num->value)) {
            out << static_cast<int>(num->value);
        } else {
            out << num->value;
        }
        return;
    }

    if (const auto* boolean = dynamic_cast<const BoolLiteralNode*>(&expr)) {
        out << (boolean->value ? "true" : "false");
        return;
    }

    if (dynamic_cast<const ThisExpressionNode*>(&expr)) {
        return;
    }

    if (const auto* id = dynamic_cast<const IdentifierNode*>(&expr)) {
        for (const auto& modName : semantic_.usedModules) {
            auto modIt = semantic_.modules.find(modName);
            if (modIt != semantic_.modules.end() && modIt->second.functions.count(id->name)) {
                out << modName << "::" << id->name;
                return;
            }
        }
        auto vit = semantic_.globalVariables.find(id->name);
        if (vit != semantic_.globalVariables.end() &&
            vit->second.kind == TypeKind::Optional) {
            out << id->name << ".value()";
            return;
        }
        out << id->name;
        return;
    }

    if (const auto* bin = dynamic_cast<const BinaryOpNode*>(&expr)) {
        if (bin->op == "+") {
            const auto* leftStr = dynamic_cast<const StringLiteralNode*>(bin->left.get());
            const auto* rightStr = dynamic_cast<const StringLiteralNode*>(bin->right.get());
            if (leftStr || rightStr) {
                out << "(";
                emitExpression(out, *bin->left, ownerClass);
                out << " + ";
                emitExpression(out, *bin->right, ownerClass);
                out << ")";
                return;
            }
        }
        out << "(";
        emitExpression(out, *bin->left, ownerClass);
        out << " " << bin->op << " ";
        emitExpression(out, *bin->right, ownerClass);
        out << ")";
        return;
    }

    if (const auto* isError = dynamic_cast<const IsErrorCheckNode*>(&expr)) {
        emitExpression(out, *isError->value, ownerClass);
        out << ".isError";
        return;
    }

    if (const auto* isDefined = dynamic_cast<const IsDefinedCheckNode*>(&expr)) {
        if (const auto* id = dynamic_cast<const IdentifierNode*>(isDefined->value.get())) {
            out << id->name << ".has_value()";
        } else {
            emitExpression(out, *isDefined->value, ownerClass);
            out << ".has_value()";
        }
        return;
    }

    if (dynamic_cast<const NothingLiteralNode*>(&expr)) {
        out << "std::nullopt";
        return;
    }

    if (const auto* enumCase = dynamic_cast<const EnumCaseExprNode*>(&expr)) {
        out << enumCase->enumName << "::make_" << enumCase->caseName << "(";
        for (std::size_t i = 0; i < enumCase->arguments.size(); ++i) {
            if (i > 0) out << ", ";
            emitExpression(out, *enumCase->arguments[i], ownerClass);
        }
        out << ")";
        return;
    }

    if (const auto* unary = dynamic_cast<const UnaryOpNode*>(&expr)) {
        out << unary->op;
        emitExpression(out, *unary->operand, ownerClass);
        return;
    }

    if (const auto* list = dynamic_cast<const ListLiteralNode*>(&expr)) {
        std::string elemCpp = list->elements.empty()
            ? "double"
            : inferExpressionType(*list->elements[0]);
        out << "std::vector<" << elemCpp << ">{";
        for (std::size_t i = 0; i < list->elements.size(); ++i) {
            if (i > 0) out << ", ";
            emitExpression(out, *list->elements[i], ownerClass);
        }
        out << "}";
        return;
    }

    if (const auto* empty = dynamic_cast<const EmptyListNode*>(&expr)) {
        out << "std::vector<" << typeFromName(empty->elementTypeName).toCpp() << ">()";
        return;
    }

    if (const auto* emptyMap = dynamic_cast<const EmptyMapNode*>(&expr)) {
        out << "std::unordered_map<"
            << typeFromName(emptyMap->keyTypeName).toCpp() << ", "
            << typeFromName(emptyMap->valueTypeName).toCpp() << ">()";
        return;
    }

    if (const auto* mapLit = dynamic_cast<const MapLiteralNode*>(&expr)) {
        std::string keyCpp = mapLit->pairs.empty()
            ? "std::string"
            : inferExpressionType(*mapLit->pairs[0].key);
        std::string valCpp = mapLit->pairs.empty()
            ? "double"
            : inferExpressionType(*mapLit->pairs[0].value);
        out << "std::unordered_map<" << keyCpp << ", " << valCpp << ">{";
        for (std::size_t i = 0; i < mapLit->pairs.size(); ++i) {
            if (i > 0) out << ", ";
            out << "{";
            emitExpression(out, *mapLit->pairs[i].key, ownerClass);
            out << ", ";
            emitExpression(out, *mapLit->pairs[i].value, ownerClass);
            out << "}";
        }
        out << "}";
        return;
    }

    if (const auto* index = dynamic_cast<const IndexExpressionNode*>(&expr)) {
        const AfrType containerType = inferExpressionAfrType(*index->object);
        emitExpression(out, *index->object, ownerClass);
        out << "[";
        if (containerType.kind == TypeKind::List) {
            out << "static_cast<size_t>(";
            emitExpression(out, *index->index, ownerClass);
            out << ")";
        } else {
            emitExpression(out, *index->index, ownerClass);
        }
        out << "]";
        return;
    }

    if (const auto* length = dynamic_cast<const LengthExpressionNode*>(&expr)) {
        emitExpression(out, *length->object, ownerClass);
        out << ".size()";
        return;
    }

    if (const auto* call = dynamic_cast<const CallExpressionNode*>(&expr)) {
        const MethodSignature* externSig = nullptr;
        if (const auto* id = dynamic_cast<const IdentifierNode*>(call->callee.get())) {
            const auto it = semantic_.functions.find(id->name);
            if (it != semantic_.functions.end() && it->second.isExtern) {
                externSig = &it->second;
            }
        }

        emitExpression(out, *call->callee, ownerClass);
        out << "(";
        for (std::size_t i = 0; i < call->arguments.size(); ++i) {
            if (i > 0) out << ", ";
            emitExpression(out, *call->arguments[i], ownerClass);
            if (externSig && i < externSig->paramTypes.size() &&
                externSig->paramTypes[i].kind == TypeKind::Text) {
                out << ".c_str()";
            }
        }
        out << ")";
        return;
    }

    if (const auto* member = dynamic_cast<const MemberAccessNode*>(&expr)) {
        if (dynamic_cast<const ThisExpressionNode*>(member->object.get())) {
            out << member->member;
        } else {
            emitExpression(out, *member->object, ownerClass);
            out << "." << member->member;
        }
        return;
    }

    if (const auto* newExpr = dynamic_cast<const NewExpressionNode*>(&expr)) {
        out << newExpr->className << "()";
        return;
    }
}

std::string CodeGenerator::inferExpressionType(const ExpressionNode& expr) const {
    if (dynamic_cast<const StringLiteralNode*>(&expr)) return "std::string";
    if (dynamic_cast<const NumberLiteralNode*>(&expr)) return "double";
    if (dynamic_cast<const BoolLiteralNode*>(&expr)) return "bool";

    if (const auto* newExpr = dynamic_cast<const NewExpressionNode*>(&expr)) {
        return newExpr->className;
    }

    if (dynamic_cast<const InterpolatedStringNode*>(&expr)) return "std::string";

    if (const auto* emptyMap = dynamic_cast<const EmptyMapNode*>(&expr)) {
        return "std::unordered_map<" +
               typeFromName(emptyMap->keyTypeName).toCpp() + ", " +
               typeFromName(emptyMap->valueTypeName).toCpp() + ">";
    }

    if (const auto* mapLit = dynamic_cast<const MapLiteralNode*>(&expr)) {
        if (!mapLit->pairs.empty()) {
            return "std::unordered_map<" +
                   inferExpressionType(*mapLit->pairs[0].key) + ", " +
                   inferExpressionType(*mapLit->pairs[0].value) + ">";
        }
    }

    if (const auto* empty = dynamic_cast<const EmptyListNode*>(&expr)) {
        return "std::vector<" + typeFromName(empty->elementTypeName).toCpp() + ">";
    }

    if (const auto* list = dynamic_cast<const ListLiteralNode*>(&expr)) {
        if (!list->elements.empty()) {
            return "std::vector<" + inferExpressionType(*list->elements[0]) + ">";
        }
    }

    if (dynamic_cast<const NothingLiteralNode*>(&expr)) {
        return "std::nullopt";
    }

    if (const auto* enumCase = dynamic_cast<const EnumCaseExprNode*>(&expr)) {
        return enumCase->enumName;
    }

    if (dynamic_cast<const IsDefinedCheckNode*>(&expr)) return "bool";

    if (const auto* id = dynamic_cast<const IdentifierNode*>(&expr)) {
        return resolveVariableType(id->name);
    }

    if (const auto* bin = dynamic_cast<const BinaryOpNode*>(&expr)) {
        if (bin->op == "+") {
            if (dynamic_cast<const StringLiteralNode*>(bin->left.get()) ||
                dynamic_cast<const StringLiteralNode*>(bin->right.get())) {
                return "std::string";
            }
        }
        if (bin->op == ">" || bin->op == "<" || bin->op == "==" || bin->op == "!=" ||
            bin->op == "&&" || bin->op == "||") {
            return "bool";
        }
        return "double";
    }

    if (dynamic_cast<const LengthExpressionNode*>(&expr)) return "double";

    return "auto";
}

std::string CodeGenerator::resolveVariableType(const std::string& name) const {
    auto it = semantic_.globalVariables.find(name);
    if (it != semantic_.globalVariables.end()) {
        return it->second.toCpp();
    }
    return "auto";
}

AfrType CodeGenerator::inferExpressionAfrType(const ExpressionNode& expr) const {
    if (const auto* id = dynamic_cast<const IdentifierNode*>(&expr)) {
        auto it = semantic_.globalVariables.find(id->name);
        if (it != semantic_.globalVariables.end()) return it->second;
    }
    if (const auto* emptyMap = dynamic_cast<const EmptyMapNode*>(&expr)) {
        return AfrType::mapType(typeFromName(emptyMap->keyTypeName),
                                typeFromName(emptyMap->valueTypeName));
    }
    if (const auto* empty = dynamic_cast<const EmptyListNode*>(&expr)) {
        return AfrType::listType(typeFromName(empty->elementTypeName));
    }
    if (const auto* mapLit = dynamic_cast<const MapLiteralNode*>(&expr)) {
        if (!mapLit->pairs.empty()) {
            return AfrType::mapType(AfrType::text(), AfrType::number());
        }
    }
    return AfrType::voidType();
}

void CodeGenerator::indent(std::ostream& out, int level) {
    for (int i = 0; i < level; ++i) {
        out << "    ";
    }
}

void CodeGenerator::emitLineDirective(std::ostream& out, const ASTNode& node,
                                      int indentLevel) const {
    if (!debugSymbols_ || sourceFilePath_.empty() || node.loc.line <= 0) return;
    indent(out, indentLevel);
    out << "#line " << node.loc.line << " \"" << sourceFilePath_ << "\"\n";
}

std::string CodeGenerator::escapeString(const std::string& s) {
    std::string result;
    result.reserve(s.size());
    for (char c : s) {
        switch (c) {
            case '"':  result += "\\\""; break;
            case '\\': result += "\\\\"; break;
            case '\n': result += "\\n";  break;
            case '\t': result += "\\t";  break;
            default:   result += c;        break;
        }
    }
    return result;
}

bool CodeGenerator::usesStdlibModule(const std::string& name) const {
    return name == "io" || name == "json" || name == "fs" || name == "http" ||
           name == "str" || name == "logging" || name == "math" || name == "chrono" ||
           name == "re" || name == "collections";
}

namespace {

std::string runtimeModuleName(const std::string& moduleName) {
    if (moduleName == "logging") return "log";
    if (moduleName == "chrono") return "time";
    return moduleName;
}

} // namespace

void CodeGenerator::emitStdlibFunction(std::ostream& out, const std::string& moduleName,
                                       const FunctionNode& func, int indentLevel) const {
    const std::string returnCpp = func.returnTypeName.empty()
        ? "void"
        : typeFromName(func.returnTypeName).toCpp();

    indent(out, indentLevel);
    out << returnCpp << " " << func.name << "(" << paramList(func) << ") {\n";
    indent(out, indentLevel + 1);

    const std::string rt = "afrilang::runtime::" + runtimeModuleName(moduleName) +
                           "::" + func.name;

    if (func.name == "writeFile") {
        out << rt << "(path, content);\n";
    } else if (moduleName == "json" && func.name == "stringify") {
        out << "return afrilang::runtime::json::normalize(value);\n";
    } else if (func.returnTypeName.empty()) {
        out << rt << "(";
        for (std::size_t i = 0; i < func.parameters.size(); ++i) {
            if (i > 0) out << ", ";
            out << func.parameters[i].name;
        }
        out << ");\n";
    } else {
        out << "return " << rt << "(";
        for (std::size_t i = 0; i < func.parameters.size(); ++i) {
            if (i > 0) out << ", ";
            out << func.parameters[i].name;
        }
        out << ");\n";
    }

    indent(out, indentLevel);
    out << "}\n";
}

std::string CodeGenerator::functionReturnCpp(const FunctionNode& func) {
    if (func.returnTypeName.empty()) return "void";
    if (func.returnsResult) return resultTypeAlias(func.returnTypeName);
    return cppTypeFromAfrName(func.returnTypeName, func.typeParams);
}

std::string CodeGenerator::resultTypeAlias(const std::string& innerTypeName) {
    return "afrilang::runtime::AfrResult_" + innerTypeName;
}

std::string CodeGenerator::sanitizeTestName(const std::string& name) {
    std::string out;
    for (char c : name) {
        if (std::isalnum(static_cast<unsigned char>(c))) out += c;
        else if (c == ' ' || c == '-') out += '_';
    }
    return out.empty() ? "unnamed" : out;
}

bool CodeGenerator::compileToExecutable(const std::string& outputPath,
                                        const std::string& executablePath) const {
    {
        std::ofstream file(outputPath);
        if (!file) return false;
        generate(file);
    }

    std::string command =
        compilerForTarget(crossTarget_) + " -std=c++17 -O2 -Wall -Wextra";
    if (debugSymbols_) {
        command += " -g";
    }
    if (crossTarget_ == "wasm32") {
        command += " -s WASM=1";
    }
    command += " -o \"" + executablePath + "\" \"" + outputPath + "\"";

    if (!runtimeDir_.empty()) {
        command += " -I\"" + runtimeDir_ + "\"";
    }

    for (const auto& lib : linkLibraries_) {
        command += " " + lib;
    }

    command += " 2>&1";

    const int result = std::system(command.c_str());
    return result == 0;
}

} // namespace afrilang
