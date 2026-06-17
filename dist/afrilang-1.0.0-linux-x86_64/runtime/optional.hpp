#pragma once

#include <optional>
#include <string>

namespace afrilang::runtime {

using OptNumber = std::optional<double>;
using OptText = std::optional<std::string>;
using OptBool = std::optional<bool>;

inline bool isDefined(const OptText& v) { return v.has_value(); }
inline bool isDefined(const OptNumber& v) { return v.has_value(); }
inline bool isDefined(const OptBool& v) { return v.has_value(); }

} // namespace afrilang::runtime
