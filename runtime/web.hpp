#pragma once

#include "net.hpp"

#include <atomic>
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
 * Multi-request routed HTTP server. Serves up to maxRequests connections
 * (0 = forever). Each request is parsed, dispatched, and answered with
 * Connection: close. Returns 0 on success, -1 on listen error.
 */
inline double httpServeRouted(double port, double routerId, double maxRequests) {
    const int id = static_cast<int>(routerId);
    const int limit = static_cast<int>(maxRequests);
    const double lf = afrilang::runtime::net::tcpListen(port);
    if (lf < 0) return -1;
    int served = 0;
    while (limit <= 0 || served < limit) {
        const double c = afrilang::runtime::net::tcpAccept(lf);
        if (c < 0) continue;
        const std::string raw = afrilang::runtime::net::tcpRead(c, 65536);
        const std::string method = afrilang::runtime::net::httpRequestMethod(raw);
        const std::string path = afrilang::runtime::net::httpRequestPath(raw);
        const std::string outBody = dispatchId(id, method, path);
        if (outBody.empty()) {
            afrilang::runtime::net::tcpWrite(c, afrilang::runtime::net::httpResponse(404, "not found"));
        } else {
            afrilang::runtime::net::tcpWrite(c, afrilang::runtime::net::httpOkResponse(outBody));
        }
        afrilang::runtime::net::tcpClose(c);
        ++served;
    }
    afrilang::runtime::net::tcpClose(lf);
    return 0;
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

/**
 * Fire N sequential GET clients against a server that stops after N requests.
 * Returns the number of non-empty response bodies received (for tests).
 */
inline double httpRoundTripRoutedN(double port, double routerId, const std::string& method,
                                   const std::string& path, double times) {
    const int id = static_cast<int>(routerId);
    const int n = static_cast<int>(times);
    if (n <= 0) return 0;
    const int p = static_cast<int>(port);
    std::atomic<int> ok{0};
    std::thread server([&]() { (void)httpServeRouted(port, id, n); });
    std::this_thread::sleep_for(std::chrono::milliseconds(40));
    for (int i = 0; i < n; ++i) {
        const double fd = afrilang::runtime::net::tcpConnect("127.0.0.1", port);
        if (fd < 0) continue;
        std::ostringstream req;
        req << afrilang::runtime::web::normalizeMethod(method) << " " << path
            << " HTTP/1.1\r\nHost: 127.0.0.1:" << p << "\r\nConnection: close\r\n\r\n";
        afrilang::runtime::net::tcpWrite(fd, req.str());
        const std::string raw = afrilang::runtime::net::tcpRead(fd, 65536);
        afrilang::runtime::net::tcpClose(fd);
        if (!afrilang::runtime::net::httpRequestBody(raw).empty()) ok.fetch_add(1);
    }
    server.join();
    return static_cast<double>(ok.load());
}

} // namespace afrilang::runtime::web
