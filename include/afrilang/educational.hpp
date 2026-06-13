#pragma once

#include "afrilang/ast.hpp"

#include <string>

namespace afrilang {

std::string explainStatement(const StatementNode& stmt);
void explainProgram(const ProgramNode& program, int filterLine = 0);

} // namespace afrilang
