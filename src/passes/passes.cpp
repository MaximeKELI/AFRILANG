#include "afrilang/passes.hpp"
#include "afrilang/ir/ir.hpp"

#include <algorithm>
#include <cmath>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

namespace afrilang::passes {
namespace {

bool almostEqual(double a, double b) {
    return std::fabs(a - b) <= 1e-12 * std::max(1.0, std::max(std::fabs(a), std::fabs(b)));
}

std::unique_ptr<ExpressionNode> foldExpr(std::unique_ptr<ExpressionNode> expr);
std::unique_ptr<ExpressionNode> cloneExpr(const ExpressionNode* e);
void foldStmtList(std::vector<std::unique_ptr<StatementNode>>& stmts);
void foldStmt(std::unique_ptr<StatementNode>& stmt);
void pruneUnreachable(std::vector<std::unique_ptr<StatementNode>>& stmts);

const NumberLiteralNode* asNumber(const ExpressionNode* e) {
    return dynamic_cast<const NumberLiteralNode*>(e);
}
const BoolLiteralNode* asBool(const ExpressionNode* e) {
    return dynamic_cast<const BoolLiteralNode*>(e);
}
const StringLiteralNode* asString(const ExpressionNode* e) {
    return dynamic_cast<const StringLiteralNode*>(e);
}
const IdentifierNode* asIdent(const ExpressionNode* e) {
    return dynamic_cast<const IdentifierNode*>(e);
}

bool isLiteralExpr(const ExpressionNode* e) {
    return asNumber(e) || asBool(e) || asString(e);
}

std::unique_ptr<ExpressionNode> cloneExpr(const ExpressionNode* e) {
    if (!e) return nullptr;
    if (const auto* n = asNumber(e)) {
        return std::make_unique<NumberLiteralNode>(n->value, n->isInteger);
    }
    if (const auto* b = asBool(e)) return std::make_unique<BoolLiteralNode>(b->value);
    if (const auto* s = asString(e)) return std::make_unique<StringLiteralNode>(s->value);
    if (const auto* id = asIdent(e)) return std::make_unique<IdentifierNode>(id->name);
    if (const auto* bin = dynamic_cast<const BinaryOpNode*>(e)) {
        return std::make_unique<BinaryOpNode>(bin->op, cloneExpr(bin->left.get()),
                                              cloneExpr(bin->right.get()));
    }
    if (const auto* un = dynamic_cast<const UnaryOpNode*>(e)) {
        return std::make_unique<UnaryOpNode>(un->op, cloneExpr(un->operand.get()));
    }
    return nullptr;
}

using ConstEnv = std::unordered_map<std::string, std::unique_ptr<ExpressionNode>>;

std::unique_ptr<ExpressionNode> substEnv(std::unique_ptr<ExpressionNode> expr, const ConstEnv& env) {
    if (!expr) return expr;
    if (auto* id = dynamic_cast<IdentifierNode*>(expr.get())) {
        const auto it = env.find(id->name);
        if (it != env.end() && it->second) return cloneExpr(it->second.get());
        return expr;
    }
    if (auto* bin = dynamic_cast<BinaryOpNode*>(expr.get())) {
        bin->left = substEnv(std::move(bin->left), env);
        bin->right = substEnv(std::move(bin->right), env);
        return expr;
    }
    if (auto* un = dynamic_cast<UnaryOpNode*>(expr.get())) {
        un->operand = substEnv(std::move(un->operand), env);
        return expr;
    }
    if (auto* call = dynamic_cast<CallExpressionNode*>(expr.get())) {
        call->callee = substEnv(std::move(call->callee), env);
        for (auto& arg : call->arguments) arg = substEnv(std::move(arg), env);
        return expr;
    }
    if (auto* list = dynamic_cast<ListLiteralNode*>(expr.get())) {
        for (auto& el : list->elements) el = substEnv(std::move(el), env);
        return expr;
    }
    if (auto* idx = dynamic_cast<IndexExpressionNode*>(expr.get())) {
        idx->object = substEnv(std::move(idx->object), env);
        idx->index = substEnv(std::move(idx->index), env);
        return expr;
    }
    if (auto* orElse = dynamic_cast<OrElseExprNode*>(expr.get())) {
        orElse->value = substEnv(std::move(orElse->value), env);
        orElse->fallback = substEnv(std::move(orElse->fallback), env);
        return expr;
    }
    return expr;
}

std::unique_ptr<ExpressionNode> substFold(std::unique_ptr<ExpressionNode> expr, const ConstEnv& env) {
    return foldExpr(substEnv(std::move(expr), env));
}

void countIdentUses(const ExpressionNode* e, std::unordered_map<std::string, int>& uses) {
    if (!e) return;
    if (const auto* id = asIdent(e)) {
        ++uses[id->name];
        return;
    }
    if (const auto* bin = dynamic_cast<const BinaryOpNode*>(e)) {
        countIdentUses(bin->left.get(), uses);
        countIdentUses(bin->right.get(), uses);
        return;
    }
    if (const auto* un = dynamic_cast<const UnaryOpNode*>(e)) {
        countIdentUses(un->operand.get(), uses);
        return;
    }
    if (const auto* call = dynamic_cast<const CallExpressionNode*>(e)) {
        countIdentUses(call->callee.get(), uses);
        for (const auto& arg : call->arguments) countIdentUses(arg.get(), uses);
        return;
    }
    if (const auto* list = dynamic_cast<const ListLiteralNode*>(e)) {
        for (const auto& el : list->elements) countIdentUses(el.get(), uses);
        return;
    }
    if (const auto* idx = dynamic_cast<const IndexExpressionNode*>(e)) {
        countIdentUses(idx->object.get(), uses);
        countIdentUses(idx->index.get(), uses);
        return;
    }
    if (const auto* orElse = dynamic_cast<const OrElseExprNode*>(e)) {
        countIdentUses(orElse->value.get(), uses);
        countIdentUses(orElse->fallback.get(), uses);
    }
}

void countStmtUses(const StatementNode* stmt, std::unordered_map<std::string, int>& uses) {
    if (!stmt) return;
    if (const auto* a = dynamic_cast<const AssignStatementNode*>(stmt)) {
        countIdentUses(a->value.get(), uses);
        return;
    }
    if (const auto* s = dynamic_cast<const SetStatementNode*>(stmt)) {
        countIdentUses(s->target.get(), uses);
        countIdentUses(s->value.get(), uses);
        return;
    }
    if (const auto* say = dynamic_cast<const SayStatementNode*>(stmt)) {
        countIdentUses(say->value.get(), uses);
        return;
    }
    if (const auto* ret = dynamic_cast<const ReturnStatementNode*>(stmt)) {
        countIdentUses(ret->value.get(), uses);
        return;
    }
    if (const auto* asrt = dynamic_cast<const AssertStatementNode*>(stmt)) {
        countIdentUses(asrt->condition.get(), uses);
        return;
    }
    if (const auto* ex = dynamic_cast<const ExpressionStatementNode*>(stmt)) {
        countIdentUses(ex->expression.get(), uses);
        return;
    }
    if (const auto* iff = dynamic_cast<const IfStatementNode*>(stmt)) {
        countIdentUses(iff->condition.get(), uses);
        for (const auto& st : iff->thenBody) countStmtUses(st.get(), uses);
        for (const auto& st : iff->elseBody) countStmtUses(st.get(), uses);
        return;
    }
    if (const auto* w = dynamic_cast<const WhileStatementNode*>(stmt)) {
        countIdentUses(w->condition.get(), uses);
        for (const auto& st : w->body) countStmtUses(st.get(), uses);
        return;
    }
    if (const auto* fr = dynamic_cast<const ForRangeStatementNode*>(stmt)) {
        countIdentUses(fr->start.get(), uses);
        countIdentUses(fr->end.get(), uses);
        countIdentUses(fr->step.get(), uses);
        for (const auto& st : fr->body) countStmtUses(st.get(), uses);
        return;
    }
    if (const auto* fe = dynamic_cast<const ForEachStatementNode*>(stmt)) {
        countIdentUses(fe->list.get(), uses);
        for (const auto& st : fe->body) countStmtUses(st.get(), uses);
    }
}

void dcePureAndUnused(std::vector<std::unique_ptr<StatementNode>>& stmts) {
    // Only drop pure no-op expression statements. Dropping unused `create`
    // requires a complete use analysis (incl. repeat/for/opaque) — too risky.
    std::vector<std::unique_ptr<StatementNode>> out;
    out.reserve(stmts.size());
    for (auto& stmt : stmts) {
        if (auto* ex = dynamic_cast<ExpressionStatementNode*>(stmt.get())) {
            if (isLiteralExpr(ex->expression.get()) || asIdent(ex->expression.get())) {
                continue;
            }
        }
        out.push_back(std::move(stmt));
    }
    stmts = std::move(out);
}

void localConstPropList(std::vector<std::unique_ptr<StatementNode>>& stmts, ConstEnv env);

void localConstPropList(std::vector<std::unique_ptr<StatementNode>>& stmts, ConstEnv env) {
    for (auto& stmt : stmts) {
        if (!stmt) continue;
        if (auto* assign = dynamic_cast<AssignStatementNode*>(stmt.get())) {
            if (assign->value) assign->value = substFold(std::move(assign->value), env);
            if (isLiteralExpr(assign->value.get())) {
                env[assign->name] = cloneExpr(assign->value.get());
            } else {
                env.erase(assign->name);
            }
            continue;
        }
        if (auto* setStmt = dynamic_cast<SetStatementNode*>(stmt.get())) {
            if (setStmt->value) setStmt->value = substFold(std::move(setStmt->value), env);
            if (auto* tid = dynamic_cast<IdentifierNode*>(setStmt->target.get())) {
                if (isLiteralExpr(setStmt->value.get())) {
                    env[tid->name] = cloneExpr(setStmt->value.get());
                } else {
                    env.erase(tid->name);
                }
            } else {
                env.clear();
            }
            continue;
        }
        if (auto* say = dynamic_cast<SayStatementNode*>(stmt.get())) {
            if (say->value) say->value = substFold(std::move(say->value), env);
            continue;
        }
        if (auto* ret = dynamic_cast<ReturnStatementNode*>(stmt.get())) {
            if (ret->value) ret->value = substFold(std::move(ret->value), env);
            continue;
        }
        if (auto* assertStmt = dynamic_cast<AssertStatementNode*>(stmt.get())) {
            if (assertStmt->condition)
                assertStmt->condition = substFold(std::move(assertStmt->condition), env);
            continue;
        }
        if (auto* raiseStmt = dynamic_cast<RaiseStatementNode*>(stmt.get())) {
            if (raiseStmt->message)
                raiseStmt->message = substFold(std::move(raiseStmt->message), env);
            continue;
        }
        if (auto* exprStmt = dynamic_cast<ExpressionStatementNode*>(stmt.get())) {
            if (exprStmt->expression)
                exprStmt->expression = substFold(std::move(exprStmt->expression), env);
            continue;
        }
        if (auto* ifStmt = dynamic_cast<IfStatementNode*>(stmt.get())) {
            ifStmt->condition = substFold(std::move(ifStmt->condition), env);
            auto copyEnv = [](const ConstEnv& src) {
                ConstEnv dst;
                for (const auto& [k, v] : src) {
                    if (v) dst[k] = cloneExpr(v.get());
                }
                return dst;
            };
            ConstEnv thenEnv = copyEnv(env);
            ConstEnv elseEnv = copyEnv(env);
            localConstPropList(ifStmt->thenBody, std::move(thenEnv));
            localConstPropList(ifStmt->elseBody, std::move(elseEnv));
            // Conservative: drop facts that may diverge across branches
            env.clear();
            continue;
        }
        // Loops / other: invalidate and fall back to structural fold
        env.clear();
        foldStmt(stmt);
    }
    pruneUnreachable(stmts);
    dcePureAndUnused(stmts);
}

std::unique_ptr<ExpressionNode> foldBinary(std::unique_ptr<BinaryOpNode> bin) {
    bin->left = foldExpr(std::move(bin->left));
    bin->right = foldExpr(std::move(bin->right));

    if (const auto* ln = asNumber(bin->left.get())) {
        if (const auto* rn = asNumber(bin->right.get())) {
            const double a = ln->value;
            const double b = rn->value;
            const bool bothInt = ln->isInteger && rn->isInteger;
            if (bin->op == "+") {
                return std::make_unique<NumberLiteralNode>(a + b, bothInt);
            }
            if (bin->op == "-") {
                return std::make_unique<NumberLiteralNode>(a - b, bothInt);
            }
            if (bin->op == "*") {
                return std::make_unique<NumberLiteralNode>(a * b, bothInt);
            }
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
        // One-sided identity / annihilator (left const) — align with Mid-IR
        if (bin->op == "+" && almostEqual(ln->value, 0.0)) return std::move(bin->right);
        if (bin->op == "*" && almostEqual(ln->value, 1.0)) return std::move(bin->right);
        if (bin->op == "*" && almostEqual(ln->value, 0.0)) {
            return std::make_unique<NumberLiteralNode>(0.0, ln->isInteger);
        }
    }
    if (const auto* rn = asNumber(bin->right.get())) {
        if (bin->op == "+" && almostEqual(rn->value, 0.0)) return std::move(bin->left);
        if (bin->op == "-" && almostEqual(rn->value, 0.0)) return std::move(bin->left);
        if (bin->op == "*" && almostEqual(rn->value, 1.0)) return std::move(bin->left);
        if (bin->op == "/" && almostEqual(rn->value, 1.0)) return std::move(bin->left);
        if (bin->op == "*" && almostEqual(rn->value, 0.0)) {
            return std::make_unique<NumberLiteralNode>(0.0, rn->isInteger);
        }
    }

    if (const auto* lb = asBool(bin->left.get())) {
        if (const auto* rb = asBool(bin->right.get())) {
            if (bin->op == "&&") return std::make_unique<BoolLiteralNode>(lb->value && rb->value);
            if (bin->op == "||") return std::make_unique<BoolLiteralNode>(lb->value || rb->value);
            if (bin->op == "==") return std::make_unique<BoolLiteralNode>(lb->value == rb->value);
            if (bin->op == "!=") return std::make_unique<BoolLiteralNode>(lb->value != rb->value);
        }
        // Short-circuit friendly folds
        if (bin->op == "&&" && !lb->value) return std::make_unique<BoolLiteralNode>(false);
        if (bin->op == "||" && lb->value) return std::make_unique<BoolLiteralNode>(true);
        if (bin->op == "&&" && lb->value) return std::move(bin->right);
        if (bin->op == "||" && !lb->value) return std::move(bin->right);
    }
    if (const auto* rb = asBool(bin->right.get())) {
        // Safe only when right is pure literal (already is)
        if (bin->op == "&&" && rb->value) return std::move(bin->left);
        if (bin->op == "||" && !rb->value) return std::move(bin->left);
    }

    if (const auto* ls = asString(bin->left.get())) {
        if (const auto* rs = asString(bin->right.get())) {
            if (bin->op == "+") {
                return std::make_unique<StringLiteralNode>(ls->value + rs->value);
            }
            if (bin->op == "==") return std::make_unique<BoolLiteralNode>(ls->value == rs->value);
            if (bin->op == "!=") return std::make_unique<BoolLiteralNode>(ls->value != rs->value);
        }
    }

    // Strength reduce: x*2/4/8 → nested adds (FP-safe; then re-fold)
    if (bin->op == "*") {
        const NumberLiteralNode* factor = nullptr;
        std::unique_ptr<ExpressionNode>* base = nullptr;
        if (const auto* rn = asNumber(bin->right.get());
            rn && (almostEqual(rn->value, 2.0) || almostEqual(rn->value, 4.0) ||
                   almostEqual(rn->value, 8.0))) {
            factor = rn;
            base = &bin->left;
        } else if (const auto* ln = asNumber(bin->left.get());
                   ln && (almostEqual(ln->value, 2.0) || almostEqual(ln->value, 4.0) ||
                          almostEqual(ln->value, 8.0))) {
            factor = ln;
            base = &bin->right;
        }
        if (factor && base && *base) {
            const int k = static_cast<int>(factor->value + 0.5);
            auto x = std::move(*base);
            if (k == 2) {
                auto a = cloneExpr(x.get());
                return foldExpr(
                    std::make_unique<BinaryOpNode>("+", std::move(x), std::move(a)));
            }
            if (k == 4) {
                auto a = cloneExpr(x.get());
                auto s2 = std::make_unique<BinaryOpNode>("+", std::move(x), std::move(a));
                auto b = cloneExpr(s2.get());
                return foldExpr(
                    std::make_unique<BinaryOpNode>("+", std::move(s2), std::move(b)));
            }
            if (k == 8) {
                auto a = cloneExpr(x.get());
                auto s2 = std::make_unique<BinaryOpNode>("+", std::move(x), std::move(a));
                auto b = cloneExpr(s2.get());
                auto s4 = std::make_unique<BinaryOpNode>("+", std::move(s2), std::move(b));
                auto c = cloneExpr(s4.get());
                return foldExpr(
                    std::make_unique<BinaryOpNode>("+", std::move(s4), std::move(c)));
            }
        }
    }
    // x - x → 0 when both sides are the same identifier
    if (bin->op == "-") {
        const auto* li = asIdent(bin->left.get());
        const auto* ri = asIdent(bin->right.get());
        if (li && ri && li->name == ri->name) {
            return std::make_unique<NumberLiteralNode>(0.0, true);
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
        // not not x → x
        if (un->op == "not") {
            if (auto* inner = dynamic_cast<UnaryOpNode*>(un->operand.get())) {
                if (inner->op == "not") {
                    return foldExpr(std::move(inner->operand));
                }
            }
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

void pruneUnreachable(std::vector<std::unique_ptr<StatementNode>>& stmts) {
    bool dead = false;
    std::vector<std::unique_ptr<StatementNode>> out;
    out.reserve(stmts.size());
    for (auto& stmt : stmts) {
        if (dead) continue;
        if (dynamic_cast<ReturnStatementNode*>(stmt.get()) ||
            dynamic_cast<BreakStatementNode*>(stmt.get()) ||
            dynamic_cast<ContinueStatementNode*>(stmt.get()) ||
            dynamic_cast<RaiseStatementNode*>(stmt.get())) {
            out.push_back(std::move(stmt));
            dead = true;
            continue;
        }
        out.push_back(std::move(stmt));
    }
    stmts = std::move(out);
}

void foldStmt(std::unique_ptr<StatementNode>& stmt);

void foldStmtList(std::vector<std::unique_ptr<StatementNode>>& stmts) {
    for (auto& stmt : stmts) foldStmt(stmt);
    pruneUnreachable(stmts);
    localConstPropList(stmts, ConstEnv{});
}

void foldStmt(std::unique_ptr<StatementNode>& stmt) {
    if (!stmt) return;
    if (auto* assign = dynamic_cast<AssignStatementNode*>(stmt.get())) {
        if (assign->value) assign->value = foldExpr(std::move(assign->value));
        return;
    }
    if (auto* setStmt = dynamic_cast<SetStatementNode*>(stmt.get())) {
        if (setStmt->value) setStmt->value = foldExpr(std::move(setStmt->value));
        return;
    }
    if (auto* say = dynamic_cast<SayStatementNode*>(stmt.get())) {
        if (say->value) say->value = foldExpr(std::move(say->value));
        return;
    }
    if (auto* ret = dynamic_cast<ReturnStatementNode*>(stmt.get())) {
        if (ret->value) ret->value = foldExpr(std::move(ret->value));
        return;
    }
    if (auto* assertStmt = dynamic_cast<AssertStatementNode*>(stmt.get())) {
        if (assertStmt->condition) assertStmt->condition = foldExpr(std::move(assertStmt->condition));
        return;
    }
    if (auto* raiseStmt = dynamic_cast<RaiseStatementNode*>(stmt.get())) {
        if (raiseStmt->message) raiseStmt->message = foldExpr(std::move(raiseStmt->message));
        return;
    }
    if (auto* exprStmt = dynamic_cast<ExpressionStatementNode*>(stmt.get())) {
        if (exprStmt->expression) exprStmt->expression = foldExpr(std::move(exprStmt->expression));
        return;
    }
    if (auto* ifStmt = dynamic_cast<IfStatementNode*>(stmt.get())) {
        ifStmt->condition = foldExpr(std::move(ifStmt->condition));
        foldStmtList(ifStmt->thenBody);
        foldStmtList(ifStmt->elseBody);
        if (const auto* b = asBool(ifStmt->condition.get())) {
            if (b->value) {
                ifStmt->elseBody.clear();
            } else {
                ifStmt->thenBody = std::move(ifStmt->elseBody);
                ifStmt->elseBody.clear();
                ifStmt->condition = std::make_unique<BoolLiteralNode>(true);
            }
        }
        return;
    }
    if (auto* whileStmt = dynamic_cast<WhileStatementNode*>(stmt.get())) {
        whileStmt->condition = foldExpr(std::move(whileStmt->condition));
        foldStmtList(whileStmt->body);
        return;
    }
    if (auto* forRange = dynamic_cast<ForRangeStatementNode*>(stmt.get())) {
        forRange->start = foldExpr(std::move(forRange->start));
        forRange->end = foldExpr(std::move(forRange->end));
        if (forRange->step) forRange->step = foldExpr(std::move(forRange->step));
        foldStmtList(forRange->body);
        return;
    }
    if (auto* forEach = dynamic_cast<ForEachStatementNode*>(stmt.get())) {
        forEach->list = foldExpr(std::move(forEach->list));
        foldStmtList(forEach->body);
        return;
    }
    if (auto* tryStmt = dynamic_cast<TryStatementNode*>(stmt.get())) {
        foldStmtList(tryStmt->tryBody);
        foldStmtList(tryStmt->catchBody);
        foldStmtList(tryStmt->finallyBody);
        return;
    }
    if (auto* idxAssign = dynamic_cast<IndexAssignStatementNode*>(stmt.get())) {
        idxAssign->object = foldExpr(std::move(idxAssign->object));
        idxAssign->index = foldExpr(std::move(idxAssign->index));
        idxAssign->value = foldExpr(std::move(idxAssign->value));
        return;
    }
    if (auto* macroCall = dynamic_cast<MacroCallStatementNode*>(stmt.get())) {
        for (auto& arg : macroCall->arguments) arg = foldExpr(std::move(arg));
        foldStmtList(macroCall->expanded);
        return;
    }
}

void foldFunction(FunctionNode& func) {
    foldStmtList(func.body);
}

} // namespace

void runAstFoldPasses(ProgramNode& program) {
    for (auto& func : program.functions) {
        if (func) foldFunction(*func);
    }
    for (auto& test : program.tests) {
        if (test) {
            foldStmtList(test->setupBody);
            foldStmtList(test->body);
            foldStmtList(test->teardownBody);
        }
    }
    for (auto& cls : program.classes) {
        if (!cls) continue;
        for (auto& method : cls->methods) {
            if (method) foldFunction(*method);
        }
    }
    for (auto& mod : program.modules) {
        if (!mod) continue;
        for (auto& func : mod->functions) {
            if (func) foldFunction(*func);
        }
        for (auto& cls : mod->classes) {
            if (!cls) continue;
            for (auto& method : cls->methods) {
                if (method) foldFunction(*method);
            }
        }
    }
    foldStmtList(program.statements);
}

void runOptionalPasses(ProgramNode& program) {
    afrilang::ir::runMidIrPasses(program);
    runAstFoldPasses(program);
}

} // namespace afrilang::passes
