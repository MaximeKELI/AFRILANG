#include "afrilang/lexer.hpp"
#include "afrilang/types.hpp"
#include "afrilang/parser.hpp"
#include "afrilang/semantic.hpp"
#include "afrilang/compiler.hpp"
#include "afrilang/cli.hpp"
#include "afrilang/diagnostics.hpp"
#include "afrilang/i18n.hpp"
#include "afrilang/security.hpp"
#include "afrilang/cache.hpp"
#include "afrilang/semver.hpp"
#include "afrilang/utf8.hpp"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <stdexcept>
#include <string>
#include <cstdlib>

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
    bool threw = false;
    try {
        analyzer.analyze();
    } catch (const afrilang::CompileError& e) {
        threw = true;
        expect(e.code() == afrilang::ErrorCode::UndeclaredVariable, "undeclared error code");
        expect(e.format().find("E3002") != std::string::npos, "E3002 in format");
    }
    expect(threw, "undeclared variable detected");
}

static void testFindSimilarNames() {
    const auto suggestions = afrilang::findSimilarNames("coutn", {"count", "counter", "x"});
    expect(!suggestions.empty(), "suggestion for coutn");
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
    bool threw = false;
    try {
        analyzer.analyze();
    } catch (const afrilang::CompileError& e) {
        threw = true;
        expect(e.code() == afrilang::ErrorCode::FfiLibraryDenied, "ffi denied");
    }
    expect(threw, "ffi library rejected");
}

static void testCompileExample() {
    afrilang::Compiler compiler("../examples/hello.afr", "..");
    auto program = compiler.compile();
    expect(program != nullptr, "compile hello.afr");
    afrilang::SemanticAnalyzer analyzer(*program, &compiler.sources(), "../examples/hello.afr");
    analyzer.analyze();
}

static void testCompileOperatorsDemo() {
    afrilang::Compiler compiler("../examples/operators_demo.afr", "..");
    auto program = compiler.compile();
    afrilang::SemanticAnalyzer analyzer(*program, &compiler.sources(), "../examples/operators_demo.afr");
    analyzer.analyze();
}

static void testCompileUnionsDemo() {
    afrilang::Compiler compiler("../examples/unions_demo.afr", "..");
    auto program = compiler.compile();
    afrilang::SemanticAnalyzer analyzer(*program, &compiler.sources(), "../examples/unions_demo.afr");
    analyzer.analyze();
}

static void testCompileFromSourceImports() {
    std::ifstream file("../examples/full_demo.afr");
    std::string src((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    afrilang::Compiler compiler("../examples/full_demo.afr", "..");
    auto program = compiler.compileFromSource(src);
    bool hasSum2 = false;
    for (const auto& fn : program->functions) {
        if (fn->name == "sum2") hasSum2 = true;
    }
    expect(hasSum2, "compileFromSource merges imported sum2");
    afrilang::SemanticAnalyzer analyzer(*program, &compiler.sources(), "../examples/full_demo.afr");
    analyzer.analyze();

    const std::string absPath = std::filesystem::absolute("../examples/full_demo.afr").string();
    afrilang::Compiler absCompiler(absPath, "..");
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

static void testSecureTempPath() {
    const std::string path = afrilang::secureTempPath("unit_test.tmp");
    expect(!path.empty(), "secure temp path generated");
    expect(path.find("/tmp/afrilang") == std::string::npos || path.find("sandbox") != std::string::npos,
           "temp path uses sandbox directory");
    afrilang::cleanupSecureSandbox();
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
    testSecureTempPath();

    std::cout << "\n";
    if (failures == 0) {
        std::cout << "Tous les tests passent.\n";
        return 0;
    }
    std::cout << failures << " test(s) en échec.\n";
    return 1;
}
