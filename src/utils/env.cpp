#include "afrilang/env.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

namespace afrilang {

ProjectEnv::ProjectEnv(const std::string& projectDir)
    : projectDir_(projectDir), envRoot_(defaultEnvRoot(projectDir)) {}

std::string ProjectEnv::defaultEnvRoot(const std::string& projectDir) {
    return (fs::path(projectDir) / ".afrilang" / "env").string();
}

std::string ProjectEnv::vendorDir() const {
    return (fs::path(envRoot_) / "vendor").string();
}

std::string ProjectEnv::packagesDir() const {
    return (fs::path(envRoot_) / "packages").string();
}

bool ProjectEnv::exists() const {
    return fs::exists(envRoot_);
}

int ProjectEnv::create() const {
    fs::create_directories(vendorDir());
    fs::create_directories(packagesDir());
    const fs::path cfg = fs::path(envRoot_) / "env.toml";
    if (!fs::exists(cfg)) {
        std::ofstream out(cfg);
        out << "# AFRILANG virtual environment\n";
        out << "version = \"1\"\n";
        out << "isolated = true\n";
    }
    std::cout << "Environnement AFRILANG créé: " << envRoot_ << "\n";
    std::cout << "Packages isolés dans: " << vendorDir() << "\n";
    return 0;
}

int ProjectEnv::activateShellHints() const {
    if (!exists()) {
        std::cerr << "Erreur: environnement introuvable. Lancez: afrilang env create\n";
        return 1;
    }
    std::cout << "export AFRILANG_ENV=" << envRoot_ << "\n";
    std::cout << "export AFRILANG_VENDOR=" << vendorDir() << "\n";
    std::cout << "# Évaluez avec: eval $(afrilang env activate)\n";
    return 0;
}

} // namespace afrilang
