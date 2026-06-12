#include "afrilang/lexer.hpp"
#include "afrilang/parser.hpp"
#include "afrilang/semantic.hpp"
#include "afrilang/compiler.hpp"
#include "afrilang/diagnostics.hpp"

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
    expect(tokens.size() >= 6, "lexer produit assez de tokens");
    expect(tokens[0].type == afrilang::TokenType::Class, "token class");
    expect(tokens[1].type == afrilang::TokenType::Function, "token function");
}

static void testParserHello() {
    const std::string src = "say \"Hello\"\n";
    afrilang::Lexer lexer(src);
    afrilang::Parser parser(lexer.tokenize());
    auto program = parser.parse();
    expect(program->statements.size() == 1, "parse say statement");
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
        const std::string msg = e.format();
        expect(msg.find("non déclarée") != std::string::npos, "message variable non déclarée");
    }
    expect(threw, "variable non déclarée détectée");
}

static void testFindSimilarNames() {
    const auto suggestions = afrilang::findSimilarNames(
        "coutn", {"count", "counter", "x"});
    expect(!suggestions.empty(), "suggestion pour coutn -> count");
}

static void testCompileExample() {
    afrilang::Compiler compiler("../examples/hello.afr", "..");
    auto program = compiler.compile();
    expect(program != nullptr, "compilation hello.afr");
    afrilang::SemanticAnalyzer analyzer(*program, &compiler.sources(), "../examples/hello.afr");
    analyzer.analyze();
}

int main() {
    std::cout << "=== Tests compilateur AFRILANG ===\n";

    testLexerKeywords();
    testParserHello();
    testSemanticUndeclaredVariable();
    testFindSimilarNames();
    testCompileExample();

    std::cout << "\n";
    if (failures == 0) {
        std::cout << "Tous les tests unitaires passent.\n";
        return 0;
    }
    std::cout << failures << " test(s) en échec.\n";
    return 1;
}
