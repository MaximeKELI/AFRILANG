#pragma once

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
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

inline bool isSafeUrl(const std::string& url) {
    if (url.size() < 8) return false;
    const bool http = url.rfind("http://", 0) == 0;
    const bool https = url.rfind("https://", 0) == 0;
    if (!http && !https) return false;
    for (char c : url) {
        if (std::isalnum(static_cast<unsigned char>(c))) continue;
        if (c == ':' || c == '/' || c == '.' || c == '-' || c == '_' || c == '?' || c == '&' ||
            c == '=') {
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

inline int connectHost(const std::string& host, std::uint16_t port) {
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

inline std::string readResponseBodyRaw(int fd, std::size_t maxBytes = 1024 * 1024) {
    std::string raw;
    char buffer[4096];
    while (raw.size() < maxBytes) {
        const ssize_t n = recv(fd, buffer, sizeof(buffer), 0);
        if (n <= 0) break;
        raw.append(buffer, static_cast<std::size_t>(n));
    }
    const auto headerEnd = raw.find("\r\n\r\n");
    if (headerEnd == std::string::npos) return raw;
    const std::string headers = raw.substr(0, headerEnd);
    std::string body = raw.substr(headerEnd + 4);
    const std::string clKey = "content-length:";
    std::size_t contentLength = 0;
    std::istringstream headerStream(headers);
    std::string line;
    while (std::getline(headerStream, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();
        std::string lower = line;
        for (char& c : lower) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        if (lower.rfind(clKey, 0) == 0) {
            contentLength = static_cast<std::size_t>(std::stoul(lower.substr(clKey.size())));
        }
    }
    if (contentLength > 0 && body.size() > contentLength) {
        body.resize(contentLength);
    }
    return body;
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

inline std::string readResponseBodySsl(SSL* ssl, std::size_t maxBytes = 1024 * 1024) {
    std::string raw;
    char buffer[4096];
    while (raw.size() < maxBytes) {
        const int n = SSL_read(ssl, buffer, sizeof(buffer));
        if (n <= 0) break;
        raw.append(buffer, static_cast<std::size_t>(n));
    }
    const auto headerEnd = raw.find("\r\n\r\n");
    if (headerEnd == std::string::npos) return raw;
    return raw.substr(headerEnd + 4);
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
        // Reject header injection / smuggling via blank lines or CR in name.
        if (line.find('\r') != std::string::npos) continue;
        out += line;
        out += "\r\n";
    }
    return out;
}

inline std::string httpsRequest(const std::string& method, const ParsedUrl& parsed,
                                const std::string& body = {},
                                const std::string& extraHeaders = {}) {
    static bool sslInit = false;
    if (!sslInit) {
        SSL_library_init();
        SSL_load_error_strings();
        OpenSSL_add_all_algorithms();
        sslInit = true;
    }

    const int fd = connectHost(parsed.host, parsed.port);
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

    if (!sendAllSsl(ssl, request.str())) {
        SSL_shutdown(ssl);
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        close(fd);
        return {};
    }

    const std::string response = readResponseBodySsl(ssl);
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(fd);
    return response;
}
#endif

inline std::string httpRequestPlain(const std::string& method, const ParsedUrl& parsed,
                                    const std::string& body = {},
                                    const std::string& extraHeaders = {}) {
    const int fd = connectHost(parsed.host, parsed.port);
    if (fd < 0) return {};

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

    if (!sendAllFd(fd, request.str())) {
        close(fd);
        return {};
    }
    const std::string response = readResponseBodyRaw(fd);
    close(fd);
    return response;
}

inline std::string httpRequest(const std::string& method, const std::string& url,
                               const std::string& body = {},
                               const std::string& extraHeaders = {}) {
    ParsedUrl parsed;
    if (!parseUrl(url, parsed)) return {};
    if (parsed.useTls) {
#ifdef AFRILANG_HAS_OPENSSL
        return httpsRequest(method, parsed, body, extraHeaders);
#else
        (void)extraHeaders;
        return {};
#endif
    }
    return httpRequestPlain(method, parsed, body, extraHeaders);
}

inline std::string httpGet(const std::string& url) {
    return httpRequest("GET", url);
}

inline std::string httpPost(const std::string& url, const std::string& body) {
    return httpRequest("POST", url, body);
}

// Extra headers: multiline "Key: Value\nKey2: Value2". Invalid URL → "".
inline std::string httpPostHeaders(const std::string& url, const std::string& body,
                                   const std::string& headersText) {
    return httpRequest("POST", url, body, headersText);
}

} // namespace http
} // namespace runtime
} // namespace afrilang
