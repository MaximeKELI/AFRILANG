#include "afrilang/parser.hpp"

#include "afrilang/error.hpp"
#include "afrilang/lexer.hpp"

#include <unordered_set>
#include <cctype>

namespace afrilang {

Parser::Parser(std::vector<Token> tokens) : tokens_(std::move(tokens)) {}

std::unique_ptr<ProgramNode> Parser::parse() {
    return parseProgram();
}

bool Parser::isAtEnd() const {
    return peek().type == TokenType::Eof;
}

const Token& Parser::peek() const {
    return tokens_[current_];
}

const Token& Parser::previous() const {
    return tokens_[current_ - 1];
}

const Token& Parser::advance() {
    if (!isAtEnd()) ++current_;
    return previous();
}

bool Parser::check(TokenType type) const {
    if (isAtEnd()) return false;
    return peek().type == type;
}

bool Parser::match(TokenType type) {
    if (check(type)) {
        advance();
        return true;
    }
    return false;
}

bool Parser::matchOneOf(TokenType a, TokenType b) {
    return match(a) || match(b);
}

bool Parser::matchOneOf(TokenType a, TokenType b, TokenType c) {
    return match(a) || match(b) || match(c);
}

bool Parser::matchOneOf(TokenType a, TokenType b, TokenType c, TokenType d) {
    return match(a) || match(b) || match(c) || match(d);
}

const Token& Parser::consume(TokenType type, const std::string& message) {
    if (check(type)) return advance();
    error(message);
}

[[noreturn]] void Parser::error(const std::string& message) const {
    const Token& token = peek();
    throw CompileError(message, token.line, token.column);
}

void Parser::synchronize() {
    advance();
    while (!isAtEnd()) {
        if (previous().type == TokenType::End) return;
        switch (peek().type) {
            case TokenType::Class:
            case TokenType::Function:
            case TokenType::Create:
            case TokenType::If:
            case TokenType::Repeat:
            case TokenType::While:
            case TokenType::For:
            case TokenType::Say:
            case TokenType::Return:
            case TokenType::Set:
            case TokenType::Module:
            case TokenType::Record:
            case TokenType::Enum:
            case TokenType::Import:
            case TokenType::Extern:
            case TokenType::Interface:
            case TokenType::Test:
            case TokenType::Assert:
            case TokenType::Explain:
            case TokenType::Try:
            case TokenType::Raise:
                return;
            default:
                break;
        }
        advance();
    }
}

void Parser::setLoc(ASTNode& node) const {
    node.loc.line = previous().line;
    node.loc.column = previous().column;
}

bool Parser::matchName(std::string& out) {
    if (match(TokenType::Identifier)) {
        out = previous().lexeme;
        return true;
    }

    static const std::unordered_set<TokenType> usableAsName = {
        TokenType::Add, TokenType::List, TokenType::Set, TokenType::Ask,
        TokenType::Use, TokenType::Module, TokenType::Record, TokenType::Field,
        TokenType::Import, TokenType::While, TokenType::Do, TokenType::For,
        TokenType::Each, TokenType::In, TokenType::Stop, TokenType::Skip,
        TokenType::Else, TokenType::Empty, TokenType::Length, TokenType::Of,
        TokenType::Public, TokenType::Private, TokenType::New
    };

    if (!isAtEnd() && usableAsName.count(peek().type)) {
        out = peek().lexeme;
        advance();
        return true;
    }
    return false;
}

const Token& Parser::consumeName(const std::string& message) {
    std::string name;
    if (!matchName(name)) {
        error(message);
    }
    return previous();
}

// ── Programme ─────────────────────────────────────────────────────────────────

std::unique_ptr<ProgramNode> Parser::parseProgram() {
    std::vector<std::unique_ptr<ImportNode>> imports;
    std::vector<std::unique_ptr<ModuleNode>> modules;
    std::vector<std::unique_ptr<InterfaceNode>> interfaces;
    std::vector<std::unique_ptr<RecordNode>> records;
    std::vector<std::unique_ptr<EnumNode>> enums;
    std::vector<std::unique_ptr<ClassNode>> classes;
    std::vector<std::unique_ptr<FunctionNode>> functions;
    std::vector<std::unique_ptr<TestNode>> tests;
    std::vector<std::unique_ptr<ExternDeclNode>> externs;
    std::vector<std::unique_ptr<StatementNode>> statements;

    while (!isAtEnd()) {
        try {
            if (match(TokenType::Import)) {
                imports.push_back(parseImport());
            } else if (match(TokenType::Extern)) {
                externs.push_back(parseExtern());
            } else if (match(TokenType::Module)) {
                modules.push_back(parseModule());
            } else if (match(TokenType::Interface)) {
                interfaces.push_back(parseInterface());
            } else if (match(TokenType::Record)) {
                records.push_back(parseRecord());
            } else if (match(TokenType::Enum)) {
                enums.push_back(parseEnum());
            } else if (match(TokenType::Class)) {
                classes.push_back(parseClass());
            } else if (match(TokenType::Function)) {
                functions.push_back(parseFunction());
            } else if (match(TokenType::Test)) {
                tests.push_back(parseTest());
            } else {
                statements.push_back(parseStatement());
            }
        } catch (const CompileError&) {
            synchronize();
            throw;
        }
    }

    return std::make_unique<ProgramNode>(
        std::move(imports), std::move(modules), std::move(interfaces),
        std::move(records), std::move(enums), std::move(classes), std::move(functions),
        std::move(tests), std::move(externs), std::move(statements));
}

std::unique_ptr<ExternDeclNode> Parser::parseExtern() {
    consume(TokenType::From, "'from' attendu après 'extern'");
    const Token& libToken = consume(TokenType::StringLiteral, "Nom de bibliothèque attendu");
    consume(TokenType::Function, "'function' attendu dans la déclaration extern");
    const Token& nameToken = consumeName("Nom de fonction extern attendu");

    consume(TokenType::LeftParen, "'(' attendu");
    std::vector<ParameterNode> params = parseParameters();
    consume(TokenType::RightParen, "')' attendu");

    std::string returnType;
    if (match(TokenType::Returns)) {
        returnType = parseTypeName();
    }

    auto node = std::make_unique<ExternDeclNode>(
        libToken.lexeme, nameToken.lexeme, std::move(params), std::move(returnType));
    setLoc(*node);
    return node;
}

bool Parser::matchToOrThan() {
    return match(TokenType::To) || match(TokenType::Than);
}

void Parser::consumeToOrThan(const std::string& message) {
    if (!matchToOrThan()) error(message);
}

void Parser::consumeIntoOrEn(const std::string& message) {
    if (!match(TokenType::Into)) {
        error(message);
    }
}

std::unique_ptr<StatementNode> Parser::parseExplainStatement() {
    auto inner = parseStatement();
    auto node = std::make_unique<ExplainStatementNode>(std::move(inner));
    setLoc(*node);
    return node;
}

std::unique_ptr<ImportNode> Parser::parseImport() {
    const Token& pathToken = consume(TokenType::StringLiteral, "Chemin de fichier attendu après 'import'");
    auto node = std::make_unique<ImportNode>(pathToken.lexeme);
    setLoc(*node);
    return node;
}

std::unique_ptr<ModuleNode> Parser::parseModule() {
    const Token& nameToken = consumeName( "Nom de module attendu après 'module'");
    std::string moduleName = nameToken.lexeme;

    std::vector<std::unique_ptr<ClassNode>> classes;
    std::vector<std::unique_ptr<RecordNode>> records;
    std::vector<std::unique_ptr<FunctionNode>> functions;

    while (!check(TokenType::End) && !isAtEnd()) {
        if (match(TokenType::Class)) {
            classes.push_back(parseClass());
        } else if (match(TokenType::Record)) {
            records.push_back(parseRecord());
        } else if (match(TokenType::Function)) {
            functions.push_back(parseFunction());
        } else {
            error("Déclaration attendue dans le module (class, record, function)");
        }
    }

    consume(TokenType::End, "'end' attendu pour fermer le module");
    auto node = std::make_unique<ModuleNode>(
        std::move(moduleName), std::move(classes), std::move(records), std::move(functions));
    node->loc = {nameToken.line, nameToken.column};
    return node;
}

std::unique_ptr<InterfaceNode> Parser::parseInterface() {
    const Token& nameToken = consumeName("Nom d'interface attendu après 'interface'");
    std::vector<std::unique_ptr<FunctionNode>> methods;

    while (!check(TokenType::End) && !isAtEnd()) {
        consume(TokenType::Function, "Signature 'function' attendue dans l'interface");
        methods.push_back(parseFunction(true));
    }

    consume(TokenType::End, "'end' attendu pour fermer l'interface");
    auto node = std::make_unique<InterfaceNode>(nameToken.lexeme, std::move(methods));
    node->loc = {nameToken.line, nameToken.column};
    return node;
}

std::unique_ptr<TestNode> Parser::parseTest() {
    const Token& nameToken = consume(TokenType::StringLiteral, "Nom de test attendu (chaîne)");
    std::vector<std::unique_ptr<StatementNode>> body = parseBlock();
    consume(TokenType::End, "'end' attendu pour fermer le test");
    auto node = std::make_unique<TestNode>(nameToken.lexeme, std::move(body));
    node->loc = {nameToken.line, nameToken.column};
    return node;
}

std::unique_ptr<RecordNode> Parser::parseRecord() {
    const Token& nameToken = consumeName( "Nom de record attendu après 'record'");

    std::vector<FieldNode> fields;
    while (!check(TokenType::End) && !isAtEnd()) {
        fields.push_back(parseField());
    }

    consume(TokenType::End, "'end' attendu pour fermer le record");
    auto node = std::make_unique<RecordNode>(nameToken.lexeme, std::move(fields));
    node->loc = {nameToken.line, nameToken.column};
    return node;
}

std::unique_ptr<EnumNode> Parser::parseEnum() {
    const Token& nameToken = consumeName("Nom d'enum attendu après 'enum'");

    std::vector<EnumCaseNode> cases;
    while (!check(TokenType::End) && !isAtEnd()) {
        consume(TokenType::Case, "'case' attendu dans l'enum");
        const Token& caseToken = consumeName("Nom de cas attendu");

        std::vector<FieldNode> fields;
        if (match(TokenType::With)) {
            do {
                const Token& fieldName = consumeName("Nom de champ attendu");
                std::string typeName = parseTypeName();
                fields.emplace_back(fieldName.lexeme, std::move(typeName), true);
            } while (match(TokenType::Comma));
        }
        cases.emplace_back(caseToken.lexeme, std::move(fields));
    }

    consume(TokenType::End, "'end' attendu pour fermer l'enum");
    enumNames_.insert(nameToken.lexeme);
    auto node = std::make_unique<EnumNode>(nameToken.lexeme, std::move(cases));
    node->loc = {nameToken.line, nameToken.column};
    return node;
}

FieldNode Parser::parseField() {
    bool isPublic = true;
    if (match(TokenType::Public)) {
        isPublic = true;
    } else if (match(TokenType::Private)) {
        isPublic = false;
    }

    consume(TokenType::Field, "'field' attendu");
    const Token& nameToken = consumeName( "Nom de champ attendu");
    std::string typeName = parseTypeName();
    return FieldNode(nameToken.lexeme, std::move(typeName), isPublic);
}

std::unique_ptr<ClassNode> Parser::parseClass() {
    const Token& nameToken = consumeName( "Nom de classe attendu après 'class'");
    std::string className = nameToken.lexeme;

    std::string baseClass;
    if (match(TokenType::Extends)) {
        const Token& baseToken = consumeName("Nom de classe de base attendu après 'extends'");
        baseClass = baseToken.lexeme;
    }

    std::vector<std::string> interfaceNames;
    if (match(TokenType::Implements)) {
        do {
            const Token& ifaceToken = consumeName("Nom d'interface attendu après 'implements'");
            interfaceNames.push_back(ifaceToken.lexeme);
        } while (match(TokenType::Comma));
    }

    std::vector<FieldNode> fields;
    std::vector<std::unique_ptr<FunctionNode>> methods;

    while (!check(TokenType::End) && !isAtEnd()) {
        if (matchOneOf(TokenType::Public, TokenType::Private)) {
            bool isPublic = previous().type == TokenType::Public;
            consume(TokenType::Field, "'field' attendu");
            const Token& fieldName = consumeName( "Nom de champ attendu");
            std::string typeName = parseTypeName();
            fields.emplace_back(fieldName.lexeme, std::move(typeName), isPublic);
        } else {
            consume(TokenType::Function, "Méthode 'function' attendue dans la classe");
            methods.push_back(parseFunction());
        }
    }

    consume(TokenType::End, "'end' attendu pour fermer la classe");
    auto node = std::make_unique<ClassNode>(
        std::move(className), std::move(baseClass), std::move(interfaceNames),
        std::move(fields), std::move(methods));
    node->loc = {nameToken.line, nameToken.column};
    return node;
}

std::vector<std::string> Parser::parseTypeParams() {
    if (!match(TokenType::AngleOpen)) return {};

    std::vector<std::string> params;
    do {
        const Token& param = consumeName("Nom de paramètre de type attendu");
        params.push_back(param.lexeme);
    } while (match(TokenType::Comma));

    consume(TokenType::AngleClose, "'>' attendu après les paramètres de type");
    return params;
}

std::string Parser::parseTypeName() {
    std::string base;
    if (match(TokenType::TypeNumber)) base = "number";
    else if (match(TokenType::TypeText))   base = "text";
    else if (match(TokenType::TypeBool))   base = "bool";
    else if (match(TokenType::List)) {
        match(TokenType::Of);
        std::string elementType = parseTypeName();
        return "list " + elementType;
    }
    else if (match(TokenType::Map)) {
        match(TokenType::Of);
        std::string keyType = parseTypeName();
        consume(TokenType::To, "'to' attendu dans le type map");
        std::string valueType = parseTypeName();
        return "map " + keyType + " to " + valueType;
    }
    else if (match(TokenType::Identifier)) base = previous().lexeme;
    else if (matchName(base)) { /* ok */ }
    else error("Type attendu (number, text, bool, list, ou nom de classe/record/enum)");

    if (match(TokenType::Question)) base += "?";
    return base;
}

std::vector<ParameterNode> Parser::parseParameters() {
    std::vector<ParameterNode> params;

    if (check(TokenType::RightParen)) return params;

    do {
        const Token& nameToken = consumeName( "Nom de paramètre attendu");
        std::string typeName = parseTypeName();
        params.emplace_back(nameToken.lexeme, std::move(typeName));
    } while (match(TokenType::Comma));

    return params;
}

std::unique_ptr<FunctionNode> Parser::parseFunction(bool signatureOnly) {
    const Token& nameToken = consumeName("Nom de fonction attendu");
    std::string funcName = nameToken.lexeme;
    std::vector<std::string> typeParams = parseTypeParams();

    consume(TokenType::LeftParen, "'(' attendu après le nom de la fonction");
    std::vector<ParameterNode> params = parseParameters();
    consume(TokenType::RightParen, "')' attendu");

    std::string returnType;
    bool returnsResult = false;
    if (match(TokenType::Returns)) {
        returnType = parseTypeName();
        if (match(TokenType::Or)) {
            consume(TokenType::ErrorKw, "'error' attendu après 'or'");
            returnsResult = true;
        }
    }

    std::vector<std::unique_ptr<StatementNode>> body;
    if (!signatureOnly) {
        body = parseBlock();
        consume(TokenType::End, "'end' attendu pour fermer la fonction");
    }

    auto node = std::make_unique<FunctionNode>(
        std::move(funcName), std::move(params), std::move(returnType),
        returnsResult, std::move(body), std::move(typeParams));
    node->loc = {nameToken.line, nameToken.column};
    return node;
}

std::vector<std::unique_ptr<StatementNode>> Parser::parseBlock() {
    std::vector<std::unique_ptr<StatementNode>> body;
    while (!check(TokenType::End) && !check(TokenType::Else) &&
           !check(TokenType::Catch) && !isAtEnd()) {
        body.push_back(parseStatement());
    }
    return body;
}

// ── Instructions ──────────────────────────────────────────────────────────────

std::unique_ptr<StatementNode> Parser::parseStatement() {
    if (match(TokenType::Explain))    return parseExplainStatement();
    if (match(TokenType::Say))       return parseSayStatement();
    if (match(TokenType::Create))    return parseCreateStatement();
    if (match(TokenType::Set))       return parseSetStatement();
    if (match(TokenType::Match))     return parseMatchStatement();
    if (match(TokenType::If))        return parseIfStatement();
    if (match(TokenType::While))     return parseWhileStatement();
    if (match(TokenType::Repeat))    return parseRepeatStatement();
    if (match(TokenType::For))       return parseForEachStatement();
    if (match(TokenType::Return))    return parseReturnStatement();
    if (match(TokenType::Assert))    return parseAssertStatement();
    if (match(TokenType::Ask))       return parseAskStatement();
    if (match(TokenType::Use))       return parseUseStatement();
    if (match(TokenType::Try))       return parseTryStatement();
    if (match(TokenType::Raise))     return parseRaiseStatement();
    if (match(TokenType::Add))       return parseAddToListStatement();
    if (match(TokenType::Stop)) {
        auto node = std::make_unique<BreakStatementNode>();
        setLoc(*node);
        return node;
    }
    if (match(TokenType::Skip)) {
        auto node = std::make_unique<ContinueStatementNode>();
        setLoc(*node);
        return node;
    }
    return parseExpressionStatement();
}

std::unique_ptr<StatementNode> Parser::parseSayStatement() {
    auto value = parseExpression();
    auto node = std::make_unique<SayStatementNode>(std::move(value));
    setLoc(*node);
    return node;
}

std::unique_ptr<StatementNode> Parser::parseCreateStatement() {
    const Token& nameToken = consumeName( "Nom de variable attendu après 'create'");
    std::string typeName;

    if (!check(TokenType::Equals)) {
        typeName = parseTypeName();
    }

    consume(TokenType::Equals, "'=' attendu");

    std::unique_ptr<ExpressionNode> value;
    if (match(TokenType::List)) {
        consume(TokenType::Of, "'of' attendu après 'list'");
        std::vector<std::unique_ptr<ExpressionNode>> elements;
        if (!check(TokenType::End) && !isAtEnd()) {
            do {
                elements.push_back(parseExpression());
            } while (match(TokenType::Comma));
        }
        value = std::make_unique<ListLiteralNode>(std::move(elements));
    } else if (match(TokenType::Map)) {
        consume(TokenType::Of, "'of' attendu après 'map'");
        std::vector<MapPairNode> pairs;
        if (!check(TokenType::End) && !isAtEnd()) {
            do {
                MapPairNode pair;
                pair.key = parseExpression();
                consume(TokenType::To, "'to' attendu dans map of ...");
                pair.value = parseExpression();
                pairs.push_back(std::move(pair));
            } while (match(TokenType::Comma));
        }
        value = std::make_unique<MapLiteralNode>(std::move(pairs));
    } else if (match(TokenType::Empty)) {
        if (match(TokenType::Map)) {
            std::string keyType = parseTypeName();
            consume(TokenType::To, "'to' attendu dans empty map");
            std::string valueType = parseTypeName();
            value = std::make_unique<EmptyMapNode>(std::move(keyType), std::move(valueType));
        } else {
            consume(TokenType::List, "'list' attendu après 'empty'");
            std::string elementType = parseTypeName();
            value = std::make_unique<EmptyListNode>(std::move(elementType));
        }
    } else if (match(TokenType::Nothing)) {
        value = std::make_unique<NothingLiteralNode>();
    } else {
        value = parseExpression();
    }

    auto node = std::make_unique<AssignStatementNode>(
        nameToken.lexeme, std::move(typeName), std::move(value));
    node->loc = {nameToken.line, nameToken.column};
    return node;
}

std::unique_ptr<StatementNode> Parser::parseSetStatement() {
    std::unique_ptr<ExpressionNode> target;

    if (match(TokenType::This)) {
        consume(TokenType::Dot, "'.' attendu après 'this'");
        const Token& member = consumeName( "Nom de champ attendu");
        target = std::make_unique<MemberAccessNode>(
            std::make_unique<ThisExpressionNode>(), member.lexeme);
    } else {
        const Token& nameToken = consumeName( "Nom de variable attendu après 'set'");

        if (match(TokenType::Dot)) {
            const Token& member = consumeName( "Nom de membre attendu");
            target = std::make_unique<MemberAccessNode>(
                std::make_unique<IdentifierNode>(nameToken.lexeme), member.lexeme);
        } else if (match(TokenType::At)) {
            auto object = std::make_unique<IdentifierNode>(nameToken.lexeme);
            auto index = parseExpression();
            consume(TokenType::Equals, "'=' attendu");
            auto value = parseExpression();
            auto node = std::make_unique<IndexAssignStatementNode>(
                std::move(object), std::move(index), std::move(value));
            node->loc = {nameToken.line, nameToken.column};
            return node;
        } else {
            target = std::make_unique<IdentifierNode>(nameToken.lexeme);
        }
    }

    consume(TokenType::Equals, "'=' attendu");
    auto value = parseExpression();
    auto node = std::make_unique<SetStatementNode>(std::move(target), std::move(value));
    setLoc(*node);
    return node;
}

std::unique_ptr<StatementNode> Parser::parseIfStatement() {
    auto condition = parseComparison();
    consume(TokenType::Then, "'then' attendu après la condition");

    std::vector<std::unique_ptr<StatementNode>> thenBody = parseBlock();
    std::vector<std::unique_ptr<StatementNode>> elseBody;

    if (match(TokenType::Else)) {
        elseBody = parseBlock();
    }

    consume(TokenType::End, "'end' attendu pour fermer le bloc 'if'");
    auto node = std::make_unique<IfStatementNode>(
        std::move(condition), std::move(thenBody), std::move(elseBody));
    setLoc(*node);
    return node;
}

std::unique_ptr<StatementNode> Parser::parseWhileStatement() {
    auto condition = parseComparison();
    consume(TokenType::Do, "'do' attendu après la condition");

    std::vector<std::unique_ptr<StatementNode>> body = parseBlock();
    consume(TokenType::End, "'end' attendu pour fermer la boucle 'while'");

    auto node = std::make_unique<WhileStatementNode>(std::move(condition), std::move(body));
    setLoc(*node);
    return node;
}

std::unique_ptr<StatementNode> Parser::parseRepeatStatement() {
    auto count = parseExpression();
    consume(TokenType::Times, "'times' attendu après le nombre de répétitions");

    std::vector<std::unique_ptr<StatementNode>> body = parseBlock();
    consume(TokenType::End, "'end' attendu pour fermer la boucle 'repeat'");

    auto node = std::make_unique<RepeatStatementNode>(std::move(count), std::move(body));
    setLoc(*node);
    return node;
}

std::unique_ptr<StatementNode> Parser::parseForEachStatement() {
    consume(TokenType::Each, "'each' attendu après 'for'");
    const Token& itemToken = consumeName( "Nom de variable attendu après 'each'");
    std::string valueName;
    if (match(TokenType::Comma)) {
        const Token& valueToken = consumeName("Nom de variable attendu après ','");
        valueName = valueToken.lexeme;
    }
    consume(TokenType::In, "'in' attendu");
    auto list = parseExpression();
    consume(TokenType::Do, "'do' attendu");

    std::vector<std::unique_ptr<StatementNode>> body = parseBlock();
    consume(TokenType::End, "'end' attendu pour fermer la boucle 'for each'");

    auto node = std::make_unique<ForEachStatementNode>(
        itemToken.lexeme, std::move(valueName), std::move(list), std::move(body));
    node->loc = {itemToken.line, itemToken.column};
    return node;
}

std::unique_ptr<StatementNode> Parser::parseTryStatement() {
    std::vector<std::unique_ptr<StatementNode>> tryBody = parseBlock();
    consume(TokenType::Catch, "'catch' attendu après le bloc try");
    consume(TokenType::ErrorKw, "'error' attendu après 'catch'");
    const Token& varToken = consumeName("Nom de variable attendu après 'catch error'");
    std::vector<std::unique_ptr<StatementNode>> catchBody = parseBlock();
    consume(TokenType::End, "'end' attendu pour fermer try/catch");

    auto node = std::make_unique<TryStatementNode>(
        std::move(tryBody), varToken.lexeme, std::move(catchBody));
    node->loc = {varToken.line, varToken.column};
    return node;
}

std::unique_ptr<StatementNode> Parser::parseRaiseStatement() {
    auto message = parseExpression();
    auto node = std::make_unique<RaiseStatementNode>(std::move(message));
    setLoc(*node);
    return node;
}

std::unique_ptr<StatementNode> Parser::parseMatchStatement() {
    auto subject = parseExpression();
    std::vector<MatchArmNode> arms;

    while (!check(TokenType::End) && !isAtEnd()) {
        if (match(TokenType::Default)) {
            MatchArmNode arm;
            arm.isDefault = true;
            arm.body = parseBlock();
            consume(TokenType::End, "'end' attendu pour fermer default");
            arms.push_back(std::move(arm));
        } else {
            consume(TokenType::Case, "'case' attendu dans match");
            const Token& caseToken = consumeName("Nom de cas attendu");
            consume(TokenType::Then, "'then' attendu après le cas");
            MatchArmNode arm;
            arm.caseName = caseToken.lexeme;
            arm.body = parseBlock();
            consume(TokenType::End, "'end' attendu pour fermer le case");
            arms.push_back(std::move(arm));
        }
    }

    consume(TokenType::End, "'end' attendu pour fermer match");
    auto node = std::make_unique<MatchStatementNode>(std::move(subject), std::move(arms));
    setLoc(*node);
    return node;
}

std::unique_ptr<StatementNode> Parser::parseReturnStatement() {
    if (match(TokenType::ErrorKw)) {
        auto msg = parseExpression();
        auto node = std::make_unique<ReturnStatementNode>(std::move(msg), true);
        setLoc(*node);
        return node;
    }
    auto value = parseExpression();
    auto node = std::make_unique<ReturnStatementNode>(std::move(value));
    setLoc(*node);
    return node;
}

std::unique_ptr<StatementNode> Parser::parseAssertStatement() {
    auto condition = parseComparison();
    auto node = std::make_unique<AssertStatementNode>(std::move(condition));
    setLoc(*node);
    return node;
}

std::unique_ptr<StatementNode> Parser::parseAskStatement() {
    auto prompt = parseExpression();
    consumeIntoOrEn("'into' ou 'en' attendu après le prompt");
    const Token& varToken = consumeName( "Nom de variable attendu après 'into'");
    auto node = std::make_unique<AskStatementNode>(std::move(prompt), varToken.lexeme);
    node->loc = {varToken.line, varToken.column};
    return node;
}

std::unique_ptr<StatementNode> Parser::parseUseStatement() {
    const Token& nameToken = consumeName( "Nom de module attendu après 'use'");
    auto node = std::make_unique<UseStatementNode>(nameToken.lexeme);
    node->loc = {nameToken.line, nameToken.column};
    return node;
}

std::unique_ptr<StatementNode> Parser::parseAddToListStatement() {
    auto value = parseExpression();
    consumeToOrThan("'to' ou 'à' attendu après la valeur");
    auto list = parseExpression();
    auto node = std::make_unique<AddToListStatementNode>(std::move(value), std::move(list));
    setLoc(*node);
    return node;
}

std::unique_ptr<StatementNode> Parser::parseExpressionStatement() {
    auto expr = parseExpression();
    auto node = std::make_unique<ExpressionStatementNode>(std::move(expr));
    setLoc(*node);
    return node;
}

// ── Expressions ───────────────────────────────────────────────────────────────

std::unique_ptr<ExpressionNode> Parser::parseExpression() {
    return parseComparison();
}

std::unique_ptr<ExpressionNode> Parser::parseComparison() {
    auto left = parseTerm();

    if (match(TokenType::Is)) {
        if (match(TokenType::ErrorKw)) {
            return std::make_unique<IsErrorCheckNode>(std::move(left));
        }
        if (match(TokenType::Defined)) {
            return std::make_unique<IsDefinedCheckNode>(std::move(left));
        }

        std::string op;

        if (match(TokenType::Greater)) {
            consumeToOrThan("'than' attendu après 'greater'");
            op = ">";
        } else if (match(TokenType::Less)) {
            consumeToOrThan("'than' attendu après 'less'");
            op = "<";
        } else if (match(TokenType::Equal)) {
            consumeToOrThan("'to' attendu après 'equal'");
            op = "==";
        } else if (match(TokenType::Not)) {
            consume(TokenType::Equal, "'equal' attendu après 'not'");
            consumeToOrThan("'to' attendu après 'equal'");
            op = "!=";
        } else {
            error("Comparateur attendu après 'is' (greater than, less than, equal to, not equal to)");
        }

        auto right = parseTerm();
        return std::make_unique<BinaryOpNode>(op, std::move(left), std::move(right));
    }

    if (match(TokenType::And)) {
        auto right = parseComparison();
        return std::make_unique<BinaryOpNode>("&&", std::move(left), std::move(right));
    }

    if (match(TokenType::Or)) {
        auto right = parseComparison();
        return std::make_unique<BinaryOpNode>("||", std::move(left), std::move(right));
    }

    return left;
}

std::unique_ptr<ExpressionNode> Parser::parseTerm() {
    auto expr = parseFactor();

    while (matchOneOf(TokenType::Plus, TokenType::Minus)) {
        std::string op = previous().lexeme;
        auto right = parseFactor();
        expr = std::make_unique<BinaryOpNode>(op, std::move(expr), std::move(right));
    }

    return expr;
}

std::unique_ptr<ExpressionNode> Parser::parseFactor() {
    auto expr = parseUnary();

    while (matchOneOf(TokenType::Star, TokenType::Slash)) {
        std::string op = previous().lexeme;
        auto right = parseUnary();
        expr = std::make_unique<BinaryOpNode>(op, std::move(expr), std::move(right));
    }

    return expr;
}

std::unique_ptr<ExpressionNode> Parser::parseUnary() {
    if (match(TokenType::Minus)) {
        return std::make_unique<UnaryOpNode>("-", parseUnary());
    }
    if (match(TokenType::Not)) {
        return std::make_unique<UnaryOpNode>("!", parseUnary());
    }
    return parsePrimary();
}

std::unique_ptr<ExpressionNode> Parser::parseListLiteral() {
    std::vector<std::unique_ptr<ExpressionNode>> elements;
    if (!check(TokenType::RightBracket)) {
        do {
            elements.push_back(parseExpression());
        } while (match(TokenType::Comma));
    }
    consume(TokenType::RightBracket, "']' attendu");
    return std::make_unique<ListLiteralNode>(std::move(elements));
}

std::unique_ptr<ExpressionNode> Parser::parseStringExpression(const std::string& raw) {
    if (raw.find('{') == std::string::npos) {
        return std::make_unique<StringLiteralNode>(raw);
    }

    auto isIdent = [](const std::string& text) {
        if (text.empty()) return false;
        if (!std::isalpha(static_cast<unsigned char>(text[0])) && text[0] != '_') {
            return false;
        }
        for (char c : text) {
            if (!std::isalnum(static_cast<unsigned char>(c)) && c != '_') return false;
        }
        return true;
    };

    std::vector<std::unique_ptr<ExpressionNode>> parts;
    std::size_t i = 0;
    while (i < raw.size()) {
        if (raw[i] == '{') {
            const std::size_t close = raw.find('}', i);
            if (close == std::string::npos) {
                error("Accolade '}' manquante dans la chaîne interpolée");
            }
            const std::string exprSource = raw.substr(i + 1, close - i - 1);
            if (isIdent(exprSource)) {
                Lexer subLexer(exprSource);
                Parser subParser(subLexer.tokenize());
                parts.push_back(subParser.parseExpression());
                i = close + 1;
                continue;
            }
            parts.push_back(std::make_unique<StringLiteralNode>(
                raw.substr(i, close - i + 1)));
            i = close + 1;
            continue;
        }

        const std::size_t next = raw.find('{', i);
        const std::size_t end = (next == std::string::npos) ? raw.size() : next;
        const std::string text = raw.substr(i, end - i);
        if (!text.empty()) {
            parts.push_back(std::make_unique<StringLiteralNode>(text));
        }
        i = end;
    }

    if (parts.empty()) {
        return std::make_unique<StringLiteralNode>("");
    }
    if (parts.size() == 1 && dynamic_cast<const StringLiteralNode*>(parts[0].get())) {
        return std::move(parts[0]);
    }
    return std::make_unique<InterpolatedStringNode>(std::move(parts));
}

std::unique_ptr<ExpressionNode> Parser::parsePrimary() {
    if (match(TokenType::StringLiteral)) {
        return parseStringExpression(previous().lexeme);
    }

    if (match(TokenType::NumberLiteral)) {
        return std::make_unique<NumberLiteralNode>(std::stod(previous().lexeme));
    }

    if (matchOneOf(TokenType::True, TokenType::Yes)) {
        return std::make_unique<BoolLiteralNode>(true);
    }

    if (match(TokenType::Nothing)) {
        return std::make_unique<NothingLiteralNode>();
    }

    if (matchOneOf(TokenType::False, TokenType::No)) {
        return std::make_unique<BoolLiteralNode>(false);
    }

    if (match(TokenType::This)) {
        return std::make_unique<ThisExpressionNode>();
    }

    if (match(TokenType::Empty)) {
        if (match(TokenType::Map)) {
            std::string keyType = parseTypeName();
            consume(TokenType::To, "'to' attendu dans empty map");
            std::string valueType = parseTypeName();
            return std::make_unique<EmptyMapNode>(std::move(keyType), std::move(valueType));
        }
        consume(TokenType::List, "'list' attendu après 'empty'");
        std::string elementType = parseTypeName();
        return std::make_unique<EmptyListNode>(std::move(elementType));
    }

    if (match(TokenType::Length)) {
        consume(TokenType::Of, "'of' attendu après 'length'");
        auto object = parsePrimary();
        return std::make_unique<LengthExpressionNode>(std::move(object));
    }

    if (match(TokenType::New)) {
        const Token& classToken = consumeName( "Nom de classe attendu après 'new'");
        return std::make_unique<NewExpressionNode>(classToken.lexeme);
    }

    if (match(TokenType::LeftBracket)) {
        return parseListLiteral();
    }

    if (match(TokenType::LeftParen)) {
        auto expr = parseExpression();
        consume(TokenType::RightParen, "')' attendu");
        return finishCall(std::move(expr));
    }

    if (match(TokenType::Identifier)) {
        auto expr = std::make_unique<IdentifierNode>(previous().lexeme);

        if (match(TokenType::At)) {
            auto index = parseExpression();
            return std::make_unique<IndexExpressionNode>(std::move(expr), std::move(index));
        }

        return finishCall(std::move(expr));
    }

    {
        std::string name;
        if (matchName(name)) {
            auto expr = std::make_unique<IdentifierNode>(name);

            if (match(TokenType::At)) {
                auto index = parseExpression();
                return std::make_unique<IndexExpressionNode>(std::move(expr), std::move(index));
            }

            return finishCall(std::move(expr));
        }
    }

    error("Expression attendue");
}

std::unique_ptr<ExpressionNode> Parser::parsePostfix(std::unique_ptr<ExpressionNode> expr) {
    while (true) {
        if (match(TokenType::LeftBracket)) {
            auto index = parseExpression();
            consume(TokenType::RightBracket, "']' attendu");
            expr = std::make_unique<IndexExpressionNode>(std::move(expr), std::move(index));
            continue;
        }
        break;
    }
    return expr;
}

std::unique_ptr<ExpressionNode> Parser::finishCall(std::unique_ptr<ExpressionNode> callee) {
    while (true) {
        if (match(TokenType::Dot)) {
            const Token& member = consumeName("Nom de membre attendu après '.'");
            if (auto* id = dynamic_cast<IdentifierNode*>(callee.get());
                id && enumNames_.count(id->name)) {
                std::vector<std::unique_ptr<ExpressionNode>> arguments;
                if (match(TokenType::With)) {
                    do {
                        arguments.push_back(parseExpression());
                    } while (match(TokenType::Comma));
                }
                callee = std::make_unique<EnumCaseExprNode>(
                    id->name, member.lexeme, std::move(arguments));
                continue;
            }
            callee = std::make_unique<MemberAccessNode>(std::move(callee), member.lexeme);
            continue;
        }

        if (match(TokenType::LeftParen)) {
            std::vector<std::unique_ptr<ExpressionNode>> arguments;
            if (!check(TokenType::RightParen)) {
                do {
                    arguments.push_back(parseExpression());
                } while (match(TokenType::Comma));
            }
            consume(TokenType::RightParen, "')' attendu après les arguments");
            callee = std::make_unique<CallExpressionNode>(std::move(callee), std::move(arguments));
            continue;
        }

        if (match(TokenType::LeftBracket)) {
            auto index = parseExpression();
            consume(TokenType::RightBracket, "']' attendu");
            callee = std::make_unique<IndexExpressionNode>(std::move(callee), std::move(index));
            continue;
        }

        break;
    }

    return callee;
}

} // namespace afrilang
