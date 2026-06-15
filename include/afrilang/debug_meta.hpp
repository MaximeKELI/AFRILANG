#pragma once

#include "afrilang/semantic.hpp"

#include <string>

namespace afrilang {

void writeDebugMetadata(const std::string& path, const SemanticResult& semantic,
                        const std::string& sourceFile);

} // namespace afrilang
