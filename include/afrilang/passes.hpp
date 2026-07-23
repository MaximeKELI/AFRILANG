#pragma once

// AFRILANG mid-end: AST optimization passes between semantic analysis and codegen.
// Not a full SSA/IR — product mid-end for Performance efficiency (ISO 25010).
// See docs/COMPILER.md.

#include "afrilang/ast.hpp"

namespace afrilang::passes {

/** Run constant folding, dead-branch pruning, and unreachable-stmt cleanup. */
void runOptionalPasses(ProgramNode& program);

} // namespace afrilang::passes
