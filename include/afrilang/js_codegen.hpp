#pragma once

#include "afrilang/ast.hpp"
#include "afrilang/semantic.hpp"

#include <ostream>
#include <string>
#include <unordered_set>

namespace afrilang {

bool supportsJavaScriptPlayground(const ProgramNode& program,
                                  const SemanticResult& semantic);

std::string compileSourceToJavaScript(const std::string& source,
                                    const std::string& virtualPath = "/playground/client.afr");

class JsCodeGenerator {
public:
    JsCodeGenerator(const ProgramNode& program, const SemanticResult& semantic);

    void generate(std::ostream& out) const;
    std::string generate() const;

private:
    const ProgramNode& program_;
    const SemanticResult& semantic_;
    bool needsGui_ = false;
    bool preferGame3d_ = false;
    std::unordered_set<std::string> userFuncs_;

    void emitStatement(std::ostream& out, const StatementNode& stmt, int indent) const;
    void emitExpression(std::ostream& out, const ExpressionNode& expr) const;
    void emitFunction(std::ostream& out, const FunctionNode& func) const;
    void emitCall(std::ostream& out, const CallExpressionNode& call) const;
    bool isRuntimeName(const std::string& name) const;
    static void indent(std::ostream& out, int level);
    static std::string escapeString(const std::string& s);
};

} // namespace afrilang
