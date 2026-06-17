#pragma once

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
        if (field.find(',') != std::string::npos || field.find('"') != std::string::npos) {
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

} // namespace afrilang::runtime::csv
