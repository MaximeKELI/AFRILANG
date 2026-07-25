#include "afrilang/js_codegen.hpp"

#include "afrilang/compiler.hpp"
#include "afrilang/error.hpp"
#include "afrilang/semantic.hpp"

#include <cstdlib>
#include <cstring>
#include <sstream>
#include <unordered_set>

namespace afrilang {

namespace {

bool expressionSupported(const ExpressionNode& expr);
bool statementsSupported(const std::vector<std::unique_ptr<StatementNode>>& stmts);

const char* kRuntimeNames[] = {
    // ui
    "openWindow", "closeWindow", "isOpen", "beginFrame", "clearBackground", "fillRect",
    "drawRect", "drawText", "drawTextColor", "drawButton", "isKeyDown", "wasKeyPressed",
    "deltaMs", "windowWidth", "windowHeight", "mouseX", "mouseY", "isMouseDown",
    "wasMousePressed", "wasMouseClicked", "fps", "showFrame",
    // game2d
    "configureGrid", "configureViewport", "gridWindowWidth", "gridWindowHeight", "cellPx",
    "cellPy", "cellWorldX", "cellWorldY", "isBorderCell", "fillCell", "drawCell", "fillBoard",
    "drawWalls", "drawGridLines", "fillCircleSolid", "everyMs", "resetTimer", "animTimeMs",
    "pulse01", "updateDirection", "inputDirX", "inputDirY", "syncDirection", "gridHas", "rgb",
    "redOf", "greenOf", "blueOf", "fillCellRgb", "drawCenteredText", "drawHud", "highScore",
    "updateHighScore", "moveIntervalForScore", "setCamera", "cameraX", "cameraY", "followCamera",
    "loadSprite", "hasSprite", "spriteWidth", "spriteHeight", "drawSprite", "drawSpriteScaled",
    "drawSpriteCell", "loadSpriteSheet", "hasSpriteSheet", "sheetCols", "sheetRows",
    "drawSpriteFrame", "drawSpriteFrameCell", "loadSound", "playSound", "playSoundVolume",
    "loadMusic", "playMusic", "stopMusic", "setMusicVolume", "defineTrigger", "setTriggerActive",
    "pointInTrigger", "mouseInTrigger", "mouseWorldX", "mouseWorldY", "saveValue", "loadValue",
    "loadHighScore", "saveHighScore", "drawFps", "shutdown",
    // game3d (subset + stubs)
    "clearScreen", "applyCamera", "updateFlyCamera", "setSceneRotation", "applySceneRotation",
    "drawCube", "drawPlane", "drawGrid", "drawAxis", "drawSphere", "drawBox", "loadTexture3d",
    "hasTexture3d", "drawPlaneTextured", "drawCubeTextured", "loadModel", "hasModel", "drawModel",
    "drawModelColored", "drawModelLit", "createBody", "hasBody", "setBodyVelocity",
    "setBodyPosition", "bodyX", "bodyY", "bodyZ", "applyImpulse", "stepPhysics", "stepPhysicsEx",
    "removeBody", "createBoxBody", "setBodyFriction", "setBodyRestitution", "drawBody",
    "enableLighting", "setAmbientLight", "setSunLight", "applyLighting", "setFog", "applyFog",
    "setWind", "followBody", "emitBurst", "updateParticles", "drawParticles", "drawSkyGradient",
    "loadSkyboxFace", "hasSkybox", "drawSkybox", "loadShader", "hasShader", "useShader",
    "stopShader", "setShaderFloat", "setShaderVec3", "drawModelShader", "loadGltf", "hasGltf",
    "drawGltf", "drawGltfLit", "loadGlb", "gltfAnimCount", "playGltfAnim", "stopGltfAnim",
    "updateGltfAnims", "gltfAnimRotY", "setEditMode", "isEditMode", "clearLevel", "addLevelGltf",
    "addLevelModel", "levelCount", "levelType", "levelAsset", "levelX", "levelY", "levelZ",
    "levelScale", "levelRotY", "saveLevel", "loadLevel", "drawLevel", "pickGround", "pickGroundX",
    "pickGroundY", "pickGroundZ", "pickGroundHit", "pickBody", "pickBodyName",
    // gamestate
    "setState", "getState", "isState", "stateTimeMs", "wasStateChanged", "tickState",
    // helpers (game / stopwatch / random2)
    "scoreBonus", "levelFromXp", "xpForScore", "speedMsForLevel", "nowMs", "elapsedMs",
    "seedRandom", "randomRange", "randomList", "shuffleList",
    nullptr,
};

bool isKnownRuntimeName(const std::string& name) {
    for (const char** p = kRuntimeNames; *p; ++p) {
        if (name == *p) return true;
    }
    return false;
}

bool onlyStdlibModules(const ProgramNode& program) {
    for (const auto& mod : program.modules) {
        if (!mod || !mod->isStdlibInjected) return false;
    }
    return true;
}

bool expressionSupported(const ExpressionNode& expr) {
    if (dynamic_cast<const StringLiteralNode*>(&expr)) return true;
    if (dynamic_cast<const NumberLiteralNode*>(&expr)) return true;
    if (dynamic_cast<const BoolLiteralNode*>(&expr)) return true;
    if (dynamic_cast<const IdentifierNode*>(&expr)) return true;
    if (dynamic_cast<const WindowIsOpenExpressionNode*>(&expr)) return true;
    if (dynamic_cast<const EmptyMapNode*>(&expr)) return true;
    if (const auto* interp = dynamic_cast<const InterpolatedStringNode*>(&expr)) {
        for (const auto& part : interp->parts) {
            if (!expressionSupported(*part)) return false;
        }
        return true;
    }
    if (const auto* button = dynamic_cast<const ButtonClickedExpressionNode*>(&expr)) {
        return expressionSupported(*button->label) && expressionSupported(*button->x) &&
               expressionSupported(*button->y) && expressionSupported(*button->width) &&
               expressionSupported(*button->height);
    }
    if (const auto* bin = dynamic_cast<const BinaryOpNode*>(&expr)) {
        static const char* ops[] = {"+", "-", "*", "/", ">", "<", "==", "!=", "&&", "||",
                                    ">=", "<=", "%"};
        bool ok = false;
        for (const char* op : ops) {
            if (bin->op == op) ok = true;
        }
        return ok && expressionSupported(*bin->left) && expressionSupported(*bin->right);
    }
    if (const auto* unary = dynamic_cast<const UnaryOpNode*>(&expr)) {
        return (unary->op == "-" || unary->op == "not") && expressionSupported(*unary->operand);
    }
    if (const auto* call = dynamic_cast<const CallExpressionNode*>(&expr)) {
        if (const auto* mem = dynamic_cast<const MemberAccessNode*>(call->callee.get())) {
            if (!expressionSupported(*mem->object)) return false;
        } else if (!expressionSupported(*call->callee)) {
            return false;
        }
        if (!call->typeArgs.empty()) return false;
        for (const auto& arg : call->arguments) {
            if (!expressionSupported(*arg)) return false;
        }
        return true;
    }
    if (const auto* mem = dynamic_cast<const MemberAccessNode*>(&expr)) {
        return expressionSupported(*mem->object);
    }
    if (const auto* list = dynamic_cast<const ListLiteralNode*>(&expr)) {
        for (const auto& elem : list->elements) {
            if (!expressionSupported(*elem)) return false;
        }
        return true;
    }
    if (const auto* mapLit = dynamic_cast<const MapLiteralNode*>(&expr)) {
        for (const auto& pair : mapLit->pairs) {
            if (!expressionSupported(*pair.key) || !expressionSupported(*pair.value)) return false;
        }
        return true;
    }
    if (const auto* index = dynamic_cast<const IndexExpressionNode*>(&expr)) {
        return expressionSupported(*index->object) && expressionSupported(*index->index);
    }
    return false;
}

bool statementsSupported(const std::vector<std::unique_ptr<StatementNode>>& stmts) {
    for (const auto& stmt : stmts) {
        if (!stmt) return false;
        if (dynamic_cast<const UseStatementNode*>(stmt.get())) continue;
        if (dynamic_cast<const CloseWindowStatementNode*>(stmt.get())) continue;
        if (dynamic_cast<const ShowFrameStatementNode*>(stmt.get())) continue;
        if (dynamic_cast<const BreakStatementNode*>(stmt.get())) continue;
        if (dynamic_cast<const ContinueStatementNode*>(stmt.get())) continue;

        if (const auto* say = dynamic_cast<const SayStatementNode*>(stmt.get())) {
            if (!expressionSupported(*say->value)) return false;
            continue;
        }
        if (const auto* assign = dynamic_cast<const AssignStatementNode*>(stmt.get())) {
            if (!assign->value || !expressionSupported(*assign->value)) return false;
            if (dynamic_cast<const NewExpressionNode*>(assign->value.get())) return false;
            continue;
        }
        if (const auto* setStmt = dynamic_cast<const SetStatementNode*>(stmt.get())) {
            if (!setStmt->value || !expressionSupported(*setStmt->value)) return false;
            if (!dynamic_cast<const IdentifierNode*>(setStmt->target.get())) return false;
            continue;
        }
        if (const auto* idx = dynamic_cast<const IndexAssignStatementNode*>(stmt.get())) {
            if (!expressionSupported(*idx->object) || !expressionSupported(*idx->index) ||
                !expressionSupported(*idx->value)) {
                return false;
            }
            continue;
        }
        if (const auto* add = dynamic_cast<const AddToListStatementNode*>(stmt.get())) {
            if (!expressionSupported(*add->value) || !expressionSupported(*add->list)) return false;
            continue;
        }
        if (const auto* ifStmt = dynamic_cast<const IfStatementNode*>(stmt.get())) {
            if (!expressionSupported(*ifStmt->condition)) return false;
            if (!statementsSupported(ifStmt->thenBody) || !statementsSupported(ifStmt->elseBody)) {
                return false;
            }
            continue;
        }
        if (const auto* whileStmt = dynamic_cast<const WhileStatementNode*>(stmt.get())) {
            if (!expressionSupported(*whileStmt->condition)) return false;
            if (!statementsSupported(whileStmt->body)) return false;
            continue;
        }
        if (const auto* repeat = dynamic_cast<const RepeatStatementNode*>(stmt.get())) {
            if (!expressionSupported(*repeat->count) || !statementsSupported(repeat->body)) {
                return false;
            }
            continue;
        }
        if (const auto* forRange = dynamic_cast<const ForRangeStatementNode*>(stmt.get())) {
            if (!expressionSupported(*forRange->start) || !expressionSupported(*forRange->end)) {
                return false;
            }
            if (forRange->step && !expressionSupported(*forRange->step)) return false;
            if (!statementsSupported(forRange->body)) return false;
            continue;
        }
        if (const auto* forEach = dynamic_cast<const ForEachStatementNode*>(stmt.get())) {
            if (!expressionSupported(*forEach->list) || !statementsSupported(forEach->body)) {
                return false;
            }
            continue;
        }
        if (const auto* macroCall = dynamic_cast<const MacroCallStatementNode*>(stmt.get())) {
            if (macroCall->expanded.empty() || !statementsSupported(macroCall->expanded)) {
                return false;
            }
            continue;
        }
        if (const auto* ret = dynamic_cast<const ReturnStatementNode*>(stmt.get())) {
            if (ret->value && !expressionSupported(*ret->value)) return false;
            continue;
        }
        if (const auto* exprStmt = dynamic_cast<const ExpressionStatementNode*>(stmt.get())) {
            if (!exprStmt->expression || !expressionSupported(*exprStmt->expression)) return false;
            continue;
        }
        if (const auto* openWin = dynamic_cast<const OpenWindowStatementNode*>(stmt.get())) {
            if (!expressionSupported(*openWin->title) || !expressionSupported(*openWin->width) ||
                !expressionSupported(*openWin->height)) {
                return false;
            }
            continue;
        }
        if (const auto* clearBg = dynamic_cast<const ClearBackgroundStatementNode*>(stmt.get())) {
            if (!expressionSupported(*clearBg->red) || !expressionSupported(*clearBg->green) ||
                !expressionSupported(*clearBg->blue)) {
                return false;
            }
            continue;
        }
        if (const auto* drawText = dynamic_cast<const DrawTextStatementNode*>(stmt.get())) {
            if (!expressionSupported(*drawText->text) || !expressionSupported(*drawText->x) ||
                !expressionSupported(*drawText->y) || !expressionSupported(*drawText->fontSize)) {
                return false;
            }
            continue;
        }
        return false;
    }
    return true;
}

} // namespace

std::string compileSourceToJavaScript(const std::string& source,
                                      const std::string& virtualPath) {
    std::string root = ".";
    if (const char* env = std::getenv("AFRILANG_HOME")) {
        root = env;
    }
    Compiler compiler(virtualPath, root);
    std::unique_ptr<ProgramNode> program = compiler.compileFromSource(source);
    SemanticAnalyzer analyzer(*program, &compiler.sources(), virtualPath);
    const SemanticResult semantic = analyzer.analyze();
    if (!supportsJavaScriptPlayground(*program, semantic)) {
        throw CompileError("JS playground: sous-ensemble non supporté "
                           "(classes/async/enums non supportés ; UI/game2d/game3d OK)",
                           0, 0, virtualPath);
    }
    JsCodeGenerator gen(*program, semantic);
    return gen.generate();
}

bool supportsJavaScriptPlayground(const ProgramNode& program,
                                  const SemanticResult& semantic) {
    if (!program.imports.empty()) return false;
    if (!program.classes.empty()) return false;
    if (!onlyStdlibModules(program)) return false;
    if (!program.enums.empty()) return false;
    if (!program.interfaces.empty() || !program.records.empty()) return false;
    if (!program.externs.empty() || !program.tests.empty()) return false;
    if (semantic.usesAsync || semantic.usesGenerators) return false;
    for (const auto& func : program.functions) {
        if (func->isAsync || func->isGenerator || func->isOperator || func->isAbstract) {
            return false;
        }
        if (!func->body.empty() && !statementsSupported(func->body)) return false;
        // Empty-body stdlib stubs are fine (runtime provides them).
    }
    return statementsSupported(program.statements);
}

JsCodeGenerator::JsCodeGenerator(const ProgramNode& program, const SemanticResult& semantic)
    : program_(program), semantic_(semantic) {
    preferGame3d_ = semantic_.usesGame3d;
    needsGui_ = semantic_.usesUi || semantic_.usesGame3d ||
                semantic_.usedModules.count("ui") || semantic_.usedModules.count("game2d") ||
                semantic_.usedModules.count("game3d");
    for (const auto& func : program_.functions) {
        if (func && !func->body.empty()) {
            userFuncs_.insert(func->name);
        }
    }
}

std::string JsCodeGenerator::generate() const {
    std::ostringstream out;
    generate(out);
    return out.str();
}

void JsCodeGenerator::generate(std::ostream& out) const {
    out << "\"use strict\";\n";
    if (needsGui_) {
        out << "return (async function(__rt) {\n";
        out << "  if (!__rt) throw new Error(\"AfrilangPlayground runtime manquant\");\n";
    }
    const int baseIndent = needsGui_ ? 1 : 0;
    for (const auto& func : program_.functions) {
        if (!func || func->body.empty()) continue;
        emitFunction(out, *func);
    }
    for (const auto& stmt : program_.statements) {
        emitStatement(out, *stmt, baseIndent);
    }
    if (needsGui_) {
        out << "})(typeof AfrilangPlayground !== \"undefined\" "
               "? AfrilangPlayground.createRuntime({game3d: "
            << (preferGame3d_ ? "true" : "false") << "}) : null);\n";
    }
}

void JsCodeGenerator::indent(std::ostream& out, int level) {
    for (int i = 0; i < level; ++i) out << "  ";
}

std::string JsCodeGenerator::escapeString(const std::string& s) {
    std::string result;
    result.reserve(s.size());
    for (char c : s) {
        switch (c) {
            case '"': result += "\\\""; break;
            case '\\': result += "\\\\"; break;
            case '\n': result += "\\n"; break;
            case '\r': result += "\\r"; break;
            case '\t': result += "\\t"; break;
            default: result += c; break;
        }
    }
    return result;
}

bool JsCodeGenerator::isRuntimeName(const std::string& name) const {
    return isKnownRuntimeName(name) && !userFuncs_.count(name);
}

void JsCodeGenerator::emitFunction(std::ostream& out, const FunctionNode& func) const {
    if (needsGui_) indent(out, 1);
    if (needsGui_) out << "async ";
    out << "function " << func.name << "(";
    for (std::size_t i = 0; i < func.parameters.size(); ++i) {
        if (i > 0) out << ", ";
        out << func.parameters[i].name;
    }
    out << ") {\n";
    for (const auto& stmt : func.body) {
        emitStatement(out, *stmt, needsGui_ ? 2 : 1);
    }
    if (needsGui_) indent(out, 1);
    out << "}\n";
}

void JsCodeGenerator::emitCall(std::ostream& out, const CallExpressionNode& call) const {
    std::string name;
    bool memberRuntime = false;
    if (const auto* id = dynamic_cast<const IdentifierNode*>(call.callee.get())) {
        name = id->name;
    } else if (const auto* mem = dynamic_cast<const MemberAccessNode*>(call.callee.get())) {
        if (const auto* obj = dynamic_cast<const IdentifierNode*>(mem->object.get())) {
            if (obj->name == "ui" || obj->name == "game2d" || obj->name == "game3d" ||
                obj->name == "gamestate" || obj->name == "game" || obj->name == "stopwatch" ||
                obj->name == "random2") {
                name = mem->member;
                memberRuntime = true;
            }
        }
    }

    const bool runtime = memberRuntime || (!name.empty() && isRuntimeName(name));
    const bool awaitShow = needsGui_ && runtime && name == "showFrame";
    const bool awaitUser =
        needsGui_ && !runtime && !name.empty() && userFuncs_.count(name) > 0;

    if (awaitShow || awaitUser) out << "(await ";

    if (runtime) {
        out << "__rt." << name;
    } else if (const auto* id = dynamic_cast<const IdentifierNode*>(call.callee.get())) {
        out << id->name;
    } else {
        emitExpression(out, *call.callee);
    }
    out << "(";
    for (std::size_t i = 0; i < call.arguments.size(); ++i) {
        if (i > 0) out << ", ";
        emitExpression(out, *call.arguments[i]);
    }
    out << ")";
    if (awaitShow || awaitUser) out << ")";
}

void JsCodeGenerator::emitExpression(std::ostream& out, const ExpressionNode& expr) const {
    if (const auto* str = dynamic_cast<const StringLiteralNode*>(&expr)) {
        out << "\"" << escapeString(str->value) << "\"";
        return;
    }
    if (const auto* num = dynamic_cast<const NumberLiteralNode*>(&expr)) {
        if (num->isInteger) {
            out << static_cast<long long>(num->value);
        } else {
            out << num->value;
        }
        return;
    }
    if (const auto* boolean = dynamic_cast<const BoolLiteralNode*>(&expr)) {
        out << (boolean->value ? "true" : "false");
        return;
    }
    if (const auto* id = dynamic_cast<const IdentifierNode*>(&expr)) {
        out << id->name;
        return;
    }
    if (const auto* interp = dynamic_cast<const InterpolatedStringNode*>(&expr)) {
        out << "(";
        if (interp->parts.empty()) {
            out << "\"\"";
        }
        for (std::size_t i = 0; i < interp->parts.size(); ++i) {
            if (i > 0) out << " + ";
            if (dynamic_cast<const StringLiteralNode*>(interp->parts[i].get())) {
                emitExpression(out, *interp->parts[i]);
            } else {
                out << "String(";
                emitExpression(out, *interp->parts[i]);
                out << ")";
            }
        }
        out << ")";
        return;
    }
    if (const auto* unary = dynamic_cast<const UnaryOpNode*>(&expr)) {
        if (unary->op == "not") out << "!";
        else out << unary->op;
        emitExpression(out, *unary->operand);
        return;
    }
    if (const auto* bin = dynamic_cast<const BinaryOpNode*>(&expr)) {
        out << "(";
        emitExpression(out, *bin->left);
        out << " " << bin->op << " ";
        emitExpression(out, *bin->right);
        out << ")";
        return;
    }
    if (const auto* call = dynamic_cast<const CallExpressionNode*>(&expr)) {
        emitCall(out, *call);
        return;
    }
    if (const auto* mem = dynamic_cast<const MemberAccessNode*>(&expr)) {
        emitExpression(out, *mem->object);
        out << "." << mem->member;
        return;
    }
    if (const auto* list = dynamic_cast<const ListLiteralNode*>(&expr)) {
        out << "[";
        for (std::size_t i = 0; i < list->elements.size(); ++i) {
            if (i > 0) out << ", ";
            emitExpression(out, *list->elements[i]);
        }
        out << "]";
        return;
    }
    if (const auto* mapLit = dynamic_cast<const MapLiteralNode*>(&expr)) {
        out << "({";
        for (std::size_t i = 0; i < mapLit->pairs.size(); ++i) {
            if (i > 0) out << ", ";
            out << "[";
            emitExpression(out, *mapLit->pairs[i].key);
            out << "]: ";
            emitExpression(out, *mapLit->pairs[i].value);
        }
        out << "})";
        return;
    }
    if (dynamic_cast<const EmptyMapNode*>(&expr)) {
        out << "({})";
        return;
    }
    if (const auto* index = dynamic_cast<const IndexExpressionNode*>(&expr)) {
        emitExpression(out, *index->object);
        out << "[";
        emitExpression(out, *index->index);
        out << "]";
        return;
    }
    if (dynamic_cast<const WindowIsOpenExpressionNode*>(&expr)) {
        out << "__rt.isOpen()";
        return;
    }
    if (const auto* button = dynamic_cast<const ButtonClickedExpressionNode*>(&expr)) {
        out << "__rt.drawButton(";
        emitExpression(out, *button->label);
        out << ", ";
        emitExpression(out, *button->x);
        out << ", ";
        emitExpression(out, *button->y);
        out << ", ";
        emitExpression(out, *button->width);
        out << ", ";
        emitExpression(out, *button->height);
        out << ")";
        return;
    }
    out << "null";
}

void JsCodeGenerator::emitStatement(std::ostream& out, const StatementNode& stmt,
                                    int indentLevel) const {
    if (dynamic_cast<const UseStatementNode*>(&stmt)) return;

    indent(out, indentLevel);

    if (const auto* say = dynamic_cast<const SayStatementNode*>(&stmt)) {
        out << "console.log(";
        emitExpression(out, *say->value);
        out << ");\n";
        return;
    }
    if (const auto* assign = dynamic_cast<const AssignStatementNode*>(&stmt)) {
        out << "let " << assign->name << " = ";
        emitExpression(out, *assign->value);
        out << ";\n";
        return;
    }
    if (const auto* setStmt = dynamic_cast<const SetStatementNode*>(&stmt)) {
        if (const auto* id = dynamic_cast<const IdentifierNode*>(setStmt->target.get())) {
            out << id->name << " = ";
            emitExpression(out, *setStmt->value);
            out << ";\n";
        }
        return;
    }
    if (const auto* idx = dynamic_cast<const IndexAssignStatementNode*>(&stmt)) {
        emitExpression(out, *idx->object);
        out << "[";
        emitExpression(out, *idx->index);
        out << "] = ";
        emitExpression(out, *idx->value);
        out << ";\n";
        return;
    }
    if (const auto* add = dynamic_cast<const AddToListStatementNode*>(&stmt)) {
        emitExpression(out, *add->list);
        out << ".push(";
        emitExpression(out, *add->value);
        out << ");\n";
        return;
    }
    if (dynamic_cast<const BreakStatementNode*>(&stmt)) {
        out << "break;\n";
        return;
    }
    if (dynamic_cast<const ContinueStatementNode*>(&stmt)) {
        out << "continue;\n";
        return;
    }
    if (const auto* ifStmt = dynamic_cast<const IfStatementNode*>(&stmt)) {
        out << "if (";
        emitExpression(out, *ifStmt->condition);
        out << ") {\n";
        for (const auto& bodyStmt : ifStmt->thenBody) {
            emitStatement(out, *bodyStmt, indentLevel + 1);
        }
        indent(out, indentLevel);
        out << "}";
        if (!ifStmt->elseBody.empty()) {
            out << " else {\n";
            for (const auto& bodyStmt : ifStmt->elseBody) {
                emitStatement(out, *bodyStmt, indentLevel + 1);
            }
            indent(out, indentLevel);
            out << "}";
        }
        out << "\n";
        return;
    }
    if (const auto* whileStmt = dynamic_cast<const WhileStatementNode*>(&stmt)) {
        const bool windowLoop =
            dynamic_cast<const WindowIsOpenExpressionNode*>(whileStmt->condition.get()) != nullptr;
        out << "while (";
        emitExpression(out, *whileStmt->condition);
        out << ") {\n";
        if (windowLoop) {
            indent(out, indentLevel + 1);
            out << "__rt.beginFrame();\n";
        }
        for (const auto& bodyStmt : whileStmt->body) {
            emitStatement(out, *bodyStmt, indentLevel + 1);
        }
        indent(out, indentLevel);
        out << "}\n";
        return;
    }
    if (const auto* openWin = dynamic_cast<const OpenWindowStatementNode*>(&stmt)) {
        out << "__rt.openWindow(";
        emitExpression(out, *openWin->title);
        out << ", ";
        emitExpression(out, *openWin->width);
        out << ", ";
        emitExpression(out, *openWin->height);
        out << ");\n";
        return;
    }
    if (dynamic_cast<const CloseWindowStatementNode*>(&stmt)) {
        out << "__rt.closeWindow();\n";
        return;
    }
    if (dynamic_cast<const ShowFrameStatementNode*>(&stmt)) {
        out << "await __rt.showFrame();\n";
        return;
    }
    if (const auto* clearBg = dynamic_cast<const ClearBackgroundStatementNode*>(&stmt)) {
        out << "__rt.clearBackground(";
        emitExpression(out, *clearBg->red);
        out << ", ";
        emitExpression(out, *clearBg->green);
        out << ", ";
        emitExpression(out, *clearBg->blue);
        out << ");\n";
        return;
    }
    if (const auto* drawText = dynamic_cast<const DrawTextStatementNode*>(&stmt)) {
        out << "__rt.drawText(";
        emitExpression(out, *drawText->text);
        out << ", ";
        emitExpression(out, *drawText->x);
        out << ", ";
        emitExpression(out, *drawText->y);
        out << ", ";
        emitExpression(out, *drawText->fontSize);
        out << ");\n";
        return;
    }
    if (const auto* forRange = dynamic_cast<const ForRangeStatementNode*>(&stmt)) {
        out << "for (let " << forRange->varName << " = ";
        emitExpression(out, *forRange->start);
        out << "; " << forRange->varName << " <= ";
        emitExpression(out, *forRange->end);
        out << "; " << forRange->varName << " += ";
        if (forRange->step) emitExpression(out, *forRange->step);
        else out << "1";
        out << ") {\n";
        for (const auto& bodyStmt : forRange->body) {
            emitStatement(out, *bodyStmt, indentLevel + 1);
        }
        indent(out, indentLevel);
        out << "}\n";
        return;
    }
    if (const auto* forEach = dynamic_cast<const ForEachStatementNode*>(&stmt)) {
        if (!forEach->valueName.empty()) {
            out << "for (const [" << forEach->itemName << ", " << forEach->valueName
                << "] of Object.entries(";
            emitExpression(out, *forEach->list);
            out << ")) {\n";
        } else {
            out << "for (const " << forEach->itemName << " of ";
            emitExpression(out, *forEach->list);
            out << ") {\n";
        }
        for (const auto& bodyStmt : forEach->body) {
            emitStatement(out, *bodyStmt, indentLevel + 1);
        }
        indent(out, indentLevel);
        out << "}\n";
        return;
    }
    if (const auto* macroCall = dynamic_cast<const MacroCallStatementNode*>(&stmt)) {
        for (const auto& expanded : macroCall->expanded) {
            emitStatement(out, *expanded, indentLevel);
        }
        return;
    }
    if (const auto* ret = dynamic_cast<const ReturnStatementNode*>(&stmt)) {
        out << "return";
        if (ret->value) {
            out << " ";
            emitExpression(out, *ret->value);
        }
        out << ";\n";
        return;
    }
    if (const auto* exprStmt = dynamic_cast<const ExpressionStatementNode*>(&stmt)) {
        emitExpression(out, *exprStmt->expression);
        out << ";\n";
        return;
    }
    if (const auto* repeat = dynamic_cast<const RepeatStatementNode*>(&stmt)) {
        out << "for (let _i = 0; _i < ";
        emitExpression(out, *repeat->count);
        out << "; _i++) {\n";
        for (const auto& bodyStmt : repeat->body) {
            emitStatement(out, *bodyStmt, indentLevel + 1);
        }
        indent(out, indentLevel);
        out << "}\n";
    }
}

} // namespace afrilang
