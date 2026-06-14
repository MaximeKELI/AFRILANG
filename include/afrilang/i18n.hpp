#pragma once

#include <string>
#include <vector>

namespace afrilang {

enum class ErrorCode {
    Generic = 1,
    Lexer = 1000,
    Parser = 2000,
    Semantic = 3000,
    TypeMismatch = 3001,
    UndeclaredVariable = 3002,
    ImportNotFound = 4000,
    InvalidUtf8 = 5000,
    FfiLibraryDenied = 6000,
    PathTraversal = 7000,
};

enum class Locale {
    French,
    English,
};

Locale currentLocale();
void setLocale(Locale locale);

std::string errorCodeString(ErrorCode code);
std::string formatErrorHeader(const std::string& file, int line, int column, ErrorCode code);
std::string formatSuggestionLabel(int count);
std::string formatDidYouMean(const std::string& name);

} // namespace afrilang
