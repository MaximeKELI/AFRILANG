#pragma once

#include <string>
#include <vector>

namespace afrilang {

int runDebugger(const std::string& executablePath,
                const std::vector<std::string>& args = {});

} // namespace afrilang
