#include "afrilang/js_codegen.hpp"

#include "afrilang/compiler.hpp"
#include "afrilang/error.hpp"
#include "afrilang/semantic.hpp"

#include <cstring>
#include <cstdlib>
#include <string>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

namespace afrilang {

#ifdef __EMSCRIPTEN__
extern "C" {

EMSCRIPTEN_KEEPALIVE
char* afrilang_compile_js(const char* source) {
    try {
        const std::string js = afrilang::compileSourceToJavaScript(
            source ? source : "", "/playground/client.afr");
        char* out = static_cast<char*>(std::malloc(js.size() + 1));
        if (!out) return nullptr;
        std::memcpy(out, js.c_str(), js.size() + 1);
        return out;
    } catch (const afrilang::CompileError& e) {
        const std::string msg = std::string("ERROR:") + e.format();
        char* out = static_cast<char*>(std::malloc(msg.size() + 1));
        if (!out) return nullptr;
        std::memcpy(out, msg.c_str(), msg.size() + 1);
        return out;
    } catch (...) {
        char* out = static_cast<char*>(std::malloc(8));
        if (!out) return nullptr;
        std::memcpy(out, "ERROR:", 7);
        return out;
    }
}

EMSCRIPTEN_KEEPALIVE
void afrilang_free(char* ptr) {
    std::free(ptr);
}

} // extern "C"
#endif

} // namespace afrilang
