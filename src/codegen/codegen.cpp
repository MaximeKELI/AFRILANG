#include "afrilang/codegen.hpp"

#include "afrilang/educational.hpp"
#include "afrilang/sandbox.hpp"
#include "afrilang/security.hpp"
#include "afrilang/stdlib_catalog.hpp"
#include "afrilang/medium_catalog.hpp"
#include "afrilang/complex_catalog.hpp"

#include <cstdlib>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
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
        return typeFromName(typeName).toCpp();
    }
    if (!typeName.empty() && typeName.back() == '?') {
        const std::string inner = typeName.substr(0, typeName.size() - 1);
        if (isParam(inner)) return "std::optional<" + inner + ">";
    }
    return typeFromName(typeName).toCpp();
}

std::vector<std::string> effectiveTypeParams(const FunctionNode& func,
                                             const ClassInfo* ownerClass) {
    if (!func.typeParams.empty()) return func.typeParams;
    if (ownerClass && !ownerClass->typeParams.empty()) return ownerClass->typeParams;
    return {};
}

std::string capitalizeName(const std::string& name) {
    if (name.empty()) return name;
    std::string out = name;
    out[0] = static_cast<char>(std::toupper(static_cast<unsigned char>(out[0])));
    return out;
}

const MethodSignature* findClassOperator(const SemanticResult& semantic,
                                         const std::string& className,
                                         const std::string& opSymbol) {
    const ClassInfo* cls = nullptr;
    auto it = semantic.classes.find(className);
    if (it != semantic.classes.end()) cls = &it->second;
    while (cls) {
        auto oit = cls->operators.find(opSymbol);
        if (oit != cls->operators.end()) return &oit->second;
        if (cls->baseClass.empty()) break;
        auto bit = semantic.classes.find(cls->baseClass);
        if (bit == semantic.classes.end()) break;
        cls = &bit->second;
    }
    return nullptr;
}

AfrType expressionOperandType(const ExpressionNode& expr, const SemanticResult& semantic) {
    if (const auto* id = dynamic_cast<const IdentifierNode*>(&expr)) {
        auto vit = semantic.globalVariables.find(id->name);
        if (vit != semantic.globalVariables.end()) return vit->second;
    }
    if (const auto* newExpr = dynamic_cast<const NewExpressionNode*>(&expr)) {
        return AfrType::classType(newExpr->className);
    }
    return AfrType::voidType();
}

bool assignValueIsNewExpression(const ExpressionNode& value) {
    if (dynamic_cast<const NewExpressionNode*>(&value)) return true;
    if (const auto* call = dynamic_cast<const CallExpressionNode*>(&value)) {
        return dynamic_cast<const NewExpressionNode*>(call->callee.get()) != nullptr;
    }
    return false;
}

std::string cppGenericArg(const std::string& afr) {
    if (afr == "number") return "double";
    if (afr == "int") return "std::int64_t";
    if (afr == "bigint") return "afrilang::runtime::bigint::BigInt";
    if (afr == "json") return "afrilang::runtime::json::Value";
    if (afr == "text") return "std::string";
    if (afr == "bool") return "bool";
    return afr;
}

std::string joinGenericArgs(const std::vector<std::string>& args) {
    std::ostringstream joined;
    for (std::size_t i = 0; i < args.size(); ++i) {
        if (i > 0) joined << ", ";
        joined << cppGenericArg(args[i]);
    }
    return joined.str();
}

std::string cppTypeFromAfrType(const AfrType& type) {
    switch (type.kind) {
        case TypeKind::Number: return "double";
        case TypeKind::Int: return "std::int64_t";
        case TypeKind::BigInt: return "afrilang::runtime::bigint::BigInt";
        case TypeKind::Json: return "afrilang::runtime::json::Value";
        case TypeKind::Text: return "std::string";
        case TypeKind::Bool: return "bool";
        case TypeKind::Void: return "void";
        default: return "auto";
    }
}

std::string propertyBackingField(const std::string& name) {
    return "_" + name;
}

std::string propertyGetterName(const std::string& name) {
    return "get" + capitalizeName(name);
}

std::string propertySetterName(const std::string& name) {
    return "set" + capitalizeName(name);
}

bool classHasProperty(const SemanticResult& semantic, const std::string& className,
                      const std::string& propName) {
    const auto clsIt = semantic.classes.find(className);
    if (clsIt == semantic.classes.end()) return false;
    const ClassInfo& cls = clsIt->second;
    if (cls.properties.count(propName)) return true;
    if (!cls.baseClass.empty()) {
        return classHasProperty(semantic, cls.baseClass, propName);
    }
    return false;
}

std::string mangleGlobalFunctionName(const std::string& name) {
    return "afr_" + name;
}

AfrType resolveCodegenDeclType(const std::string& name, const SemanticResult& semantic) {
    if (semantic.interfaces.count(name)) return AfrType::interfaceType(name);
    if (semantic.enums.count(name)) return AfrType::enumType(name);
    if (semantic.records.count(name)) return AfrType::recordType(name);
    return typeFromName(name);
}

std::string storageCppForType(const AfrType& type) {
    if (type.kind == TypeKind::Class || type.kind == TypeKind::Interface) {
        return "std::unique_ptr<" + type.className + ">";
    }
    return type.toCpp();
}

std::string instantiatedClassStorageCpp(const NewExpressionNode& newExpr) {
    if (newExpr.typeArgs.empty()) {
        return "std::unique_ptr<" + newExpr.className + ">";
    }
    return "std::unique_ptr<" + newExpr.className + "<" +
           joinGenericArgs(newExpr.typeArgs) + ">>";
}

bool expressionUsesNaturalListOps(const ExpressionNode& expr) {
    if (dynamic_cast<const MapEachExpressionNode*>(&expr)) return true;
    if (dynamic_cast<const FlatMapEachExpressionNode*>(&expr)) return true;
    if (dynamic_cast<const FilterEachExpressionNode*>(&expr)) return true;
    if (dynamic_cast<const ComprehensionExpressionNode*>(&expr)) return true;
    if (dynamic_cast<const ReduceExpressionNode*>(&expr)) return true;

    if (const auto* bin = dynamic_cast<const BinaryOpNode*>(&expr)) {
        return expressionUsesNaturalListOps(*bin->left) ||
               expressionUsesNaturalListOps(*bin->right);
    }
    if (const auto* unary = dynamic_cast<const UnaryOpNode*>(&expr)) {
        return expressionUsesNaturalListOps(*unary->operand);
    }
    if (const auto* call = dynamic_cast<const CallExpressionNode*>(&expr)) {
        if (expressionUsesNaturalListOps(*call->callee)) return true;
        for (const auto& arg : call->arguments) {
            if (expressionUsesNaturalListOps(*arg)) return true;
        }
    }
    if (const auto* member = dynamic_cast<const MemberAccessNode*>(&expr)) {
        return expressionUsesNaturalListOps(*member->object);
    }
    if (const auto* index = dynamic_cast<const IndexExpressionNode*>(&expr)) {
        return expressionUsesNaturalListOps(*index->object) ||
               expressionUsesNaturalListOps(*index->index);
    }
    if (const auto* length = dynamic_cast<const LengthExpressionNode*>(&expr)) {
        return expressionUsesNaturalListOps(*length->object);
    }
    if (const auto* list = dynamic_cast<const ListLiteralNode*>(&expr)) {
        for (const auto& elem : list->elements) {
            if (expressionUsesNaturalListOps(*elem)) return true;
        }
    }
    if (const auto* mapLit = dynamic_cast<const MapLiteralNode*>(&expr)) {
        for (const auto& pair : mapLit->pairs) {
            if (expressionUsesNaturalListOps(*pair.key) ||
                expressionUsesNaturalListOps(*pair.value)) {
                return true;
            }
        }
    }
    if (const auto* interp = dynamic_cast<const InterpolatedStringNode*>(&expr)) {
        for (const auto& part : interp->parts) {
            if (expressionUsesNaturalListOps(*part)) return true;
        }
    }
    if (const auto* lambda = dynamic_cast<const LambdaExpressionNode*>(&expr)) {
        for (const auto& stmt : lambda->body) {
            if (const auto* say = dynamic_cast<const SayStatementNode*>(stmt.get())) {
                if (expressionUsesNaturalListOps(*say->value)) return true;
            } else if (const auto* ret = dynamic_cast<const ReturnStatementNode*>(stmt.get())) {
                if (ret->value && expressionUsesNaturalListOps(*ret->value)) return true;
            }
        }
    }
    return false;
}

bool statementUsesNaturalListOps(const StatementNode& stmt) {
    if (const auto* assign = dynamic_cast<const AssignStatementNode*>(&stmt)) {
        return expressionUsesNaturalListOps(*assign->value);
    }
    if (const auto* say = dynamic_cast<const SayStatementNode*>(&stmt)) {
        return expressionUsesNaturalListOps(*say->value);
    }
    if (const auto* set = dynamic_cast<const SetStatementNode*>(&stmt)) {
        return expressionUsesNaturalListOps(*set->target) ||
               expressionUsesNaturalListOps(*set->value);
    }
    if (const auto* ret = dynamic_cast<const ReturnStatementNode*>(&stmt)) {
        return ret->value && expressionUsesNaturalListOps(*ret->value);
    }
    if (const auto* exprStmt = dynamic_cast<const ExpressionStatementNode*>(&stmt)) {
        return expressionUsesNaturalListOps(*exprStmt->expression);
    }
    if (const auto* ifStmt = dynamic_cast<const IfStatementNode*>(&stmt)) {
        if (expressionUsesNaturalListOps(*ifStmt->condition)) return true;
        for (const auto& s : ifStmt->thenBody) {
            if (statementUsesNaturalListOps(*s)) return true;
        }
        for (const auto& s : ifStmt->elseBody) {
            if (statementUsesNaturalListOps(*s)) return true;
        }
    }
    if (const auto* whileStmt = dynamic_cast<const WhileStatementNode*>(&stmt)) {
        if (expressionUsesNaturalListOps(*whileStmt->condition)) return true;
        for (const auto& s : whileStmt->body) {
            if (statementUsesNaturalListOps(*s)) return true;
        }
    }
    if (const auto* forEach = dynamic_cast<const ForEachStatementNode*>(&stmt)) {
        if (expressionUsesNaturalListOps(*forEach->list)) return true;
        for (const auto& s : forEach->body) {
            if (statementUsesNaturalListOps(*s)) return true;
        }
    }
    return false;
}

bool programUsesNaturalListOps(const ProgramNode& program) {
    for (const auto& stmt : program.statements) {
        if (statementUsesNaturalListOps(*stmt)) return true;
    }
    for (const auto& func : program.functions) {
        for (const auto& stmt : func->body) {
            if (statementUsesNaturalListOps(*stmt)) return true;
        }
    }
    for (const auto& test : program.tests) {
        for (const auto& stmt : test->body) {
            if (statementUsesNaturalListOps(*stmt)) return true;
        }
    }
    for (const auto& cls : program.classes) {
        for (const auto& method : cls->methods) {
            for (const auto& stmt : method->body) {
                if (statementUsesNaturalListOps(*stmt)) return true;
            }
        }
    }
    for (const auto& mod : program.modules) {
        for (const auto& func : mod->functions) {
            for (const auto& stmt : func->body) {
                if (statementUsesNaturalListOps(*stmt)) return true;
            }
        }
    }
    return false;
}

bool expressionUsesAwait(const ExpressionNode& expr) {
    if (dynamic_cast<const AwaitExpressionNode*>(&expr)) return true;

    if (const auto* bin = dynamic_cast<const BinaryOpNode*>(&expr)) {
        return expressionUsesAwait(*bin->left) || expressionUsesAwait(*bin->right);
    }
    if (const auto* unary = dynamic_cast<const UnaryOpNode*>(&expr)) {
        return expressionUsesAwait(*unary->operand);
    }
    if (const auto* call = dynamic_cast<const CallExpressionNode*>(&expr)) {
        if (expressionUsesAwait(*call->callee)) return true;
        for (const auto& arg : call->arguments) {
            if (expressionUsesAwait(*arg)) return true;
        }
    }
    if (const auto* member = dynamic_cast<const MemberAccessNode*>(&expr)) {
        return expressionUsesAwait(*member->object);
    }
    if (const auto* index = dynamic_cast<const IndexExpressionNode*>(&expr)) {
        return expressionUsesAwait(*index->object) || expressionUsesAwait(*index->index);
    }
    if (const auto* length = dynamic_cast<const LengthExpressionNode*>(&expr)) {
        return expressionUsesAwait(*length->object);
    }
    if (const auto* list = dynamic_cast<const ListLiteralNode*>(&expr)) {
        for (const auto& elem : list->elements) {
            if (expressionUsesAwait(*elem)) return true;
        }
    }
    if (const auto* matchExpr = dynamic_cast<const MatchExpressionNode*>(&expr)) {
        if (expressionUsesAwait(*matchExpr->subject)) return true;
        for (const auto& arm : matchExpr->arms) {
            if (arm.value && expressionUsesAwait(*arm.value)) return true;
        }
    }
    if (const auto* lambda = dynamic_cast<const LambdaExpressionNode*>(&expr)) {
        for (const auto& stmt : lambda->body) {
            if (const auto* say = dynamic_cast<const SayStatementNode*>(stmt.get())) {
                if (expressionUsesAwait(*say->value)) return true;
            } else if (const auto* ret = dynamic_cast<const ReturnStatementNode*>(stmt.get())) {
                if (ret->value && expressionUsesAwait(*ret->value)) return true;
            }
        }
    }
    return false;
}

bool statementUsesAwait(const StatementNode& stmt) {
    if (const auto* assign = dynamic_cast<const AssignStatementNode*>(&stmt)) {
        return expressionUsesAwait(*assign->value);
    }
    if (const auto* say = dynamic_cast<const SayStatementNode*>(&stmt)) {
        return expressionUsesAwait(*say->value);
    }
    if (const auto* ret = dynamic_cast<const ReturnStatementNode*>(&stmt)) {
        return ret->value && expressionUsesAwait(*ret->value);
    }
    if (const auto* exprStmt = dynamic_cast<const ExpressionStatementNode*>(&stmt)) {
        return expressionUsesAwait(*exprStmt->expression);
    }
    if (const auto* ifStmt = dynamic_cast<const IfStatementNode*>(&stmt)) {
        if (expressionUsesAwait(*ifStmt->condition)) return true;
        for (const auto& s : ifStmt->thenBody) {
            if (statementUsesAwait(*s)) return true;
        }
        for (const auto& s : ifStmt->elseBody) {
            if (statementUsesAwait(*s)) return true;
        }
    }
    if (const auto* assertStmt = dynamic_cast<const AssertStatementNode*>(&stmt)) {
        return expressionUsesAwait(*assertStmt->condition);
    }
    return false;
}

bool statementUsesAwaitInBlock(
    const std::vector<std::unique_ptr<StatementNode>>& stmts) {
    for (const auto& stmt : stmts) {
        if (statementUsesAwait(*stmt)) return true;
    }
    return false;
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
    out << "#include <cstdint>\n";
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
    bool needsArgs = false;
    bool needsPath = false;
    bool needsSql = false;
    bool needsWeb = false;
    bool needsOrm = false;
    bool needsThread = false;
    bool needsBigint = false;
    bool needsSimpleLibs = false;
    bool needsMediumLibs = false;
    bool needsComplexLibs = false;
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
        if (module->name == "args") needsArgs = true;
        if (module->name == "path") needsPath = true;
        if (module->name == "sql") needsSql = true;
        if (module->name == "web") needsWeb = true;
        if (module->name == "orm") needsOrm = true;
        if (module->name == "thread") needsThread = true;
        if (module->name == "bigint") needsBigint = true;
        if (stdlibCatalogIsSimpleModule(module->name)) needsSimpleLibs = true;
        if (mediumCatalogIsMediumModule(module->name)) needsMediumLibs = true;
        if (complexCatalogIsComplexModule(module->name)) needsComplexLibs = true;
        if (module->name == "async") { /* async.hpp via usesAsync */ }
    }
    for (const auto& modName : semantic_.usedModules) {
        if (modName == "args") needsArgs = true;
        if (modName == "path") needsPath = true;
    }
    if (programUsesNaturalListOps(program_)) needsCollections = true;
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
    if (needsArgs) out << "#include \"args.hpp\"\n";
    if (needsPath) out << "#include \"path.hpp\"\n";
    if (needsSql) out << "#include \"sql.hpp\"\n";
    if (needsWeb) out << "#include \"web.hpp\"\n";
    if (needsOrm) out << "#include \"orm.hpp\"\n";
    if (needsThread) {
        out << "#include \"thread.hpp\"\n";
        linkLibraries_.insert("-pthread");
    }
    if (needsBigint) out << "#include \"bigint.hpp\"\n";
    if (needsSimpleLibs) out << "#include \"simple_libs.hpp\"\n";
    if (needsMediumLibs) out << "#include \"medium_libs.hpp\"\n";
    if (needsComplexLibs) out << "#include \"complex_libs.hpp\"\n";
    if (semantic_.usesUi) out << "#include \"ui.hpp\"\n";
    if (semantic_.usesAsync) out << "#include \"async.hpp\"\n";
    if (!program_.classes.empty()) out << "#include <memory>\n";
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
    if (needsHttp) {
        linkLibraries_.insert("-lssl");
        linkLibraries_.insert("-lcrypto");
    }
    if (needsOrm || needsSql) {
        linkLibraries_.insert("-lsqlite3");
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
    if (typeName == "int") return "std::int64_t";
    if (typeName == "json") return "const afrilang::runtime::json::Value&";
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
    static const std::unordered_set<std::string> kAllowed = {
        "m", "libm", "c", "libc", "pthread", "dl", "math", "curl"
    };
    if (!kAllowed.count(library)) return {};
    if (library == "c" || library == "libc") return {};
    if (library == "m" || library == "libm" || library == "math") return "-lm";
    if (library == "pthread") return "-lpthread";
    if (library == "dl") return "-ldl";
    if (library == "curl") return "-lcurl";
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
    auto emitOne = [&](const EnumNode& en) {
        const EnumInfo* info = nullptr;
        auto it = semantic_.enums.find(en.name);
        if (it != semantic_.enums.end()) info = &it->second;

        out << "struct " << en.name << " {\n";
        out << "    enum class Tag {";
        for (std::size_t i = 0; i < en.cases.size(); ++i) {
            if (i > 0) out << ',';
            out << " " << en.cases[i].name;
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

        for (const auto& c : en.cases) {
            out << "    static " << en.name << " make_" << c.name << "(";
            if (info && info->cases.count(c.name)) {
                const auto& fields = info->cases.at(c.name).fields;
                for (std::size_t i = 0; i < fields.size(); ++i) {
                    if (i > 0) out << ", ";
                    out << fields[i].second.toCpp() << " " << fields[i].first;
                }
            }
            out << ") {\n";
            out << "        " << en.name << " v;\n";
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
    };

    for (const auto& en : program_.enums) {
        emitOne(*en);
    }
    for (const auto& module : program_.modules) {
        for (const auto& en : module->enums) {
            emitOne(*en);
        }
    }
}

void CodeGenerator::emitClass(std::ostream& out, const ClassNode& cls) const {
    const ClassInfo* classInfo = nullptr;
    auto it = semantic_.classes.find(cls.name);
    if (it != semantic_.classes.end()) classInfo = &it->second;

    if (!cls.typeParams.empty()) {
        out << "template<typename";
        for (std::size_t i = 0; i < cls.typeParams.size(); ++i) {
            if (i == 0) out << " ";
            else out << ", typename ";
            out << cls.typeParams[i];
        }
        out << ">\n";
    }

    out << "class " << cls.name;
    if (cls.isFinal) out << " final";
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
    if (!cls.destroyBody.empty()) {
        out << "    virtual ~" << cls.name << "() {\n";
        for (const auto& stmt : cls.destroyBody) {
            emitStatement(out, *stmt, 2, classInfo);
        }
        out << "    }\n\n";
    } else {
        out << "    virtual ~" << cls.name << "() = default;\n\n";
    }
    for (const auto& field : cls.fields) {
        const std::string fieldCpp = cppTypeFromAfrName(field.typeName, cls.typeParams);
        if (field.isStatic) {
            out << "    inline static " << fieldCpp << " " << field.name;
            if (field.typeName == "number" || field.typeName == "int") out << " = 0";
            else if (field.typeName == "text") out << " = \"\"";
            else if (field.typeName == "bool") out << " = false";
            out << ";\n";
        } else {
            out << "    " << fieldCpp << " " << field.name << ";\n";
        }
    }
    for (const auto& prop : cls.properties) {
        const std::string propCpp = cppTypeFromAfrName(prop.typeName, cls.typeParams);
        out << "    " << propCpp << " " << propertyBackingField(prop.name) << ";\n";
    }
    if (!cls.fields.empty() || !cls.properties.empty()) out << "\n";

    for (const auto& prop : cls.properties) {
        const std::string propCpp = cppTypeFromAfrName(prop.typeName, cls.typeParams);
        out << "    " << propCpp << " " << propertyGetterName(prop.name) << "() const {\n";
        out << "        return " << propertyBackingField(prop.name) << ";\n";
        out << "    }\n";
        out << "    void " << propertySetterName(prop.name) << "(const " << propCpp
            << "& value) {\n";
        out << "        " << propertyBackingField(prop.name) << " = value;\n";
        out << "    }\n\n";
    }

    const FunctionNode* constructor = nullptr;
    for (const auto& method : cls.methods) {
        if (method->name == "init") {
            constructor = method.get();
            break;
        }
    }

    if (constructor) {
        std::string baseInit;
        std::vector<const StatementNode*> ctorBody;
        for (const auto& stmt : constructor->body) {
            bool skip = false;
            if (const auto* exprStmt = dynamic_cast<const ExpressionStatementNode*>(stmt.get())) {
                if (const auto* call =
                        dynamic_cast<const CallExpressionNode*>(exprStmt->expression.get())) {
                    if (dynamic_cast<const SuperExpressionNode*>(call->callee.get()) &&
                        !cls.baseClassName.empty()) {
                        std::ostringstream args;
                        for (std::size_t i = 0; i < call->arguments.size(); ++i) {
                            if (i > 0) args << ", ";
                            std::ostringstream argOut;
                            emitExpression(argOut, *call->arguments[i], classInfo);
                            args << argOut.str();
                        }
                        baseInit = cls.baseClassName + "(" + args.str() + ")";
                        skip = true;
                    }
                }
            }
            if (!skip) ctorBody.push_back(stmt.get());
        }

        out << "    " << cls.name << "(" << paramList(*constructor, classInfo) << ")";
        if (!baseInit.empty()) out << " : " << baseInit;
        out << " {\n";
        for (const auto* stmt : ctorBody) {
            emitStatement(out, *stmt, 2, classInfo);
        }
        out << "    }\n\n";
    }

    for (const auto& method : cls.methods) {
        if (method->name == "init") continue;
        if (method->isAbstract) {
            const std::string ret = functionReturnCpp(*method, classInfo);
            out << "    virtual " << ret << " " << method->name
                << "(" << paramList(*method, classInfo) << ") = 0;\n\n";
        } else {
            emitFunction(out, *method, classInfo, 1);
            out << "\n";
        }
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

std::string CodeGenerator::paramList(const FunctionNode& func, const ClassInfo* ownerClass) {
    const std::vector<std::string> tparams = effectiveTypeParams(func, ownerClass);
    std::ostringstream out;
    for (std::size_t i = 0; i < func.parameters.size(); ++i) {
        if (i > 0) out << ", ";
        const auto& param = func.parameters[i];
        const AfrType paramType = typeFromName(param.typeName);
        if (paramType.kind == TypeKind::Class) {
            out << "const " << paramType.className << "& " << param.name;
        } else {
            out << cppTypeFromAfrName(param.typeName, tparams) << " " << param.name;
        }
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

std::string CodeGenerator::classStorageCpp(const AfrType& type) {
    if (type.kind == TypeKind::Interface || type.kind == TypeKind::Class) {
        return "std::unique_ptr<" + type.className + ">";
    }
    return type.toCpp();
}

std::string CodeGenerator::classStorageCpp(const std::string& className) {
    return "std::unique_ptr<" + className + ">";
}

bool CodeGenerator::usesPointerAccess(const ExpressionNode& object) const {
    if (dynamic_cast<const ThisExpressionNode*>(&object)) return false;
    if (dynamic_cast<const SuperExpressionNode*>(&object)) return false;
    if (const auto* index = dynamic_cast<const IndexExpressionNode*>(&object)) {
        const AfrType containerType = inferExpressionAfrType(*index->object);
        if (containerType.kind == TypeKind::List &&
            (containerType.listElementType().kind == TypeKind::Class ||
             containerType.listElementType().kind == TypeKind::Interface)) {
            return true;
        }
        return usesPointerAccess(*index->object);
    }
    if (const auto* id = dynamic_cast<const IdentifierNode*>(&object)) {
        const auto it = semantic_.globalVariables.find(id->name);
        if (it != semantic_.globalVariables.end() &&
            (it->second.kind == TypeKind::Class || it->second.kind == TypeKind::Interface)) {
            return true;
        }
    }
    if (const auto* member = dynamic_cast<const MemberAccessNode*>(&object)) {
        if (dynamic_cast<const ThisExpressionNode*>(member->object.get())) return false;
        return usesPointerAccess(*member->object);
    }
    return false;
}

void CodeGenerator::emitReceiver(std::ostream& out, const ExpressionNode& object,
                                 const ClassInfo* ownerClass) const {
    emitExpression(out, object, ownerClass);
    if (usesPointerAccess(object)) {
        out << "->";
    } else {
        out << ".";
    }
}

void CodeGenerator::emitCallArgument(std::ostream& out, const ExpressionNode& arg,
                                     const AfrType& paramType,
                                     const ClassInfo* ownerClass) const {
    if (dynamic_cast<const StringLiteralNode*>(&arg) &&
        (paramType.kind == TypeKind::Text || paramType.kind == TypeKind::TypeVar)) {
        out << "std::string(";
        emitExpression(out, arg, ownerClass);
        out << ")";
        return;
    }
    if (paramType.kind == TypeKind::Class || paramType.kind == TypeKind::Interface) {
        if (usesPointerAccess(arg)) {
            out << "*";
        }
    }
    emitExpression(out, arg, ownerClass);
}

void CodeGenerator::emitListElement(std::ostream& out, const ExpressionNode& elem,
                                    const std::string& listElemCpp,
                                    const ClassInfo* ownerClass) const {
    const std::string elemCpp = inferExpressionType(elem);
    if (listElemCpp.rfind("std::unique_ptr<", 0) == 0 &&
        elemCpp.rfind("std::unique_ptr<", 0) == 0 &&
        listElemCpp != elemCpp) {
        out << listElemCpp << "(";
        emitExpression(out, elem, ownerClass);
        out << ")";
        return;
    }
    emitExpression(out, elem, ownerClass);
}

void CodeGenerator::emitFunction(std::ostream& out, const FunctionNode& func,
                                 const ClassInfo* ownerClass, int indentLevel) const {
    const std::vector<std::string> tparams = effectiveTypeParams(func, ownerClass);
    const std::string returnCpp = functionReturnCpp(func, ownerClass);

    if (!func.typeParams.empty() && (!ownerClass || ownerClass->typeParams.empty())) {
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
    if (func.isStatic) {
        out << "static ";
    } else if (ownerClass) {
        out << "virtual ";
    }
    const std::string emittedName = (ownerClass || indentLevel > 0)
        ? func.name
        : mangleGlobalFunctionName(func.name);
    out << returnCpp << " " << emittedName << "(" << paramList(func, ownerClass) << ")";

    if (ownerClass && !func.isStatic) {
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
    if (func.isFinal) out << " final";
    if (func.isOperator && ownerClass && !func.isStatic) out << " const";

    out << " {\n";
    const FunctionNode* saved = currentFunction_;
    currentFunction_ = &func;
    for (const auto& stmt : func.body) {
        emitStatement(out, *stmt, indentLevel + 1, ownerClass);
    }
    currentFunction_ = saved;
    if (func.isAsync && func.returnTypeName.empty()) {
        indent(out, indentLevel + 1);
        out << "co_return;\n";
    }
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
        const bool wrapAsync = statementUsesAwaitInBlock(test->body);

        out << "void " << fn << "() {\n";
        bool savedTest = inTest_;
        inTest_ = true;

        if (wrapAsync) {
            out << "    afrilang::runtime::async::run([]() -> afrilang::runtime::async::Task<void> {\n";
        }

        const bool savedAsync = inAsyncCoroutine_;
        if (wrapAsync) inAsyncCoroutine_ = true;

        const int indentLevel = wrapAsync ? 2 : 1;
        for (const auto& stmt : test->body) {
            emitStatement(out, *stmt, indentLevel, nullptr);
        }

        if (wrapAsync) {
            indent(out, 2);
            out << "co_return;\n";
            indent(out, 1);
            out << "}());\n";
        }

        inAsyncCoroutine_ = savedAsync;
        inTest_ = savedTest;
        out << "}\n\n";
    }
}

void CodeGenerator::emitMain(std::ostream& out) const {
    for (const auto& modName : semantic_.usedModules) {
        out << "using namespace " << modName << ";\n";
    }
    if (!semantic_.usedModules.empty()) out << "\n";

    const bool needsArgs = semantic_.usedModules.count("args") > 0;
    if (needsArgs) {
        out << "int main(int argc, char** argv) {\n";
        out << "    afrilang::runtime::args::init(argc, argv);\n";
    } else {
        out << "int main() {\n";
    }

    const bool wrapMainAsync = semantic_.usesAsync;
    if (wrapMainAsync) {
        out << "    afrilang::runtime::async::run([]() -> afrilang::runtime::async::Task<void> {\n";
    }

    const bool savedAsyncMain = inAsyncCoroutine_;
    if (wrapMainAsync) inAsyncCoroutine_ = true;

    const int mainIndent = wrapMainAsync ? 2 : 1;
    for (const auto& stmt : program_.statements) {
        emitStatement(out, *stmt, mainIndent, nullptr);
    }

    if (wrapMainAsync) {
        indent(out, 2);
        out << "co_return;\n";
        indent(out, 1);
        out << "}());\n";
    }

    inAsyncCoroutine_ = savedAsyncMain;

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

        if (const auto* lambda = dynamic_cast<const LambdaExpressionNode*>(assign->value.get())) {
            std::string typeCpp;
            if (!assign->typeName.empty()) {
                typeCpp = typeFromName(assign->typeName).toCpp();
            } else {
                std::ostringstream params;
                for (std::size_t i = 0; i < lambda->parameters.size(); ++i) {
                    if (i > 0) params << ", ";
                    params << lambda->parameters[i].typeName;
                }
                typeCpp = AfrType::functionType(params.str(), lambda->returnTypeName).toCpp();
            }
            out << constPrefix << typeCpp << " " << assign->name << " = ";
            emitExpression(out, *assign->value, ownerClass);
            out << ";\n";
            return;
        }

        if (const auto* newExpr = dynamic_cast<const NewExpressionNode*>(assign->value.get())) {
            const std::string storage = !assign->typeName.empty()
                ? storageCppForType(resolveCodegenDeclType(assign->typeName, semantic_))
                : instantiatedClassStorageCpp(*newExpr);
            out << constPrefix << storage << " " << assign->name << " = ";
            emitExpression(out, *assign->value, ownerClass);
            out << ";\n";
            return;
        }

        if (const auto* newCall = dynamic_cast<const CallExpressionNode*>(assign->value.get())) {
            if (const auto* newExpr =
                    dynamic_cast<const NewExpressionNode*>(newCall->callee.get())) {
                const std::string storage = !assign->typeName.empty()
                    ? storageCppForType(resolveCodegenDeclType(assign->typeName, semantic_))
                    : instantiatedClassStorageCpp(*newExpr);
                out << constPrefix << storage << " " << assign->name << " = ";
                emitExpression(out, *assign->value, ownerClass);
                out << ";\n";
                return;
            }
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
                if (t.kind == TypeKind::List) elemCpp = t.listElementCpp();
            }
            if (elemCpp.empty() && !list->elementTypeName.empty()) {
                elemCpp = typeFromName(list->elementTypeName).toCpp();
            }
            if (elemCpp.empty() && !list->elements.empty()) {
                elemCpp = inferExpressionType(*list->elements[0]);
            }
            const bool usePushBack = elemCpp.rfind("std::unique_ptr<", 0) == 0;
            out << constPrefix << "std::vector<" << elemCpp << "> " << assign->name;
            if (usePushBack) {
                out << ";\n";
                for (const auto& element : list->elements) {
                    indent(out, indentLevel);
                    out << assign->name << ".push_back(";
                    emitListElement(out, *element, elemCpp, ownerClass);
                    out << ");\n";
                }
            } else {
                out << " = {";
                for (std::size_t i = 0; i < list->elements.size(); ++i) {
                    if (i > 0) out << ", ";
                    emitListElement(out, *list->elements[i], elemCpp, ownerClass);
                }
                out << "};\n";
            }
            return;
        }

        std::string typeCpp;
        AfrType resolvedType = AfrType::voidType();
        if (!assign->typeName.empty()) {
            const AfrType declared = resolveCodegenDeclType(assign->typeName, semantic_);
            resolvedType = declared;
            typeCpp = (declared.kind == TypeKind::Class || declared.kind == TypeKind::Interface)
                ? classStorageCpp(declared)
                : declared.toCpp();
        } else {
            const auto vit = semantic_.globalVariables.find(assign->name);
            if (vit != semantic_.globalVariables.end()) {
                resolvedType = vit->second;
                typeCpp = (vit->second.kind == TypeKind::Class ||
                           vit->second.kind == TypeKind::Interface)
                    ? classStorageCpp(vit->second)
                    : vit->second.toCpp();
            } else {
                typeCpp = inferExpressionType(*assign->value);
            }
        }
        const bool wrapUnique =
            typeCpp.rfind("std::unique_ptr<", 0) == 0 &&
            !assignValueIsNewExpression(*assign->value) &&
            (resolvedType.kind == TypeKind::Class ||
             resolvedType.kind == TypeKind::Interface);
        out << constPrefix << typeCpp << " " << assign->name << " = ";
        if (wrapUnique) {
            out << "std::make_unique<" << resolvedType.className << ">(";
        }
        emitExpression(out, *assign->value, ownerClass);
        if (wrapUnique) out << ")";
        out << ";\n";
        return;
    }

    if (const auto* set = dynamic_cast<const SetStatementNode*>(&stmt)) {
        if (const auto* member = dynamic_cast<const MemberAccessNode*>(set->target.get())) {
            std::string className;
            if (dynamic_cast<const ThisExpressionNode*>(member->object.get()) && ownerClass) {
                className = ownerClass->name;
            } else {
                const AfrType objectType = inferExpressionAfrType(*member->object);
                if (objectType.kind == TypeKind::Class) {
                    className = objectType.className;
                }
            }
            if (!className.empty() &&
                classHasProperty(semantic_, className, member->member)) {
                if (dynamic_cast<const ThisExpressionNode*>(member->object.get())) {
                    out << propertySetterName(member->member) << "(";
                } else {
                    emitReceiver(out, *member->object, ownerClass);
                    out << propertySetterName(member->member) << "(";
                }
                emitExpression(out, *set->value, ownerClass);
                out << ");\n";
                return;
            }
        }
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
        const AfrType listType = inferExpressionAfrType(*addTo->list);
        const std::string listElemCpp = listType.kind == TypeKind::List
            ? listType.listElementCpp() : "";
        emitExpression(out, *addTo->list, ownerClass);
        out << ".push_back(";
        if (listType.kind == TypeKind::List &&
            (listType.listElementType().kind == TypeKind::Class ||
             listType.listElementType().kind == TypeKind::Interface) &&
            dynamic_cast<const IdentifierNode*>(addTo->value.get())) {
            out << "std::move(";
            emitExpression(out, *addTo->value, ownerClass);
            out << ")";
        } else if (!listElemCpp.empty()) {
            emitListElement(out, *addTo->value, listElemCpp, ownerClass);
        } else {
            emitExpression(out, *addTo->value, ownerClass);
        }
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

    if (const auto* openWin = dynamic_cast<const OpenWindowStatementNode*>(&stmt)) {
        out << "afrilang::runtime::ui::openWindow(";
        emitExpression(out, *openWin->title, ownerClass);
        out << ", ";
        emitExpression(out, *openWin->width, ownerClass);
        out << ", ";
        emitExpression(out, *openWin->height, ownerClass);
        out << ");\n";
        return;
    }

    if (dynamic_cast<const CloseWindowStatementNode*>(&stmt)) {
        out << "afrilang::runtime::ui::closeWindow();\n";
        return;
    }

    if (dynamic_cast<const ShowFrameStatementNode*>(&stmt)) {
        out << "afrilang::runtime::ui::showFrame();\n";
        return;
    }

    if (const auto* clearBg = dynamic_cast<const ClearBackgroundStatementNode*>(&stmt)) {
        out << "afrilang::runtime::ui::clearBackground(";
        emitExpression(out, *clearBg->red, ownerClass);
        out << ", ";
        emitExpression(out, *clearBg->green, ownerClass);
        out << ", ";
        emitExpression(out, *clearBg->blue, ownerClass);
        out << ");\n";
        return;
    }

    if (const auto* drawText = dynamic_cast<const DrawTextStatementNode*>(&stmt)) {
        out << "afrilang::runtime::ui::drawText(";
        emitExpression(out, *drawText->text, ownerClass);
        out << ", ";
        emitExpression(out, *drawText->x, ownerClass);
        out << ", ";
        emitExpression(out, *drawText->y, ownerClass);
        out << ", ";
        emitExpression(out, *drawText->fontSize, ownerClass);
        out << ");\n";
        return;
    }

    if (const auto* ret = dynamic_cast<const ReturnStatementNode*>(&stmt)) {
        const bool useCoReturn =
            inAsyncCoroutine_ || (currentFunction_ && currentFunction_->isAsync);
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
            out << (useCoReturn ? "co_return" : "return") << " _result;\n";
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
            out << (useCoReturn ? "co_return" : "return") << " _result;\n";
            return;
        }
        if (useCoReturn) {
            out << "co_return ";
            emitExpression(out, *ret->value, ownerClass);
            out << ";\n";
            return;
        }
        const bool returningClassValue =
            currentFunction_ && !currentFunction_->returnTypeName.empty() &&
            typeFromName(currentFunction_->returnTypeName).kind == TypeKind::Class &&
            assignValueIsNewExpression(*ret->value);
        out << "return ";
        if (returningClassValue) out << "*";
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
            out << (inAsyncCoroutine_ ? "co_return" : "return") << ";\n";
        } else {
            out << "std::exit(1);\n";
        }
        indent(out, indentLevel);
        out << "}\n";
        return;
    }

    if (const auto* matchStmt = dynamic_cast<const MatchStatementNode*>(&stmt)) {
        AfrType subjectType = inferExpressionAfrType(*matchStmt->subject);
        if (subjectType.kind == TypeKind::Text || subjectType.kind == TypeKind::Number) {
            indent(out, indentLevel);
            out << "{\n";
            indent(out, indentLevel + 1);
            out << "auto _afr_match = ";
            emitExpression(out, *matchStmt->subject, ownerClass);
            out << ";\n";
            for (std::size_t i = 0; i < matchStmt->arms.size(); ++i) {
                const auto& arm = matchStmt->arms[i];
                indent(out, indentLevel + 1);
                if (arm.isDefault) {
                    out << "else {\n";
                } else if (i == 0) {
                    out << "if (";
                } else {
                    out << "else if (";
                }
                if (!arm.isDefault) {
                    out << "_afr_match == ";
                    if (subjectType.kind == TypeKind::Text) {
                        out << "\"" << arm.caseName << "\"";
                    } else {
                        out << arm.caseName;
                    }
                    out << ") {\n";
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
            if (!arm.isDefault && !arm.bindNames.empty()) {
                const auto enumIt = semantic_.enums.find(enumName);
                if (enumIt != semantic_.enums.end()) {
                    const auto caseIt = enumIt->second.cases.find(arm.caseName);
                    if (caseIt != enumIt->second.cases.end()) {
                        for (std::size_t bi = 0;
                             bi < arm.bindNames.size() && bi < caseIt->second.fields.size();
                             ++bi) {
                            indent(out, indentLevel + 2);
                            out << cppTypeFromAfrType(caseIt->second.fields[bi].second) << " "
                                << arm.bindNames[bi] << " = _afr_match."
                                << caseIt->second.fields[bi].first << ";\n";
                        }
                    }
                }
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
        if (dynamic_cast<const WindowIsOpenExpressionNode*>(whileStmt->condition.get())) {
            indent(out, indentLevel + 1);
            out << "afrilang::runtime::ui::beginFrame();\n";
        }
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
        } else if (containerType.kind == TypeKind::List &&
                   (containerType.listElementType().kind == TypeKind::Class ||
                    containerType.listElementType().kind == TypeKind::Interface)) {
            out << "for (auto& _afr_ptr : ";
            emitExpression(out, *forEach->list, ownerClass);
            out << ") {\n";
            indent(out, indentLevel + 1);
            out << "auto& " << forEach->itemName << " = *_afr_ptr;\n";
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
        if (num->isInteger) {
            out << static_cast<long long>(num->value) << "LL";
        } else if (num->value == static_cast<int>(num->value)) {
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

        const AfrType leftType = expressionOperandType(*bin->left, semantic_);
        if (leftType.kind == TypeKind::Class) {
            if (const MethodSignature* opSig =
                    findClassOperator(semantic_, leftType.className, bin->op)) {
                out << "(";
                emitReceiver(out, *bin->left, ownerClass);
                out << "operator" << bin->op << "(";
                if (!opSig->paramTypes.empty()) {
                    emitCallArgument(out, *bin->right, opSig->paramTypes[0], ownerClass);
                } else {
                    emitExpression(out, *bin->right, ownerClass);
                }
                out << "))";
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

    if (dynamic_cast<const WindowIsOpenExpressionNode*>(&expr)) {
        out << "afrilang::runtime::ui::isOpen()";
        return;
    }

    if (const auto* button = dynamic_cast<const ButtonClickedExpressionNode*>(&expr)) {
        out << "afrilang::runtime::ui::drawButton(";
        emitExpression(out, *button->label, ownerClass);
        out << ", ";
        emitExpression(out, *button->x, ownerClass);
        out << ", ";
        emitExpression(out, *button->y, ownerClass);
        out << ", ";
        emitExpression(out, *button->width, ownerClass);
        out << ", ";
        emitExpression(out, *button->height, ownerClass);
        out << ")";
        return;
    }

    if (const auto* awaitExpr = dynamic_cast<const AwaitExpressionNode*>(&expr)) {
        out << "co_await ";
        emitExpression(out, *awaitExpr->value, ownerClass);
        return;
    }

    if (const auto* unary = dynamic_cast<const UnaryOpNode*>(&expr)) {
        out << unary->op;
        emitExpression(out, *unary->operand, ownerClass);
        return;
    }

    if (const auto* list = dynamic_cast<const ListLiteralNode*>(&expr)) {
        std::string elemCpp;
        if (!list->elementTypeName.empty()) {
            elemCpp = typeFromName(list->elementTypeName).toCpp();
        } else if (!list->elements.empty()) {
            elemCpp = inferExpressionType(*list->elements[0]);
        } else {
            elemCpp = "double";
        }
        out << "std::vector<" << elemCpp << ">{";
        for (std::size_t i = 0; i < list->elements.size(); ++i) {
            if (i > 0) out << ", ";
            emitListElement(out, *list->elements[i], elemCpp, ownerClass);
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

    if (const auto* slice = dynamic_cast<const SliceExpressionNode*>(&expr)) {
        const AfrType listType = inferExpressionAfrType(*slice->object);
        const AfrType elemType = listType.listElementType();
        out << "([&]() { const auto& _afr_lst = ";
        emitExpression(out, *slice->object, ownerClass);
        out << "; const std::size_t _afr_s = static_cast<std::size_t>(";
        emitExpression(out, *slice->start, ownerClass);
        out << "); const std::size_t _afr_e = static_cast<std::size_t>(";
        emitExpression(out, *slice->end, ownerClass);
        out << "); return std::vector<" << elemType.toCpp()
            << ">(_afr_lst.begin() + _afr_s, _afr_lst.begin() + _afr_e); })()";
        return;
    }

    if (const auto* length = dynamic_cast<const LengthExpressionNode*>(&expr)) {
        emitExpression(out, *length->object, ownerClass);
        out << ".size()";
        return;
    }

    if (const auto* lambda = dynamic_cast<const LambdaExpressionNode*>(&expr)) {
        out << "[&](";
        for (std::size_t i = 0; i < lambda->parameters.size(); ++i) {
            if (i > 0) out << ", ";
            out << typeFromName(lambda->parameters[i].typeName).toCpp()
                << " " << lambda->parameters[i].name;
        }
        out << ")";
        if (!lambda->returnTypeName.empty()) {
            out << " -> " << typeFromName(lambda->returnTypeName).toCpp();
        }
        out << " {\n";
        for (const auto& bodyStmt : lambda->body) {
            emitStatement(out, *bodyStmt, 1, ownerClass);
        }
        out << "    }";
        return;
    }

    if (const auto* mapEach = dynamic_cast<const MapEachExpressionNode*>(&expr)) {
        const std::string fn = mapEach->elementTypeName == "text" ? "mapText" : "mapNumbers";
        const AfrType elemType = typeFromName(mapEach->elementTypeName);
        const AfrType resultType = typeFromName(mapEach->resultElementTypeName);
        out << "afrilang::runtime::collections::" << fn << "(";
        emitExpression(out, *mapEach->list, ownerClass);
        out << ", [&](" << elemType.toCpp() << " " << mapEach->itemName << ") -> "
            << resultType.toCpp() << " {\n";
        for (const auto& bodyStmt : mapEach->body) {
            emitStatement(out, *bodyStmt, 1, ownerClass);
        }
        out << "    })";
        return;
    }

    if (const auto* flatMapEach = dynamic_cast<const FlatMapEachExpressionNode*>(&expr)) {
        const std::string fn =
            flatMapEach->elementTypeName == "text" ? "flatMapText" : "flatMapNumbers";
        const AfrType elemType = typeFromName(flatMapEach->elementTypeName);
        const AfrType resultType = typeFromName(flatMapEach->resultElementTypeName);
        out << "afrilang::runtime::collections::" << fn << "(";
        emitExpression(out, *flatMapEach->list, ownerClass);
        out << ", [&](" << elemType.toCpp() << " " << flatMapEach->itemName << ") -> "
            << "std::vector<" << resultType.toCpp() << "> {\n";
        for (const auto& bodyStmt : flatMapEach->body) {
            emitStatement(out, *bodyStmt, 1, ownerClass);
        }
        out << "    })";
        return;
    }

    if (const auto* filterEach = dynamic_cast<const FilterEachExpressionNode*>(&expr)) {
        const std::string fn =
            filterEach->elementTypeName == "text" ? "filterText" : "filterNumbers";
        const AfrType elemType = typeFromName(filterEach->elementTypeName);
        out << "afrilang::runtime::collections::" << fn << "(";
        emitExpression(out, *filterEach->list, ownerClass);
        out << ", [&](" << elemType.toCpp() << " " << filterEach->itemName << ") -> bool {\n";
        out << "        return ";
        emitExpression(out, *filterEach->condition, ownerClass);
        out << ";\n    })";
        return;
    }

    if (const auto* reduce = dynamic_cast<const ReduceExpressionNode*>(&expr)) {
        const AfrType elemType = typeFromName(reduce->elementTypeName);
        const AfrType resultType = typeFromName(reduce->resultTypeName);
        const std::string fn = reduce->elementTypeName == "text" ? "reduceText" : "reduceNumbers";
        out << "afrilang::runtime::collections::" << fn << "(";
        emitExpression(out, *reduce->list, ownerClass);
        out << ", [&](" << resultType.toCpp() << " " << reduce->accName << ", "
            << elemType.toCpp() << " " << reduce->itemName << ") -> "
            << resultType.toCpp() << " {\n";
        for (const auto& bodyStmt : reduce->body) {
            emitStatement(out, *bodyStmt, 1, ownerClass);
        }
        out << "    }, ";
        emitExpression(out, *reduce->initial, ownerClass);
        out << ")";
        return;
    }

    if (const auto* matchExpr = dynamic_cast<const MatchExpressionNode*>(&expr)) {
        AfrType subjectType = inferExpressionAfrType(*matchExpr->subject);
        if (subjectType.kind == TypeKind::Text || subjectType.kind == TypeKind::Number) {
            const std::string resultCpp = matchExpr->resultTypeName.empty()
                ? "auto"
                : typeFromName(matchExpr->resultTypeName).toCpp();
            out << "([&]() -> " << resultCpp << " {\n";
            out << "    auto _afr_match = ";
            emitExpression(out, *matchExpr->subject, ownerClass);
            out << ";\n";
            std::size_t nonDefaultIdx = 0;
            for (const auto& arm : matchExpr->arms) {
                if (arm.isDefault) continue;
                out << "    " << (nonDefaultIdx == 0 ? "if" : "else if") << " (_afr_match == ";
                if (subjectType.kind == TypeKind::Text) {
                    out << "\"" << arm.caseName << "\"";
                } else {
                    out << arm.caseName;
                }
                out << ") {\n        return ";
                emitExpression(out, *arm.value, ownerClass);
                out << ";\n    }\n";
                ++nonDefaultIdx;
            }
            for (const auto& arm : matchExpr->arms) {
                if (arm.isDefault) {
                    out << "    else {\n        return ";
                    emitExpression(out, *arm.value, ownerClass);
                    out << ";\n    }\n";
                    break;
                }
            }
            out << "})()";
            return;
        }

        std::string enumName;
        if (const auto* id = dynamic_cast<const IdentifierNode*>(matchExpr->subject.get())) {
            auto vit = semantic_.globalVariables.find(id->name);
            if (vit != semantic_.globalVariables.end() &&
                vit->second.kind == TypeKind::Enum) {
                enumName = vit->second.className;
            }
        }
        if (enumName.empty()) {
            enumName = inferExpressionType(*matchExpr->subject);
        }

        const std::string resultCpp = matchExpr->resultTypeName.empty()
            ? "auto"
            : typeFromName(matchExpr->resultTypeName).toCpp();

        out << "([&]() -> " << resultCpp << " {\n";
        out << "    " << enumName << " _afr_match = ";
        emitExpression(out, *matchExpr->subject, ownerClass);
        out << ";\n";

        std::size_t nonDefaultIdx = 0;
        for (const auto& arm : matchExpr->arms) {
            if (arm.isDefault) continue;

            if (nonDefaultIdx == 0) {
                out << "    if (_afr_match.tag == " << enumName << "::Tag::" << arm.caseName
                    << ") {\n";
            } else {
                out << "    else if (_afr_match.tag == " << enumName << "::Tag::" << arm.caseName
                    << ") {\n";
            }

            if (!arm.bindNames.empty()) {
                const auto enumIt = semantic_.enums.find(enumName);
                if (enumIt != semantic_.enums.end()) {
                    const auto caseIt = enumIt->second.cases.find(arm.caseName);
                    if (caseIt != enumIt->second.cases.end()) {
                        for (std::size_t bi = 0;
                             bi < arm.bindNames.size() && bi < caseIt->second.fields.size();
                             ++bi) {
                            out << "        "
                                << cppTypeFromAfrType(caseIt->second.fields[bi].second) << " "
                                << arm.bindNames[bi] << " = _afr_match."
                                << caseIt->second.fields[bi].first << ";\n";
                        }
                    }
                }
            }

            out << "        return ";
            emitExpression(out, *arm.value, ownerClass);
            out << ";\n    }\n";
            ++nonDefaultIdx;
        }

        for (const auto& arm : matchExpr->arms) {
            if (arm.isDefault) {
                out << "    else {\n        return ";
                emitExpression(out, *arm.value, ownerClass);
                out << ";\n    }\n";
                break;
            }
        }

        bool hasDefault = false;
        for (const auto& arm : matchExpr->arms) {
            if (arm.isDefault) { hasDefault = true; break; }
        }
        if (!hasDefault) {
            out << "    throw std::runtime_error(\"match: cas non couvert\");\n";
        }

        out << "})()";
        return;
    }

    if (const auto* call = dynamic_cast<const CallExpressionNode*>(&expr)) {
        if (const auto* newExpr = dynamic_cast<const NewExpressionNode*>(call->callee.get())) {
            const std::string classCpp = newExpr->typeArgs.empty()
                ? newExpr->className
                : newExpr->className + "<" + joinGenericArgs(newExpr->typeArgs) + ">";
            out << "std::make_unique<" << classCpp << ">(";
            for (std::size_t i = 0; i < call->arguments.size(); ++i) {
                if (i > 0) out << ", ";
                emitExpression(out, *call->arguments[i], ownerClass);
            }
            out << ")";
            return;
        }

        if (dynamic_cast<const SuperExpressionNode*>(call->callee.get())) {
            if (ownerClass && !ownerClass->baseClass.empty()) {
                out << ownerClass->baseClass << "::" << ownerClass->baseClass << "(";
                for (std::size_t i = 0; i < call->arguments.size(); ++i) {
                    if (i > 0) out << ", ";
                    emitExpression(out, *call->arguments[i], ownerClass);
                }
                out << ")";
            }
            return;
        }

        const MethodSignature* externSig = nullptr;
        const MethodSignature* globalSig = nullptr;
        if (const auto* id = dynamic_cast<const IdentifierNode*>(call->callee.get())) {
            const auto it = semantic_.functions.find(id->name);
            if (it != semantic_.functions.end() && it->second.isExtern) {
                externSig = &it->second;
            }
            if (it != semantic_.functions.end() && !it->second.isExtern) {
                globalSig = &it->second;
                out << mangleGlobalFunctionName(id->name);
                if (!globalSig->typeParams.empty() && !call->typeArgs.empty()) {
                    out << "<" << joinGenericArgs(call->typeArgs) << ">";
                }
                out << "(";
                for (std::size_t i = 0; i < call->arguments.size(); ++i) {
                    if (i > 0) out << ", ";
                    const AfrType paramType = i < globalSig->paramTypes.size()
                        ? globalSig->paramTypes[i] : AfrType::voidType();
                    emitCallArgument(out, *call->arguments[i], paramType, ownerClass);
                }
                out << ")";
                return;
            }
        }

        if (const auto* member = dynamic_cast<const MemberAccessNode*>(call->callee.get())) {
            if (dynamic_cast<const SuperExpressionNode*>(member->object.get())) {
                if (ownerClass && !ownerClass->baseClass.empty()) {
                    out << ownerClass->baseClass << "::" << member->member << "(";
                    for (std::size_t i = 0; i < call->arguments.size(); ++i) {
                        if (i > 0) out << ", ";
                        emitExpression(out, *call->arguments[i], ownerClass);
                    }
                    out << ")";
                }
                return;
            }

            if (const auto* classId = dynamic_cast<const IdentifierNode*>(member->object.get())) {
                const auto modIt = semantic_.modules.find(classId->name);
                if (modIt != semantic_.modules.end() &&
                    modIt->second.functions.count(member->member)) {
                    const MethodSignature& modSig = modIt->second.functions.at(member->member);
                    out << classId->name << "::" << member->member;
                    if (!modSig.typeParams.empty() && !call->typeArgs.empty()) {
                        out << "<" << joinGenericArgs(call->typeArgs) << ">";
                    }
                    out << "(";
                    for (std::size_t i = 0; i < call->arguments.size(); ++i) {
                        if (i > 0) out << ", ";
                        emitExpression(out, *call->arguments[i], ownerClass);
                    }
                    out << ")";
                    return;
                }

                if (semantic_.classes.count(classId->name)) {
                    out << classId->name << "::" << member->member << "(";
                    for (std::size_t i = 0; i < call->arguments.size(); ++i) {
                        if (i > 0) out << ", ";
                        emitExpression(out, *call->arguments[i], ownerClass);
                    }
                    out << ")";
                    return;
                }
            }

            const MethodSignature* methodSig = nullptr;
            if (const auto* objId = dynamic_cast<const IdentifierNode*>(member->object.get())) {
                const auto vit = semantic_.globalVariables.find(objId->name);
                if (vit != semantic_.globalVariables.end() &&
                    vit->second.kind == TypeKind::Class) {
                    const auto mit = semantic_.classes.find(vit->second.className);
                    if (mit != semantic_.classes.end()) {
                        const auto sit = mit->second.methods.find(member->member);
                        if (sit != mit->second.methods.end()) methodSig = &sit->second;
                    }
                }
            }

            emitReceiver(out, *member->object, ownerClass);
            out << member->member << "(";
            for (std::size_t i = 0; i < call->arguments.size(); ++i) {
                if (i > 0) out << ", ";
                const AfrType paramType = methodSig && i < methodSig->paramTypes.size()
                    ? methodSig->paramTypes[i] : AfrType::voidType();
                if (methodSig && i < methodSig->paramTypes.size()) {
                    emitCallArgument(out, *call->arguments[i], paramType, ownerClass);
                } else {
                    emitExpression(out, *call->arguments[i], ownerClass);
                }
            }
            out << ")";
            return;
        }

        if (dynamic_cast<const LambdaExpressionNode*>(call->callee.get())) {
            out << "(";
            emitExpression(out, *call->callee, ownerClass);
            out << ")";
        } else {
            emitExpression(out, *call->callee, ownerClass);
        }
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
        const AfrType objectType = inferExpressionAfrType(*member->object);
        if (objectType.kind == TypeKind::Class &&
            classHasProperty(semantic_, objectType.className, member->member)) {
            emitReceiver(out, *member->object, ownerClass);
            out << propertyGetterName(member->member) << "()";
            return;
        }
        if (dynamic_cast<const ThisExpressionNode*>(member->object.get())) {
            out << member->member;
        } else if (const auto* classId = dynamic_cast<const IdentifierNode*>(member->object.get())) {
            if (semantic_.classes.count(classId->name)) {
                out << classId->name << "::" << member->member;
            } else {
                emitReceiver(out, *member->object, ownerClass);
                out << member->member;
            }
        } else {
            emitReceiver(out, *member->object, ownerClass);
            out << member->member;
        }
        return;
    }

    if (const auto* newExpr = dynamic_cast<const NewExpressionNode*>(&expr)) {
        out << "std::make_unique<" << newExpr->className << ">()";
        return;
    }
}

std::string CodeGenerator::inferExpressionType(const ExpressionNode& expr) const {
    if (dynamic_cast<const StringLiteralNode*>(&expr)) return "std::string";
    if (dynamic_cast<const NumberLiteralNode*>(&expr)) return "double";
    if (dynamic_cast<const BoolLiteralNode*>(&expr)) return "bool";

    if (const auto* newExpr = dynamic_cast<const NewExpressionNode*>(&expr)) {
        return instantiatedClassStorageCpp(*newExpr);
    }

    if (const auto* call = dynamic_cast<const CallExpressionNode*>(&expr)) {
        if (const auto* newCallee = dynamic_cast<const NewExpressionNode*>(call->callee.get())) {
            return instantiatedClassStorageCpp(*newCallee);
        }
    }

    if (dynamic_cast<const InterpolatedStringNode*>(&expr)) return "std::string";

    if (const auto* lambda = dynamic_cast<const LambdaExpressionNode*>(&expr)) {
        std::ostringstream params;
        for (std::size_t i = 0; i < lambda->parameters.size(); ++i) {
            if (i > 0) params << ", ";
            params << lambda->parameters[i].typeName;
        }
        return AfrType::functionType(params.str(), lambda->returnTypeName).toCpp();
    }

    if (const auto* mapEach = dynamic_cast<const MapEachExpressionNode*>(&expr)) {
        return "std::vector<" + typeFromName(mapEach->resultElementTypeName).toCpp() + ">";
    }

    if (const auto* flatMapEach = dynamic_cast<const FlatMapEachExpressionNode*>(&expr)) {
        return "std::vector<" + typeFromName(flatMapEach->resultElementTypeName).toCpp() + ">";
    }

    if (const auto* filterEach = dynamic_cast<const FilterEachExpressionNode*>(&expr)) {
        return "std::vector<" + typeFromName(filterEach->elementTypeName).toCpp() + ">";
    }

    if (const auto* reduce = dynamic_cast<const ReduceExpressionNode*>(&expr)) {
        return typeFromName(reduce->resultTypeName).toCpp();
    }

    if (const auto* matchExpr = dynamic_cast<const MatchExpressionNode*>(&expr)) {
        if (!matchExpr->resultTypeName.empty()) {
            return typeFromName(matchExpr->resultTypeName).toCpp();
        }
        if (!matchExpr->arms.empty() && matchExpr->arms[0].value) {
            return inferExpressionType(*matchExpr->arms[0].value);
        }
    }

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
        if (!list->elementTypeName.empty()) {
            return "std::vector<" + typeFromName(list->elementTypeName).toCpp() + ">";
        }
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
        const AfrType leftType = expressionOperandType(*bin->left, semantic_);
        if (leftType.kind == TypeKind::Class) {
            if (const MethodSignature* opSig =
                    findClassOperator(semantic_, leftType.className, bin->op)) {
                if (opSig->returnType.kind == TypeKind::Class ||
                    opSig->returnType.kind == TypeKind::Interface) {
                    return classStorageCpp(opSig->returnType);
                }
                return opSig->returnType.toCpp();
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
        if (it->second.kind == TypeKind::Class || it->second.kind == TypeKind::Interface) {
            return classStorageCpp(it->second);
        }
        return it->second.toCpp();
    }
    return "auto";
}

AfrType CodeGenerator::inferExpressionAfrType(const ExpressionNode& expr) const {
    if (const auto* id = dynamic_cast<const IdentifierNode*>(&expr)) {
        auto it = semantic_.globalVariables.find(id->name);
        if (it != semantic_.globalVariables.end()) return it->second;
    }
    if (const auto* num = dynamic_cast<const NumberLiteralNode*>(&expr)) {
        (void)num;
        return AfrType::number();
    }
    if (const auto* str = dynamic_cast<const StringLiteralNode*>(&expr)) {
        (void)str;
        return AfrType::text();
    }
    if (const auto* slice = dynamic_cast<const SliceExpressionNode*>(&expr)) {
        return inferExpressionAfrType(*slice->object);
    }
    if (const auto* list = dynamic_cast<const ListLiteralNode*>(&expr)) {
        if (!list->elementTypeName.empty()) {
            return AfrType::listType(typeFromName(list->elementTypeName));
        }
    }
    if (const auto* newExpr = dynamic_cast<const NewExpressionNode*>(&expr)) {
        return AfrType::classType(newExpr->className);
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
           name == "re" || name == "collections" || name == "args" || name == "path" ||
           name == "sql" || name == "web" || name == "orm" || name == "thread" ||
           name == "bigint" || name == "async" || name == "ui" || stdlibCatalogIsSimpleModule(name) ||
           mediumCatalogIsMediumModule(name) || complexCatalogIsComplexModule(name);
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
    std::string returnCpp;
    if (func.isAsync) {
        returnCpp = func.returnTypeName.empty()
            ? "afrilang::runtime::async::Task<void>"
            : "afrilang::runtime::async::Task<" +
              typeFromName(func.returnTypeName).toCpp() + ">";
    } else {
        returnCpp = func.returnTypeName.empty()
            ? "void"
            : typeFromName(func.returnTypeName).toCpp();
    }

    indent(out, indentLevel);
    out << returnCpp << " " << func.name << "(" << paramList(func) << ") {\n";
    indent(out, indentLevel + 1);

    if (moduleName == "async" && func.name == "sleep") {
        out << "return afrilang::runtime::async::sleep(" << func.parameters[0].name << ");\n";
        indent(out, indentLevel);
        out << "}\n";
        return;
    }

    if (moduleName == "ui") {
        const std::string rt = "afrilang::runtime::ui::" + func.name;
        if (func.returnTypeName.empty()) {
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
        return;
    }

    if (stdlibCatalogIsSimpleModule(moduleName)) {
        const std::string rt = "afrilang::runtime::" + moduleName + "::" + func.name;
        if (func.returnTypeName.empty()) {
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
        return;
    }

    if (mediumCatalogIsMediumModule(moduleName)) {
        const std::string rt = "afrilang::runtime::med::" + moduleName + "::" + func.name;
        if (func.returnTypeName.empty()) {
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
        return;
    }

    if (complexCatalogIsComplexModule(moduleName)) {
        const std::string rt = "afrilang::runtime::cx::" + moduleName + "::" + func.name;
        if (func.returnTypeName.empty()) {
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
        return;
    }

    if (func.isAsync && moduleName == "http") {
        if (func.name == "httpGetAsync") {
            out << "return afrilang::runtime::async::runBlockingTask([url]() { "
                << "return afrilang::runtime::http::httpGet(url); });\n";
            indent(out, indentLevel);
            out << "}\n";
            return;
        }
        if (func.name == "httpPostAsync") {
            out << "return afrilang::runtime::async::runBlockingTask([url, body]() { "
                << "return afrilang::runtime::http::httpPost(url, body); });\n";
            indent(out, indentLevel);
            out << "}\n";
            return;
        }
    }

    if (func.isAsync && moduleName == "io") {
        if (func.name == "readFileAsync") {
            out << "return afrilang::runtime::async::runBlockingTask([path]() { "
                << "return afrilang::runtime::io::readFile(path); });\n";
            indent(out, indentLevel);
            out << "}\n";
            return;
        }
    }

    const std::string rt = "afrilang::runtime::" + runtimeModuleName(moduleName) +
                           "::" + func.name;

    if (func.name == "writeFile") {
        out << rt << "(path, content);\n";
    } else if (moduleName == "json") {
        if (func.name == "parse") {
            out << "return afrilang::runtime::json::parseValue(text);\n";
        } else if (func.name == "stringify") {
            out << "return afrilang::runtime::json::stringifyValue(value);\n";
        } else if (func.name == "getString") {
            out << "return afrilang::runtime::json::getStringFrom(value, key);\n";
        } else if (func.name == "getNumber") {
            out << "return afrilang::runtime::json::getNumberFrom(value, key);\n";
        } else if (func.name == "getInt") {
            out << "return afrilang::runtime::json::getIntFrom(value, key);\n";
        } else if (func.name == "makeObject") {
            out << "return afrilang::runtime::json::makeObjectValue(key, value);\n";
        }
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

std::string CodeGenerator::functionReturnCpp(const FunctionNode& func,
                                             const ClassInfo* ownerClass) {
    if (func.returnTypeName.empty() && !func.isAsync) return "void";
    if (func.isAsync) {
        if (func.returnTypeName.empty()) {
            return "afrilang::runtime::async::Task<void>";
        }
        if (func.returnsResult) {
            return "afrilang::runtime::async::Task<" +
                   resultTypeAlias(func.returnTypeName) + ">";
        }
        return "afrilang::runtime::async::Task<" +
               cppTypeFromAfrName(func.returnTypeName, effectiveTypeParams(func, ownerClass)) +
               ">";
    }
    if (func.returnsResult) return resultTypeAlias(func.returnTypeName);
    return cppTypeFromAfrName(func.returnTypeName, effectiveTypeParams(func, ownerClass));
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

    std::vector<std::string> args;
    args.push_back(compilerForTarget(crossTarget_));
    args.push_back("-std=" + (semantic_.usesAsync ? std::string("c++20") : std::string("c++17")));
    args.push_back("-O2");
    args.push_back("-Wall");
    args.push_back("-Wextra");
    args.push_back("-fstack-protector-strong");
    args.push_back("-D_FORTIFY_SOURCE=2");
    args.push_back("-fPIE");
    if (semantic_.usesAsync && crossTarget_ != "wasm32") {
        args.push_back("-fcoroutines");
        args.push_back("-pthread");
    }
    if (semantic_.usesUi && crossTarget_ != "wasm32") {
        args.push_back("-I/usr/include/SDL2");
        args.push_back("-D_REENTRANT");
    }
    if (debugSymbols_) {
        args.push_back("-g");
    }
    if (crossTarget_ == "wasm32") {
        args.push_back("-s");
        args.push_back("WASM=1");
    }
    args.push_back("-o");
    args.push_back(executablePath);
    args.push_back(outputPath);
    if (!runtimeDir_.empty()) {
        args.push_back("-I" + runtimeDir_);
    }
    for (const auto& lib : linkLibraries_) {
        if (!lib.empty()) args.push_back(lib);
    }
    if (semantic_.usesUi && crossTarget_ != "wasm32") {
        args.push_back("-lSDL2");
        args.push_back("-lSDL2_ttf");
    }

    ProcessConfig config;
    config.timeoutSeconds = securityLimits(SecurityContext::TrustedCompile).compileTimeoutSeconds;
    config.maxMemoryMb = securityLimits(SecurityContext::TrustedCompile).maxMemoryMb;
    config.maxCpuSeconds = static_cast<std::size_t>(config.timeoutSeconds);
    config.applyResourceLimits = isSecureMode();

    std::string output;
    const int code = runCommand(args, config, output);
    if (code != 0 && !output.empty()) {
        std::cerr << output;
    }
    return code == 0;
}

} // namespace afrilang
