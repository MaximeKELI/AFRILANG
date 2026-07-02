#include "afrilang/torch_install.hpp"
#include "afrilang/sandbox.hpp"
#include "afrilang/security.hpp"

#include <cctype>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <sys/stat.h>
#include <unistd.h>

namespace fs = std::filesystem;

namespace afrilang {

namespace {

constexpr const char* kDefaultLibtorchVersion = "2.5.1";

bool envFlagEnabled(const char* name) {
    if (const char* v = std::getenv(name)) {
        return v[0] == '1' || v[0] == 'y' || v[0] == 'Y' ||
               v[0] == 't' || v[0] == 'T';
    }
    return false;
}

bool commandExists(const std::string& cmd) {
    if (cmd.find('/') != std::string::npos) {
        return fs::exists(cmd) && fs::is_regular_file(cmd);
    }
    const char* pathEnv = std::getenv("PATH");
    if (!pathEnv) return false;
    std::string path = pathEnv;
    std::size_t start = 0;
    while (start < path.size()) {
        const std::size_t end = path.find(':', start);
        const std::string dir = path.substr(start, end == std::string::npos ? std::string::npos : end - start);
        if (!dir.empty() && fs::exists(dir + "/" + cmd)) return true;
        if (end == std::string::npos) break;
        start = end + 1;
    }
    return false;
}

std::string afrilangDataRoot() {
    if (const char* home = std::getenv("HOME")) {
        return std::string(home) + "/.local/afrilang";
    }
    if (const char* env = std::getenv("AFRILANG_HOME")) {
        return std::string(env) + "/vendor";
    }
    return "/tmp/afrilang";
}

int runShellStep(const std::string& label, const std::vector<std::string>& args,
                 int timeoutSeconds, std::string& errorOut) {
    ProcessConfig config;
    config.timeoutSeconds = timeoutSeconds;
    config.maxMemoryMb = securityLimits(SecurityContext::TrustedCompile).maxMemoryMb;
    config.maxCpuSeconds = static_cast<std::size_t>(timeoutSeconds);
    config.applyResourceLimits = false;
    config.limitProcessCount = false;

    std::string output;
    const int code = runCommand(args, config, output);
    if (code != 0) {
        errorOut = label + " a echoue (code " + std::to_string(code) + ")";
        if (!output.empty()) errorOut += "\n" + output;
        return code;
    }
    return 0;
}

std::string trim(const std::string& s) {
    std::size_t start = 0;
    while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start]))) ++start;
    std::size_t end = s.size();
    while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1]))) --end;
    return s.substr(start, end - start);
}

bool parseCudaVersion(const std::string& text, int& major, int& minor) {
    const std::size_t pos = text.find("CUDA Version:");
    std::string ver = pos == std::string::npos ? text : text.substr(pos + 13);
    ver = trim(ver);
    const std::size_t dot = ver.find('.');
    if (dot == std::string::npos) return false;
    try {
        major = std::stoi(ver.substr(0, dot));
        minor = std::stoi(ver.substr(dot + 1));
        return true;
    } catch (...) {
        return false;
    }
}

void writeInstallMetadata(const TorchInstallInfo& info) {
    const fs::path meta = fs::path(info.installDir) / ".afrilang-torch.json";
    std::ofstream out(meta);
    if (!out) return;
    out << "{\n";
    out << "  \"version\": \"" << info.version << "\",\n";
    out << "  \"backend\": \"" << info.backendLabel << "\",\n";
    out << "  \"cuda_tag\": \"" << info.cudaTag << "\",\n";
    out << "  \"gpu_name\": \"" << info.gpu.name << "\",\n";
    out << "  \"cuda_version\": \"" << info.gpu.cudaVersion << "\"\n";
    out << "}\n";
}

TorchBackend backendForAutoInstall() {
    return envFlagEnabled("AFRILANG_TORCH_CUDA") ? TorchBackend::Gpu : TorchBackend::Cpu;
}

} // namespace

bool libtorchIsValid(const std::string& root) {
    if (root.empty()) return false;
    const fs::path base(root);
    const bool hasHeader =
        fs::exists(base / "include" / "torch" / "torch.h") ||
        fs::exists(base / "include" / "torch" / "csrc" / "api" / "include" / "torch" / "torch.h");
    const bool hasLib = fs::exists(base / "lib" / "libtorch.so") ||
                        fs::exists(base / "lib" / "libtorch_cpu.so");
    return hasHeader && hasLib;
}

std::string defaultLibtorchInstallDir() {
    return afrilangDataRoot() + "/libtorch";
}

std::string resolveLibtorchHome() {
    if (const char* env = std::getenv("AFRILANG_TORCH_HOME")) {
        if (libtorchIsValid(env)) return env;
    }
    if (const char* env = std::getenv("LIBTORCH")) {
        if (libtorchIsValid(env)) return env;
    }
    const std::string local = defaultLibtorchInstallDir();
    if (libtorchIsValid(local)) return local;
    return {};
}

bool programUsesTorchModule(const std::unordered_set<std::string>& usedModules) {
    return usedModules.count("torch") > 0 || usedModules.count("tensor") > 0;
}

GpuInfo detectGpuInfo() {
    GpuInfo info;
    if (!commandExists("nvidia-smi")) return info;

    std::string output;
    ProcessConfig config;
    config.timeoutSeconds = 10;
    config.applyResourceLimits = false;
    if (runCommand({"nvidia-smi", "--query-gpu=name,driver_version", "--format=csv,noheader"},
                   config, output) != 0) {
        return info;
    }

    const std::string line = trim(output.substr(0, output.find('\n')));
    const std::size_t comma = line.find(',');
    if (comma != std::string::npos) {
        info.name = trim(line.substr(0, comma));
        info.driverVersion = trim(line.substr(comma + 1));
        info.found = !info.name.empty();
    }

    output.clear();
    if (runCommand({"nvidia-smi"}, config, output) == 0) {
        if (parseCudaVersion(output, info.cudaMajor, info.cudaMinor)) {
            info.cudaVersion = std::to_string(info.cudaMajor) + "." + std::to_string(info.cudaMinor);
        }
    }

    if (info.cudaMajor == 0 && commandExists("nvcc")) {
        output.clear();
        if (runCommand({"nvcc", "--version"}, config, output) == 0) {
            const std::size_t release = output.find("release ");
            if (release != std::string::npos) {
                parseCudaVersion(output.substr(release + 8), info.cudaMajor, info.cudaMinor);
                info.cudaVersion = std::to_string(info.cudaMajor) + "." + std::to_string(info.cudaMinor);
            }
        }
    }

    return info;
}

std::string cudaTagForGpu(const GpuInfo& gpu) {
    if (gpu.cudaMajor > 12 || (gpu.cudaMajor == 12 && gpu.cudaMinor >= 4)) return "cu124";
    if (gpu.cudaMajor == 12 && gpu.cudaMinor >= 1) return "cu121";
    if (gpu.cudaMajor == 11 && gpu.cudaMinor >= 8) return "cu118";
    if (gpu.cudaMajor >= 12) return "cu124";
    return "cu118";
}

std::string buildLibtorchDownloadUrl(const std::string& version,
                                     TorchBackend backend,
                                     const std::string& cudaTag) {
    const std::string folder = backend == TorchBackend::Gpu ? cudaTag : "cpu";
    const std::string suffix = backend == TorchBackend::Gpu ? cudaTag : "cpu";
    return "https://download.pytorch.org/libtorch/" + folder +
           "/libtorch-cxx11-abi-shared-with-deps-" + version + "%2B" + suffix + ".zip";
}

bool installLibtorch(const TorchInstallRequest& request,
                     TorchInstallInfo& info,
                     std::string& errorOut) {
    info.version = request.version.empty() ? kDefaultLibtorchVersion : request.version;
    info.installDir = defaultLibtorchInstallDir();
    info.gpu = detectGpuInfo();

    TorchBackend backend = request.backend;
    if (backend == TorchBackend::Auto) {
        backend = backendForAutoInstall();
    }

    if (backend == TorchBackend::Gpu) {
        if (!info.gpu.found) {
            errorOut = "Aucun GPU NVIDIA detecte (nvidia-smi introuvable ou vide).";
            errorOut += "\nUtilisez: afrilang install torch cpu";
            return false;
        }
        if (info.gpu.cudaMajor == 0) {
            errorOut = "GPU detecte (" + info.gpu.name + ") mais version CUDA introuvable.";
            errorOut += "\nInstallez les drivers NVIDIA/CUDA ou essayez: afrilang install torch cpu";
            return false;
        }
        info.cudaTag = cudaTagForGpu(info.gpu);
        info.backendLabel = "gpu";
    } else {
        info.cudaTag = "cpu";
        info.backendLabel = "cpu";
        backend = TorchBackend::Cpu;
    }

    if (!request.force && libtorchIsValid(info.installDir)) {
        std::cout << "libtorch deja installe dans " << info.installDir << "\n";
        setenv("AFRILANG_TORCH_HOME", info.installDir.c_str(), 1);
        if (backend == TorchBackend::Gpu) {
            setenv("AFRILANG_TORCH_CUDA", "1", 1);
        }
        return true;
    }

    const std::string dataRoot = afrilangDataRoot();
    const std::string cacheDir = dataRoot + "/cache";
    const std::string zipPath = cacheDir + "/libtorch-" + info.backendLabel + "-" + info.version + ".zip";

    if (!commandExists("curl") && !commandExists("wget")) {
        errorOut = "curl ou wget est requis pour telecharger libtorch.";
        return false;
    }
    if (!commandExists("unzip")) {
        errorOut = "unzip est requis pour extraire libtorch.";
        return false;
    }

    try {
        fs::create_directories(cacheDir);
        if (request.force && fs::exists(info.installDir)) {
            std::string rmErr;
            if (runShellStep("Nettoyage libtorch", {"rm", "-rf", info.installDir}, 120, rmErr) != 0) {
                errorOut = "Impossible de supprimer l'ancienne installation: " + rmErr;
                return false;
            }
        }
    } catch (const std::exception& ex) {
        errorOut = std::string("Erreur preparation installation: ") + ex.what();
        return false;
    }

    const std::string url = buildLibtorchDownloadUrl(info.version, backend, info.cudaTag);

    std::cout << "Installation libtorch v" << info.version << " (" << info.backendLabel << ")\n";
    if (backend == TorchBackend::Gpu) {
        std::cout << "  GPU: " << info.gpu.name << "\n";
        std::cout << "  Driver: " << info.gpu.driverVersion << "\n";
        std::cout << "  CUDA detecte: " << info.gpu.cudaVersion
                  << " -> build " << info.cudaTag << "\n";
    }
    std::cout << "  URL: " << url << "\n";

    std::vector<std::string> downloadArgs;
    if (commandExists("curl")) {
        downloadArgs = {"curl", "-fL", "--retry", "3", "--retry-delay", "2",
                        "-o", zipPath, url};
    } else {
        downloadArgs = {"wget", "-O", zipPath, url};
    }

    std::cout << "Telechargement en cours...\n";
    if (runShellStep("Telechargement libtorch", downloadArgs, 1800, errorOut) != 0) {
        return false;
    }

    if (!fs::exists(zipPath) || fs::file_size(zipPath) < 1024 * 1024) {
        errorOut = "Archive libtorch invalide ou incomplete.";
        return false;
    }

    std::cout << "Extraction vers " << dataRoot << "...\n";
    if (runShellStep("Extraction libtorch",
                     {"unzip", "-q", "-o", zipPath, "-d", dataRoot}, 600, errorOut) != 0) {
        return false;
    }

    if (!libtorchIsValid(info.installDir)) {
        errorOut = "libtorch extrait mais installation invalide dans " + info.installDir;
        return false;
    }

    setenv("AFRILANG_TORCH_HOME", info.installDir.c_str(), 1);
    if (backend == TorchBackend::Gpu) {
        setenv("AFRILANG_TORCH_CUDA", "1", 1);
    } else {
        unsetenv("AFRILANG_TORCH_CUDA");
    }

    writeInstallMetadata(info);
    std::cout << "libtorch installe dans " << info.installDir << "\n";
    std::cout << "export AFRILANG_TORCH_HOME=\"" << info.installDir << "\"\n";
    if (backend == TorchBackend::Gpu) {
        std::cout << "export AFRILANG_TORCH_CUDA=1\n";
        std::cout << "export LD_LIBRARY_PATH=\"" << info.installDir << "/lib:$LD_LIBRARY_PATH\"\n";
    }
    return true;
}

bool ensureLibtorchInstalled(std::string& outHome, std::string& errorOut) {
    outHome = resolveLibtorchHome();
    if (!outHome.empty()) return true;

    TorchInstallRequest request;
    request.backend = TorchBackend::Auto;
    request.version = kDefaultLibtorchVersion;
    request.force = false;

    TorchInstallInfo info;
    std::cout << "libtorch introuvable — installation automatique...\n";
    if (!installLibtorch(request, info, errorOut)) return false;
    outHome = info.installDir;
    return true;
}

int cmdInstallTorch(int argc, char* argv[]) {
    TorchInstallRequest request;
    request.version = kDefaultLibtorchVersion;

    for (int i = 3; i < argc; ++i) {
        const std::string arg = argv[i];
        if (arg == "gpu") {
            request.backend = TorchBackend::Gpu;
        } else if (arg == "cpu") {
            request.backend = TorchBackend::Cpu;
        } else if (arg == "version" && i + 1 < argc) {
            request.version = argv[++i];
        } else if (arg == "--force") {
            request.force = true;
        } else {
            std::cerr << "Option inconnue: " << arg << "\n";
            std::cerr << "Usage: afrilang install torch [gpu|cpu] [version <X.Y.Z>] [--force]\n";
            return 1;
        }
    }

    if (request.backend == TorchBackend::Auto) {
        const GpuInfo gpu = detectGpuInfo();
        if (gpu.found) {
            std::cout << "GPU detecte: " << gpu.name;
            if (!gpu.cudaVersion.empty()) {
                std::cout << " (CUDA " << gpu.cudaVersion << " -> " << cudaTagForGpu(gpu) << ")";
            }
            std::cout << "\n";
            std::cout << "Astuce: afrilang install torch gpu   pour la version GPU\n";
            std::cout << "        afrilang install torch cpu   pour la version CPU\n\n";
        }
        request.backend = TorchBackend::Cpu;
    }

    TorchInstallInfo info;
    std::string errorOut;
    if (!installLibtorch(request, info, errorOut)) {
        std::cerr << "Erreur: " << errorOut << "\n";
        return 1;
    }
    return 0;
}

} // namespace afrilang
