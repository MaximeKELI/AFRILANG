#pragma once

// AFRILANG mid-end between semantic analysis and codegen.
// Pipeline: Mid-IR CFG (const-prop / simplify-cfg / DCE) then residual AST fold.
// Not SSA / not LLVM — see docs/COMPILER.md.

#include "afrilang/ast.hpp"

namespace afrilang::passes {

/** Run Mid-IR CFG passes then residual AST constant-fold / dead cleanup. */
void runOptionalPasses(ProgramNode& program);

} // namespace afrilang::passes
