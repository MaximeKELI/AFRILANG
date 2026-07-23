#pragma once

#include "afrilang/stdlib_catalog.hpp"

#include <string>

namespace afrilang {

// Version du schéma du catalogue complexe externalisé (JSON chargé
// paresseusement). Doit correspondre à `CATALOG_JSON_VERSION` dans
// scripts/gen_catalog_lib.py. Garde-fou anti-skew binaire/catalogue.
constexpr int kComplexCatalogVersion = 1;

// Chargé depuis share/afrilang/catalog/complex.json au premier appel.
const StdlibModuleSpec* complexCatalogFindModule(const std::string& name);
bool complexCatalogIsComplexModule(const std::string& name);

} // namespace afrilang
