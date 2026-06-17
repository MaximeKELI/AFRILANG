#pragma once

#include <algorithm>
#include <cstdint>
#include <string>
#include <vector>

namespace afrilang::runtime::bigint {

class BigInt {
public:
    BigInt() : digits_("0") {}

    explicit BigInt(std::string value) : digits_(normalize(std::move(value))) {}

    static BigInt fromInt(std::int64_t value) {
        if (value == 0) return BigInt();
        if (value < 0) return BigInt("-" + std::to_string(-value));
        return BigInt(std::to_string(value));
    }

    std::string toText() const { return digits_; }

    bool isNegative() const { return !digits_.empty() && digits_[0] == '-'; }

private:
    std::string digits_;

    static std::string normalize(std::string s) {
        if (s.empty()) return "0";
        bool neg = false;
        if (s[0] == '-') {
            neg = true;
            s.erase(s.begin());
        }
        while (s.size() > 1 && s[0] == '0') s.erase(s.begin());
        if (s.empty() || s == "0") return "0";
        return neg ? "-" + s : s;
    }

    static std::string stripSign(const std::string& s) {
        return (!s.empty() && s[0] == '-') ? s.substr(1) : s;
    }

    static int cmpAbs(const std::string& a, const std::string& b) {
        const std::string aa = stripSign(a);
        const std::string bb = stripSign(b);
        if (aa.size() != bb.size()) return aa.size() < bb.size() ? -1 : 1;
        if (aa == bb) return 0;
        return aa < bb ? -1 : 1;
    }

    static std::string addAbs(const std::string& a, const std::string& b) {
        const std::string aa = stripSign(a);
        const std::string bb = stripSign(b);
        std::string out;
        int carry = 0;
        std::size_t i = aa.size();
        std::size_t j = bb.size();
        while (i > 0 || j > 0 || carry) {
            const int da = i > 0 ? aa[--i] - '0' : 0;
            const int db = j > 0 ? bb[--j] - '0' : 0;
            const int sum = da + db + carry;
            out.push_back(static_cast<char>('0' + sum % 10));
            carry = sum / 10;
        }
        std::reverse(out.begin(), out.end());
        return out.empty() ? "0" : out;
    }

    static std::string subAbs(const std::string& a, const std::string& b) {
        const std::string aa = stripSign(a);
        const std::string bb = stripSign(b);
        std::string out;
        int borrow = 0;
        std::size_t i = aa.size();
        std::size_t j = bb.size();
        while (i > 0) {
            const int da = aa[--i] - '0' - borrow;
            const int db = j > 0 ? bb[--j] - '0' : 0;
            int diff = da - db;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            out.push_back(static_cast<char>('0' + diff));
        }
        while (out.size() > 1 && out.back() == '0') out.pop_back();
        std::reverse(out.begin(), out.end());
        return out.empty() ? "0" : out;
    }

    static std::string mulAbs(const std::string& a, const std::string& b) {
        const std::string aa = stripSign(a);
        const std::string bb = stripSign(b);
        if (aa == "0" || bb == "0") return "0";
        std::vector<int> prod(aa.size() + bb.size(), 0);
        for (int i = static_cast<int>(aa.size()) - 1; i >= 0; --i) {
            for (int j = static_cast<int>(bb.size()) - 1; j >= 0; --j) {
                const int mul = (aa[static_cast<std::size_t>(i)] - '0') *
                                (bb[static_cast<std::size_t>(j)] - '0');
                const int sum = prod[i + j + 1] + mul;
                prod[i + j + 1] = sum % 10;
                prod[i + j] += sum / 10;
            }
        }
        std::string out;
        bool leading = true;
        for (int d : prod) {
            if (leading && d == 0) continue;
            leading = false;
            out.push_back(static_cast<char>('0' + d));
        }
        return out.empty() ? "0" : out;
    }

    friend inline BigInt add(const BigInt& a, const BigInt& b);
    friend inline BigInt sub(const BigInt& a, const BigInt& b);
    friend inline BigInt mul(const BigInt& a, const BigInt& b);
    friend inline int compare(const BigInt& a, const BigInt& b);
};

inline BigInt add(const BigInt& a, const BigInt& b) {
    if (a.isNegative() == b.isNegative()) {
        const std::string sum = BigInt::addAbs(a.digits_, b.digits_);
        return a.isNegative() ? BigInt("-" + sum) : BigInt(sum);
    }
    if (BigInt::cmpAbs(a.digits_, b.digits_) >= 0) {
        const std::string diff = BigInt::subAbs(a.digits_, b.digits_);
        return a.isNegative() ? BigInt("-" + diff) : BigInt(diff);
    }
    const std::string diff = BigInt::subAbs(b.digits_, a.digits_);
    return b.isNegative() ? BigInt("-" + diff) : BigInt(diff);
}

inline BigInt sub(const BigInt& a, const BigInt& b) {
    if (a.isNegative() != b.isNegative()) {
        const std::string sum = BigInt::addAbs(a.digits_, b.digits_);
        return a.isNegative() ? BigInt("-" + sum) : BigInt(sum);
    }
    if (BigInt::cmpAbs(a.digits_, b.digits_) >= 0) {
        const std::string diff = BigInt::subAbs(a.digits_, b.digits_);
        return a.isNegative() ? BigInt("-" + diff) : BigInt(diff);
    }
    const std::string diff = BigInt::subAbs(b.digits_, a.digits_);
    return b.isNegative() ? BigInt(diff) : BigInt("-" + diff);
}

inline BigInt mul(const BigInt& a, const BigInt& b) {
    const std::string prod = BigInt::mulAbs(a.digits_, b.digits_);
    if (prod == "0") return BigInt();
    const bool neg = a.isNegative() != b.isNegative();
    return neg ? BigInt("-" + prod) : BigInt(prod);
}

inline int compare(const BigInt& a, const BigInt& b) {
    if (a.digits_ == b.digits_) return 0;
    if (a.isNegative() != b.isNegative()) return a.isNegative() ? -1 : 1;
    const int c = BigInt::cmpAbs(a.digits_, b.digits_);
    return a.isNegative() ? -c : c;
}

} // namespace afrilang::runtime::bigint
