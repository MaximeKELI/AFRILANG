#pragma once

#include <string>
#include <unordered_set>

namespace afrilang {

enum class TorchBackend {
    Auto,
    Cpu,
    Gpu
};

struct GpuInfo {
    bool found = false;
    std::string name;
    std::string driverVersion;
    std::string cudaVersion;
    int cudaMajor = 0;
    int cudaMinor = 0;
};

struct TorchInstallRequest {
    TorchBackend backend = TorchBackend::Auto;
    std::string version = "2.5.1";
    bool force = false;
};

struct TorchInstallInfo {
    std::string installDir;
    std::string backendLabel;
    std::string cudaTag;
    std::string version;
    GpuInfo gpu;
};

bool libtorchIsValid(const std::string& root);
std::string defaultLibtorchInstallDir();
std::string resolveLibtorchHome();
bool programUsesTorchModule(const std::unordered_set<std::string>& usedModules);

GpuInfo detectGpuInfo();
std::string cudaTagForGpu(const GpuInfo& gpu);
std::string buildLibtorchDownloadUrl(const std::string& version,
                                     TorchBackend backend,
                                     const std::string& cudaTag);

bool installLibtorch(const TorchInstallRequest& request,
                     TorchInstallInfo& info,
                     std::string& errorOut);
bool ensureLibtorchInstalled(std::string& outHome, std::string& errorOut);

int cmdInstallTorch(int argc, char* argv[]);

} // namespace afrilang
