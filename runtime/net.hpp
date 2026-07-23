#pragma once

// std/net — TCP primitives + minimal HTTP server (plain + TLS with cert/key).

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cstdint>
#include <cstring>
#include <sstream>
#include <string>
#include <vector>

#if defined(__has_include)
#if __has_include(<openssl/ssl.h>)
#include <openssl/err.h>
#include <openssl/ssl.h>
#define AFRILANG_NET_OPENSSL 1
#endif
#endif

namespace afrilang::runtime::net {

inline double tcpConnect(const std::string& host, double port) {
    addrinfo hints{};
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    addrinfo* res = nullptr;
    if (getaddrinfo(host.c_str(), std::to_string(static_cast<int>(port)).c_str(), &hints, &res) !=
        0) {
        return -1;
    }
    int fd = -1;
    for (addrinfo* p = res; p; p = p->ai_next) {
        fd = ::socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (fd < 0) continue;
        if (::connect(fd, p->ai_addr, p->ai_addrlen) == 0) break;
        ::close(fd);
        fd = -1;
    }
    freeaddrinfo(res);
    return static_cast<double>(fd);
}

inline void tcpClose(double fd) {
    if (fd >= 0) ::close(static_cast<int>(fd));
}

inline double tcpWrite(double fd, const std::string& data) {
    if (fd < 0) return -1;
    const ssize_t n = ::send(static_cast<int>(fd), data.data(), data.size(), 0);
    return static_cast<double>(n);
}

inline std::string tcpRead(double fd, double maxBytes) {
    if (fd < 0) return {};
    int nmax = static_cast<int>(maxBytes);
    if (nmax <= 0) nmax = 4096;
    if (nmax > 1024 * 1024) nmax = 1024 * 1024;
    std::string buf(static_cast<std::size_t>(nmax), '\0');
    const ssize_t n = ::recv(static_cast<int>(fd), buf.data(), static_cast<std::size_t>(nmax), 0);
    if (n <= 0) return {};
    buf.resize(static_cast<std::size_t>(n));
    return buf;
}

inline double tcpListen(double port) {
    const int fd = ::socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) return -1;
    int yes = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));
    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(static_cast<uint16_t>(port));
    if (bind(fd, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) != 0 || listen(fd, 16) != 0) {
        ::close(fd);
        return -1;
    }
    return static_cast<double>(fd);
}

inline double tcpAccept(double listenFd) {
    if (listenFd < 0) return -1;
    const int c = ::accept(static_cast<int>(listenFd), nullptr, nullptr);
    return static_cast<double>(c);
}

inline std::string httpOkResponse(const std::string& body) {
    std::ostringstream out;
    out << "HTTP/1.1 200 OK\r\n"
        << "Content-Type: text/plain; charset=utf-8\r\n"
        << "Content-Length: " << body.size() << "\r\n"
        << "Connection: close\r\n\r\n"
        << body;
    return out.str();
}

inline std::string httpResponse(double statusCode, const std::string& body) {
    const int code = static_cast<int>(statusCode);
    const char* reason = "OK";
    if (code == 404) reason = "Not Found";
    else if (code == 400) reason = "Bad Request";
    else if (code == 500) reason = "Internal Server Error";
    else if (code != 200) reason = "Response";
    std::ostringstream out;
    out << "HTTP/1.1 " << code << " " << reason << "\r\n"
        << "Content-Type: text/plain; charset=utf-8\r\n"
        << "Content-Length: " << body.size() << "\r\n"
        << "Connection: close\r\n\r\n"
        << body;
    return out.str();
}

inline std::string httpRequestMethod(const std::string& raw) {
    const std::size_t sp = raw.find(' ');
    if (sp == std::string::npos || sp == 0) return {};
    return raw.substr(0, sp);
}

inline std::string httpRequestPath(const std::string& raw) {
    const std::size_t sp1 = raw.find(' ');
    if (sp1 == std::string::npos) return {};
    const std::size_t sp2 = raw.find(' ', sp1 + 1);
    if (sp2 == std::string::npos) return {};
    std::string target = raw.substr(sp1 + 1, sp2 - sp1 - 1);
    const std::size_t q = target.find('?');
    if (q != std::string::npos) target = target.substr(0, q);
    return target.empty() ? "/" : target;
}

inline std::string httpRequestBody(const std::string& raw) {
    std::size_t sep = raw.find("\r\n\r\n");
    std::size_t skip = 4;
    if (sep == std::string::npos) {
        sep = raw.find("\n\n");
        skip = 2;
    }
    if (sep == std::string::npos) return {};
    return raw.substr(sep + skip);
}

// Serve a fixed body forever (blocking). Returns 0 normally, -1 on listen error.
inline double httpServe(double port, const std::string& body) {
    const double lf = tcpListen(port);
    if (lf < 0) return -1;
    const std::string resp = httpOkResponse(body);
    while (true) {
        const double c = tcpAccept(lf);
        if (c < 0) continue;
        (void)tcpRead(c, 65536); // drain request
        tcpWrite(c, resp);
        tcpClose(c);
    }
}

// Handle exactly one HTTP request then return (useful for tests).
inline double httpServeOnce(double port, const std::string& body) {
    const double lf = tcpListen(port);
    if (lf < 0) return -1;
    const double c = tcpAccept(lf);
    if (c < 0) {
        tcpClose(lf);
        return -1;
    }
    (void)tcpRead(c, 65536);
    tcpWrite(c, httpOkResponse(body));
    tcpClose(c);
    tcpClose(lf);
    return 0;
}

/** Serve one request using a callback: body = handler(method, path, body). Empty → 404. */
template <typename Handler>
inline double httpServeOnceHandler(double port, Handler&& handler) {
    const double lf = tcpListen(port);
    if (lf < 0) return -1;
    const double c = tcpAccept(lf);
    if (c < 0) {
        tcpClose(lf);
        return -1;
    }
    const std::string raw = tcpRead(c, 65536);
    const std::string method = httpRequestMethod(raw);
    const std::string path = httpRequestPath(raw);
    const std::string reqBody = httpRequestBody(raw);
    const std::string outBody = handler(method, path, reqBody);
    if (outBody.empty()) {
        tcpWrite(c, httpResponse(404, "not found"));
    } else {
        tcpWrite(c, httpOkResponse(outBody));
    }
    tcpClose(c);
    tcpClose(lf);
    return 0;
}

#if AFRILANG_NET_OPENSSL
inline double httpServeTlsOnce(double port, const std::string& certFile,
                               const std::string& keyFile, const std::string& body) {
    const double lf = tcpListen(port);
    if (lf < 0) return -1;

    SSL_library_init();
    SSL_load_error_strings();
    const SSL_METHOD* method = TLS_server_method();
    SSL_CTX* ctx = SSL_CTX_new(method);
    if (!ctx) {
        tcpClose(lf);
        return -1;
    }
    if (SSL_CTX_use_certificate_file(ctx, certFile.c_str(), SSL_FILETYPE_PEM) != 1 ||
        SSL_CTX_use_PrivateKey_file(ctx, keyFile.c_str(), SSL_FILETYPE_PEM) != 1) {
        SSL_CTX_free(ctx);
        tcpClose(lf);
        return -1;
    }

    const double c = tcpAccept(lf);
    if (c < 0) {
        SSL_CTX_free(ctx);
        tcpClose(lf);
        return -1;
    }
    SSL* ssl = SSL_new(ctx);
    SSL_set_fd(ssl, static_cast<int>(c));
    if (SSL_accept(ssl) != 1) {
        SSL_free(ssl);
        tcpClose(c);
        SSL_CTX_free(ctx);
        tcpClose(lf);
        return -1;
    }
    char buf[4096];
    (void)SSL_read(ssl, buf, sizeof(buf));
    const std::string resp = httpOkResponse(body);
    SSL_write(ssl, resp.data(), static_cast<int>(resp.size()));
    SSL_shutdown(ssl);
    SSL_free(ssl);
    tcpClose(c);
    SSL_CTX_free(ctx);
    tcpClose(lf);
    return 0;
}
#else
inline double httpServeTlsOnce(double, const std::string&, const std::string&,
                               const std::string&) {
    return -1;
}
#endif

} // namespace afrilang::runtime::net
