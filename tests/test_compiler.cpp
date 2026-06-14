#include "afrilang/lexer.hpp"
#include "afrilang/parser.hpp"
#include "afrilang/semantic.hpp"
#include "afrilang/compiler.hpp"
#include "afrilang/diagnostics.hpp"
#include "afrilang/i18n.hpp"
#include "afrilang/semver.hpp"
#include "afrilang/utf8.hpp"

#include <iostream>
#include <stdexcept>
#include <string>

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

static void testLintUnusedModule() {
    const std::string src =
        "module M\n    export function f() returns number\n        return 1\n    end\n"
        "end\n"
        "use M\n"
        "say \"hi\"\n";
    afrilang::Lexer lexer(src);
    afrilang::Parser parser(lexer.tokenize());
    auto program = parser.parse();
    afrilang::SourceManager sources;
    sources.addFile("test.afr", src);
    afrilang::SemanticAnalyzer analyzer(*program, &sources, "test.afr");
    const auto result = analyzer.analyze();
    expect(!result.warnings.empty(), "lint warns unused module");
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
    testLintUnusedModule();
    testFfiAllowlist();
    testCompileExample();
    testCompileOperatorsDemo();
    testCompileUnionsDemo();

    std::cout << "\n";
    if (failures == 0) {
        std::cout << "Tous les tests passent.\n";
        return 0;
    }
    std::cout << failures << " test(s) en échec.\n";
    return 1;
}
