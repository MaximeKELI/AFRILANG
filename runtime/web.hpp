#pragma once

#include <cctype>
#include <string>
#include <vector>

namespace afrilang::runtime::web {

struct Route {
    std::string method;
    std::string path;
    std::string body;
};

struct Router {
    std::vector<Route> routes;
};

inline std::string normalizeMethod(std::string method) {
    for (char& c : method) {
        c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
    }
    return method;
}

inline Router newRouter() { return Router{}; }

inline void addRoute(Router& router, const std::string& method, const std::string& path,
                     const std::string& body) {
    router.routes.push_back(Route{normalizeMethod(method), path, body});
}

inline std::string dispatch(const Router& router, const std::string& method,
                            const std::string& path) {
    const std::string m = normalizeMethod(method);
    for (const Route& route : router.routes) {
        if (route.method == m && route.path == path) return route.body;
    }
    return {};
}

} // namespace afrilang::runtime::web
