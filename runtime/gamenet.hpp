#pragma once

#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cmath>
#include <cstring>
#include <string>

namespace afrilang::runtime::gamenet {

struct NetState {
    int sock = -1;
    bool hosting = false;
    std::string remoteHost;
    int port = 0;
    double localX = 0;
    double localY = 0;
    double localZ = 0;
    double localRotY = 0;
    double remoteX = 0;
    double remoteY = 0;
    double remoteZ = 0;
    double remoteRotY = 0;
    bool hasRemote = false;
    double lastRemoteMs = 0;
};

inline NetState& state() {
    static NetState s;
    return s;
}

inline void closeSocket() {
    NetState& s = state();
    if (s.sock >= 0) {
        close(s.sock);
        s.sock = -1;
    }
    s.hosting = false;
    s.hasRemote = false;
}

inline bool setNonBlocking(int fd) {
    const int flags = fcntl(fd, F_GETFL, 0);
    if (flags < 0) return false;
    return fcntl(fd, F_SETFL, flags | O_NONBLOCK) == 0;
}

inline bool hostGame(double port) {
    closeSocket();
    NetState& s = state();
    s.sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (s.sock < 0) return false;

    int yes = 1;
    setsockopt(s.sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(static_cast<uint16_t>(static_cast<int>(port)));
    if (::bind(s.sock, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) != 0) {
        closeSocket();
        return false;
    }
    setNonBlocking(s.sock);
    s.hosting = true;
    s.port = static_cast<int>(port);
    s.hasRemote = false;
    return true;
}

inline bool joinGame(const std::string& host, double port) {
    closeSocket();
    NetState& s = state();
    s.sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (s.sock < 0) return false;
    setNonBlocking(s.sock);
    s.hosting = false;
    s.remoteHost = host;
    s.port = static_cast<int>(port);
    s.hasRemote = false;
    return true;
}

inline void sendPose(double x, double y, double z, double rotY) {
    NetState& s = state();
    if (s.sock < 0) return;
    s.localX = x;
    s.localY = y;
    s.localZ = z;
    s.localRotY = rotY;

    char buf[128];
    const int n = std::snprintf(buf, sizeof(buf), "POSE %.3f %.3f %.3f %.3f", x, y, z, rotY);
    if (n <= 0) return;

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(static_cast<uint16_t>(s.port));
    if (s.hosting) {
        addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    } else {
        if (s.remoteHost.empty()) return;
        if (inet_pton(AF_INET, s.remoteHost.c_str(), &addr.sin_addr) != 1) {
            addr.sin_addr.s_addr = inet_addr(s.remoteHost.c_str());
        }
    }
    sendto(s.sock, buf, static_cast<std::size_t>(n), 0,
           reinterpret_cast<sockaddr*>(&addr), sizeof(addr));
}

inline void pollNet(double nowMs) {
    NetState& s = state();
    if (s.sock < 0) return;

    char buf[256];
    sockaddr_in from{};
    socklen_t fromLen = sizeof(from);
    while (true) {
        const ssize_t n = recvfrom(s.sock, buf, sizeof(buf) - 1, 0,
                                   reinterpret_cast<sockaddr*>(&from), &fromLen);
        if (n <= 0) break;
        buf[n] = '\0';
        if (std::strncmp(buf, "POSE ", 5) != 0) continue;
        double x = 0, y = 0, z = 0, rot = 0;
        if (std::sscanf(buf + 5, "%lf %lf %lf %lf", &x, &y, &z, &rot) == 4) {
            s.remoteX = x;
            s.remoteY = y;
            s.remoteZ = z;
            s.remoteRotY = rot;
            s.hasRemote = true;
            s.lastRemoteMs = nowMs;
        }
    }
}

inline bool hasRemotePlayer() {
    return state().hasRemote;
}

inline double remoteX() { return state().remoteX; }
inline double remoteY() { return state().remoteY; }
inline double remoteZ() { return state().remoteZ; }
inline double remoteRotY() { return state().remoteRotY; }

inline void shutdownNet() {
    closeSocket();
}

} // namespace afrilang::runtime::gamenet
