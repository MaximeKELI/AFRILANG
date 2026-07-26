#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

namespace afrilang::runtime::csv {

inline std::vector<std::string> splitLine(const std::string& line) {
    std::vector<std::string> fields;
    std::string current;
    bool inQuotes = false;
    for (std::size_t i = 0; i < line.size(); ++i) {
        const char c = line[i];
        if (c == '"') {
            if (inQuotes && i + 1 < line.size() && line[i + 1] == '"') {
                current.push_back('"');
                ++i;
            } else {
                inQuotes = !inQuotes;
            }
        } else if (c == ',' && !inQuotes) {
            fields.push_back(current);
            current.clear();
        } else {
            current.push_back(c);
        }
    }
    fields.push_back(current);
    return fields;
}

inline std::string joinFields(const std::vector<std::string>& fields) {
    std::ostringstream out;
    for (std::size_t i = 0; i < fields.size(); ++i) {
        if (i > 0) out << ',';
        const std::string& field = fields[i];
        if (field.find(',') != std::string::npos || field.find('"') != std::string::npos ||
            field.find('\n') != std::string::npos) {
            out << '"';
            for (char c : field) {
                if (c == '"') out << "\"\"";
                else out << c;
            }
            out << '"';
        } else {
            out << field;
        }
    }
    return out.str();
}

inline std::string readText(const std::string& path) {
    std::ifstream file(path);
    if (!file) return "";
    std::ostringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

inline bool writeText(const std::string& path, const std::string& content) {
    std::ofstream file(path);
    if (!file) return false;
    file << content;
    return static_cast<bool>(file);
}

inline std::vector<std::string> readRows(const std::string& path) {
    std::vector<std::string> rows;
    const std::string text = readText(path);
    if (text.empty()) return rows;
    std::string line;
    for (char c : text) {
        if (c == '\n') {
            if (!line.empty() && line.back() == '\r') line.pop_back();
            rows.push_back(line);
            line.clear();
        } else {
            line.push_back(c);
        }
    }
    if (!line.empty()) {
        if (line.back() == '\r') line.pop_back();
        rows.push_back(line);
    }
    return rows;
}

inline std::string headerRow(const std::string& path) {
    const auto rows = readRows(path);
    return rows.empty() ? "" : rows.front();
}

inline double rowCount(const std::string& path) {
    return static_cast<double>(readRows(path).size());
}

} // namespace afrilang::runtime::csv
