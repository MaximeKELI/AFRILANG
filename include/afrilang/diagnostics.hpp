#pragma once

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
                 std::vector<std::string> suggestions = {});

    int line() const { return line_; }
    int column() const { return column_; }
    const std::string& file() const { return file_; }
    const std::vector<std::string>& suggestions() const { return suggestions_; }

    std::string format() const;

private:
    std::string message_;
    int line_;
    int column_;
    std::string file_;
    std::string sourceLine_;
    std::vector<std::string> suggestions_;
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
