#include "afrilang/lexer.hpp"

#include "afrilang/error.hpp"

#include <cctype>

namespace afrilang {

const std::unordered_map<std::string, TokenType> Lexer::keywords_ = {
    {"class",    TokenType::Class},
    {"function", TokenType::Function},
    {"end",      TokenType::End},
    {"create",   TokenType::Create},
    {"new",      TokenType::New},
    {"if",       TokenType::If},
    {"then",     TokenType::Then},
    {"else",     TokenType::Else},
    {"repeat",   TokenType::Repeat},
    {"times",    TokenType::Times},
    {"say",      TokenType::Say},
    {"is",       TokenType::Is},
    {"greater",  TokenType::Greater},
    {"than",     TokenType::Than},
    {"less",     TokenType::Less},
    {"equal",    TokenType::Equal},
    {"to",       TokenType::To},
    {"and",      TokenType::And},
    {"or",       TokenType::Or},
    {"not",      TokenType::Not},
    {"extends",  TokenType::Extends},
    {"returns",  TokenType::Returns},
    {"return",   TokenType::Return},
    {"number",   TokenType::TypeNumber},
    {"text",     TokenType::TypeText},
    {"bool",     TokenType::TypeBool},
    {"while",    TokenType::While},
    {"do",       TokenType::Do},
    {"for",      TokenType::For},
    {"each",     TokenType::Each},
    {"in",       TokenType::In},
    {"stop",     TokenType::Stop},
    {"skip",     TokenType::Skip},
    {"module",   TokenType::Module},
    {"use",      TokenType::Use},
    {"import",   TokenType::Import},
    {"export",   TokenType::Export},
    {"record",   TokenType::Record},
    {"field",    TokenType::Field},
    {"public",   TokenType::Public},
    {"private",  TokenType::Private},
    {"set",      TokenType::Set},
    {"this",     TokenType::This},
    {"ask",      TokenType::Ask},
    {"into",     TokenType::Into},
    {"at",       TokenType::At},
    {"add",      TokenType::Add},
    {"length",   TokenType::Length},
    {"of",       TokenType::Of},
    {"empty",    TokenType::Empty},
    {"list",     TokenType::List},
    {"true",     TokenType::True},
    {"false",    TokenType::False},
    {"yes",      TokenType::Yes},
    {"no",       TokenType::No},
    {"interface", TokenType::Interface},
    {"implements", TokenType::Implements},
    {"test",     TokenType::Test},
    {"assert",   TokenType::Assert},
    {"error",    TokenType::ErrorKw},
    {"extern",   TokenType::Extern},
    {"from",     TokenType::From},
    {"explain",  TokenType::Explain},
    {"enum",     TokenType::Enum},
    {"case",     TokenType::Case},
    {"match",    TokenType::Match},
    {"default",  TokenType::Default},
    {"with",     TokenType::With},
    {"nothing",  TokenType::Nothing},
    {"defined",  TokenType::Defined},
    {"map",      TokenType::Map},
    {"try",      TokenType::Try},
    {"catch",    TokenType::Catch},
    {"raise",    TokenType::Raise},
    {"const",    TokenType::Const},
    {"step",     TokenType::Step},
    {"filter",   TokenType::Filter},
    {"reduce",   TokenType::Reduce},
    {"where",    TokenType::Where},
    {"flatMap",  TokenType::FlatMap},
    {"super",    TokenType::Super},
    {"static",   TokenType::Static},
    {"abstract", TokenType::Abstract},
    {"protected", TokenType::Protected},
    {"final",     TokenType::Final},
    {"property",  TokenType::Property},
    {"destroy",   TokenType::Destroy},
    {"async",     TokenType::Async},
    {"await",     TokenType::Await},
    {"task",      TokenType::Task},
    {"open",      TokenType::Open},
    {"window",    TokenType::Window},
    {"titled",    TokenType::Titled},
    {"draw",      TokenType::Draw},
    {"button",    TokenType::Button},
    {"clicked",   TokenType::Clicked},
    {"background", TokenType::Background},
    {"frame",     TokenType::Frame},
    {"color",     TokenType::Color},
    {"width",     TokenType::Width},
    {"height",    TokenType::Height},
    {"size",      TokenType::Size},
    {"close",     TokenType::Close},
    {"show",      TokenType::Show},
    {"clear",     TokenType::Clear},

    // Alias français (mots-clés bilingues)
    {"fin",       TokenType::End},
    {"classe",    TokenType::Class},
    {"fonction",  TokenType::Function},
    {"creer",     TokenType::Create},
    {"dire",      TokenType::Say},
    {"si",        TokenType::If},
    {"alors",     TokenType::Then},
    {"sinon",     TokenType::Else},
    {"tantque",   TokenType::While},
    {"faire",     TokenType::Do},
    {"pour",      TokenType::For},
    {"chaque",    TokenType::Each},
    {"dans",      TokenType::In},
    {"retourner", TokenType::Return},
    {"renvoyer",  TokenType::Return},
    {"vrai",      TokenType::True},
    {"faux",      TokenType::False},
    {"utiliser",  TokenType::Use},
    {"importer",  TokenType::Import},
    {"exporter",  TokenType::Export},
    {"en",        TokenType::Into},
    {"et",        TokenType::And},
    {"ou",        TokenType::Or},
    {"avec",      TokenType::With},
    {"defaut",    TokenType::Default},
    {"cas",       TokenType::Case},
    {"essayer",   TokenType::Try},
    {"attraper",  TokenType::Catch},
    {"lever",     TokenType::Raise},
    {"depuis",    TokenType::From},
    {"prive",     TokenType::Private},
    {"protege",   TokenType::Protected},
    {"abstrait",  TokenType::Abstract},
    {"statique",  TokenType::Static},
    {"fini",      TokenType::Final},
    {"propriete", TokenType::Property},
    {"detruire",  TokenType::Destroy},
    {"ouvrir",    TokenType::Open},
    {"fenetre",   TokenType::Window},
    {"intitule",  TokenType::Titled},
    {"dessiner",  TokenType::Draw},
    {"bouton",    TokenType::Button},
    {"clique",    TokenType::Clicked},
    {"arriereplan", TokenType::Background},
    {"cadre",     TokenType::Frame},
    {"couleur",   TokenType::Color},
    {"largeur",   TokenType::Width},
    {"hauteur",   TokenType::Height},
    {"taille",    TokenType::Size},
    {"fermer",    TokenType::Close},
    {"afficher",  TokenType::Show},
    {"effacer",   TokenType::Clear},
    {"rien",      TokenType::Nothing},
    {"defini",    TokenType::Defined},
    {"constante", TokenType::Const},
    {"enregistrement", TokenType::Record},
    {"champ",     TokenType::Field},
    {"interface", TokenType::Interface},
    {"implemente", TokenType::Implements},
    {"tester",    TokenType::Test},
    {"verifier",  TokenType::Assert},
    {"erreur",    TokenType::ErrorKw},
    {"externe",   TokenType::Extern},
    {"expliquer", TokenType::Explain},
    {"etend",     TokenType::Extends},
    {"retourne",  TokenType::Returns},
    {"nombre",    TokenType::TypeNumber},
    {"texte",     TokenType::TypeText},
    {"booleen",   TokenType::TypeBool},
    {"liste",     TokenType::List},
    {"vide",      TokenType::Empty},
    {"longueur",  TokenType::Length},
    {"de",        TokenType::Of},
    {"ajouter",   TokenType::Add},
    {"definir",   TokenType::Set},
    {"ceci",      TokenType::This},
    {"demander",  TokenType::Ask},
    {"superieur", TokenType::Greater},
    {"inferieur", TokenType::Less},
    {"egal",      TokenType::Equal},
    {"repeter",   TokenType::Repeat},
    {"fois",      TokenType::Times},
    {"est",       TokenType::Is},
    {"pas",       TokenType::Not},
    {"arreter",   TokenType::Stop},
    {"passer",    TokenType::Skip},
    {"nouveau",   TokenType::New},
    {"carte",     TokenType::Map},
    {"filtrer",   TokenType::Filter},
    {"reduire",   TokenType::Reduce},
    {"etape",     TokenType::Step},
};

Lexer::Lexer(std::string source) : source_(std::move(source)) {}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    tokens.reserve(source_.size() / 4);

    while (!isAtEnd()) {
        skipWhitespace();
        if (isAtEnd()) break;

        const int startLine = line_;
        const int startColumn = column_;
        char c = peek();

        if (c == '"') {
            tokens.push_back(stringLiteral());
        } else if (std::isdigit(static_cast<unsigned char>(c))) {
            tokens.push_back(numberLiteral());
        } else if (std::isalpha(static_cast<unsigned char>(c)) || c == '_') {
            tokens.push_back(identifierOrKeyword());
        } else {
            advance();
            switch (c) {
                case '+': tokens.push_back(makeToken(TokenType::Plus, "+")); break;
                case '-': tokens.push_back(makeToken(TokenType::Minus, "-")); break;
                case '*': tokens.push_back(makeToken(TokenType::Star, "*")); break;
                case '/':
                    if (peek() == '/') {
                        while (!isAtEnd() && peek() != '\n') advance();
                    } else {
                        tokens.push_back(makeToken(TokenType::Slash, "/"));
                    }
                    break;
                case '.': tokens.push_back(makeToken(TokenType::Dot, ".")); break;
                case '=': tokens.push_back(makeToken(TokenType::Equals, "=")); break;
                case ',': tokens.push_back(makeToken(TokenType::Comma, ",")); break;
                case '(': tokens.push_back(makeToken(TokenType::LeftParen, "(")); break;
                case ')': tokens.push_back(makeToken(TokenType::RightParen, ")")); break;
                case '[': tokens.push_back(makeToken(TokenType::LeftBracket, "[")); break;
                case ']': tokens.push_back(makeToken(TokenType::RightBracket, "]")); break;
                case '?': tokens.push_back(makeToken(TokenType::Question, "?")); break;
                case '<': tokens.push_back(makeToken(TokenType::AngleOpen, "<")); break;
                case '>': tokens.push_back(makeToken(TokenType::AngleClose, ">")); break;
                default:
                    throw CompileError(
                        std::string("Caractère inattendu '") + c + "'",
                        startLine, startColumn);
            }
        }
    }

    tokens.push_back(makeToken(TokenType::Eof, ""));
    return tokens;
}

bool Lexer::isAtEnd() const {
    return current_ >= source_.size();
}

char Lexer::peek() const {
    if (isAtEnd()) return '\0';
    return source_[current_];
}

char Lexer::peekNext() const {
    if (current_ + 1 >= source_.size()) return '\0';
    return source_[current_ + 1];
}

char Lexer::advance() {
    char c = source_[current_++];
    if (c == '\n') {
        line_++;
        column_ = 1;
    } else {
        column_++;
    }
    return c;
}

void Lexer::skipWhitespace() {
    while (!isAtEnd()) {
        char c = peek();
        if (c == ' ' || c == '\t' || c == '\r' || c == '\n') {
            advance();
        } else {
            break;
        }
    }
}

Token Lexer::makeToken(TokenType type, std::string lexeme) const {
    return Token(type, std::move(lexeme), line_, column_);
}

Token Lexer::errorToken(const std::string& message) const {
    throw CompileError(message, line_, column_);
}

Token Lexer::stringLiteral() {
    const int startLine = line_;
    const int startColumn = column_;
    advance();

    std::string value;
    while (!isAtEnd() && peek() != '"') {
        char c = advance();
        if (c == '\\' && !isAtEnd()) {
            char esc = advance();
            switch (esc) {
                case 'n':  value += '\n'; break;
                case 't':  value += '\t'; break;
                case '"':  value += '"';  break;
                case '\\': value += '\\'; break;
                default:   value += esc;  break;
            }
        } else if (c == '\n') {
            throw CompileError("Chaîne non terminée", startLine, startColumn);
        } else {
            value += c;
        }
    }

    if (isAtEnd()) {
        throw CompileError("Chaîne non terminée", startLine, startColumn);
    }

    advance();
    return Token(TokenType::StringLiteral, std::move(value), startLine, startColumn);
}

Token Lexer::numberLiteral() {
    const int startLine = line_;
    const int startColumn = column_;

    std::string num;
    while (!isAtEnd() && std::isdigit(static_cast<unsigned char>(peek()))) {
        num += advance();
    }

    if (peek() == '.' && std::isdigit(static_cast<unsigned char>(peekNext()))) {
        num += advance();
        while (!isAtEnd() && std::isdigit(static_cast<unsigned char>(peek()))) {
            num += advance();
        }
    }

    return Token(TokenType::NumberLiteral, std::move(num), startLine, startColumn);
}

Token Lexer::identifierOrKeyword() {
    const int startLine = line_;
    const int startColumn = column_;

    std::string text;
    while (!isAtEnd()) {
        char c = peek();
        if (std::isalnum(static_cast<unsigned char>(c)) || c == '_') {
            text += advance();
        } else {
            break;
        }
    }

    auto it = keywords_.find(text);
    TokenType type = (it != keywords_.end()) ? it->second : TokenType::Identifier;
    return Token(type, std::move(text), startLine, startColumn);
}

} // namespace afrilang
