#pragma once

#include "afrilang/stdlib_catalog.hpp"

#include <string>

namespace afrilang {

const StdlibModuleSpec* mediumCatalogFindModule(const std::string& name);
bool mediumCatalogIsMediumModule(const std::string& name);

} // namespace afrilang
