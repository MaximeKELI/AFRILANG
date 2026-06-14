#pragma once

#include <string>

namespace afrilang {

class ProjectEnv {
public:
    explicit ProjectEnv(const std::string& projectDir);

    std::string root() const { return envRoot_; }
    std::string vendorDir() const;
    std::string packagesDir() const;
    bool exists() const;

    int create() const;
    int activateShellHints() const;

    static std::string defaultEnvRoot(const std::string& projectDir);

private:
    std::string projectDir_;
    std::string envRoot_;
};

} // namespace afrilang
