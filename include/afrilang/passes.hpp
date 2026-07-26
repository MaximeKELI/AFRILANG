#pragma once

// AFRILANG mid-end between semantic analysis and codegen.
// Pipeline: Mid-IR CFG (fold / per-block const-prop / simplify-cfg / DCE)
// then residual AST fold (identity / strength-reduce / local const-prop / DCE).
// Not SSA / not LLVM — see docs/COMPILER.md and docs/PERF.md.

#include "afrilang/ast.hpp"

namespace afrilang::passes {

/** Run Mid-IR CFG passes then residual AST constant-fold / dead cleanup. */
void runOptionalPasses(ProgramNode& program);

} // namespace afrilang::passes
