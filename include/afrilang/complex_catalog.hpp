#pragma once

#include "afrilang/stdlib_catalog.hpp"

#include <string>

namespace afrilang {

const StdlibModuleSpec* complexCatalogFindModule(const std::string& name);
bool complexCatalogIsComplexModule(const std::string& name);

} // namespace afrilang
