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
