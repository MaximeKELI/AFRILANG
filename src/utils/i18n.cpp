#include "afrilang/i18n.hpp"

#include <cstdlib>
#include <cctype>

namespace afrilang {

namespace {

Locale g_locale = Locale::French;
bool g_localeInitialized = false;

void initLocaleFromEnv() {
    if (g_localeInitialized) return;
    g_localeInitialized = true;
    if (const char* env = std::getenv("AFRILANG_LOCALE")) {
        std::string v(env);
        for (char& c : v) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        if (v == "en" || v == "english") g_locale = Locale::English;
    }
}

} // namespace

Locale currentLocale() {
    initLocaleFromEnv();
    return g_locale;
}

void setLocale(Locale locale) {
    g_locale = locale;
    g_localeInitialized = true;
}

std::string errorCodeString(ErrorCode code) {
    switch (code) {
        case ErrorCode::Generic: return "E0001";
        case ErrorCode::Lexer: return "E1000";
        case ErrorCode::Parser: return "E2000";
        case ErrorCode::Semantic: return "E3000";
        case ErrorCode::TypeMismatch: return "E3001";
        case ErrorCode::UndeclaredVariable: return "E3002";
        case ErrorCode::ImportNotFound: return "E4000";
        case ErrorCode::InvalidUtf8: return "E5000";
        case ErrorCode::FfiLibraryDenied: return "E6000";
        case ErrorCode::PathTraversal: return "E7000";
    }
    return "E0001";
}

std::string formatErrorHeader(const std::string& file, int line, int column, ErrorCode code) {
    const bool en = currentLocale() == Locale::English;
    const std::string tag = errorCodeString(code);
    if (!file.empty()) {
        return en
            ? "Error [" + tag + "] in " + file + ":" + std::to_string(line) + ":" +
              std::to_string(column) + "\n"
            : "Erreur [" + tag + "] dans " + file + ":" + std::to_string(line) + ":" +
              std::to_string(column) + "\n";
    }
    if (line > 0) {
        return en
            ? "Error [" + tag + "] at line " + std::to_string(line) + ", column " +
              std::to_string(column) + "\n"
            : "Erreur [" + tag + "] ligne " + std::to_string(line) + ", colonne " +
              std::to_string(column) + "\n";
    }
    return en ? "Error [" + tag + "]\n" : "Erreur [" + tag + "]\n";
}

std::string formatSuggestionLabel(int count) {
    const bool en = currentLocale() == Locale::English;
    if (count > 1) return en ? "Suggestions:" : "Suggestions :";
    return en ? "Suggestion:" : "Suggestion :";
}

std::string formatDidYouMean(const std::string& name) {
    const bool en = currentLocale() == Locale::English;
    return en ? ("did you mean '" + name + "'?")
              : ("vouliez-vous dire '" + name + "' ?");
}

} // namespace afrilang
