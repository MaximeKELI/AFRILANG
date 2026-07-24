#pragma once

// Quarantine for the ~19MB complex catalog runtime (std/c/*).
// The compiler only #includes this header when a complex catalog module is used.
// Including this file is itself the opt-in signal (older compilers did not pass
// -DAFRILANG_ENABLE_COMPLEX_LIBS=1; keep that flag for explicit disable).
#if defined(AFRILANG_ENABLE_COMPLEX_LIBS) && (AFRILANG_ENABLE_COMPLEX_LIBS + 0) == 0
#error "Complex catalog runtime disabled (AFRILANG_ENABLE_COMPLEX_LIBS=0). See docs/STDLIB_GEN.md."
#else
#include "optional/complex_libs.hpp"
#endif
