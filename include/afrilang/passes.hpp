#pragma once

// Optional AST mid-end extension point (no IR yet).
// Future passes can transform ProgramNode between semantic analysis and codegen.
// See docs/COMPILER.md.

#include "afrilang/ast.hpp"

namespace afrilang::passes {

inline void runOptionalPasses(ProgramNode& /*program*/) {
    // Intentionally empty — host C++ optimizer is the current performance path.
}

} // namespace afrilang::passes
