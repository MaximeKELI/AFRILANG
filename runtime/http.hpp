#pragma once

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#include <cctype>
#include <cstdint>
#include <cstring>
#include <sstream>
#include <string>
#include <vector>

#if defined(__has_include)
#if __has_include(<openssl/ssl.h>)
#include <openssl/err.h>
#include <openssl/ssl.h>
#define AFRILANG_HAS_OPENSSL 1
#endif
#endif

namespace afrilang {
namespace runtime {
namespace http {

inline constexpr int kDefaultTimeoutMs = 30000;

inline bool isSafeUrl(const std::string& url) {
    if (url.size() < 8) return false;
    const bool http = url.rfind("http://", 0) == 0;
    const bool https = url.rfind("https://", 0) == 0;
    if (!http && !https) return false;
    for (char c : url) {
        if (std::isalnum(static_cast<unsigned char>(c))) continue;
        if (c == ':' || c == '/' || c == '.' || c == '-' || c == '_' || c == '?' || c == '&' ||
            c == '=' || c == '%' || c == '+' || c == '#' || c == '@' || c == ',' || c == ';') {
            continue;
        }
        return false;
    }
    return true;
}

struct ParsedUrl {
    std::string host;
    std::string path;
    std::uint16_t port = 80;
    bool useTls = false;
};

struct HttpResponse {
    int status = 0;
    std::string body;
    std::string headers;
};

inline bool parseUrl(const std::string& url, ParsedUrl& out) {
    if (!isSafeUrl(url)) return false;
    std::size_t pos = 0;
    if (url.rfind("https://", 0) == 0) {
        out.useTls = true;
        out.port = 443;
        pos = 8;
    } else {
        pos = 7;
    }
    const std::size_t slash = url.find('/', pos);
    const std::string hostPort =
        slash == std::string::npos ? url.substr(pos) : url.substr(pos, slash - pos);
    out.path = slash == std::string::npos ? "/" : url.substr(slash);
    const std::size_t colon = hostPort.find(':');
    if (colon != std::string::npos) {
        out.host = hostPort.substr(0, colon);
        out.port = static_cast<std::uint16_t>(std::stoi(hostPort.substr(colon + 1)));
    } else {
        out.host = hostPort;
    }
    return !out.host.empty();
}

inline void setSocketTimeoutMs(int fd, int timeoutMs) {
    if (fd < 0 || timeoutMs <= 0) return;
    timeval tv{};
    tv.tv_sec = timeoutMs / 1000;
    tv.tv_usec = (timeoutMs % 1000) * 1000;
    setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));
    setsockopt(fd, SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv));
}

inline int connectHost(const std::string& host, std::uint16_t port, int timeoutMs) {
    addrinfo hints{};
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    addrinfo* result = nullptr;
    if (getaddrinfo(host.c_str(), std::to_string(port).c_str(), &hints, &result) != 0) {
        return -1;
    }
    int fd = -1;
    for (addrinfo* rp = result; rp != nullptr; rp = rp->ai_next) {
        fd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (fd < 0) continue;
        setSocketTimeoutMs(fd, timeoutMs);
        if (connect(fd, rp->ai_addr, rp->ai_addrlen) == 0) break;
        close(fd);
        fd = -1;
    }
    freeaddrinfo(result);
    return fd;
}

inline bool sendAllFd(int fd, const std::string& data) {
    std::size_t sent = 0;
    while (sent < data.size()) {
        const ssize_t n = send(fd, data.data() + sent, data.size() - sent, 0);
        if (n <= 0) return false;
        sent += static_cast<std::size_t>(n);
    }
    return true;
}

inline HttpResponse parseHttpRaw(const std::string& raw, std::size_t maxBody = 1024 * 1024) {
    HttpResponse resp;
    const auto headerEnd = raw.find("\r\n\r\n");
    if (headerEnd == std::string::npos) {
        resp.body = raw;
        return resp;
    }
    resp.headers = raw.substr(0, headerEnd);
    resp.body = raw.substr(headerEnd + 4);

    // Status line: HTTP/1.x NNN ...
    {
        const auto lineEnd = resp.headers.find("\r\n");
        const std::string statusLine =
            lineEnd == std::string::npos ? resp.headers : resp.headers.substr(0, lineEnd);
        const auto sp1 = statusLine.find(' ');
        if (sp1 != std::string::npos) {
            const auto sp2 = statusLine.find(' ', sp1 + 1);
            const std::string code = sp2 == std::string::npos
                                         ? statusLine.substr(sp1 + 1)
                                         : statusLine.substr(sp1 + 1, sp2 - sp1 - 1);
            try {
                resp.status = std::stoi(code);
            } catch (...) {
                resp.status = 0;
            }
        }
    }

    const std::string clKey = "content-length:";
    std::size_t contentLength = 0;
    std::istringstream headerStream(resp.headers);
    std::string line;
    while (std::getline(headerStream, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();
        std::string lower = line;
        for (char& c : lower) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        if (lower.rfind(clKey, 0) == 0) {
            try {
                contentLength = static_cast<std::size_t>(std::stoul(lower.substr(clKey.size())));
            } catch (...) {
                contentLength = 0;
            }
        }
    }
    if (contentLength > 0 && resp.body.size() > contentLength) {
        resp.body.resize(contentLength);
    }
    if (resp.body.size() > maxBody) resp.body.resize(maxBody);
    return resp;
}

inline std::string readAllFd(int fd, std::size_t maxBytes = 1024 * 1024) {
    std::string raw;
    char buffer[4096];
    while (raw.size() < maxBytes) {
        const ssize_t n = recv(fd, buffer, sizeof(buffer), 0);
        if (n <= 0) break;
        raw.append(buffer, static_cast<std::size_t>(n));
    }
    return raw;
}

// Normalize multiline "Key: Value\n…" into HTTP header block lines ending with CRLF.
inline std::string normalizeExtraHeaders(const std::string& headersText) {
    if (headersText.empty()) return {};
    std::string out;
    std::size_t start = 0;
    while (start < headersText.size()) {
        std::size_t end = headersText.find('\n', start);
        if (end == std::string::npos) end = headersText.size();
        std::string line = headersText.substr(start, end - start);
        if (!line.empty() && line.back() == '\r') line.pop_back();
        start = end + 1;
        if (line.empty()) continue;
        if (line.find('\r') != std::string::npos) continue;
        out += line;
        out += "\r\n";
    }
    return out;
}

inline std::string buildRequest(const std::string& method, const ParsedUrl& parsed,
                                const std::string& body, const std::string& extraHeaders) {
    std::ostringstream request;
    request << method << " " << parsed.path << " HTTP/1.1\r\n";
    request << "Host: " << parsed.host << "\r\n";
    request << "Connection: close\r\n";
    request << "User-Agent: afrilang/1.0\r\n";
    if (!body.empty()) {
        request << "Content-Type: application/json\r\n";
        request << "Content-Length: " << body.size() << "\r\n";
    }
    request << normalizeExtraHeaders(extraHeaders);
    request << "\r\n";
    if (!body.empty()) request << body;
    return request.str();
}

#ifdef AFRILANG_HAS_OPENSSL
inline bool sendAllSsl(SSL* ssl, const std::string& data) {
    std::size_t sent = 0;
    while (sent < data.size()) {
        const int n = SSL_write(ssl, data.data() + sent,
                                static_cast<int>(data.size() - sent));
        if (n <= 0) return false;
        sent += static_cast<std::size_t>(n);
    }
    return true;
}

inline std::string readAllSsl(SSL* ssl, std::size_t maxBytes = 1024 * 1024) {
    std::string raw;
    char buffer[4096];
    while (raw.size() < maxBytes) {
        const int n = SSL_read(ssl, buffer, sizeof(buffer));
        if (n <= 0) break;
        raw.append(buffer, static_cast<std::size_t>(n));
    }
    return raw;
}

inline HttpResponse httpsRequestEx(const std::string& method, const ParsedUrl& parsed,
                                   const std::string& body, const std::string& extraHeaders,
                                   int timeoutMs) {
    static bool sslInit = false;
    if (!sslInit) {
        SSL_library_init();
        SSL_load_error_strings();
        OpenSSL_add_all_algorithms();
        sslInit = true;
    }

    const int fd = connectHost(parsed.host, parsed.port, timeoutMs);
    if (fd < 0) return {};

    SSL_CTX* ctx = SSL_CTX_new(TLS_client_method());
    if (!ctx) {
        close(fd);
        return {};
    }
    SSL* ssl = SSL_new(ctx);
    if (!ssl) {
        SSL_CTX_free(ctx);
        close(fd);
        return {};
    }
    SSL_set_fd(ssl, fd);
    SSL_set_tlsext_host_name(ssl, parsed.host.c_str());

    if (SSL_connect(ssl) != 1) {
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        close(fd);
        return {};
    }

    if (!sendAllSsl(ssl, buildRequest(method, parsed, body, extraHeaders))) {
        SSL_shutdown(ssl);
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        close(fd);
        return {};
    }

    const HttpResponse resp = parseHttpRaw(readAllSsl(ssl));
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(fd);
    return resp;
}
#endif

inline HttpResponse httpRequestPlainEx(const std::string& method, const ParsedUrl& parsed,
                                       const std::string& body, const std::string& extraHeaders,
                                       int timeoutMs) {
    const int fd = connectHost(parsed.host, parsed.port, timeoutMs);
    if (fd < 0) return {};

    if (!sendAllFd(fd, buildRequest(method, parsed, body, extraHeaders))) {
        close(fd);
        return {};
    }
    const HttpResponse resp = parseHttpRaw(readAllFd(fd));
    close(fd);
    return resp;
}

inline HttpResponse httpRequestEx(const std::string& method, const std::string& url,
                                  const std::string& body = {},
                                  const std::string& extraHeaders = {},
                                  int timeoutMs = kDefaultTimeoutMs) {
    ParsedUrl parsed;
    if (!parseUrl(url, parsed)) return {};
    if (parsed.useTls) {
#ifdef AFRILANG_HAS_OPENSSL
        return httpsRequestEx(method, parsed, body, extraHeaders, timeoutMs);
#else
        (void)extraHeaders;
        (void)timeoutMs;
        return {};
#endif
    }
    return httpRequestPlainEx(method, parsed, body, extraHeaders, timeoutMs);
}

inline std::string httpRequest(const std::string& method, const std::string& url,
                               const std::string& body = {},
                               const std::string& extraHeaders = {}) {
    return httpRequestEx(method, url, body, extraHeaders).body;
}

inline std::string httpGet(const std::string& url) {
    return httpRequest("GET", url);
}

inline std::string httpPost(const std::string& url, const std::string& body) {
    return httpRequest("POST", url, body);
}

inline std::string httpPostHeaders(const std::string& url, const std::string& body,
                                   const std::string& headersText) {
    return httpRequest("POST", url, body, headersText);
}

inline std::string httpPut(const std::string& url, const std::string& body) {
    return httpRequest("PUT", url, body);
}

inline std::string httpPatch(const std::string& url, const std::string& body) {
    return httpRequest("PATCH", url, body);
}

inline std::string httpDelete(const std::string& url) {
    return httpRequest("DELETE", url);
}

inline std::string httpMethod(const std::string& method, const std::string& url,
                              const std::string& body) {
    return httpRequest(method, url, body);
}

// Full exchange: "STATUS\nbody" (status 0 / empty on failure).
inline std::string httpExchange(const std::string& method, const std::string& url,
                                const std::string& body, const std::string& headersText) {
    const HttpResponse resp = httpRequestEx(method, url, body, headersText);
    return std::to_string(resp.status) + "\n" + resp.body;
}

inline std::string httpGetTimeout(const std::string& url, double timeoutMs) {
    const int ms = timeoutMs <= 0 ? kDefaultTimeoutMs : static_cast<int>(timeoutMs);
    return httpRequestEx("GET", url, {}, {}, ms).body;
}

inline double httpGetStatus(const std::string& url) {
    return static_cast<double>(httpRequestEx("GET", url).status);
}

inline double httpStatusOf(const std::string& exchange) {
    const auto nl = exchange.find('\n');
    const std::string code = nl == std::string::npos ? exchange : exchange.substr(0, nl);
    try {
        return static_cast<double>(std::stoi(code));
    } catch (...) {
        return 0;
    }
}

inline std::string httpBodyOf(const std::string& exchange) {
    const auto nl = exchange.find('\n');
    if (nl == std::string::npos) return {};
    return exchange.substr(nl + 1);
}

} // namespace http
} // namespace runtime
} // namespace afrilang
