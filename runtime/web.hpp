#pragma once

#include "net.hpp"

#include <chrono>
#include <cctype>
#include <map>
#include <sstream>
#include <string>
#include <thread>
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

inline std::map<int, Router>& routerRegistry() {
    static std::map<int, Router> routers;
    return routers;
}

inline int& nextRouterId() {
    static int id = 1;
    return id;
}

inline int createRouter() {
    const int id = nextRouterId()++;
    routerRegistry()[id] = newRouter();
    return id;
}

inline void addRouteId(int routerId, const std::string& method, const std::string& path,
                       const std::string& body) {
    addRoute(routerRegistry()[routerId], method, path, body);
}

inline std::string dispatchId(int routerId, const std::string& method,
                              const std::string& path) {
    const auto it = routerRegistry().find(routerId);
    if (it == routerRegistry().end()) return {};
    return dispatch(it->second, method, path);
}

/** One-shot HTTP server: parse request, route via router id, respond 200/404. */
inline double httpServeOnceRouted(double port, double routerId) {
    const int id = static_cast<int>(routerId);
    return afrilang::runtime::net::httpServeOnceHandler(
        port, [id](const std::string& method, const std::string& path, const std::string&) {
            return dispatchId(id, method, path);
        });
}

/**
 * In-process round-trip for tests: background GET client + one routed serve.
 * Returns response body text (empty on failure / 404).
 */
inline std::string httpRoundTripRouted(double port, double routerId, const std::string& method,
                                       const std::string& path) {
    const int id = static_cast<int>(routerId);
    const int p = static_cast<int>(port);
    std::string rawResp;
    std::thread client([&]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(40));
        const double fd = afrilang::runtime::net::tcpConnect("127.0.0.1", port);
        if (fd < 0) return;
        std::ostringstream req;
        req << afrilang::runtime::web::normalizeMethod(method) << " " << path
            << " HTTP/1.1\r\nHost: 127.0.0.1:" << p << "\r\nConnection: close\r\n\r\n";
        afrilang::runtime::net::tcpWrite(fd, req.str());
        rawResp = afrilang::runtime::net::tcpRead(fd, 65536);
        afrilang::runtime::net::tcpClose(fd);
    });
    (void)httpServeOnceRouted(port, id);
    client.join();
    return afrilang::runtime::net::httpRequestBody(rawResp);
}

} // namespace afrilang::runtime::web
