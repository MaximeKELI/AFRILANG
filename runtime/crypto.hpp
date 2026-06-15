#pragma once

#include <fstream>
#include <iomanip>
#include <openssl/evp.h>
#include <sstream>
#include <string>

namespace afrilang::runtime::crypto {

inline std::string digestToHex(const unsigned char* digest, std::size_t len) {
    std::ostringstream out;
    for (std::size_t i = 0; i < len; ++i) {
        out << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(digest[i]);
    }
    return out.str();
}

inline std::string sha256(const std::string& data) {
    unsigned char digest[EVP_MAX_MD_SIZE];
    unsigned int digestLen = 0;
    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    if (!ctx) return {};
    EVP_DigestInit_ex(ctx, EVP_sha256(), nullptr);
    EVP_DigestUpdate(ctx, data.data(), data.size());
    EVP_DigestFinal_ex(ctx, digest, &digestLen);
    EVP_MD_CTX_free(ctx);
    return digestToHex(digest, digestLen);
}

inline std::string sha256File(const std::string& path) {
    std::ifstream in(path, std::ios::binary);
    if (!in) return {};
    std::ostringstream buf;
    buf << in.rdbuf();
    return sha256(buf.str());
}

} // namespace afrilang::runtime::crypto
