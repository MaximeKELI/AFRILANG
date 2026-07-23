#include "afrilang/passes.hpp"
#include "afrilang/ir/ir.hpp"

#include <algorithm>
#include <cmath>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace afrilang::passes {
namespace {

bool almostEqual(double a, double b) {
    return std::fabs(a - b) <= 1e-12 * std::max(1.0, std::max(std::fabs(a), std::fabs(b)));
}

std::unique_ptr<ExpressionNode> foldExpr(std::unique_ptr<ExpressionNode> expr);

void foldStmtList(std::vector<std::unique_ptr<StatementNode>>& stmts);

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
