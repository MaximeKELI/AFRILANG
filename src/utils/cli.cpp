#include "afrilang/cli.hpp"
#include "afrilang/educational.hpp"
#include "afrilang/lsp.hpp"
#include "afrilang/pkg.hpp"
#include "afrilang/serve.hpp"

#include "afrilang/codegen.hpp"
#include "afrilang/compiler.hpp"
#include "afrilang/lexer.hpp"
#include "afrilang/parser.hpp"
#include "afrilang/project.hpp"
#include "afrilang/semantic.hpp"

#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

namespace fs = std::filesystem;

namespace afrilang {

std::string detectAfrilangRoot() {
    if (const char* env = std::getenv("AFRILANG_HOME")) {
        return env;
    }

    fs::path exe = fs::read_symlink("/proc/self/exe").parent_path();
    if (fs::exists(exe / "stdlib")) return exe.string();
    if (fs::exists(exe.parent_path() / "stdlib")) return exe.parent_path().string();
    return fs::current_path().string();
}

static void printFileNotFoundHint(const std::string& userPath) {
    const fs::path requested = fs::absolute(userPath);
    const fs::path cwd = fs::current_path();
    const std::string baseName = requested.filename().string();

    std::cerr << "Fichier introuvable: " << requested << "\n";

    if (requested.string().find("/examples/examples/") != std::string::npos) {
        std::cerr << "  Astuce: vous êtes déjà dans examples/ — utilisez:\n";
        std::cerr << "    afrilang run " << baseName << "\n";
        return;
    }

    if (fs::exists(cwd / baseName)) {
        std::cerr << "  Astuce: le fichier est ici — utilisez:\n";
        std::cerr << "    afrilang run " << baseName << "\n";
        return;
    }

    if (fs::exists(cwd / "examples" / baseName)) {
        std::cerr << "  Astuce: le fichier est dans examples/ — utilisez:\n";
        std::cerr << "    afrilang run examples/" << baseName << "\n";
        return;
    }

    if (fs::exists(cwd.parent_path() / "examples" / baseName)) {
        std::cerr << "  Astuce: depuis la racine du projet — utilisez:\n";
        std::cerr << "    afrilang run examples/" << baseName << "\n";
    }
}

static int reportCliException(const std::exception& e, const std::string& userPath = {}) {
    const std::string msg = e.what();
    if (msg.rfind("Impossible d'ouvrir le fichier:", 0) == 0) {
        printFileNotFoundHint(userPath.empty()
            ? msg.substr(std::string("Impossible d'ouvrir le fichier: ").size())
            : userPath);
        return 1;
    }
    std::cerr << "Erreur: " << msg << "\n";
    return 1;
}

static void printUsage() {
    std::cerr << "AFRILANG — compilateur v1.0\n\n";
    std::cerr << "Usage:\n";
    std::cerr << "  afrilang build [projet/]     Compiler un projet (afrilang.toml)\n";
    std::cerr << "  afrilang run <fichier.afr>   Compiler et exécuter\n";
    std::cerr << "  afrilang check <fichier.afr> Vérifier sans compiler\n";
    std::cerr << "  afrilang test                Lancer la suite de tests\n";
    std::cerr << "  afrilang lsp                 Démarrer le serveur LSP\n";
    std::cerr << "  afrilang fmt <fichier.afr>   Formater un fichier\n";
    std::cerr << "  afrilang repl                REPL interactif\n";
    std::cerr << "  afrilang pkg list            Lister les paquets\n";
    std::cerr << "  afrilang pkg search [query]  Rechercher un paquet\n";
    std::cerr << "  afrilang pkg add <name>      Ajouter un paquet\n";
    std::cerr << "  afrilang pkg install         Installer les dépendances\n";
    std::cerr << "  afrilang pkg publish <dir>   Publier dans le registre local\n";
    std::cerr << "  afrilang serve [port]        Playground web local\n";
    std::cerr << "  afrilang explain <fichier>   Mode éducatif (explications)\n";
    std::cerr << "  afrilang init [nom]          Créer un nouveau projet\n";
    std::cerr << "  afrilang lint <fichier.afr>  Analyse statique (warnings)\n";
    std::cerr << "  afrilang doc <fichier.afr>   Générer la doc (Markdown)\n";
    std::cerr << "  afrilang <fichier.afr> [opts] Mode legacy\n\n";
    std::cerr << "Options (mode legacy):\n";
    std::cerr << "  --tokens  --ast  --emit  --run  -o <exe>\n";
}

static void printTokens(const std::vector<Token>& tokens) {
    std::cout << "=== Tokens ===\n";
    for (const auto& token : tokens) {
        std::cout << "  L" << token.line << " C" << token.column << "  " << token << "\n";
    }
    std::cout << "==============\n";
}

CompileResult Pipeline::compileFile(const std::string& sourcePath,
                                    const CompileOptions& options) {
    CompileResult result;
    const fs::path srcPath = fs::absolute(sourcePath);
    const std::string baseName = srcPath.stem().string();

    if (options.showTokens) {
        std::ifstream file(srcPath);
        std::ostringstream buffer;
        buffer << file.rdbuf();
        Lexer lexer(buffer.str());
        printTokens(lexer.tokenize());
    }

    Compiler compiler(srcPath.string(), detectAfrilangRoot());
    std::unique_ptr<ProgramNode> program = compiler.compile();

    if (options.showAST) {
        std::cout << "=== AST ===\n";
        std::cout << "Classes: " << program->classes.size() << "\n";
        std::cout << "Functions: " << program->functions.size() << "\n";
        std::cout << "Modules: " << program->modules.size() << "\n";
        std::cout << "===========\n";
    }

    SemanticAnalyzer analyzer(*program, &compiler.sources(), srcPath.string());
    const SemanticResult semantic = analyzer.analyze();

    CodeGenerator codegen(*program, semantic);
    codegen.setRuntimeDir(options.runtimeDir.empty() ? detectAfrilangRoot() + "/runtime"
                                                     : options.runtimeDir);
    codegen.setSourceFile(srcPath.string());
    codegen.setDebugSymbols(options.debugSymbols);
    codegen.setCrossTarget(options.crossTarget);

    result.generatedCpp = baseName + ".generated.cpp";
    result.executable = options.outputExecutable.empty() ? baseName : options.outputExecutable;

    if (options.emitOnly) {
        std::ofstream out(result.generatedCpp);
        codegen.generate(out);
        result.success = true;
        return result;
    }

    std::cout << "Compilation de " << sourcePath << "...\n";

    if (!codegen.compileToExecutable(result.generatedCpp, result.executable)) {
        std::cerr << "Erreur: la compilation g++ a échoué.\n";
        std::cerr << "Consultez " << result.generatedCpp << " pour le code généré.\n";
        return result;
    }

    result.success = true;
    std::cout << "Exécutable produit: " << result.executable << "\n";

    if (options.runAfter) {
        std::cout << "--- Exécution ---\n";
        const int code = std::system(("./" + result.executable).c_str());
        std::cout << "--- Fin (code: " << code << ") ---\n";
    }

    return result;
}

bool Pipeline::checkFile(const std::string& sourcePath) {
    try {
        const fs::path srcPath = fs::absolute(sourcePath);
        if (!fs::exists(srcPath)) {
            printFileNotFoundHint(sourcePath);
            return false;
        }
        Compiler compiler(srcPath.string(), detectAfrilangRoot());
        std::unique_ptr<ProgramNode> program = compiler.compile();
        SemanticAnalyzer analyzer(*program, &compiler.sources(), srcPath.string());
        analyzer.analyze();
        std::cout << "OK — " << sourcePath << " (aucune erreur)\n";
        return true;
    } catch (const CompileError& e) {
        std::cerr << e.format();
        return false;
    } catch (const std::exception& e) {
        reportCliException(e, sourcePath);
        return false;
    }
}

int Pipeline::runTests(const std::string& afrilangRoot) {
    int failures = 0;
    const fs::path root(afrilangRoot);

    std::cout << "=== Tests AFRILANG ===\n\n";

    const std::vector<std::string> examples = {
        "hello.afr", "oop.afr", "conditions.afr", "inheritance.afr",
        "functions.afr", "while.afr", "lists.afr", "modules.afr",
        "fields.afr", "records.afr", "full_demo.afr", "stdlib_demo.afr",
        "result.afr", "interfaces.afr", "tests.afr",
        "ffi.afr", "pkg_demo.afr",
        "natural.afr", "educational.afr",
        "advanced.afr", "fs_demo.afr",
        "generics.afr", "maps.afr", "exceptions.afr", "phase9_demo.afr",
        "defaults.afr", "phase10_demo.afr", "lambdas.afr", "list_ops.afr",
        "natural_list_ops.afr", "poo_demo.afr", "oop_full.afr",
        "polymorphic_list.afr", "generic_class.afr", "poo_advanced.afr",
        "args_path_demo.afr", "phase11_demo.afr", "async_demo.afr", "async_full.afr",
        "gui_demo.afr", "simple_libs_demo.afr"
    };

    CompileOptions opts;
    opts.runtimeDir = (root / "runtime").string();

    std::cout << "[examples]\n";
    for (const auto& ex : examples) {
        const std::string path = (root / "examples" / ex).string();
        std::cout << "  " << ex << " ... ";
        std::cout.flush();
        try {
            auto result = compileFile(path, opts);
            if (result.success) {
                std::cout << "OK\n";
            } else {
                std::cout << "FAIL\n";
                ++failures;
            }
        } catch (const CompileError&) {
            std::cout << "FAIL\n";
            ++failures;
        }
    }

    if (fs::exists(root / "examples" / "stdlib_demo.afr")) {
        std::cout << "  stdlib_demo.afr ... ";
        std::cout.flush();
        try {
            auto result = compileFile((root / "examples/stdlib_demo.afr").string(), opts);
            std::cout << (result.success ? "OK\n" : "FAIL\n");
            if (!result.success) ++failures;
        } catch (const CompileError&) {
            std::cout << "FAIL\n";
            ++failures;
        }
    }

    std::cout << "\n";
    if (failures == 0) {
        std::cout << "Tous les tests passent.\n";
    } else {
        std::cout << failures << " test(s) en échec.\n";
    }
    return failures;
}

static int cmdBuild(int argc, char* argv[]) {
    std::string projectDir;
    std::string target = "native";
    for (int i = 2; i < argc; ++i) {
        const std::string arg = argv[i];
        if (arg == "--target" && i + 1 < argc) {
            target = argv[++i];
        } else if (arg.rfind("--", 0) != 0 && projectDir.empty()) {
            projectDir = arg;
        }
    }

    const fs::path dir = projectDir.empty() ? fs::current_path() : fs::path(projectDir);
    const fs::path configPath = dir / "afrilang.toml";

    if (!fs::exists(configPath)) {
        std::cerr << "Erreur: afrilang.toml introuvable dans " << dir << "\n";
        std::cerr << "Utilisez 'afrilang init' pour créer un projet.\n";
        return 1;
    }

    ProjectConfig config = loadProjectConfig(configPath.string());
    const fs::path mainFile = dir / config.mainFile;
    if (!fs::exists(mainFile)) {
        std::cerr << "Erreur: fichier principal introuvable: " << mainFile << "\n";
        return 1;
    }

    fs::create_directories(dir / "build");

    CompileOptions opts;
    opts.outputExecutable = (dir / config.output).string();
    opts.runtimeDir = (fs::path(detectAfrilangRoot()) / "runtime").string();
    opts.crossTarget = target;

    if (target != "native") {
        std::cout << "Cible de compilation: " << target << "\n";
    }

    const fs::path oldCwd = fs::current_path();
    fs::current_path(dir / "build");

    try {
        auto result = Pipeline::compileFile(mainFile.string(), opts);
        fs::current_path(oldCwd);
        return result.success ? 0 : 1;
    } catch (const CompileError& e) {
        fs::current_path(oldCwd);
        std::cerr << e.format();
        return 1;
    } catch (const std::exception& e) {
        fs::current_path(oldCwd);
        return reportCliException(e, mainFile.string());
    }
}

static int cmdRun(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: afrilang run <fichier.afr> [--target <cible>]\n";
        return 1;
    }

    CompileOptions opts;
    opts.runAfter = true;
    opts.runtimeDir = (fs::path(detectAfrilangRoot()) / "runtime").string();
    std::string file = argv[2];
    for (int i = 3; i < argc; ++i) {
        if (std::string(argv[i]) == "--target" && i + 1 < argc) {
            opts.crossTarget = argv[++i];
        }
    }

    const fs::path absPath = fs::absolute(file);
    if (!fs::exists(absPath)) {
        printFileNotFoundHint(file);
        return 1;
    }

    try {
        auto result = Pipeline::compileFile(file, opts);
        return result.success ? 0 : 1;
    } catch (const CompileError& e) {
        std::cerr << e.format();
        return 1;
    } catch (const std::exception& e) {
        return reportCliException(e, file);
    }
}

static int cmdExplain(const std::string& file, int lineFilter) {
    try {
        const fs::path srcPath = fs::absolute(file);
        Compiler compiler(srcPath.string(), detectAfrilangRoot());
        auto program = compiler.compile();
        SemanticAnalyzer analyzer(*program, &compiler.sources(), srcPath.string());
        analyzer.analyze();
        std::cout << "=== Mode éducatif AFRILANG ===\n\n";
        explainProgram(*program, lineFilter);
        return 0;
    } catch (const CompileError& e) {
        std::cerr << e.format();
        return 1;
    } catch (const std::exception& e) {
        return reportCliException(e, file);
    }
}

static int cmdInit(const std::string& name) {
    const std::string projectName = name.empty() ? "mon_projet" : name;
    const fs::path dir = fs::current_path() / projectName;

    if (fs::exists(dir)) {
        std::cerr << "Erreur: le dossier '" << projectName << "' existe déjà.\n";
        return 1;
    }

    fs::create_directories(dir / "src");
    fs::create_directories(dir / "tests");
    fs::create_directories(dir / "build");

    {
        std::ofstream cfg(dir / "afrilang.toml");
        cfg << "name = \"" << projectName << "\"\n";
        cfg << "version = \"0.1.0\"\n";
        cfg << "main = \"src/main.afr\"\n";
        cfg << "output = \"build/" << projectName << "\"\n";
    }

    {
        std::ofstream main(dir / "src/main.afr");
        main << "say \"Bonjour depuis " << projectName << "!\"\n";
    }

    {
        std::ofstream test(dir / "tests/smoke.afr");
        test << "say \"Test OK\"\n";
    }

    std::cout << "Projet '" << projectName << "' créé.\n";
    std::cout << "  cd " << projectName << "\n";
    std::cout << "  afrilang build\n";
    std::cout << "  afrilang run src/main.afr\n";
    return 0;
}

static int legacyMode(int argc, char* argv[]) {
    CompileOptions opts;
    std::string sourcePath = argv[1];

    for (int i = 2; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--tokens") opts.showTokens = true;
        else if (arg == "--ast") opts.showAST = true;
        else if (arg == "--emit") opts.emitOnly = true;
        else if (arg == "--run") opts.runAfter = true;
        else if (arg == "--target" && i + 1 < argc) opts.crossTarget = argv[++i];
        else if (arg == "-o" && i + 1 < argc) opts.outputExecutable = argv[++i];
        else {
            std::cerr << "Option inconnue: " << arg << "\n";
            return 1;
        }
    }

    opts.runtimeDir = (fs::path(detectAfrilangRoot()) / "runtime").string();

    try {
        auto result = Pipeline::compileFile(sourcePath, opts);
        return result.success ? 0 : 1;
    } catch (const CompileError& e) {
        std::cerr << e.format();
        return 1;
    } catch (const std::exception& e) {
        return reportCliException(e, sourcePath);
    }
}

static int cmdLint(const std::string& sourcePath) {
    if (Pipeline::checkFile(sourcePath)) {
        std::cout << "lint: OK (no errors)\n";
        return 0;
    }
    return 1;
}

static int cmdDoc(const std::string& sourcePath) {
    try {
        const fs::path srcPath = fs::absolute(sourcePath);
        Compiler compiler(srcPath.string(), detectAfrilangRoot());
        std::unique_ptr<ProgramNode> program = compiler.compile();
        std::cout << "# " << srcPath.filename().string() << "\n\n";
        for (const auto& func : program->functions) {
            std::cout << "## function " << func->name << "\n\n";
            if (!func->returnTypeName.empty()) {
                std::cout << "Returns `" << func->returnTypeName << "`\n\n";
            }
        }
        for (const auto& cls : program->classes) {
            std::cout << "## class " << cls->name << "\n\n";
        }
        for (const auto& test : program->tests) {
            std::cout << "## test \"" << test->name << "\"\n\n";
        }
        return 0;
    } catch (const CompileError& e) {
        std::cerr << e.format();
        return 1;
    } catch (const std::exception& e) {
        return reportCliException(e, sourcePath);
    }
}

int runCli(int argc, char* argv[]) {
    if (argc < 2) {
        printUsage();
        return 1;
    }

    const std::string cmd = argv[1];

    if (cmd == "build") {
        return cmdBuild(argc, argv);
    }
    if (cmd == "run") {
        return cmdRun(argc, argv);
    }
    if (cmd == "check") {
        if (argc < 3) { std::cerr << "Usage: afrilang check <fichier.afr>\n"; return 1; }
        return Pipeline::checkFile(argv[2]) ? 0 : 1;
    }
    if (cmd == "test") {
        return Pipeline::runTests(argc > 2 ? argv[2] : detectAfrilangRoot());
    }
    if (cmd == "lsp") {
        return afrilang::runLspServer();
    }
    if (cmd == "fmt") {
        if (argc < 3) {
            std::cerr << "Usage: afrilang fmt <fichier.afr> [-w]\n";
            return 1;
        }
        bool writeBack = false;
        for (int i = 3; i < argc; ++i) {
            if (std::string(argv[i]) == "-w" || std::string(argv[i]) == "--write") {
                writeBack = true;
            }
        }
        return Pipeline::formatFile(argv[2], writeBack) ? 0 : 1;
    }
    if (cmd == "repl") {
        return runRepl();
    }
    if (cmd == "pkg") {
        if (argc < 3) {
            std::cerr << "Usage: afrilang pkg <list|search|add|install|publish> [args]\n";
            return 1;
        }
        const std::string sub = argv[2];
        const std::string root = detectAfrilangRoot();
        const std::string dir = fs::current_path().string();
        if (sub == "list") return PkgRegistry::cmdList(root);
        if (sub == "search") {
            const std::string query = argc >= 4 ? argv[3] : "";
            return PkgRegistry::cmdSearch(root, query);
        }
        if (sub == "add") {
            if (argc < 4) {
                std::cerr << "Usage: afrilang pkg add <name>\n";
                return 1;
            }
            return PkgRegistry::cmdAdd(dir, argv[3], root);
        }
        if (sub == "install") return PkgRegistry::cmdInstall(dir, root);
        if (sub == "publish") {
            const std::string pkgDir = argc >= 4 ? argv[3] : dir;
            return PkgRegistry::cmdPublish(pkgDir, root);
        }
        std::cerr << "Sous-commande pkg inconnue: " << sub << "\n";
        return 1;
    }
    if (cmd == "serve") {
        int port = 8080;
        if (argc >= 3) port = std::stoi(argv[2]);
        return runHttpServer(port, (fs::path(detectAfrilangRoot()) / "site").string());
    }
    if (cmd == "explain") {
        if (argc < 3) {
            std::cerr << "Usage: afrilang explain <fichier.afr> [--line N]\n";
            return 1;
        }
        int lineFilter = 0;
        for (int i = 3; i < argc; ++i) {
            if (std::string(argv[i]) == "--line" && i + 1 < argc) {
                lineFilter = std::stoi(argv[++i]);
            }
        }
        return cmdExplain(argv[2], lineFilter);
    }
    if (cmd == "init") {
        return cmdInit(argc > 2 ? argv[2] : "");
    }
    if (cmd == "lint") {
        if (argc < 3) { std::cerr << "Usage: afrilang lint <fichier.afr>\n"; return 1; }
        return cmdLint(argv[2]);
    }
    if (cmd == "doc") {
        if (argc < 3) { std::cerr << "Usage: afrilang doc <fichier.afr>\n"; return 1; }
        return cmdDoc(argv[2]);
    }
    if (cmd == "--help" || cmd == "-h") {
        printUsage();
        return 0;
    }

    if (cmd.size() > 4 && cmd.substr(cmd.size() - 4) == ".afr") {
        return legacyMode(argc, argv);
    }

    std::cerr << "Commande inconnue: " << cmd << "\n";
    printUsage();
    return 1;
}

} // namespace afrilang
