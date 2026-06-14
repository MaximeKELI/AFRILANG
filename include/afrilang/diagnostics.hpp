#pragma once

#include "afrilang/i18n.hpp"

#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

namespace afrilang {

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
    const std::vector<std::string>& suggestions() const { return suggestions_; }
    ErrorCode code() const { return code_; }

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

std::vector<std::string> findSimilarNames(const std::string& name,
                                          const std::vector<std::string>& candidates,
                                          int maxResults = 3);

} // namespace afrilang
