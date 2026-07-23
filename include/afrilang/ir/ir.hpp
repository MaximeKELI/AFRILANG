#pragma once

// Lightweight CFG mid-IR (language mid-end). Not SSA / not LLVM.
// Pipeline: AST → lower → const-prop / simplify-cfg / DCE → raise → AST → codegen.
// See docs/COMPILER.md.

#include "afrilang/ast.hpp"

namespace afrilang::ir {

/** Best-effort Mid-IR optimize on a statement list. Returns false if lowering skipped. */
bool optimizeStmtList(std::vector<std::unique_ptr<StatementNode>>& stmts);

/** Run Mid-IR on all function/test/class/module bodies in the program. */
void runMidIrPasses(ProgramNode& program);

} // namespace afrilang::ir
