#pragma once

#include "afrilang/ast.hpp"
#include "afrilang/semantic.hpp"

#include <string>

namespace afrilang {

void writeDebugMetadata(const std::string& path, const ProgramNode& program,
                        const SemanticResult& semantic,
                        const std::string& sourceFile);

} // namespace afrilang
