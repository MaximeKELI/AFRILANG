#include "afrilang/diagnostics.hpp"

#include "afrilang/i18n.hpp"
#include "afrilang/utf8.hpp"

#include <algorithm>
#include <cctype>
#include <sstream>

namespace afrilang {

CompileError::CompileError(std::string message, int line, int column,
                           std::string file, std::string sourceLine,
                           std::vector<std::string> suggestions,
                           ErrorCode code)
    : std::runtime_error("")
    , message_(std::move(message))
    , line_(line)
    , column_(column)
    , file_(std::move(file))
    , sourceLine_(std::move(sourceLine))
    , suggestions_(std::move(suggestions))
    , code_(code == static_cast<ErrorCode>(0) ? ErrorCode::Generic : code)
{
    static_cast<std::runtime_error&>(*this) = std::runtime_error(format());
}

std::string CompileError::format() const {
    std::ostringstream out;
    out << formatErrorHeader(file_, line_, column_, code_);
    out << "  " << message_ << "\n";

    if (!sourceLine_.empty()) {
        out << "\n  " << sourceLine_ << "\n  ";
        const std::size_t caretPos = utf8DisplayWidthBefore(sourceLine_, column_);
        for (std::size_t i = 0; i < caretPos; ++i) {
            out << ' ';
        }
        out << "^\n";
    }

    if (!suggestions_.empty()) {
        out << "\n  " << formatSuggestionLabel(static_cast<int>(suggestions_.size())) << "\n";
        for (const auto& s : suggestions_) {
            out << "    - " << s << "\n";
        }
    }

    return out.str();
}

std::string CompileError::formatJson() const {
    std::ostringstream out;
    out << "{\"code\":\"" << errorCodeString(code_) << "\","
        << "\"message\":\"" << message_ << "\","
        << "\"line\":" << line_ << ","
        << "\"column\":" << column_ << ","
        << "\"file\":\"" << file_ << "\"}";
    return out.str();
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
    files_[std::move(path)] = SourceFile{path, std::move(content)};
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
