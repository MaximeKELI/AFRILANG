#include "afrilang/educational.hpp"

#include <iostream>
#include <sstream>

namespace afrilang {

static std::string explainKeyword(const std::string& keyword) {
    if (keyword == "say") {
        return "Affiche du texte ou une valeur à l'écran (équivalent de print() en Python, cout en C++).";
    }
    if (keyword == "create") {
        return "Déclare une nouvelle variable avec une valeur initiale.";
    }
    if (keyword == "if") {
        return "Exécute un bloc de code seulement si la condition est vraie.";
    }
    if (keyword == "while") {
        return "Répète un bloc tant que la condition reste vraie.";
    }
    if (keyword == "repeat") {
        return "Répète un bloc un nombre fixe de fois.";
    }
    if (keyword == "for") {
        return "Parcourt chaque élément d'une liste (for-each).";
    }
    if (keyword == "function") {
        return "Définit une fonction réutilisable avec paramètres et valeur de retour.";
    }
    if (keyword == "class") {
        return "Définit un type objet avec méthodes et champs (programmation orientée objet).";
    }
    if (keyword == "return") {
        return "Renvoie une valeur depuis une fonction.";
    }
    if (keyword == "ask") {
        return "Demande une saisie à l'utilisateur et la stocke dans une variable.";
    }
    if (keyword == "set") {
        return "Modifie la valeur d'une variable ou d'un champ existant.";
    }
    if (keyword == "assert") {
        return "Vérifie qu'une condition est vraie ; échoue si ce n'est pas le cas.";
    }
    if (keyword == "import") {
        return "Importe du code depuis un autre fichier .afr.";
    }
    if (keyword == "use") {
        return "Active un module importé pour l'utiliser sans préfixe.";
    }
    return {};
}

std::string explainStatement(const StatementNode& stmt) {
    if (dynamic_cast<const SayStatementNode*>(&stmt)) {
        return explainKeyword("say");
    }
    if (dynamic_cast<const AssignStatementNode*>(&stmt)) {
        return explainKeyword("create");
    }
    if (dynamic_cast<const SetStatementNode*>(&stmt)) {
        return explainKeyword("set");
    }
    if (dynamic_cast<const IfStatementNode*>(&stmt)) {
        return explainKeyword("if");
    }
    if (dynamic_cast<const WhileStatementNode*>(&stmt)) {
        return explainKeyword("while");
    }
    if (dynamic_cast<const RepeatStatementNode*>(&stmt)) {
        return explainKeyword("repeat");
    }
    if (dynamic_cast<const ForEachStatementNode*>(&stmt)) {
        return explainKeyword("for");
    }
    if (dynamic_cast<const ReturnStatementNode*>(&stmt)) {
        return explainKeyword("return");
    }
    if (dynamic_cast<const AskStatementNode*>(&stmt)) {
        return explainKeyword("ask");
    }
    if (dynamic_cast<const AssertStatementNode*>(&stmt)) {
        return explainKeyword("assert");
    }
    if (dynamic_cast<const UseStatementNode*>(&stmt)) {
        return explainKeyword("use");
    }
    if (dynamic_cast<const BreakStatementNode*>(&stmt)) {
        return "Sort immédiatement de la boucle en cours (équivalent de break).";
    }
    if (dynamic_cast<const ContinueStatementNode*>(&stmt)) {
        return "Passe à l'itération suivante de la boucle (équivalent de continue).";
    }
    if (const auto* explain = dynamic_cast<const ExplainStatementNode*>(&stmt)) {
        return "Mode éducatif : affiche une explication de l'instruction suivante.\n  → "
               + explainStatement(*explain->statement);
    }
    if (dynamic_cast<const AddToListStatementNode*>(&stmt)) {
        return "Ajoute un élément à la fin d'une liste.";
    }
    if (dynamic_cast<const IndexAssignStatementNode*>(&stmt)) {
        return "Modifie un élément d'une liste à un index donné.";
    }
    return "Instruction AFRILANG.";
}

void explainProgram(const ProgramNode& program, int filterLine) {
    auto printIf = [&](const StatementNode& stmt, const std::string& context) {
        if (filterLine > 0 && stmt.loc.line != filterLine) return;
        std::cout << context;
        if (stmt.loc.line > 0) {
            std::cout << " (ligne " << stmt.loc.line << ")";
        }
        std::cout << ":\n  " << explainStatement(stmt) << "\n\n";
    };

    for (const auto& func : program.functions) {
        for (const auto& stmt : func->body) {
            printIf(*stmt, "function " + func->name);
        }
    }

    for (const auto& cls : program.classes) {
        for (const auto& method : cls->methods) {
            for (const auto& stmt : method->body) {
                printIf(*stmt, "class " + cls->name + "." + method->name);
            }
        }
    }

    for (const auto& test : program.tests) {
        for (const auto& stmt : test->body) {
            printIf(*stmt, "test \"" + test->name + "\"");
        }
    }

    for (const auto& stmt : program.statements) {
        printIf(*stmt, "instruction");
    }
}

} // namespace afrilang
