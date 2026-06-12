#include "afrilang/parser.hpp"

#include "afrilang/error.hpp"

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
            case TokenType::Say:
            case TokenType::Return:
                return;
            default:
                break;
        }
        advance();
    }
}

// ── Programme ─────────────────────────────────────────────────────────────────

std::unique_ptr<ProgramNode> Parser::parseProgram() {
    std::vector<std::unique_ptr<ClassNode>> classes;
    std::vector<std::unique_ptr<FunctionNode>> functions;
    std::vector<std::unique_ptr<StatementNode>> statements;

    while (!isAtEnd()) {
        try {
            if (match(TokenType::Class)) {
                classes.push_back(parseClass());
            } else if (match(TokenType::Function)) {
                functions.push_back(parseFunction());
            } else {
                statements.push_back(parseStatement());
            }
        } catch (const CompileError&) {
            synchronize();
            throw;
        }
    }

    return std::make_unique<ProgramNode>(
        std::move(classes), std::move(functions), std::move(statements));
}

std::unique_ptr<ClassNode> Parser::parseClass() {
    const Token& nameToken = consume(TokenType::Identifier, "Nom de classe attendu après 'class'");
    std::string className = nameToken.lexeme;

    std::string baseClass;
    if (match(TokenType::Extends)) {
        const Token& baseToken = consume(TokenType::Identifier, "Nom de classe de base attendu après 'extends'");
        baseClass = baseToken.lexeme;
    }

    std::vector<std::unique_ptr<FunctionNode>> methods;
    while (!check(TokenType::End) && !isAtEnd()) {
        consume(TokenType::Function, "Méthode 'function' attendue dans la classe");
        methods.push_back(parseFunction());
    }

    consume(TokenType::End, "'end' attendu pour fermer la classe");
    return std::make_unique<ClassNode>(std::move(className), std::move(baseClass), std::move(methods));
}

std::string Parser::parseTypeName() {
    if (match(TokenType::TypeNumber)) return "number";
    if (match(TokenType::TypeText))   return "text";
    if (match(TokenType::Identifier)) return previous().lexeme;
    error("Type attendu (number, text, ou nom de classe)");
}

std::vector<ParameterNode> Parser::parseParameters() {
    std::vector<ParameterNode> params;

    if (check(TokenType::RightParen)) return params;

    do {
        const Token& nameToken = consume(TokenType::Identifier, "Nom de paramètre attendu");
        std::string typeName = parseTypeName();
        params.emplace_back(nameToken.lexeme, std::move(typeName));
    } while (match(TokenType::Comma));

    return params;
}

std::unique_ptr<FunctionNode> Parser::parseFunction() {
    const Token& nameToken = consume(TokenType::Identifier, "Nom de fonction attendu");
    std::string funcName = nameToken.lexeme;

    consume(TokenType::LeftParen, "'(' attendu après le nom de la fonction");
    std::vector<ParameterNode> params = parseParameters();
    consume(TokenType::RightParen, "')' attendu");

    std::string returnType;
    if (match(TokenType::Returns)) {
        returnType = parseTypeName();
    }

    std::vector<std::unique_ptr<StatementNode>> body;
    while (!check(TokenType::End) && !isAtEnd()) {
        body.push_back(parseStatement());
    }

    consume(TokenType::End, "'end' attendu pour fermer la fonction");
    return std::make_unique<FunctionNode>(
        std::move(funcName), std::move(params), std::move(returnType), std::move(body));
}

// ── Instructions ──────────────────────────────────────────────────────────────

std::unique_ptr<StatementNode> Parser::parseStatement() {
    if (match(TokenType::Say))       return parseSayStatement();
    if (match(TokenType::Create))    return parseCreateStatement();
    if (match(TokenType::If))        return parseIfStatement();
    if (match(TokenType::Repeat))    return parseRepeatStatement();
    if (match(TokenType::Return))    return parseReturnStatement();
    return parseExpressionStatement();
}

std::unique_ptr<StatementNode> Parser::parseSayStatement() {
    auto value = parseExpression();
    return std::make_unique<SayStatementNode>(std::move(value));
}

std::unique_ptr<StatementNode> Parser::parseCreateStatement() {
    const Token& nameToken = consume(TokenType::Identifier, "Nom de variable attendu après 'create'");
    consume(TokenType::Equals, "'=' attendu");
    auto value = parseExpression();
    return std::make_unique<AssignStatementNode>(nameToken.lexeme, std::move(value));
}

std::unique_ptr<StatementNode> Parser::parseIfStatement() {
    auto condition = parseComparison();
    consume(TokenType::Then, "'then' attendu après la condition");

    std::vector<std::unique_ptr<StatementNode>> body;
    while (!check(TokenType::End) && !isAtEnd()) {
        body.push_back(parseStatement());
    }

    consume(TokenType::End, "'end' attendu pour fermer le bloc 'if'");
    return std::make_unique<IfStatementNode>(std::move(condition), std::move(body));
}

std::unique_ptr<StatementNode> Parser::parseRepeatStatement() {
    auto count = parseExpression();
    consume(TokenType::Times, "'times' attendu après le nombre de répétitions");

    std::vector<std::unique_ptr<StatementNode>> body;
    while (!check(TokenType::End) && !isAtEnd()) {
        body.push_back(parseStatement());
    }

    consume(TokenType::End, "'end' attendu pour fermer la boucle 'repeat'");
    return std::make_unique<RepeatStatementNode>(std::move(count), std::move(body));
}

std::unique_ptr<StatementNode> Parser::parseReturnStatement() {
    auto value = parseExpression();
    return std::make_unique<ReturnStatementNode>(std::move(value));
}

std::unique_ptr<StatementNode> Parser::parseExpressionStatement() {
    auto expr = parseExpression();
    return std::make_unique<ExpressionStatementNode>(std::move(expr));
}

// ── Expressions ───────────────────────────────────────────────────────────────

std::unique_ptr<ExpressionNode> Parser::parseExpression() {
    return parseComparison();
}

std::unique_ptr<ExpressionNode> Parser::parseComparison() {
    auto left = parseTerm();

    if (match(TokenType::Is)) {
        std::string op;

        if (match(TokenType::Greater)) {
            consume(TokenType::Than, "'than' attendu après 'greater'");
            op = ">";
        } else if (match(TokenType::Less)) {
            consume(TokenType::Than, "'than' attendu après 'less'");
            op = "<";
        } else if (match(TokenType::Equal)) {
            consume(TokenType::To, "'to' attendu après 'equal'");
            op = "==";
        } else if (match(TokenType::Not)) {
            consume(TokenType::Equal, "'equal' attendu après 'not'");
            consume(TokenType::To, "'to' attendu après 'equal'");
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

std::unique_ptr<ExpressionNode> Parser::parsePrimary() {
    if (match(TokenType::StringLiteral)) {
        return std::make_unique<StringLiteralNode>(previous().lexeme);
    }

    if (match(TokenType::NumberLiteral)) {
        return std::make_unique<NumberLiteralNode>(std::stod(previous().lexeme));
    }

    if (match(TokenType::New)) {
        const Token& classToken = consume(TokenType::Identifier, "Nom de classe attendu après 'new'");
        return std::make_unique<NewExpressionNode>(classToken.lexeme);
    }

    if (match(TokenType::LeftParen)) {
        auto expr = parseExpression();
        consume(TokenType::RightParen, "')' attendu");
        return finishCall(std::move(expr));
    }

    if (match(TokenType::Identifier)) {
        auto expr = std::make_unique<IdentifierNode>(previous().lexeme);
        return finishCall(std::move(expr));
    }

    error("Expression attendue");
}

std::unique_ptr<ExpressionNode> Parser::finishCall(std::unique_ptr<ExpressionNode> callee) {
    while (true) {
        if (match(TokenType::Dot)) {
            const Token& member = consume(TokenType::Identifier, "Nom de membre attendu après '.'");
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

        break;
    }

    return callee;
}

} // namespace afrilang
