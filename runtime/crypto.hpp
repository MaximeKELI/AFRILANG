#pragma once

#include <fstream>
#include <iomanip>
#include <openssl/evp.h>
#include <openssl/hmac.h>
#include <openssl/rand.h>
#include <sstream>
#include <string>
#include <vector>

namespace afrilang::runtime::crypto {

inline std::string digestToHex(const unsigned char* digest, std::size_t len) {
    std::ostringstream out;
    for (std::size_t i = 0; i < len; ++i) {
        out << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(digest[i]);
    }
    return out.str();
}

inline std::string hexEncode(const std::string& data) {
    return digestToHex(reinterpret_cast<const unsigned char*>(data.data()), data.size());
}

inline int hexVal(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    return -1;
}

inline std::string hexDecode(const std::string& hex) {
    if (hex.size() % 2 != 0) return {};
    std::string out;
    out.reserve(hex.size() / 2);
    for (std::size_t i = 0; i < hex.size(); i += 2) {
        const int hi = hexVal(hex[i]);
        const int lo = hexVal(hex[i + 1]);
        if (hi < 0 || lo < 0) return {};
        out.push_back(static_cast<char>((hi << 4) | lo));
    }
    return out;
}

inline std::string digest(const EVP_MD* md, const std::string& data) {
    unsigned char dig[EVP_MAX_MD_SIZE];
    unsigned int digLen = 0;
    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    if (!ctx) return {};
    if (EVP_DigestInit_ex(ctx, md, nullptr) != 1 ||
        EVP_DigestUpdate(ctx, data.data(), data.size()) != 1 ||
        EVP_DigestFinal_ex(ctx, dig, &digLen) != 1) {
        EVP_MD_CTX_free(ctx);
        return {};
    }
    EVP_MD_CTX_free(ctx);
    return digestToHex(dig, digLen);
}

inline std::string sha256(const std::string& data) { return digest(EVP_sha256(), data); }
inline std::string sha512(const std::string& data) { return digest(EVP_sha512(), data); }
inline std::string sha1(const std::string& data) { return digest(EVP_sha1(), data); }
inline std::string sha3_256(const std::string& data) {
#if defined(EVP_sha3_256)
    return digest(EVP_sha3_256(), data);
#else
    return sha256(data);
#endif
}

inline std::string sha256File(const std::string& path) {
    std::ifstream in(path, std::ios::binary);
    if (!in) return {};
    std::ostringstream buf;
    buf << in.rdbuf();
    return sha256(buf.str());
}

inline std::string hmacSha256(const std::string& key, const std::string& data) {
    unsigned char dig[EVP_MAX_MD_SIZE];
    unsigned int digLen = 0;
    unsigned char* ok = HMAC(EVP_sha256(), key.data(), static_cast<int>(key.size()),
                             reinterpret_cast<const unsigned char*>(data.data()), data.size(),
                             dig, &digLen);
    if (!ok) return {};
    return digestToHex(dig, digLen);
}

inline std::string randomBytes(double n) {
    const int count = static_cast<int>(n);
    if (count <= 0) return {};
    std::string out(static_cast<std::size_t>(count), '\0');
    if (RAND_bytes(reinterpret_cast<unsigned char*>(out.data()), count) != 1) return {};
    return out;
}

inline std::string randomHex(double n) {
    return hexEncode(randomBytes(n));
}

// AES-256-GCM: returns hex(nonce[12] || tag[16] || ciphertext)
inline std::string aesGcmEncrypt(const std::string& keyHex, const std::string& plaintext) {
    std::string key = hexDecode(keyHex);
    if (key.size() != 32) {
        // Derive a 32-byte key from arbitrary text via SHA-256
        unsigned char dig[32];
        unsigned int digLen = 0;
        EVP_MD_CTX* ctx = EVP_MD_CTX_new();
        if (!ctx) return {};
        EVP_DigestInit_ex(ctx, EVP_sha256(), nullptr);
        EVP_DigestUpdate(ctx, keyHex.data(), keyHex.size());
        EVP_DigestFinal_ex(ctx, dig, &digLen);
        EVP_MD_CTX_free(ctx);
        key.assign(reinterpret_cast<char*>(dig), digLen);
    }

    unsigned char nonce[12];
    if (RAND_bytes(nonce, sizeof(nonce)) != 1) return {};

    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) return {};
    std::string ciphertext(plaintext.size(), '\0');
    unsigned char tag[16];
    int len = 0;
    int total = 0;
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_gcm(), nullptr,
                           reinterpret_cast<unsigned char*>(key.data()), nonce) != 1 ||
        EVP_EncryptUpdate(ctx, reinterpret_cast<unsigned char*>(ciphertext.data()), &len,
                          reinterpret_cast<const unsigned char*>(plaintext.data()),
                          static_cast<int>(plaintext.size())) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return {};
    }
    total = len;
    if (EVP_EncryptFinal_ex(ctx, reinterpret_cast<unsigned char*>(ciphertext.data()) + total,
                            &len) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return {};
    }
    total += len;
    ciphertext.resize(static_cast<std::size_t>(total));
    if (EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_GET_TAG, 16, tag) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return {};
    }
    EVP_CIPHER_CTX_free(ctx);

    std::string packed;
    packed.append(reinterpret_cast<char*>(nonce), 12);
    packed.append(reinterpret_cast<char*>(tag), 16);
    packed.append(ciphertext);
    return hexEncode(packed);
}

inline std::string aesGcmDecrypt(const std::string& keyHex, const std::string& packedHex) {
    std::string key = hexDecode(keyHex);
    if (key.size() != 32) {
        unsigned char dig[32];
        unsigned int digLen = 0;
        EVP_MD_CTX* ctx = EVP_MD_CTX_new();
        if (!ctx) return {};
        EVP_DigestInit_ex(ctx, EVP_sha256(), nullptr);
        EVP_DigestUpdate(ctx, keyHex.data(), keyHex.size());
        EVP_DigestFinal_ex(ctx, dig, &digLen);
        EVP_MD_CTX_free(ctx);
        key.assign(reinterpret_cast<char*>(dig), digLen);
    }
    std::string packed = hexDecode(packedHex);
    if (packed.size() < 12 + 16) return {};
    const unsigned char* nonce = reinterpret_cast<const unsigned char*>(packed.data());
    const unsigned char* tag = nonce + 12;
    const unsigned char* ct = tag + 16;
    const int ctLen = static_cast<int>(packed.size() - 28);

    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) return {};
    std::string plain(static_cast<std::size_t>(ctLen), '\0');
    int len = 0;
    int total = 0;
    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_gcm(), nullptr,
                           reinterpret_cast<unsigned char*>(key.data()), nonce) != 1 ||
        EVP_DecryptUpdate(ctx, reinterpret_cast<unsigned char*>(plain.data()), &len, ct, ctLen) !=
            1) {
        EVP_CIPHER_CTX_free(ctx);
        return {};
    }
    total = len;
    if (EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_TAG, 16,
                            const_cast<unsigned char*>(tag)) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return {};
    }
    if (EVP_DecryptFinal_ex(ctx, reinterpret_cast<unsigned char*>(plain.data()) + total, &len) !=
        1) {
        EVP_CIPHER_CTX_free(ctx);
        return {}; // auth failure
    }
    total += len;
    EVP_CIPHER_CTX_free(ctx);
    plain.resize(static_cast<std::size_t>(total));
    return plain;
}

// --- Signatures Ed25519 (provenance de paquets) ---------------------------
// Clés au format brut (raw) encodées en hexadécimal : privée = 32 octets
// (graine), publique = 32 octets, signature = 64 octets.

inline std::string ed25519GenPrivate() {
    return hexEncode(randomBytes(32));
}

inline std::string ed25519PublicFromPrivate(const std::string& privHex) {
    const std::string priv = hexDecode(privHex);
    if (priv.size() != 32) return {};
    EVP_PKEY* pkey = EVP_PKEY_new_raw_private_key(
        EVP_PKEY_ED25519, nullptr,
        reinterpret_cast<const unsigned char*>(priv.data()), priv.size());
    if (!pkey) return {};
    unsigned char pub[32];
    std::size_t publen = sizeof(pub);
    std::string out;
    if (EVP_PKEY_get_raw_public_key(pkey, pub, &publen) == 1) {
        out = digestToHex(pub, publen);
    }
    EVP_PKEY_free(pkey);
    return out;
}

inline std::string ed25519Sign(const std::string& privHex, const std::string& message) {
    const std::string priv = hexDecode(privHex);
    if (priv.size() != 32) return {};
    EVP_PKEY* pkey = EVP_PKEY_new_raw_private_key(
        EVP_PKEY_ED25519, nullptr,
        reinterpret_cast<const unsigned char*>(priv.data()), priv.size());
    if (!pkey) return {};
    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    std::string out;
    if (ctx && EVP_DigestSignInit(ctx, nullptr, nullptr, nullptr, pkey) == 1) {
        std::size_t siglen = 0;
        if (EVP_DigestSign(ctx, nullptr, &siglen,
                           reinterpret_cast<const unsigned char*>(message.data()),
                           message.size()) == 1) {
            std::vector<unsigned char> sig(siglen);
            if (EVP_DigestSign(ctx, sig.data(), &siglen,
                               reinterpret_cast<const unsigned char*>(message.data()),
                               message.size()) == 1) {
                out = digestToHex(sig.data(), siglen);
            }
        }
    }
    if (ctx) EVP_MD_CTX_free(ctx);
    EVP_PKEY_free(pkey);
    return out;
}

inline bool ed25519Verify(const std::string& pubHex, const std::string& message,
                          const std::string& sigHex) {
    const std::string pub = hexDecode(pubHex);
    const std::string sig = hexDecode(sigHex);
    if (pub.size() != 32 || sig.size() != 64) return false;
    EVP_PKEY* pkey = EVP_PKEY_new_raw_public_key(
        EVP_PKEY_ED25519, nullptr,
        reinterpret_cast<const unsigned char*>(pub.data()), pub.size());
    if (!pkey) return false;
    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    bool ok = false;
    if (ctx && EVP_DigestVerifyInit(ctx, nullptr, nullptr, nullptr, pkey) == 1) {
        ok = EVP_DigestVerify(ctx, reinterpret_cast<const unsigned char*>(sig.data()), sig.size(),
                              reinterpret_cast<const unsigned char*>(message.data()),
                              message.size()) == 1;
    }
    if (ctx) EVP_MD_CTX_free(ctx);
    EVP_PKEY_free(pkey);
    return ok;
}

} // namespace afrilang::runtime::crypto
