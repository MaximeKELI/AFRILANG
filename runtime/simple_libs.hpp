#pragma once

#include <algorithm>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <string>

namespace afrilang::runtime::absnum {
inline double absNumber(double n) { return std::fabs(n); }
inline double absDiff(double a, double b) { return std::fabs(a - b); }
} // namespace

namespace afrilang::runtime::sqrtlib {
inline double sqrtNumber(double n) { return std::sqrt(n); }
inline double square(double n) { return n * n; }
} // namespace

namespace afrilang::runtime::cbrtlib {
inline double cbrtNumber(double n) { return std::cbrt(n); }
inline double cube(double n) { return n * n * n; }
} // namespace

namespace afrilang::runtime::min2 {
inline double min2(double a, double b) { return a < b ? a : b; }
inline double min3(double a, double b, double c) { return std::min({a, b, c}); }
} // namespace

namespace afrilang::runtime::max2 {
inline double max2(double a, double b) { return a > b ? a : b; }
inline double max3(double a, double b, double c) { return std::max({a, b, c}); }
} // namespace

namespace afrilang::runtime::clamp {
inline double clamp(double n, double lo, double hi) { return n < lo ? lo : (n > hi ? hi : n); }
inline double clamp01(double n) { return n < 0 ? 0 : (n > 1 ? 1 : n); }
} // namespace

namespace afrilang::runtime::lerp {
inline double lerp(double a, double b, double t) { return a + (b - a) * t; }
inline double inverseLerp(double a, double b, double v) { return (b == a) ? 0 : (v - a) / (b - a); }
} // namespace

namespace afrilang::runtime::sign {
inline double sign(double n) { return n > 0 ? 1 : (n < 0 ? -1 : 0); }
inline bool isPositive(double n) { return n > 0; }
} // namespace

namespace afrilang::runtime::parity {
inline bool isEven(double n) { return static_cast<long long>(n) % 2 == 0; }
inline bool isOdd(double n) { return static_cast<long long>(n) % 2 != 0; }
} // namespace

namespace afrilang::runtime::trig {
inline double sinDeg(double deg) { return std::sin(deg * 3.141592653589793 / 180.0); }
inline double cosDeg(double deg) { return std::cos(deg * 3.141592653589793 / 180.0); }
} // namespace

namespace afrilang::runtime::trig2 {
inline double tanDeg(double deg) { return std::tan(deg * 3.141592653589793 / 180.0); }
inline double cotDeg(double deg) { return 1.0 / std::tan(deg * 3.141592653589793 / 180.0); }
} // namespace

namespace afrilang::runtime::arc {
inline double asinSafe(double n) { return std::asin(n < -1 ? -1 : (n > 1 ? 1 : n)); }
inline double acosSafe(double n) { return std::acos(n < -1 ? -1 : (n > 1 ? 1 : n)); }
} // namespace

namespace afrilang::runtime::hyper {
inline double sinhN(double n) { return std::sinh(n); }
inline double coshN(double n) { return std::cosh(n); }
} // namespace

namespace afrilang::runtime::deg {
inline double degToRad(double d) { return d * 3.141592653589793 / 180.0; }
inline double radToDeg(double r) { return r * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::roundlib {
inline double roundN(double n) { return std::round(n); }
inline double truncN(double n) { return std::trunc(n); }
} // namespace

namespace afrilang::runtime::modlib {
inline double mod(double a, double b) { return b == 0 ? 0 : std::fmod(a, b); }
inline double wrap(double n, double lo, double hi) { return lo + std::fmod(n - lo, hi - lo); }
} // namespace

namespace afrilang::runtime::gcdlib {
inline double gcd(double a, double b) { { long long x = std::llabs(static_cast<long long>(a)); long long y = std::llabs(static_cast<long long>(b)); while (y) { long long t = x % y; x = y; y = t; } return static_cast<double>(x); } }
inline double lcm(double a, double b) { { double g = gcd(a, b); return g == 0 ? 0 : std::fabs(a * b / g); } }
} // namespace

namespace afrilang::runtime::fact {
inline double factorial(double n) { { long long r = 1; for (long long i = 2; i <= static_cast<long long>(n); ++i) r *= i; return static_cast<double>(r); } }
inline double doubleFact(double n) { { double r = 1; for (long long i = static_cast<long long>(n); i > 0; i -= 2) r *= i; return r; } }
} // namespace

namespace afrilang::runtime::fib {
inline double fib(double n) { { long long a = 0, b = 1; for (long long i = 0; i < static_cast<long long>(n); ++i) { long long t = a + b; a = b; b = t; } return static_cast<double>(a); } }
inline double fibB(double n) { { long long a = 0, b = 1; for (long long i = 0; i < static_cast<long long>(n); ++i) { long long t = a + b; a = b; b = t; } return static_cast<double>(b); } }
} // namespace

namespace afrilang::runtime::prime {
inline bool isPrime(double n) { { long long v = static_cast<long long>(n); if (v < 2) return false; for (long long i = 2; i * i <= v; ++i) if (v % i == 0) return false; return true; } }
inline double nextPrime(double n) { { long long v = static_cast<long long>(n) + 1; while (!isPrime(static_cast<double>(v))) ++v; return static_cast<double>(v); } }
} // namespace

namespace afrilang::runtime::mean {
inline double mean2(double a, double b) { return (a + b) / 2.0; }
inline double mean3(double a, double b, double c) { return (a + b + c) / 3.0; }
} // namespace

namespace afrilang::runtime::percent {
inline double percent(double part, double whole) { return whole == 0 ? 0 : (part / whole) * 100.0; }
inline double percentChange(double oldVal, double newVal) { return oldVal == 0 ? 0 : ((newVal - oldVal) / oldVal) * 100.0; }
} // namespace

namespace afrilang::runtime::ratio {
inline double ratio(double a, double b) { return b == 0 ? 0 : a / b; }
inline double proportion(double a, double b, double total) { return (a + b) == 0 ? 0 : total * a / (a + b); }
} // namespace

namespace afrilang::runtime::dice {
inline double roll(double sides) { return sides <= 0 ? 0 : (std::rand() % static_cast<int>(sides)) + 1; }
inline double roll2d6(double ignored) { (void)ignored; return (std::rand() % 6 + 1) + (std::rand() % 6 + 1); }
} // namespace

namespace afrilang::runtime::coin {
inline bool flip(double ignored) { (void)ignored; return std::rand() % 2 == 0; }
inline double flipN(double n) { { int heads = 0; for (int i = 0; i < static_cast<int>(n); ++i) if (std::rand() % 2 == 0) ++heads; return heads; } }
} // namespace

namespace afrilang::runtime::upper {
inline std::string toUpper(std::string s) { { std::string r = s; for (char& c : r) c = static_cast<char>(std::toupper(static_cast<unsigned char>(c))); return r; } }
inline std::string toLower(std::string s) { { std::string r = s; for (char& c : r) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c))); return r; } }
} // namespace

namespace afrilang::runtime::capitalize {
inline std::string capitalize(std::string s) { return s.empty() ? s : std::string(1, static_cast<char>(std::toupper(static_cast<unsigned char>(s[0])))) + s.substr(1); }
inline std::string titleWord(std::string s) { return capitalize(s); }
} // namespace

namespace afrilang::runtime::prefix {
inline bool startsWith(std::string s, std::string prefix) { return s.rfind(prefix, 0) == 0; }
inline bool endsWith(std::string s, std::string suffix) { return s.size() >= suffix.size() && s.compare(s.size() - suffix.size(), suffix.size(), suffix) == 0; }
} // namespace

namespace afrilang::runtime::repeat {
inline std::string repeatText(std::string s, double n) { { std::string r; for (int i = 0; i < static_cast<int>(n); ++i) r += s; return r; } }
inline std::string repeatChar(std::string c, double n) { return repeatText(c, n); }
} // namespace

namespace afrilang::runtime::pad {
inline std::string padLeft(std::string s, double n, std::string ch) { { std::string r = s; while (static_cast<int>(r.size()) < static_cast<int>(n)) r = (ch.empty() ? " " : ch.substr(0,1)) + r; return r; } }
inline std::string padRight(std::string s, double n, std::string ch) { { std::string r = s; while (static_cast<int>(r.size()) < static_cast<int>(n)) r += (ch.empty() ? " " : ch.substr(0,1)); return r; } }
} // namespace

namespace afrilang::runtime::reverse {
inline std::string reverseText(std::string s) { { return std::string(s.rbegin(), s.rend()); } }
inline std::string reverseWords(std::string s) { { std::string r; std::string w; for (char c : s) { if (c == ' ') { if (!w.empty()) { if (!r.empty()) r = w + " " + r; else r = w; w.clear(); } } else w += c; } if (!w.empty()) r = r.empty() ? w : w + " " + r; return r; } }
} // namespace

namespace afrilang::runtime::textlen {
inline double length(std::string s) { return static_cast<double>(s.size()); }
inline bool isEmpty(std::string s) { return s.empty(); }
} // namespace

namespace afrilang::runtime::concat {
inline std::string concat2(std::string a, std::string b) { return a + b; }
inline std::string concat3(std::string a, std::string b, std::string c) { return a + b + c; }
} // namespace

namespace afrilang::runtime::compare {
inline bool equals(std::string a, std::string b) { return a == b; }
inline bool equalsIgnoreCase(std::string a, std::string b) { { if (a.size() != b.size()) return false; for (std::size_t i = 0; i < a.size(); ++i) if (std::tolower(static_cast<unsigned char>(a[i])) != std::tolower(static_cast<unsigned char>(b[i]))) return false; return true; } }
} // namespace

namespace afrilang::runtime::celsius {
inline double cToF(double c) { return c * 9.0 / 5.0 + 32.0; }
inline double fToC(double f) { return (f - 32.0) * 5.0 / 9.0; }
} // namespace

namespace afrilang::runtime::kelvin {
inline double cToK(double c) { return c + 273.15; }
inline double kToC(double k) { return k - 273.15; }
} // namespace

namespace afrilang::runtime::distance {
inline double kmToMiles(double km) { return km * 0.621371; }
inline double milesToKm(double mi) { return mi / 0.621371; }
} // namespace

namespace afrilang::runtime::weight {
inline double kgToLb(double kg) { return kg * 2.20462; }
inline double lbToKg(double lb) { return lb / 2.20462; }
} // namespace

namespace afrilang::runtime::bytes {
inline double bytesToKb(double b) { return b / 1024.0; }
inline double kbToMb(double kb) { return kb / 1024.0; }
} // namespace

namespace afrilang::runtime::timeconv {
inline double secToMin(double s) { return s / 60.0; }
inline double minToHour(double m) { return m / 60.0; }
} // namespace

namespace afrilang::runtime::msconv {
inline double msToSec(double ms) { return ms / 1000.0; }
inline double secToMs(double s) { return s * 1000.0; }
} // namespace

namespace afrilang::runtime::angle {
inline double normalizeAngle(double d) { { double r = std::fmod(d, 360.0); return r < 0 ? r + 360.0 : r; } }
inline double angleDiff(double a, double b) { { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; } }
} // namespace

namespace afrilang::runtime::hex {
inline std::string toHex(double n) { { std::ostringstream os; os << std::hex << static_cast<long long>(n); return os.str(); } }
inline double fromHex(std::string s) { { return static_cast<double>(std::stoll(s, nullptr, 16)); } }
} // namespace

namespace afrilang::runtime::binary {
inline std::string toBinary(double n) { { std::string r; long long v = static_cast<long long>(n); if (v == 0) return "0"; while (v) { r = char('0' + v % 2) + r; v /= 2; } return r; } }
inline double fromBinary(std::string s) { return static_cast<double>(std::stoll(s, nullptr, 2)); }
} // namespace

namespace afrilang::runtime::octal {
inline std::string toOctal(double n) { { std::ostringstream os; os << std::oct << static_cast<long long>(n); return os.str(); } }
inline double fromOctal(std::string s) { return static_cast<double>(std::stoll(s, nullptr, 8)); }
} // namespace

namespace afrilang::runtime::rot13 {
inline std::string rot13(std::string s) { { std::string r = s; for (char& c : r) { if (c >= 'a' && c <= 'z') c = char('a' + (c - 'a' + 13) % 26); else if (c >= 'A' && c <= 'Z') c = char('A' + (c - 'A' + 13) % 26); } return r; } }
inline std::string rot47(std::string s) { { std::string r = s; for (char& c : r) if (c >= 33 && c <= 126) c = char(33 + (c - 33 + 47) % 94); return r; } }
} // namespace

namespace afrilang::runtime::hash {
inline double hashText(std::string s) { { unsigned long h = 5381; for (unsigned char c : s) h = ((h << 5) + h) + c; return static_cast<double>(h); } }
inline double hashNumber(double n) { return hashText(std::to_string(static_cast<long long>(n))); }
} // namespace

namespace afrilang::runtime::checksum {
inline double xorChecksum(std::string s) { { unsigned char x = 0; for (unsigned char c : s) x ^= c; return static_cast<double>(x); } }
inline double sumBytes(std::string s) { { unsigned long x = 0; for (unsigned char c : s) x += c; return static_cast<double>(x); } }
} // namespace

namespace afrilang::runtime::slug {
inline std::string slugify(std::string s) { { std::string r; for (char c : s) { if (std::isalnum(static_cast<unsigned char>(c))) r += static_cast<char>(std::tolower(static_cast<unsigned char>(c))); else if (c == ' ' || c == '-') { if (!r.empty() && r.back() != '-') r += '-'; } } while (!r.empty() && r.back() == '-') r.pop_back(); return r; } }
inline std::string deslugify(std::string s) { { std::string r; for (char c : s) r += (c == '-') ? ' ' : c; return r; } }
} // namespace

namespace afrilang::runtime::email {
inline bool isEmail(std::string s) { return s.find('@') != std::string::npos && s.find('.') != std::string::npos; }
inline std::string domainOf(std::string s) { { auto p = s.find('@'); return p == std::string::npos ? "" : s.substr(p + 1); } }
} // namespace

namespace afrilang::runtime::phone {
inline bool isPhone(std::string s) { { int d = 0; for (char c : s) if (std::isdigit(static_cast<unsigned char>(c))) ++d; return d >= 8; } }
inline std::string digitsOnly(std::string s) { { std::string r; for (char c : s) if (std::isdigit(static_cast<unsigned char>(c))) r += c; return r; } }
} // namespace

namespace afrilang::runtime::ipv4 {
inline bool isIpv4(std::string s) { { int dots = 0; for (char c : s) if (c == '.') ++dots; return dots == 3; } }
inline double countDots(std::string s) { { int d = 0; for (char c : s) if (c == '.') ++d; return d; } }
} // namespace

namespace afrilang::runtime::html {
inline std::string escapeHtml(std::string s) { { std::string r; for (char c : s) { if (c == '<') r += "&lt;"; else if (c == '>') r += "&gt;"; else if (c == '&') r += "&amp;"; else r += c; } return r; } }
inline std::string unescapeHtml(std::string s) { return s; }
} // namespace

namespace afrilang::runtime::point {
inline double distance2d(double x1, double y1, double x2, double y2) { return std::hypot(x2 - x1, y2 - y1); }
inline double midpointX(double x1, double x2) { return (x1 + x2) / 2.0; }
} // namespace

namespace afrilang::runtime::rect {
inline double area(double w, double h) { return w * h; }
inline double perimeter(double w, double h) { return 2.0 * (w + h); }
} // namespace

namespace afrilang::runtime::circle {
inline double area(double r) { return 3.141592653589793 * r * r; }
inline double circumference(double r) { return 2.0 * 3.141592653589793 * r; }
} // namespace

namespace afrilang::runtime::triangle {
inline double areaBaseHeight(double b, double h) { return 0.5 * b * h; }
inline double heron(double a, double b, double c) { { double s = (a + b + c) / 2.0; return std::sqrt(s * (s - a) * (s - b) * (s - c)); } }
} // namespace

namespace afrilang::runtime::vector2 {
inline double dot2(double x1, double y1, double x2, double y2) { return x1 * x2 + y1 * y2; }
inline double length2(double x, double y) { return std::hypot(x, y); }
} // namespace

namespace afrilang::runtime::collision {
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px < rx + rw && py >= ry && py < ry + rh; }
inline bool rectsOverlap(double x1, double y1, double w1, double h1, double x2, double y2, double w2, double h2) { return !(x1 + w1 <= x2 || x2 + w2 <= x1 || y1 + h1 <= y2 || y2 + h2 <= y1); }
} // namespace

namespace afrilang::runtime::color {
inline double rgb(double r, double g, double b) { return r * 65536 + g * 256 + b; }
inline double redOf(double packed) { return static_cast<long long>(packed) / 65536 % 256; }
} // namespace

namespace afrilang::runtime::easing {
inline double easeIn(double t) { return t * t; }
inline double easeOut(double t) { return t * (2.0 - t); }
} // namespace

namespace afrilang::runtime::noise {
inline double noise1D(double x) { { unsigned long n = static_cast<unsigned long>(x * 1000); n = (n << 13) ^ n; return static_cast<double>((n * (n * n * 15731 + 789221) + 1376312589) & 0x7fffffff) / 2147483647.0; } }
inline double noise2D(double x, double y) { return noise1D(x + y * 57.0); }
} // namespace

namespace afrilang::runtime::semver {
inline double parseMajor(std::string s) { { try { return static_cast<double>(std::stoi(s)); } catch (...) { return 0; } } }
inline std::string bumpMajor(std::string s) { { try { return std::to_string(std::stoi(s) + 1) + ".0.0"; } catch (...) { return "1.0.0"; } } }
} // namespace

namespace afrilang::runtime::validate {
inline bool isAlpha(std::string s) { { if (s.empty()) return false; for (char c : s) if (!std::isalpha(static_cast<unsigned char>(c))) return false; return true; } }
inline bool isDigit(std::string s) { { if (s.empty()) return false; for (char c : s) if (!std::isdigit(static_cast<unsigned char>(c))) return false; return true; } }
} // namespace

namespace afrilang::runtime::parse {
inline double parseInt(std::string s) { { try { return static_cast<double>(std::stoll(s)); } catch (...) { return 0; } } }
inline double parseFloat(std::string s) { { try { return std::stod(s); } catch (...) { return 0; } } }
} // namespace

namespace afrilang::runtime::format {
inline std::string formatNumber(double n, double decimals) { { std::ostringstream os; os << std::fixed << std::setprecision(static_cast<int>(decimals)) << n; return os.str(); } }
inline std::string formatPercent(double n) { return formatNumber(n, 1) + "%"; }
} // namespace

namespace afrilang::runtime::currency {
inline std::string formatEuro(double n) { { std::ostringstream os; os << std::fixed << std::setprecision(2) << n; return os.str() + " EUR"; } }
inline std::string formatDollar(double n) { { std::ostringstream os; os << std::fixed << std::setprecision(2) << n; return "$" + os.str(); } }
} // namespace

namespace afrilang::runtime::stopwatch {
inline double nowMs(double ignored) { (void)ignored; return static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count()); }
inline double elapsedMs(double start) { return nowMs(0) - start; }
} // namespace

namespace afrilang::runtime::bits {
inline double bitAnd(double a, double b) { return static_cast<double>(static_cast<long long>(a) & static_cast<long long>(b)); }
inline double bitOr(double a, double b) { return static_cast<double>(static_cast<long long>(a) | static_cast<long long>(b)); }
} // namespace

namespace afrilang::runtime::shift {
inline double shl(double n, double b) { return static_cast<double>(static_cast<long long>(n) << static_cast<int>(b)); }
inline double shr(double n, double b) { return static_cast<double>(static_cast<long long>(n) >> static_cast<int>(b)); }
} // namespace

namespace afrilang::runtime::flags {
inline bool hasFlag(double n, double f) { return (static_cast<long long>(n) & static_cast<long long>(f)) != 0; }
inline double setFlag(double n, double f) { return static_cast<double>(static_cast<long long>(n) | static_cast<long long>(f)); }
} // namespace

namespace afrilang::runtime::order {
inline double cmpNumber(double a, double b) { return a < b ? -1 : (a > b ? 1 : 0); }
inline double cmpText(std::string a, std::string b) { return a < b ? -1 : (a > b ? 1 : 0); }
} // namespace

namespace afrilang::runtime::range {
inline bool inRange(double n, double lo, double hi) { return n >= lo && n <= hi; }
inline double rangeSize(double lo, double hi) { return hi - lo; }
} // namespace

namespace afrilang::runtime::seq {
inline double arithmetic(double a, double d, double n) { return a + d * n; }
inline double geometric(double a, double r, double n) { return a * std::pow(r, n); }
} // namespace

namespace afrilang::runtime::loglib {
inline double log10(double n) { return std::log10(n); }
inline double log2(double n) { return std::log2(n); }
} // namespace

namespace afrilang::runtime::powlib {
inline double pow2(double n) { return std::pow(2.0, n); }
inline double pow10(double n) { return std::pow(10.0, n); }
} // namespace

namespace afrilang::runtime::hypot {
inline double hypot2(double a, double b) { return std::hypot(a, b); }
inline double hypot3(double a, double b, double c) { return std::sqrt(a*a + b*b + c*c); }
} // namespace

namespace afrilang::runtime::stats2 {
inline double sum2(double a, double b) { return a + b; }
inline double product2(double a, double b) { return a * b; }
} // namespace

namespace afrilang::runtime::stats3 {
inline double sum3(double a, double b, double c) { return a + b + c; }
inline double product3(double a, double b, double c) { return a * b * c; }
} // namespace

namespace afrilang::runtime::diff {
inline double delta(double a, double b) { return b - a; }
inline double absDelta(double a, double b) { return std::fabs(b - a); }
} // namespace

namespace afrilang::runtime::avg {
inline double avg4(double a, double b, double c, double d) { return (a + b + c + d) / 4.0; }
inline double avg5(double a, double b, double c, double d, double e) { return (a + b + c + d + e) / 5.0; }
} // namespace

namespace afrilang::runtime::margin {
inline double margin(double cost, double price) { return price == 0 ? 0 : ((price - cost) / price) * 100.0; }
inline double markup(double cost, double price) { return cost == 0 ? 0 : ((price - cost) / cost) * 100.0; }
} // namespace

namespace afrilang::runtime::tax {
inline double addTax(double amount, double rate) { return amount * (1.0 + rate / 100.0); }
inline double taxAmount(double amount, double rate) { return amount * rate / 100.0; }
} // namespace

namespace afrilang::runtime::discount {
inline double applyDiscount(double price, double rate) { return price * (1.0 - rate / 100.0); }
inline double discountAmount(double price, double rate) { return price * rate / 100.0; }
} // namespace

namespace afrilang::runtime::interest {
inline double simpleInterest(double principal, double rate, double years) { return principal * rate * years / 100.0; }
inline double compoundOnce(double principal, double rate) { return principal * (1.0 + rate / 100.0); }
} // namespace

namespace afrilang::runtime::loan {
inline double monthlyPayment(double principal, double rate, double months) { { double r = rate / 100.0 / 12.0; return r == 0 ? principal / months : principal * r / (1.0 - std::pow(1.0 + r, -months)); } }
inline double totalPaid(double payment, double months) { return payment * months; }
} // namespace

namespace afrilang::runtime::speed {
inline double kmhToMs(double kmh) { return kmh / 3.6; }
inline double msToKmh(double ms) { return ms * 3.6; }
} // namespace

namespace afrilang::runtime::volume {
inline double litersToMl(double l) { return l * 1000.0; }
inline double mlToLiters(double ml) { return ml / 1000.0; }
} // namespace

namespace afrilang::runtime::area_conv {
inline double m2ToCm2(double m2) { return m2 * 10000.0; }
inline double cm2ToM2(double cm2) { return cm2 / 10000.0; }
} // namespace

namespace afrilang::runtime::pressure {
inline double barToPsi(double bar) { return bar * 14.5038; }
inline double psiToBar(double psi) { return psi / 14.5038; }
} // namespace

namespace afrilang::runtime::energy {
inline double joulesToCal(double j) { return j / 4.184; }
inline double calToJoules(double cal) { return cal * 4.184; }
} // namespace

namespace afrilang::runtime::bmi {
inline double bmi(double kg, double m) { return m == 0 ? 0 : kg / (m * m); }
inline std::string bmiCategory(double bmi) { return bmi < 18.5 ? "underweight" : (bmi < 25 ? "normal" : "overweight"); }
} // namespace

namespace afrilang::runtime::geo {
inline double haversineKm(double lat1, double lon1, double lat2, double lon2) { { double R = 6371.0; auto rad = [](double d){ return d * 3.141592653589793 / 180.0; }; double dLat = rad(lat2-lat1), dLon = rad(lon2-lon1); double a = std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R * 2 * std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
inline double midLat(double a, double b) { return (a + b) / 2.0; }
} // namespace

namespace afrilang::runtime::compass {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad = [](double d){ return d * 3.141592653589793 / 180.0; }; double y = std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x = std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline std::string cardinal(double deg) { { static const char* dirs[] = {"N","NE","E","SE","S","SW","W","NW"}; int i = static_cast<int>((deg + 22.5) / 45.0) % 8; return dirs[i]; } }
} // namespace

namespace afrilang::runtime::uuid {
inline std::string randomHex(double n) { { static const char* h = "0123456789abcdef"; std::string r; for (int i = 0; i < static_cast<int>(n); ++i) r += h[std::rand() % 16]; return r; } }
inline std::string simpleId(double ignored) { (void)ignored; return randomHex(8); }
} // namespace

namespace afrilang::runtime::counter {
inline double nextId(double ignored) { (void)ignored; { static double c = 0; return ++c; } }
inline double resetId(double ignored) { (void)ignored; { static double c = 0; c = 0; return c; } }
} // namespace

namespace afrilang::runtime::env {
inline std::string getEnv(std::string key) { { const char* v = std::getenv(key.c_str()); return v ? std::string(v) : ""; } }
inline bool hasEnv(std::string key) { return std::getenv(key.c_str()) != nullptr; }
} // namespace

namespace afrilang::runtime::platform {
inline std::string osName(double ignored) { (void)ignored; return "linux"; }
inline std::string archName(double ignored) { (void)ignored; return "x64"; }
} // namespace

namespace afrilang::runtime::pathutil {
inline std::string normalizeSlashes(std::string s) { { std::string r = s; for (char& c : r) if (c == '\\') c = '/'; return r; } }
inline bool hasTrailingSlash(std::string s) { return !s.empty() && s.back() == '/'; }
} // namespace

namespace afrilang::runtime::url {
inline std::string urlEncodeSpace(std::string s) { { std::string r; for (char c : s) r += (c == ' ') ? "%20" : std::string(1, c); return r; } }
inline std::string urlDecodeSpace(std::string s) { { std::string r; for (std::size_t i = 0; i < s.size(); ++i) { if (s[i] == '%' && i + 2 < s.size() && s[i+1]=='2' && s[i+2]=='0') { r += ' '; i += 2; } else r += s[i]; } return r; } }
} // namespace

namespace afrilang::runtime::csv {
inline std::string splitCsv2(std::string line) { { auto p = line.find(','); return p == std::string::npos ? line : line.substr(0, p); } }
inline std::string splitCsvRest(std::string line) { { auto p = line.find(','); return p == std::string::npos ? "" : line.substr(p + 1); } }
} // namespace

namespace afrilang::runtime::jsonlite {
inline std::string quote(std::string s) { return "\"" + s + "\""; }
inline std::string pair(std::string key, std::string value) { return quote(key) + ":" + quote(value); }
} // namespace

namespace afrilang::runtime::xml {
inline std::string tag(std::string name, std::string content) { return "<" + name + ">" + content + "</" + name + ">"; }
inline std::string escapeXml(std::string s) { { std::string r; for (char c : s) { if (c == '<') r += "&lt;"; else if (c == '>') r += "&gt;"; else r += c; } return r; } }
} // namespace

namespace afrilang::runtime::markdown {
inline std::string bold(std::string s) { return "**" + s + "**"; }
inline std::string italic(std::string s) { return "*" + s + "*"; }
} // namespace

namespace afrilang::runtime::password {
inline double strengthScore(std::string s) { { double sc = 0; if (s.size() >= 8) sc += 1; if (s.size() >= 12) sc += 1; for (char c : s) { if (std::isdigit(static_cast<unsigned char>(c))) sc += 0.5; if (std::isupper(static_cast<unsigned char>(c))) sc += 0.5; } return sc; } }
inline bool isStrong(std::string s) { return strengthScore(s) >= 3; }
} // namespace

namespace afrilang::runtime::base64 {
inline std::string encode64(std::string s) { return s; }
inline std::string decode64(std::string s) { return s; }
} // namespace

namespace afrilang::runtime::mime {
inline bool isTextPlain(std::string mime) { return mime == "text/plain"; }
inline bool isJson(std::string mime) { return mime == "application/json"; }
} // namespace

namespace afrilang::runtime::httpcode {
inline bool isSuccess(double code) { return code >= 200 && code < 300; }
inline bool isRedirect(double code) { return code >= 300 && code < 400; }
} // namespace

namespace afrilang::runtime::game {
inline double scoreBonus(double score, double level) { return score + level * 100; }
inline double levelFromXp(double xp) { return std::floor(xp / 1000.0) + 1; }
} // namespace

namespace afrilang::runtime::music {
inline double midiNote(double octave, double note) { return (octave + 1) * 12 + note; }
inline double freqA4(double ignored) { (void)ignored; return 440.0; }
} // namespace

namespace afrilang::runtime::color2 {
inline double lerpColor(double a, double b, double t) { return a + (b - a) * t; }
inline double invertRgb(double packed) { { long long r = static_cast<long long>(packed)/65536%256; long long g = static_cast<long long>(packed)/256%256; long long b = static_cast<long long>(packed)%256; return (255-r)*65536+(255-g)*256+(255-b); } }
} // namespace

namespace afrilang::runtime::matrix2 {
inline double det2(double a, double b, double c, double d) { return a * d - b * c; }
inline double trace2(double a, double d) { return a + d; }
} // namespace

namespace afrilang::runtime::physics {
inline double force(double m, double a) { return m * a; }
inline double kineticEnergy(double m, double v) { return 0.5 * m * v * v; }
} // namespace

namespace afrilang::runtime::chemistry {
inline double moles(double mass, double molarMass) { return molarMass == 0 ? 0 : mass / molarMass; }
inline double mass(double moles, double molarMass) { return moles * molarMass; }
} // namespace

namespace afrilang::runtime::units {
inline double inchToCm(double inch) { return inch * 2.54; }
inline double cmToInch(double cm) { return cm / 2.54; }
} // namespace

namespace afrilang::runtime::paper {
inline double a4WidthCm(double ignored) { (void)ignored; return 21.0; }
inline double a4HeightCm(double ignored) { (void)ignored; return 29.7; }
} // namespace

namespace afrilang::runtime::roman {
inline std::string toRoman(double n) { { static const std::pair<int,const char*> map[] = {{1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}}; int v = static_cast<int>(n); std::string r; for (auto [val, sym] : map) while (v >= val) { r += sym; v -= val; } return r; } }
inline double fromRoman(std::string s) { { int total = 0, prev = 0; for (int i = static_cast<int>(s.size()) - 1; i >= 0; --i) { int val = (s[i]=='I'?1:s[i]=='V'?5:s[i]=='X'?10:s[i]=='L'?50:s[i]=='C'?100:s[i]=='D'?500:s[i]=='M'?1000:0); total += val < prev ? -val : val; prev = val; } return total; } }
} // namespace

namespace afrilang::runtime::spell {
inline std::string spellDigit(double n) { { static const char* w[] = {"zero","one","two","three","four","five","six","seven","eight","nine"}; int i = static_cast<int>(n); return (i >= 0 && i <= 9) ? w[i] : ""; } }
inline std::string spellBool(bool b) { return b ? "yes" : "no"; }
} // namespace

namespace afrilang::runtime::listutil {
inline double firstIndex(double ignored) { (void)ignored; return 0; }
inline double lastIndex(double count) { return count <= 0 ? -1 : count - 1; }
} // namespace

namespace afrilang::runtime::queue {
inline double wrapIndex(double i, double size) { return size == 0 ? 0 : std::fmod(i, size); }
inline double nextIndex(double i, double size) { return size == 0 ? 0 : std::fmod(i + 1, size); }
} // namespace

namespace afrilang::runtime::stackutil {
inline double peekOffset(double size, double offset) { return size - 1 - offset; }
inline bool isEmptyStack(double size) { return size <= 0; }
} // namespace

namespace afrilang::runtime::graph {
inline double edgeKey(double a, double b) { return a * 1000000 + b; }
inline bool selfLoop(double a, double b) { return a == b; }
} // namespace

namespace afrilang::runtime::search {
inline double binarySteps(double n) { return n <= 1 ? 0 : std::floor(std::log2(n)); }
inline double linearWorst(double n) { return n; }
} // namespace

namespace afrilang::runtime::sortkey {
inline double ascKey(double n) { return n; }
inline double descKey(double n) { return -n; }
} // namespace

namespace afrilang::runtime::textwrap {
inline std::string truncate(std::string s, double n) { return static_cast<int>(s.size()) <= static_cast<int>(n) ? s : s.substr(0, static_cast<std::size_t>(n)) + "..."; }
inline std::string ellipsize(std::string s, double n) { return truncate(s, n); }
} // namespace

namespace afrilang::runtime::whitespace {
inline std::string collapseSpaces(std::string s) { { std::string r; bool sp = false; for (char c : s) { if (c == ' ') { if (!sp) r += c; sp = true; } else { r += c; sp = false; } } return r; } }
inline bool isWhitespace(std::string s) { { for (char c : s) if (!std::isspace(static_cast<unsigned char>(c))) return false; return true; } }
} // namespace

namespace afrilang::runtime::charutil {
inline double charCode(std::string s) { return s.empty() ? 0 : static_cast<unsigned char>(s[0]); }
inline std::string fromCharCode(double n) { return std::string(1, static_cast<char>(static_cast<int>(n))); }
} // namespace

namespace afrilang::runtime::version {
inline double compareMajor(std::string a, std::string b) { return a < b ? -1 : (a > b ? 1 : 0); }
inline bool sameMajor(std::string a, std::string b) { return a == b; }
} // namespace

namespace afrilang::runtime::config {
inline bool parseBool(std::string s) { return s == "true" || s == "yes" || s == "1"; }
inline std::string boolToText(bool b) { return b ? "true" : "false"; }
} // namespace

namespace afrilang::runtime::retry {
inline double backoffMs(double attempt) { return std::pow(2.0, attempt) * 100.0; }
inline bool shouldRetry(double attempt, double max) { return attempt < max; }
} // namespace

namespace afrilang::runtime::ratelimit {
inline bool allowBurst(double count, double limit) { return count < limit; }
inline double tokensLeft(double count, double limit) { return limit - count; }
} // namespace

namespace afrilang::runtime::cache {
inline bool ttlExpired(double ageMs, double ttlMs) { return ageMs >= ttlMs; }
inline double freshness(double ageMs, double ttlMs) { return ttlMs == 0 ? 0 : 1.0 - ageMs / ttlMs; }
} // namespace

namespace afrilang::runtime::id {
inline std::string hashId(std::string s) { return std::to_string(static_cast<long long>(afrilang::runtime::hash::hashText(s))); }
inline std::string shortHash(std::string s) { return std::to_string(static_cast<long long>(afrilang::runtime::hash::hashText(s)) % 100000LL); }
} // namespace

namespace afrilang::runtime::locale {
inline std::string decimalComma(std::string s) { { std::string r = s; for (char& c : r) if (c == '.') c = ','; return r; } }
inline std::string decimalDot(std::string s) { { std::string r = s; for (char& c : r) if (c == ',') c = '.'; return r; } }
} // namespace

namespace afrilang::runtime::calendar {
inline double daysInYear(double ignored) { (void)ignored; return 365; }
inline bool isLeap(double year) { { int y = static_cast<int>(year); return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0); } }
} // namespace

namespace afrilang::runtime::weekday {
inline double weekIndex(double day) { return std::fmod(day, 7); }
inline bool isWeekendIndex(double day) { { double i = weekIndex(day); return i == 5 || i == 6; } }
} // namespace

namespace afrilang::runtime::timezone {
inline double utcOffsetHours(double ignored) { (void)ignored; return 0; }
inline double localHour(double utcHour) { return std::fmod(utcHour + utcOffsetHours(0) + 24.0, 24.0); }
} // namespace

namespace afrilang::runtime::network {
inline bool isPortValid(double port) { return port > 0 && port <= 65535; }
inline bool isLocalhost(std::string host) { return host == "localhost" || host == "127.0.0.1"; }
} // namespace

namespace afrilang::runtime::dns {
inline bool isValidHostname(std::string s) { return !s.empty() && s.find(' ') == std::string::npos; }
inline bool hasSubdomain(std::string s) { return s.find('.') != std::string::npos; }
} // namespace

namespace afrilang::runtime::socket {
inline double portPairKey(double a, double b) { return a * 65536 + b; }
inline bool isEphemeralPort(double port) { return port >= 49152; }
} // namespace

namespace afrilang::runtime::process {
inline bool exitOk(double code) { return code == 0; }
inline bool exitFailed(double code) { return code != 0; }
} // namespace

namespace afrilang::runtime::shell {
inline std::string quoteShell(std::string s) { return "'" + s + "'"; }
inline std::string escapeShell(std::string s) { { std::string r; for (char c : s) { if (c == '\'') r += "'\\'\'"; else r += c; } return r; } }
} // namespace

namespace afrilang::runtime::memory {
inline double kbFromBytes(double b) { return b / 1024.0; }
inline double mbFromBytes(double b) { return b / (1024.0 * 1024.0); }
} // namespace

namespace afrilang::runtime::cpu {
inline double clampUsage(double pct) { return pct < 0 ? 0 : (pct > 100 ? 100 : pct); }
inline bool isHighLoad(double pct) { return pct >= 90; }
} // namespace

namespace afrilang::runtime::disk {
inline double usagePercent(double used, double total) { return total == 0 ? 0 : (used / total) * 100.0; }
inline double freeSpace(double used, double total) { return total - used; }
} // namespace

namespace afrilang::runtime::security {
inline std::string maskSecret(std::string s) { return s.size() <= 4 ? "****" : s.substr(0, 2) + "****" + s.substr(s.size() - 2); }
inline bool isMasked(std::string s) { return s.find("****") != std::string::npos; }
} // namespace

namespace afrilang::runtime::audit {
inline std::string auditLine(std::string action, std::string user) { return user + ":" + action; }
inline std::string timestampPrefix(std::string msg) { return std::to_string(static_cast<long long>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count())) + ":" + msg; }
} // namespace

namespace afrilang::runtime::tmpl {
inline std::string fill(std::string pattern, std::string value) { { std::string r = pattern; auto p = r.find("{}"); if (p != std::string::npos) r.replace(p, 2, value); return r; } }
inline std::string fill2(std::string pattern, std::string a, std::string b) { return fill(fill(pattern, a), b); }
} // namespace

namespace afrilang::runtime::i18n {
inline std::string greetFr(std::string name) { return "Bonjour " + name; }
inline std::string greetEn(std::string name) { return "Hello " + name; }
} // namespace

namespace afrilang::runtime::education {
inline std::string gradeLetter(double score) { return score >= 90 ? "A" : (score >= 80 ? "B" : (score >= 70 ? "C" : "D")); }
inline bool passed(double score, double min) { return score >= min; }
} // namespace

namespace afrilang::runtime::quiz {
inline double scorePercent(double correct, double total) { return total == 0 ? 0 : (correct / total) * 100.0; }
inline bool isPerfect(double correct, double total) { return total > 0 && correct == total; }
} // namespace

namespace afrilang::runtime::gamekit001 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.610000; }
inline double shake(double time, double amp) { return std::sin(time * 0.610000 + 0.031416) * amp; }
} // namespace

namespace afrilang::runtime::gamekit002 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.720000; }
} // namespace

namespace afrilang::runtime::gamekit003 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.151000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit004 {
inline double spring(double x, double v, double target, double dt) { double w = 0.168000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 0.940000 + 0.125664) * amp; }
} // namespace

namespace afrilang::runtime::gamekit005 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit006 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.160000; }
inline double shake(double time, double amp) { return std::sin(time * 1.160000 + 0.188495) * amp; }
} // namespace

namespace afrilang::runtime::gamekit007 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.270000; }
} // namespace

namespace afrilang::runtime::gamekit008 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.236000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit009 {
inline double spring(double x, double v, double target, double dt) { double w = 0.253000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.490000 + 0.282743) * amp; }
} // namespace

namespace afrilang::runtime::gamekit010 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit011 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.710000; }
inline double shake(double time, double amp) { return std::sin(time * 1.710000 + 0.345575) * amp; }
} // namespace

namespace afrilang::runtime::gamekit012 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.820000; }
} // namespace

namespace afrilang::runtime::gamekit013 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.321000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit014 {
inline double spring(double x, double v, double target, double dt) { double w = 0.338000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 2.040000 + 0.439823) * amp; }
} // namespace

namespace afrilang::runtime::gamekit015 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit016 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.260000; }
inline double shake(double time, double amp) { return std::sin(time * 2.260000 + 0.502654) * amp; }
} // namespace

namespace afrilang::runtime::gamekit017 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.370000; }
} // namespace

namespace afrilang::runtime::gamekit018 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.406000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit019 {
inline double spring(double x, double v, double target, double dt) { double w = 0.423000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 0.500000 + 0.596902) * amp; }
} // namespace

namespace afrilang::runtime::gamekit020 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit021 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.720000; }
inline double shake(double time, double amp) { return std::sin(time * 0.720000 + 0.659734) * amp; }
} // namespace

namespace afrilang::runtime::gamekit022 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.830000; }
} // namespace

namespace afrilang::runtime::gamekit023 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.491000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit024 {
inline double spring(double x, double v, double target, double dt) { double w = 0.508000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.050000 + 0.753982) * amp; }
} // namespace

namespace afrilang::runtime::gamekit025 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit026 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.270000; }
inline double shake(double time, double amp) { return std::sin(time * 1.270000 + 0.816813) * amp; }
} // namespace

namespace afrilang::runtime::gamekit027 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.380000; }
} // namespace

namespace afrilang::runtime::gamekit028 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.576000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit029 {
inline double spring(double x, double v, double target, double dt) { double w = 0.593000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.600000 + 0.911061) * amp; }
} // namespace

namespace afrilang::runtime::gamekit030 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit031 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.820000; }
inline double shake(double time, double amp) { return std::sin(time * 1.820000 + 0.973893) * amp; }
} // namespace

namespace afrilang::runtime::gamekit032 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.930000; }
} // namespace

namespace afrilang::runtime::gamekit033 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.661000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit034 {
inline double spring(double x, double v, double target, double dt) { double w = 0.678000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 2.150000 + 1.068141) * amp; }
} // namespace

namespace afrilang::runtime::gamekit035 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit036 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.370000; }
inline double shake(double time, double amp) { return std::sin(time * 2.370000 + 1.130972) * amp; }
} // namespace

namespace afrilang::runtime::gamekit037 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.480000; }
} // namespace

namespace afrilang::runtime::gamekit038 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.117000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit039 {
inline double spring(double x, double v, double target, double dt) { double w = 0.134000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 0.610000 + 1.225220) * amp; }
} // namespace

namespace afrilang::runtime::gamekit040 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit041 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.830000; }
inline double shake(double time, double amp) { return std::sin(time * 0.830000 + 1.288052) * amp; }
} // namespace

namespace afrilang::runtime::gamekit042 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.940000; }
} // namespace

namespace afrilang::runtime::gamekit043 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.202000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit044 {
inline double spring(double x, double v, double target, double dt) { double w = 0.219000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.160000 + 1.382300) * amp; }
} // namespace

namespace afrilang::runtime::gamekit045 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit046 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.380000; }
inline double shake(double time, double amp) { return std::sin(time * 1.380000 + 1.445131) * amp; }
} // namespace

namespace afrilang::runtime::gamekit047 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.490000; }
} // namespace

namespace afrilang::runtime::gamekit048 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.287000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit049 {
inline double spring(double x, double v, double target, double dt) { double w = 0.304000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.710000 + 1.539379) * amp; }
} // namespace

namespace afrilang::runtime::gamekit050 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit051 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.930000; }
inline double shake(double time, double amp) { return std::sin(time * 1.930000 + 1.602211) * amp; }
} // namespace

namespace afrilang::runtime::gamekit052 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.040000; }
} // namespace

namespace afrilang::runtime::gamekit053 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.372000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit054 {
inline double spring(double x, double v, double target, double dt) { double w = 0.389000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 2.260000 + 1.696459) * amp; }
} // namespace

namespace afrilang::runtime::gamekit055 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit056 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.480000; }
inline double shake(double time, double amp) { return std::sin(time * 2.480000 + 1.759290) * amp; }
} // namespace

namespace afrilang::runtime::gamekit057 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.500000; }
} // namespace

namespace afrilang::runtime::gamekit058 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.457000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit059 {
inline double spring(double x, double v, double target, double dt) { double w = 0.474000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 0.720000 + 1.853538) * amp; }
} // namespace

namespace afrilang::runtime::gamekit060 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit061 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.940000; }
inline double shake(double time, double amp) { return std::sin(time * 0.940000 + 1.916370) * amp; }
} // namespace

namespace afrilang::runtime::gamekit062 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.050000; }
} // namespace

namespace afrilang::runtime::gamekit063 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.542000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit064 {
inline double spring(double x, double v, double target, double dt) { double w = 0.559000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.270000 + 2.010618) * amp; }
} // namespace

namespace afrilang::runtime::gamekit065 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit066 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.490000; }
inline double shake(double time, double amp) { return std::sin(time * 1.490000 + 2.073449) * amp; }
} // namespace

namespace afrilang::runtime::gamekit067 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.600000; }
} // namespace

namespace afrilang::runtime::gamekit068 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.627000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit069 {
inline double spring(double x, double v, double target, double dt) { double w = 0.644000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.820000 + 2.167697) * amp; }
} // namespace

namespace afrilang::runtime::gamekit070 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit071 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.040000; }
inline double shake(double time, double amp) { return std::sin(time * 2.040000 + 2.230529) * amp; }
} // namespace

namespace afrilang::runtime::gamekit072 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.150000; }
} // namespace

namespace afrilang::runtime::gamekit073 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.712000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit074 {
inline double spring(double x, double v, double target, double dt) { double w = 0.100000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 2.370000 + 2.324777) * amp; }
} // namespace

namespace afrilang::runtime::gamekit075 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit076 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.500000; }
inline double shake(double time, double amp) { return std::sin(time * 0.500000 + 2.387608) * amp; }
} // namespace

namespace afrilang::runtime::gamekit077 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.610000; }
} // namespace

namespace afrilang::runtime::gamekit078 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.168000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit079 {
inline double spring(double x, double v, double target, double dt) { double w = 0.185000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 0.830000 + 2.481856) * amp; }
} // namespace

namespace afrilang::runtime::gamekit080 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit081 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.050000; }
inline double shake(double time, double amp) { return std::sin(time * 1.050000 + 2.544688) * amp; }
} // namespace

namespace afrilang::runtime::gamekit082 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.160000; }
} // namespace

namespace afrilang::runtime::gamekit083 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.253000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit084 {
inline double spring(double x, double v, double target, double dt) { double w = 0.270000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.380000 + 2.638936) * amp; }
} // namespace

namespace afrilang::runtime::gamekit085 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit086 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.600000; }
inline double shake(double time, double amp) { return std::sin(time * 1.600000 + 2.701767) * amp; }
} // namespace

namespace afrilang::runtime::gamekit087 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.710000; }
} // namespace

namespace afrilang::runtime::gamekit088 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.338000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit089 {
inline double spring(double x, double v, double target, double dt) { double w = 0.355000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.930000 + 2.796015) * amp; }
} // namespace

namespace afrilang::runtime::gamekit090 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit091 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.150000; }
inline double shake(double time, double amp) { return std::sin(time * 2.150000 + 2.858847) * amp; }
} // namespace

namespace afrilang::runtime::gamekit092 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.260000; }
} // namespace

namespace afrilang::runtime::gamekit093 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.423000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit094 {
inline double spring(double x, double v, double target, double dt) { double w = 0.440000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 2.480000 + 2.953095) * amp; }
} // namespace

namespace afrilang::runtime::gamekit095 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit096 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.610000; }
inline double shake(double time, double amp) { return std::sin(time * 0.610000 + 3.015926) * amp; }
} // namespace

namespace afrilang::runtime::gamekit097 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.720000; }
} // namespace

namespace afrilang::runtime::gamekit098 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.508000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit099 {
inline double spring(double x, double v, double target, double dt) { double w = 0.525000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 0.940000 + 0.062832) * amp; }
} // namespace

namespace afrilang::runtime::gamekit100 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit101 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.160000; }
inline double shake(double time, double amp) { return std::sin(time * 1.160000 + 0.125664) * amp; }
} // namespace

namespace afrilang::runtime::gamekit102 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.270000; }
} // namespace

namespace afrilang::runtime::gamekit103 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.593000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit104 {
inline double spring(double x, double v, double target, double dt) { double w = 0.610000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.490000 + 0.219911) * amp; }
} // namespace

namespace afrilang::runtime::gamekit105 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit106 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.710000; }
inline double shake(double time, double amp) { return std::sin(time * 1.710000 + 0.282743) * amp; }
} // namespace

namespace afrilang::runtime::gamekit107 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.820000; }
} // namespace

namespace afrilang::runtime::gamekit108 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.678000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit109 {
inline double spring(double x, double v, double target, double dt) { double w = 0.695000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 2.040000 + 0.376991) * amp; }
} // namespace

namespace afrilang::runtime::gamekit110 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit111 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.260000; }
inline double shake(double time, double amp) { return std::sin(time * 2.260000 + 0.439823) * amp; }
} // namespace

namespace afrilang::runtime::gamekit112 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.370000; }
} // namespace

namespace afrilang::runtime::gamekit113 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.134000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit114 {
inline double spring(double x, double v, double target, double dt) { double w = 0.151000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 0.500000 + 0.534070) * amp; }
} // namespace

namespace afrilang::runtime::gamekit115 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit116 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.720000; }
inline double shake(double time, double amp) { return std::sin(time * 0.720000 + 0.596902) * amp; }
} // namespace

namespace afrilang::runtime::gamekit117 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.830000; }
} // namespace

namespace afrilang::runtime::gamekit118 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.219000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit119 {
inline double spring(double x, double v, double target, double dt) { double w = 0.236000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.050000 + 0.691150) * amp; }
} // namespace

namespace afrilang::runtime::gamekit120 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit121 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.270000; }
inline double shake(double time, double amp) { return std::sin(time * 1.270000 + 0.753982) * amp; }
} // namespace

namespace afrilang::runtime::gamekit122 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.380000; }
} // namespace

namespace afrilang::runtime::gamekit123 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.304000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit124 {
inline double spring(double x, double v, double target, double dt) { double w = 0.321000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.600000 + 0.848229) * amp; }
} // namespace

namespace afrilang::runtime::gamekit125 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit126 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.820000; }
inline double shake(double time, double amp) { return std::sin(time * 1.820000 + 0.911061) * amp; }
} // namespace

namespace afrilang::runtime::gamekit127 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.930000; }
} // namespace

namespace afrilang::runtime::gamekit128 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.389000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit129 {
inline double spring(double x, double v, double target, double dt) { double w = 0.406000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 2.150000 + 1.005309) * amp; }
} // namespace

namespace afrilang::runtime::gamekit130 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit131 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.370000; }
inline double shake(double time, double amp) { return std::sin(time * 2.370000 + 1.068141) * amp; }
} // namespace

namespace afrilang::runtime::gamekit132 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.480000; }
} // namespace

namespace afrilang::runtime::gamekit133 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.474000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit134 {
inline double spring(double x, double v, double target, double dt) { double w = 0.491000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 0.610000 + 1.162388) * amp; }
} // namespace

namespace afrilang::runtime::gamekit135 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit136 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.830000; }
inline double shake(double time, double amp) { return std::sin(time * 0.830000 + 1.225220) * amp; }
} // namespace

namespace afrilang::runtime::gamekit137 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.940000; }
} // namespace

namespace afrilang::runtime::gamekit138 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.559000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit139 {
inline double spring(double x, double v, double target, double dt) { double w = 0.576000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.160000 + 1.319468) * amp; }
} // namespace

namespace afrilang::runtime::gamekit140 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit141 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.380000; }
inline double shake(double time, double amp) { return std::sin(time * 1.380000 + 1.382300) * amp; }
} // namespace

namespace afrilang::runtime::gamekit142 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.490000; }
} // namespace

namespace afrilang::runtime::gamekit143 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.644000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit144 {
inline double spring(double x, double v, double target, double dt) { double w = 0.661000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.710000 + 1.476547) * amp; }
} // namespace

namespace afrilang::runtime::gamekit145 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit146 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.930000; }
inline double shake(double time, double amp) { return std::sin(time * 1.930000 + 1.539379) * amp; }
} // namespace

namespace afrilang::runtime::gamekit147 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.040000; }
} // namespace

namespace afrilang::runtime::gamekit148 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.100000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit149 {
inline double spring(double x, double v, double target, double dt) { double w = 0.117000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 2.260000 + 1.633627) * amp; }
} // namespace

namespace afrilang::runtime::gamekit150 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit151 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.480000; }
inline double shake(double time, double amp) { return std::sin(time * 2.480000 + 1.696459) * amp; }
} // namespace

namespace afrilang::runtime::gamekit152 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.500000; }
} // namespace

namespace afrilang::runtime::gamekit153 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.185000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit154 {
inline double spring(double x, double v, double target, double dt) { double w = 0.202000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 0.720000 + 1.790706) * amp; }
} // namespace

namespace afrilang::runtime::gamekit155 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit156 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.940000; }
inline double shake(double time, double amp) { return std::sin(time * 0.940000 + 1.853538) * amp; }
} // namespace

namespace afrilang::runtime::gamekit157 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.050000; }
} // namespace

namespace afrilang::runtime::gamekit158 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.270000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit159 {
inline double spring(double x, double v, double target, double dt) { double w = 0.287000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.270000 + 1.947786) * amp; }
} // namespace

namespace afrilang::runtime::gamekit160 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit161 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.490000; }
inline double shake(double time, double amp) { return std::sin(time * 1.490000 + 2.010618) * amp; }
} // namespace

namespace afrilang::runtime::gamekit162 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.600000; }
} // namespace

namespace afrilang::runtime::gamekit163 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.355000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit164 {
inline double spring(double x, double v, double target, double dt) { double w = 0.372000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.820000 + 2.104865) * amp; }
} // namespace

namespace afrilang::runtime::gamekit165 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit166 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.040000; }
inline double shake(double time, double amp) { return std::sin(time * 2.040000 + 2.167697) * amp; }
} // namespace

namespace afrilang::runtime::gamekit167 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.150000; }
} // namespace

namespace afrilang::runtime::gamekit168 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.440000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit169 {
inline double spring(double x, double v, double target, double dt) { double w = 0.457000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 2.370000 + 2.261945) * amp; }
} // namespace

namespace afrilang::runtime::gamekit170 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit171 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.500000; }
inline double shake(double time, double amp) { return std::sin(time * 0.500000 + 2.324777) * amp; }
} // namespace

namespace afrilang::runtime::gamekit172 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.610000; }
} // namespace

namespace afrilang::runtime::gamekit173 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.525000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit174 {
inline double spring(double x, double v, double target, double dt) { double w = 0.542000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 0.830000 + 2.419024) * amp; }
} // namespace

namespace afrilang::runtime::gamekit175 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit176 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.050000; }
inline double shake(double time, double amp) { return std::sin(time * 1.050000 + 2.481856) * amp; }
} // namespace

namespace afrilang::runtime::gamekit177 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.160000; }
} // namespace

namespace afrilang::runtime::gamekit178 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.610000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit179 {
inline double spring(double x, double v, double target, double dt) { double w = 0.627000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.380000 + 2.576104) * amp; }
} // namespace

namespace afrilang::runtime::gamekit180 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit181 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.600000; }
inline double shake(double time, double amp) { return std::sin(time * 1.600000 + 2.638936) * amp; }
} // namespace

namespace afrilang::runtime::gamekit182 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.710000; }
} // namespace

namespace afrilang::runtime::gamekit183 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.695000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit184 {
inline double spring(double x, double v, double target, double dt) { double w = 0.712000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.930000 + 2.733183) * amp; }
} // namespace

namespace afrilang::runtime::gamekit185 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit186 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.150000; }
inline double shake(double time, double amp) { return std::sin(time * 2.150000 + 2.796015) * amp; }
} // namespace

namespace afrilang::runtime::gamekit187 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.260000; }
} // namespace

namespace afrilang::runtime::gamekit188 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.151000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit189 {
inline double spring(double x, double v, double target, double dt) { double w = 0.168000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 2.480000 + 2.890263) * amp; }
} // namespace

namespace afrilang::runtime::gamekit190 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit191 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.610000; }
inline double shake(double time, double amp) { return std::sin(time * 0.610000 + 2.953095) * amp; }
} // namespace

namespace afrilang::runtime::gamekit192 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.720000; }
} // namespace

namespace afrilang::runtime::gamekit193 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.236000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit194 {
inline double spring(double x, double v, double target, double dt) { double w = 0.253000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 0.940000 + 0.000000) * amp; }
} // namespace

namespace afrilang::runtime::gamekit195 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit196 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.160000; }
inline double shake(double time, double amp) { return std::sin(time * 1.160000 + 0.062832) * amp; }
} // namespace

namespace afrilang::runtime::gamekit197 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.270000; }
} // namespace

namespace afrilang::runtime::gamekit198 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.321000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit199 {
inline double spring(double x, double v, double target, double dt) { double w = 0.338000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.490000 + 0.157079) * amp; }
} // namespace

namespace afrilang::runtime::gamekit200 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit201 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.710000; }
inline double shake(double time, double amp) { return std::sin(time * 1.710000 + 0.219911) * amp; }
} // namespace

namespace afrilang::runtime::gamekit202 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.820000; }
} // namespace

namespace afrilang::runtime::gamekit203 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.406000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit204 {
inline double spring(double x, double v, double target, double dt) { double w = 0.423000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 2.040000 + 0.314159) * amp; }
} // namespace

namespace afrilang::runtime::gamekit205 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit206 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.260000; }
inline double shake(double time, double amp) { return std::sin(time * 2.260000 + 0.376991) * amp; }
} // namespace

namespace afrilang::runtime::gamekit207 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.370000; }
} // namespace

namespace afrilang::runtime::gamekit208 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.491000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit209 {
inline double spring(double x, double v, double target, double dt) { double w = 0.508000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 0.500000 + 0.471238) * amp; }
} // namespace

namespace afrilang::runtime::gamekit210 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit211 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.720000; }
inline double shake(double time, double amp) { return std::sin(time * 0.720000 + 0.534070) * amp; }
} // namespace

namespace afrilang::runtime::gamekit212 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.830000; }
} // namespace

namespace afrilang::runtime::gamekit213 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.576000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit214 {
inline double spring(double x, double v, double target, double dt) { double w = 0.593000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.050000 + 0.628318) * amp; }
} // namespace

namespace afrilang::runtime::gamekit215 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit216 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.270000; }
inline double shake(double time, double amp) { return std::sin(time * 1.270000 + 0.691150) * amp; }
} // namespace

namespace afrilang::runtime::gamekit217 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.380000; }
} // namespace

namespace afrilang::runtime::gamekit218 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.661000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit219 {
inline double spring(double x, double v, double target, double dt) { double w = 0.678000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.600000 + 0.785397) * amp; }
} // namespace

namespace afrilang::runtime::gamekit220 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit221 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.820000; }
inline double shake(double time, double amp) { return std::sin(time * 1.820000 + 0.848229) * amp; }
} // namespace

namespace afrilang::runtime::gamekit222 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.930000; }
} // namespace

namespace afrilang::runtime::gamekit223 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.117000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit224 {
inline double spring(double x, double v, double target, double dt) { double w = 0.134000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 2.150000 + 0.942477) * amp; }
} // namespace

namespace afrilang::runtime::gamekit225 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit226 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.370000; }
inline double shake(double time, double amp) { return std::sin(time * 2.370000 + 1.005309) * amp; }
} // namespace

namespace afrilang::runtime::gamekit227 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.480000; }
} // namespace

namespace afrilang::runtime::gamekit228 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.202000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit229 {
inline double spring(double x, double v, double target, double dt) { double w = 0.219000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 0.610000 + 1.099556) * amp; }
} // namespace

namespace afrilang::runtime::gamekit230 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit231 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.830000; }
inline double shake(double time, double amp) { return std::sin(time * 0.830000 + 1.162388) * amp; }
} // namespace

namespace afrilang::runtime::gamekit232 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.940000; }
} // namespace

namespace afrilang::runtime::gamekit233 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.287000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit234 {
inline double spring(double x, double v, double target, double dt) { double w = 0.304000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.160000 + 1.256636) * amp; }
} // namespace

namespace afrilang::runtime::gamekit235 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit236 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.380000; }
inline double shake(double time, double amp) { return std::sin(time * 1.380000 + 1.319468) * amp; }
} // namespace

namespace afrilang::runtime::gamekit237 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.490000; }
} // namespace

namespace afrilang::runtime::gamekit238 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.372000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit239 {
inline double spring(double x, double v, double target, double dt) { double w = 0.389000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.710000 + 1.413715) * amp; }
} // namespace

namespace afrilang::runtime::gamekit240 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit241 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.930000; }
inline double shake(double time, double amp) { return std::sin(time * 1.930000 + 1.476547) * amp; }
} // namespace

namespace afrilang::runtime::gamekit242 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.040000; }
} // namespace

namespace afrilang::runtime::gamekit243 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.457000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit244 {
inline double spring(double x, double v, double target, double dt) { double w = 0.474000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 2.260000 + 1.570795) * amp; }
} // namespace

namespace afrilang::runtime::gamekit245 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit246 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.480000; }
inline double shake(double time, double amp) { return std::sin(time * 2.480000 + 1.633627) * amp; }
} // namespace

namespace afrilang::runtime::gamekit247 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.500000; }
} // namespace

namespace afrilang::runtime::gamekit248 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.542000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit249 {
inline double spring(double x, double v, double target, double dt) { double w = 0.559000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 0.720000 + 1.727874) * amp; }
} // namespace

namespace afrilang::runtime::gamekit250 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit251 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.940000; }
inline double shake(double time, double amp) { return std::sin(time * 0.940000 + 1.790706) * amp; }
} // namespace

namespace afrilang::runtime::gamekit252 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.050000; }
} // namespace

namespace afrilang::runtime::gamekit253 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.627000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit254 {
inline double spring(double x, double v, double target, double dt) { double w = 0.644000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.270000 + 1.884954) * amp; }
} // namespace

namespace afrilang::runtime::gamekit255 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit256 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.490000; }
inline double shake(double time, double amp) { return std::sin(time * 1.490000 + 1.947786) * amp; }
} // namespace

namespace afrilang::runtime::gamekit257 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.600000; }
} // namespace

namespace afrilang::runtime::gamekit258 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.712000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit259 {
inline double spring(double x, double v, double target, double dt) { double w = 0.100000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.820000 + 2.042033) * amp; }
} // namespace

namespace afrilang::runtime::gamekit260 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit261 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.040000; }
inline double shake(double time, double amp) { return std::sin(time * 2.040000 + 2.104865) * amp; }
} // namespace

namespace afrilang::runtime::gamekit262 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.150000; }
} // namespace

namespace afrilang::runtime::gamekit263 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.168000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit264 {
inline double spring(double x, double v, double target, double dt) { double w = 0.185000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 2.370000 + 2.199113) * amp; }
} // namespace

namespace afrilang::runtime::gamekit265 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit266 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.500000; }
inline double shake(double time, double amp) { return std::sin(time * 0.500000 + 2.261945) * amp; }
} // namespace

namespace afrilang::runtime::gamekit267 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.610000; }
} // namespace

namespace afrilang::runtime::gamekit268 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.253000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit269 {
inline double spring(double x, double v, double target, double dt) { double w = 0.270000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 0.830000 + 2.356192) * amp; }
} // namespace

namespace afrilang::runtime::gamekit270 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit271 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.050000; }
inline double shake(double time, double amp) { return std::sin(time * 1.050000 + 2.419024) * amp; }
} // namespace

namespace afrilang::runtime::gamekit272 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.160000; }
} // namespace

namespace afrilang::runtime::gamekit273 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.338000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit274 {
inline double spring(double x, double v, double target, double dt) { double w = 0.355000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.380000 + 2.513272) * amp; }
} // namespace

namespace afrilang::runtime::gamekit275 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit276 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.600000; }
inline double shake(double time, double amp) { return std::sin(time * 1.600000 + 2.576104) * amp; }
} // namespace

namespace afrilang::runtime::gamekit277 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.710000; }
} // namespace

namespace afrilang::runtime::gamekit278 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.423000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit279 {
inline double spring(double x, double v, double target, double dt) { double w = 0.440000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.930000 + 2.670351) * amp; }
} // namespace

namespace afrilang::runtime::gamekit280 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit281 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.150000; }
inline double shake(double time, double amp) { return std::sin(time * 2.150000 + 2.733183) * amp; }
} // namespace

namespace afrilang::runtime::gamekit282 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.260000; }
} // namespace

namespace afrilang::runtime::gamekit283 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.508000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit284 {
inline double spring(double x, double v, double target, double dt) { double w = 0.525000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 2.480000 + 2.827431) * amp; }
} // namespace

namespace afrilang::runtime::gamekit285 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit286 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.610000; }
inline double shake(double time, double amp) { return std::sin(time * 0.610000 + 2.890263) * amp; }
} // namespace

namespace afrilang::runtime::gamekit287 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.720000; }
} // namespace

namespace afrilang::runtime::gamekit288 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.593000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit289 {
inline double spring(double x, double v, double target, double dt) { double w = 0.610000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 0.940000 + 2.984510) * amp; }
} // namespace

namespace afrilang::runtime::gamekit290 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit291 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.160000; }
inline double shake(double time, double amp) { return std::sin(time * 1.160000 + 0.000000) * amp; }
} // namespace

namespace afrilang::runtime::gamekit292 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.270000; }
} // namespace

namespace afrilang::runtime::gamekit293 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.678000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit294 {
inline double spring(double x, double v, double target, double dt) { double w = 0.695000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.490000 + 0.094248) * amp; }
} // namespace

namespace afrilang::runtime::gamekit295 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit296 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.710000; }
inline double shake(double time, double amp) { return std::sin(time * 1.710000 + 0.157079) * amp; }
} // namespace

namespace afrilang::runtime::gamekit297 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.820000; }
} // namespace

namespace afrilang::runtime::gamekit298 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.134000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit299 {
inline double spring(double x, double v, double target, double dt) { double w = 0.151000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 2.040000 + 0.251327) * amp; }
} // namespace

namespace afrilang::runtime::gamekit300 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit301 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.260000; }
inline double shake(double time, double amp) { return std::sin(time * 2.260000 + 0.314159) * amp; }
} // namespace

namespace afrilang::runtime::gamekit302 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.370000; }
} // namespace

namespace afrilang::runtime::gamekit303 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.219000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit304 {
inline double spring(double x, double v, double target, double dt) { double w = 0.236000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 0.500000 + 0.408407) * amp; }
} // namespace

namespace afrilang::runtime::gamekit305 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit306 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.720000; }
inline double shake(double time, double amp) { return std::sin(time * 0.720000 + 0.471238) * amp; }
} // namespace

namespace afrilang::runtime::gamekit307 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.830000; }
} // namespace

namespace afrilang::runtime::gamekit308 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.304000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit309 {
inline double spring(double x, double v, double target, double dt) { double w = 0.321000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.050000 + 0.565486) * amp; }
} // namespace

namespace afrilang::runtime::gamekit310 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit311 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.270000; }
inline double shake(double time, double amp) { return std::sin(time * 1.270000 + 0.628318) * amp; }
} // namespace

namespace afrilang::runtime::gamekit312 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.380000; }
} // namespace

namespace afrilang::runtime::gamekit313 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.389000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit314 {
inline double spring(double x, double v, double target, double dt) { double w = 0.406000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.600000 + 0.722566) * amp; }
} // namespace

namespace afrilang::runtime::gamekit315 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit316 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.820000; }
inline double shake(double time, double amp) { return std::sin(time * 1.820000 + 0.785397) * amp; }
} // namespace

namespace afrilang::runtime::gamekit317 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.930000; }
} // namespace

namespace afrilang::runtime::gamekit318 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.474000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit319 {
inline double spring(double x, double v, double target, double dt) { double w = 0.491000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 2.150000 + 0.879645) * amp; }
} // namespace

namespace afrilang::runtime::gamekit320 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit321 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.370000; }
inline double shake(double time, double amp) { return std::sin(time * 2.370000 + 0.942477) * amp; }
} // namespace

namespace afrilang::runtime::gamekit322 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.480000; }
} // namespace

namespace afrilang::runtime::gamekit323 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.559000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit324 {
inline double spring(double x, double v, double target, double dt) { double w = 0.576000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 0.610000 + 1.036725) * amp; }
} // namespace

namespace afrilang::runtime::gamekit325 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit326 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.830000; }
inline double shake(double time, double amp) { return std::sin(time * 0.830000 + 1.099556) * amp; }
} // namespace

namespace afrilang::runtime::gamekit327 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.940000; }
} // namespace

namespace afrilang::runtime::gamekit328 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.644000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit329 {
inline double spring(double x, double v, double target, double dt) { double w = 0.661000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.160000 + 1.193804) * amp; }
} // namespace

namespace afrilang::runtime::gamekit330 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit331 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.380000; }
inline double shake(double time, double amp) { return std::sin(time * 1.380000 + 1.256636) * amp; }
} // namespace

namespace afrilang::runtime::gamekit332 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.490000; }
} // namespace

namespace afrilang::runtime::gamekit333 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.100000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit334 {
inline double spring(double x, double v, double target, double dt) { double w = 0.117000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.710000 + 1.350884) * amp; }
} // namespace

namespace afrilang::runtime::gamekit335 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit336 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.930000; }
inline double shake(double time, double amp) { return std::sin(time * 1.930000 + 1.413715) * amp; }
} // namespace

namespace afrilang::runtime::gamekit337 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.040000; }
} // namespace

namespace afrilang::runtime::gamekit338 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.185000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit339 {
inline double spring(double x, double v, double target, double dt) { double w = 0.202000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 2.260000 + 1.507963) * amp; }
} // namespace

namespace afrilang::runtime::gamekit340 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit341 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.480000; }
inline double shake(double time, double amp) { return std::sin(time * 2.480000 + 1.570795) * amp; }
} // namespace

namespace afrilang::runtime::gamekit342 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.500000; }
} // namespace

namespace afrilang::runtime::gamekit343 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.270000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit344 {
inline double spring(double x, double v, double target, double dt) { double w = 0.287000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 0.720000 + 1.665043) * amp; }
} // namespace

namespace afrilang::runtime::gamekit345 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit346 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.940000; }
inline double shake(double time, double amp) { return std::sin(time * 0.940000 + 1.727874) * amp; }
} // namespace

namespace afrilang::runtime::gamekit347 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.050000; }
} // namespace

namespace afrilang::runtime::gamekit348 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.355000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit349 {
inline double spring(double x, double v, double target, double dt) { double w = 0.372000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.270000 + 1.822122) * amp; }
} // namespace

namespace afrilang::runtime::gamekit350 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit351 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.490000; }
inline double shake(double time, double amp) { return std::sin(time * 1.490000 + 1.884954) * amp; }
} // namespace

namespace afrilang::runtime::gamekit352 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.600000; }
} // namespace

namespace afrilang::runtime::gamekit353 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.440000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit354 {
inline double spring(double x, double v, double target, double dt) { double w = 0.457000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.820000 + 1.979202) * amp; }
} // namespace

namespace afrilang::runtime::gamekit355 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit356 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.040000; }
inline double shake(double time, double amp) { return std::sin(time * 2.040000 + 2.042033) * amp; }
} // namespace

namespace afrilang::runtime::gamekit357 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.150000; }
} // namespace

namespace afrilang::runtime::gamekit358 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.525000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit359 {
inline double spring(double x, double v, double target, double dt) { double w = 0.542000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 2.370000 + 2.136281) * amp; }
} // namespace

namespace afrilang::runtime::gamekit360 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit361 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.500000; }
inline double shake(double time, double amp) { return std::sin(time * 0.500000 + 2.199113) * amp; }
} // namespace

namespace afrilang::runtime::gamekit362 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.610000; }
} // namespace

namespace afrilang::runtime::gamekit363 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.610000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit364 {
inline double spring(double x, double v, double target, double dt) { double w = 0.627000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 0.830000 + 2.293361) * amp; }
} // namespace

namespace afrilang::runtime::gamekit365 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit366 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.050000; }
inline double shake(double time, double amp) { return std::sin(time * 1.050000 + 2.356192) * amp; }
} // namespace

namespace afrilang::runtime::gamekit367 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.160000; }
} // namespace

namespace afrilang::runtime::gamekit368 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.695000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit369 {
inline double spring(double x, double v, double target, double dt) { double w = 0.712000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.380000 + 2.450440) * amp; }
} // namespace

namespace afrilang::runtime::gamekit370 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit371 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.600000; }
inline double shake(double time, double amp) { return std::sin(time * 1.600000 + 2.513272) * amp; }
} // namespace

namespace afrilang::runtime::gamekit372 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.710000; }
} // namespace

namespace afrilang::runtime::gamekit373 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.151000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit374 {
inline double spring(double x, double v, double target, double dt) { double w = 0.168000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.930000 + 2.607520) * amp; }
} // namespace

namespace afrilang::runtime::gamekit375 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit376 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.150000; }
inline double shake(double time, double amp) { return std::sin(time * 2.150000 + 2.670351) * amp; }
} // namespace

namespace afrilang::runtime::gamekit377 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.260000; }
} // namespace

namespace afrilang::runtime::gamekit378 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.236000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit379 {
inline double spring(double x, double v, double target, double dt) { double w = 0.253000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 2.480000 + 2.764599) * amp; }
} // namespace

namespace afrilang::runtime::gamekit380 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit381 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.610000; }
inline double shake(double time, double amp) { return std::sin(time * 0.610000 + 2.827431) * amp; }
} // namespace

namespace afrilang::runtime::gamekit382 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.720000; }
} // namespace

namespace afrilang::runtime::gamekit383 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.321000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit384 {
inline double spring(double x, double v, double target, double dt) { double w = 0.338000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 0.940000 + 2.921679) * amp; }
} // namespace

namespace afrilang::runtime::gamekit385 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit386 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.160000; }
inline double shake(double time, double amp) { return std::sin(time * 1.160000 + 2.984510) * amp; }
} // namespace

namespace afrilang::runtime::gamekit387 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.270000; }
} // namespace

namespace afrilang::runtime::gamekit388 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.406000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit389 {
inline double spring(double x, double v, double target, double dt) { double w = 0.423000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.490000 + 0.031416) * amp; }
} // namespace

namespace afrilang::runtime::gamekit390 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit391 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.710000; }
inline double shake(double time, double amp) { return std::sin(time * 1.710000 + 0.094248) * amp; }
} // namespace

namespace afrilang::runtime::gamekit392 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.820000; }
} // namespace

namespace afrilang::runtime::gamekit393 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.491000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit394 {
inline double spring(double x, double v, double target, double dt) { double w = 0.508000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 2.040000 + 0.188495) * amp; }
} // namespace

namespace afrilang::runtime::gamekit395 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit396 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.260000; }
inline double shake(double time, double amp) { return std::sin(time * 2.260000 + 0.251327) * amp; }
} // namespace

namespace afrilang::runtime::gamekit397 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.370000; }
} // namespace

namespace afrilang::runtime::gamekit398 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.576000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit399 {
inline double spring(double x, double v, double target, double dt) { double w = 0.593000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 0.500000 + 0.345575) * amp; }
} // namespace

namespace afrilang::runtime::gamekit400 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit401 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.720000; }
inline double shake(double time, double amp) { return std::sin(time * 0.720000 + 0.408407) * amp; }
} // namespace

namespace afrilang::runtime::gamekit402 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.830000; }
} // namespace

namespace afrilang::runtime::gamekit403 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.661000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit404 {
inline double spring(double x, double v, double target, double dt) { double w = 0.678000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.050000 + 0.502654) * amp; }
} // namespace

namespace afrilang::runtime::gamekit405 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit406 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.270000; }
inline double shake(double time, double amp) { return std::sin(time * 1.270000 + 0.565486) * amp; }
} // namespace

namespace afrilang::runtime::gamekit407 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.380000; }
} // namespace

namespace afrilang::runtime::gamekit408 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.117000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit409 {
inline double spring(double x, double v, double target, double dt) { double w = 0.134000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.600000 + 0.659734) * amp; }
} // namespace

namespace afrilang::runtime::gamekit410 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit411 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.820000; }
inline double shake(double time, double amp) { return std::sin(time * 1.820000 + 0.722566) * amp; }
} // namespace

namespace afrilang::runtime::gamekit412 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.930000; }
} // namespace

namespace afrilang::runtime::gamekit413 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.202000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit414 {
inline double spring(double x, double v, double target, double dt) { double w = 0.219000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 2.150000 + 0.816813) * amp; }
} // namespace

namespace afrilang::runtime::gamekit415 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit416 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.370000; }
inline double shake(double time, double amp) { return std::sin(time * 2.370000 + 0.879645) * amp; }
} // namespace

namespace afrilang::runtime::gamekit417 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.480000; }
} // namespace

namespace afrilang::runtime::gamekit418 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.287000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit419 {
inline double spring(double x, double v, double target, double dt) { double w = 0.304000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 0.610000 + 0.973893) * amp; }
} // namespace

namespace afrilang::runtime::gamekit420 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit421 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.830000; }
inline double shake(double time, double amp) { return std::sin(time * 0.830000 + 1.036725) * amp; }
} // namespace

namespace afrilang::runtime::gamekit422 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.940000; }
} // namespace

namespace afrilang::runtime::gamekit423 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.372000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit424 {
inline double spring(double x, double v, double target, double dt) { double w = 0.389000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.160000 + 1.130972) * amp; }
} // namespace

namespace afrilang::runtime::gamekit425 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit426 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.380000; }
inline double shake(double time, double amp) { return std::sin(time * 1.380000 + 1.193804) * amp; }
} // namespace

namespace afrilang::runtime::gamekit427 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.490000; }
} // namespace

namespace afrilang::runtime::gamekit428 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.457000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit429 {
inline double spring(double x, double v, double target, double dt) { double w = 0.474000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.710000 + 1.288052) * amp; }
} // namespace

namespace afrilang::runtime::gamekit430 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit431 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.930000; }
inline double shake(double time, double amp) { return std::sin(time * 1.930000 + 1.350884) * amp; }
} // namespace

namespace afrilang::runtime::gamekit432 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.040000; }
} // namespace

namespace afrilang::runtime::gamekit433 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.542000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit434 {
inline double spring(double x, double v, double target, double dt) { double w = 0.559000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 2.260000 + 1.445131) * amp; }
} // namespace

namespace afrilang::runtime::gamekit435 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit436 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.480000; }
inline double shake(double time, double amp) { return std::sin(time * 2.480000 + 1.507963) * amp; }
} // namespace

namespace afrilang::runtime::gamekit437 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.500000; }
} // namespace

namespace afrilang::runtime::gamekit438 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.627000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit439 {
inline double spring(double x, double v, double target, double dt) { double w = 0.644000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 0.720000 + 1.602211) * amp; }
} // namespace

namespace afrilang::runtime::gamekit440 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit441 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.940000; }
inline double shake(double time, double amp) { return std::sin(time * 0.940000 + 1.665043) * amp; }
} // namespace

namespace afrilang::runtime::gamekit442 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.050000; }
} // namespace

namespace afrilang::runtime::gamekit443 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.712000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit444 {
inline double spring(double x, double v, double target, double dt) { double w = 0.100000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.270000 + 1.759290) * amp; }
} // namespace

namespace afrilang::runtime::gamekit445 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit446 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.490000; }
inline double shake(double time, double amp) { return std::sin(time * 1.490000 + 1.822122) * amp; }
} // namespace

namespace afrilang::runtime::gamekit447 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.600000; }
} // namespace

namespace afrilang::runtime::gamekit448 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.168000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit449 {
inline double spring(double x, double v, double target, double dt) { double w = 0.185000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.820000 + 1.916370) * amp; }
} // namespace

namespace afrilang::runtime::gamekit450 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit451 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.040000; }
inline double shake(double time, double amp) { return std::sin(time * 2.040000 + 1.979202) * amp; }
} // namespace

namespace afrilang::runtime::gamekit452 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.150000; }
} // namespace

namespace afrilang::runtime::gamekit453 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.253000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit454 {
inline double spring(double x, double v, double target, double dt) { double w = 0.270000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 2.370000 + 2.073449) * amp; }
} // namespace

namespace afrilang::runtime::gamekit455 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit456 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.500000; }
inline double shake(double time, double amp) { return std::sin(time * 0.500000 + 2.136281) * amp; }
} // namespace

namespace afrilang::runtime::gamekit457 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.610000; }
} // namespace

namespace afrilang::runtime::gamekit458 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.338000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit459 {
inline double spring(double x, double v, double target, double dt) { double w = 0.355000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 0.830000 + 2.230529) * amp; }
} // namespace

namespace afrilang::runtime::gamekit460 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit461 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.050000; }
inline double shake(double time, double amp) { return std::sin(time * 1.050000 + 2.293361) * amp; }
} // namespace

namespace afrilang::runtime::gamekit462 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.160000; }
} // namespace

namespace afrilang::runtime::gamekit463 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.423000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit464 {
inline double spring(double x, double v, double target, double dt) { double w = 0.440000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.380000 + 2.387608) * amp; }
} // namespace

namespace afrilang::runtime::gamekit465 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit466 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.600000; }
inline double shake(double time, double amp) { return std::sin(time * 1.600000 + 2.450440) * amp; }
} // namespace

namespace afrilang::runtime::gamekit467 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.710000; }
} // namespace

namespace afrilang::runtime::gamekit468 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.508000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit469 {
inline double spring(double x, double v, double target, double dt) { double w = 0.525000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.930000 + 2.544688) * amp; }
} // namespace

namespace afrilang::runtime::gamekit470 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit471 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.150000; }
inline double shake(double time, double amp) { return std::sin(time * 2.150000 + 2.607520) * amp; }
} // namespace

namespace afrilang::runtime::gamekit472 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.260000; }
} // namespace

namespace afrilang::runtime::gamekit473 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.593000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit474 {
inline double spring(double x, double v, double target, double dt) { double w = 0.610000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 2.480000 + 2.701767) * amp; }
} // namespace

namespace afrilang::runtime::gamekit475 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit476 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.610000; }
inline double shake(double time, double amp) { return std::sin(time * 0.610000 + 2.764599) * amp; }
} // namespace

namespace afrilang::runtime::gamekit477 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.720000; }
} // namespace

namespace afrilang::runtime::gamekit478 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.678000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit479 {
inline double spring(double x, double v, double target, double dt) { double w = 0.695000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 0.940000 + 2.858847) * amp; }
} // namespace

namespace afrilang::runtime::gamekit480 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit481 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.160000; }
inline double shake(double time, double amp) { return std::sin(time * 1.160000 + 2.921679) * amp; }
} // namespace

namespace afrilang::runtime::gamekit482 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.270000; }
} // namespace

namespace afrilang::runtime::gamekit483 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.134000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit484 {
inline double spring(double x, double v, double target, double dt) { double w = 0.151000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.490000 + 3.015926) * amp; }
} // namespace

namespace afrilang::runtime::gamekit485 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit486 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.710000; }
inline double shake(double time, double amp) { return std::sin(time * 1.710000 + 0.031416) * amp; }
} // namespace

namespace afrilang::runtime::gamekit487 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 1.820000; }
} // namespace

namespace afrilang::runtime::gamekit488 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.219000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit489 {
inline double spring(double x, double v, double target, double dt) { double w = 0.236000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 2.040000 + 0.125664) * amp; }
} // namespace

namespace afrilang::runtime::gamekit490 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit491 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.260000; }
inline double shake(double time, double amp) { return std::sin(time * 2.260000 + 0.188495) * amp; }
} // namespace

namespace afrilang::runtime::gamekit492 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 2.370000; }
} // namespace

namespace afrilang::runtime::gamekit493 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.304000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit494 {
inline double spring(double x, double v, double target, double dt) { double w = 0.321000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 0.500000 + 0.282743) * amp; }
} // namespace

namespace afrilang::runtime::gamekit495 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace

namespace afrilang::runtime::gamekit496 {
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.720000; }
inline double shake(double time, double amp) { return std::sin(time * 0.720000 + 0.345575) * amp; }
} // namespace

namespace afrilang::runtime::gamekit497 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double falloff(double dist, double radius) { if (radius <= 0) return 0; double d = std::fabs(dist) / radius; if (d >= 1) return 0; double t = 1.0 - d; return t * t * 0.830000; }
} // namespace

namespace afrilang::runtime::gamekit498 {
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
inline double spring(double x, double v, double target, double dt) { double w = 0.389000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
} // namespace

namespace afrilang::runtime::gamekit499 {
inline double spring(double x, double v, double target, double dt) { double w = 0.406000; double a = (target - x) * w; v = v + a * dt; return x + v * dt; }
inline double shake(double time, double amp) { return std::sin(time * 1.050000 + 0.439823) * amp; }
} // namespace

namespace afrilang::runtime::gamekit500 {
inline double easeIn(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t; }
inline double easeOut(double t) { t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u; }
} // namespace
