#pragma once

#include "json.hpp"

#include <sstream>
#include <string>

namespace afrilang::runtime::yaml {

inline json::Value parseSimple(const std::string& text) {
    json::Value root;
    root.kind = json::Value::Kind::Object;
    std::istringstream in(text);
    std::string line;
    while (std::getline(in, line)) {
        if (line.empty() || line[0] == '#') continue;
        const std::size_t colon = line.find(':');
        if (colon == std::string::npos) continue;
        std::string key = line.substr(0, colon);
        std::string value = line.substr(colon + 1);
        while (!key.empty() && key.front() == ' ') key.erase(key.begin());
        while (!key.empty() && key.back() == ' ') key.pop_back();
        while (!value.empty() && value.front() == ' ') value.erase(value.begin());
        while (!value.empty() && value.back() == ' ') value.pop_back();
        if (key.empty()) continue;
        json::Value field;
        if (value == "true" || value == "false") {
            field.kind = json::Value::Kind::Bool;
            field.boolVal = (value == "true");
        } else if (!value.empty() &&
                   (value[0] == '-' || std::isdigit(static_cast<unsigned char>(value[0])))) {
            field.kind = json::Value::Kind::Number;
            field.numberVal = std::stod(value);
        } else {
            field.kind = json::Value::Kind::String;
            if (value.size() >= 2 && value.front() == '"' && value.back() == '"') {
                value = value.substr(1, value.size() - 2);
            }
            field.stringVal = value;
        }
        root.objectVal[key] = std::move(field);
    }
    return root;
}

inline std::string stringifySimple(const json::Value& value) {
    return json::stringifyValue(value);
}

} // namespace afrilang::runtime::yaml
