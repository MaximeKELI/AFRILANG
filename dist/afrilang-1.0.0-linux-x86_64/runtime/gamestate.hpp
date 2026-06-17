#pragma once

#include <string>

namespace afrilang::runtime::gamestate {

struct StateContext {
    std::string current = "menu";
    std::string previous;
    double timeInStateMs = 0;
    bool changed = false;
};

inline StateContext& context() {
    static StateContext ctx;
    return ctx;
}

inline void setState(const std::string& name) {
    StateContext& ctx = context();
    if (ctx.current == name) return;
    ctx.previous = ctx.current;
    ctx.current = name;
    ctx.timeInStateMs = 0;
    ctx.changed = true;
}

inline std::string getState() {
    return context().current;
}

inline bool isState(const std::string& name) {
    return context().current == name;
}

inline double stateTimeMs() {
    return context().timeInStateMs;
}

inline bool wasStateChanged() {
    StateContext& ctx = context();
    const bool v = ctx.changed;
    ctx.changed = false;
    return v;
}

inline void tickState(double deltaMs) {
    context().timeInStateMs += deltaMs;
}

} // namespace afrilang::runtime::gamestate
