#pragma once

#include "afrilang/i18n.hpp"

#include <cstddef>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

namespace afrilang {

enum class DiagnosticSeverity {
    Error,
    Warning,
};

struct DiagnosticNote {
    std::string message;
    std::string file;
    int line = 0;
    int column = 0;
};

struct Diagnostic {
    DiagnosticSeverity severity = DiagnosticSeverity::Error;
    ErrorCode code = ErrorCode::Generic;
    std::string message;
    std::string file;
    int line = 0;
    int column = 0;
    std::string sourceLine;
    std::vector<std::string> suggestions;
    std::vector<DiagnosticNote> notes;
};

class CompileError : public std::runtime_error {
public:
    CompileError(std::string message, int line, int column,
                 std::string file = "",
                 std::string sourceLine = "",
                 std::vector<std::string> suggestions = {},
                 ErrorCode code = ErrorCode::Generic);

    int line() const { return line_; }
    int column() const { return column_; }
    const std::string& file() const { return file_; }
    const std::string& messageText() const { return message_; }
    const std::string& sourceLine() const { return sourceLine_; }
    const std::vector<std::string>& suggestions() const { return suggestions_; }
    ErrorCode code() const { return code_; }

    Diagnostic toDiagnostic() const;
    std::string format() const;
    std::string formatJson() const;

private:
    std::string message_;
    int line_;
    int column_;
    std::string file_;
    std::string sourceLine_;
    std::vector<std::string> suggestions_;
    ErrorCode code_;
};

class DiagnosticEngine {
public:
    static constexpr std::size_t kDefaultErrorLimit = 32;

    explicit DiagnosticEngine(std::size_t errorLimit = kDefaultErrorLimit);

    void report(Diagnostic diagnostic);
    void report(const CompileError& error);
    void reportError(std::string message, int line, int column,
                     std::string file = "",
                     std::string sourceLine = "",
                     std::vector<std::string> suggestions = {},
                     ErrorCode code = ErrorCode::Generic);
    void reportWarning(std::string message, int line = 0, int column = 0,
                       std::string file = "");

    bool hasErrors() const;
    bool errorLimitReached() const { return errorLimitReached_; }
    std::size_t errorCount() const;
    const std::vector<Diagnostic>& diagnostics() const { return diagnostics_; }
    std::vector<Diagnostic> errors() const;
    std::vector<Diagnostic> warnings() const;

    std::string formatAll() const;
    void clear();

private:
    std::size_t errorLimit_;
    bool errorLimitReached_ = false;
    std::vector<Diagnostic> diagnostics_;
};

struct LintWarning {
    int line = 0;
    int column = 0;
    std::string message;
    std::string file;
};

struct SourceFile {
    std::string path;
    std::string content;

    std::string lineAt(int line) const;
};

class SourceManager {
public:
    void addFile(std::string path, std::string content);
    const SourceFile* getFile(const std::string& path) const;
    const SourceFile* findByPathSuffix(const std::string& suffix) const;

    const std::unordered_map<std::string, SourceFile>& files() const { return files_; }

private:
    std::unordered_map<std::string, SourceFile> files_;
};

std::string formatDiagnostic(const Diagnostic& diagnostic);
std::vector<std::string> findSimilarNames(const std::string& name,
                                          const std::vector<std::string>& candidates,
                                          int maxResults = 3);

} // namespace afrilang
