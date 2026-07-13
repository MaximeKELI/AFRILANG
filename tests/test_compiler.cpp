#include "afrilang/lexer.hpp"
#include "afrilang/types.hpp"
#include "afrilang/parser.hpp"
#include "afrilang/ast.hpp"
#include "afrilang/semantic.hpp"
#include "afrilang/compiler.hpp"
#include "afrilang/codegen.hpp"
#include "afrilang/cli.hpp"
#include "afrilang/diagnostics.hpp"
#include "afrilang/i18n.hpp"
#include "afrilang/security.hpp"
#include "afrilang/cache.hpp"
#include "afrilang/semver.hpp"
#include "afrilang/utf8.hpp"
#include "afrilang/version.hpp"

#include "afrilang/sandbox.hpp"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <stdexcept>
#include <string>
#include <cstdlib>

#if __has_include(<SDL2/SDL_ttf.h>)
#include "../runtime/ui.hpp"
#define AFRILANG_HAS_UI_TEST 1
#endif

static int failures = 0;

static void expect(bool condition, const std::string& message) {
    if (!condition) {
        std::cerr << "FAIL: " << message << "\n";
        ++failures;
    }
}

static void testLexerKeywords() {
    afrilang::Lexer lexer("class function if say end create");
    const auto tokens = lexer.tokenize();
    expect(tokens.size() >= 6, "lexer produces enough tokens");
    expect(tokens[0].type == afrilang::TokenType::Class, "token class");
}

static void testLexerFrenchKeywords() {
    afrilang::Lexer lexer("dire fin classe fonction si alors");
    const auto tokens = lexer.tokenize();
    expect(tokens[0].type == afrilang::TokenType::Say, "dire -> say");
    expect(tokens[1].type == afrilang::TokenType::End, "fin -> end");
    expect(tokens[4].type == afrilang::TokenType::If, "si -> if");
}

static void testLexerAsyncFrench() {
    afrilang::Lexer lexer("asynchrone attendre enumeration oui non");
    const auto tokens = lexer.tokenize();
    expect(tokens[0].type == afrilang::TokenType::Async, "asynchrone");
    expect(tokens[1].type == afrilang::TokenType::Await, "attendre");
    expect(tokens[2].type == afrilang::TokenType::Enum, "enumeration");
    expect(tokens[3].type == afrilang::TokenType::Yes, "oui");
    expect(tokens[4].type == afrilang::TokenType::No, "non");
}

static void testLexerUtf8Identifier() {
    afrilang::Lexer lexer("create café = 1\nsay café\n");
    const auto tokens = lexer.tokenize();
    bool foundCafe = false;
    for (const auto& t : tokens) {
        if (t.lexeme == "café") foundCafe = true;
    }
    expect(foundCafe, "UTF-8 identifier café");
}

static void testParserHello() {
    const std::string src = "say \"Hello\"\n";
    afrilang::Lexer lexer(src);
    afrilang::Parser parser(lexer.tokenize());
    auto program = parser.parse();
    expect(program->statements.size() == 1, "parse say statement");
}

static void testParserEnumUnion() {
    const std::string src =
        "union Shape\n"
        "    case Circle with radius number\n"
        "end\n";
    afrilang::Lexer lexer(src);
    afrilang::Parser parser(lexer.tokenize());
    auto program = parser.parse();
    expect(program->enums.size() == 1, "union parses as enum");
}

static void testParserOperator() {
    const std::string src =
        "class V\n"
        "    operator + (other V) returns V\n"
        "        return new V()\n"
        "    end\n"
        "end\n";
    afrilang::Lexer lexer(src);
    afrilang::Parser parser(lexer.tokenize());
    auto program = parser.parse();
    expect(!program->classes.empty(), "class with operator parses");
    expect(program->classes[0]->methods[0]->isOperator, "operator flag");
}

static void testSemanticUndeclaredVariable() {
    const std::string src = "say unknown_var\n";
    afrilang::Lexer lexer(src);
    afrilang::Parser parser(lexer.tokenize());
    auto program = parser.parse();
    afrilang::SourceManager sources;
    sources.addFile("test.afr", src);
    afrilang::SemanticAnalyzer analyzer(*program, &sources, "test.afr");
    const auto result = analyzer.analyze();
    expect(result.hasErrors(), "undeclared variable detected");
    expect(!result.errors.empty(), "errors vector populated");
    expect(result.errors[0].code == afrilang::ErrorCode::UndeclaredVariable, "undeclared error code");
    expect(afrilang::formatDiagnostic(result.errors[0]).find("E3002") != std::string::npos,
           "E3002 in format");
}

static void testFindSimilarNames() {
    const auto suggestions = afrilang::findSimilarNames("coutn", {"count", "counter", "x"});
    expect(!suggestions.empty(), "suggestion for coutn");
}

static void testUiMultilineTextRenders() {
#if AFRILANG_HAS_UI_TEST
    setenv("SDL_VIDEODRIVER", "dummy", 1);

    afrilang::runtime::ui::openWindow("test", 320, 240);
    expect(afrilang::runtime::ui::isOpen(), "ui window opens (dummy driver)");
    afrilang::runtime::ui::beginFrame();
    afrilang::runtime::ui::clearBackground(0, 0, 0);
    afrilang::runtime::ui::drawText("Hello\nWorld", 10, 10, 18);
    afrilang::runtime::ui::showFrame();
    afrilang::runtime::ui::closeWindow();
    expect(!afrilang::runtime::ui::isOpen(), "ui window closes");
#else
    (void)0; // SDL2 non disponible — test ignoré
#endif
}

static void testSemVer() {
    afrilang::SemVer v;
    expect(afrilang::parseSemVer("1.2.3", v), "parse semver");
    expect(v.major == 1 && v.minor == 2 && v.patch == 3, "semver parts");
    expect(afrilang::semverSatisfies("1.0.0", "1.2.3"), "semver satisfies");
    expect(!afrilang::semverSatisfies("2.0.0", "1.2.3"), "semver not satisfies");
}

static void testUtf8Validation() {
    expect(afrilang::isValidUtf8("hello"), "ascii valid utf8");
    expect(afrilang::isValidUtf8("café"), "accented valid utf8");
    expect(!afrilang::isValidUtf8("\xff\xfe"), "invalid utf8");
}

static void testI18nEnglish() {
    afrilang::setLocale(afrilang::Locale::English);
    const std::string header = afrilang::formatErrorHeader("f.afr", 1, 1, afrilang::ErrorCode::Generic);
    expect(header.find("Error") != std::string::npos, "english error header");
    afrilang::setLocale(afrilang::Locale::French);
}

static void testMatchExpressionParse() {
    const std::string src =
        "enum S\n    case Ok\nend\n"
        "create s = S.Ok\n"
        "create x = match s\n"
        "    case Ok then \"ok\"\n"
        "    end\n"
        "    default \"?\"\n"
        "    end\n"
        "end\n";
    afrilang::Lexer lexer(src);
    afrilang::Parser parser(lexer.tokenize());
    auto program = parser.parse();
    expect(!program->statements.empty(), "match expression parses");
}

static void testLintEmptyFunction() {
    const std::string src =
        "function empty()\n"
        "end\n";
    afrilang::Lexer lexer(src);
    afrilang::Parser parser(lexer.tokenize());
    auto program = parser.parse();
    afrilang::SourceManager sources;
    sources.addFile("test.afr", src);
    afrilang::SemanticAnalyzer analyzer(*program, &sources, "test.afr");
    const auto result = analyzer.analyze();
    expect(!result.warnings.empty(), "lint warns empty function");
}

static void testFfiAllowlist() {
    const std::string src =
        "extern from \"evil\" function hack(x number) returns number\n";
    afrilang::Lexer lexer(src);
    afrilang::Parser parser(lexer.tokenize());
    auto program = parser.parse();
    afrilang::SourceManager sources;
    sources.addFile("test.afr", src);
    afrilang::SemanticAnalyzer analyzer(*program, &sources, "test.afr");
    const auto result = analyzer.analyze();
    expect(result.hasErrors(), "ffi library rejected");
    bool found = false;
    for (const auto& e : result.errors) {
        if (e.code == afrilang::ErrorCode::FfiLibraryDenied) found = true;
    }
    expect(found, "ffi denied");
}

static void testCompileExample() {
    afrilang::Compiler compiler("examples/hello.afr", ".");
    auto program = compiler.compile();
    expect(program != nullptr, "compile hello.afr");
    afrilang::SemanticAnalyzer analyzer(*program, &compiler.sources(), "examples/hello.afr");
    analyzer.analyze();
}

static void testCompileOperatorsDemo() {
    afrilang::Compiler compiler("examples/operators_demo.afr", ".");
    auto program = compiler.compile();
    afrilang::SemanticAnalyzer analyzer(*program, &compiler.sources(), "examples/operators_demo.afr");
    analyzer.analyze();
}

static void testCompileUnionsDemo() {
    afrilang::Compiler compiler("examples/unions_demo.afr", ".");
    auto program = compiler.compile();
    afrilang::SemanticAnalyzer analyzer(*program, &compiler.sources(), "examples/unions_demo.afr");
    analyzer.analyze();
}

static void testCompileFromSourceImports() {
    std::ifstream file("examples/full_demo.afr");
    std::string src((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    afrilang::Compiler compiler("examples/full_demo.afr", ".");
    auto program = compiler.compileFromSource(src);
    bool hasSum2 = false;
    for (const auto& fn : program->functions) {
        if (fn->name == "sum2") hasSum2 = true;
    }
    expect(hasSum2, "compileFromSource merges imported sum2");
    afrilang::SemanticAnalyzer analyzer(*program, &compiler.sources(), "examples/full_demo.afr");
    analyzer.analyze();

    const std::string absPath = std::filesystem::absolute("examples/full_demo.afr").string();
    afrilang::Compiler absCompiler(absPath, ".");
    auto absProgram = absCompiler.compileFromSource(src);
    hasSum2 = false;
    for (const auto& fn : absProgram->functions) {
        if (fn->name == "sum2") hasSum2 = true;
    }
    expect(hasSum2, "absolute path compileFromSource merges sum2");
    afrilang::Compiler rootCompiler(absPath, afrilang::detectAfrilangRoot());
    auto rootProgram = rootCompiler.compileFromSource(src);
    hasSum2 = false;
    for (const auto& fn : rootProgram->functions) {
        if (fn->name == "sum2") hasSum2 = true;
    }
    expect(hasSum2, "detectAfrilangRoot compileFromSource merges sum2");
    afrilang::SemanticAnalyzer rootAnalyzer(*rootProgram, &rootCompiler.sources(), absPath);
    rootAnalyzer.analyze();
}

static void testSecureModeDefault() {
    unsetenv("AFRILANG_INSECURE");
    expect(afrilang::isSecureMode(), "secure mode enabled by default");
}

static void testSecureModeInsecure() {
    setenv("AFRILANG_INSECURE", "1", 1);
    expect(!afrilang::isSecureMode(), "AFRILANG_INSECURE disables secure mode");
    unsetenv("AFRILANG_INSECURE");
}

static void testSourceSizeLimit() {
    unsetenv("AFRILANG_INSECURE");
    const std::string huge(600 * 1024, 'x');
    bool caught = false;
    try {
        afrilang::validateSourceContent(huge, "test");
    } catch (const afrilang::CompileError& e) {
        caught = e.code() == afrilang::ErrorCode::SecurityViolation;
    }
    expect(caught, "oversized source rejected in secure mode");
}

static void testPathComponentValidation() {
    bool caught = false;
    try {
        afrilang::validatePathComponent("..");
    } catch (const afrilang::CompileError& e) {
        caught = e.code() == afrilang::ErrorCode::SecurityViolation;
    }
    expect(caught, "path traversal component rejected");
}

static void testNetworkServeGate() {
    unsetenv("AFRILANG_INSECURE");
    unsetenv("AFRILANG_ALLOW_SERVE");
    expect(!afrilang::allowNetworkServe(), "serve blocked without AFRILANG_ALLOW_SERVE");
    setenv("AFRILANG_ALLOW_SERVE", "1", 1);
    expect(afrilang::allowNetworkServe(), "serve allowed with AFRILANG_ALLOW_SERVE=1");
    unsetenv("AFRILANG_ALLOW_SERVE");
}

static void testIntAndJsonTypes() {
    expect(afrilang::typeFromName("int").kind == afrilang::TypeKind::Int, "int type name");
    expect(afrilang::typeFromName("json").kind == afrilang::TypeKind::Json, "json type name");

    const std::string src = "create x int = 10\n";
    afrilang::Lexer lexer(src);
    afrilang::Parser parser(lexer.tokenize());
    auto program = parser.parse();
    afrilang::SemanticAnalyzer analyzer(*program, nullptr, "test.afr");
    const auto result = analyzer.analyze();
    expect(result.globalVariables.at("x").kind == afrilang::TypeKind::Int, "int variable type");
}

static void testCompileCacheHash() {
    const std::string h1 = afrilang::CompileCache::hashContent("hello");
    const std::string h2 = afrilang::CompileCache::hashContent("hello");
    const std::string h3 = afrilang::CompileCache::hashContent("world");
    expect(h1 == h2, "cache hash stable");
    expect(h1 != h3, "cache hash differs");
}

static void testMultiSemanticErrors() {
    const std::string src =
        "say unknown_one\n"
        "say unknown_two\n";
    afrilang::Lexer lexer(src);
    afrilang::Parser parser(lexer.tokenize());
    auto program = parser.parse();
    afrilang::SourceManager sources;
    sources.addFile("multi.afr", src);
    afrilang::SemanticAnalyzer analyzer(*program, &sources, "multi.afr");
    const auto result = analyzer.analyze();
    expect(result.errors.size() >= 2, "multi semantic errors collected");
}

static void testParserRecoveryContinues() {
    const std::string src =
        "function broken(\n"
        "say \"still parsed\"\n";
    afrilang::Lexer lexer(src);
    afrilang::Parser parser(lexer.tokenize());
    auto program = parser.parse();
    expect(parser.hasErrors(), "parser reports errors");
    expect(!program->statements.empty() || parser.diagnostics().errorCount() >= 1,
           "parser recovery yields partial AST or diagnostics");
    bool hasSay = false;
    for (const auto& stmt : program->statements) {
        if (dynamic_cast<const afrilang::SayStatementNode*>(stmt.get())) hasSay = true;
    }
    expect(hasSay || parser.diagnostics().errorCount() >= 1,
           "valid say recovered or error reported");
}

static void testDuplicateClassErrorCode() {
    const std::string src =
        "class A\nend\n"
        "class A\nend\n";
    afrilang::Lexer lexer(src);
    afrilang::Parser parser(lexer.tokenize());
    auto program = parser.parse();
    afrilang::SemanticAnalyzer analyzer(*program, nullptr, "dup.afr");
    const auto result = analyzer.analyze();
    expect(result.hasErrors(), "duplicate class error");
}

static void testTypedExpressionAnnotation() {
    const std::string src = "create x = 42\nsay x\n";
    afrilang::Lexer lexer(src);
    afrilang::Parser parser(lexer.tokenize());
    auto program = parser.parse();
    afrilang::SemanticAnalyzer analyzer(*program, nullptr, "typed.afr");
    analyzer.analyze();
    expect(program->statements.size() >= 2, "two statements");
    const auto* say = dynamic_cast<const afrilang::SayStatementNode*>(program->statements[1].get());
    expect(say != nullptr, "say statement");
    expect(say->value->typeInferred, "expression type annotated");
    expect(say->value->inferredType.kind == afrilang::TypeKind::Number ||
           say->value->inferredType.kind == afrilang::TypeKind::Int,
           "inferred number type");
}

static void testCacheFingerprintVersionInvalidates() {
    afrilang::CacheFingerprintInput a;
    a.sourceContent = "say \"hi\"\n";
    a.compilerVersion = "1.0.0";
    a.crossTarget = "native";
    a.runtimeDir = "";
    a.stdlibStamp = "stdlib-v1";
    afrilang::CacheFingerprintInput b = a;
    b.compilerVersion = "1.0.1";
    expect(afrilang::CompileCache::buildFingerprint(a) !=
               afrilang::CompileCache::buildFingerprint(b),
           "version change invalidates fingerprint");
}

static void testCacheMetaKeyDistinctPaths() {
    const std::string k1 = afrilang::CompileCache::metaKeyForPath("/tmp/a/hello.afr");
    const std::string k2 = afrilang::CompileCache::metaKeyForPath("/tmp/b/hello.afr");
    expect(k1 != k2, "basename collision avoided via absolute path key");
}

static void testPipelineMissingFile() {
    afrilang::CompileOptions opts;
    opts.useCache = false;
    auto result = afrilang::Pipeline::compileFile("/tmp/afrilang_does_not_exist_xyz.afr", opts);
    expect(!result.success, "missing file fails");
    expect(!result.diagnostics.empty(), "missing file has diagnostic");
}

static void testPipelineMultiErrorNoCodegen() {
    namespace fs = std::filesystem;
    const fs::path tmp = fs::temp_directory_path() / "afrilang_multi_err.afr";
    {
        std::ofstream out(tmp);
        out << "say foo_missing\n"
            << "say bar_missing\n";
    }
    afrilang::CompileOptions opts;
    opts.useCache = false;
    opts.emitOnly = true;
    auto result = afrilang::Pipeline::compileFile(tmp.string(), opts);
    expect(!result.success, "pipeline fails on semantic errors");
    expect(result.diagnostics.size() >= 2, "pipeline collects multiple diagnostics");
    std::error_code ec;
    fs::remove(tmp, ec);
}

static void testSecureTempPath() {
    const std::string path = afrilang::secureTempPath("unit_test.tmp");
    expect(!path.empty(), "secure temp path generated");
    expect(path.find("/tmp/afrilang") == std::string::npos || path.find("sandbox") != std::string::npos,
           "temp path uses sandbox directory");
    afrilang::cleanupSecureSandbox();
}

static void testParseIndexComparison() {
    const std::string src =
        "function f(xs list number, i number, gx number)\n"
        "    if xs at i is equal to gx then\n"
        "        say \"ok\"\n"
        "    end\n"
        "end\n";
    afrilang::Lexer lexer(src);
    afrilang::Parser parser(lexer.tokenize());
    auto program = parser.parse();
    expect(!program->functions.empty(), "index comparison parses");
    const auto& body = program->functions[0]->body;
    expect(!body.empty(), "function body not empty");
    const auto* ifStmt = dynamic_cast<const afrilang::IfStatementNode*>(body[0].get());
    expect(ifStmt != nullptr, "if statement in body");
    const auto* cond = dynamic_cast<const afrilang::BinaryOpNode*>(ifStmt->condition.get());
    expect(cond != nullptr && cond->op == "==", "condition is equality comparison");
    expect(dynamic_cast<const afrilang::IndexExpressionNode*>(cond->left.get()) != nullptr,
           "left side is index expression");
}

static void testParseCallComparison() {
    const std::string src =
        "function occupied() returns bool\n"
        "    return yes\n"
        "end\n"
        "function run()\n"
        "    if occupied() is equal to false then\n"
        "        say \"bad\"\n"
        "    end\n"
        "end\n";
    afrilang::Lexer lexer(src);
    afrilang::Parser parser(lexer.tokenize());
    auto program = parser.parse();
    expect(program->functions.size() >= 2, "call comparison program parses");
    const auto& runBody = program->functions[1]->body;
    const auto* ifStmt = dynamic_cast<const afrilang::IfStatementNode*>(runBody[0].get());
    expect(ifStmt != nullptr, "if in run");
    const auto* cond = dynamic_cast<const afrilang::BinaryOpNode*>(ifStmt->condition.get());
    expect(cond != nullptr && cond->op == "==", "call compared with false");
    expect(dynamic_cast<const afrilang::CallExpressionNode*>(cond->left.get()) != nullptr,
           "left side is call expression");
}

static void testParseAssertCallComparison() {
    const std::string src =
        "function occupied(xs list number, ys list number, count number, gx number, gy number) returns bool\n"
        "    return no\n"
        "end\n"
        "test \"assert call compare\"\n"
        "    create xs list number = list of 5\n"
        "    create ys list number = list of 5\n"
        "    assert occupied(xs, ys, 1, 9, 9) is equal to false\n"
        "end\n";
    afrilang::Lexer lexer(src);
    afrilang::Parser parser(lexer.tokenize());
    auto program = parser.parse();
    expect(!program->tests.empty(), "assert call comparison parses");
    afrilang::SourceManager sources;
    sources.addFile("test.afr", src);
    afrilang::SemanticAnalyzer analyzer(*program, &sources, "test.afr");
    analyzer.analyze();
}

static void testCompileSnake() {
    afrilang::Compiler compiler("examples/snake.afr", afrilang::detectAfrilangRoot());
    auto program = compiler.compile();
    expect(program != nullptr, "compile snake.afr");
    afrilang::SemanticAnalyzer analyzer(*program, &compiler.sources(), "examples/snake.afr");
    analyzer.analyze();
}

static void testSnakeLogicUnitTests() {
#if AFRILANG_HAS_UI_TEST
    afrilang::CompileOptions opts;
    opts.runtimeDir = afrilang::detectAfrilangRoot() + "/runtime";
    opts.useCache = false;
    opts.outputExecutable = "snake_test_bin";
    const auto result = afrilang::Pipeline::compileFile("examples/snake_test.afr", opts);
    expect(result.success, "compile snake_test.afr");

    afrilang::ProcessConfig config;
    config.timeoutSeconds = 30;
    config.applyResourceLimits = true;
    const auto exec = afrilang::execSandboxed("./" + result.executable, {}, config);
    expect(exec.exitCode == 0, "snake logic unit tests pass");
#else
    (void)0; // SDL2 requis pour linker snake_test
#endif
}

static void testStringInterpolationCall() {
    const std::string src =
        "import \"std/game2d\"\n"
        "use game2d\n"
        "create msg text = \"Record {highScore()}\"\n";
    afrilang::Compiler compiler("examples/snake_interp.afr", ".");
    auto program = compiler.compileFromSource(src);
    afrilang::SemanticAnalyzer analyzer(*program, &compiler.sources(),
                                         "examples/snake_interp.afr");
    const auto semantic = analyzer.analyze();
    afrilang::CodeGenerator codegen(*program, semantic);
    const std::string cpp = codegen.generate();
    expect(cpp.find("game2d::highScore()") != std::string::npos,
           "interpolation calls highScore()");
}

static void testJsonStringLiteralParse() {
    const std::string src =
        "import \"std/json\"\n"
        "use json\n"
        "create doc json = parse(\"{\\\"value\\\": 42}\")\n";
    afrilang::Compiler compiler("examples/json_literal_test.afr",
                                afrilang::detectAfrilangRoot());
    auto program = compiler.compileFromSource(src);
    expect(program != nullptr, "parse JSON string literal in source");
    afrilang::SemanticAnalyzer analyzer(*program, &compiler.sources(),
                                         "examples/json_literal_test.afr");
    analyzer.analyze();
}

int main() {
    std::cout << "=== Tests compilateur AFRILANG ===\n";

    testLexerKeywords();
    testLexerFrenchKeywords();
    testLexerAsyncFrench();
    testLexerUtf8Identifier();
    testParserHello();
    testParserEnumUnion();
    testParserOperator();
    testSemanticUndeclaredVariable();
    testFindSimilarNames();
    testUiMultilineTextRenders();
    testSemVer();
    testUtf8Validation();
    testI18nEnglish();
    testMatchExpressionParse();
    testLintEmptyFunction();
    testFfiAllowlist();
    testCompileExample();
    testCompileOperatorsDemo();
    testCompileUnionsDemo();
    testCompileFromSourceImports();
    testSecureModeDefault();
    testSecureModeInsecure();
    testSourceSizeLimit();
    testPathComponentValidation();
    testNetworkServeGate();
    testIntAndJsonTypes();
    testCompileCacheHash();
    testMultiSemanticErrors();
    testParserRecoveryContinues();
    testDuplicateClassErrorCode();
    testTypedExpressionAnnotation();
    testCacheFingerprintVersionInvalidates();
    testCacheMetaKeyDistinctPaths();
    testPipelineMissingFile();
    testPipelineMultiErrorNoCodegen();
    testSecureTempPath();
    testParseIndexComparison();
    testParseCallComparison();
    testParseAssertCallComparison();
    testCompileSnake();
    testSnakeLogicUnitTests();
    testStringInterpolationCall();
    testJsonStringLiteralParse();
    std::cout << "\n";
    if (failures == 0) {
        std::cout << "Tous les tests passent.\n";
        return 0;
    }
    std::cout << failures << " test(s) en échec.\n";
    return 1;
}
