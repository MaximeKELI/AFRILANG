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
#include "afrilang/cache.hpp"
#include "afrilang/debug.hpp"
#include "afrilang/debug_meta.hpp"
#include "afrilang/env.hpp"
#include "afrilang/target.hpp"
#include "afrilang/sandbox.hpp"
#include "afrilang/security.hpp"
#include "afrilang/semantic.hpp"
#include "afrilang/js_codegen.hpp"
#include "afrilang/formatter.hpp"

#include "afrilang/version.hpp"

#include <cstdlib>
#include <chrono>
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <thread>
#include <sstream>
#include <vector>

#if defined(__APPLE__)
#include <mach-o/dyld.h>
#endif

namespace fs = std::filesystem;

namespace afrilang {

namespace {

fs::path executableDirectory() {
#if defined(__linux__)
    try {
        return fs::weakly_canonical(fs::read_symlink("/proc/self/exe")).parent_path();
    } catch (...) {
        return {};
    }
#elif defined(__APPLE__)
    char path[4096];
    uint32_t size = sizeof(path);
    if (_NSGetExecutablePath(path, &size) == 0) {
        return fs::weakly_canonical(fs::path(path)).parent_path();
    }
    return {};
#else
    return {};
#endif
}

bool hasRuntimeLayout(const fs::path& root) {
    return fs::exists(root / "stdlib") && fs::exists(root / "runtime");
}

} // namespace

std::string detectAfrilangRoot() {
    if (const char* env = std::getenv("AFRILANG_HOME")) {
        return env;
    }

    const fs::path exeDir = executableDirectory();
    if (!exeDir.empty()) {
        const std::vector<fs::path> candidates = {
            exeDir,
            exeDir.parent_path(),
            exeDir.parent_path() / "share" / "afrilang",
            exeDir.parent_path().parent_path() / "share" / "afrilang",
        };
        for (const auto& candidate : candidates) {
            if (!candidate.empty() && hasRuntimeLayout(candidate)) {
                return fs::weakly_canonical(candidate).string();
            }
        }
    }

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
    std::cerr << "AFRILANG — compilateur v" << kVersion << "\n\n";
    std::cerr << "Usage:\n";
    std::cerr << "  afrilang version             Afficher la version\n";
    std::cerr << "  afrilang build [projet/]     Compiler un projet (afrilang.toml)\n";
    std::cerr << "  afrilang run <fichier.afr>   Compiler et exécuter [--watch] [--profile]\n";
    std::cerr << "  afrilang check <fichier.afr> [--error-limit N]\n";
    std::cerr << "  afrilang test [--examples|--specs] [--coverage]\n";
    std::cerr << "      Tests projet | exemples | specs (tests/specs + tests/stdlib)\n";
    std::cerr << "  afrilang lsp                 Démarrer le serveur LSP\n";
    std::cerr << "  afrilang fmt <fichier.afr>   Formater un fichier\n";
    std::cerr << "  afrilang repl                REPL interactif\n";
    std::cerr << "  afrilang pkg list [--blessed] Lister les paquets\n";
    std::cerr << "  afrilang pkg search [query] [--blessed]  Rechercher un paquet\n";
    std::cerr << "  afrilang pkg add <name> [--git URL|--path DIR] [--tag T]\n";
    std::cerr << "  afrilang pkg install         Installer depuis afrilang.lock / toml\n";
    std::cerr << "  afrilang pkg update          Re-résoudre et régénérer le lock\n";
    std::cerr << "  afrilang pkg init [nom] [--template lib|cli|http|game]\n";
    std::cerr << "  afrilang pkg test [dir]      Tester un paquet (self-vendor)\n";
    std::cerr << "  afrilang pkg publish <dir> [--remote]  Publier (local / registre)\n";
    std::cerr << "  afrilang pkg sign <name> <privHex>  Signer (Ed25519) le hash du paquet\n";
    std::cerr << "  afrilang pkg verify <name>   Vérifier checksum + signature\n";
    std::cerr << "  afrilang pkg sync            Télécharger l'index distant\n";
    std::cerr << "  afrilang debug <fichier>      Débugger avec GDB\n";
    std::cerr << "  afrilang benchmark           Mesurer compile + exec (exemples)\n";
    std::cerr << "  afrilang serve [port]        Playground web local\n";
    std::cerr << "  afrilang compile-js <fichier> Transpiler vers JavaScript (stdout)\n";
    std::cerr << "  afrilang build-wasm-web <fichier> -o <dir>  Module WASM navigateur\n";
    std::cerr << "  afrilang explain <fichier>   Mode éducatif (explications)\n";
    std::cerr << "  afrilang init [nom] [--lib]  Créer un projet (ou paquet avec --lib)\n";
    std::cerr << "  afrilang lint <fichier.afr>  Analyse statique (warnings)\n";
    std::cerr << "  afrilang doc <fichier|dir>   Doc Markdown (stdout ou docs/api/)\n";
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

static bool validateCrossTarget(const std::string& target) {
    if (isKnownCrossTarget(target)) return true;
    std::cerr << "Erreur: cible inconnue '" << target << "'.\n";
    std::cerr << "Cibles valides: native, linux-x64, linux-arm64, wasm32\n";
    return false;
}

static bool sourceUsesGui(const std::string& source) {
    return source.find("open window") != std::string::npos ||
           source.find("openWindow") != std::string::npos ||
           source.find("import \"std/ui\"") != std::string::npos ||
           source.find("import \"std/game2d\"") != std::string::npos ||
           source.find("import \"std/game3d\"") != std::string::npos ||
           source.find("use ui") != std::string::npos ||
           source.find("use game2d") != std::string::npos ||
           source.find("use game3d") != std::string::npos;
}

static void applyGuiExecConfig(ProcessConfig& config) {
    config.interactiveGui = true;
    config.newSession = false;
    config.timeoutSeconds = 0;
    config.limitProcessCount = false;
    config.maxCpuSeconds = 0;
}

static void applyInteractiveConsoleConfig(ProcessConfig& config) {
    config.interactiveConsole = true;
    config.newSession = false;
    config.timeoutSeconds = 0;
    config.limitProcessCount = false;
    config.maxCpuSeconds = 0;
}

static ExecResult runCompiledProgram(const std::string& crossTarget,
                                     const std::string& executable,
                                     const ProcessConfig& config) {
    if (isWasmTarget(crossTarget)) {
        return execSandboxed("node", {executable}, config);
    }
    return execSandboxed("./" + executable, {}, config);
}

CompileResult Pipeline::compileFile(const std::string& sourcePath,
                                    const CompileOptions& options) {
    CompileResult result;
    try {
        const std::string crossTarget = normalizeCrossTarget(options.crossTarget);
        if (!validateCrossTarget(options.crossTarget)) {
            Diagnostic d;
            d.severity = DiagnosticSeverity::Error;
            d.code = ErrorCode::Generic;
            d.message = "Cible de cross-compilation invalide: " + options.crossTarget;
            result.diagnostics.push_back(std::move(d));
            return result;
        }

        const fs::path srcPath = fs::absolute(sourcePath);
        if (!fs::exists(srcPath)) {
            printFileNotFoundHint(sourcePath);
            Diagnostic d;
            d.severity = DiagnosticSeverity::Error;
            d.code = ErrorCode::Generic;
            d.message = "Fichier introuvable: " + sourcePath;
            result.diagnostics.push_back(std::move(d));
            return result;
        }

        const std::string baseName = srcPath.stem().string();
        const std::string root = detectAfrilangRoot();
        const std::string runtimeDir = options.runtimeDir.empty()
            ? root + "/runtime"
            : options.runtimeDir;

        if (options.showTokens) {
            std::ifstream file(srcPath);
            std::ostringstream buffer;
            buffer << file.rdbuf();
            Lexer lexer(buffer.str());
            printTokens(lexer.tokenize());
        }

        Compiler compiler(srcPath.string(), root);
        compiler.setErrorLimit(options.errorLimit);
        std::unique_ptr<ProgramNode> program = compiler.compile();

        for (const auto& d : compiler.diagnostics().diagnostics()) {
            result.diagnostics.push_back(d);
        }

        if (options.showAST) {
            std::cout << "=== AST ===\n";
            std::cout << "Classes: " << program->classes.size() << "\n";
            std::cout << "Functions: " << program->functions.size() << "\n";
            std::cout << "Modules: " << program->modules.size() << "\n";
            std::cout << "===========\n";
        }

        SemanticAnalyzer analyzer(*program, &compiler.sources(), srcPath.string());
        analyzer.setErrorLimit(options.errorLimit);
        const SemanticResult semantic = analyzer.analyze();
        for (const auto& d : semantic.errors) {
            result.diagnostics.push_back(d);
        }

        const bool hasErrors = compiler.hasErrors() || semantic.hasErrors();
        if (hasErrors) {
            DiagnosticEngine printer(options.errorLimit);
            for (const auto& d : result.diagnostics) printer.report(d);
            std::cerr << printer.formatAll();
            return result;
        }

        CodeGenerator codegen(*program, semantic);
        codegen.setRuntimeDir(runtimeDir);
        codegen.setSourceFile(srcPath.string());
        codegen.setDebugSymbols(options.debugSymbols);
        codegen.setCrossTarget(crossTarget);
        codegen.setCoverageMode(options.coverageMode);

        result.generatedCpp = baseName + ".generated.cpp";
        std::string executable = options.outputExecutable.empty() ? baseName : options.outputExecutable;
        if (fs::exists(executable) && fs::is_directory(executable)) {
            executable = baseName + "_bin";
        }
        if (isWasmTarget(crossTarget)) {
            executable = baseName + ".js";
        }
        result.executable = executable;

        if (options.emitOnly) {
            std::ofstream out(result.generatedCpp);
            codegen.generate(out);
            result.success = true;
            return result;
        }

        std::cout << "Compilation de " << sourcePath << "...\n";

        const auto compileStart = std::chrono::steady_clock::now();

        std::ifstream sourceIn(srcPath);
        std::ostringstream sourceBuf;
        sourceBuf << sourceIn.rdbuf();
        const std::string sourceContent = sourceBuf.str();
        const std::string projectDir = srcPath.parent_path().string();
        const CompileCache cache(projectDir);

        CacheFingerprintInput fpIn;
        fpIn.sourceContent = sourceContent;
        for (const auto& [path, file] : compiler.sources().files()) {
            if (path != srcPath.string()) {
                fpIn.importContents.push_back(file.content);
            }
        }
        fpIn.compilerVersion = kVersion;
        fpIn.crossTarget = crossTarget;
        fpIn.debugSymbols = options.debugSymbols;
        fpIn.coverageMode = options.coverageMode;
        fpIn.runtimeDir = runtimeDir;
        fpIn.stdlibStamp = "stdlib-v1";
        const std::string fingerprint = CompileCache::buildFingerprint(fpIn);

        if (options.useCache) {
            const CompileCacheEntry cached = cache.lookup(srcPath.string());
            if (cached.valid && cached.sourceHash == fingerprint &&
                fs::exists(result.executable)) {
                result.success = true;
                std::cout << "Cache: exécutable à jour (" << result.executable << ")\n";
                if (options.runAfter) {
                    std::cout << "--- Exécution ---\n" << std::flush;
                    const auto execStart = std::chrono::steady_clock::now();
                    const auto limits = securityLimits(SecurityContext::TrustedCompile);
                    ProcessConfig config;
                    config.timeoutSeconds = limits.execTimeoutSeconds;
                    config.maxMemoryMb = limits.maxMemoryMb;
                    config.maxCpuSeconds = limits.maxCpuSeconds;
                    config.maxOutputBytes = limits.maxOutputBytes;
                    const bool needsSpawn =
                        semantic.usesAsync || semantic.usedModules.count("process") > 0 ||
                        semantic.usedModules.count("thread") > 0 ||
                        semantic.usedModules.count("net") > 0;
                    config.limitProcessCount = !needsSpawn;
                    if (semantic.usesUi || semantic.usesGame3d || sourceUsesGui(sourceContent)) {
                        applyGuiExecConfig(config);
                    } else if (semantic.usesAsk) {
                        applyInteractiveConsoleConfig(config);
                    }
                    const ExecResult exec = runCompiledProgram(crossTarget, result.executable, config);
                    if (!exec.output.empty()) std::cout << exec.output;
                    const auto execMs = std::chrono::duration_cast<std::chrono::milliseconds>(
                        std::chrono::steady_clock::now() - execStart).count();
                    std::cout << "--- Fin (code: " << exec.exitCode << ") ---\n";
                    if (options.profileMode) {
                        std::cout << "[profile] exec: " << execMs << " ms (cache hit)\n";
                    }
                    if (exec.exitCode != 0 || exec.timedOut) {
                        result.success = false;
                    }
                }
                return result;
            }
        }

        if (!codegen.compileToExecutable(result.generatedCpp, result.executable)) {
            const char* compilerName = isWasmTarget(crossTarget) ? "em++" : "g++";
            std::cerr << "Erreur: la compilation " << compilerName << " a échoué.\n";
            if (isWasmTarget(crossTarget)) {
                std::cerr << "Installez Emscripten (emsdk) et assurez-vous que em++ est dans le PATH.\n";
            }
            std::cerr << "Consultez " << result.generatedCpp << " pour le code généré.\n";
            Diagnostic d;
            d.severity = DiagnosticSeverity::Error;
            d.code = ErrorCode::Generic;
            d.message = std::string("Échec de compilation ") + compilerName;
            d.file = srcPath.string();
            result.diagnostics.push_back(std::move(d));
            return result;
        }

        result.success = true;
        if (options.debugSymbols) {
            writeDebugMetadata(result.executable + ".afr.debug.json", *program, semantic,
                               srcPath.string());
        }
        if (options.useCache) {
            cache.store(srcPath.string(), fingerprint, fs::absolute(result.executable).string());
        }
        const auto compileMs = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now() - compileStart).count();
        if (isWasmTarget(crossTarget)) {
            const fs::path wasmPath = fs::path(result.executable).replace_extension(".wasm");
            std::cout << "Module WASM produit: " << wasmPath.filename().string()
                      << " (+ " << result.executable << ")\n";
        } else {
            std::cout << "Exécutable produit: " << result.executable << "\n";
        }
        if (options.profileMode) {
            std::cout << "[profile] compile: " << compileMs << " ms\n";
        }

        if (options.runAfter) {
            std::cout << "--- Exécution ---\n" << std::flush;
            const auto execStart = std::chrono::steady_clock::now();
            const auto limits = securityLimits(SecurityContext::TrustedCompile);
            ProcessConfig config;
            config.timeoutSeconds = limits.execTimeoutSeconds;
            config.maxMemoryMb = limits.maxMemoryMb;
            config.maxCpuSeconds = limits.maxCpuSeconds;
            config.maxOutputBytes = limits.maxOutputBytes;
            const bool needsSpawn =
                semantic.usesAsync || semantic.usedModules.count("process") > 0 ||
                semantic.usedModules.count("thread") > 0 ||
                semantic.usedModules.count("net") > 0;
            config.limitProcessCount = !needsSpawn;
            if (semantic.usesUi || semantic.usesGame3d || sourceUsesGui(sourceContent)) {
                applyGuiExecConfig(config);
            } else if (semantic.usesAsk) {
                applyInteractiveConsoleConfig(config);
            }
            const ExecResult exec = runCompiledProgram(crossTarget, result.executable, config);
            if (!exec.output.empty()) {
                std::cout << exec.output;
            }
            if (exec.timedOut) {
                std::cerr << "Exécution interrompue (timeout " << config.timeoutSeconds << "s)\n";
            }
            const auto execMs = std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::steady_clock::now() - execStart).count();
            std::cout << "--- Fin (code: " << exec.exitCode << ") ---\n";
            if (options.profileMode) {
                std::cout << "[profile] exec: " << execMs << " ms\n";
                std::cout << "[profile] total: " << (compileMs + execMs) << " ms\n";
            }
            if (exec.exitCode != 0 || exec.timedOut) {
                result.success = false;
            }
        }

        return result;
    } catch (const CompileError& e) {
        result.diagnostics.push_back(e.toDiagnostic());
        std::cerr << e.format();
        return result;
    } catch (const std::exception& e) {
        reportCliException(e, sourcePath);
        Diagnostic d;
        d.severity = DiagnosticSeverity::Error;
        d.code = ErrorCode::Generic;
        d.message = e.what();
        d.file = sourcePath;
        result.diagnostics.push_back(std::move(d));
        return result;
    }
}

bool Pipeline::checkFile(const std::string& sourcePath, std::size_t errorLimit) {
    try {
        const fs::path srcPath = fs::absolute(sourcePath);
        if (!fs::exists(srcPath)) {
            printFileNotFoundHint(sourcePath);
            return false;
        }
        Compiler compiler(srcPath.string(), detectAfrilangRoot());
        compiler.setErrorLimit(errorLimit);
        std::unique_ptr<ProgramNode> program = compiler.compile();
        SemanticAnalyzer analyzer(*program, &compiler.sources(), srcPath.string());
        analyzer.setErrorLimit(errorLimit);
        const SemanticResult semantic = analyzer.analyze();

        DiagnosticEngine all(errorLimit);
        for (const auto& d : compiler.diagnostics().diagnostics()) all.report(d);
        for (const auto& d : semantic.errors) all.report(d);
        for (const auto& w : semantic.warnings) {
            all.reportWarning(w.message, w.line, w.column, w.file);
        }

        if (all.hasErrors()) {
            std::cerr << all.formatAll();
            return false;
        }

        if (!all.warnings().empty()) {
            std::cout << all.formatAll();
        }
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

static int runExampleSuite(const fs::path& root, bool coverage) {
    int failures = 0;
    int passed = 0;

    std::cout << "=== Tests AFRILANG (exemples) ===\n\n";

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
        "gui_demo.afr", "simple_libs_demo.afr", "medium_libs_demo.afr",
        "complex_libs_demo.afr",
        "language_demo.afr",
        "traits_demo.afr",
        "match_expr_demo.afr",
        "unions_demo.afr",
        "operators_demo.afr",
        "tier1_demo.afr",
        "tier2_demo.afr",
        "tier3_demo.afr",
        "tier4_demo.afr",
        "tier5_demo.afr",
        "tier6_demo.afr",
        "tier7_demo.afr",
        "tier8_demo.afr",
        "tier9_demo.afr",
        "tier10_demo.afr",
        "giskit_demo.afr",
        "segultra_demo.afr",
        "datasci_demo.afr",
        "dbultra_demo.afr",
        "snake_test.afr",
        "game3d_demo.afr",
        "test_game2dkit.afr",
    };

    const std::vector<std::string> stdlibSamples = {
        "examples/giskit_demo.afr",
        "examples/segultra_demo.afr",
        "examples/dataultra_demo.afr",
        "examples/rasterultra_demo.afr",
        "examples/gisultra_demo.afr",
        "examples/iaultra_demo.afr",
        "examples/vizultra_demo.afr",
        "examples/test_gameultra.afr",
    };

    CompileOptions opts;
    opts.runtimeDir = (root / "runtime").string();
    opts.useCache = false;
    opts.coverageMode = coverage;

    std::cout << "[examples]\n";
    for (const auto& ex : examples) {
        const std::string path = (root / "examples" / ex).string();
        std::cout << "  " << ex << " ... ";
        std::cout.flush();
        try {
            auto result = Pipeline::compileFile(path, opts);
            if (result.success) {
                std::cout << "OK\n";
                ++passed;
            } else {
                std::cout << "FAIL\n";
                ++failures;
            }
        } catch (const CompileError&) {
            std::cout << "FAIL\n";
            ++failures;
        }
    }

    std::cout << "\n[stdlib samples]\n";
    for (const auto& rel : stdlibSamples) {
        const std::string path = (root / rel).string();
        const std::string label = fs::path(rel).filename().string();
        std::cout << "  " << label << " ... ";
        std::cout.flush();
        try {
            auto result = Pipeline::compileFile(path, opts);
            if (result.success) {
                std::cout << "OK\n";
                ++passed;
            } else {
                std::cout << "FAIL\n";
                ++failures;
            }
        } catch (const CompileError&) {
            std::cout << "FAIL\n";
            ++failures;
        }
    }

    const int totalTests = static_cast<int>(examples.size() + stdlibSamples.size());
    std::cout << "\n";
    if (coverage) {
        const int pct = totalTests > 0 ? (passed * 100) / totalTests : 0;
        std::cout << "Couverture exemples: " << passed << "/" << totalTests
                  << " (" << pct << "%)\n";
    }
    if (failures == 0) {
        std::cout << "Tous les tests passent.\n";
    } else {
        std::cout << failures << " test(s) en échec.\n";
    }
    return failures == 0 ? 0 : 1;
}

static std::vector<fs::path> discoverProjectTests(const fs::path& projectDir) {
    std::vector<fs::path> files;
    const fs::path testsDir = projectDir / "tests";
    if (!fs::exists(testsDir) || !fs::is_directory(testsDir)) return files;
    for (const auto& entry : fs::recursive_directory_iterator(
             testsDir, fs::directory_options::skip_permission_denied)) {
        if (!entry.is_regular_file()) continue;
        if (entry.path().extension() == ".afr") {
            files.push_back(entry.path());
        }
    }
    std::sort(files.begin(), files.end());
    return files;
}

static int runProjectTests(const fs::path& projectDir, bool coverage) {
    const auto files = discoverProjectTests(projectDir);
    if (files.empty()) {
        std::cout << "Aucun fichier tests/**/*.afr trouvé dans " << projectDir.string() << "\n";
        std::cout << "Astuce: afrilang test --examples pour la suite d'exemples du compilateur.\n";
        return 1;
    }

    std::cout << "=== Tests projet (" << files.size() << " fichier(s)) ===\n\n";
    CompileOptions opts;
    opts.runtimeDir = (fs::path(detectAfrilangRoot()) / "runtime").string();
    opts.useCache = false;
    opts.coverageMode = coverage;
    opts.runAfter = true;

    int failures = 0;
    int passed = 0;
    for (const auto& path : files) {
        const std::string rel = fs::relative(path, projectDir).string();
        std::cout << "  " << rel << " ... ";
        std::cout.flush();
        try {
            auto result = Pipeline::compileFile(path.string(), opts);
            if (result.success) {
                std::cout << "OK\n";
                ++passed;
            } else {
                std::cout << "FAIL\n";
                ++failures;
            }
        } catch (const CompileError&) {
            std::cout << "FAIL\n";
            ++failures;
        } catch (const std::exception& e) {
            std::cout << "FAIL (" << e.what() << ")\n";
            ++failures;
        }
    }

    std::cout << "\n" << passed << " réussi(s), " << failures << " échec(s).\n";
    return failures == 0 ? 0 : 1;
}

static int runSpecsSuite(const fs::path& root, bool coverage) {
    std::vector<fs::path> files;
    for (const char* sub : {"tests/specs", "tests/stdlib"}) {
        const fs::path dir = root / sub;
        if (!fs::exists(dir) || !fs::is_directory(dir)) continue;
        for (const auto& entry : fs::recursive_directory_iterator(
                 dir, fs::directory_options::skip_permission_denied)) {
            if (!entry.is_regular_file()) continue;
            if (entry.path().extension() == ".afr") files.push_back(entry.path());
        }
    }
    std::sort(files.begin(), files.end());
    if (files.empty()) {
        std::cout << "Aucun fichier tests/specs ou tests/stdlib trouvé.\n";
        return 1;
    }

    std::cout << "=== Specs AFRILANG (" << files.size() << " fichier(s)) ===\n\n";
    CompileOptions opts;
    opts.runtimeDir = (root / "runtime").string();
    opts.useCache = false;
    opts.coverageMode = coverage;
    opts.runAfter = true;

    int failures = 0;
    int passed = 0;
    for (const auto& path : files) {
        const std::string rel = fs::relative(path, root).string();
        std::cout << "  " << rel << " ... ";
        std::cout.flush();
        try {
            auto result = Pipeline::compileFile(path.string(), opts);
            if (result.success) {
                std::cout << "OK\n";
                ++passed;
            } else {
                std::cout << "FAIL\n";
                ++failures;
            }
        } catch (const CompileError&) {
            std::cout << "FAIL\n";
            ++failures;
        } catch (const std::exception& e) {
            std::cout << "FAIL (" << e.what() << ")\n";
            ++failures;
        }
    }
    std::cout << "\n" << passed << " réussi(s), " << failures << " échec(s).\n";
    return failures == 0 ? 0 : 1;
}

int Pipeline::runTests(const std::string& rootOrProject, bool coverage, bool examplesMode,
                       bool specsMode) {
    const fs::path root(rootOrProject);
    if (specsMode) {
        return runSpecsSuite(root, coverage);
    }
    if (examplesMode) {
        return runExampleSuite(root, coverage);
    }

    if (fs::exists(root / "tests") && fs::is_directory(root / "tests") &&
        !discoverProjectTests(root).empty() &&
        !(fs::exists(root / "examples" / "hello.afr") && fs::exists(root / "src" / "utils"))) {
        return runProjectTests(root, coverage);
    }
    if (fs::exists(root / "examples" / "hello.afr")) {
        return runExampleSuite(root, coverage);
    }
    return runProjectTests(fs::current_path(), coverage);
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
    target = normalizeCrossTarget(target);
    if (!validateCrossTarget(target)) return 1;

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
    opts.crossTarget = normalizeCrossTarget(target);

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
        std::cerr << "Usage: afrilang run <fichier.afr> [--target <cible>] [--watch] [--profile]\n";
        return 1;
    }

    CompileOptions opts;
    opts.runAfter = true;
    opts.runtimeDir = (fs::path(detectAfrilangRoot()) / "runtime").string();
    std::string file = argv[2];
    for (int i = 3; i < argc; ++i) {
        const std::string arg = argv[i];
        if (arg == "--target" && i + 1 < argc) {
            opts.crossTarget = argv[++i];
        } else if (arg == "--watch") {
            opts.watchMode = true;
        } else if (arg == "--profile") {
            opts.profileMode = true;
        } else if (arg == "--error-limit" && i + 1 < argc) {
            opts.errorLimit = static_cast<std::size_t>(std::stoul(argv[++i]));
        }
    }
    opts.crossTarget = normalizeCrossTarget(opts.crossTarget);
    if (!validateCrossTarget(opts.crossTarget)) return 1;

    const fs::path absPath = fs::absolute(file);
    if (!fs::exists(absPath)) {
        printFileNotFoundHint(file);
        return 1;
    }

    try {
        if (!opts.watchMode) {
            auto result = Pipeline::compileFile(file, opts);
            return result.success ? 0 : 1;
        }

        std::cout << "Mode watch: Ctrl+C pour quitter.\n";
        auto lastWrite = fs::file_time_type::min();
        while (true) {
            const auto mtime = fs::last_write_time(absPath);
            if (mtime != lastWrite) {
                lastWrite = mtime;
                std::cout << "\n--- Recompilation ---\n";
                opts.useCache = false;
                auto result = Pipeline::compileFile(file, opts);
                if (!result.success) return 1;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
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

static int cmdInit(const std::string& name, bool asLib) {
    const std::string projectName = name.empty() ? "mon_projet" : name;
    if (asLib) {
        return PkgRegistry::cmdInit(projectName);
    }

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
        test << "test \"smoke\"\n";
        test << "    create x = 1 + 1\n";
        test << "    assert x is equal to 2\n";
        test << "end\n";
    }

    {
        std::ofstream readme(dir / "README.md");
        readme << "# " << projectName << "\n\n";
        readme << "Projet AFRILANG.\n\n";
        readme << "```bash\n";
        readme << "afrilang build\n";
        readme << "afrilang run src/main.afr\n";
        readme << "afrilang test\n";
        readme << "```\n";
    }

    {
        std::ofstream gi(dir / ".gitignore");
        gi << "build/\nvendor/\n*.o\n.afrilang/\n";
    }

    std::cout << "Projet '" << projectName << "' créé.\n";
    std::cout << "  cd " << projectName << "\n";
    std::cout << "  afrilang build\n";
    std::cout << "  afrilang run src/main.afr\n";
    std::cout << "  afrilang test\n";
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
    try {
        const fs::path srcPath = fs::absolute(sourcePath);
        Compiler compiler(srcPath.string(), detectAfrilangRoot());
        std::unique_ptr<ProgramNode> program = compiler.compile();
        SemanticAnalyzer analyzer(*program, &compiler.sources(), srcPath.string());
        const SemanticResult semantic = analyzer.analyze();
        int warnings = 0;
        for (const auto& w : semantic.warnings) {
            std::cout << "warning";
            if (w.line > 0) {
                std::cout << " [" << w.line << ":" << w.column << "]";
            }
            std::cout << ": " << w.message << "\n";
            ++warnings;
        }
        if (warnings == 0) {
            std::cout << "lint: OK (no errors, no warnings)\n";
        } else {
            std::cout << "lint: " << warnings << " warning(s), no errors\n";
        }
        return 0;
    } catch (const CompileError& e) {
        std::cerr << e.format();
        return 1;
    }
}

static int cmdCompileJs(const std::string& sourcePath) {
    try {
        std::string source;
        if (sourcePath == "-") {
            std::ostringstream buf;
            buf << std::cin.rdbuf();
            source = buf.str();
        } else {
            std::ifstream in(sourcePath);
            if (!in) {
                std::cerr << "Impossible d'ouvrir " << sourcePath << "\n";
                return 1;
            }
            std::ostringstream buf;
            buf << in.rdbuf();
            source = buf.str();
        }
        validateSourceContent(source, sourcePath == "-" ? "stdin" : sourcePath);
        const std::string virtualPath = sourcePath == "-" ? "stdin.afr" : sourcePath;
        const std::string js = compileSourceToJavaScript(source, virtualPath);
        std::cout << js;
        return 0;
    } catch (const CompileError& e) {
        std::cerr << e.format();
        return 1;
    } catch (const std::exception& e) {
        return reportCliException(e, sourcePath);
    }
}

static int cmdBuildWasmWeb(const std::string& sourcePath, const std::string& outDir) {
    try {
        std::ifstream in(sourcePath);
        if (!in) {
            std::cerr << "Impossible d'ouvrir " << sourcePath << "\n";
            return 1;
        }
        std::ostringstream buf;
        buf << in.rdbuf();
        const std::string source = buf.str();
        validateSourceContent(source, sourcePath);

        fs::create_directories(outDir);
        const fs::path cppPath = fs::path(outDir) / "module.cpp";
        const fs::path jsPath = fs::path(outDir) / "module.js";

        SourceManager sources;
        sources.addFile(sourcePath, source);
        auto program = parseSourceProgram(source, sourcePath, &sources);
        SemanticAnalyzer analyzer(*program, &sources, sourcePath);
        const SemanticResult semantic = analyzer.analyze();

        CodeGenerator codegen(*program, semantic);
        codegen.setRuntimeDir((fs::path(detectAfrilangRoot()) / "runtime").string());
        codegen.setSourceFile(sourcePath);
        codegen.setCrossTarget("wasm32");
        codegen.setWasmEnvironment("web");

        if (!codegen.compileToExecutable(cppPath.string(), jsPath.string())) {
            std::cerr << "Erreur compilation WASM (installez Emscripten: em++)\n";
            return 1;
        }

        fs::path wasmPath = jsPath;
        wasmPath.replace_extension(".wasm");
        if (!fs::exists(wasmPath)) {
            std::cerr << "Fichier .wasm introuvable après compilation\n";
            return 1;
        }
        return 0;
    } catch (const CompileError& e) {
        std::cerr << e.format();
        return 1;
    } catch (const std::exception& e) {
        return reportCliException(e, sourcePath);
    }
}

static int writeDocForFile(const fs::path& srcPath, std::ostream& out) {
    Compiler compiler(srcPath.string(), detectAfrilangRoot());
    std::unique_ptr<ProgramNode> program = compiler.compile();
    out << "# " << srcPath.filename().string() << "\n\n";
    for (const auto& func : program->functions) {
        out << "## function " << func->name << "\n\n";
        if (!func->parameters.empty()) {
            out << "**Parameters:** ";
            for (std::size_t i = 0; i < func->parameters.size(); ++i) {
                if (i > 0) out << ", ";
                out << func->parameters[i].name << " `" << func->parameters[i].typeName << "`";
            }
            out << "\n\n";
        }
        if (!func->returnTypeName.empty()) {
            out << "**Returns:** `" << func->returnTypeName << "`\n\n";
        }
    }
    for (const auto& cls : program->classes) {
        out << "## class " << cls->name << "\n\n";
        for (const auto& method : cls->methods) {
            if (method->isOperator) continue;
            out << "- `" << method->name << "`";
            if (!method->returnTypeName.empty()) {
                out << " → `" << method->returnTypeName << "`";
            }
            out << "\n";
        }
        out << "\n";
    }
    for (const auto& test : program->tests) {
        out << "## test \"" << test->name << "\"\n\n";
    }
    return 0;
}

static int cmdDoc(const std::string& sourcePath) {
    try {
        const fs::path srcPath = fs::absolute(sourcePath);
        if (fs::is_directory(srcPath)) {
            const fs::path outDir = fs::current_path() / "docs" / "api";
            fs::create_directories(outDir);
            int count = 0;
            for (const auto& entry : fs::recursive_directory_iterator(
                     srcPath, fs::directory_options::skip_permission_denied)) {
                if (!entry.is_regular_file()) continue;
                if (entry.path().extension() != ".afr") continue;
                const fs::path rel = fs::relative(entry.path(), srcPath);
                fs::path outFile = outDir / rel;
                outFile.replace_extension(".md");
                fs::create_directories(outFile.parent_path());
                std::ofstream out(outFile);
                writeDocForFile(entry.path(), out);
                std::cout << "Wrote " << outFile.string() << "\n";
                ++count;
            }
            if (count == 0) {
                std::cerr << "Aucun fichier .afr dans " << srcPath << "\n";
                return 1;
            }
            std::cout << count << " fichier(s) documenté(s) → " << outDir.string() << "\n";
            return 0;
        }
        return writeDocForFile(srcPath, std::cout);
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

    if (cmd == "version" || cmd == "--version" || cmd == "-V") {
        std::cout << "afrilang " << kVersion << "\n";
        std::cout << "root: " << detectAfrilangRoot() << "\n";
        return 0;
    }
    if (cmd == "build") {
        return cmdBuild(argc, argv);
    }
    if (cmd == "run") {
        return cmdRun(argc, argv);
    }
    if (cmd == "check") {
        if (argc < 3) {
            std::cerr << "Usage: afrilang check <fichier.afr> [--error-limit N]\n";
            return 1;
        }
        std::string file;
        std::size_t errorLimit = DiagnosticEngine::kDefaultErrorLimit;
        for (int i = 2; i < argc; ++i) {
            const std::string arg = argv[i];
            if (arg == "--error-limit" && i + 1 < argc) {
                errorLimit = static_cast<std::size_t>(std::stoul(argv[++i]));
            } else if (!arg.empty() && arg[0] != '-') {
                file = arg;
            }
        }
        if (file.empty()) {
            std::cerr << "Usage: afrilang check <fichier.afr> [--error-limit N]\n";
            return 1;
        }
        return Pipeline::checkFile(file, errorLimit) ? 0 : 1;
    }
    if (cmd == "test") {
        bool coverage = false;
        bool examplesMode = false;
        bool specsMode = false;
        std::string rootArg;
        for (int i = 2; i < argc; ++i) {
            const std::string arg = argv[i];
            if (arg == "--coverage") coverage = true;
            else if (arg == "--examples") examplesMode = true;
            else if (arg == "--specs") specsMode = true;
            else if (!arg.empty() && arg[0] != '-' && rootArg.empty()) rootArg = arg;
        }
        if (specsMode) {
            if (rootArg.empty()) rootArg = detectAfrilangRoot();
            return Pipeline::runTests(rootArg, coverage, false, true);
        }
        if (rootArg.empty()) {
            rootArg = examplesMode ? detectAfrilangRoot() : fs::current_path().string();
            if (!examplesMode && fs::exists(fs::path(rootArg) / "examples" / "hello.afr") &&
                fs::exists(fs::path(rootArg) / "CMakeLists.txt")) {
                examplesMode = true;
            }
        } else if (fs::exists(fs::path(rootArg) / "examples" / "hello.afr") &&
                   fs::exists(fs::path(rootArg) / "CMakeLists.txt") && !examplesMode) {
            examplesMode = true;
        }
        return Pipeline::runTests(rootArg.empty() ? detectAfrilangRoot() : rootArg, coverage,
                                  examplesMode, false);
    }
    if (cmd == "lsp") {
        return afrilang::runLspServer();
    }
    if (cmd == "compile-js") {
        if (argc < 3) {
            std::cerr << "Usage: afrilang compile-js <fichier.afr|- >\n";
            return 1;
        }
        return cmdCompileJs(argv[2]);
    }
    if (cmd == "build-wasm-web") {
        if (argc < 3) {
            std::cerr << "Usage: afrilang build-wasm-web <fichier.afr> -o <dir>\n";
            return 1;
        }
        std::string outDir;
        for (int i = 3; i < argc; ++i) {
            if (std::string(argv[i]) == "-o" && i + 1 < argc) {
                outDir = argv[++i];
            }
        }
        if (outDir.empty()) {
            std::cerr << "Usage: afrilang build-wasm-web <fichier.afr> -o <dir>\n";
            return 1;
        }
        return cmdBuildWasmWeb(argv[2], outDir);
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
            std::cerr << "Usage: afrilang pkg <list|search|add|install|update|init|test|sync|reindex|publish|sign|verify> [args]\n";
            return 1;
        }
        const std::string sub = argv[2];
        const std::string root = detectAfrilangRoot();
        const std::string dir = fs::current_path().string();
        if (sub == "list") {
            bool blessedOnly = false;
            for (int i = 3; i < argc; ++i) {
                if (std::string(argv[i]) == "--blessed") blessedOnly = true;
            }
            return PkgRegistry::cmdList(root, blessedOnly);
        }
        if (sub == "search") {
            const std::string query = argc >= 4 ? argv[3] : "";
            return PkgRegistry::cmdSearch(root, query);
        }
        if (sub == "init") {
            const std::string name = argc >= 4 ? argv[3] : "mylib";
            return PkgRegistry::cmdInit(name);
        }
        if (sub == "test") {
            const std::string pkgDir = argc >= 4 ? argv[3] : dir;
            return PkgRegistry::cmdTest(pkgDir, root);
        }
        if (sub == "add") {
            if (argc < 4) {
                std::cerr << "Usage: afrilang pkg add <name> [--git URL|--path DIR] [--tag T] [--branch B]\n";
                return 1;
            }
            const std::string name = argv[3];
            std::string gitUrl;
            std::string pathDep;
            std::string tag;
            std::string branch;
            for (int i = 4; i < argc; ++i) {
                const std::string arg = argv[i];
                if (arg == "--git" && i + 1 < argc) gitUrl = argv[++i];
                else if (arg == "--path" && i + 1 < argc) pathDep = argv[++i];
                else if (arg == "--tag" && i + 1 < argc) tag = argv[++i];
                else if (arg == "--branch" && i + 1 < argc) branch = argv[++i];
            }
            if (!gitUrl.empty()) {
                return PkgRegistry::cmdAddGit(dir, name, gitUrl, tag, branch, root);
            }
            if (!pathDep.empty()) {
                return PkgRegistry::cmdAddPath(dir, name, pathDep, root);
            }
            return PkgRegistry::cmdAdd(dir, name, root);
        }
        if (sub == "install") return PkgRegistry::cmdInstall(dir, root);
        if (sub == "update") return PkgRegistry::cmdUpdate(dir, root);
        if (sub == "sync") return PkgRegistry::syncRemoteRegistry(root);
        if (sub == "reindex") return PkgRegistry::rebuildIndex(root);
        if (sub == "sign") {
            if (argc < 5) {
                std::cerr << "Usage: afrilang pkg sign <name> <privateKeyHex>\n";
                std::cerr << "  (générer une clé: crypto ed25519GenPrivate)\n";
                return 1;
            }
            return PkgRegistry::cmdSign(argv[3], argv[4], root);
        }
        if (sub == "verify") {
            if (argc < 4) {
                std::cerr << "Usage: afrilang pkg verify <name>\n";
                return 1;
            }
            return PkgRegistry::cmdVerify(argv[3], root);
        }
        if (sub == "publish") {
            std::string pkgDir = dir;
            bool remote = false;
            for (int i = 3; i < argc; ++i) {
                const std::string arg = argv[i];
                if (arg == "--remote") remote = true;
                else if (!arg.empty() && arg[0] != '-') pkgDir = arg;
            }
            return PkgRegistry::cmdPublish(pkgDir, root, remote);
        }
        std::cerr << "Sous-commande pkg inconnue: " << sub << "\n";
        return 1;
    }
    if (cmd == "benchmark") {
        const fs::path script = fs::path(detectAfrilangRoot()) / "scripts" / "benchmark.sh";
        if (!fs::exists(script)) {
            std::cerr << "Script introuvable: " << script << "\n";
            return 1;
        }
        const std::string cmdline = "bash \"" + script.string() + "\"";
        const int code = std::system(cmdline.c_str());
        return code != 0 ? (code > 0 ? code : 1) : 0;
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
        bool asLib = false;
        std::string name;
        for (int i = 2; i < argc; ++i) {
            const std::string arg = argv[i];
            if (arg == "--lib") asLib = true;
            else if (!arg.empty() && arg[0] != '-' && name.empty()) name = arg;
        }
        return cmdInit(name, asLib);
    }
    if (cmd == "lint") {
        if (argc < 3) { std::cerr << "Usage: afrilang lint <fichier.afr>\n"; return 1; }
        return cmdLint(argv[2]);
    }
    if (cmd == "doc") {
        if (argc < 3) { std::cerr << "Usage: afrilang doc <fichier.afr|dossier>\n"; return 1; }
        return cmdDoc(argv[2]);
    }
    if (cmd == "debug") {
        if (argc < 3) {
            std::cerr << "Usage: afrilang debug <fichier.afr> [args...]\n";
            return 1;
        }
        try {
            CompileOptions opts;
            opts.debugSymbols = true;
            opts.runtimeDir = (fs::path(detectAfrilangRoot()) / "runtime").string();
            auto result = Pipeline::compileFile(argv[2], opts);
            if (!result.success) {
                for (std::size_t i = 0; i < result.diagnostics.size(); ++i) {
                    // compileFile already printed errors; ensure exit code
                }
                return 1;
            }
            std::vector<std::string> progArgs;
            for (int i = 3; i < argc; ++i) {
                progArgs.emplace_back(argv[i]);
            }
            return runDebugger("./" + result.executable, progArgs);
        } catch (const CompileError& e) {
            std::cerr << e.format();
            return 1;
        } catch (const std::exception& e) {
            reportCliException(e, argv[2]);
            return 1;
        }
    }
    if (cmd == "env") {
        if (argc < 3) {
            std::cerr << "Usage: afrilang env <create|activate|path>\n";
            return 1;
        }
        const std::string sub = argv[2];
        const ProjectEnv env(fs::current_path().string());
        if (sub == "create") return env.create();
        if (sub == "activate") return env.activateShellHints();
        if (sub == "path") {
            std::cout << env.root() << "\n";
            return 0;
        }
        std::cerr << "Sous-commande env inconnue: " << sub << "\n";
        return 1;
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
