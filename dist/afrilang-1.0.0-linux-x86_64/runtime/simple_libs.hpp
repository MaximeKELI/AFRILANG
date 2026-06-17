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

namespace afrilang::runtime::phone {
inline bool isPhone(std::string s) { { int d = 0; for (char c : s) if (std::isdigit(static_cast<unsigned char>(c))) ++d; return d >= 8; } }
inline std::string digitsOnly(std::string s) { { std::string r; for (char c : s) if (std::isdigit(static_cast<unsigned char>(c))) r += c; return r; } }
} // namespace

namespace afrilang::runtime::ipv4 {
inline bool isIpv4(std::string s) { { int dots = 0; for (char c : s) if (c == '.') ++dots; return dots == 3; } }
inline double countDots(std::string s) { { int d = 0; for (char c : s) if (c == '.') ++d; return d; } }
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
inline double xpForScore(double score) { return score * 250.0; }
inline double speedMsForLevel(double level) { { double ms = 140.0 - (level - 1.0) * 8.0; return ms < 55.0 ? 55.0 : ms; } }
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

namespace afrilang::runtime::game2dkit001 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit002 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.052000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit003 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit004 {
inline double shake(double time, double amp) { return std::sin(time * 0.800000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.064000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit005 {
inline double snapGrid(double v) { double g = 28.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit006 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit007 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit008 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.088000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit009 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit010 {
inline double shake(double time, double amp) { return std::sin(time * 0.920000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.100000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit011 {
inline double snapGrid(double v) { double g = 16.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit012 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit013 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit014 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.124000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit015 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit016 {
inline double shake(double time, double amp) { return std::sin(time * 0.820000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.136000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit017 {
inline double snapGrid(double v) { double g = 40.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit018 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit019 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit020 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.160000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit021 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit022 {
inline double shake(double time, double amp) { return std::sin(time * 0.720000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.172000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit023 {
inline double snapGrid(double v) { double g = 28.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit024 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit025 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit026 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.196000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit027 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit028 {
inline double shake(double time, double amp) { return std::sin(time * 0.840000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.208000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit029 {
inline double snapGrid(double v) { double g = 16.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit030 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit031 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit032 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.058000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit033 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit034 {
inline double shake(double time, double amp) { return std::sin(time * 0.740000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.070000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit035 {
inline double snapGrid(double v) { double g = 40.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit036 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit037 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit038 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.094000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit039 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit040 {
inline double shake(double time, double amp) { return std::sin(time * 0.860000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.106000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit041 {
inline double snapGrid(double v) { double g = 28.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit042 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit043 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit044 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.130000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit045 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit046 {
inline double shake(double time, double amp) { return std::sin(time * 0.760000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.142000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit047 {
inline double snapGrid(double v) { double g = 16.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit048 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit049 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit050 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.166000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit051 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit052 {
inline double shake(double time, double amp) { return std::sin(time * 0.880000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.178000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit053 {
inline double snapGrid(double v) { double g = 40.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit054 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit055 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit056 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.202000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit057 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit058 {
inline double shake(double time, double amp) { return std::sin(time * 0.780000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.040000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit059 {
inline double snapGrid(double v) { double g = 28.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit060 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit061 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit062 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.064000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit063 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit064 {
inline double shake(double time, double amp) { return std::sin(time * 0.900000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.076000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit065 {
inline double snapGrid(double v) { double g = 16.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit066 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit067 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit068 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.100000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit069 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit070 {
inline double shake(double time, double amp) { return std::sin(time * 0.800000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.112000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit071 {
inline double snapGrid(double v) { double g = 40.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit072 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit073 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit074 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.136000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit075 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit076 {
inline double shake(double time, double amp) { return std::sin(time * 0.920000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.148000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit077 {
inline double snapGrid(double v) { double g = 28.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit078 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit079 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit080 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.172000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit081 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit082 {
inline double shake(double time, double amp) { return std::sin(time * 0.820000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.184000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit083 {
inline double snapGrid(double v) { double g = 16.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit084 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit085 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit086 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.208000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit087 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit088 {
inline double shake(double time, double amp) { return std::sin(time * 0.720000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.046000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit089 {
inline double snapGrid(double v) { double g = 40.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit090 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit091 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit092 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.070000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit093 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit094 {
inline double shake(double time, double amp) { return std::sin(time * 0.840000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.082000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit095 {
inline double snapGrid(double v) { double g = 28.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit096 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit097 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit098 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.106000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit099 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit100 {
inline double shake(double time, double amp) { return std::sin(time * 0.740000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.118000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit101 {
inline double snapGrid(double v) { double g = 16.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit102 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit103 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit104 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.142000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit105 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit106 {
inline double shake(double time, double amp) { return std::sin(time * 0.860000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.154000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit107 {
inline double snapGrid(double v) { double g = 40.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit108 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit109 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit110 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.178000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit111 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit112 {
inline double shake(double time, double amp) { return std::sin(time * 0.760000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.190000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit113 {
inline double snapGrid(double v) { double g = 28.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit114 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit115 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit116 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.040000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit117 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit118 {
inline double shake(double time, double amp) { return std::sin(time * 0.880000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.052000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit119 {
inline double snapGrid(double v) { double g = 16.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit120 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit121 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit122 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.076000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit123 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit124 {
inline double shake(double time, double amp) { return std::sin(time * 0.780000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.088000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit125 {
inline double snapGrid(double v) { double g = 40.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit126 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit127 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit128 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.112000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit129 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit130 {
inline double shake(double time, double amp) { return std::sin(time * 0.900000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.124000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit131 {
inline double snapGrid(double v) { double g = 28.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit132 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit133 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit134 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.148000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit135 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit136 {
inline double shake(double time, double amp) { return std::sin(time * 0.800000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.160000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit137 {
inline double snapGrid(double v) { double g = 16.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit138 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit139 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit140 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.184000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit141 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit142 {
inline double shake(double time, double amp) { return std::sin(time * 0.920000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.196000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit143 {
inline double snapGrid(double v) { double g = 40.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit144 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit145 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit146 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.046000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit147 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit148 {
inline double shake(double time, double amp) { return std::sin(time * 0.820000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.058000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit149 {
inline double snapGrid(double v) { double g = 28.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit150 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit151 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit152 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.082000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit153 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit154 {
inline double shake(double time, double amp) { return std::sin(time * 0.720000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.094000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit155 {
inline double snapGrid(double v) { double g = 16.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit156 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit157 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit158 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.118000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit159 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit160 {
inline double shake(double time, double amp) { return std::sin(time * 0.840000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.130000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit161 {
inline double snapGrid(double v) { double g = 40.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit162 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit163 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit164 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.154000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit165 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit166 {
inline double shake(double time, double amp) { return std::sin(time * 0.740000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.166000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit167 {
inline double snapGrid(double v) { double g = 28.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit168 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit169 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit170 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.190000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit171 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit172 {
inline double shake(double time, double amp) { return std::sin(time * 0.860000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.202000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit173 {
inline double snapGrid(double v) { double g = 16.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit174 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit175 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit176 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.052000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit177 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit178 {
inline double shake(double time, double amp) { return std::sin(time * 0.760000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.064000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit179 {
inline double snapGrid(double v) { double g = 40.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit180 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit181 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit182 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.088000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit183 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit184 {
inline double shake(double time, double amp) { return std::sin(time * 0.880000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.100000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit185 {
inline double snapGrid(double v) { double g = 28.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit186 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit187 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit188 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.124000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit189 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit190 {
inline double shake(double time, double amp) { return std::sin(time * 0.780000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.136000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit191 {
inline double snapGrid(double v) { double g = 16.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit192 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit193 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit194 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.160000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit195 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit196 {
inline double shake(double time, double amp) { return std::sin(time * 0.900000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.172000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit197 {
inline double snapGrid(double v) { double g = 40.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit198 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit199 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit200 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.196000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit201 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit202 {
inline double shake(double time, double amp) { return std::sin(time * 0.800000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.208000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit203 {
inline double snapGrid(double v) { double g = 28.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit204 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit205 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit206 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.058000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit207 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit208 {
inline double shake(double time, double amp) { return std::sin(time * 0.920000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.070000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit209 {
inline double snapGrid(double v) { double g = 16.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit210 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit211 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit212 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.094000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit213 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit214 {
inline double shake(double time, double amp) { return std::sin(time * 0.820000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.106000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit215 {
inline double snapGrid(double v) { double g = 40.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit216 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit217 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit218 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.130000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit219 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit220 {
inline double shake(double time, double amp) { return std::sin(time * 0.720000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.142000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit221 {
inline double snapGrid(double v) { double g = 28.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit222 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit223 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit224 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.166000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit225 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit226 {
inline double shake(double time, double amp) { return std::sin(time * 0.840000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.178000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit227 {
inline double snapGrid(double v) { double g = 16.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit228 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit229 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit230 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.202000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit231 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit232 {
inline double shake(double time, double amp) { return std::sin(time * 0.740000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.040000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit233 {
inline double snapGrid(double v) { double g = 40.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit234 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit235 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit236 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.064000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit237 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit238 {
inline double shake(double time, double amp) { return std::sin(time * 0.860000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.076000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit239 {
inline double snapGrid(double v) { double g = 28.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit240 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit241 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit242 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.100000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit243 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit244 {
inline double shake(double time, double amp) { return std::sin(time * 0.760000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.112000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit245 {
inline double snapGrid(double v) { double g = 16.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit246 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit247 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit248 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.136000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit249 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit250 {
inline double shake(double time, double amp) { return std::sin(time * 0.880000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.148000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit251 {
inline double snapGrid(double v) { double g = 40.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit252 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit253 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit254 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.172000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit255 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit256 {
inline double shake(double time, double amp) { return std::sin(time * 0.780000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.184000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit257 {
inline double snapGrid(double v) { double g = 28.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit258 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit259 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit260 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.208000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit261 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit262 {
inline double shake(double time, double amp) { return std::sin(time * 0.900000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.046000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit263 {
inline double snapGrid(double v) { double g = 16.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit264 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit265 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit266 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.070000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit267 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit268 {
inline double shake(double time, double amp) { return std::sin(time * 0.800000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.082000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit269 {
inline double snapGrid(double v) { double g = 40.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit270 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit271 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit272 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.106000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit273 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit274 {
inline double shake(double time, double amp) { return std::sin(time * 0.920000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.118000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit275 {
inline double snapGrid(double v) { double g = 28.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit276 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit277 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit278 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.142000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit279 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit280 {
inline double shake(double time, double amp) { return std::sin(time * 0.820000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.154000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit281 {
inline double snapGrid(double v) { double g = 16.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit282 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit283 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit284 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.178000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit285 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit286 {
inline double shake(double time, double amp) { return std::sin(time * 0.720000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.190000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit287 {
inline double snapGrid(double v) { double g = 40.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit288 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit289 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit290 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.040000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit291 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit292 {
inline double shake(double time, double amp) { return std::sin(time * 0.840000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.052000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit293 {
inline double snapGrid(double v) { double g = 28.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit294 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit295 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit296 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.076000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit297 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit298 {
inline double shake(double time, double amp) { return std::sin(time * 0.740000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.088000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit299 {
inline double snapGrid(double v) { double g = 16.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit300 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit301 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit302 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.112000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit303 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit304 {
inline double shake(double time, double amp) { return std::sin(time * 0.860000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.124000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit305 {
inline double snapGrid(double v) { double g = 40.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit306 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit307 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit308 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.148000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit309 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit310 {
inline double shake(double time, double amp) { return std::sin(time * 0.760000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.160000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit311 {
inline double snapGrid(double v) { double g = 28.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit312 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit313 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit314 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.184000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit315 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit316 {
inline double shake(double time, double amp) { return std::sin(time * 0.880000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.196000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit317 {
inline double snapGrid(double v) { double g = 16.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit318 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit319 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit320 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.046000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit321 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit322 {
inline double shake(double time, double amp) { return std::sin(time * 0.780000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.058000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit323 {
inline double snapGrid(double v) { double g = 40.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit324 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit325 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit326 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.082000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit327 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit328 {
inline double shake(double time, double amp) { return std::sin(time * 0.900000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.094000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit329 {
inline double snapGrid(double v) { double g = 28.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit330 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit331 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit332 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.118000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit333 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit334 {
inline double shake(double time, double amp) { return std::sin(time * 0.800000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.130000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit335 {
inline double snapGrid(double v) { double g = 16.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit336 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit337 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit338 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.154000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit339 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit340 {
inline double shake(double time, double amp) { return std::sin(time * 0.920000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.166000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit341 {
inline double snapGrid(double v) { double g = 40.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit342 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit343 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit344 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.190000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit345 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit346 {
inline double shake(double time, double amp) { return std::sin(time * 0.820000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.202000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit347 {
inline double snapGrid(double v) { double g = 28.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit348 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit349 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit350 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.052000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit351 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit352 {
inline double shake(double time, double amp) { return std::sin(time * 0.720000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.064000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit353 {
inline double snapGrid(double v) { double g = 16.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit354 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit355 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit356 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.088000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit357 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit358 {
inline double shake(double time, double amp) { return std::sin(time * 0.840000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.100000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit359 {
inline double snapGrid(double v) { double g = 40.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit360 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit361 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit362 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.124000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit363 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit364 {
inline double shake(double time, double amp) { return std::sin(time * 0.740000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.136000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit365 {
inline double snapGrid(double v) { double g = 28.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit366 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit367 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit368 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.160000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit369 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit370 {
inline double shake(double time, double amp) { return std::sin(time * 0.860000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.172000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit371 {
inline double snapGrid(double v) { double g = 16.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit372 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit373 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit374 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.196000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit375 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit376 {
inline double shake(double time, double amp) { return std::sin(time * 0.760000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.208000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit377 {
inline double snapGrid(double v) { double g = 40.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit378 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit379 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit380 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.058000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit381 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit382 {
inline double shake(double time, double amp) { return std::sin(time * 0.880000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.070000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit383 {
inline double snapGrid(double v) { double g = 28.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit384 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit385 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit386 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.094000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit387 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit388 {
inline double shake(double time, double amp) { return std::sin(time * 0.780000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.106000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit389 {
inline double snapGrid(double v) { double g = 16.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit390 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit391 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit392 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.130000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit393 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit394 {
inline double shake(double time, double amp) { return std::sin(time * 0.900000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.142000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit395 {
inline double snapGrid(double v) { double g = 40.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit396 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit397 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit398 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.166000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit399 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit400 {
inline double shake(double time, double amp) { return std::sin(time * 0.800000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.178000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit401 {
inline double snapGrid(double v) { double g = 28.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit402 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit403 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit404 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.202000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit405 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit406 {
inline double shake(double time, double amp) { return std::sin(time * 0.920000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.040000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit407 {
inline double snapGrid(double v) { double g = 16.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit408 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit409 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit410 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.064000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit411 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit412 {
inline double shake(double time, double amp) { return std::sin(time * 0.820000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.076000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit413 {
inline double snapGrid(double v) { double g = 40.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit414 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit415 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit416 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.100000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit417 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit418 {
inline double shake(double time, double amp) { return std::sin(time * 0.720000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.112000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit419 {
inline double snapGrid(double v) { double g = 28.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit420 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit421 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit422 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.136000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit423 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit424 {
inline double shake(double time, double amp) { return std::sin(time * 0.840000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.148000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit425 {
inline double snapGrid(double v) { double g = 16.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit426 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit427 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit428 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.172000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit429 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit430 {
inline double shake(double time, double amp) { return std::sin(time * 0.740000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.184000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit431 {
inline double snapGrid(double v) { double g = 40.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit432 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit433 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit434 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.208000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit435 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit436 {
inline double shake(double time, double amp) { return std::sin(time * 0.860000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.046000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit437 {
inline double snapGrid(double v) { double g = 28.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit438 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit439 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit440 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.070000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit441 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit442 {
inline double shake(double time, double amp) { return std::sin(time * 0.760000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.082000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit443 {
inline double snapGrid(double v) { double g = 16.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit444 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit445 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit446 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.106000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit447 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit448 {
inline double shake(double time, double amp) { return std::sin(time * 0.880000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.118000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit449 {
inline double snapGrid(double v) { double g = 40.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit450 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit451 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit452 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.142000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit453 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit454 {
inline double shake(double time, double amp) { return std::sin(time * 0.780000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.154000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit455 {
inline double snapGrid(double v) { double g = 28.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit456 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit457 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit458 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.178000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit459 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit460 {
inline double shake(double time, double amp) { return std::sin(time * 0.900000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.190000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit461 {
inline double snapGrid(double v) { double g = 16.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit462 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit463 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit464 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.040000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit465 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit466 {
inline double shake(double time, double amp) { return std::sin(time * 0.800000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.052000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit467 {
inline double snapGrid(double v) { double g = 40.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit468 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit469 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit470 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.076000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit471 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit472 {
inline double shake(double time, double amp) { return std::sin(time * 0.920000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.088000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit473 {
inline double snapGrid(double v) { double g = 28.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit474 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit475 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit476 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.112000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit477 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit478 {
inline double shake(double time, double amp) { return std::sin(time * 0.820000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.124000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit479 {
inline double snapGrid(double v) { double g = 16.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit480 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit481 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit482 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.148000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit483 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit484 {
inline double shake(double time, double amp) { return std::sin(time * 0.720000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.160000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit485 {
inline double snapGrid(double v) { double g = 40.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit486 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit487 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit488 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.184000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit489 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit490 {
inline double shake(double time, double amp) { return std::sin(time * 0.840000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.196000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit491 {
inline double snapGrid(double v) { double g = 28.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit492 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit493 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit494 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.046000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit495 {
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
inline double wrap(double v, double size) { return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size); }
} // namespace

namespace afrilang::runtime::game2dkit496 {
inline double shake(double time, double amp) { return std::sin(time * 0.740000) * amp; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.058000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game2dkit497 {
inline double snapGrid(double v) { double g = 16.0; return std::floor(v / g + 0.5) * g; }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit498 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline bool pointInRect(double px, double py, double rx, double ry, double rw, double rh) { return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh; }
} // namespace

namespace afrilang::runtime::game2dkit499 {
inline bool aabbHit(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) { return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by); }
inline double dist2(double x0, double y0, double x1, double y1) { double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy; }
} // namespace

namespace afrilang::runtime::game2dkit500 {
inline double approach(double cur, double target, double maxDelta) { double d = target - cur; if (d > maxDelta) return cur + maxDelta; if (d < -maxDelta) return cur - maxDelta; return target; }
inline double follow(double cam, double target, double dt) { double t = dt * 0.082000; if (t > 1.0) t = 1.0; return cam + (target - cam) * t; }
} // namespace

namespace afrilang::runtime::game3dkit001 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit002 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit003 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit004 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000005000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit005 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.040000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit006 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit007 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit008 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit009 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit010 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000004000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit011 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.064000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit012 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit013 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit014 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit015 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit016 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000003000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit017 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.088000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit018 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit019 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit020 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit021 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit022 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000002000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit023 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.112000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit024 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit025 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit026 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit027 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit028 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000001000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit029 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.136000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit030 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit031 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit032 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit033 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit034 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000007000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit035 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.036000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit036 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit037 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit038 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit039 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit040 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000006000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit041 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.060000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit042 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit043 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit044 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit045 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit046 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000005000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit047 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.084000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit048 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit049 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit050 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit051 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit052 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000004000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit053 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.108000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit054 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit055 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit056 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit057 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit058 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000003000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit059 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.132000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit060 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit061 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit062 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit063 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit064 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000002000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit065 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.032000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit066 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit067 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit068 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit069 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit070 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000001000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit071 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.056000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit072 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit073 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit074 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit075 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit076 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000007000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit077 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.080000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit078 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit079 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit080 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit081 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit082 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000006000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit083 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.104000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit084 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit085 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit086 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit087 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit088 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000005000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit089 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.128000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit090 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit091 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit092 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit093 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit094 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000004000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit095 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.028000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit096 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit097 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit098 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit099 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit100 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000003000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit101 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.052000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit102 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit103 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit104 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit105 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit106 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000002000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit107 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.076000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit108 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit109 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit110 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit111 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit112 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000001000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit113 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.100000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit114 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit115 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit116 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit117 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit118 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000007000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit119 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.124000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit120 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit121 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit122 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit123 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit124 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000006000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit125 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.024000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit126 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit127 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit128 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit129 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit130 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000005000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit131 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.048000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit132 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit133 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit134 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit135 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit136 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000004000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit137 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.072000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit138 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit139 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit140 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit141 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit142 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000003000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit143 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.096000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit144 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit145 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit146 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit147 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit148 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000002000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit149 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.120000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit150 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit151 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit152 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit153 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit154 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000001000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit155 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.020000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit156 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit157 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit158 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit159 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit160 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000007000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit161 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.044000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit162 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit163 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit164 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit165 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit166 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000006000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit167 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.068000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit168 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit169 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit170 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit171 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit172 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000005000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit173 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.092000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit174 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit175 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit176 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit177 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit178 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000004000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit179 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.116000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit180 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit181 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit182 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit183 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit184 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000003000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit185 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.140000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit186 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit187 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit188 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit189 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit190 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000002000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit191 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.040000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit192 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit193 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit194 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit195 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit196 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000001000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit197 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.064000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit198 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit199 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit200 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit201 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit202 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000007000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit203 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.088000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit204 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit205 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit206 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit207 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit208 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000006000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit209 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.112000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit210 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit211 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit212 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit213 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit214 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000005000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit215 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.136000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit216 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit217 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit218 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit219 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit220 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000004000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit221 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.036000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit222 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit223 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit224 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit225 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit226 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000003000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit227 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.060000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit228 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit229 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit230 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit231 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit232 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000002000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit233 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.084000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit234 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit235 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit236 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit237 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit238 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000001000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit239 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.108000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit240 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit241 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit242 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit243 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit244 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000007000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit245 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.132000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit246 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit247 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit248 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit249 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit250 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000006000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit251 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.032000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit252 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit253 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit254 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit255 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit256 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000005000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit257 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.056000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit258 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit259 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit260 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit261 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit262 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000004000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit263 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.080000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit264 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit265 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit266 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit267 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit268 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000003000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit269 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.104000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit270 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit271 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit272 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit273 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit274 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000002000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit275 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.128000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit276 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit277 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit278 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit279 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit280 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000001000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit281 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.028000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit282 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit283 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit284 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit285 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit286 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000007000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit287 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.052000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit288 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit289 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit290 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit291 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit292 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000006000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit293 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.076000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit294 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit295 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit296 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit297 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit298 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000005000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit299 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.100000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit300 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit301 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit302 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit303 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit304 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000004000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit305 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.124000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit306 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit307 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit308 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit309 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit310 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000003000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit311 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.024000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit312 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit313 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit314 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit315 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit316 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000002000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit317 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.048000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit318 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit319 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit320 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit321 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit322 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000001000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit323 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.072000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit324 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit325 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit326 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit327 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit328 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000007000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit329 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.096000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit330 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit331 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit332 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit333 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit334 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000006000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit335 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.120000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit336 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit337 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit338 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit339 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit340 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000005000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit341 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.020000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit342 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit343 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit344 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit345 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit346 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000004000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit347 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.044000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit348 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit349 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit350 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit351 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit352 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000003000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit353 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.068000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit354 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit355 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit356 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit357 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit358 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000002000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit359 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.092000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit360 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit361 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit362 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit363 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit364 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000001000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit365 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.116000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit366 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit367 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit368 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit369 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit370 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000007000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit371 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.140000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit372 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit373 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit374 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit375 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit376 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000006000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit377 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.040000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit378 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit379 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit380 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit381 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit382 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000005000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit383 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.064000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit384 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit385 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit386 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit387 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit388 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000004000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit389 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.088000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit390 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit391 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit392 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit393 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit394 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000003000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit395 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.112000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit396 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit397 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit398 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit399 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit400 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000002000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit401 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.136000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit402 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit403 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit404 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit405 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit406 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000001000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit407 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.036000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit408 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit409 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit410 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit411 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit412 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000007000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit413 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.060000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit414 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit415 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit416 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit417 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit418 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000006000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit419 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.084000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit420 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit421 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit422 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit423 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit424 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000005000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit425 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.108000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit426 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit427 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit428 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit429 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit430 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000004000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit431 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.132000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit432 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit433 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit434 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit435 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit436 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000003000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit437 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.032000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit438 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit439 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit440 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit441 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit442 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000002000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit443 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.056000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit444 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit445 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit446 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit447 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit448 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000001000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit449 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.080000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit450 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit451 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit452 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit453 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit454 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000007000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit455 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.104000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit456 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit457 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit458 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit459 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit460 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000006000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit461 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.128000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit462 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit463 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit464 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit465 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit466 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000005000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit467 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.028000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit468 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit469 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit470 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000002000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit471 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit472 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000004000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit473 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.052000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit474 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit475 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit476 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000001000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit477 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit478 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000003000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit479 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.076000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit480 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit481 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit482 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000007000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit483 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit484 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000002000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit485 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.100000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit486 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit487 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit488 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000006000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit489 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit490 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000001000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit491 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.124000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit492 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit493 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit494 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000005000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::game3dkit495 {
inline double yawFromDir(double dx, double dz) { return std::atan2(dx, -dz) * 180.0 / 3.141592653589793; }
inline double pitchFromDir(double dx, double dy, double dz) { return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::game3dkit496 {
inline double rayPlaneHitT(double ox, double oy, double oz, double dx, double dy, double dz, double py) { if (std::fabs(dy) < 0.000007000) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit497 {
inline double smooth(double cur, double target, double dt) { double t = dt * 0.024000; if (t > 1.0) t = 1.0; return cur + (target - cur) * t; }
inline double lerp3x(double ax, double bx, double t) { return ax + (bx - ax) * t; }
} // namespace

namespace afrilang::runtime::game3dkit498 {
inline double dot3(double ax, double ay, double az, double bx, double by, double bz) { return ax * bx + ay * by + az * bz; }
inline double crossX(double ax, double ay, double az, double bx, double by, double bz) { return ay * bz - az * by; }
inline double crossY(double ax, double ay, double az, double bx, double by, double bz) { return az * bx - ax * bz; }
} // namespace

namespace afrilang::runtime::game3dkit499 {
inline double len3(double x, double y, double z) { return std::sqrt(x * x + y * y + z * z); }
inline double normalize3x(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return x / l; }
inline double normalize3y(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000003000) return 0; return y / l; }
} // namespace

namespace afrilang::runtime::game3dkit500 {
inline double normalize3z(double x, double y, double z) { double l = std::sqrt(x*x + y*y + z*z); if (l < 0.000004000) return 0; return z / l; }
inline double dist3(double x0, double y0, double z0, double x1, double y1, double z1) { double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; return std::sqrt(dx * dx + dy * dy + dz * dz); }
} // namespace

namespace afrilang::runtime::giskit001 {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad=[](double d){return d*3.141592653589793/180.0;}; double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline double azimuthDiff(double a, double b) { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }
} // namespace

namespace afrilang::runtime::giskit002 {
inline double bboxWidth(double minX, double minY, double maxX, double maxY) { return maxX - minX; }
inline double bboxArea(double minX, double minY, double maxX, double maxY) { return std::fabs(maxX - minX) * std::fabs(maxY - minY); }
} // namespace

namespace afrilang::runtime::giskit003 {
inline double bboxCenterX(double minX, double minY, double maxX, double maxY) { return (minX + maxX) / 2.0; }
inline double bboxCenterY(double minX, double minY, double maxX, double maxY) { return (minY + maxY) / 2.0; }
} // namespace

namespace afrilang::runtime::giskit004 {
inline bool pointInBbox(double x, double y, double minX, double minY, double maxX, double maxY) { return x >= minX && x <= maxX && y >= minY && y <= maxY; }
inline double degToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace

namespace afrilang::runtime::giskit005 {
inline double mToKm(double m) { return m / 1000.0; }
inline double kmToM(double km) { return km * 1000.0; }
} // namespace

namespace afrilang::runtime::giskit006 {
inline double normalizeLon(double lon) { return std::fmod(std::fmod(lon + 180.0, 360.0) + 360.0, 360.0) - 180.0; }
inline double clampLat(double lat) { return lat < -90.0 ? -90.0 : (lat > 90.0 ? 90.0 : lat); }
} // namespace

namespace afrilang::runtime::giskit007 {
inline double pixelIndex(double row, double col, double width) { return row * width + col; }
inline double geoToPixelX(double x, double originX, double resX) { return resX == 0 ? 0 : (x - originX) / resX; }
} // namespace

namespace afrilang::runtime::giskit008 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5300+g*0.6460+b*0.2)/(1.3760); }
} // namespace

namespace afrilang::runtime::giskit009 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5400+g*0.6580+b*0.2)/(1.3980); }
} // namespace

namespace afrilang::runtime::giskit010 {
inline double gsdFromAltitude(double altM, double focalMm, double pixelUm) { return focalMm == 0 ? 0 : (altM * pixelUm) / (focalMm * 1000.0); }
inline double groundWidth(double pixels, double gsd) { return pixels * gsd; }
} // namespace

namespace afrilang::runtime::giskit011 {
inline double tileRow(double lat, double z) { { double n = std::pow(2.0, z); double latR = lat * 3.141592653589793 / 180.0; return std::floor((1.0 - std::log(std::tan(latR) + 1.0 / std::cos(latR)) / 3.141592653589793) / 2.0 * n); } }
inline double tileCol(double lon, double z) { { double n = std::pow(2.0, z); return std::floor((lon + 180.0) / 360.0 * n); } }
} // namespace

namespace afrilang::runtime::giskit012 {
inline double utmZone(double lon) { return std::floor((lon + 180.0) / 6.0) + 1.0; }
inline bool isNorthernHemisphere(double lat) { return lat >= 0.0; }
} // namespace

namespace afrilang::runtime::giskit013 {
inline double planarDist(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return std::sqrt(dx*dx+dy*dy); }
inline double planarDist2(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy; }
} // namespace

namespace afrilang::runtime::giskit014 {
inline double percentSlope(double rise, double run) { return run == 0 ? 0 : (rise / run) * 100.0; }
inline double degreeSlope(double rise, double run) { return run == 0 ? 0 : std::atan(rise / run) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::giskit015 {
inline double tileOriginX(double tileCol, double tileSize) { return tileCol * tileSize * 4.250000; }
inline double tileOriginY(double tileRow, double tileSize) { return tileRow * tileSize * 4.250000; }
} // namespace

namespace afrilang::runtime::giskit016 {
inline double haversineKm(double lat1, double lon1, double lat2, double lon2) { { double R=6371.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
inline double haversineM(double lat1, double lon1, double lat2, double lon2) { { double R=6371000.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
} // namespace

namespace afrilang::runtime::giskit017 {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad=[](double d){return d*3.141592653589793/180.0;}; double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline double azimuthDiff(double a, double b) { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }
} // namespace

namespace afrilang::runtime::giskit018 {
inline double bboxWidth(double minX, double minY, double maxX, double maxY) { return maxX - minX; }
inline double bboxArea(double minX, double minY, double maxX, double maxY) { return std::fabs(maxX - minX) * std::fabs(maxY - minY); }
} // namespace

namespace afrilang::runtime::giskit019 {
inline double bboxCenterX(double minX, double minY, double maxX, double maxY) { return (minX + maxX) / 2.0; }
inline double bboxCenterY(double minX, double minY, double maxX, double maxY) { return (minY + maxY) / 2.0; }
} // namespace

namespace afrilang::runtime::giskit020 {
inline bool pointInBbox(double x, double y, double minX, double minY, double maxX, double maxY) { return x >= minX && x <= maxX && y >= minY && y <= maxY; }
inline double degToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace

namespace afrilang::runtime::giskit021 {
inline double mToKm(double m) { return m / 1000.0; }
inline double kmToM(double km) { return km * 1000.0; }
} // namespace

namespace afrilang::runtime::giskit022 {
inline double normalizeLon(double lon) { return std::fmod(std::fmod(lon + 180.0, 360.0) + 360.0, 360.0) - 180.0; }
inline double clampLat(double lat) { return lat < -90.0 ? -90.0 : (lat > 90.0 ? 90.0 : lat); }
} // namespace

namespace afrilang::runtime::giskit023 {
inline double pixelIndex(double row, double col, double width) { return row * width + col; }
inline double geoToPixelX(double x, double originX, double resX) { return resX == 0 ? 0 : (x - originX) / resX; }
} // namespace

namespace afrilang::runtime::giskit024 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5200+g*0.6820+b*0.2)/(1.4020); }
} // namespace

namespace afrilang::runtime::giskit025 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5300+g*0.6940+b*0.2)/(1.4240); }
} // namespace

namespace afrilang::runtime::giskit026 {
inline double gsdFromAltitude(double altM, double focalMm, double pixelUm) { return focalMm == 0 ? 0 : (altM * pixelUm) / (focalMm * 1000.0); }
inline double groundWidth(double pixels, double gsd) { return pixels * gsd; }
} // namespace

namespace afrilang::runtime::giskit027 {
inline double tileRow(double lat, double z) { { double n = std::pow(2.0, z); double latR = lat * 3.141592653589793 / 180.0; return std::floor((1.0 - std::log(std::tan(latR) + 1.0 / std::cos(latR)) / 3.141592653589793) / 2.0 * n); } }
inline double tileCol(double lon, double z) { { double n = std::pow(2.0, z); return std::floor((lon + 180.0) / 360.0 * n); } }
} // namespace

namespace afrilang::runtime::giskit028 {
inline double utmZone(double lon) { return std::floor((lon + 180.0) / 6.0) + 1.0; }
inline bool isNorthernHemisphere(double lat) { return lat >= 0.0; }
} // namespace

namespace afrilang::runtime::giskit029 {
inline double planarDist(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return std::sqrt(dx*dx+dy*dy); }
inline double planarDist2(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy; }
} // namespace

namespace afrilang::runtime::giskit030 {
inline double percentSlope(double rise, double run) { return run == 0 ? 0 : (rise / run) * 100.0; }
inline double degreeSlope(double rise, double run) { return run == 0 ? 0 : std::atan(rise / run) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::giskit031 {
inline double tileOriginX(double tileCol, double tileSize) { return tileCol * tileSize * 1.000000; }
inline double tileOriginY(double tileRow, double tileSize) { return tileRow * tileSize * 1.000000; }
} // namespace

namespace afrilang::runtime::giskit032 {
inline double haversineKm(double lat1, double lon1, double lat2, double lon2) { { double R=6371.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
inline double haversineM(double lat1, double lon1, double lat2, double lon2) { { double R=6371000.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
} // namespace

namespace afrilang::runtime::giskit033 {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad=[](double d){return d*3.141592653589793/180.0;}; double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline double azimuthDiff(double a, double b) { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }
} // namespace

namespace afrilang::runtime::giskit034 {
inline double bboxWidth(double minX, double minY, double maxX, double maxY) { return maxX - minX; }
inline double bboxArea(double minX, double minY, double maxX, double maxY) { return std::fabs(maxX - minX) * std::fabs(maxY - minY); }
} // namespace

namespace afrilang::runtime::giskit035 {
inline double bboxCenterX(double minX, double minY, double maxX, double maxY) { return (minX + maxX) / 2.0; }
inline double bboxCenterY(double minX, double minY, double maxX, double maxY) { return (minY + maxY) / 2.0; }
} // namespace

namespace afrilang::runtime::giskit036 {
inline bool pointInBbox(double x, double y, double minX, double minY, double maxX, double maxY) { return x >= minX && x <= maxX && y >= minY && y <= maxY; }
inline double degToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace

namespace afrilang::runtime::giskit037 {
inline double mToKm(double m) { return m / 1000.0; }
inline double kmToM(double km) { return km * 1000.0; }
} // namespace

namespace afrilang::runtime::giskit038 {
inline double normalizeLon(double lon) { return std::fmod(std::fmod(lon + 180.0, 360.0) + 360.0, 360.0) - 180.0; }
inline double clampLat(double lat) { return lat < -90.0 ? -90.0 : (lat > 90.0 ? 90.0 : lat); }
} // namespace

namespace afrilang::runtime::giskit039 {
inline double pixelIndex(double row, double col, double width) { return row * width + col; }
inline double geoToPixelX(double x, double originX, double resX) { return resX == 0 ? 0 : (x - originX) / resX; }
} // namespace

namespace afrilang::runtime::giskit040 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5100+g*0.5620+b*0.2)/(1.2720); }
} // namespace

namespace afrilang::runtime::giskit041 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5200+g*0.5740+b*0.2)/(1.2940); }
} // namespace

namespace afrilang::runtime::giskit042 {
inline double gsdFromAltitude(double altM, double focalMm, double pixelUm) { return focalMm == 0 ? 0 : (altM * pixelUm) / (focalMm * 1000.0); }
inline double groundWidth(double pixels, double gsd) { return pixels * gsd; }
} // namespace

namespace afrilang::runtime::giskit043 {
inline double tileRow(double lat, double z) { { double n = std::pow(2.0, z); double latR = lat * 3.141592653589793 / 180.0; return std::floor((1.0 - std::log(std::tan(latR) + 1.0 / std::cos(latR)) / 3.141592653589793) / 2.0 * n); } }
inline double tileCol(double lon, double z) { { double n = std::pow(2.0, z); return std::floor((lon + 180.0) / 360.0 * n); } }
} // namespace

namespace afrilang::runtime::giskit044 {
inline double utmZone(double lon) { return std::floor((lon + 180.0) / 6.0) + 1.0; }
inline bool isNorthernHemisphere(double lat) { return lat >= 0.0; }
} // namespace

namespace afrilang::runtime::giskit045 {
inline double planarDist(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return std::sqrt(dx*dx+dy*dy); }
inline double planarDist2(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy; }
} // namespace

namespace afrilang::runtime::giskit046 {
inline double percentSlope(double rise, double run) { return run == 0 ? 0 : (rise / run) * 100.0; }
inline double degreeSlope(double rise, double run) { return run == 0 ? 0 : std::atan(rise / run) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::giskit047 {
inline double tileOriginX(double tileCol, double tileSize) { return tileCol * tileSize * 5.000000; }
inline double tileOriginY(double tileRow, double tileSize) { return tileRow * tileSize * 5.000000; }
} // namespace

namespace afrilang::runtime::giskit048 {
inline double haversineKm(double lat1, double lon1, double lat2, double lon2) { { double R=6371.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
inline double haversineM(double lat1, double lon1, double lat2, double lon2) { { double R=6371000.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
} // namespace

namespace afrilang::runtime::giskit049 {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad=[](double d){return d*3.141592653589793/180.0;}; double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline double azimuthDiff(double a, double b) { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }
} // namespace

namespace afrilang::runtime::giskit050 {
inline double bboxWidth(double minX, double minY, double maxX, double maxY) { return maxX - minX; }
inline double bboxArea(double minX, double minY, double maxX, double maxY) { return std::fabs(maxX - minX) * std::fabs(maxY - minY); }
} // namespace

namespace afrilang::runtime::giskit051 {
inline double bboxCenterX(double minX, double minY, double maxX, double maxY) { return (minX + maxX) / 2.0; }
inline double bboxCenterY(double minX, double minY, double maxX, double maxY) { return (minY + maxY) / 2.0; }
} // namespace

namespace afrilang::runtime::giskit052 {
inline bool pointInBbox(double x, double y, double minX, double minY, double maxX, double maxY) { return x >= minX && x <= maxX && y >= minY && y <= maxY; }
inline double degToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace

namespace afrilang::runtime::giskit053 {
inline double mToKm(double m) { return m / 1000.0; }
inline double kmToM(double km) { return km * 1000.0; }
} // namespace

namespace afrilang::runtime::giskit054 {
inline double normalizeLon(double lon) { return std::fmod(std::fmod(lon + 180.0, 360.0) + 360.0, 360.0) - 180.0; }
inline double clampLat(double lat) { return lat < -90.0 ? -90.0 : (lat > 90.0 ? 90.0 : lat); }
} // namespace

namespace afrilang::runtime::giskit055 {
inline double pixelIndex(double row, double col, double width) { return row * width + col; }
inline double geoToPixelX(double x, double originX, double resX) { return resX == 0 ? 0 : (x - originX) / resX; }
} // namespace

namespace afrilang::runtime::giskit056 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5000+g*0.5980+b*0.2)/(1.2980); }
} // namespace

namespace afrilang::runtime::giskit057 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5100+g*0.6100+b*0.2)/(1.3200); }
} // namespace

namespace afrilang::runtime::giskit058 {
inline double gsdFromAltitude(double altM, double focalMm, double pixelUm) { return focalMm == 0 ? 0 : (altM * pixelUm) / (focalMm * 1000.0); }
inline double groundWidth(double pixels, double gsd) { return pixels * gsd; }
} // namespace

namespace afrilang::runtime::giskit059 {
inline double tileRow(double lat, double z) { { double n = std::pow(2.0, z); double latR = lat * 3.141592653589793 / 180.0; return std::floor((1.0 - std::log(std::tan(latR) + 1.0 / std::cos(latR)) / 3.141592653589793) / 2.0 * n); } }
inline double tileCol(double lon, double z) { { double n = std::pow(2.0, z); return std::floor((lon + 180.0) / 360.0 * n); } }
} // namespace

namespace afrilang::runtime::giskit060 {
inline double utmZone(double lon) { return std::floor((lon + 180.0) / 6.0) + 1.0; }
inline bool isNorthernHemisphere(double lat) { return lat >= 0.0; }
} // namespace

namespace afrilang::runtime::giskit061 {
inline double planarDist(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return std::sqrt(dx*dx+dy*dy); }
inline double planarDist2(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy; }
} // namespace

namespace afrilang::runtime::giskit062 {
inline double percentSlope(double rise, double run) { return run == 0 ? 0 : (rise / run) * 100.0; }
inline double degreeSlope(double rise, double run) { return run == 0 ? 0 : std::atan(rise / run) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::giskit063 {
inline double tileOriginX(double tileCol, double tileSize) { return tileCol * tileSize * 1.750000; }
inline double tileOriginY(double tileRow, double tileSize) { return tileRow * tileSize * 1.750000; }
} // namespace

namespace afrilang::runtime::giskit064 {
inline double haversineKm(double lat1, double lon1, double lat2, double lon2) { { double R=6371.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
inline double haversineM(double lat1, double lon1, double lat2, double lon2) { { double R=6371000.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
} // namespace

namespace afrilang::runtime::giskit065 {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad=[](double d){return d*3.141592653589793/180.0;}; double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline double azimuthDiff(double a, double b) { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }
} // namespace

namespace afrilang::runtime::giskit066 {
inline double bboxWidth(double minX, double minY, double maxX, double maxY) { return maxX - minX; }
inline double bboxArea(double minX, double minY, double maxX, double maxY) { return std::fabs(maxX - minX) * std::fabs(maxY - minY); }
} // namespace

namespace afrilang::runtime::giskit067 {
inline double bboxCenterX(double minX, double minY, double maxX, double maxY) { return (minX + maxX) / 2.0; }
inline double bboxCenterY(double minX, double minY, double maxX, double maxY) { return (minY + maxY) / 2.0; }
} // namespace

namespace afrilang::runtime::giskit068 {
inline bool pointInBbox(double x, double y, double minX, double minY, double maxX, double maxY) { return x >= minX && x <= maxX && y >= minY && y <= maxY; }
inline double degToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace

namespace afrilang::runtime::giskit069 {
inline double mToKm(double m) { return m / 1000.0; }
inline double kmToM(double km) { return km * 1000.0; }
} // namespace

namespace afrilang::runtime::giskit070 {
inline double normalizeLon(double lon) { return std::fmod(std::fmod(lon + 180.0, 360.0) + 360.0, 360.0) - 180.0; }
inline double clampLat(double lat) { return lat < -90.0 ? -90.0 : (lat > 90.0 ? 90.0 : lat); }
} // namespace

namespace afrilang::runtime::giskit071 {
inline double pixelIndex(double row, double col, double width) { return row * width + col; }
inline double geoToPixelX(double x, double originX, double resX) { return resX == 0 ? 0 : (x - originX) / resX; }
} // namespace

namespace afrilang::runtime::giskit072 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.4900+g*0.6340+b*0.2)/(1.3240); }
} // namespace

namespace afrilang::runtime::giskit073 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5000+g*0.6460+b*0.2)/(1.3460); }
} // namespace

namespace afrilang::runtime::giskit074 {
inline double gsdFromAltitude(double altM, double focalMm, double pixelUm) { return focalMm == 0 ? 0 : (altM * pixelUm) / (focalMm * 1000.0); }
inline double groundWidth(double pixels, double gsd) { return pixels * gsd; }
} // namespace

namespace afrilang::runtime::giskit075 {
inline double tileRow(double lat, double z) { { double n = std::pow(2.0, z); double latR = lat * 3.141592653589793 / 180.0; return std::floor((1.0 - std::log(std::tan(latR) + 1.0 / std::cos(latR)) / 3.141592653589793) / 2.0 * n); } }
inline double tileCol(double lon, double z) { { double n = std::pow(2.0, z); return std::floor((lon + 180.0) / 360.0 * n); } }
} // namespace

namespace afrilang::runtime::giskit076 {
inline double utmZone(double lon) { return std::floor((lon + 180.0) / 6.0) + 1.0; }
inline bool isNorthernHemisphere(double lat) { return lat >= 0.0; }
} // namespace

namespace afrilang::runtime::giskit077 {
inline double planarDist(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return std::sqrt(dx*dx+dy*dy); }
inline double planarDist2(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy; }
} // namespace

namespace afrilang::runtime::giskit078 {
inline double percentSlope(double rise, double run) { return run == 0 ? 0 : (rise / run) * 100.0; }
inline double degreeSlope(double rise, double run) { return run == 0 ? 0 : std::atan(rise / run) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::giskit079 {
inline double tileOriginX(double tileCol, double tileSize) { return tileCol * tileSize * 5.750000; }
inline double tileOriginY(double tileRow, double tileSize) { return tileRow * tileSize * 5.750000; }
} // namespace

namespace afrilang::runtime::giskit080 {
inline double haversineKm(double lat1, double lon1, double lat2, double lon2) { { double R=6371.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
inline double haversineM(double lat1, double lon1, double lat2, double lon2) { { double R=6371000.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
} // namespace

namespace afrilang::runtime::giskit081 {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad=[](double d){return d*3.141592653589793/180.0;}; double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline double azimuthDiff(double a, double b) { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }
} // namespace

namespace afrilang::runtime::giskit082 {
inline double bboxWidth(double minX, double minY, double maxX, double maxY) { return maxX - minX; }
inline double bboxArea(double minX, double minY, double maxX, double maxY) { return std::fabs(maxX - minX) * std::fabs(maxY - minY); }
} // namespace

namespace afrilang::runtime::giskit083 {
inline double bboxCenterX(double minX, double minY, double maxX, double maxY) { return (minX + maxX) / 2.0; }
inline double bboxCenterY(double minX, double minY, double maxX, double maxY) { return (minY + maxY) / 2.0; }
} // namespace

namespace afrilang::runtime::giskit084 {
inline bool pointInBbox(double x, double y, double minX, double minY, double maxX, double maxY) { return x >= minX && x <= maxX && y >= minY && y <= maxY; }
inline double degToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace

namespace afrilang::runtime::giskit085 {
inline double mToKm(double m) { return m / 1000.0; }
inline double kmToM(double km) { return km * 1000.0; }
} // namespace

namespace afrilang::runtime::giskit086 {
inline double normalizeLon(double lon) { return std::fmod(std::fmod(lon + 180.0, 360.0) + 360.0, 360.0) - 180.0; }
inline double clampLat(double lat) { return lat < -90.0 ? -90.0 : (lat > 90.0 ? 90.0 : lat); }
} // namespace

namespace afrilang::runtime::giskit087 {
inline double pixelIndex(double row, double col, double width) { return row * width + col; }
inline double geoToPixelX(double x, double originX, double resX) { return resX == 0 ? 0 : (x - originX) / resX; }
} // namespace

namespace afrilang::runtime::giskit088 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.4800+g*0.6700+b*0.2)/(1.3500); }
} // namespace

namespace afrilang::runtime::giskit089 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.4900+g*0.6820+b*0.2)/(1.3720); }
} // namespace

namespace afrilang::runtime::giskit090 {
inline double gsdFromAltitude(double altM, double focalMm, double pixelUm) { return focalMm == 0 ? 0 : (altM * pixelUm) / (focalMm * 1000.0); }
inline double groundWidth(double pixels, double gsd) { return pixels * gsd; }
} // namespace

namespace afrilang::runtime::giskit091 {
inline double tileRow(double lat, double z) { { double n = std::pow(2.0, z); double latR = lat * 3.141592653589793 / 180.0; return std::floor((1.0 - std::log(std::tan(latR) + 1.0 / std::cos(latR)) / 3.141592653589793) / 2.0 * n); } }
inline double tileCol(double lon, double z) { { double n = std::pow(2.0, z); return std::floor((lon + 180.0) / 360.0 * n); } }
} // namespace

namespace afrilang::runtime::giskit092 {
inline double utmZone(double lon) { return std::floor((lon + 180.0) / 6.0) + 1.0; }
inline bool isNorthernHemisphere(double lat) { return lat >= 0.0; }
} // namespace

namespace afrilang::runtime::giskit093 {
inline double planarDist(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return std::sqrt(dx*dx+dy*dy); }
inline double planarDist2(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy; }
} // namespace

namespace afrilang::runtime::giskit094 {
inline double percentSlope(double rise, double run) { return run == 0 ? 0 : (rise / run) * 100.0; }
inline double degreeSlope(double rise, double run) { return run == 0 ? 0 : std::atan(rise / run) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::giskit095 {
inline double tileOriginX(double tileCol, double tileSize) { return tileCol * tileSize * 2.500000; }
inline double tileOriginY(double tileRow, double tileSize) { return tileRow * tileSize * 2.500000; }
} // namespace

namespace afrilang::runtime::giskit096 {
inline double haversineKm(double lat1, double lon1, double lat2, double lon2) { { double R=6371.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
inline double haversineM(double lat1, double lon1, double lat2, double lon2) { { double R=6371000.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
} // namespace

namespace afrilang::runtime::giskit097 {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad=[](double d){return d*3.141592653589793/180.0;}; double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline double azimuthDiff(double a, double b) { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }
} // namespace

namespace afrilang::runtime::giskit098 {
inline double bboxWidth(double minX, double minY, double maxX, double maxY) { return maxX - minX; }
inline double bboxArea(double minX, double minY, double maxX, double maxY) { return std::fabs(maxX - minX) * std::fabs(maxY - minY); }
} // namespace

namespace afrilang::runtime::giskit099 {
inline double bboxCenterX(double minX, double minY, double maxX, double maxY) { return (minX + maxX) / 2.0; }
inline double bboxCenterY(double minX, double minY, double maxX, double maxY) { return (minY + maxY) / 2.0; }
} // namespace

namespace afrilang::runtime::giskit100 {
inline bool pointInBbox(double x, double y, double minX, double minY, double maxX, double maxY) { return x >= minX && x <= maxX && y >= minY && y <= maxY; }
inline double degToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace

namespace afrilang::runtime::giskit101 {
inline double mToKm(double m) { return m / 1000.0; }
inline double kmToM(double km) { return km * 1000.0; }
} // namespace

namespace afrilang::runtime::giskit102 {
inline double normalizeLon(double lon) { return std::fmod(std::fmod(lon + 180.0, 360.0) + 360.0, 360.0) - 180.0; }
inline double clampLat(double lat) { return lat < -90.0 ? -90.0 : (lat > 90.0 ? 90.0 : lat); }
} // namespace

namespace afrilang::runtime::giskit103 {
inline double pixelIndex(double row, double col, double width) { return row * width + col; }
inline double geoToPixelX(double x, double originX, double resX) { return resX == 0 ? 0 : (x - originX) / resX; }
} // namespace

namespace afrilang::runtime::giskit104 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.4700+g*0.5500+b*0.2)/(1.2200); }
} // namespace

namespace afrilang::runtime::giskit105 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.4800+g*0.5620+b*0.2)/(1.2420); }
} // namespace

namespace afrilang::runtime::giskit106 {
inline double gsdFromAltitude(double altM, double focalMm, double pixelUm) { return focalMm == 0 ? 0 : (altM * pixelUm) / (focalMm * 1000.0); }
inline double groundWidth(double pixels, double gsd) { return pixels * gsd; }
} // namespace

namespace afrilang::runtime::giskit107 {
inline double tileRow(double lat, double z) { { double n = std::pow(2.0, z); double latR = lat * 3.141592653589793 / 180.0; return std::floor((1.0 - std::log(std::tan(latR) + 1.0 / std::cos(latR)) / 3.141592653589793) / 2.0 * n); } }
inline double tileCol(double lon, double z) { { double n = std::pow(2.0, z); return std::floor((lon + 180.0) / 360.0 * n); } }
} // namespace

namespace afrilang::runtime::giskit108 {
inline double utmZone(double lon) { return std::floor((lon + 180.0) / 6.0) + 1.0; }
inline bool isNorthernHemisphere(double lat) { return lat >= 0.0; }
} // namespace

namespace afrilang::runtime::giskit109 {
inline double planarDist(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return std::sqrt(dx*dx+dy*dy); }
inline double planarDist2(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy; }
} // namespace

namespace afrilang::runtime::giskit110 {
inline double percentSlope(double rise, double run) { return run == 0 ? 0 : (rise / run) * 100.0; }
inline double degreeSlope(double rise, double run) { return run == 0 ? 0 : std::atan(rise / run) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::giskit111 {
inline double tileOriginX(double tileCol, double tileSize) { return tileCol * tileSize * 6.500000; }
inline double tileOriginY(double tileRow, double tileSize) { return tileRow * tileSize * 6.500000; }
} // namespace

namespace afrilang::runtime::giskit112 {
inline double haversineKm(double lat1, double lon1, double lat2, double lon2) { { double R=6371.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
inline double haversineM(double lat1, double lon1, double lat2, double lon2) { { double R=6371000.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
} // namespace

namespace afrilang::runtime::giskit113 {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad=[](double d){return d*3.141592653589793/180.0;}; double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline double azimuthDiff(double a, double b) { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }
} // namespace

namespace afrilang::runtime::giskit114 {
inline double bboxWidth(double minX, double minY, double maxX, double maxY) { return maxX - minX; }
inline double bboxArea(double minX, double minY, double maxX, double maxY) { return std::fabs(maxX - minX) * std::fabs(maxY - minY); }
} // namespace

namespace afrilang::runtime::giskit115 {
inline double bboxCenterX(double minX, double minY, double maxX, double maxY) { return (minX + maxX) / 2.0; }
inline double bboxCenterY(double minX, double minY, double maxX, double maxY) { return (minY + maxY) / 2.0; }
} // namespace

namespace afrilang::runtime::giskit116 {
inline bool pointInBbox(double x, double y, double minX, double minY, double maxX, double maxY) { return x >= minX && x <= maxX && y >= minY && y <= maxY; }
inline double degToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace

namespace afrilang::runtime::giskit117 {
inline double mToKm(double m) { return m / 1000.0; }
inline double kmToM(double km) { return km * 1000.0; }
} // namespace

namespace afrilang::runtime::giskit118 {
inline double normalizeLon(double lon) { return std::fmod(std::fmod(lon + 180.0, 360.0) + 360.0, 360.0) - 180.0; }
inline double clampLat(double lat) { return lat < -90.0 ? -90.0 : (lat > 90.0 ? 90.0 : lat); }
} // namespace

namespace afrilang::runtime::giskit119 {
inline double pixelIndex(double row, double col, double width) { return row * width + col; }
inline double geoToPixelX(double x, double originX, double resX) { return resX == 0 ? 0 : (x - originX) / resX; }
} // namespace

namespace afrilang::runtime::giskit120 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.4600+g*0.5860+b*0.2)/(1.2460); }
} // namespace

namespace afrilang::runtime::giskit121 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.4700+g*0.5980+b*0.2)/(1.2680); }
} // namespace

namespace afrilang::runtime::giskit122 {
inline double gsdFromAltitude(double altM, double focalMm, double pixelUm) { return focalMm == 0 ? 0 : (altM * pixelUm) / (focalMm * 1000.0); }
inline double groundWidth(double pixels, double gsd) { return pixels * gsd; }
} // namespace

namespace afrilang::runtime::giskit123 {
inline double tileRow(double lat, double z) { { double n = std::pow(2.0, z); double latR = lat * 3.141592653589793 / 180.0; return std::floor((1.0 - std::log(std::tan(latR) + 1.0 / std::cos(latR)) / 3.141592653589793) / 2.0 * n); } }
inline double tileCol(double lon, double z) { { double n = std::pow(2.0, z); return std::floor((lon + 180.0) / 360.0 * n); } }
} // namespace

namespace afrilang::runtime::giskit124 {
inline double utmZone(double lon) { return std::floor((lon + 180.0) / 6.0) + 1.0; }
inline bool isNorthernHemisphere(double lat) { return lat >= 0.0; }
} // namespace

namespace afrilang::runtime::giskit125 {
inline double planarDist(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return std::sqrt(dx*dx+dy*dy); }
inline double planarDist2(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy; }
} // namespace

namespace afrilang::runtime::giskit126 {
inline double percentSlope(double rise, double run) { return run == 0 ? 0 : (rise / run) * 100.0; }
inline double degreeSlope(double rise, double run) { return run == 0 ? 0 : std::atan(rise / run) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::giskit127 {
inline double tileOriginX(double tileCol, double tileSize) { return tileCol * tileSize * 3.250000; }
inline double tileOriginY(double tileRow, double tileSize) { return tileRow * tileSize * 3.250000; }
} // namespace

namespace afrilang::runtime::giskit128 {
inline double haversineKm(double lat1, double lon1, double lat2, double lon2) { { double R=6371.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
inline double haversineM(double lat1, double lon1, double lat2, double lon2) { { double R=6371000.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
} // namespace

namespace afrilang::runtime::giskit129 {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad=[](double d){return d*3.141592653589793/180.0;}; double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline double azimuthDiff(double a, double b) { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }
} // namespace

namespace afrilang::runtime::giskit130 {
inline double bboxWidth(double minX, double minY, double maxX, double maxY) { return maxX - minX; }
inline double bboxArea(double minX, double minY, double maxX, double maxY) { return std::fabs(maxX - minX) * std::fabs(maxY - minY); }
} // namespace

namespace afrilang::runtime::giskit131 {
inline double bboxCenterX(double minX, double minY, double maxX, double maxY) { return (minX + maxX) / 2.0; }
inline double bboxCenterY(double minX, double minY, double maxX, double maxY) { return (minY + maxY) / 2.0; }
} // namespace

namespace afrilang::runtime::giskit132 {
inline bool pointInBbox(double x, double y, double minX, double minY, double maxX, double maxY) { return x >= minX && x <= maxX && y >= minY && y <= maxY; }
inline double degToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace

namespace afrilang::runtime::giskit133 {
inline double mToKm(double m) { return m / 1000.0; }
inline double kmToM(double km) { return km * 1000.0; }
} // namespace

namespace afrilang::runtime::giskit134 {
inline double normalizeLon(double lon) { return std::fmod(std::fmod(lon + 180.0, 360.0) + 360.0, 360.0) - 180.0; }
inline double clampLat(double lat) { return lat < -90.0 ? -90.0 : (lat > 90.0 ? 90.0 : lat); }
} // namespace

namespace afrilang::runtime::giskit135 {
inline double pixelIndex(double row, double col, double width) { return row * width + col; }
inline double geoToPixelX(double x, double originX, double resX) { return resX == 0 ? 0 : (x - originX) / resX; }
} // namespace

namespace afrilang::runtime::giskit136 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.4500+g*0.6220+b*0.2)/(1.2720); }
} // namespace

namespace afrilang::runtime::giskit137 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.4600+g*0.6340+b*0.2)/(1.2940); }
} // namespace

namespace afrilang::runtime::giskit138 {
inline double gsdFromAltitude(double altM, double focalMm, double pixelUm) { return focalMm == 0 ? 0 : (altM * pixelUm) / (focalMm * 1000.0); }
inline double groundWidth(double pixels, double gsd) { return pixels * gsd; }
} // namespace

namespace afrilang::runtime::giskit139 {
inline double tileRow(double lat, double z) { { double n = std::pow(2.0, z); double latR = lat * 3.141592653589793 / 180.0; return std::floor((1.0 - std::log(std::tan(latR) + 1.0 / std::cos(latR)) / 3.141592653589793) / 2.0 * n); } }
inline double tileCol(double lon, double z) { { double n = std::pow(2.0, z); return std::floor((lon + 180.0) / 360.0 * n); } }
} // namespace

namespace afrilang::runtime::giskit140 {
inline double utmZone(double lon) { return std::floor((lon + 180.0) / 6.0) + 1.0; }
inline bool isNorthernHemisphere(double lat) { return lat >= 0.0; }
} // namespace

namespace afrilang::runtime::giskit141 {
inline double planarDist(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return std::sqrt(dx*dx+dy*dy); }
inline double planarDist2(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy; }
} // namespace

namespace afrilang::runtime::giskit142 {
inline double percentSlope(double rise, double run) { return run == 0 ? 0 : (rise / run) * 100.0; }
inline double degreeSlope(double rise, double run) { return run == 0 ? 0 : std::atan(rise / run) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::giskit143 {
inline double tileOriginX(double tileCol, double tileSize) { return tileCol * tileSize * 7.250000; }
inline double tileOriginY(double tileRow, double tileSize) { return tileRow * tileSize * 7.250000; }
} // namespace

namespace afrilang::runtime::giskit144 {
inline double haversineKm(double lat1, double lon1, double lat2, double lon2) { { double R=6371.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
inline double haversineM(double lat1, double lon1, double lat2, double lon2) { { double R=6371000.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
} // namespace

namespace afrilang::runtime::giskit145 {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad=[](double d){return d*3.141592653589793/180.0;}; double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline double azimuthDiff(double a, double b) { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }
} // namespace

namespace afrilang::runtime::giskit146 {
inline double bboxWidth(double minX, double minY, double maxX, double maxY) { return maxX - minX; }
inline double bboxArea(double minX, double minY, double maxX, double maxY) { return std::fabs(maxX - minX) * std::fabs(maxY - minY); }
} // namespace

namespace afrilang::runtime::giskit147 {
inline double bboxCenterX(double minX, double minY, double maxX, double maxY) { return (minX + maxX) / 2.0; }
inline double bboxCenterY(double minX, double minY, double maxX, double maxY) { return (minY + maxY) / 2.0; }
} // namespace

namespace afrilang::runtime::giskit148 {
inline bool pointInBbox(double x, double y, double minX, double minY, double maxX, double maxY) { return x >= minX && x <= maxX && y >= minY && y <= maxY; }
inline double degToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace

namespace afrilang::runtime::giskit149 {
inline double mToKm(double m) { return m / 1000.0; }
inline double kmToM(double km) { return km * 1000.0; }
} // namespace

namespace afrilang::runtime::giskit150 {
inline double normalizeLon(double lon) { return std::fmod(std::fmod(lon + 180.0, 360.0) + 360.0, 360.0) - 180.0; }
inline double clampLat(double lat) { return lat < -90.0 ? -90.0 : (lat > 90.0 ? 90.0 : lat); }
} // namespace

namespace afrilang::runtime::giskit151 {
inline double pixelIndex(double row, double col, double width) { return row * width + col; }
inline double geoToPixelX(double x, double originX, double resX) { return resX == 0 ? 0 : (x - originX) / resX; }
} // namespace

namespace afrilang::runtime::giskit152 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.6100+g*0.6580+b*0.2)/(1.4680); }
} // namespace

namespace afrilang::runtime::giskit153 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.4500+g*0.6700+b*0.2)/(1.3200); }
} // namespace

namespace afrilang::runtime::giskit154 {
inline double gsdFromAltitude(double altM, double focalMm, double pixelUm) { return focalMm == 0 ? 0 : (altM * pixelUm) / (focalMm * 1000.0); }
inline double groundWidth(double pixels, double gsd) { return pixels * gsd; }
} // namespace

namespace afrilang::runtime::giskit155 {
inline double tileRow(double lat, double z) { { double n = std::pow(2.0, z); double latR = lat * 3.141592653589793 / 180.0; return std::floor((1.0 - std::log(std::tan(latR) + 1.0 / std::cos(latR)) / 3.141592653589793) / 2.0 * n); } }
inline double tileCol(double lon, double z) { { double n = std::pow(2.0, z); return std::floor((lon + 180.0) / 360.0 * n); } }
} // namespace

namespace afrilang::runtime::giskit156 {
inline double utmZone(double lon) { return std::floor((lon + 180.0) / 6.0) + 1.0; }
inline bool isNorthernHemisphere(double lat) { return lat >= 0.0; }
} // namespace

namespace afrilang::runtime::giskit157 {
inline double planarDist(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return std::sqrt(dx*dx+dy*dy); }
inline double planarDist2(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy; }
} // namespace

namespace afrilang::runtime::giskit158 {
inline double percentSlope(double rise, double run) { return run == 0 ? 0 : (rise / run) * 100.0; }
inline double degreeSlope(double rise, double run) { return run == 0 ? 0 : std::atan(rise / run) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::giskit159 {
inline double tileOriginX(double tileCol, double tileSize) { return tileCol * tileSize * 4.000000; }
inline double tileOriginY(double tileRow, double tileSize) { return tileRow * tileSize * 4.000000; }
} // namespace

namespace afrilang::runtime::giskit160 {
inline double haversineKm(double lat1, double lon1, double lat2, double lon2) { { double R=6371.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
inline double haversineM(double lat1, double lon1, double lat2, double lon2) { { double R=6371000.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
} // namespace

namespace afrilang::runtime::giskit161 {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad=[](double d){return d*3.141592653589793/180.0;}; double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline double azimuthDiff(double a, double b) { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }
} // namespace

namespace afrilang::runtime::giskit162 {
inline double bboxWidth(double minX, double minY, double maxX, double maxY) { return maxX - minX; }
inline double bboxArea(double minX, double minY, double maxX, double maxY) { return std::fabs(maxX - minX) * std::fabs(maxY - minY); }
} // namespace

namespace afrilang::runtime::giskit163 {
inline double bboxCenterX(double minX, double minY, double maxX, double maxY) { return (minX + maxX) / 2.0; }
inline double bboxCenterY(double minX, double minY, double maxX, double maxY) { return (minY + maxY) / 2.0; }
} // namespace

namespace afrilang::runtime::giskit164 {
inline bool pointInBbox(double x, double y, double minX, double minY, double maxX, double maxY) { return x >= minX && x <= maxX && y >= minY && y <= maxY; }
inline double degToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace

namespace afrilang::runtime::giskit165 {
inline double mToKm(double m) { return m / 1000.0; }
inline double kmToM(double km) { return km * 1000.0; }
} // namespace

namespace afrilang::runtime::giskit166 {
inline double normalizeLon(double lon) { return std::fmod(std::fmod(lon + 180.0, 360.0) + 360.0, 360.0) - 180.0; }
inline double clampLat(double lat) { return lat < -90.0 ? -90.0 : (lat > 90.0 ? 90.0 : lat); }
} // namespace

namespace afrilang::runtime::giskit167 {
inline double pixelIndex(double row, double col, double width) { return row * width + col; }
inline double geoToPixelX(double x, double originX, double resX) { return resX == 0 ? 0 : (x - originX) / resX; }
} // namespace

namespace afrilang::runtime::giskit168 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.6000+g*0.6940+b*0.2)/(1.4940); }
} // namespace

namespace afrilang::runtime::giskit169 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.6100+g*0.5500+b*0.2)/(1.3600); }
} // namespace

namespace afrilang::runtime::giskit170 {
inline double gsdFromAltitude(double altM, double focalMm, double pixelUm) { return focalMm == 0 ? 0 : (altM * pixelUm) / (focalMm * 1000.0); }
inline double groundWidth(double pixels, double gsd) { return pixels * gsd; }
} // namespace

namespace afrilang::runtime::giskit171 {
inline double tileRow(double lat, double z) { { double n = std::pow(2.0, z); double latR = lat * 3.141592653589793 / 180.0; return std::floor((1.0 - std::log(std::tan(latR) + 1.0 / std::cos(latR)) / 3.141592653589793) / 2.0 * n); } }
inline double tileCol(double lon, double z) { { double n = std::pow(2.0, z); return std::floor((lon + 180.0) / 360.0 * n); } }
} // namespace

namespace afrilang::runtime::giskit172 {
inline double utmZone(double lon) { return std::floor((lon + 180.0) / 6.0) + 1.0; }
inline bool isNorthernHemisphere(double lat) { return lat >= 0.0; }
} // namespace

namespace afrilang::runtime::giskit173 {
inline double planarDist(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return std::sqrt(dx*dx+dy*dy); }
inline double planarDist2(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy; }
} // namespace

namespace afrilang::runtime::giskit174 {
inline double percentSlope(double rise, double run) { return run == 0 ? 0 : (rise / run) * 100.0; }
inline double degreeSlope(double rise, double run) { return run == 0 ? 0 : std::atan(rise / run) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::giskit175 {
inline double tileOriginX(double tileCol, double tileSize) { return tileCol * tileSize * 0.750000; }
inline double tileOriginY(double tileRow, double tileSize) { return tileRow * tileSize * 0.750000; }
} // namespace

namespace afrilang::runtime::giskit176 {
inline double haversineKm(double lat1, double lon1, double lat2, double lon2) { { double R=6371.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
inline double haversineM(double lat1, double lon1, double lat2, double lon2) { { double R=6371000.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
} // namespace

namespace afrilang::runtime::giskit177 {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad=[](double d){return d*3.141592653589793/180.0;}; double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline double azimuthDiff(double a, double b) { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }
} // namespace

namespace afrilang::runtime::giskit178 {
inline double bboxWidth(double minX, double minY, double maxX, double maxY) { return maxX - minX; }
inline double bboxArea(double minX, double minY, double maxX, double maxY) { return std::fabs(maxX - minX) * std::fabs(maxY - minY); }
} // namespace

namespace afrilang::runtime::giskit179 {
inline double bboxCenterX(double minX, double minY, double maxX, double maxY) { return (minX + maxX) / 2.0; }
inline double bboxCenterY(double minX, double minY, double maxX, double maxY) { return (minY + maxY) / 2.0; }
} // namespace

namespace afrilang::runtime::giskit180 {
inline bool pointInBbox(double x, double y, double minX, double minY, double maxX, double maxY) { return x >= minX && x <= maxX && y >= minY && y <= maxY; }
inline double degToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace

namespace afrilang::runtime::giskit181 {
inline double mToKm(double m) { return m / 1000.0; }
inline double kmToM(double km) { return km * 1000.0; }
} // namespace

namespace afrilang::runtime::giskit182 {
inline double normalizeLon(double lon) { return std::fmod(std::fmod(lon + 180.0, 360.0) + 360.0, 360.0) - 180.0; }
inline double clampLat(double lat) { return lat < -90.0 ? -90.0 : (lat > 90.0 ? 90.0 : lat); }
} // namespace

namespace afrilang::runtime::giskit183 {
inline double pixelIndex(double row, double col, double width) { return row * width + col; }
inline double geoToPixelX(double x, double originX, double resX) { return resX == 0 ? 0 : (x - originX) / resX; }
} // namespace

namespace afrilang::runtime::giskit184 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5900+g*0.5740+b*0.2)/(1.3640); }
} // namespace

namespace afrilang::runtime::giskit185 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.6000+g*0.5860+b*0.2)/(1.3860); }
} // namespace

namespace afrilang::runtime::giskit186 {
inline double gsdFromAltitude(double altM, double focalMm, double pixelUm) { return focalMm == 0 ? 0 : (altM * pixelUm) / (focalMm * 1000.0); }
inline double groundWidth(double pixels, double gsd) { return pixels * gsd; }
} // namespace

namespace afrilang::runtime::giskit187 {
inline double tileRow(double lat, double z) { { double n = std::pow(2.0, z); double latR = lat * 3.141592653589793 / 180.0; return std::floor((1.0 - std::log(std::tan(latR) + 1.0 / std::cos(latR)) / 3.141592653589793) / 2.0 * n); } }
inline double tileCol(double lon, double z) { { double n = std::pow(2.0, z); return std::floor((lon + 180.0) / 360.0 * n); } }
} // namespace

namespace afrilang::runtime::giskit188 {
inline double utmZone(double lon) { return std::floor((lon + 180.0) / 6.0) + 1.0; }
inline bool isNorthernHemisphere(double lat) { return lat >= 0.0; }
} // namespace

namespace afrilang::runtime::giskit189 {
inline double planarDist(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return std::sqrt(dx*dx+dy*dy); }
inline double planarDist2(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy; }
} // namespace

namespace afrilang::runtime::giskit190 {
inline double percentSlope(double rise, double run) { return run == 0 ? 0 : (rise / run) * 100.0; }
inline double degreeSlope(double rise, double run) { return run == 0 ? 0 : std::atan(rise / run) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::giskit191 {
inline double tileOriginX(double tileCol, double tileSize) { return tileCol * tileSize * 4.750000; }
inline double tileOriginY(double tileRow, double tileSize) { return tileRow * tileSize * 4.750000; }
} // namespace

namespace afrilang::runtime::giskit192 {
inline double haversineKm(double lat1, double lon1, double lat2, double lon2) { { double R=6371.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
inline double haversineM(double lat1, double lon1, double lat2, double lon2) { { double R=6371000.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
} // namespace

namespace afrilang::runtime::giskit193 {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad=[](double d){return d*3.141592653589793/180.0;}; double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline double azimuthDiff(double a, double b) { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }
} // namespace

namespace afrilang::runtime::giskit194 {
inline double bboxWidth(double minX, double minY, double maxX, double maxY) { return maxX - minX; }
inline double bboxArea(double minX, double minY, double maxX, double maxY) { return std::fabs(maxX - minX) * std::fabs(maxY - minY); }
} // namespace

namespace afrilang::runtime::giskit195 {
inline double bboxCenterX(double minX, double minY, double maxX, double maxY) { return (minX + maxX) / 2.0; }
inline double bboxCenterY(double minX, double minY, double maxX, double maxY) { return (minY + maxY) / 2.0; }
} // namespace

namespace afrilang::runtime::giskit196 {
inline bool pointInBbox(double x, double y, double minX, double minY, double maxX, double maxY) { return x >= minX && x <= maxX && y >= minY && y <= maxY; }
inline double degToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace

namespace afrilang::runtime::giskit197 {
inline double mToKm(double m) { return m / 1000.0; }
inline double kmToM(double km) { return km * 1000.0; }
} // namespace

namespace afrilang::runtime::giskit198 {
inline double normalizeLon(double lon) { return std::fmod(std::fmod(lon + 180.0, 360.0) + 360.0, 360.0) - 180.0; }
inline double clampLat(double lat) { return lat < -90.0 ? -90.0 : (lat > 90.0 ? 90.0 : lat); }
} // namespace

namespace afrilang::runtime::giskit199 {
inline double pixelIndex(double row, double col, double width) { return row * width + col; }
inline double geoToPixelX(double x, double originX, double resX) { return resX == 0 ? 0 : (x - originX) / resX; }
} // namespace

namespace afrilang::runtime::giskit200 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5800+g*0.6100+b*0.2)/(1.3900); }
} // namespace

namespace afrilang::runtime::giskit201 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5900+g*0.6220+b*0.2)/(1.4120); }
} // namespace

namespace afrilang::runtime::giskit202 {
inline double gsdFromAltitude(double altM, double focalMm, double pixelUm) { return focalMm == 0 ? 0 : (altM * pixelUm) / (focalMm * 1000.0); }
inline double groundWidth(double pixels, double gsd) { return pixels * gsd; }
} // namespace

namespace afrilang::runtime::giskit203 {
inline double tileRow(double lat, double z) { { double n = std::pow(2.0, z); double latR = lat * 3.141592653589793 / 180.0; return std::floor((1.0 - std::log(std::tan(latR) + 1.0 / std::cos(latR)) / 3.141592653589793) / 2.0 * n); } }
inline double tileCol(double lon, double z) { { double n = std::pow(2.0, z); return std::floor((lon + 180.0) / 360.0 * n); } }
} // namespace

namespace afrilang::runtime::giskit204 {
inline double utmZone(double lon) { return std::floor((lon + 180.0) / 6.0) + 1.0; }
inline bool isNorthernHemisphere(double lat) { return lat >= 0.0; }
} // namespace

namespace afrilang::runtime::giskit205 {
inline double planarDist(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return std::sqrt(dx*dx+dy*dy); }
inline double planarDist2(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy; }
} // namespace

namespace afrilang::runtime::giskit206 {
inline double percentSlope(double rise, double run) { return run == 0 ? 0 : (rise / run) * 100.0; }
inline double degreeSlope(double rise, double run) { return run == 0 ? 0 : std::atan(rise / run) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::giskit207 {
inline double tileOriginX(double tileCol, double tileSize) { return tileCol * tileSize * 1.500000; }
inline double tileOriginY(double tileRow, double tileSize) { return tileRow * tileSize * 1.500000; }
} // namespace

namespace afrilang::runtime::giskit208 {
inline double haversineKm(double lat1, double lon1, double lat2, double lon2) { { double R=6371.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
inline double haversineM(double lat1, double lon1, double lat2, double lon2) { { double R=6371000.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
} // namespace

namespace afrilang::runtime::giskit209 {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad=[](double d){return d*3.141592653589793/180.0;}; double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline double azimuthDiff(double a, double b) { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }
} // namespace

namespace afrilang::runtime::giskit210 {
inline double bboxWidth(double minX, double minY, double maxX, double maxY) { return maxX - minX; }
inline double bboxArea(double minX, double minY, double maxX, double maxY) { return std::fabs(maxX - minX) * std::fabs(maxY - minY); }
} // namespace

namespace afrilang::runtime::giskit211 {
inline double bboxCenterX(double minX, double minY, double maxX, double maxY) { return (minX + maxX) / 2.0; }
inline double bboxCenterY(double minX, double minY, double maxX, double maxY) { return (minY + maxY) / 2.0; }
} // namespace

namespace afrilang::runtime::giskit212 {
inline bool pointInBbox(double x, double y, double minX, double minY, double maxX, double maxY) { return x >= minX && x <= maxX && y >= minY && y <= maxY; }
inline double degToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace

namespace afrilang::runtime::giskit213 {
inline double mToKm(double m) { return m / 1000.0; }
inline double kmToM(double km) { return km * 1000.0; }
} // namespace

namespace afrilang::runtime::giskit214 {
inline double normalizeLon(double lon) { return std::fmod(std::fmod(lon + 180.0, 360.0) + 360.0, 360.0) - 180.0; }
inline double clampLat(double lat) { return lat < -90.0 ? -90.0 : (lat > 90.0 ? 90.0 : lat); }
} // namespace

namespace afrilang::runtime::giskit215 {
inline double pixelIndex(double row, double col, double width) { return row * width + col; }
inline double geoToPixelX(double x, double originX, double resX) { return resX == 0 ? 0 : (x - originX) / resX; }
} // namespace

namespace afrilang::runtime::giskit216 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5700+g*0.6460+b*0.2)/(1.4160); }
} // namespace

namespace afrilang::runtime::giskit217 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5800+g*0.6580+b*0.2)/(1.4380); }
} // namespace

namespace afrilang::runtime::giskit218 {
inline double gsdFromAltitude(double altM, double focalMm, double pixelUm) { return focalMm == 0 ? 0 : (altM * pixelUm) / (focalMm * 1000.0); }
inline double groundWidth(double pixels, double gsd) { return pixels * gsd; }
} // namespace

namespace afrilang::runtime::giskit219 {
inline double tileRow(double lat, double z) { { double n = std::pow(2.0, z); double latR = lat * 3.141592653589793 / 180.0; return std::floor((1.0 - std::log(std::tan(latR) + 1.0 / std::cos(latR)) / 3.141592653589793) / 2.0 * n); } }
inline double tileCol(double lon, double z) { { double n = std::pow(2.0, z); return std::floor((lon + 180.0) / 360.0 * n); } }
} // namespace

namespace afrilang::runtime::giskit220 {
inline double utmZone(double lon) { return std::floor((lon + 180.0) / 6.0) + 1.0; }
inline bool isNorthernHemisphere(double lat) { return lat >= 0.0; }
} // namespace

namespace afrilang::runtime::giskit221 {
inline double planarDist(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return std::sqrt(dx*dx+dy*dy); }
inline double planarDist2(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy; }
} // namespace

namespace afrilang::runtime::giskit222 {
inline double percentSlope(double rise, double run) { return run == 0 ? 0 : (rise / run) * 100.0; }
inline double degreeSlope(double rise, double run) { return run == 0 ? 0 : std::atan(rise / run) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::giskit223 {
inline double tileOriginX(double tileCol, double tileSize) { return tileCol * tileSize * 5.500000; }
inline double tileOriginY(double tileRow, double tileSize) { return tileRow * tileSize * 5.500000; }
} // namespace

namespace afrilang::runtime::giskit224 {
inline double haversineKm(double lat1, double lon1, double lat2, double lon2) { { double R=6371.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
inline double haversineM(double lat1, double lon1, double lat2, double lon2) { { double R=6371000.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
} // namespace

namespace afrilang::runtime::giskit225 {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad=[](double d){return d*3.141592653589793/180.0;}; double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline double azimuthDiff(double a, double b) { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }
} // namespace

namespace afrilang::runtime::giskit226 {
inline double bboxWidth(double minX, double minY, double maxX, double maxY) { return maxX - minX; }
inline double bboxArea(double minX, double minY, double maxX, double maxY) { return std::fabs(maxX - minX) * std::fabs(maxY - minY); }
} // namespace

namespace afrilang::runtime::giskit227 {
inline double bboxCenterX(double minX, double minY, double maxX, double maxY) { return (minX + maxX) / 2.0; }
inline double bboxCenterY(double minX, double minY, double maxX, double maxY) { return (minY + maxY) / 2.0; }
} // namespace

namespace afrilang::runtime::giskit228 {
inline bool pointInBbox(double x, double y, double minX, double minY, double maxX, double maxY) { return x >= minX && x <= maxX && y >= minY && y <= maxY; }
inline double degToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace

namespace afrilang::runtime::giskit229 {
inline double mToKm(double m) { return m / 1000.0; }
inline double kmToM(double km) { return km * 1000.0; }
} // namespace

namespace afrilang::runtime::giskit230 {
inline double normalizeLon(double lon) { return std::fmod(std::fmod(lon + 180.0, 360.0) + 360.0, 360.0) - 180.0; }
inline double clampLat(double lat) { return lat < -90.0 ? -90.0 : (lat > 90.0 ? 90.0 : lat); }
} // namespace

namespace afrilang::runtime::giskit231 {
inline double pixelIndex(double row, double col, double width) { return row * width + col; }
inline double geoToPixelX(double x, double originX, double resX) { return resX == 0 ? 0 : (x - originX) / resX; }
} // namespace

namespace afrilang::runtime::giskit232 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5600+g*0.6820+b*0.2)/(1.4420); }
} // namespace

namespace afrilang::runtime::giskit233 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5700+g*0.6940+b*0.2)/(1.4640); }
} // namespace

namespace afrilang::runtime::giskit234 {
inline double gsdFromAltitude(double altM, double focalMm, double pixelUm) { return focalMm == 0 ? 0 : (altM * pixelUm) / (focalMm * 1000.0); }
inline double groundWidth(double pixels, double gsd) { return pixels * gsd; }
} // namespace

namespace afrilang::runtime::giskit235 {
inline double tileRow(double lat, double z) { { double n = std::pow(2.0, z); double latR = lat * 3.141592653589793 / 180.0; return std::floor((1.0 - std::log(std::tan(latR) + 1.0 / std::cos(latR)) / 3.141592653589793) / 2.0 * n); } }
inline double tileCol(double lon, double z) { { double n = std::pow(2.0, z); return std::floor((lon + 180.0) / 360.0 * n); } }
} // namespace

namespace afrilang::runtime::giskit236 {
inline double utmZone(double lon) { return std::floor((lon + 180.0) / 6.0) + 1.0; }
inline bool isNorthernHemisphere(double lat) { return lat >= 0.0; }
} // namespace

namespace afrilang::runtime::giskit237 {
inline double planarDist(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return std::sqrt(dx*dx+dy*dy); }
inline double planarDist2(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy; }
} // namespace

namespace afrilang::runtime::giskit238 {
inline double percentSlope(double rise, double run) { return run == 0 ? 0 : (rise / run) * 100.0; }
inline double degreeSlope(double rise, double run) { return run == 0 ? 0 : std::atan(rise / run) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::giskit239 {
inline double tileOriginX(double tileCol, double tileSize) { return tileCol * tileSize * 2.250000; }
inline double tileOriginY(double tileRow, double tileSize) { return tileRow * tileSize * 2.250000; }
} // namespace

namespace afrilang::runtime::giskit240 {
inline double haversineKm(double lat1, double lon1, double lat2, double lon2) { { double R=6371.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
inline double haversineM(double lat1, double lon1, double lat2, double lon2) { { double R=6371000.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
} // namespace

namespace afrilang::runtime::giskit241 {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad=[](double d){return d*3.141592653589793/180.0;}; double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline double azimuthDiff(double a, double b) { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }
} // namespace

namespace afrilang::runtime::giskit242 {
inline double bboxWidth(double minX, double minY, double maxX, double maxY) { return maxX - minX; }
inline double bboxArea(double minX, double minY, double maxX, double maxY) { return std::fabs(maxX - minX) * std::fabs(maxY - minY); }
} // namespace

namespace afrilang::runtime::giskit243 {
inline double bboxCenterX(double minX, double minY, double maxX, double maxY) { return (minX + maxX) / 2.0; }
inline double bboxCenterY(double minX, double minY, double maxX, double maxY) { return (minY + maxY) / 2.0; }
} // namespace

namespace afrilang::runtime::giskit244 {
inline bool pointInBbox(double x, double y, double minX, double minY, double maxX, double maxY) { return x >= minX && x <= maxX && y >= minY && y <= maxY; }
inline double degToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace

namespace afrilang::runtime::giskit245 {
inline double mToKm(double m) { return m / 1000.0; }
inline double kmToM(double km) { return km * 1000.0; }
} // namespace

namespace afrilang::runtime::giskit246 {
inline double normalizeLon(double lon) { return std::fmod(std::fmod(lon + 180.0, 360.0) + 360.0, 360.0) - 180.0; }
inline double clampLat(double lat) { return lat < -90.0 ? -90.0 : (lat > 90.0 ? 90.0 : lat); }
} // namespace

namespace afrilang::runtime::giskit247 {
inline double pixelIndex(double row, double col, double width) { return row * width + col; }
inline double geoToPixelX(double x, double originX, double resX) { return resX == 0 ? 0 : (x - originX) / resX; }
} // namespace

namespace afrilang::runtime::giskit248 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5500+g*0.5620+b*0.2)/(1.3120); }
} // namespace

namespace afrilang::runtime::giskit249 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5600+g*0.5740+b*0.2)/(1.3340); }
} // namespace

namespace afrilang::runtime::giskit250 {
inline double gsdFromAltitude(double altM, double focalMm, double pixelUm) { return focalMm == 0 ? 0 : (altM * pixelUm) / (focalMm * 1000.0); }
inline double groundWidth(double pixels, double gsd) { return pixels * gsd; }
} // namespace

namespace afrilang::runtime::giskit251 {
inline double tileRow(double lat, double z) { { double n = std::pow(2.0, z); double latR = lat * 3.141592653589793 / 180.0; return std::floor((1.0 - std::log(std::tan(latR) + 1.0 / std::cos(latR)) / 3.141592653589793) / 2.0 * n); } }
inline double tileCol(double lon, double z) { { double n = std::pow(2.0, z); return std::floor((lon + 180.0) / 360.0 * n); } }
} // namespace

namespace afrilang::runtime::giskit252 {
inline double utmZone(double lon) { return std::floor((lon + 180.0) / 6.0) + 1.0; }
inline bool isNorthernHemisphere(double lat) { return lat >= 0.0; }
} // namespace

namespace afrilang::runtime::giskit253 {
inline double planarDist(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return std::sqrt(dx*dx+dy*dy); }
inline double planarDist2(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy; }
} // namespace

namespace afrilang::runtime::giskit254 {
inline double percentSlope(double rise, double run) { return run == 0 ? 0 : (rise / run) * 100.0; }
inline double degreeSlope(double rise, double run) { return run == 0 ? 0 : std::atan(rise / run) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::giskit255 {
inline double tileOriginX(double tileCol, double tileSize) { return tileCol * tileSize * 6.250000; }
inline double tileOriginY(double tileRow, double tileSize) { return tileRow * tileSize * 6.250000; }
} // namespace

namespace afrilang::runtime::giskit256 {
inline double haversineKm(double lat1, double lon1, double lat2, double lon2) { { double R=6371.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
inline double haversineM(double lat1, double lon1, double lat2, double lon2) { { double R=6371000.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
} // namespace

namespace afrilang::runtime::giskit257 {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad=[](double d){return d*3.141592653589793/180.0;}; double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline double azimuthDiff(double a, double b) { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }
} // namespace

namespace afrilang::runtime::giskit258 {
inline double bboxWidth(double minX, double minY, double maxX, double maxY) { return maxX - minX; }
inline double bboxArea(double minX, double minY, double maxX, double maxY) { return std::fabs(maxX - minX) * std::fabs(maxY - minY); }
} // namespace

namespace afrilang::runtime::giskit259 {
inline double bboxCenterX(double minX, double minY, double maxX, double maxY) { return (minX + maxX) / 2.0; }
inline double bboxCenterY(double minX, double minY, double maxX, double maxY) { return (minY + maxY) / 2.0; }
} // namespace

namespace afrilang::runtime::giskit260 {
inline bool pointInBbox(double x, double y, double minX, double minY, double maxX, double maxY) { return x >= minX && x <= maxX && y >= minY && y <= maxY; }
inline double degToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace

namespace afrilang::runtime::giskit261 {
inline double mToKm(double m) { return m / 1000.0; }
inline double kmToM(double km) { return km * 1000.0; }
} // namespace

namespace afrilang::runtime::giskit262 {
inline double normalizeLon(double lon) { return std::fmod(std::fmod(lon + 180.0, 360.0) + 360.0, 360.0) - 180.0; }
inline double clampLat(double lat) { return lat < -90.0 ? -90.0 : (lat > 90.0 ? 90.0 : lat); }
} // namespace

namespace afrilang::runtime::giskit263 {
inline double pixelIndex(double row, double col, double width) { return row * width + col; }
inline double geoToPixelX(double x, double originX, double resX) { return resX == 0 ? 0 : (x - originX) / resX; }
} // namespace

namespace afrilang::runtime::giskit264 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5400+g*0.5980+b*0.2)/(1.3380); }
} // namespace

namespace afrilang::runtime::giskit265 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5500+g*0.6100+b*0.2)/(1.3600); }
} // namespace

namespace afrilang::runtime::giskit266 {
inline double gsdFromAltitude(double altM, double focalMm, double pixelUm) { return focalMm == 0 ? 0 : (altM * pixelUm) / (focalMm * 1000.0); }
inline double groundWidth(double pixels, double gsd) { return pixels * gsd; }
} // namespace

namespace afrilang::runtime::giskit267 {
inline double tileRow(double lat, double z) { { double n = std::pow(2.0, z); double latR = lat * 3.141592653589793 / 180.0; return std::floor((1.0 - std::log(std::tan(latR) + 1.0 / std::cos(latR)) / 3.141592653589793) / 2.0 * n); } }
inline double tileCol(double lon, double z) { { double n = std::pow(2.0, z); return std::floor((lon + 180.0) / 360.0 * n); } }
} // namespace

namespace afrilang::runtime::giskit268 {
inline double utmZone(double lon) { return std::floor((lon + 180.0) / 6.0) + 1.0; }
inline bool isNorthernHemisphere(double lat) { return lat >= 0.0; }
} // namespace

namespace afrilang::runtime::giskit269 {
inline double planarDist(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return std::sqrt(dx*dx+dy*dy); }
inline double planarDist2(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy; }
} // namespace

namespace afrilang::runtime::giskit270 {
inline double percentSlope(double rise, double run) { return run == 0 ? 0 : (rise / run) * 100.0; }
inline double degreeSlope(double rise, double run) { return run == 0 ? 0 : std::atan(rise / run) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::giskit271 {
inline double tileOriginX(double tileCol, double tileSize) { return tileCol * tileSize * 3.000000; }
inline double tileOriginY(double tileRow, double tileSize) { return tileRow * tileSize * 3.000000; }
} // namespace

namespace afrilang::runtime::giskit272 {
inline double haversineKm(double lat1, double lon1, double lat2, double lon2) { { double R=6371.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
inline double haversineM(double lat1, double lon1, double lat2, double lon2) { { double R=6371000.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
} // namespace

namespace afrilang::runtime::giskit273 {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad=[](double d){return d*3.141592653589793/180.0;}; double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline double azimuthDiff(double a, double b) { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }
} // namespace

namespace afrilang::runtime::giskit274 {
inline double bboxWidth(double minX, double minY, double maxX, double maxY) { return maxX - minX; }
inline double bboxArea(double minX, double minY, double maxX, double maxY) { return std::fabs(maxX - minX) * std::fabs(maxY - minY); }
} // namespace

namespace afrilang::runtime::giskit275 {
inline double bboxCenterX(double minX, double minY, double maxX, double maxY) { return (minX + maxX) / 2.0; }
inline double bboxCenterY(double minX, double minY, double maxX, double maxY) { return (minY + maxY) / 2.0; }
} // namespace

namespace afrilang::runtime::giskit276 {
inline bool pointInBbox(double x, double y, double minX, double minY, double maxX, double maxY) { return x >= minX && x <= maxX && y >= minY && y <= maxY; }
inline double degToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace

namespace afrilang::runtime::giskit277 {
inline double mToKm(double m) { return m / 1000.0; }
inline double kmToM(double km) { return km * 1000.0; }
} // namespace

namespace afrilang::runtime::giskit278 {
inline double normalizeLon(double lon) { return std::fmod(std::fmod(lon + 180.0, 360.0) + 360.0, 360.0) - 180.0; }
inline double clampLat(double lat) { return lat < -90.0 ? -90.0 : (lat > 90.0 ? 90.0 : lat); }
} // namespace

namespace afrilang::runtime::giskit279 {
inline double pixelIndex(double row, double col, double width) { return row * width + col; }
inline double geoToPixelX(double x, double originX, double resX) { return resX == 0 ? 0 : (x - originX) / resX; }
} // namespace

namespace afrilang::runtime::giskit280 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5300+g*0.6340+b*0.2)/(1.3640); }
} // namespace

namespace afrilang::runtime::giskit281 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5400+g*0.6460+b*0.2)/(1.3860); }
} // namespace

namespace afrilang::runtime::giskit282 {
inline double gsdFromAltitude(double altM, double focalMm, double pixelUm) { return focalMm == 0 ? 0 : (altM * pixelUm) / (focalMm * 1000.0); }
inline double groundWidth(double pixels, double gsd) { return pixels * gsd; }
} // namespace

namespace afrilang::runtime::giskit283 {
inline double tileRow(double lat, double z) { { double n = std::pow(2.0, z); double latR = lat * 3.141592653589793 / 180.0; return std::floor((1.0 - std::log(std::tan(latR) + 1.0 / std::cos(latR)) / 3.141592653589793) / 2.0 * n); } }
inline double tileCol(double lon, double z) { { double n = std::pow(2.0, z); return std::floor((lon + 180.0) / 360.0 * n); } }
} // namespace

namespace afrilang::runtime::giskit284 {
inline double utmZone(double lon) { return std::floor((lon + 180.0) / 6.0) + 1.0; }
inline bool isNorthernHemisphere(double lat) { return lat >= 0.0; }
} // namespace

namespace afrilang::runtime::giskit285 {
inline double planarDist(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return std::sqrt(dx*dx+dy*dy); }
inline double planarDist2(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy; }
} // namespace

namespace afrilang::runtime::giskit286 {
inline double percentSlope(double rise, double run) { return run == 0 ? 0 : (rise / run) * 100.0; }
inline double degreeSlope(double rise, double run) { return run == 0 ? 0 : std::atan(rise / run) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::giskit287 {
inline double tileOriginX(double tileCol, double tileSize) { return tileCol * tileSize * 7.000000; }
inline double tileOriginY(double tileRow, double tileSize) { return tileRow * tileSize * 7.000000; }
} // namespace

namespace afrilang::runtime::giskit288 {
inline double haversineKm(double lat1, double lon1, double lat2, double lon2) { { double R=6371.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
inline double haversineM(double lat1, double lon1, double lat2, double lon2) { { double R=6371000.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
} // namespace

namespace afrilang::runtime::giskit289 {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad=[](double d){return d*3.141592653589793/180.0;}; double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline double azimuthDiff(double a, double b) { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }
} // namespace

namespace afrilang::runtime::giskit290 {
inline double bboxWidth(double minX, double minY, double maxX, double maxY) { return maxX - minX; }
inline double bboxArea(double minX, double minY, double maxX, double maxY) { return std::fabs(maxX - minX) * std::fabs(maxY - minY); }
} // namespace

namespace afrilang::runtime::giskit291 {
inline double bboxCenterX(double minX, double minY, double maxX, double maxY) { return (minX + maxX) / 2.0; }
inline double bboxCenterY(double minX, double minY, double maxX, double maxY) { return (minY + maxY) / 2.0; }
} // namespace

namespace afrilang::runtime::giskit292 {
inline bool pointInBbox(double x, double y, double minX, double minY, double maxX, double maxY) { return x >= minX && x <= maxX && y >= minY && y <= maxY; }
inline double degToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace

namespace afrilang::runtime::giskit293 {
inline double mToKm(double m) { return m / 1000.0; }
inline double kmToM(double km) { return km * 1000.0; }
} // namespace

namespace afrilang::runtime::giskit294 {
inline double normalizeLon(double lon) { return std::fmod(std::fmod(lon + 180.0, 360.0) + 360.0, 360.0) - 180.0; }
inline double clampLat(double lat) { return lat < -90.0 ? -90.0 : (lat > 90.0 ? 90.0 : lat); }
} // namespace

namespace afrilang::runtime::giskit295 {
inline double pixelIndex(double row, double col, double width) { return row * width + col; }
inline double geoToPixelX(double x, double originX, double resX) { return resX == 0 ? 0 : (x - originX) / resX; }
} // namespace

namespace afrilang::runtime::giskit296 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5200+g*0.6700+b*0.2)/(1.3900); }
} // namespace

namespace afrilang::runtime::giskit297 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5300+g*0.6820+b*0.2)/(1.4120); }
} // namespace

namespace afrilang::runtime::giskit298 {
inline double gsdFromAltitude(double altM, double focalMm, double pixelUm) { return focalMm == 0 ? 0 : (altM * pixelUm) / (focalMm * 1000.0); }
inline double groundWidth(double pixels, double gsd) { return pixels * gsd; }
} // namespace

namespace afrilang::runtime::giskit299 {
inline double tileRow(double lat, double z) { { double n = std::pow(2.0, z); double latR = lat * 3.141592653589793 / 180.0; return std::floor((1.0 - std::log(std::tan(latR) + 1.0 / std::cos(latR)) / 3.141592653589793) / 2.0 * n); } }
inline double tileCol(double lon, double z) { { double n = std::pow(2.0, z); return std::floor((lon + 180.0) / 360.0 * n); } }
} // namespace

namespace afrilang::runtime::giskit300 {
inline double utmZone(double lon) { return std::floor((lon + 180.0) / 6.0) + 1.0; }
inline bool isNorthernHemisphere(double lat) { return lat >= 0.0; }
} // namespace

namespace afrilang::runtime::giskit301 {
inline double planarDist(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return std::sqrt(dx*dx+dy*dy); }
inline double planarDist2(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy; }
} // namespace

namespace afrilang::runtime::giskit302 {
inline double percentSlope(double rise, double run) { return run == 0 ? 0 : (rise / run) * 100.0; }
inline double degreeSlope(double rise, double run) { return run == 0 ? 0 : std::atan(rise / run) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::giskit303 {
inline double tileOriginX(double tileCol, double tileSize) { return tileCol * tileSize * 3.750000; }
inline double tileOriginY(double tileRow, double tileSize) { return tileRow * tileSize * 3.750000; }
} // namespace

namespace afrilang::runtime::giskit304 {
inline double haversineKm(double lat1, double lon1, double lat2, double lon2) { { double R=6371.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
inline double haversineM(double lat1, double lon1, double lat2, double lon2) { { double R=6371000.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
} // namespace

namespace afrilang::runtime::giskit305 {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad=[](double d){return d*3.141592653589793/180.0;}; double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline double azimuthDiff(double a, double b) { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }
} // namespace

namespace afrilang::runtime::giskit306 {
inline double bboxWidth(double minX, double minY, double maxX, double maxY) { return maxX - minX; }
inline double bboxArea(double minX, double minY, double maxX, double maxY) { return std::fabs(maxX - minX) * std::fabs(maxY - minY); }
} // namespace

namespace afrilang::runtime::giskit307 {
inline double bboxCenterX(double minX, double minY, double maxX, double maxY) { return (minX + maxX) / 2.0; }
inline double bboxCenterY(double minX, double minY, double maxX, double maxY) { return (minY + maxY) / 2.0; }
} // namespace

namespace afrilang::runtime::giskit308 {
inline bool pointInBbox(double x, double y, double minX, double minY, double maxX, double maxY) { return x >= minX && x <= maxX && y >= minY && y <= maxY; }
inline double degToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace

namespace afrilang::runtime::giskit309 {
inline double mToKm(double m) { return m / 1000.0; }
inline double kmToM(double km) { return km * 1000.0; }
} // namespace

namespace afrilang::runtime::giskit310 {
inline double normalizeLon(double lon) { return std::fmod(std::fmod(lon + 180.0, 360.0) + 360.0, 360.0) - 180.0; }
inline double clampLat(double lat) { return lat < -90.0 ? -90.0 : (lat > 90.0 ? 90.0 : lat); }
} // namespace

namespace afrilang::runtime::giskit311 {
inline double pixelIndex(double row, double col, double width) { return row * width + col; }
inline double geoToPixelX(double x, double originX, double resX) { return resX == 0 ? 0 : (x - originX) / resX; }
} // namespace

namespace afrilang::runtime::giskit312 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5100+g*0.5500+b*0.2)/(1.2600); }
} // namespace

namespace afrilang::runtime::giskit313 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5200+g*0.5620+b*0.2)/(1.2820); }
} // namespace

namespace afrilang::runtime::giskit314 {
inline double gsdFromAltitude(double altM, double focalMm, double pixelUm) { return focalMm == 0 ? 0 : (altM * pixelUm) / (focalMm * 1000.0); }
inline double groundWidth(double pixels, double gsd) { return pixels * gsd; }
} // namespace

namespace afrilang::runtime::giskit315 {
inline double tileRow(double lat, double z) { { double n = std::pow(2.0, z); double latR = lat * 3.141592653589793 / 180.0; return std::floor((1.0 - std::log(std::tan(latR) + 1.0 / std::cos(latR)) / 3.141592653589793) / 2.0 * n); } }
inline double tileCol(double lon, double z) { { double n = std::pow(2.0, z); return std::floor((lon + 180.0) / 360.0 * n); } }
} // namespace

namespace afrilang::runtime::giskit316 {
inline double utmZone(double lon) { return std::floor((lon + 180.0) / 6.0) + 1.0; }
inline bool isNorthernHemisphere(double lat) { return lat >= 0.0; }
} // namespace

namespace afrilang::runtime::giskit317 {
inline double planarDist(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return std::sqrt(dx*dx+dy*dy); }
inline double planarDist2(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy; }
} // namespace

namespace afrilang::runtime::giskit318 {
inline double percentSlope(double rise, double run) { return run == 0 ? 0 : (rise / run) * 100.0; }
inline double degreeSlope(double rise, double run) { return run == 0 ? 0 : std::atan(rise / run) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::giskit319 {
inline double tileOriginX(double tileCol, double tileSize) { return tileCol * tileSize * 0.500000; }
inline double tileOriginY(double tileRow, double tileSize) { return tileRow * tileSize * 0.500000; }
} // namespace

namespace afrilang::runtime::giskit320 {
inline double haversineKm(double lat1, double lon1, double lat2, double lon2) { { double R=6371.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
inline double haversineM(double lat1, double lon1, double lat2, double lon2) { { double R=6371000.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
} // namespace

namespace afrilang::runtime::giskit321 {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad=[](double d){return d*3.141592653589793/180.0;}; double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline double azimuthDiff(double a, double b) { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }
} // namespace

namespace afrilang::runtime::giskit322 {
inline double bboxWidth(double minX, double minY, double maxX, double maxY) { return maxX - minX; }
inline double bboxArea(double minX, double minY, double maxX, double maxY) { return std::fabs(maxX - minX) * std::fabs(maxY - minY); }
} // namespace

namespace afrilang::runtime::giskit323 {
inline double bboxCenterX(double minX, double minY, double maxX, double maxY) { return (minX + maxX) / 2.0; }
inline double bboxCenterY(double minX, double minY, double maxX, double maxY) { return (minY + maxY) / 2.0; }
} // namespace

namespace afrilang::runtime::giskit324 {
inline bool pointInBbox(double x, double y, double minX, double minY, double maxX, double maxY) { return x >= minX && x <= maxX && y >= minY && y <= maxY; }
inline double degToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace

namespace afrilang::runtime::giskit325 {
inline double mToKm(double m) { return m / 1000.0; }
inline double kmToM(double km) { return km * 1000.0; }
} // namespace

namespace afrilang::runtime::giskit326 {
inline double normalizeLon(double lon) { return std::fmod(std::fmod(lon + 180.0, 360.0) + 360.0, 360.0) - 180.0; }
inline double clampLat(double lat) { return lat < -90.0 ? -90.0 : (lat > 90.0 ? 90.0 : lat); }
} // namespace

namespace afrilang::runtime::giskit327 {
inline double pixelIndex(double row, double col, double width) { return row * width + col; }
inline double geoToPixelX(double x, double originX, double resX) { return resX == 0 ? 0 : (x - originX) / resX; }
} // namespace

namespace afrilang::runtime::giskit328 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5000+g*0.5860+b*0.2)/(1.2860); }
} // namespace

namespace afrilang::runtime::giskit329 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5100+g*0.5980+b*0.2)/(1.3080); }
} // namespace

namespace afrilang::runtime::giskit330 {
inline double gsdFromAltitude(double altM, double focalMm, double pixelUm) { return focalMm == 0 ? 0 : (altM * pixelUm) / (focalMm * 1000.0); }
inline double groundWidth(double pixels, double gsd) { return pixels * gsd; }
} // namespace

namespace afrilang::runtime::giskit331 {
inline double tileRow(double lat, double z) { { double n = std::pow(2.0, z); double latR = lat * 3.141592653589793 / 180.0; return std::floor((1.0 - std::log(std::tan(latR) + 1.0 / std::cos(latR)) / 3.141592653589793) / 2.0 * n); } }
inline double tileCol(double lon, double z) { { double n = std::pow(2.0, z); return std::floor((lon + 180.0) / 360.0 * n); } }
} // namespace

namespace afrilang::runtime::giskit332 {
inline double utmZone(double lon) { return std::floor((lon + 180.0) / 6.0) + 1.0; }
inline bool isNorthernHemisphere(double lat) { return lat >= 0.0; }
} // namespace

namespace afrilang::runtime::giskit333 {
inline double planarDist(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return std::sqrt(dx*dx+dy*dy); }
inline double planarDist2(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy; }
} // namespace

namespace afrilang::runtime::giskit334 {
inline double percentSlope(double rise, double run) { return run == 0 ? 0 : (rise / run) * 100.0; }
inline double degreeSlope(double rise, double run) { return run == 0 ? 0 : std::atan(rise / run) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::giskit335 {
inline double tileOriginX(double tileCol, double tileSize) { return tileCol * tileSize * 4.500000; }
inline double tileOriginY(double tileRow, double tileSize) { return tileRow * tileSize * 4.500000; }
} // namespace

namespace afrilang::runtime::giskit336 {
inline double haversineKm(double lat1, double lon1, double lat2, double lon2) { { double R=6371.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
inline double haversineM(double lat1, double lon1, double lat2, double lon2) { { double R=6371000.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
} // namespace

namespace afrilang::runtime::giskit337 {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad=[](double d){return d*3.141592653589793/180.0;}; double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline double azimuthDiff(double a, double b) { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }
} // namespace

namespace afrilang::runtime::giskit338 {
inline double bboxWidth(double minX, double minY, double maxX, double maxY) { return maxX - minX; }
inline double bboxArea(double minX, double minY, double maxX, double maxY) { return std::fabs(maxX - minX) * std::fabs(maxY - minY); }
} // namespace

namespace afrilang::runtime::giskit339 {
inline double bboxCenterX(double minX, double minY, double maxX, double maxY) { return (minX + maxX) / 2.0; }
inline double bboxCenterY(double minX, double minY, double maxX, double maxY) { return (minY + maxY) / 2.0; }
} // namespace

namespace afrilang::runtime::giskit340 {
inline bool pointInBbox(double x, double y, double minX, double minY, double maxX, double maxY) { return x >= minX && x <= maxX && y >= minY && y <= maxY; }
inline double degToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace

namespace afrilang::runtime::giskit341 {
inline double mToKm(double m) { return m / 1000.0; }
inline double kmToM(double km) { return km * 1000.0; }
} // namespace

namespace afrilang::runtime::giskit342 {
inline double normalizeLon(double lon) { return std::fmod(std::fmod(lon + 180.0, 360.0) + 360.0, 360.0) - 180.0; }
inline double clampLat(double lat) { return lat < -90.0 ? -90.0 : (lat > 90.0 ? 90.0 : lat); }
} // namespace

namespace afrilang::runtime::giskit343 {
inline double pixelIndex(double row, double col, double width) { return row * width + col; }
inline double geoToPixelX(double x, double originX, double resX) { return resX == 0 ? 0 : (x - originX) / resX; }
} // namespace

namespace afrilang::runtime::giskit344 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.4900+g*0.6220+b*0.2)/(1.3120); }
} // namespace

namespace afrilang::runtime::giskit345 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5000+g*0.6340+b*0.2)/(1.3340); }
} // namespace

namespace afrilang::runtime::giskit346 {
inline double gsdFromAltitude(double altM, double focalMm, double pixelUm) { return focalMm == 0 ? 0 : (altM * pixelUm) / (focalMm * 1000.0); }
inline double groundWidth(double pixels, double gsd) { return pixels * gsd; }
} // namespace

namespace afrilang::runtime::giskit347 {
inline double tileRow(double lat, double z) { { double n = std::pow(2.0, z); double latR = lat * 3.141592653589793 / 180.0; return std::floor((1.0 - std::log(std::tan(latR) + 1.0 / std::cos(latR)) / 3.141592653589793) / 2.0 * n); } }
inline double tileCol(double lon, double z) { { double n = std::pow(2.0, z); return std::floor((lon + 180.0) / 360.0 * n); } }
} // namespace

namespace afrilang::runtime::giskit348 {
inline double utmZone(double lon) { return std::floor((lon + 180.0) / 6.0) + 1.0; }
inline bool isNorthernHemisphere(double lat) { return lat >= 0.0; }
} // namespace

namespace afrilang::runtime::giskit349 {
inline double planarDist(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return std::sqrt(dx*dx+dy*dy); }
inline double planarDist2(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy; }
} // namespace

namespace afrilang::runtime::giskit350 {
inline double percentSlope(double rise, double run) { return run == 0 ? 0 : (rise / run) * 100.0; }
inline double degreeSlope(double rise, double run) { return run == 0 ? 0 : std::atan(rise / run) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::giskit351 {
inline double tileOriginX(double tileCol, double tileSize) { return tileCol * tileSize * 1.250000; }
inline double tileOriginY(double tileRow, double tileSize) { return tileRow * tileSize * 1.250000; }
} // namespace

namespace afrilang::runtime::giskit352 {
inline double haversineKm(double lat1, double lon1, double lat2, double lon2) { { double R=6371.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
inline double haversineM(double lat1, double lon1, double lat2, double lon2) { { double R=6371000.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
} // namespace

namespace afrilang::runtime::giskit353 {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad=[](double d){return d*3.141592653589793/180.0;}; double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline double azimuthDiff(double a, double b) { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }
} // namespace

namespace afrilang::runtime::giskit354 {
inline double bboxWidth(double minX, double minY, double maxX, double maxY) { return maxX - minX; }
inline double bboxArea(double minX, double minY, double maxX, double maxY) { return std::fabs(maxX - minX) * std::fabs(maxY - minY); }
} // namespace

namespace afrilang::runtime::giskit355 {
inline double bboxCenterX(double minX, double minY, double maxX, double maxY) { return (minX + maxX) / 2.0; }
inline double bboxCenterY(double minX, double minY, double maxX, double maxY) { return (minY + maxY) / 2.0; }
} // namespace

namespace afrilang::runtime::giskit356 {
inline bool pointInBbox(double x, double y, double minX, double minY, double maxX, double maxY) { return x >= minX && x <= maxX && y >= minY && y <= maxY; }
inline double degToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace

namespace afrilang::runtime::giskit357 {
inline double mToKm(double m) { return m / 1000.0; }
inline double kmToM(double km) { return km * 1000.0; }
} // namespace

namespace afrilang::runtime::giskit358 {
inline double normalizeLon(double lon) { return std::fmod(std::fmod(lon + 180.0, 360.0) + 360.0, 360.0) - 180.0; }
inline double clampLat(double lat) { return lat < -90.0 ? -90.0 : (lat > 90.0 ? 90.0 : lat); }
} // namespace

namespace afrilang::runtime::giskit359 {
inline double pixelIndex(double row, double col, double width) { return row * width + col; }
inline double geoToPixelX(double x, double originX, double resX) { return resX == 0 ? 0 : (x - originX) / resX; }
} // namespace

namespace afrilang::runtime::giskit360 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.4800+g*0.6580+b*0.2)/(1.3380); }
} // namespace

namespace afrilang::runtime::giskit361 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.4900+g*0.6700+b*0.2)/(1.3600); }
} // namespace

namespace afrilang::runtime::giskit362 {
inline double gsdFromAltitude(double altM, double focalMm, double pixelUm) { return focalMm == 0 ? 0 : (altM * pixelUm) / (focalMm * 1000.0); }
inline double groundWidth(double pixels, double gsd) { return pixels * gsd; }
} // namespace

namespace afrilang::runtime::giskit363 {
inline double tileRow(double lat, double z) { { double n = std::pow(2.0, z); double latR = lat * 3.141592653589793 / 180.0; return std::floor((1.0 - std::log(std::tan(latR) + 1.0 / std::cos(latR)) / 3.141592653589793) / 2.0 * n); } }
inline double tileCol(double lon, double z) { { double n = std::pow(2.0, z); return std::floor((lon + 180.0) / 360.0 * n); } }
} // namespace

namespace afrilang::runtime::giskit364 {
inline double utmZone(double lon) { return std::floor((lon + 180.0) / 6.0) + 1.0; }
inline bool isNorthernHemisphere(double lat) { return lat >= 0.0; }
} // namespace

namespace afrilang::runtime::giskit365 {
inline double planarDist(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return std::sqrt(dx*dx+dy*dy); }
inline double planarDist2(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy; }
} // namespace

namespace afrilang::runtime::giskit366 {
inline double percentSlope(double rise, double run) { return run == 0 ? 0 : (rise / run) * 100.0; }
inline double degreeSlope(double rise, double run) { return run == 0 ? 0 : std::atan(rise / run) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::giskit367 {
inline double tileOriginX(double tileCol, double tileSize) { return tileCol * tileSize * 5.250000; }
inline double tileOriginY(double tileRow, double tileSize) { return tileRow * tileSize * 5.250000; }
} // namespace

namespace afrilang::runtime::giskit368 {
inline double haversineKm(double lat1, double lon1, double lat2, double lon2) { { double R=6371.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
inline double haversineM(double lat1, double lon1, double lat2, double lon2) { { double R=6371000.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
} // namespace

namespace afrilang::runtime::giskit369 {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad=[](double d){return d*3.141592653589793/180.0;}; double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline double azimuthDiff(double a, double b) { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }
} // namespace

namespace afrilang::runtime::giskit370 {
inline double bboxWidth(double minX, double minY, double maxX, double maxY) { return maxX - minX; }
inline double bboxArea(double minX, double minY, double maxX, double maxY) { return std::fabs(maxX - minX) * std::fabs(maxY - minY); }
} // namespace

namespace afrilang::runtime::giskit371 {
inline double bboxCenterX(double minX, double minY, double maxX, double maxY) { return (minX + maxX) / 2.0; }
inline double bboxCenterY(double minX, double minY, double maxX, double maxY) { return (minY + maxY) / 2.0; }
} // namespace

namespace afrilang::runtime::giskit372 {
inline bool pointInBbox(double x, double y, double minX, double minY, double maxX, double maxY) { return x >= minX && x <= maxX && y >= minY && y <= maxY; }
inline double degToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace

namespace afrilang::runtime::giskit373 {
inline double mToKm(double m) { return m / 1000.0; }
inline double kmToM(double km) { return km * 1000.0; }
} // namespace

namespace afrilang::runtime::giskit374 {
inline double normalizeLon(double lon) { return std::fmod(std::fmod(lon + 180.0, 360.0) + 360.0, 360.0) - 180.0; }
inline double clampLat(double lat) { return lat < -90.0 ? -90.0 : (lat > 90.0 ? 90.0 : lat); }
} // namespace

namespace afrilang::runtime::giskit375 {
inline double pixelIndex(double row, double col, double width) { return row * width + col; }
inline double geoToPixelX(double x, double originX, double resX) { return resX == 0 ? 0 : (x - originX) / resX; }
} // namespace

namespace afrilang::runtime::giskit376 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.4700+g*0.6940+b*0.2)/(1.3640); }
} // namespace

namespace afrilang::runtime::giskit377 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.4800+g*0.5500+b*0.2)/(1.2300); }
} // namespace

namespace afrilang::runtime::giskit378 {
inline double gsdFromAltitude(double altM, double focalMm, double pixelUm) { return focalMm == 0 ? 0 : (altM * pixelUm) / (focalMm * 1000.0); }
inline double groundWidth(double pixels, double gsd) { return pixels * gsd; }
} // namespace

namespace afrilang::runtime::giskit379 {
inline double tileRow(double lat, double z) { { double n = std::pow(2.0, z); double latR = lat * 3.141592653589793 / 180.0; return std::floor((1.0 - std::log(std::tan(latR) + 1.0 / std::cos(latR)) / 3.141592653589793) / 2.0 * n); } }
inline double tileCol(double lon, double z) { { double n = std::pow(2.0, z); return std::floor((lon + 180.0) / 360.0 * n); } }
} // namespace

namespace afrilang::runtime::giskit380 {
inline double utmZone(double lon) { return std::floor((lon + 180.0) / 6.0) + 1.0; }
inline bool isNorthernHemisphere(double lat) { return lat >= 0.0; }
} // namespace

namespace afrilang::runtime::giskit381 {
inline double planarDist(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return std::sqrt(dx*dx+dy*dy); }
inline double planarDist2(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy; }
} // namespace

namespace afrilang::runtime::giskit382 {
inline double percentSlope(double rise, double run) { return run == 0 ? 0 : (rise / run) * 100.0; }
inline double degreeSlope(double rise, double run) { return run == 0 ? 0 : std::atan(rise / run) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::giskit383 {
inline double tileOriginX(double tileCol, double tileSize) { return tileCol * tileSize * 2.000000; }
inline double tileOriginY(double tileRow, double tileSize) { return tileRow * tileSize * 2.000000; }
} // namespace

namespace afrilang::runtime::giskit384 {
inline double haversineKm(double lat1, double lon1, double lat2, double lon2) { { double R=6371.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
inline double haversineM(double lat1, double lon1, double lat2, double lon2) { { double R=6371000.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
} // namespace

namespace afrilang::runtime::giskit385 {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad=[](double d){return d*3.141592653589793/180.0;}; double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline double azimuthDiff(double a, double b) { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }
} // namespace

namespace afrilang::runtime::giskit386 {
inline double bboxWidth(double minX, double minY, double maxX, double maxY) { return maxX - minX; }
inline double bboxArea(double minX, double minY, double maxX, double maxY) { return std::fabs(maxX - minX) * std::fabs(maxY - minY); }
} // namespace

namespace afrilang::runtime::giskit387 {
inline double bboxCenterX(double minX, double minY, double maxX, double maxY) { return (minX + maxX) / 2.0; }
inline double bboxCenterY(double minX, double minY, double maxX, double maxY) { return (minY + maxY) / 2.0; }
} // namespace

namespace afrilang::runtime::giskit388 {
inline bool pointInBbox(double x, double y, double minX, double minY, double maxX, double maxY) { return x >= minX && x <= maxX && y >= minY && y <= maxY; }
inline double degToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace

namespace afrilang::runtime::giskit389 {
inline double mToKm(double m) { return m / 1000.0; }
inline double kmToM(double km) { return km * 1000.0; }
} // namespace

namespace afrilang::runtime::giskit390 {
inline double normalizeLon(double lon) { return std::fmod(std::fmod(lon + 180.0, 360.0) + 360.0, 360.0) - 180.0; }
inline double clampLat(double lat) { return lat < -90.0 ? -90.0 : (lat > 90.0 ? 90.0 : lat); }
} // namespace

namespace afrilang::runtime::giskit391 {
inline double pixelIndex(double row, double col, double width) { return row * width + col; }
inline double geoToPixelX(double x, double originX, double resX) { return resX == 0 ? 0 : (x - originX) / resX; }
} // namespace

namespace afrilang::runtime::giskit392 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.4600+g*0.5740+b*0.2)/(1.2340); }
} // namespace

namespace afrilang::runtime::giskit393 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.4700+g*0.5860+b*0.2)/(1.2560); }
} // namespace

namespace afrilang::runtime::giskit394 {
inline double gsdFromAltitude(double altM, double focalMm, double pixelUm) { return focalMm == 0 ? 0 : (altM * pixelUm) / (focalMm * 1000.0); }
inline double groundWidth(double pixels, double gsd) { return pixels * gsd; }
} // namespace

namespace afrilang::runtime::giskit395 {
inline double tileRow(double lat, double z) { { double n = std::pow(2.0, z); double latR = lat * 3.141592653589793 / 180.0; return std::floor((1.0 - std::log(std::tan(latR) + 1.0 / std::cos(latR)) / 3.141592653589793) / 2.0 * n); } }
inline double tileCol(double lon, double z) { { double n = std::pow(2.0, z); return std::floor((lon + 180.0) / 360.0 * n); } }
} // namespace

namespace afrilang::runtime::giskit396 {
inline double utmZone(double lon) { return std::floor((lon + 180.0) / 6.0) + 1.0; }
inline bool isNorthernHemisphere(double lat) { return lat >= 0.0; }
} // namespace

namespace afrilang::runtime::giskit397 {
inline double planarDist(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return std::sqrt(dx*dx+dy*dy); }
inline double planarDist2(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy; }
} // namespace

namespace afrilang::runtime::giskit398 {
inline double percentSlope(double rise, double run) { return run == 0 ? 0 : (rise / run) * 100.0; }
inline double degreeSlope(double rise, double run) { return run == 0 ? 0 : std::atan(rise / run) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::giskit399 {
inline double tileOriginX(double tileCol, double tileSize) { return tileCol * tileSize * 6.000000; }
inline double tileOriginY(double tileRow, double tileSize) { return tileRow * tileSize * 6.000000; }
} // namespace

namespace afrilang::runtime::giskit400 {
inline double haversineKm(double lat1, double lon1, double lat2, double lon2) { { double R=6371.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
inline double haversineM(double lat1, double lon1, double lat2, double lon2) { { double R=6371000.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
} // namespace

namespace afrilang::runtime::giskit401 {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad=[](double d){return d*3.141592653589793/180.0;}; double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline double azimuthDiff(double a, double b) { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }
} // namespace

namespace afrilang::runtime::giskit402 {
inline double bboxWidth(double minX, double minY, double maxX, double maxY) { return maxX - minX; }
inline double bboxArea(double minX, double minY, double maxX, double maxY) { return std::fabs(maxX - minX) * std::fabs(maxY - minY); }
} // namespace

namespace afrilang::runtime::giskit403 {
inline double bboxCenterX(double minX, double minY, double maxX, double maxY) { return (minX + maxX) / 2.0; }
inline double bboxCenterY(double minX, double minY, double maxX, double maxY) { return (minY + maxY) / 2.0; }
} // namespace

namespace afrilang::runtime::giskit404 {
inline bool pointInBbox(double x, double y, double minX, double minY, double maxX, double maxY) { return x >= minX && x <= maxX && y >= minY && y <= maxY; }
inline double degToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace

namespace afrilang::runtime::giskit405 {
inline double mToKm(double m) { return m / 1000.0; }
inline double kmToM(double km) { return km * 1000.0; }
} // namespace

namespace afrilang::runtime::giskit406 {
inline double normalizeLon(double lon) { return std::fmod(std::fmod(lon + 180.0, 360.0) + 360.0, 360.0) - 180.0; }
inline double clampLat(double lat) { return lat < -90.0 ? -90.0 : (lat > 90.0 ? 90.0 : lat); }
} // namespace

namespace afrilang::runtime::giskit407 {
inline double pixelIndex(double row, double col, double width) { return row * width + col; }
inline double geoToPixelX(double x, double originX, double resX) { return resX == 0 ? 0 : (x - originX) / resX; }
} // namespace

namespace afrilang::runtime::giskit408 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.4500+g*0.6100+b*0.2)/(1.2600); }
} // namespace

namespace afrilang::runtime::giskit409 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.4600+g*0.6220+b*0.2)/(1.2820); }
} // namespace

namespace afrilang::runtime::giskit410 {
inline double gsdFromAltitude(double altM, double focalMm, double pixelUm) { return focalMm == 0 ? 0 : (altM * pixelUm) / (focalMm * 1000.0); }
inline double groundWidth(double pixels, double gsd) { return pixels * gsd; }
} // namespace

namespace afrilang::runtime::giskit411 {
inline double tileRow(double lat, double z) { { double n = std::pow(2.0, z); double latR = lat * 3.141592653589793 / 180.0; return std::floor((1.0 - std::log(std::tan(latR) + 1.0 / std::cos(latR)) / 3.141592653589793) / 2.0 * n); } }
inline double tileCol(double lon, double z) { { double n = std::pow(2.0, z); return std::floor((lon + 180.0) / 360.0 * n); } }
} // namespace

namespace afrilang::runtime::giskit412 {
inline double utmZone(double lon) { return std::floor((lon + 180.0) / 6.0) + 1.0; }
inline bool isNorthernHemisphere(double lat) { return lat >= 0.0; }
} // namespace

namespace afrilang::runtime::giskit413 {
inline double planarDist(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return std::sqrt(dx*dx+dy*dy); }
inline double planarDist2(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy; }
} // namespace

namespace afrilang::runtime::giskit414 {
inline double percentSlope(double rise, double run) { return run == 0 ? 0 : (rise / run) * 100.0; }
inline double degreeSlope(double rise, double run) { return run == 0 ? 0 : std::atan(rise / run) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::giskit415 {
inline double tileOriginX(double tileCol, double tileSize) { return tileCol * tileSize * 2.750000; }
inline double tileOriginY(double tileRow, double tileSize) { return tileRow * tileSize * 2.750000; }
} // namespace

namespace afrilang::runtime::giskit416 {
inline double haversineKm(double lat1, double lon1, double lat2, double lon2) { { double R=6371.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
inline double haversineM(double lat1, double lon1, double lat2, double lon2) { { double R=6371000.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
} // namespace

namespace afrilang::runtime::giskit417 {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad=[](double d){return d*3.141592653589793/180.0;}; double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline double azimuthDiff(double a, double b) { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }
} // namespace

namespace afrilang::runtime::giskit418 {
inline double bboxWidth(double minX, double minY, double maxX, double maxY) { return maxX - minX; }
inline double bboxArea(double minX, double minY, double maxX, double maxY) { return std::fabs(maxX - minX) * std::fabs(maxY - minY); }
} // namespace

namespace afrilang::runtime::giskit419 {
inline double bboxCenterX(double minX, double minY, double maxX, double maxY) { return (minX + maxX) / 2.0; }
inline double bboxCenterY(double minX, double minY, double maxX, double maxY) { return (minY + maxY) / 2.0; }
} // namespace

namespace afrilang::runtime::giskit420 {
inline bool pointInBbox(double x, double y, double minX, double minY, double maxX, double maxY) { return x >= minX && x <= maxX && y >= minY && y <= maxY; }
inline double degToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace

namespace afrilang::runtime::giskit421 {
inline double mToKm(double m) { return m / 1000.0; }
inline double kmToM(double km) { return km * 1000.0; }
} // namespace

namespace afrilang::runtime::giskit422 {
inline double normalizeLon(double lon) { return std::fmod(std::fmod(lon + 180.0, 360.0) + 360.0, 360.0) - 180.0; }
inline double clampLat(double lat) { return lat < -90.0 ? -90.0 : (lat > 90.0 ? 90.0 : lat); }
} // namespace

namespace afrilang::runtime::giskit423 {
inline double pixelIndex(double row, double col, double width) { return row * width + col; }
inline double geoToPixelX(double x, double originX, double resX) { return resX == 0 ? 0 : (x - originX) / resX; }
} // namespace

namespace afrilang::runtime::giskit424 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.6100+g*0.6460+b*0.2)/(1.4560); }
} // namespace

namespace afrilang::runtime::giskit425 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.4500+g*0.6580+b*0.2)/(1.3080); }
} // namespace

namespace afrilang::runtime::giskit426 {
inline double gsdFromAltitude(double altM, double focalMm, double pixelUm) { return focalMm == 0 ? 0 : (altM * pixelUm) / (focalMm * 1000.0); }
inline double groundWidth(double pixels, double gsd) { return pixels * gsd; }
} // namespace

namespace afrilang::runtime::giskit427 {
inline double tileRow(double lat, double z) { { double n = std::pow(2.0, z); double latR = lat * 3.141592653589793 / 180.0; return std::floor((1.0 - std::log(std::tan(latR) + 1.0 / std::cos(latR)) / 3.141592653589793) / 2.0 * n); } }
inline double tileCol(double lon, double z) { { double n = std::pow(2.0, z); return std::floor((lon + 180.0) / 360.0 * n); } }
} // namespace

namespace afrilang::runtime::giskit428 {
inline double utmZone(double lon) { return std::floor((lon + 180.0) / 6.0) + 1.0; }
inline bool isNorthernHemisphere(double lat) { return lat >= 0.0; }
} // namespace

namespace afrilang::runtime::giskit429 {
inline double planarDist(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return std::sqrt(dx*dx+dy*dy); }
inline double planarDist2(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy; }
} // namespace

namespace afrilang::runtime::giskit430 {
inline double percentSlope(double rise, double run) { return run == 0 ? 0 : (rise / run) * 100.0; }
inline double degreeSlope(double rise, double run) { return run == 0 ? 0 : std::atan(rise / run) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::giskit431 {
inline double tileOriginX(double tileCol, double tileSize) { return tileCol * tileSize * 6.750000; }
inline double tileOriginY(double tileRow, double tileSize) { return tileRow * tileSize * 6.750000; }
} // namespace

namespace afrilang::runtime::giskit432 {
inline double haversineKm(double lat1, double lon1, double lat2, double lon2) { { double R=6371.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
inline double haversineM(double lat1, double lon1, double lat2, double lon2) { { double R=6371000.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
} // namespace

namespace afrilang::runtime::giskit433 {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad=[](double d){return d*3.141592653589793/180.0;}; double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline double azimuthDiff(double a, double b) { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }
} // namespace

namespace afrilang::runtime::giskit434 {
inline double bboxWidth(double minX, double minY, double maxX, double maxY) { return maxX - minX; }
inline double bboxArea(double minX, double minY, double maxX, double maxY) { return std::fabs(maxX - minX) * std::fabs(maxY - minY); }
} // namespace

namespace afrilang::runtime::giskit435 {
inline double bboxCenterX(double minX, double minY, double maxX, double maxY) { return (minX + maxX) / 2.0; }
inline double bboxCenterY(double minX, double minY, double maxX, double maxY) { return (minY + maxY) / 2.0; }
} // namespace

namespace afrilang::runtime::giskit436 {
inline bool pointInBbox(double x, double y, double minX, double minY, double maxX, double maxY) { return x >= minX && x <= maxX && y >= minY && y <= maxY; }
inline double degToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace

namespace afrilang::runtime::giskit437 {
inline double mToKm(double m) { return m / 1000.0; }
inline double kmToM(double km) { return km * 1000.0; }
} // namespace

namespace afrilang::runtime::giskit438 {
inline double normalizeLon(double lon) { return std::fmod(std::fmod(lon + 180.0, 360.0) + 360.0, 360.0) - 180.0; }
inline double clampLat(double lat) { return lat < -90.0 ? -90.0 : (lat > 90.0 ? 90.0 : lat); }
} // namespace

namespace afrilang::runtime::giskit439 {
inline double pixelIndex(double row, double col, double width) { return row * width + col; }
inline double geoToPixelX(double x, double originX, double resX) { return resX == 0 ? 0 : (x - originX) / resX; }
} // namespace

namespace afrilang::runtime::giskit440 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.6000+g*0.6820+b*0.2)/(1.4820); }
} // namespace

namespace afrilang::runtime::giskit441 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.6100+g*0.6940+b*0.2)/(1.5040); }
} // namespace

namespace afrilang::runtime::giskit442 {
inline double gsdFromAltitude(double altM, double focalMm, double pixelUm) { return focalMm == 0 ? 0 : (altM * pixelUm) / (focalMm * 1000.0); }
inline double groundWidth(double pixels, double gsd) { return pixels * gsd; }
} // namespace

namespace afrilang::runtime::giskit443 {
inline double tileRow(double lat, double z) { { double n = std::pow(2.0, z); double latR = lat * 3.141592653589793 / 180.0; return std::floor((1.0 - std::log(std::tan(latR) + 1.0 / std::cos(latR)) / 3.141592653589793) / 2.0 * n); } }
inline double tileCol(double lon, double z) { { double n = std::pow(2.0, z); return std::floor((lon + 180.0) / 360.0 * n); } }
} // namespace

namespace afrilang::runtime::giskit444 {
inline double utmZone(double lon) { return std::floor((lon + 180.0) / 6.0) + 1.0; }
inline bool isNorthernHemisphere(double lat) { return lat >= 0.0; }
} // namespace

namespace afrilang::runtime::giskit445 {
inline double planarDist(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return std::sqrt(dx*dx+dy*dy); }
inline double planarDist2(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy; }
} // namespace

namespace afrilang::runtime::giskit446 {
inline double percentSlope(double rise, double run) { return run == 0 ? 0 : (rise / run) * 100.0; }
inline double degreeSlope(double rise, double run) { return run == 0 ? 0 : std::atan(rise / run) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::giskit447 {
inline double tileOriginX(double tileCol, double tileSize) { return tileCol * tileSize * 3.500000; }
inline double tileOriginY(double tileRow, double tileSize) { return tileRow * tileSize * 3.500000; }
} // namespace

namespace afrilang::runtime::giskit448 {
inline double haversineKm(double lat1, double lon1, double lat2, double lon2) { { double R=6371.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
inline double haversineM(double lat1, double lon1, double lat2, double lon2) { { double R=6371000.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
} // namespace

namespace afrilang::runtime::giskit449 {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad=[](double d){return d*3.141592653589793/180.0;}; double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline double azimuthDiff(double a, double b) { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }
} // namespace

namespace afrilang::runtime::giskit450 {
inline double bboxWidth(double minX, double minY, double maxX, double maxY) { return maxX - minX; }
inline double bboxArea(double minX, double minY, double maxX, double maxY) { return std::fabs(maxX - minX) * std::fabs(maxY - minY); }
} // namespace

namespace afrilang::runtime::giskit451 {
inline double bboxCenterX(double minX, double minY, double maxX, double maxY) { return (minX + maxX) / 2.0; }
inline double bboxCenterY(double minX, double minY, double maxX, double maxY) { return (minY + maxY) / 2.0; }
} // namespace

namespace afrilang::runtime::giskit452 {
inline bool pointInBbox(double x, double y, double minX, double minY, double maxX, double maxY) { return x >= minX && x <= maxX && y >= minY && y <= maxY; }
inline double degToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace

namespace afrilang::runtime::giskit453 {
inline double mToKm(double m) { return m / 1000.0; }
inline double kmToM(double km) { return km * 1000.0; }
} // namespace

namespace afrilang::runtime::giskit454 {
inline double normalizeLon(double lon) { return std::fmod(std::fmod(lon + 180.0, 360.0) + 360.0, 360.0) - 180.0; }
inline double clampLat(double lat) { return lat < -90.0 ? -90.0 : (lat > 90.0 ? 90.0 : lat); }
} // namespace

namespace afrilang::runtime::giskit455 {
inline double pixelIndex(double row, double col, double width) { return row * width + col; }
inline double geoToPixelX(double x, double originX, double resX) { return resX == 0 ? 0 : (x - originX) / resX; }
} // namespace

namespace afrilang::runtime::giskit456 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5900+g*0.5620+b*0.2)/(1.3520); }
} // namespace

namespace afrilang::runtime::giskit457 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.6000+g*0.5740+b*0.2)/(1.3740); }
} // namespace

namespace afrilang::runtime::giskit458 {
inline double gsdFromAltitude(double altM, double focalMm, double pixelUm) { return focalMm == 0 ? 0 : (altM * pixelUm) / (focalMm * 1000.0); }
inline double groundWidth(double pixels, double gsd) { return pixels * gsd; }
} // namespace

namespace afrilang::runtime::giskit459 {
inline double tileRow(double lat, double z) { { double n = std::pow(2.0, z); double latR = lat * 3.141592653589793 / 180.0; return std::floor((1.0 - std::log(std::tan(latR) + 1.0 / std::cos(latR)) / 3.141592653589793) / 2.0 * n); } }
inline double tileCol(double lon, double z) { { double n = std::pow(2.0, z); return std::floor((lon + 180.0) / 360.0 * n); } }
} // namespace

namespace afrilang::runtime::giskit460 {
inline double utmZone(double lon) { return std::floor((lon + 180.0) / 6.0) + 1.0; }
inline bool isNorthernHemisphere(double lat) { return lat >= 0.0; }
} // namespace

namespace afrilang::runtime::giskit461 {
inline double planarDist(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return std::sqrt(dx*dx+dy*dy); }
inline double planarDist2(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy; }
} // namespace

namespace afrilang::runtime::giskit462 {
inline double percentSlope(double rise, double run) { return run == 0 ? 0 : (rise / run) * 100.0; }
inline double degreeSlope(double rise, double run) { return run == 0 ? 0 : std::atan(rise / run) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::giskit463 {
inline double tileOriginX(double tileCol, double tileSize) { return tileCol * tileSize * 7.500000; }
inline double tileOriginY(double tileRow, double tileSize) { return tileRow * tileSize * 7.500000; }
} // namespace

namespace afrilang::runtime::giskit464 {
inline double haversineKm(double lat1, double lon1, double lat2, double lon2) { { double R=6371.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
inline double haversineM(double lat1, double lon1, double lat2, double lon2) { { double R=6371000.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
} // namespace

namespace afrilang::runtime::giskit465 {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad=[](double d){return d*3.141592653589793/180.0;}; double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline double azimuthDiff(double a, double b) { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }
} // namespace

namespace afrilang::runtime::giskit466 {
inline double bboxWidth(double minX, double minY, double maxX, double maxY) { return maxX - minX; }
inline double bboxArea(double minX, double minY, double maxX, double maxY) { return std::fabs(maxX - minX) * std::fabs(maxY - minY); }
} // namespace

namespace afrilang::runtime::giskit467 {
inline double bboxCenterX(double minX, double minY, double maxX, double maxY) { return (minX + maxX) / 2.0; }
inline double bboxCenterY(double minX, double minY, double maxX, double maxY) { return (minY + maxY) / 2.0; }
} // namespace

namespace afrilang::runtime::giskit468 {
inline bool pointInBbox(double x, double y, double minX, double minY, double maxX, double maxY) { return x >= minX && x <= maxX && y >= minY && y <= maxY; }
inline double degToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace

namespace afrilang::runtime::giskit469 {
inline double mToKm(double m) { return m / 1000.0; }
inline double kmToM(double km) { return km * 1000.0; }
} // namespace

namespace afrilang::runtime::giskit470 {
inline double normalizeLon(double lon) { return std::fmod(std::fmod(lon + 180.0, 360.0) + 360.0, 360.0) - 180.0; }
inline double clampLat(double lat) { return lat < -90.0 ? -90.0 : (lat > 90.0 ? 90.0 : lat); }
} // namespace

namespace afrilang::runtime::giskit471 {
inline double pixelIndex(double row, double col, double width) { return row * width + col; }
inline double geoToPixelX(double x, double originX, double resX) { return resX == 0 ? 0 : (x - originX) / resX; }
} // namespace

namespace afrilang::runtime::giskit472 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5800+g*0.5980+b*0.2)/(1.3780); }
} // namespace

namespace afrilang::runtime::giskit473 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5900+g*0.6100+b*0.2)/(1.4000); }
} // namespace

namespace afrilang::runtime::giskit474 {
inline double gsdFromAltitude(double altM, double focalMm, double pixelUm) { return focalMm == 0 ? 0 : (altM * pixelUm) / (focalMm * 1000.0); }
inline double groundWidth(double pixels, double gsd) { return pixels * gsd; }
} // namespace

namespace afrilang::runtime::giskit475 {
inline double tileRow(double lat, double z) { { double n = std::pow(2.0, z); double latR = lat * 3.141592653589793 / 180.0; return std::floor((1.0 - std::log(std::tan(latR) + 1.0 / std::cos(latR)) / 3.141592653589793) / 2.0 * n); } }
inline double tileCol(double lon, double z) { { double n = std::pow(2.0, z); return std::floor((lon + 180.0) / 360.0 * n); } }
} // namespace

namespace afrilang::runtime::giskit476 {
inline double utmZone(double lon) { return std::floor((lon + 180.0) / 6.0) + 1.0; }
inline bool isNorthernHemisphere(double lat) { return lat >= 0.0; }
} // namespace

namespace afrilang::runtime::giskit477 {
inline double planarDist(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return std::sqrt(dx*dx+dy*dy); }
inline double planarDist2(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy; }
} // namespace

namespace afrilang::runtime::giskit478 {
inline double percentSlope(double rise, double run) { return run == 0 ? 0 : (rise / run) * 100.0; }
inline double degreeSlope(double rise, double run) { return run == 0 ? 0 : std::atan(rise / run) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::giskit479 {
inline double tileOriginX(double tileCol, double tileSize) { return tileCol * tileSize * 4.250000; }
inline double tileOriginY(double tileRow, double tileSize) { return tileRow * tileSize * 4.250000; }
} // namespace

namespace afrilang::runtime::giskit480 {
inline double haversineKm(double lat1, double lon1, double lat2, double lon2) { { double R=6371.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
inline double haversineM(double lat1, double lon1, double lat2, double lon2) { { double R=6371000.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
} // namespace

namespace afrilang::runtime::giskit481 {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad=[](double d){return d*3.141592653589793/180.0;}; double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline double azimuthDiff(double a, double b) { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }
} // namespace

namespace afrilang::runtime::giskit482 {
inline double bboxWidth(double minX, double minY, double maxX, double maxY) { return maxX - minX; }
inline double bboxArea(double minX, double minY, double maxX, double maxY) { return std::fabs(maxX - minX) * std::fabs(maxY - minY); }
} // namespace

namespace afrilang::runtime::giskit483 {
inline double bboxCenterX(double minX, double minY, double maxX, double maxY) { return (minX + maxX) / 2.0; }
inline double bboxCenterY(double minX, double minY, double maxX, double maxY) { return (minY + maxY) / 2.0; }
} // namespace

namespace afrilang::runtime::giskit484 {
inline bool pointInBbox(double x, double y, double minX, double minY, double maxX, double maxY) { return x >= minX && x <= maxX && y >= minY && y <= maxY; }
inline double degToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace

namespace afrilang::runtime::giskit485 {
inline double mToKm(double m) { return m / 1000.0; }
inline double kmToM(double km) { return km * 1000.0; }
} // namespace

namespace afrilang::runtime::giskit486 {
inline double normalizeLon(double lon) { return std::fmod(std::fmod(lon + 180.0, 360.0) + 360.0, 360.0) - 180.0; }
inline double clampLat(double lat) { return lat < -90.0 ? -90.0 : (lat > 90.0 ? 90.0 : lat); }
} // namespace

namespace afrilang::runtime::giskit487 {
inline double pixelIndex(double row, double col, double width) { return row * width + col; }
inline double geoToPixelX(double x, double originX, double resX) { return resX == 0 ? 0 : (x - originX) / resX; }
} // namespace

namespace afrilang::runtime::giskit488 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5700+g*0.6340+b*0.2)/(1.4040); }
} // namespace

namespace afrilang::runtime::giskit489 {
inline double ndvi(double nir, double red) { double d=nir+red; return d==0?0:(nir-red)/d; }
inline double brightness(double r, double g, double b) { return (r*0.5800+g*0.6460+b*0.2)/(1.4260); }
} // namespace

namespace afrilang::runtime::giskit490 {
inline double gsdFromAltitude(double altM, double focalMm, double pixelUm) { return focalMm == 0 ? 0 : (altM * pixelUm) / (focalMm * 1000.0); }
inline double groundWidth(double pixels, double gsd) { return pixels * gsd; }
} // namespace

namespace afrilang::runtime::giskit491 {
inline double tileRow(double lat, double z) { { double n = std::pow(2.0, z); double latR = lat * 3.141592653589793 / 180.0; return std::floor((1.0 - std::log(std::tan(latR) + 1.0 / std::cos(latR)) / 3.141592653589793) / 2.0 * n); } }
inline double tileCol(double lon, double z) { { double n = std::pow(2.0, z); return std::floor((lon + 180.0) / 360.0 * n); } }
} // namespace

namespace afrilang::runtime::giskit492 {
inline double utmZone(double lon) { return std::floor((lon + 180.0) / 6.0) + 1.0; }
inline bool isNorthernHemisphere(double lat) { return lat >= 0.0; }
} // namespace

namespace afrilang::runtime::giskit493 {
inline double planarDist(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return std::sqrt(dx*dx+dy*dy); }
inline double planarDist2(double x1, double y1, double x2, double y2) { double dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy; }
} // namespace

namespace afrilang::runtime::giskit494 {
inline double percentSlope(double rise, double run) { return run == 0 ? 0 : (rise / run) * 100.0; }
inline double degreeSlope(double rise, double run) { return run == 0 ? 0 : std::atan(rise / run) * 180.0 / 3.141592653589793; }
} // namespace

namespace afrilang::runtime::giskit495 {
inline double tileOriginX(double tileCol, double tileSize) { return tileCol * tileSize * 1.000000; }
inline double tileOriginY(double tileRow, double tileSize) { return tileRow * tileSize * 1.000000; }
} // namespace

namespace afrilang::runtime::giskit496 {
inline double haversineKm(double lat1, double lon1, double lat2, double lon2) { { double R=6371.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
inline double haversineM(double lat1, double lon1, double lat2, double lon2) { { double R=6371000.0; auto rad=[](double d){return d*3.141592653589793/180.0;}; double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); } }
} // namespace

namespace afrilang::runtime::giskit497 {
inline double bearingDeg(double lat1, double lon1, double lat2, double lon2) { { auto rad=[](double d){return d*3.141592653589793/180.0;}; double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); } }
inline double azimuthDiff(double a, double b) { double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }
} // namespace

namespace afrilang::runtime::giskit498 {
inline double bboxWidth(double minX, double minY, double maxX, double maxY) { return maxX - minX; }
inline double bboxArea(double minX, double minY, double maxX, double maxY) { return std::fabs(maxX - minX) * std::fabs(maxY - minY); }
} // namespace

namespace afrilang::runtime::giskit499 {
inline double bboxCenterX(double minX, double minY, double maxX, double maxY) { return (minX + maxX) / 2.0; }
inline double bboxCenterY(double minX, double minY, double maxX, double maxY) { return (minY + maxY) / 2.0; }
} // namespace

namespace afrilang::runtime::giskit500 {
inline bool pointInBbox(double x, double y, double minX, double minY, double maxX, double maxY) { return x >= minX && x <= maxX && y >= minY && y <= maxY; }
inline double degToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace
