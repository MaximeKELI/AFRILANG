#include "afrilang/ir/ir.hpp"

#include <algorithm>
#include <cmath>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace afrilang::ir {
namespace {

bool almostEqual(double a, double b) {
    return std::fabs(a - b) <= 1e-12 * std::max(1.0, std::max(std::fabs(a), std::fabs(b)));
}

std::unique_ptr<ExpressionNode> foldExpr(std::unique_ptr<ExpressionNode> expr);

const NumberLiteralNode* asNumber(const ExpressionNode* e) {
    return dynamic_cast<const NumberLiteralNode*>(e);
}
const BoolLiteralNode* asBool(const ExpressionNode* e) {
    return dynamic_cast<const BoolLiteralNode*>(e);
}
const StringLiteralNode* asString(const ExpressionNode* e) {
    return dynamic_cast<const StringLiteralNode*>(e);
}

std::unique_ptr<ExpressionNode> foldBinary(std::unique_ptr<BinaryOpNode> bin) {
    bin->left = foldExpr(std::move(bin->left));
    bin->right = foldExpr(std::move(bin->right));
    if (const auto* ln = asNumber(bin->left.get())) {
        if (const auto* rn = asNumber(bin->right.get())) {
            const double a = ln->value;
            const double b = rn->value;
            const bool bothInt = ln->isInteger && rn->isInteger;
            if (bin->op == "+") return std::make_unique<NumberLiteralNode>(a + b, bothInt);
            if (bin->op == "-") return std::make_unique<NumberLiteralNode>(a - b, bothInt);
            if (bin->op == "*") return std::make_unique<NumberLiteralNode>(a * b, bothInt);
            if (bin->op == "/" && !almostEqual(b, 0.0)) {
                return std::make_unique<NumberLiteralNode>(a / b, false);
            }
            if (bin->op == "==") return std::make_unique<BoolLiteralNode>(almostEqual(a, b));
            if (bin->op == "!=") return std::make_unique<BoolLiteralNode>(!almostEqual(a, b));
            if (bin->op == "<") return std::make_unique<BoolLiteralNode>(a < b);
            if (bin->op == ">") return std::make_unique<BoolLiteralNode>(a > b);
            if (bin->op == "<=") return std::make_unique<BoolLiteralNode>(a <= b);
            if (bin->op == ">=") return std::make_unique<BoolLiteralNode>(a >= b);
        }
    }
    if (const auto* lb = asBool(bin->left.get())) {
        if (const auto* rb = asBool(bin->right.get())) {
            if (bin->op == "&&") return std::make_unique<BoolLiteralNode>(lb->value && rb->value);
            if (bin->op == "||") return std::make_unique<BoolLiteralNode>(lb->value || rb->value);
            if (bin->op == "==") return std::make_unique<BoolLiteralNode>(lb->value == rb->value);
            if (bin->op == "!=") return std::make_unique<BoolLiteralNode>(lb->value != rb->value);
        }
        if (bin->op == "&&" && !lb->value) return std::make_unique<BoolLiteralNode>(false);
        if (bin->op == "||" && lb->value) return std::make_unique<BoolLiteralNode>(true);
    }
    if (const auto* ls = asString(bin->left.get())) {
        if (const auto* rs = asString(bin->right.get())) {
            if (bin->op == "+") return std::make_unique<StringLiteralNode>(ls->value + rs->value);
            if (bin->op == "==") return std::make_unique<BoolLiteralNode>(ls->value == rs->value);
            if (bin->op == "!=") return std::make_unique<BoolLiteralNode>(ls->value != rs->value);
        }
    }
    return bin;
}

std::unique_ptr<ExpressionNode> foldUnary(std::unique_ptr<UnaryOpNode> un) {
    un->operand = foldExpr(std::move(un->operand));
    if (un->op == "-" || un->op == "not") {
        if (const auto* n = asNumber(un->operand.get())) {
            if (un->op == "-") return std::make_unique<NumberLiteralNode>(-n->value, n->isInteger);
        }
        if (const auto* b = asBool(un->operand.get())) {
            if (un->op == "not") return std::make_unique<BoolLiteralNode>(!b->value);
        }
    }
    return un;
}

std::unique_ptr<ExpressionNode> foldExpr(std::unique_ptr<ExpressionNode> expr) {
    if (!expr) return expr;
    if (auto* bin = dynamic_cast<BinaryOpNode*>(expr.get())) {
        expr.release();
        return foldBinary(std::unique_ptr<BinaryOpNode>(bin));
    }
    if (auto* un = dynamic_cast<UnaryOpNode*>(expr.get())) {
        expr.release();
        return foldUnary(std::unique_ptr<UnaryOpNode>(un));
    }
    if (auto* call = dynamic_cast<CallExpressionNode*>(expr.get())) {
        call->callee = foldExpr(std::move(call->callee));
        for (auto& arg : call->arguments) arg = foldExpr(std::move(arg));
        return expr;
    }
    if (auto* list = dynamic_cast<ListLiteralNode*>(expr.get())) {
        for (auto& el : list->elements) el = foldExpr(std::move(el));
        return expr;
    }
    if (auto* idx = dynamic_cast<IndexExpressionNode*>(expr.get())) {
        idx->object = foldExpr(std::move(idx->object));
        idx->index = foldExpr(std::move(idx->index));
        return expr;
    }
    if (auto* orElse = dynamic_cast<OrElseExprNode*>(expr.get())) {
        orElse->value = foldExpr(std::move(orElse->value));
        orElse->fallback = foldExpr(std::move(orElse->fallback));
        return expr;
    }
    return expr;
}

enum class TermKind { Fallthrough, Jump, Branch, Return, Raise, Stop };

struct Terminator {
    TermKind kind = TermKind::Fallthrough;
    int target = -1;
    int thenTarget = -1;
    int elseTarget = -1;
    bool returnIsError = false;
    std::unique_ptr<ExpressionNode> cond;
    std::unique_ptr<ExpressionNode> value;
};

enum class InstrKind { Assign, Set, Say, Assert, ExprStmt, Opaque };

struct Instr {
    InstrKind kind = InstrKind::Opaque;
    std::string name;
    std::string typeHint;
    bool isConst = false;
    std::unique_ptr<ExpressionNode> target; // Set
    std::unique_ptr<ExpressionNode> value;
    std::unique_ptr<StatementNode> opaque;
};

struct Block {
    int id = 0;
    std::vector<Instr> instrs;
    Terminator term;
    bool reachable = false;
};

struct FunctionIR {
    std::vector<Block> blocks;
    int newBlock() {
        Block b;
        b.id = static_cast<int>(blocks.size());
        blocks.push_back(std::move(b));
        return static_cast<int>(blocks.size()) - 1;
    }
};

bool lowerStmtList(std::vector<std::unique_ptr<StatementNode>>& stmts, FunctionIR& ir, int& blockId);

void optimizeNestedOpaque(StatementNode& stmt) {
    // Loops: fold conditions/bounds only. Full CFG raise on loop bodies can
    // drop increments (infinite loops) — residual AST fold handles the body.
    if (auto* whileStmt = dynamic_cast<WhileStatementNode*>(&stmt)) {
        whileStmt->condition = foldExpr(std::move(whileStmt->condition));
    } else if (auto* repeatStmt = dynamic_cast<RepeatStatementNode*>(&stmt)) {
        if (repeatStmt->count) repeatStmt->count = foldExpr(std::move(repeatStmt->count));
    } else if (auto* forRange = dynamic_cast<ForRangeStatementNode*>(&stmt)) {
        forRange->start = foldExpr(std::move(forRange->start));
        forRange->end = foldExpr(std::move(forRange->end));
        if (forRange->step) forRange->step = foldExpr(std::move(forRange->step));
    } else if (auto* forEach = dynamic_cast<ForEachStatementNode*>(&stmt)) {
        forEach->list = foldExpr(std::move(forEach->list));
    } else if (auto* tryStmt = dynamic_cast<TryStatementNode*>(&stmt)) {
        (void)optimizeStmtList(tryStmt->tryBody);
        (void)optimizeStmtList(tryStmt->catchBody);
        (void)optimizeStmtList(tryStmt->finallyBody);
    } else if (auto* macroCall = dynamic_cast<MacroCallStatementNode*>(&stmt)) {
        for (auto& arg : macroCall->arguments) arg = foldExpr(std::move(arg));
        (void)optimizeStmtList(macroCall->expanded);
    } else if (auto* idxAssign = dynamic_cast<IndexAssignStatementNode*>(&stmt)) {
        idxAssign->object = foldExpr(std::move(idxAssign->object));
        idxAssign->index = foldExpr(std::move(idxAssign->index));
        idxAssign->value = foldExpr(std::move(idxAssign->value));
    }
}

bool lowerInto(std::unique_ptr<StatementNode> stmt, FunctionIR& ir, int& blockId) {
    if (!stmt) return true;
    auto& block = ir.blocks[static_cast<size_t>(blockId)];
    if (block.term.kind != TermKind::Fallthrough) return true;

    if (auto* ret = dynamic_cast<ReturnStatementNode*>(stmt.get())) {
        Terminator t;
        t.kind = TermKind::Return;
        t.returnIsError = ret->isError;
        if (ret->value) t.value = foldExpr(std::move(ret->value));
        block.term = std::move(t);
        return true;
    }
    if (auto* raiseStmt = dynamic_cast<RaiseStatementNode*>(stmt.get())) {
        Terminator t;
        t.kind = TermKind::Raise;
        if (raiseStmt->message) t.value = foldExpr(std::move(raiseStmt->message));
        block.term = std::move(t);
        return true;
    }
    if (auto* ifStmt = dynamic_cast<IfStatementNode*>(stmt.get())) {
        auto cond = foldExpr(std::move(ifStmt->condition));
        const int thenB = ir.newBlock();
        const int elseB = ir.newBlock();
        const int joinB = ir.newBlock();

        Terminator br;
        if (const auto* b = asBool(cond.get())) {
            br.kind = TermKind::Jump;
            br.target = b->value ? thenB : elseB;
        } else {
            br.kind = TermKind::Branch;
            br.cond = std::move(cond);
            br.thenTarget = thenB;
            br.elseTarget = elseB;
        }
        ir.blocks[static_cast<size_t>(blockId)].term = std::move(br);

        int thenCur = thenB;
        if (!lowerStmtList(ifStmt->thenBody, ir, thenCur)) return false;
        if (ir.blocks[static_cast<size_t>(thenCur)].term.kind == TermKind::Fallthrough) {
            Terminator j;
            j.kind = TermKind::Jump;
            j.target = joinB;
            ir.blocks[static_cast<size_t>(thenCur)].term = std::move(j);
        }

        int elseCur = elseB;
        if (!lowerStmtList(ifStmt->elseBody, ir, elseCur)) return false;
        if (ir.blocks[static_cast<size_t>(elseCur)].term.kind == TermKind::Fallthrough) {
            Terminator j;
            j.kind = TermKind::Jump;
            j.target = joinB;
            ir.blocks[static_cast<size_t>(elseCur)].term = std::move(j);
        }

        blockId = joinB;
        return true;
    }

    Instr in;
    if (auto* assign = dynamic_cast<AssignStatementNode*>(stmt.get())) {
        in.kind = InstrKind::Assign;
        in.name = assign->name;
        in.typeHint = assign->typeName;
        in.isConst = assign->isConst;
        if (assign->value) in.value = foldExpr(std::move(assign->value));
        ir.blocks[static_cast<size_t>(blockId)].instrs.push_back(std::move(in));
        return true;
    }
    if (auto* setStmt = dynamic_cast<SetStatementNode*>(stmt.get())) {
        in.kind = InstrKind::Set;
        in.target = std::move(setStmt->target);
        if (setStmt->value) in.value = foldExpr(std::move(setStmt->value));
        ir.blocks[static_cast<size_t>(blockId)].instrs.push_back(std::move(in));
        return true;
    }
    if (auto* say = dynamic_cast<SayStatementNode*>(stmt.get())) {
        in.kind = InstrKind::Say;
        if (say->value) in.value = foldExpr(std::move(say->value));
        ir.blocks[static_cast<size_t>(blockId)].instrs.push_back(std::move(in));
        return true;
    }
    if (auto* assertStmt = dynamic_cast<AssertStatementNode*>(stmt.get())) {
        in.kind = InstrKind::Assert;
        if (assertStmt->condition) in.value = foldExpr(std::move(assertStmt->condition));
        ir.blocks[static_cast<size_t>(blockId)].instrs.push_back(std::move(in));
        return true;
    }
    if (auto* exprStmt = dynamic_cast<ExpressionStatementNode*>(stmt.get())) {
        in.kind = InstrKind::ExprStmt;
        if (exprStmt->expression) in.value = foldExpr(std::move(exprStmt->expression));
        ir.blocks[static_cast<size_t>(blockId)].instrs.push_back(std::move(in));
        return true;
    }

    optimizeNestedOpaque(*stmt);
    in.kind = InstrKind::Opaque;
    in.opaque = std::move(stmt);
    ir.blocks[static_cast<size_t>(blockId)].instrs.push_back(std::move(in));
    return true;
}

bool lowerStmtList(std::vector<std::unique_ptr<StatementNode>>& stmts, FunctionIR& ir, int& blockId) {
    for (auto& stmt : stmts) {
        if (ir.blocks[static_cast<size_t>(blockId)].term.kind != TermKind::Fallthrough) break;
        if (!lowerInto(std::move(stmt), ir, blockId)) return false;
    }
    stmts.clear();
    return true;
}

void markReachable(FunctionIR& ir, int id) {
    if (id < 0 || id >= static_cast<int>(ir.blocks.size())) return;
    auto& b = ir.blocks[static_cast<size_t>(id)];
    if (b.reachable) return;
    b.reachable = true;
    switch (b.term.kind) {
    case TermKind::Jump:
        markReachable(ir, b.term.target);
        break;
    case TermKind::Branch:
        markReachable(ir, b.term.thenTarget);
        markReachable(ir, b.term.elseTarget);
        break;
    default:
        break;
    }
}

void simplifyCfg(FunctionIR& ir) {
    for (auto& b : ir.blocks) {
        for (auto& in : b.instrs) {
            if (in.value) in.value = foldExpr(std::move(in.value));
            if (in.target) in.target = foldExpr(std::move(in.target));
        }
        if (b.term.kind == TermKind::Branch && b.term.cond) {
            b.term.cond = foldExpr(std::move(b.term.cond));
            if (const auto* c = asBool(b.term.cond.get())) {
                Terminator j;
                j.kind = TermKind::Jump;
                j.target = c->value ? b.term.thenTarget : b.term.elseTarget;
                b.term = std::move(j);
            }
        }
        if (b.term.value) b.term.value = foldExpr(std::move(b.term.value));
    }
    for (auto& b : ir.blocks) b.reachable = false;
    if (!ir.blocks.empty()) markReachable(ir, 0);
    for (auto& b : ir.blocks) {
        if (!b.reachable) {
            b.instrs.clear();
            b.term = Terminator{};
            b.term.kind = TermKind::Stop;
        }
    }
}

std::unique_ptr<StatementNode> instrToStmt(Instr& in) {
    switch (in.kind) {
    case InstrKind::Assign:
        return std::make_unique<AssignStatementNode>(in.name, in.typeHint, std::move(in.value),
                                                     in.isConst);
    case InstrKind::Set: {
        if (!in.target || !in.value) return nullptr;
        return std::make_unique<SetStatementNode>(std::move(in.target), std::move(in.value));
    }
    case InstrKind::Say:
        if (!in.value) return nullptr;
        return std::make_unique<SayStatementNode>(std::move(in.value));
    case InstrKind::Assert:
        if (!in.value) return nullptr;
        return std::make_unique<AssertStatementNode>(std::move(in.value));
    case InstrKind::ExprStmt:
        if (!in.value) return nullptr;
        return std::make_unique<ExpressionStatementNode>(std::move(in.value));
    case InstrKind::Opaque:
        return std::move(in.opaque);
    }
    return nullptr;
}

int findJoin(const FunctionIR& ir, int thenEntry, int elseEntry) {
    auto exitJump = [&](int entry) -> int {
        int cur = entry;
        std::vector<char> seen(ir.blocks.size(), 0);
        while (cur >= 0 && cur < static_cast<int>(ir.blocks.size()) &&
               !seen[static_cast<size_t>(cur)]) {
            seen[static_cast<size_t>(cur)] = 1;
            const auto& term = ir.blocks[static_cast<size_t>(cur)].term;
            if (term.kind == TermKind::Jump) return term.target;
            if (term.kind == TermKind::Branch) return -1;
            if (term.kind == TermKind::Return || term.kind == TermKind::Raise ||
                term.kind == TermKind::Stop)
                return -2;
            break;
        }
        return -1;
    };
    const int jt = exitJump(thenEntry);
    const int je = exitJump(elseEntry);
    if (jt >= 0 && jt == je) return jt;
    if (jt >= 0 && je == -2) return jt;
    if (je >= 0 && jt == -2) return je;
    return -1;
}

bool raiseBlock(FunctionIR& ir, int blockId, std::vector<std::unique_ptr<StatementNode>>& out);

bool raiseSide(FunctionIR& ir, int entry, int join,
               std::vector<std::unique_ptr<StatementNode>>& side) {
    int cur = entry;
    std::vector<char> seen(ir.blocks.size(), 0);
    while (cur >= 0 && cur < static_cast<int>(ir.blocks.size()) && !seen[static_cast<size_t>(cur)]) {
        seen[static_cast<size_t>(cur)] = 1;
        if (join >= 0 && cur == join) return true;
        auto& sb = ir.blocks[static_cast<size_t>(cur)];
        if (!sb.reachable) return true;
        for (auto& in : sb.instrs) {
            auto s = instrToStmt(in);
            if (s) side.push_back(std::move(s));
        }
        sb.instrs.clear();
        auto& st = sb.term;
        if (st.kind == TermKind::Jump) {
            if (join >= 0 && st.target == join) return true;
            cur = st.target;
            continue;
        }
        if (st.kind == TermKind::Branch) {
            std::vector<std::unique_ptr<StatementNode>> nested;
            if (!raiseBlock(ir, cur, nested)) return false;
            for (auto& n : nested) side.push_back(std::move(n));
            return true;
        }
        if (st.kind == TermKind::Return) {
            side.push_back(std::make_unique<ReturnStatementNode>(std::move(st.value),
                                                                 st.returnIsError));
            st.kind = TermKind::Stop;
            return true;
        }
        if (st.kind == TermKind::Raise) {
            side.push_back(std::make_unique<RaiseStatementNode>(std::move(st.value)));
            st.kind = TermKind::Stop;
            return true;
        }
        break;
    }
    return true;
}

bool raiseBlock(FunctionIR& ir, int blockId, std::vector<std::unique_ptr<StatementNode>>& out) {
    if (blockId < 0 || blockId >= static_cast<int>(ir.blocks.size())) return true;
    auto& b = ir.blocks[static_cast<size_t>(blockId)];
    if (!b.reachable) return true;

    for (auto& in : b.instrs) {
        auto s = instrToStmt(in);
        if (s) out.push_back(std::move(s));
    }
    b.instrs.clear();

    auto& t = b.term;
    switch (t.kind) {
    case TermKind::Fallthrough:
    case TermKind::Stop:
        return true;
    case TermKind::Return:
        out.push_back(std::make_unique<ReturnStatementNode>(std::move(t.value), t.returnIsError));
        t.kind = TermKind::Stop;
        return true;
    case TermKind::Raise:
        out.push_back(std::make_unique<RaiseStatementNode>(std::move(t.value)));
        t.kind = TermKind::Stop;
        return true;
    case TermKind::Jump: {
        const int target = t.target;
        t.kind = TermKind::Stop;
        return raiseBlock(ir, target, out);
    }
    case TermKind::Branch: {
        const int thenT = t.thenTarget;
        const int elseT = t.elseTarget;
        const int join = findJoin(ir, thenT, elseT);
        std::vector<std::unique_ptr<StatementNode>> thenBody;
        std::vector<std::unique_ptr<StatementNode>> elseBody;
        auto cond = t.cond ? std::move(t.cond) : std::make_unique<BoolLiteralNode>(true);
        t.kind = TermKind::Stop;
        if (!raiseSide(ir, thenT, join, thenBody)) return false;
        if (!raiseSide(ir, elseT, join, elseBody)) return false;
        out.push_back(std::make_unique<IfStatementNode>(std::move(cond), std::move(thenBody),
                                                        std::move(elseBody)));
        if (join >= 0) return raiseBlock(ir, join, out);
        return true;
    }
    }
    return true;
}

} // namespace

bool optimizeStmtList(std::vector<std::unique_ptr<StatementNode>>& stmts) {
    if (stmts.empty()) return true;
    FunctionIR ir;
    const int entry = ir.newBlock();
    std::vector<std::unique_ptr<StatementNode>> moved = std::move(stmts);
    stmts.clear();
    int blockId = entry;
    if (!lowerStmtList(moved, ir, blockId)) {
        stmts = std::move(moved);
        return false;
    }
    simplifyCfg(ir);
    return raiseBlock(ir, entry, stmts);
}

void runMidIrPasses(ProgramNode& program) {
    for (auto& func : program.functions) {
        if (func) (void)optimizeStmtList(func->body);
    }
    for (auto& test : program.tests) {
        if (!test) continue;
        (void)optimizeStmtList(test->setupBody);
        (void)optimizeStmtList(test->body);
        (void)optimizeStmtList(test->teardownBody);
    }
    for (auto& cls : program.classes) {
        if (!cls) continue;
        for (auto& method : cls->methods) {
            if (method) (void)optimizeStmtList(method->body);
        }
    }
    for (auto& mod : program.modules) {
        if (!mod) continue;
        for (auto& func : mod->functions) {
            if (func) (void)optimizeStmtList(func->body);
        }
        for (auto& cls : mod->classes) {
            if (!cls) continue;
            for (auto& method : cls->methods) {
                if (method) (void)optimizeStmtList(method->body);
            }
        }
    }
    (void)optimizeStmtList(program.statements);
}

} // namespace afrilang::ir
