#include "afrilang/diagnostics.hpp"

#include "afrilang/i18n.hpp"
#include "afrilang/utf8.hpp"

#include <algorithm>
#include <cstdlib>
#include <sstream>

#if defined(__unix__) || defined(__APPLE__)
#include <unistd.h>
#endif

namespace afrilang {

namespace {

const char* ansiReset() { return "\033[0m"; }
const char* ansiBold() { return "\033[1m"; }
const char* ansiRed() { return "\033[31m"; }
const char* ansiYellow() { return "\033[33m"; }
const char* ansiCyan() { return "\033[36m"; }
const char* ansiBlue() { return "\033[34m"; }

} // namespace

bool diagnosticsUseColor() {
    if (const char* no = std::getenv("NO_COLOR")) {
        if (no[0] != '\0') return false;
    }
    if (const char* forced = std::getenv("AFRILANG_COLOR")) {
        if (forced[0] == '0') return false;
        if (forced[0] == '1') return true;
    }
#if defined(__unix__) || defined(__APPLE__)
    return isatty(STDERR_FILENO) != 0;
#else
    return false;
#endif
}

CompileError::CompileError(std::string message, int line, int column,
                           std::string file, std::string sourceLine,
                           std::vector<std::string> suggestions,
                           ErrorCode code,
                           std::vector<DiagnosticNote> notes,
                           int endLine,
                           int endColumn)
    : std::runtime_error("")
    , message_(std::move(message))
    , line_(line)
    , column_(column)
    , endLine_(endLine)
    , endColumn_(endColumn)
    , file_(std::move(file))
    , sourceLine_(std::move(sourceLine))
    , suggestions_(std::move(suggestions))
    , code_(code)
    , notes_(std::move(notes))
{
    static_cast<std::runtime_error&>(*this) = std::runtime_error(format());
}

Diagnostic CompileError::toDiagnostic() const {
    Diagnostic d;
    d.severity = DiagnosticSeverity::Error;
    d.code = code_;
    d.message = message_;
    d.file = file_;
    d.line = line_;
    d.column = column_;
    d.endLine = endLine_;
    d.endColumn = endColumn_;
    d.sourceLine = sourceLine_;
    d.suggestions = suggestions_;
    d.notes = notes_;
    return d;
}

std::string formatDiagnostic(const Diagnostic& diagnostic) {
    const bool color = diagnosticsUseColor();
    auto styled = [&](const char* style, const std::string& text) -> std::string {
        if (!color) return text;
        return std::string(style) + text + ansiReset();
    };

    std::ostringstream out;
    const std::string header = formatErrorHeader(
        diagnostic.file, diagnostic.line, diagnostic.column, diagnostic.code);
    out << (color ? std::string(ansiBold()) + ansiRed() + header + ansiReset() : header);
    out << "  " << styled(ansiBold(), diagnostic.message) << "\n";

    if (!diagnostic.sourceLine.empty() && diagnostic.line > 0) {
        out << "\n  " << diagnostic.sourceLine << "\n  ";
        const int startCol = std::max(1, diagnostic.column);
        const int endLine = diagnostic.resolvedEndLine();
        const int endCol = diagnostic.resolvedEndColumn();
        const std::size_t caretPos = utf8DisplayWidthBefore(diagnostic.sourceLine, startCol);

        for (std::size_t i = 0; i < caretPos; ++i) out << ' ';

        std::string underline;
        if (endLine > diagnostic.line) {
            underline = "^";
            const std::size_t rest =
                utf8DisplayWidthBefore(diagnostic.sourceLine,
                                       static_cast<int>(diagnostic.sourceLine.size()) + 1);
            for (std::size_t i = caretPos + 1; i < rest && i < caretPos + 16; ++i) {
                underline += '~';
            }
            out << styled(ansiRed(), underline) << "\n";
            const bool en = currentLocale() == Locale::English;
            out << "  " << styled(ansiCyan(),
                (en ? "... through line " : "... jusqu'à la ligne ") +
                std::to_string(endLine) +
                (en ? ", column " : ", colonne ") + std::to_string(endCol)) << "\n";
        } else {
            int span = std::max(1, endCol - startCol);
            if (span > 40) span = 40;
            underline = "^";
            for (int i = 1; i < span; ++i) underline += '~';
            out << styled(ansiRed(), underline) << "\n";
        }
    }

    if (!diagnostic.suggestions.empty()) {
        out << "\n  " << styled(ansiYellow(), formatSuggestionLabel(
                              static_cast<int>(diagnostic.suggestions.size())))
            << "\n";
        for (const auto& s : diagnostic.suggestions) {
            out << "    - " << s << "\n";
        }
    }

    for (const auto& note : diagnostic.notes) {
        out << "  " << styled(ansiBlue(), "help:") << " " << note.message;
        if (!note.file.empty() && note.line > 0) {
            out << " (" << note.file << ":" << note.line << ":" << note.column << ")";
        }
        out << "\n";
    }

    return out.str();
}

std::string CompileError::format() const {
    return formatDiagnostic(toDiagnostic());
}

std::string CompileError::formatJson() const {
    std::ostringstream out;
    out << "{\"code\":\"" << errorCodeString(code_) << "\","
        << "\"message\":\"" << message_ << "\","
        << "\"line\":" << line_ << ","
        << "\"column\":" << column_ << ","
        << "\"endLine\":" << (endLine_ > 0 ? endLine_ : line_) << ","
        << "\"endColumn\":" << (endColumn_ > 0 ? endColumn_ : (column_ > 0 ? column_ + 1 : 1)) << ","
        << "\"file\":\"" << file_ << "\"}";
    return out.str();
}

DiagnosticEngine::DiagnosticEngine(std::size_t errorLimit) : errorLimit_(errorLimit) {}

void DiagnosticEngine::setErrorLimit(std::size_t limit) {
    errorLimit_ = limit == 0 ? kDefaultErrorLimit : limit;
}

void DiagnosticEngine::report(Diagnostic diagnostic) {
    if (diagnostic.severity == DiagnosticSeverity::Error) {
        if (errorCount() >= errorLimit_) {
            if (!errorLimitReached_) {
                errorLimitReached_ = true;
                Diagnostic limitDiag;
                limitDiag.severity = DiagnosticSeverity::Error;
                limitDiag.code = ErrorCode::ResourceLimit;
                limitDiag.message = "Limite d'erreurs atteinte (" +
                                    std::to_string(errorLimit_) +
                                    ") — compilation arrêtée";
                diagnostics_.push_back(std::move(limitDiag));
            }
            return;
        }
    }
    diagnostics_.push_back(std::move(diagnostic));
}

void DiagnosticEngine::report(const CompileError& error) {
    report(error.toDiagnostic());
}

void DiagnosticEngine::reportError(std::string message, int line, int column,
                                   std::string file, std::string sourceLine,
                                   std::vector<std::string> suggestions,
                                   ErrorCode code,
                                   int endLine,
                                   int endColumn) {
    Diagnostic d;
    d.severity = DiagnosticSeverity::Error;
    d.code = code;
    d.message = std::move(message);
    d.file = std::move(file);
    d.line = line;
    d.column = column;
    d.endLine = endLine;
    d.endColumn = endColumn;
    d.sourceLine = std::move(sourceLine);
    d.suggestions = std::move(suggestions);
    report(std::move(d));
}

void DiagnosticEngine::reportWarning(std::string message, int line, int column,
                                     std::string file) {
    Diagnostic d;
    d.severity = DiagnosticSeverity::Warning;
    d.code = ErrorCode::Semantic;
    d.message = std::move(message);
    d.file = std::move(file);
    d.line = line;
    d.column = column;
    report(std::move(d));
}

bool DiagnosticEngine::hasErrors() const {
    for (const auto& d : diagnostics_) {
        if (d.severity == DiagnosticSeverity::Error) return true;
    }
    return false;
}

std::size_t DiagnosticEngine::errorCount() const {
    std::size_t count = 0;
    for (const auto& d : diagnostics_) {
        if (d.severity == DiagnosticSeverity::Error) ++count;
    }
    return count;
}

std::vector<Diagnostic> DiagnosticEngine::errors() const {
    std::vector<Diagnostic> out;
    for (const auto& d : diagnostics_) {
        if (d.severity == DiagnosticSeverity::Error) out.push_back(d);
    }
    return out;
}

std::vector<Diagnostic> DiagnosticEngine::warnings() const {
    std::vector<Diagnostic> out;
    for (const auto& d : diagnostics_) {
        if (d.severity == DiagnosticSeverity::Warning) out.push_back(d);
    }
    return out;
}

std::string DiagnosticEngine::formatAll() const {
    std::ostringstream out;
    for (std::size_t i = 0; i < diagnostics_.size(); ++i) {
        if (i > 0) out << "\n";
        out << formatDiagnostic(diagnostics_[i]);
    }
    const std::size_t errs = errorCount();
    if (errs > 1) {
        const bool en = currentLocale() == Locale::English;
        const bool color = diagnosticsUseColor();
        std::string summary = en
            ? ("error: aborting due to " + std::to_string(errs) + " previous errors\n")
            : ("erreur : arrêt après " + std::to_string(errs) + " erreurs précédentes\n");
        if (color) {
            summary = std::string(ansiBold()) + ansiRed() + summary + ansiReset();
        }
        out << "\n" << summary;
    }
    return out.str();
}

void DiagnosticEngine::clear() {
    diagnostics_.clear();
    errorLimitReached_ = false;
}

std::string SourceFile::lineAt(int line) const {
    if (line <= 0) return "";
    std::istringstream stream(content);
    std::string current;
    for (int i = 1; i <= line && std::getline(stream, current); ++i) {
        if (i == line) return current;
    }
    return "";
}

void SourceManager::addFile(std::string path, std::string content) {
    files_[path] = SourceFile{path, std::move(content)};
}

const SourceFile* SourceManager::getFile(const std::string& path) const {
    auto it = files_.find(path);
    return it != files_.end() ? &it->second : nullptr;
}

const SourceFile* SourceManager::findByPathSuffix(const std::string& suffix) const {
    for (const auto& [path, file] : files_) {
        if (path.size() >= suffix.size() &&
            path.compare(path.size() - suffix.size(), suffix.size(), suffix) == 0) {
            return &file;
        }
    }
    return nullptr;
}

static int levenshtein(const std::string& a, const std::string& b) {
    const std::size_t m = a.size(), n = b.size();
    std::vector<int> prev(n + 1), curr(n + 1);
    for (std::size_t j = 0; j <= n; ++j) prev[j] = static_cast<int>(j);
    for (std::size_t i = 1; i <= m; ++i) {
        curr[0] = static_cast<int>(i);
        for (std::size_t j = 1; j <= n; ++j) {
            const int cost = (a[i - 1] == b[j - 1]) ? 0 : 1;
            curr[j] = std::min({prev[j] + 1, curr[j - 1] + 1, prev[j - 1] + cost});
        }
        prev.swap(curr);
    }
    return prev[n];
}

std::vector<std::string> findSimilarNames(const std::string& name,
                                          const std::vector<std::string>& candidates,
                                          int maxResults) {
    struct Scored {
        std::string name;
        int distance;
    };
    std::vector<Scored> scored;
    scored.reserve(candidates.size());

    for (const auto& candidate : candidates) {
        if (candidate == name) continue;
        const int dist = levenshtein(name, candidate);
        if (dist <= static_cast<int>(name.size()) + 2) {
            scored.push_back({candidate, dist});
        }
    }

    std::sort(scored.begin(), scored.end(),
              [](const Scored& a, const Scored& b) { return a.distance < b.distance; });

    std::vector<std::string> results;
    for (int i = 0; i < maxResults && i < static_cast<int>(scored.size()); ++i) {
        results.push_back(formatDidYouMean(scored[static_cast<std::size_t>(i)].name));
    }
    return results;
}

} // namespace afrilang
