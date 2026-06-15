#include "afrilang/hash.hpp"

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>

#include <openssl/evp.h>

namespace fs = std::filesystem;

namespace afrilang {

namespace {

std::string digestToHex(const unsigned char* digest, std::size_t len) {
    std::ostringstream out;
    for (std::size_t i = 0; i < len; ++i) {
        out << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(digest[i]);
    }
    return out.str();
}

std::string sha256Digest(const unsigned char* data, std::size_t size) {
    unsigned char digest[EVP_MAX_MD_SIZE];
    unsigned int digestLen = 0;
    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    if (!ctx) return {};
    EVP_DigestInit_ex(ctx, EVP_sha256(), nullptr);
    EVP_DigestUpdate(ctx, data, size);
    EVP_DigestFinal_ex(ctx, digest, &digestLen);
    EVP_MD_CTX_free(ctx);
    return digestToHex(digest, digestLen);
}

} // namespace

std::string sha256Hex(const std::string& data) {
    return sha256Digest(reinterpret_cast<const unsigned char*>(data.data()), data.size());
}

std::string sha256File(const std::string& path) {
    std::ifstream in(path, std::ios::binary);
    if (!in) return {};
    std::ostringstream buf;
    buf << in.rdbuf();
    const std::string content = buf.str();
    return sha256Hex(content);
}

std::string sha256Directory(const std::string& dirPath) {
    std::vector<fs::path> files;
    if (!fs::exists(dirPath)) return {};
    for (const auto& entry : fs::recursive_directory_iterator(
             dirPath, fs::directory_options::skip_permission_denied)) {
        if (entry.is_regular_file()) {
            files.push_back(fs::relative(entry.path(), dirPath));
        }
    }
    std::sort(files.begin(), files.end());

    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    if (!ctx) return {};
    EVP_DigestInit_ex(ctx, EVP_sha256(), nullptr);

    for (const auto& rel : files) {
        const fs::path full = fs::path(dirPath) / rel;
        const std::string relStr = rel.generic_string();
        EVP_DigestUpdate(ctx, relStr.data(), relStr.size());
        EVP_DigestUpdate(ctx, "\0", 1);
        const std::string fileHash = sha256File(full.string());
        EVP_DigestUpdate(ctx, fileHash.data(), fileHash.size());
    }

    unsigned char digest[EVP_MAX_MD_SIZE];
    unsigned int digestLen = 0;
    EVP_DigestFinal_ex(ctx, digest, &digestLen);
    EVP_MD_CTX_free(ctx);
    return digestToHex(digest, digestLen);
}

} // namespace afrilang
