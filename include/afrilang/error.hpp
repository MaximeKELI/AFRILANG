#pragma once

#include <stdexcept>
#include <string>

namespace afrilang {

class CompileError : public std::runtime_error {
public:
    CompileError(const std::string& message, int line, int column)
        : std::runtime_error(format(message, line, column))
        , line_(line)
        , column_(column) {}

    int line() const { return line_; }
    int column() const { return column_; }

private:
    int line_;
    int column_;

    static std::string format(const std::string& message, int line, int column) {
        return "Erreur ligne " + std::to_string(line) + ", colonne " +
               std::to_string(column) + ": " + message;
    }
};

} // namespace afrilang
