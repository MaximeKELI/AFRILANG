#!/usr/bin/env python3
"""Generate simple stdlib catalog (100+ modules) and C++ runtime."""

from __future__ import annotations
import os
import textwrap

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

# Each module: (import_name, use_name, [(func, ret, [(param, type), ...], cpp_body), ...])
MODULES: list[tuple] = [
    ("absnum", "absnum", [
        ("absNumber", "number", [("n", "number")], "return std::fabs(n);"),
        ("absDiff", "number", [("a", "number"), ("b", "number")], "return std::fabs(a - b);"),
    ]),
    ("sqrtlib", "sqrtlib", [
        ("sqrtNumber", "number", [("n", "number")], "return std::sqrt(n);"),
        ("square", "number", [("n", "number")], "return n * n;"),
    ]),
    ("cbrtlib", "cbrtlib", [
        ("cbrtNumber", "number", [("n", "number")], "return std::cbrt(n);"),
        ("cube", "number", [("n", "number")], "return n * n * n;"),
    ]),
    ("min2", "min2", [
        ("min2", "number", [("a", "number"), ("b", "number")], "return a < b ? a : b;"),
        ("min3", "number", [("a", "number"), ("b", "number"), ("c", "number")], "return std::min({a, b, c});"),
    ]),
    ("max2", "max2", [
        ("max2", "number", [("a", "number"), ("b", "number")], "return a > b ? a : b;"),
        ("max3", "number", [("a", "number"), ("b", "number"), ("c", "number")], "return std::max({a, b, c});"),
    ]),
    ("clamp", "clamp", [
        ("clamp", "number", [("n", "number"), ("lo", "number"), ("hi", "number")], "return n < lo ? lo : (n > hi ? hi : n);"),
        ("clamp01", "number", [("n", "number")], "return n < 0 ? 0 : (n > 1 ? 1 : n);"),
    ]),
    ("lerp", "lerp", [
        ("lerp", "number", [("a", "number"), ("b", "number"), ("t", "number")], "return a + (b - a) * t;"),
        ("inverseLerp", "number", [("a", "number"), ("b", "number"), ("v", "number")], "return (b == a) ? 0 : (v - a) / (b - a);"),
    ]),
    ("sign", "sign", [
        ("sign", "number", [("n", "number")], "return n > 0 ? 1 : (n < 0 ? -1 : 0);"),
        ("isPositive", "bool", [("n", "number")], "return n > 0;"),
    ]),
    ("parity", "parity", [
        ("isEven", "bool", [("n", "number")], "return static_cast<long long>(n) % 2 == 0;"),
        ("isOdd", "bool", [("n", "number")], "return static_cast<long long>(n) % 2 != 0;"),
    ]),
    ("trig", "trig", [
        ("sinDeg", "number", [("deg", "number")], "return std::sin(deg * 3.141592653589793 / 180.0);"),
        ("cosDeg", "number", [("deg", "number")], "return std::cos(deg * 3.141592653589793 / 180.0);"),
    ]),
    ("trig2", "trig2", [
        ("tanDeg", "number", [("deg", "number")], "return std::tan(deg * 3.141592653589793 / 180.0);"),
        ("cotDeg", "number", [("deg", "number")], "return 1.0 / std::tan(deg * 3.141592653589793 / 180.0);"),
    ]),
    ("arc", "arc", [
        ("asinSafe", "number", [("n", "number")], "return std::asin(n < -1 ? -1 : (n > 1 ? 1 : n));"),
        ("acosSafe", "number", [("n", "number")], "return std::acos(n < -1 ? -1 : (n > 1 ? 1 : n));"),
    ]),
    ("hyper", "hyper", [
        ("sinhN", "number", [("n", "number")], "return std::sinh(n);"),
        ("coshN", "number", [("n", "number")], "return std::cosh(n);"),
    ]),
    ("deg", "deg", [
        ("degToRad", "number", [("d", "number")], "return d * 3.141592653589793 / 180.0;"),
        ("radToDeg", "number", [("r", "number")], "return r * 180.0 / 3.141592653589793;"),
    ]),
    ("roundlib", "roundlib", [
        ("roundN", "number", [("n", "number")], "return std::round(n);"),
        ("truncN", "number", [("n", "number")], "return std::trunc(n);"),
    ]),
    ("modlib", "modlib", [
        ("mod", "number", [("a", "number"), ("b", "number")], "return b == 0 ? 0 : std::fmod(a, b);"),
        ("wrap", "number", [("n", "number"), ("lo", "number"), ("hi", "number")], "return lo + std::fmod(n - lo, hi - lo);"),
    ]),
    ("gcdlib", "gcdlib", [
        ("gcd", "number", [("a", "number"), ("b", "number")], "{ long long x = std::llabs(static_cast<long long>(a)); long long y = std::llabs(static_cast<long long>(b)); while (y) { long long t = x % y; x = y; y = t; } return static_cast<double>(x); }"),
        ("lcm", "number", [("a", "number"), ("b", "number")], "{ double g = gcd(a, b); return g == 0 ? 0 : std::fabs(a * b / g); }"),
    ]),
    ("fact", "fact", [
        ("factorial", "number", [("n", "number")], "{ long long r = 1; for (long long i = 2; i <= static_cast<long long>(n); ++i) r *= i; return static_cast<double>(r); }"),
        ("doubleFact", "number", [("n", "number")], "{ double r = 1; for (long long i = static_cast<long long>(n); i > 0; i -= 2) r *= i; return r; }"),
    ]),
    ("fib", "fib", [
        ("fib", "number", [("n", "number")], "{ long long a = 0, b = 1; for (long long i = 0; i < static_cast<long long>(n); ++i) { long long t = a + b; a = b; b = t; } return static_cast<double>(a); }"),
        ("fibB", "number", [("n", "number")], "{ long long a = 0, b = 1; for (long long i = 0; i < static_cast<long long>(n); ++i) { long long t = a + b; a = b; b = t; } return static_cast<double>(b); }"),
    ]),
    ("prime", "prime", [
        ("isPrime", "bool", [("n", "number")], "{ long long v = static_cast<long long>(n); if (v < 2) return false; for (long long i = 2; i * i <= v; ++i) if (v % i == 0) return false; return true; }"),
        ("nextPrime", "number", [("n", "number")], "{ long long v = static_cast<long long>(n) + 1; while (!isPrime(static_cast<double>(v))) ++v; return static_cast<double>(v); }"),
    ]),
    ("mean", "mean", [
        ("mean2", "number", [("a", "number"), ("b", "number")], "return (a + b) / 2.0;"),
        ("mean3", "number", [("a", "number"), ("b", "number"), ("c", "number")], "return (a + b + c) / 3.0;"),
    ]),
    ("percent", "percent", [
        ("percent", "number", [("part", "number"), ("whole", "number")], "return whole == 0 ? 0 : (part / whole) * 100.0;"),
        ("percentChange", "number", [("oldVal", "number"), ("newVal", "number")], "return oldVal == 0 ? 0 : ((newVal - oldVal) / oldVal) * 100.0;"),
    ]),
    ("ratio", "ratio", [
        ("ratio", "number", [("a", "number"), ("b", "number")], "return b == 0 ? 0 : a / b;"),
        ("proportion", "number", [("a", "number"), ("b", "number"), ("total", "number")], "return (a + b) == 0 ? 0 : total * a / (a + b);"),
    ]),
    ("dice", "dice", [
        ("roll", "number", [("sides", "number")], "return sides <= 0 ? 0 : (std::rand() % static_cast<int>(sides)) + 1;"),
        ("roll2d6", "number", [("ignored", "number")], "(void)ignored; return (std::rand() % 6 + 1) + (std::rand() % 6 + 1);"),
    ]),
    ("coin", "coin", [
        ("flip", "bool", [("ignored", "number")], "(void)ignored; return std::rand() % 2 == 0;"),
        ("flipN", "number", [("n", "number")], "{ int heads = 0; for (int i = 0; i < static_cast<int>(n); ++i) if (std::rand() % 2 == 0) ++heads; return heads; }"),
    ]),
    ("upper", "upper", [
        ("toUpper", "text", [("s", "text")], "{ std::string r = s; for (char& c : r) c = static_cast<char>(std::toupper(static_cast<unsigned char>(c))); return r; }"),
        ("toLower", "text", [("s", "text")], "{ std::string r = s; for (char& c : r) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c))); return r; }"),
    ]),
    ("capitalize", "capitalize", [
        ("capitalize", "text", [("s", "text")], "return s.empty() ? s : std::string(1, static_cast<char>(std::toupper(static_cast<unsigned char>(s[0])))) + s.substr(1);"),
        ("titleWord", "text", [("s", "text")], "return capitalize(s);"),
    ]),
    ("prefix", "prefix", [
        ("startsWith", "bool", [("s", "text"), ("prefix", "text")], "return s.rfind(prefix, 0) == 0;"),
        ("endsWith", "bool", [("s", "text"), ("suffix", "text")], "return s.size() >= suffix.size() && s.compare(s.size() - suffix.size(), suffix.size(), suffix) == 0;"),
    ]),
    ("repeat", "repeat", [
        ("repeatText", "text", [("s", "text"), ("n", "number")], "{ std::string r; for (int i = 0; i < static_cast<int>(n); ++i) r += s; return r; }"),
        ("repeatChar", "text", [("c", "text"), ("n", "number")], "return repeatText(c, n);"),
    ]),
    ("pad", "pad", [
        ("padLeft", "text", [("s", "text"), ("n", "number"), ("ch", "text")], "{ std::string r = s; while (static_cast<int>(r.size()) < static_cast<int>(n)) r = (ch.empty() ? \" \" : ch.substr(0,1)) + r; return r; }"),
        ("padRight", "text", [("s", "text"), ("n", "number"), ("ch", "text")], "{ std::string r = s; while (static_cast<int>(r.size()) < static_cast<int>(n)) r += (ch.empty() ? \" \" : ch.substr(0,1)); return r; }"),
    ]),
    ("reverse", "reverse", [
        ("reverseText", "text", [("s", "text")], "{ return std::string(s.rbegin(), s.rend()); }"),
        ("reverseWords", "text", [("s", "text")], "{ std::string r; std::string w; for (char c : s) { if (c == ' ') { if (!w.empty()) { if (!r.empty()) r = w + \" \" + r; else r = w; w.clear(); } } else w += c; } if (!w.empty()) r = r.empty() ? w : w + \" \" + r; return r; }"),
    ]),
    ("textlen", "textlen", [
        ("length", "number", [("s", "text")], "return static_cast<double>(s.size());"),
        ("isEmpty", "bool", [("s", "text")], "return s.empty();"),
    ]),
    ("concat", "concat", [
        ("concat2", "text", [("a", "text"), ("b", "text")], "return a + b;"),
        ("concat3", "text", [("a", "text"), ("b", "text"), ("c", "text")], "return a + b + c;"),
    ]),
    ("compare", "compare", [
        ("equals", "bool", [("a", "text"), ("b", "text")], "return a == b;"),
        ("equalsIgnoreCase", "bool", [("a", "text"), ("b", "text")], "{ if (a.size() != b.size()) return false; for (std::size_t i = 0; i < a.size(); ++i) if (std::tolower(static_cast<unsigned char>(a[i])) != std::tolower(static_cast<unsigned char>(b[i]))) return false; return true; }"),
    ]),
    ("celsius", "celsius", [
        ("cToF", "number", [("c", "number")], "return c * 9.0 / 5.0 + 32.0;"),
        ("fToC", "number", [("f", "number")], "return (f - 32.0) * 5.0 / 9.0;"),
    ]),
    ("kelvin", "kelvin", [
        ("cToK", "number", [("c", "number")], "return c + 273.15;"),
        ("kToC", "number", [("k", "number")], "return k - 273.15;"),
    ]),
    ("distance", "distance", [
        ("kmToMiles", "number", [("km", "number")], "return km * 0.621371;"),
        ("milesToKm", "number", [("mi", "number")], "return mi / 0.621371;"),
    ]),
    ("weight", "weight", [
        ("kgToLb", "number", [("kg", "number")], "return kg * 2.20462;"),
        ("lbToKg", "number", [("lb", "number")], "return lb / 2.20462;"),
    ]),
    ("bytes", "bytes", [
        ("bytesToKb", "number", [("b", "number")], "return b / 1024.0;"),
        ("kbToMb", "number", [("kb", "number")], "return kb / 1024.0;"),
    ]),
    ("timeconv", "timeconv", [
        ("secToMin", "number", [("s", "number")], "return s / 60.0;"),
        ("minToHour", "number", [("m", "number")], "return m / 60.0;"),
    ]),
    ("msconv", "msconv", [
        ("msToSec", "number", [("ms", "number")], "return ms / 1000.0;"),
        ("secToMs", "number", [("s", "number")], "return s * 1000.0;"),
    ]),
    ("angle", "angle", [
        ("normalizeAngle", "number", [("d", "number")], "{ double r = std::fmod(d, 360.0); return r < 0 ? r + 360.0 : r; }"),
        ("angleDiff", "number", [("a", "number"), ("b", "number")], "{ double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d; }"),
    ]),
    ("hex", "hex", [
        ("toHex", "text", [("n", "number")], "{ std::ostringstream os; os << std::hex << static_cast<long long>(n); return os.str(); }"),
        ("fromHex", "number", [("s", "text")], "{ return static_cast<double>(std::stoll(s, nullptr, 16)); }"),
    ]),
    ("binary", "binary", [
        ("toBinary", "text", [("n", "number")], "{ std::string r; long long v = static_cast<long long>(n); if (v == 0) return \"0\"; while (v) { r = char('0' + v % 2) + r; v /= 2; } return r; }"),
        ("fromBinary", "number", [("s", "text")], "return static_cast<double>(std::stoll(s, nullptr, 2));"),
    ]),
    ("octal", "octal", [
        ("toOctal", "text", [("n", "number")], "{ std::ostringstream os; os << std::oct << static_cast<long long>(n); return os.str(); }"),
        ("fromOctal", "number", [("s", "text")], "return static_cast<double>(std::stoll(s, nullptr, 8));"),
    ]),
    ("rot13", "rot13", [
        ("rot13", "text", [("s", "text")], "{ std::string r = s; for (char& c : r) { if (c >= 'a' && c <= 'z') c = char('a' + (c - 'a' + 13) % 26); else if (c >= 'A' && c <= 'Z') c = char('A' + (c - 'A' + 13) % 26); } return r; }"),
        ("rot47", "text", [("s", "text")], "{ std::string r = s; for (char& c : r) if (c >= 33 && c <= 126) c = char(33 + (c - 33 + 47) % 94); return r; }"),
    ]),
    ("hash", "hash", [
        ("hashText", "number", [("s", "text")], "{ unsigned long h = 5381; for (unsigned char c : s) h = ((h << 5) + h) + c; return static_cast<double>(h); }"),
        ("hashNumber", "number", [("n", "number")], "return hashText(std::to_string(static_cast<long long>(n)));"),
    ]),
    ("checksum", "checksum", [
        ("xorChecksum", "number", [("s", "text")], "{ unsigned char x = 0; for (unsigned char c : s) x ^= c; return static_cast<double>(x); }"),
        ("sumBytes", "number", [("s", "text")], "{ unsigned long x = 0; for (unsigned char c : s) x += c; return static_cast<double>(x); }"),
    ]),
    ("slug", "slug", [
        ("slugify", "text", [("s", "text")], "{ std::string r; for (char c : s) { if (std::isalnum(static_cast<unsigned char>(c))) r += static_cast<char>(std::tolower(static_cast<unsigned char>(c))); else if (c == ' ' || c == '-') { if (!r.empty() && r.back() != '-') r += '-'; } } while (!r.empty() && r.back() == '-') r.pop_back(); return r; }"),
        ("deslugify", "text", [("s", "text")], "{ std::string r; for (char c : s) r += (c == '-') ? ' ' : c; return r; }"),
    ]),
    ("email", "email", [
        ("isEmail", "bool", [("s", "text")], "return s.find('@') != std::string::npos && s.find('.') != std::string::npos;"),
        ("domainOf", "text", [("s", "text")], "{ auto p = s.find('@'); return p == std::string::npos ? \"\" : s.substr(p + 1); }"),
    ]),
    ("phone", "phone", [
        ("isPhone", "bool", [("s", "text")], "{ int d = 0; for (char c : s) if (std::isdigit(static_cast<unsigned char>(c))) ++d; return d >= 8; }"),
        ("digitsOnly", "text", [("s", "text")], "{ std::string r; for (char c : s) if (std::isdigit(static_cast<unsigned char>(c))) r += c; return r; }"),
    ]),
    ("ipv4", "ipv4", [
        ("isIpv4", "bool", [("s", "text")], "{ int dots = 0; for (char c : s) if (c == '.') ++dots; return dots == 3; }"),
        ("countDots", "number", [("s", "text")], "{ int d = 0; for (char c : s) if (c == '.') ++d; return d; }"),
    ]),
    ("html", "html", [
        ("escapeHtml", "text", [("s", "text")], "{ std::string r; for (char c : s) { if (c == '<') r += \"&lt;\"; else if (c == '>') r += \"&gt;\"; else if (c == '&') r += \"&amp;\"; else r += c; } return r; }"),
        ("unescapeHtml", "text", [("s", "text")], "return s;"),
    ]),
    ("point", "point", [
        ("distance2d", "number", [("x1", "number"), ("y1", "number"), ("x2", "number"), ("y2", "number")], "return std::hypot(x2 - x1, y2 - y1);"),
        ("midpointX", "number", [("x1", "number"), ("x2", "number")], "return (x1 + x2) / 2.0;"),
    ]),
    ("rect", "rect", [
        ("area", "number", [("w", "number"), ("h", "number")], "return w * h;"),
        ("perimeter", "number", [("w", "number"), ("h", "number")], "return 2.0 * (w + h);"),
    ]),
    ("circle", "circle", [
        ("area", "number", [("r", "number")], "return 3.141592653589793 * r * r;"),
        ("circumference", "number", [("r", "number")], "return 2.0 * 3.141592653589793 * r;"),
    ]),
    ("triangle", "triangle", [
        ("areaBaseHeight", "number", [("b", "number"), ("h", "number")], "return 0.5 * b * h;"),
        ("heron", "number", [("a", "number"), ("b", "number"), ("c", "number")], "{ double s = (a + b + c) / 2.0; return std::sqrt(s * (s - a) * (s - b) * (s - c)); }"),
    ]),
    ("vector2", "vector2", [
        ("dot2", "number", [("x1", "number"), ("y1", "number"), ("x2", "number"), ("y2", "number")], "return x1 * x2 + y1 * y2;"),
        ("length2", "number", [("x", "number"), ("y", "number")], "return std::hypot(x, y);"),
    ]),
    ("collision", "collision", [
        ("pointInRect", "bool", [("px", "number"), ("py", "number"), ("rx", "number"), ("ry", "number"), ("rw", "number"), ("rh", "number")], "return px >= rx && px < rx + rw && py >= ry && py < ry + rh;"),
        ("rectsOverlap", "bool", [("x1", "number"), ("y1", "number"), ("w1", "number"), ("h1", "number"), ("x2", "number"), ("y2", "number"), ("w2", "number"), ("h2", "number")], "return !(x1 + w1 <= x2 || x2 + w2 <= x1 || y1 + h1 <= y2 || y2 + h2 <= y1);"),
    ]),
    ("color", "color", [
        ("rgb", "number", [("r", "number"), ("g", "number"), ("b", "number")], "return r * 65536 + g * 256 + b;"),
        ("redOf", "number", [("packed", "number")], "return static_cast<long long>(packed) / 65536 % 256;"),
    ]),
    ("easing", "easing", [
        ("easeIn", "number", [("t", "number")], "return t * t;"),
        ("easeOut", "number", [("t", "number")], "return t * (2.0 - t);"),
    ]),
    ("noise", "noise", [
        ("noise1D", "number", [("x", "number")], "{ unsigned long n = static_cast<unsigned long>(x * 1000); n = (n << 13) ^ n; return static_cast<double>((n * (n * n * 15731 + 789221) + 1376312589) & 0x7fffffff) / 2147483647.0; }"),
        ("noise2D", "number", [("x", "number"), ("y", "number")], "return noise1D(x + y * 57.0);"),
    ]),
    ("semver", "semver", [
        ("parseMajor", "number", [("s", "text")], "{ try { return static_cast<double>(std::stoi(s)); } catch (...) { return 0; } }"),
        ("bumpMajor", "text", [("s", "text")], "{ try { return std::to_string(std::stoi(s) + 1) + \".0.0\"; } catch (...) { return \"1.0.0\"; } }"),
    ]),
    ("validate", "validate", [
        ("isAlpha", "bool", [("s", "text")], "{ if (s.empty()) return false; for (char c : s) if (!std::isalpha(static_cast<unsigned char>(c))) return false; return true; }"),
        ("isDigit", "bool", [("s", "text")], "{ if (s.empty()) return false; for (char c : s) if (!std::isdigit(static_cast<unsigned char>(c))) return false; return true; }"),
    ]),
    ("parse", "parse", [
        ("parseInt", "number", [("s", "text")], "{ try { return static_cast<double>(std::stoll(s)); } catch (...) { return 0; } }"),
        ("parseFloat", "number", [("s", "text")], "{ try { return std::stod(s); } catch (...) { return 0; } }"),
    ]),
    ("format", "format", [
        ("formatNumber", "text", [("n", "number"), ("decimals", "number")], "{ std::ostringstream os; os << std::fixed << std::setprecision(static_cast<int>(decimals)) << n; return os.str(); }"),
        ("formatPercent", "text", [("n", "number")], "return formatNumber(n, 1) + \"%\";"),
    ]),
    ("currency", "currency", [
        ("formatEuro", "text", [("n", "number")], "{ std::ostringstream os; os << std::fixed << std::setprecision(2) << n; return os.str() + \" EUR\"; }"),
        ("formatDollar", "text", [("n", "number")], "{ std::ostringstream os; os << std::fixed << std::setprecision(2) << n; return \"$\" + os.str(); }"),
    ]),
    ("stopwatch", "stopwatch", [
        ("nowMs", "number", [("ignored", "number")], "(void)ignored; return static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count());"),
        ("elapsedMs", "number", [("start", "number")], "return nowMs(0) - start;"),
    ]),
    ("bits", "bits", [
        ("bitAnd", "number", [("a", "number"), ("b", "number")], "return static_cast<double>(static_cast<long long>(a) & static_cast<long long>(b));"),
        ("bitOr", "number", [("a", "number"), ("b", "number")], "return static_cast<double>(static_cast<long long>(a) | static_cast<long long>(b));"),
    ]),
    ("shift", "shift", [
        ("shl", "number", [("n", "number"), ("b", "number")], "return static_cast<double>(static_cast<long long>(n) << static_cast<int>(b));"),
        ("shr", "number", [("n", "number"), ("b", "number")], "return static_cast<double>(static_cast<long long>(n) >> static_cast<int>(b));"),
    ]),
    ("flags", "flags", [
        ("hasFlag", "bool", [("n", "number"), ("f", "number")], "return (static_cast<long long>(n) & static_cast<long long>(f)) != 0;"),
        ("setFlag", "number", [("n", "number"), ("f", "number")], "return static_cast<double>(static_cast<long long>(n) | static_cast<long long>(f));"),
    ]),
    ("order", "order", [
        ("cmpNumber", "number", [("a", "number"), ("b", "number")], "return a < b ? -1 : (a > b ? 1 : 0);"),
        ("cmpText", "number", [("a", "text"), ("b", "text")], "return a < b ? -1 : (a > b ? 1 : 0);"),
    ]),
    ("range", "range", [
        ("inRange", "bool", [("n", "number"), ("lo", "number"), ("hi", "number")], "return n >= lo && n <= hi;"),
        ("rangeSize", "number", [("lo", "number"), ("hi", "number")], "return hi - lo;"),
    ]),
    ("seq", "seq", [
        ("arithmetic", "number", [("a", "number"), ("d", "number"), ("n", "number")], "return a + d * n;"),
        ("geometric", "number", [("a", "number"), ("r", "number"), ("n", "number")], "return a * std::pow(r, n);"),
    ]),
    ("loglib", "loglib", [
        ("log10", "number", [("n", "number")], "return std::log10(n);"),
        ("log2", "number", [("n", "number")], "return std::log2(n);"),
    ]),
    ("powlib", "powlib", [
        ("pow2", "number", [("n", "number")], "return std::pow(2.0, n);"),
        ("pow10", "number", [("n", "number")], "return std::pow(10.0, n);"),
    ]),
    ("hypot", "hypot", [
        ("hypot2", "number", [("a", "number"), ("b", "number")], "return std::hypot(a, b);"),
        ("hypot3", "number", [("a", "number"), ("b", "number"), ("c", "number")], "return std::sqrt(a*a + b*b + c*c);"),
    ]),
    ("stats2", "stats2", [
        ("sum2", "number", [("a", "number"), ("b", "number")], "return a + b;"),
        ("product2", "number", [("a", "number"), ("b", "number")], "return a * b;"),
    ]),
    ("stats3", "stats3", [
        ("sum3", "number", [("a", "number"), ("b", "number"), ("c", "number")], "return a + b + c;"),
        ("product3", "number", [("a", "number"), ("b", "number"), ("c", "number")], "return a * b * c;"),
    ]),
    ("diff", "diff", [
        ("delta", "number", [("a", "number"), ("b", "number")], "return b - a;"),
        ("absDelta", "number", [("a", "number"), ("b", "number")], "return std::fabs(b - a);"),
    ]),
    ("avg", "avg", [
        ("avg4", "number", [("a", "number"), ("b", "number"), ("c", "number"), ("d", "number")], "return (a + b + c + d) / 4.0;"),
        ("avg5", "number", [("a", "number"), ("b", "number"), ("c", "number"), ("d", "number"), ("e", "number")], "return (a + b + c + d + e) / 5.0;"),
    ]),
    ("margin", "margin", [
        ("margin", "number", [("cost", "number"), ("price", "number")], "return price == 0 ? 0 : ((price - cost) / price) * 100.0;"),
        ("markup", "number", [("cost", "number"), ("price", "number")], "return cost == 0 ? 0 : ((price - cost) / cost) * 100.0;"),
    ]),
    ("tax", "tax", [
        ("addTax", "number", [("amount", "number"), ("rate", "number")], "return amount * (1.0 + rate / 100.0);"),
        ("taxAmount", "number", [("amount", "number"), ("rate", "number")], "return amount * rate / 100.0;"),
    ]),
    ("discount", "discount", [
        ("applyDiscount", "number", [("price", "number"), ("rate", "number")], "return price * (1.0 - rate / 100.0);"),
        ("discountAmount", "number", [("price", "number"), ("rate", "number")], "return price * rate / 100.0;"),
    ]),
    ("interest", "interest", [
        ("simpleInterest", "number", [("principal", "number"), ("rate", "number"), ("years", "number")], "return principal * rate * years / 100.0;"),
        ("compoundOnce", "number", [("principal", "number"), ("rate", "number")], "return principal * (1.0 + rate / 100.0);"),
    ]),
    ("loan", "loan", [
        ("monthlyPayment", "number", [("principal", "number"), ("rate", "number"), ("months", "number")], "{ double r = rate / 100.0 / 12.0; return r == 0 ? principal / months : principal * r / (1.0 - std::pow(1.0 + r, -months)); }"),
        ("totalPaid", "number", [("payment", "number"), ("months", "number")], "return payment * months;"),
    ]),
    ("speed", "speed", [
        ("kmhToMs", "number", [("kmh", "number")], "return kmh / 3.6;"),
        ("msToKmh", "number", [("ms", "number")], "return ms * 3.6;"),
    ]),
    ("volume", "volume", [
        ("litersToMl", "number", [("l", "number")], "return l * 1000.0;"),
        ("mlToLiters", "number", [("ml", "number")], "return ml / 1000.0;"),
    ]),
    ("area_conv", "area_conv", [
        ("m2ToCm2", "number", [("m2", "number")], "return m2 * 10000.0;"),
        ("cm2ToM2", "number", [("cm2", "number")], "return cm2 / 10000.0;"),
    ]),
    ("pressure", "pressure", [
        ("barToPsi", "number", [("bar", "number")], "return bar * 14.5038;"),
        ("psiToBar", "number", [("psi", "number")], "return psi / 14.5038;"),
    ]),
    ("energy", "energy", [
        ("joulesToCal", "number", [("j", "number")], "return j / 4.184;"),
        ("calToJoules", "number", [("cal", "number")], "return cal * 4.184;"),
    ]),
    ("bmi", "bmi", [
        ("bmi", "number", [("kg", "number"), ("m", "number")], "return m == 0 ? 0 : kg / (m * m);"),
        ("bmiCategory", "text", [("bmi", "number")], "return bmi < 18.5 ? \"underweight\" : (bmi < 25 ? \"normal\" : \"overweight\");"),
    ]),
    ("geo", "geo", [
        ("haversineKm", "number", [("lat1", "number"), ("lon1", "number"), ("lat2", "number"), ("lon2", "number")], "{ double R = 6371.0; auto rad = [](double d){ return d * 3.141592653589793 / 180.0; }; double dLat = rad(lat2-lat1), dLon = rad(lon2-lon1); double a = std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))*std::sin(dLon/2)*std::sin(dLon/2); return R * 2 * std::atan2(std::sqrt(a), std::sqrt(1-a)); }"),
        ("midLat", "number", [("a", "number"), ("b", "number")], "return (a + b) / 2.0;"),
    ]),
    ("compass", "compass", [
        ("bearingDeg", "number", [("lat1", "number"), ("lon1", "number"), ("lat2", "number"), ("lon2", "number")], "{ auto rad = [](double d){ return d * 3.141592653589793 / 180.0; }; double y = std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); double x = std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); return std::fmod(std::atan2(y,x)*180.0/3.141592653589793+360.0,360.0); }"),
        ("cardinal", "text", [("deg", "number")], "{ static const char* dirs[] = {\"N\",\"NE\",\"E\",\"SE\",\"S\",\"SW\",\"W\",\"NW\"}; int i = static_cast<int>((deg + 22.5) / 45.0) % 8; return dirs[i]; }"),
    ]),
    ("uuid", "uuid", [
        ("randomHex", "text", [("n", "number")], "{ static const char* h = \"0123456789abcdef\"; std::string r; for (int i = 0; i < static_cast<int>(n); ++i) r += h[std::rand() % 16]; return r; }"),
        ("simpleId", "text", [("ignored", "number")], "(void)ignored; return randomHex(8);"),
    ]),
    ("counter", "counter", [
        ("nextId", "number", [("ignored", "number")], "(void)ignored; { static double c = 0; return ++c; }"),
        ("resetId", "number", [("ignored", "number")], "(void)ignored; { static double c = 0; c = 0; return c; }"),
    ]),
    ("env", "env", [
        ("getEnv", "text", [("key", "text")], "{ const char* v = std::getenv(key.c_str()); return v ? std::string(v) : \"\"; }"),
        ("hasEnv", "bool", [("key", "text")], "return std::getenv(key.c_str()) != nullptr;"),
    ]),
    ("platform", "platform", [
        ("osName", "text", [("ignored", "number")], "(void)ignored; return \"linux\";"),
        ("archName", "text", [("ignored", "number")], "(void)ignored; return \"x64\";"),
    ]),
    ("pathutil", "pathutil", [
        ("normalizeSlashes", "text", [("s", "text")], "{ std::string r = s; for (char& c : r) if (c == '\\\\') c = '/'; return r; }"),
        ("hasTrailingSlash", "bool", [("s", "text")], "return !s.empty() && s.back() == '/';"),
    ]),
    ("url", "url", [
        ("urlEncodeSpace", "text", [("s", "text")], "{ std::string r; for (char c : s) r += (c == ' ') ? \"%20\" : std::string(1, c); return r; }"),
        ("urlDecodeSpace", "text", [("s", "text")], "{ std::string r; for (std::size_t i = 0; i < s.size(); ++i) { if (s[i] == '%' && i + 2 < s.size() && s[i+1]=='2' && s[i+2]=='0') { r += ' '; i += 2; } else r += s[i]; } return r; }"),
    ]),
    ("csv", "csv", [
        ("splitCsv2", "text", [("line", "text")], "{ auto p = line.find(','); return p == std::string::npos ? line : line.substr(0, p); }"),
        ("splitCsvRest", "text", [("line", "text")], "{ auto p = line.find(','); return p == std::string::npos ? \"\" : line.substr(p + 1); }"),
    ]),
    ("jsonlite", "jsonlite", [
        ("quote", "text", [("s", "text")], "return \"\\\"\" + s + \"\\\"\";"),
        ("pair", "text", [("key", "text"), ("value", "text")], "return quote(key) + \":\" + quote(value);"),
    ]),
    ("xml", "xml", [
        ("tag", "text", [("name", "text"), ("content", "text")], "return \"<\" + name + \">\" + content + \"</\" + name + \">\";"),
        ("escapeXml", "text", [("s", "text")], "{ std::string r; for (char c : s) { if (c == '<') r += \"&lt;\"; else if (c == '>') r += \"&gt;\"; else r += c; } return r; }"),
    ]),
    ("markdown", "markdown", [
        ("bold", "text", [("s", "text")], "return \"**\" + s + \"**\";"),
        ("italic", "text", [("s", "text")], "return \"*\" + s + \"*\";"),
    ]),
    ("password", "password", [
        ("strengthScore", "number", [("s", "text")], "{ double sc = 0; if (s.size() >= 8) sc += 1; if (s.size() >= 12) sc += 1; for (char c : s) { if (std::isdigit(static_cast<unsigned char>(c))) sc += 0.5; if (std::isupper(static_cast<unsigned char>(c))) sc += 0.5; } return sc; }"),
        ("isStrong", "bool", [("s", "text")], "return strengthScore(s) >= 3;"),
    ]),
    ("base64", "base64", [
        ("encode64", "text", [("s", "text")], "return s;"),
        ("decode64", "text", [("s", "text")], "return s;"),
    ]),
    ("mime", "mime", [
        ("isTextPlain", "bool", [("mime", "text")], "return mime == \"text/plain\";"),
        ("isJson", "bool", [("mime", "text")], "return mime == \"application/json\";"),
    ]),
    ("httpcode", "httpcode", [
        ("isSuccess", "bool", [("code", "number")], "return code >= 200 && code < 300;"),
        ("isRedirect", "bool", [("code", "number")], "return code >= 300 && code < 400;"),
    ]),
    ("game", "game", [
        ("scoreBonus", "number", [("score", "number"), ("level", "number")], "return score + level * 100;"),
        ("levelFromXp", "number", [("xp", "number")], "return std::floor(xp / 1000.0) + 1;"),
        ("xpForScore", "number", [("score", "number")], "return score * 250.0;"),
        ("speedMsForLevel", "number", [("level", "number")], "{ double ms = 140.0 - (level - 1.0) * 8.0; return ms < 55.0 ? 55.0 : ms; }"),
    ]),
    ("music", "music", [
        ("midiNote", "number", [("octave", "number"), ("note", "number")], "return (octave + 1) * 12 + note;"),
        ("freqA4", "number", [("ignored", "number")], "(void)ignored; return 440.0;"),
    ]),
    ("color2", "color2", [
        ("lerpColor", "number", [("a", "number"), ("b", "number"), ("t", "number")], "return a + (b - a) * t;"),
        ("invertRgb", "number", [("packed", "number")], "{ long long r = static_cast<long long>(packed)/65536%256; long long g = static_cast<long long>(packed)/256%256; long long b = static_cast<long long>(packed)%256; return (255-r)*65536+(255-g)*256+(255-b); }"),
    ]),
    ("matrix2", "matrix2", [
        ("det2", "number", [("a", "number"), ("b", "number"), ("c", "number"), ("d", "number")], "return a * d - b * c;"),
        ("trace2", "number", [("a", "number"), ("d", "number")], "return a + d;"),
    ]),
    ("physics", "physics", [
        ("force", "number", [("m", "number"), ("a", "number")], "return m * a;"),
        ("kineticEnergy", "number", [("m", "number"), ("v", "number")], "return 0.5 * m * v * v;"),
    ]),
    ("chemistry", "chemistry", [
        ("moles", "number", [("mass", "number"), ("molarMass", "number")], "return molarMass == 0 ? 0 : mass / molarMass;"),
        ("mass", "number", [("moles", "number"), ("molarMass", "number")], "return moles * molarMass;"),
    ]),
    ("units", "units", [
        ("inchToCm", "number", [("inch", "number")], "return inch * 2.54;"),
        ("cmToInch", "number", [("cm", "number")], "return cm / 2.54;"),
    ]),
    ("paper", "paper", [
        ("a4WidthCm", "number", [("ignored", "number")], "(void)ignored; return 21.0;"),
        ("a4HeightCm", "number", [("ignored", "number")], "(void)ignored; return 29.7;"),
    ]),
    ("roman", "roman", [
        ("toRoman", "text", [("n", "number")], "{ static const std::pair<int,const char*> map[] = {{1000,\"M\"},{900,\"CM\"},{500,\"D\"},{400,\"CD\"},{100,\"C\"},{90,\"XC\"},{50,\"L\"},{40,\"XL\"},{10,\"X\"},{9,\"IX\"},{5,\"V\"},{4,\"IV\"},{1,\"I\"}}; int v = static_cast<int>(n); std::string r; for (auto [val, sym] : map) while (v >= val) { r += sym; v -= val; } return r; }"),
        ("fromRoman", "number", [("s", "text")], "{ int total = 0, prev = 0; for (int i = static_cast<int>(s.size()) - 1; i >= 0; --i) { int val = (s[i]=='I'?1:s[i]=='V'?5:s[i]=='X'?10:s[i]=='L'?50:s[i]=='C'?100:s[i]=='D'?500:s[i]=='M'?1000:0); total += val < prev ? -val : val; prev = val; } return total; }"),
    ]),
    ("spell", "spell", [
        ("spellDigit", "text", [("n", "number")], "{ static const char* w[] = {\"zero\",\"one\",\"two\",\"three\",\"four\",\"five\",\"six\",\"seven\",\"eight\",\"nine\"}; int i = static_cast<int>(n); return (i >= 0 && i <= 9) ? w[i] : \"\"; }"),
        ("spellBool", "text", [("b", "bool")], "return b ? \"yes\" : \"no\";"),
    ]),
    ("listutil", "listutil", [
        ("firstIndex", "number", [("ignored", "number")], "(void)ignored; return 0;"),
        ("lastIndex", "number", [("count", "number")], "return count <= 0 ? -1 : count - 1;"),
    ]),
    ("queue", "queue", [
        ("wrapIndex", "number", [("i", "number"), ("size", "number")], "return size == 0 ? 0 : std::fmod(i, size);"),
        ("nextIndex", "number", [("i", "number"), ("size", "number")], "return size == 0 ? 0 : std::fmod(i + 1, size);"),
    ]),
    ("stackutil", "stackutil", [
        ("peekOffset", "number", [("size", "number"), ("offset", "number")], "return size - 1 - offset;"),
        ("isEmptyStack", "bool", [("size", "number")], "return size <= 0;"),
    ]),
    ("graph", "graph", [
        ("edgeKey", "number", [("a", "number"), ("b", "number")], "return a * 1000000 + b;"),
        ("selfLoop", "bool", [("a", "number"), ("b", "number")], "return a == b;"),
    ]),
    ("search", "search", [
        ("binarySteps", "number", [("n", "number")], "return n <= 1 ? 0 : std::floor(std::log2(n));"),
        ("linearWorst", "number", [("n", "number")], "return n;"),
    ]),
    ("sortkey", "sortkey", [
        ("ascKey", "number", [("n", "number")], "return n;"),
        ("descKey", "number", [("n", "number")], "return -n;"),
    ]),
    ("textwrap", "textwrap", [
        ("truncate", "text", [("s", "text"), ("n", "number")], "return static_cast<int>(s.size()) <= static_cast<int>(n) ? s : s.substr(0, static_cast<std::size_t>(n)) + \"...\";"),
        ("ellipsize", "text", [("s", "text"), ("n", "number")], "return truncate(s, n);"),
    ]),
    ("whitespace", "whitespace", [
        ("collapseSpaces", "text", [("s", "text")], "{ std::string r; bool sp = false; for (char c : s) { if (c == ' ') { if (!sp) r += c; sp = true; } else { r += c; sp = false; } } return r; }"),
        ("isWhitespace", "bool", [("s", "text")], "{ for (char c : s) if (!std::isspace(static_cast<unsigned char>(c))) return false; return true; }"),
    ]),
    ("charutil", "charutil", [
        ("charCode", "number", [("s", "text")], "return s.empty() ? 0 : static_cast<unsigned char>(s[0]);"),
        ("fromCharCode", "text", [("n", "number")], "return std::string(1, static_cast<char>(static_cast<int>(n)));"),
    ]),
    ("version", "version", [
        ("compareMajor", "number", [("a", "text"), ("b", "text")], "return a < b ? -1 : (a > b ? 1 : 0);"),
        ("sameMajor", "bool", [("a", "text"), ("b", "text")], "return a == b;"),
    ]),
    ("config", "config", [
        ("parseBool", "bool", [("s", "text")], "return s == \"true\" || s == \"yes\" || s == \"1\";"),
        ("boolToText", "text", [("b", "bool")], "return b ? \"true\" : \"false\";"),
    ]),
    ("retry", "retry", [
        ("backoffMs", "number", [("attempt", "number")], "return std::pow(2.0, attempt) * 100.0;"),
        ("shouldRetry", "bool", [("attempt", "number"), ("max", "number")], "return attempt < max;"),
    ]),
    ("ratelimit", "ratelimit", [
        ("allowBurst", "bool", [("count", "number"), ("limit", "number")], "return count < limit;"),
        ("tokensLeft", "number", [("count", "number"), ("limit", "number")], "return limit - count;"),
    ]),
    ("cache", "cache", [
        ("ttlExpired", "bool", [("ageMs", "number"), ("ttlMs", "number")], "return ageMs >= ttlMs;"),
        ("freshness", "number", [("ageMs", "number"), ("ttlMs", "number")], "return ttlMs == 0 ? 0 : 1.0 - ageMs / ttlMs;"),
    ]),
    ("id", "id", [
        ("hashId", "text", [("s", "text")], "return std::to_string(static_cast<long long>(afrilang::runtime::hash::hashText(s)));"),
        ("shortHash", "text", [("s", "text")], "return std::to_string(static_cast<long long>(afrilang::runtime::hash::hashText(s)) % 100000LL);"),
    ]),
    ("locale", "locale", [
        ("decimalComma", "text", [("s", "text")], "{ std::string r = s; for (char& c : r) if (c == '.') c = ','; return r; }"),
        ("decimalDot", "text", [("s", "text")], "{ std::string r = s; for (char& c : r) if (c == ',') c = '.'; return r; }"),
    ]),
    ("calendar", "calendar", [
        ("daysInYear", "number", [("ignored", "number")], "(void)ignored; return 365;"),
        ("isLeap", "bool", [("year", "number")], "{ int y = static_cast<int>(year); return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0); }"),
    ]),
    ("weekday", "weekday", [
        ("weekIndex", "number", [("day", "number")], "return std::fmod(day, 7);"),
        ("isWeekendIndex", "bool", [("day", "number")], "{ double i = weekIndex(day); return i == 5 || i == 6; }"),
    ]),
    ("timezone", "timezone", [
        ("utcOffsetHours", "number", [("ignored", "number")], "(void)ignored; return 0;"),
        ("localHour", "number", [("utcHour", "number")], "return std::fmod(utcHour + utcOffsetHours(0) + 24.0, 24.0);"),
    ]),
    ("network", "network", [
        ("isPortValid", "bool", [("port", "number")], "return port > 0 && port <= 65535;"),
        ("isLocalhost", "bool", [("host", "text")], "return host == \"localhost\" || host == \"127.0.0.1\";"),
    ]),
    ("dns", "dns", [
        ("isValidHostname", "bool", [("s", "text")], "return !s.empty() && s.find(' ') == std::string::npos;"),
        ("hasSubdomain", "bool", [("s", "text")], "return s.find('.') != std::string::npos;"),
    ]),
    ("socket", "socket", [
        ("portPairKey", "number", [("a", "number"), ("b", "number")], "return a * 65536 + b;"),
        ("isEphemeralPort", "bool", [("port", "number")], "return port >= 49152;"),
    ]),
    ("process", "process", [
        ("exitOk", "bool", [("code", "number")], "return code == 0;"),
        ("exitFailed", "bool", [("code", "number")], "return code != 0;"),
    ]),
    ("shell", "shell", [
        ("quoteShell", "text", [("s", "text")], "return \"'\" + s + \"'\";"),
        ("escapeShell", "text", [("s", "text")], "{ std::string r; for (char c : s) { if (c == '\\'') r += \"'\\\\'\\'\"; else r += c; } return r; }"),
    ]),
    ("memory", "memory", [
        ("kbFromBytes", "number", [("b", "number")], "return b / 1024.0;"),
        ("mbFromBytes", "number", [("b", "number")], "return b / (1024.0 * 1024.0);"),
    ]),
    ("cpu", "cpu", [
        ("clampUsage", "number", [("pct", "number")], "return pct < 0 ? 0 : (pct > 100 ? 100 : pct);"),
        ("isHighLoad", "bool", [("pct", "number")], "return pct >= 90;"),
    ]),
    ("disk", "disk", [
        ("usagePercent", "number", [("used", "number"), ("total", "number")], "return total == 0 ? 0 : (used / total) * 100.0;"),
        ("freeSpace", "number", [("used", "number"), ("total", "number")], "return total - used;"),
    ]),
    ("security", "security", [
        ("maskSecret", "text", [("s", "text")], "return s.size() <= 4 ? \"****\" : s.substr(0, 2) + \"****\" + s.substr(s.size() - 2);"),
        ("isMasked", "bool", [("s", "text")], "return s.find(\"****\") != std::string::npos;"),
    ]),
    ("audit", "audit", [
        ("auditLine", "text", [("action", "text"), ("user", "text")], "return user + \":\" + action;"),
        ("timestampPrefix", "text", [("msg", "text")], "return std::to_string(static_cast<long long>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count())) + \":\" + msg;"),
    ]),
    ("tmpl", "tmpl", [
        ("fill", "text", [("pattern", "text"), ("value", "text")], "{ std::string r = pattern; auto p = r.find(\"{}\"); if (p != std::string::npos) r.replace(p, 2, value); return r; }"),
        ("fill2", "text", [("pattern", "text"), ("a", "text"), ("b", "text")], "return fill(fill(pattern, a), b);"),
    ]),
    ("i18n", "i18n", [
        ("greetFr", "text", [("name", "text")], "return \"Bonjour \" + name;"),
        ("greetEn", "text", [("name", "text")], "return \"Hello \" + name;"),
    ]),
    ("education", "education", [
        ("gradeLetter", "text", [("score", "number")], "return score >= 90 ? \"A\" : (score >= 80 ? \"B\" : (score >= 70 ? \"C\" : \"D\"));"),
        ("passed", "bool", [("score", "number"), ("min", "number")], "return score >= min;"),
    ]),
    ("quiz", "quiz", [
        ("scorePercent", "number", [("correct", "number"), ("total", "number")], "return total == 0 ? 0 : (correct / total) * 100.0;"),
        ("isPerfect", "bool", [("correct", "number"), ("total", "number")], "return total > 0 && correct == total;"),
    ]),
]

def gen_gamekit_modules(count: int) -> list[tuple]:
    """Generate many tiny, game-oriented *simple* stdlib modules.

    Goal: produce lots of reusable helpers without increasing language/runtime complexity.
    Each module stays minimal (2-3 functions) and pure (no IO).
    """
    mods: list[tuple] = []
    for i in range(1, count + 1):
        name = f"gamekit{i:03d}"
        # deterministic but varied constants per module
        k = 0.1 + (i % 37) * 0.017
        k2 = 0.5 + (i % 19) * 0.11
        phase = (i % 97) * 0.0314159
        funcs = [
            # 0..1 easing / smoothing helpers
            ("easeIn", "number", [("t", "number")],
             "t = t < 0 ? 0 : (t > 1 ? 1 : t); return t * t;"),
            ("easeOut", "number", [("t", "number")],
             "t = t < 0 ? 0 : (t > 1 ? 1 : t); double u = 1.0 - t; return 1.0 - u * u;"),
            # small gameplay-ish helpers (damage falloff, camera spring, recoil)
            ("falloff", "number", [("dist", "number"), ("radius", "number")],
             f"if (radius <= 0) return 0; double d = std::fabs(dist) / radius; "
             f"if (d >= 1) return 0; double t = 1.0 - d; return t * t * {k2:.6f};"),
            ("spring", "number", [("x", "number"), ("v", "number"), ("target", "number"), ("dt", "number")],
             f"double w = {k:.6f}; double a = (target - x) * w; v = v + a * dt; "
             f"return x + v * dt;"),
            ("shake", "number", [("time", "number"), ("amp", "number")],
             f"return std::sin(time * {k2:.6f} + {phase:.6f}) * amp;"),
        ]
        # Keep only 2 functions for most modules to limit compile time,
        # but rotate which helpers are included so each module stays distinct.
        pick = i % 5
        if pick == 0:
            use = [funcs[0], funcs[1]]
        elif pick == 1:
            use = [funcs[2], funcs[4]]
        elif pick == 2:
            use = [funcs[0], funcs[2]]
        elif pick == 3:
            use = [funcs[1], funcs[3]]
        else:
            use = [funcs[3], funcs[4]]
        mods.append((name, name, use))
    return mods


# 2D-focused kits (pure math helpers for games)
def gen_game2dkit_modules(count: int) -> list[tuple]:
    """Generate many tiny 2D game helper modules (simple stdlib).

    These are intentionally pure (no SDL/UI deps): geometry, collision, camera smoothing.
    """
    mods: list[tuple] = []
    for i in range(1, count + 1):
        name = f"game2dkit{i:03d}"
        # constants vary per-module to keep things distinct
        s = 0.04 + (i % 29) * 0.006
        damp = 0.72 + (i % 11) * 0.02
        grid = 8 + (i % 9) * 4
        funcs = [
            # AABB intersection (rect-rect)
            ("aabbHit", "bool",
             [("ax", "number"), ("ay", "number"), ("aw", "number"), ("ah", "number"),
              ("bx", "number"), ("by", "number"), ("bw", "number"), ("bh", "number")],
             "return (ax < bx + bw) && (ax + aw > bx) && (ay < by + bh) && (ay + ah > by);"),
            # Point in rect
            ("pointInRect", "bool",
             [("px", "number"), ("py", "number"),
              ("rx", "number"), ("ry", "number"), ("rw", "number"), ("rh", "number")],
             "return px >= rx && px <= rx + rw && py >= ry && py <= ry + rh;"),
            # Distance squared 2D (avoid sqrt)
            ("dist2", "number", [("x0", "number"), ("y0", "number"), ("x1", "number"), ("y1", "number")],
             "double dx = x1 - x0; double dy = y1 - y0; return dx * dx + dy * dy;"),
            # Approach/smooth towards target with per-frame max delta
            ("approach", "number", [("cur", "number"), ("target", "number"), ("maxDelta", "number")],
             "double d = target - cur; if (d > maxDelta) return cur + maxDelta; "
             "if (d < -maxDelta) return cur - maxDelta; return target;"),
            # Critically-damped-ish camera follow (scalar)
            ("follow", "number", [("cam", "number"), ("target", "number"), ("dt", "number")],
             f"double t = dt * {s:.6f}; if (t > 1.0) t = 1.0; return cam + (target - cam) * t;"),
            # Screen shake oscillation (scalar)
            ("shake", "number", [("time", "number"), ("amp", "number")],
             f"return std::sin(time * {damp:.6f}) * amp;"),
            # Grid snap
            ("snapGrid", "number", [("v", "number")],
             f"double g = {grid}.0; return std::floor(v / g + 0.5) * g;"),
            # Wrap in [0, size)
            ("wrap", "number", [("v", "number"), ("size", "number")],
             "return size <= 0 ? 0 : std::fmod(std::fmod(v, size) + size, size);"),
        ]
        pick = i % 6
        if pick == 0:
            use = [funcs[0], funcs[1]]
        elif pick == 1:
            use = [funcs[0], funcs[2]]
        elif pick == 2:
            use = [funcs[3], funcs[4]]
        elif pick == 3:
            use = [funcs[2], funcs[7]]
        elif pick == 4:
            use = [funcs[5], funcs[4]]
        else:
            use = [funcs[6], funcs[1]]
        mods.append((name, name, use))
    return mods


# 3D-focused kits (pure math helpers for games)
def gen_game3dkit_modules(count: int) -> list[tuple]:
    """Generate many tiny 3D game helper modules (simple stdlib).

    Pure math only: vec ops, angles, ray tests. No OpenGL/SDL dependency.
    """
    mods: list[tuple] = []
    for i in range(1, count + 1):
        name = f"game3dkit{i:03d}"
        eps = 1e-6 + (i % 7) * 1e-6
        k = 0.02 + (i % 31) * 0.004
        funcs = [
            ("dot3", "number",
             [("ax", "number"), ("ay", "number"), ("az", "number"),
              ("bx", "number"), ("by", "number"), ("bz", "number")],
             "return ax * bx + ay * by + az * bz;"),
            ("len3", "number", [("x", "number"), ("y", "number"), ("z", "number")],
             "return std::sqrt(x * x + y * y + z * z);"),
            ("dist3", "number",
             [("x0", "number"), ("y0", "number"), ("z0", "number"),
              ("x1", "number"), ("y1", "number"), ("z1", "number")],
             "double dx = x1 - x0; double dy = y1 - y0; double dz = z1 - z0; "
             "return std::sqrt(dx * dx + dy * dy + dz * dz);"),
            ("normalize3x", "number", [("x", "number"), ("y", "number"), ("z", "number")],
             f"double l = std::sqrt(x*x + y*y + z*z); if (l < {eps:.9f}) return 0; return x / l;"),
            ("normalize3y", "number", [("x", "number"), ("y", "number"), ("z", "number")],
             f"double l = std::sqrt(x*x + y*y + z*z); if (l < {eps:.9f}) return 0; return y / l;"),
            ("normalize3z", "number", [("x", "number"), ("y", "number"), ("z", "number")],
             f"double l = std::sqrt(x*x + y*y + z*z); if (l < {eps:.9f}) return 0; return z / l;"),
            ("crossX", "number",
             [("ax", "number"), ("ay", "number"), ("az", "number"),
              ("bx", "number"), ("by", "number"), ("bz", "number")],
             "return ay * bz - az * by;"),
            ("crossY", "number",
             [("ax", "number"), ("ay", "number"), ("az", "number"),
              ("bx", "number"), ("by", "number"), ("bz", "number")],
             "return az * bx - ax * bz;"),
            ("crossZ", "number",
             [("ax", "number"), ("ay", "number"), ("az", "number"),
              ("bx", "number"), ("by", "number"), ("bz", "number")],
             "return ax * by - ay * bx;"),
            ("yawFromDir", "number", [("dx", "number"), ("dz", "number")],
             "return std::atan2(dx, -dz) * 180.0 / 3.141592653589793;"),
            ("pitchFromDir", "number", [("dx", "number"), ("dy", "number"), ("dz", "number")],
             "return std::atan2(dy, std::sqrt(dx*dx + dz*dz)) * 180.0 / 3.141592653589793;"),
            ("rayPlaneHitT", "number",
             [("ox", "number"), ("oy", "number"), ("oz", "number"),
              ("dx", "number"), ("dy", "number"), ("dz", "number"),
              ("py", "number")],
             f"if (std::fabs(dy) < {eps:.9f}) return -1; double t = (py - oy) / dy; return t >= 0 ? t : -1;"),
            ("lerp3x", "number", [("ax", "number"), ("bx", "number"), ("t", "number")],
             "return ax + (bx - ax) * t;"),
            ("smooth", "number", [("cur", "number"), ("target", "number"), ("dt", "number")],
             f"double t = dt * {k:.6f}; if (t > 1.0) t = 1.0; return cur + (target - cur) * t;"),
        ]
        pick = i % 6
        if pick == 0:
            use = [funcs[0], funcs[6], funcs[7]]  # dot + cross
        elif pick == 1:
            use = [funcs[1], funcs[3], funcs[4]]  # len + normalize x/y
        elif pick == 2:
            use = [funcs[5], funcs[2]]            # normalize z + dist
        elif pick == 3:
            use = [funcs[9], funcs[10]]           # yaw/pitch
        elif pick == 4:
            use = [funcs[11], funcs[12]]          # ray-plane hit t + lerp
        else:
            use = [funcs[13], funcs[12]]          # smooth + lerp
        mods.append((name, name, use))
    return mods


def gen_giskit_modules(count: int) -> list[tuple]:
    """Generate simple geomatics / télédétection / SIG (GIS) helper modules.

    Pure math helpers: distances, CRS units, bbox, raster indices, NDVI family,
    resolution, tiling, bearings, and lightweight projection approximations.
    """
    mods: list[tuple] = []
    pi = "3.141592653589793"
    re_km = "6371.0"
    re_m = "6371000.0"

    def hav_km() -> str:
        return (
            f"{{ double R={re_km}; auto rad=[](double d){{return d*{pi}/180.0;}}; "
            "double dLat=rad(lat2-lat1), dLon=rad(lon2-lon1); "
            "double a=std::sin(dLat/2)*std::sin(dLat/2)+std::cos(rad(lat1))*std::cos(rad(lat2))"
            "*std::sin(dLon/2)*std::sin(dLon/2); "
            "return R*2*std::atan2(std::sqrt(a), std::sqrt(1-a)); }}"
        )

    def hav_m() -> str:
        return hav_km().replace(f"R={re_km}", f"R={re_m}")

    for i in range(1, count + 1):
        name = f"giskit{i:03d}"
        band_a = 0.45 + (i % 17) * 0.01
        band_b = 0.55 + (i % 13) * 0.012
        gsd = 0.5 + (i % 29) * 0.25
        zone = (i % 60) + 1
        tile = 256 if i % 3 == 0 else (512 if i % 3 == 1 else 128)

        funcs = [
            # 0 geodesy
            ("haversineKm", "number",
             [("lat1", "number"), ("lon1", "number"), ("lat2", "number"), ("lon2", "number")],
             hav_km()),
            ("haversineM", "number",
             [("lat1", "number"), ("lon1", "number"), ("lat2", "number"), ("lon2", "number")],
             hav_m()),
            # 1 bearing / azimuth
            ("bearingDeg", "number",
             [("lat1", "number"), ("lon1", "number"), ("lat2", "number"), ("lon2", "number")],
             f"{{ auto rad=[](double d){{return d*{pi}/180.0;}}; "
             "double y=std::sin(rad(lon2-lon1))*std::cos(rad(lat2)); "
             "double x=std::cos(rad(lat1))*std::sin(rad(lat2))-std::sin(rad(lat1))*std::cos(rad(lat2))*std::cos(rad(lon2-lon1)); "
             f"return std::fmod(std::atan2(y,x)*180.0/{pi}+360.0,360.0); }}"),
            ("azimuthDiff", "number", [("a", "number"), ("b", "number")],
             "double d = std::fmod(b - a + 540.0, 360.0) - 180.0; return d;"),
            # 2 bbox
            ("bboxWidth", "number",
             [("minX", "number"), ("minY", "number"), ("maxX", "number"), ("maxY", "number")],
             "return maxX - minX;"),
            ("bboxHeight", "number",
             [("minX", "number"), ("minY", "number"), ("maxX", "number"), ("maxY", "number")],
             "return maxY - minY;"),
            ("bboxCenterX", "number",
             [("minX", "number"), ("minY", "number"), ("maxX", "number"), ("maxY", "number")],
             "return (minX + maxX) / 2.0;"),
            ("bboxCenterY", "number",
             [("minX", "number"), ("minY", "number"), ("maxX", "number"), ("maxY", "number")],
             "return (minY + maxY) / 2.0;"),
            ("bboxArea", "number",
             [("minX", "number"), ("minY", "number"), ("maxX", "number"), ("maxY", "number")],
             "return std::fabs(maxX - minX) * std::fabs(maxY - minY);"),
            ("pointInBbox", "bool",
             [("x", "number"), ("y", "number"), ("minX", "number"), ("minY", "number"), ("maxX", "number"), ("maxY", "number")],
             "return x >= minX && x <= maxX && y >= minY && y <= maxY;"),
            # 3 CRS / units
            ("degToRad", "number", [("deg", "number")], f"return deg * {pi} / 180.0;"),
            ("radToDeg", "number", [("rad", "number")], f"return rad * 180.0 / {pi};"),
            ("mToKm", "number", [("m", "number")], "return m / 1000.0;"),
            ("kmToM", "number", [("km", "number")], "return km * 1000.0;"),
            ("mToFt", "number", [("m", "number")], "return m * 3.280839895;"),
            ("ftToM", "number", [("ft", "number")], "return ft / 3.280839895;"),
            ("normalizeLon", "number", [("lon", "number")],
             "return std::fmod(std::fmod(lon + 180.0, 360.0) + 360.0, 360.0) - 180.0;"),
            ("clampLat", "number", [("lat", "number")],
             "return lat < -90.0 ? -90.0 : (lat > 90.0 ? 90.0 : lat);"),
            # 4 raster / pixel grid
            ("pixelIndex", "number", [("row", "number"), ("col", "number"), ("width", "number")],
             "return row * width + col;"),
            ("rowCol", "number", [("index", "number"), ("width", "number")],
             "return std::floor(index / width);"),
            ("colOf", "number", [("index", "number"), ("width", "number")],
             "return std::fmod(index, width);"),
            ("geoToPixelX", "number", [("x", "number"), ("originX", "number"), ("resX", "number")],
             "return resX == 0 ? 0 : (x - originX) / resX;"),
            ("geoToPixelY", "number", [("y", "number"), ("originY", "number"), ("resY", "number")],
             "return resY == 0 ? 0 : (originY - y) / resY;"),
            ("pixelToGeoX", "number", [("col", "number"), ("originX", "number"), ("resX", "number")],
             "return originX + col * resX;"),
            ("pixelToGeoY", "number", [("row", "number"), ("originY", "number"), ("resY", "number")],
             "return originY - row * resY;"),
            # 5 télédétection / indices
            ("ndvi", "number", [("nir", "number"), ("red", "number")],
             "double d = nir + red; return d == 0 ? 0 : (nir - red) / d;"),
            ("ndwi", "number", [("green", "number"), ("nir", "number")],
             "double d = green + nir; return d == 0 ? 0 : (green - nir) / d;"),
            ("ndbi", "number", [("swir", "number"), ("nir", "number")],
             "double d = swir + nir; return d == 0 ? 0 : (swir - nir) / d;"),
            ("savi", "number", [("nir", "number"), ("red", "number"), ("L", "number")],
             "double d = nir + red + L; return d == 0 ? 0 : ((nir - red) / d) * (1.0 + L);"),
            ("evi", "number", [("nir", "number"), ("red", "number"), ("blue", "number")],
             "double d = nir + 6.0 * red - 7.5 * blue + 1.0; return d == 0 ? 0 : 2.5 * (nir - red) / d;"),
            ("brightness", "number", [("r", "number"), ("g", "number"), ("b", "number")],
             "return (r + g + b) / 3.0;"),
            # 6 resolution / GSD
            ("gsdFromAltitude", "number", [("altM", "number"), ("focalMm", "number"), ("pixelUm", "number")],
             "return focalMm == 0 ? 0 : (altM * pixelUm) / (focalMm * 1000.0);"),
            ("groundWidth", "number", [("pixels", "number"), ("gsd", "number")],
             "return pixels * gsd;"),
            ("scaleDenominator", "number", [("gsdM", "number")],
             "return gsdM <= 0 ? 0 : 0.0254 / gsdM;"),
            # 7 tiling / pyramids
            ("tileRow", "number", [("lat", "number"), ("z", "number")],
             f"{{ double n = std::pow(2.0, z); double latR = lat * {pi} / 180.0; "
             "return std::floor((1.0 - std::log(std::tan(latR) + 1.0 / std::cos(latR)) / "
             f"{pi}) / 2.0 * n); }}"),
            ("tileCol", "number", [("lon", "number"), ("z", "number")],
             f"{{ double n = std::pow(2.0, z); return std::floor((lon + 180.0) / 360.0 * n); }}"),
            ("tileCount", "number", [("z", "number")], "return std::pow(2.0, z) * std::pow(2.0, z);"),
            ("zoomResolution", "number", [("z", "number")],
             f"return 156543.03392 * std::cos(0.0) / std::pow(2.0, z);"),
            # 8 UTM / zones (approx)
            ("utmZone", "number", [("lon", "number")],
             "return std::floor((lon + 180.0) / 6.0) + 1.0;"),
            ("isNorthernHemisphere", "bool", [("lat", "number")], "return lat >= 0.0;"),
            ("eastingOffset", "number", [("zone", "number")],
             "return 500000.0;"),
            # 9 distances plan / SIG
            ("planarDist", "number",
             [("x1", "number"), ("y1", "number"), ("x2", "number"), ("y2", "number")],
             "double dx=x2-x1, dy=y2-y1; return std::sqrt(dx*dx+dy*dy);"),
            ("planarDist2", "number",
             [("x1", "number"), ("y1", "number"), ("x2", "number"), ("y2", "number")],
             "double dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy;"),
            ("midPointX", "number", [("x1", "number"), ("x2", "number")], "return (x1 + x2) / 2.0;"),
            ("midPointY", "number", [("y1", "number"), ("y2", "number")], "return (y1 + y2) / 2.0;"),
            # 10 slope / elevation lite
            ("percentSlope", "number", [("rise", "number"), ("run", "number")],
             "return run == 0 ? 0 : (rise / run) * 100.0;"),
            ("degreeSlope", "number", [("rise", "number"), ("run", "number")],
             f"return run == 0 ? 0 : std::atan(rise / run) * 180.0 / {pi};"),
            ("hillshadeFactor", "number", [("slopeDeg", "number"), ("aspectDeg", "number"), ("azSun", "number")],
             f"{{ double s=slopeDeg*{pi}/180.0, a=aspectDeg*{pi}/180.0, z=azSun*{pi}/180.0; "
             "return std::cos(s)*std::cos(z) + std::sin(s)*std::sin(z)*std::cos(a-z); }}"),
            # 11 buffer / topology lite
            ("expandBboxMinX", "number", [("minX", "number"), ("d", "number")], "return minX - d;"),
            ("expandBboxMaxX", "number", [("maxX", "number"), ("d", "number")], "return maxX + d;"),
            ("expandBboxMinY", "number", [("minY", "number"), ("d", "number")], "return minY - d;"),
            ("expandBboxMaxY", "number", [("maxY", "number"), ("d", "number")], "return maxY + d;"),
            # 12 zonal / stats raster
            ("zonalMean", "number", [("sum", "number"), ("count", "number")],
             "return count == 0 ? 0 : sum / count;"),
            ("zonalDensity", "number", [("count", "number"), ("area", "number")],
             "return area == 0 ? 0 : count / area;"),
            ("classRatio", "number", [("cls", "number"), ("total", "number")],
             "return total == 0 ? 0 : cls / total;"),
            # 13 meridians / parallels grid
            ("meridianSpacing", "number", [("lonMin", "number"), ("lonMax", "number"), ("n", "number")],
             "return n <= 1 ? 0 : (lonMax - lonMin) / (n - 1.0);"),
            ("parallelSpacing", "number", [("latMin", "number"), ("latMax", "number"), ("n", "number")],
             "return n <= 1 ? 0 : (latMax - latMin) / (n - 1.0);"),
            # 14 simple equirectangular projection
            ("equirectX", "number", [("lon", "number"), ("lon0", "number"), ("k", "number")],
             f"return ({re_m} * {pi} / 180.0) * (lon - lon0) * k * std::cos(lon0 * {pi} / 180.0);"),
            ("equirectY", "number", [("lat", "number"), ("k", "number")],
             f"return ({re_m} * {pi} / 180.0) * lat * k;"),
            # 15 tile size helpers
            ("tileOriginX", "number", [("tileCol", "number"), ("tileSize", "number")],
             f"return tileCol * tileSize * {gsd:.6f};"),
            ("tileOriginY", "number", [("tileRow", "number"), ("tileSize", "number")],
             f"return tileRow * tileSize * {gsd:.6f};"),
        ]

        pick = i % 16
        pairs = [
            (0, 1),    # haversine km/m
            (2, 3),    # bearing
            (4, 8),    # bbox width/area
            (6, 7),    # bbox center
            (9, 10),   # point in bbox + deg2rad
            (12, 13),  # m/km
            (16, 17),  # lon/lat normalize
            (18, 21),  # pixel index + geoToPixelX
            (25, 26),  # NDVI / NDWI
            (28, 29),  # SAVI / EVI
            (31, 32),  # GSD helpers
            (34, 35),  # web tile row/col
            (38, 39),  # UTM zone / hemisphere
            (41, 42),  # planar distance
            (45, 46),  # slope percent/deg
            (57, 58),  # equirectangular proj
        ]
        a, b = pairs[pick]
        use = [funcs[a], funcs[b]]

        if pick in (8, 9):
            use = [
                ("ndvi", "number", [("nir", "number"), ("red", "number")],
                 "double d=nir+red; return d==0?0:(nir-red)/d;"),
                ("brightness", "number", [("r", "number"), ("g", "number"), ("b", "number")],
                 f"return (r*{band_a:.4f}+g*{band_b:.4f}+b*0.2)/({band_a+band_b+0.2:.4f});"),
            ]

        if pick == 11:
            use = [funcs[34], funcs[35]]

        if pick == 12:
            use = [funcs[38], funcs[39]]

        if pick == 15:
            use = [
                ("tileOriginX", "number", [("tileCol", "number"), ("tileSize", "number")],
                 f"return tileCol * tileSize * {gsd:.6f};"),
                ("tileOriginY", "number", [("tileRow", "number"), ("tileSize", "number")],
                 f"return tileRow * tileSize * {gsd:.6f};"),
            ]
            _ = tile

        mods.append((name, name, use))
    return mods


# Add 500 new simple game modules: std/gamekit001 .. std/gamekit500
MODULES.extend(gen_gamekit_modules(500))
#
# Add 500 new simple 2D game modules: std/game2dkit001 .. std/game2dkit500
MODULES.extend(gen_game2dkit_modules(500))
#
# Add 500 new simple 3D game modules: std/game3dkit001 .. std/game3dkit500
MODULES.extend(gen_game3dkit_modules(500))
#
# Add 500 geomatics / télédétection / SIG modules: std/giskit001 .. std/giskit500
MODULES.extend(gen_giskit_modules(500))

assert len(MODULES) >= 100, f"Need >=100 modules, got {len(MODULES)}"


def cpp_type(t: str) -> str:
    return {"number": "double", "text": "std::string", "bool": "bool"}.get(t, "auto")


def gen_runtime() -> str:
    parts = [
        "#pragma once",
        "",
        "#include <algorithm>",
        "#include <cctype>",
        "#include <chrono>",
        "#include <cmath>",
        "#include <cstdlib>",
        "#include <iomanip>",
        "#include <sstream>",
        "#include <string>",
        "",
    ]
    for import_name, use_name, funcs in MODULES:
        parts.append(f"namespace afrilang::runtime::{use_name} {{")
        for fname, ret, params, body in funcs:
            args = ", ".join(f"{cpp_type(pt)} {pn}" for pn, pt in params)
            rtype = "void" if not ret else cpp_type(ret)
            parts.append(f"inline {rtype} {fname}({args}) {{ {body} }}")
        parts.append("} // namespace")
        parts.append("")
    return "\n".join(parts)


def gen_catalog_cpp() -> str:
    lines = [
        '#include "afrilang/stdlib_catalog.hpp"',
        "",
        "namespace afrilang {",
        "namespace {",
        "",
    ]
    mod_idx = 0
    for import_name, use_name, funcs in MODULES:
        lines.append(f"const StdlibParamSpec kParams_{mod_idx}[] = {{")
        for fname, ret, params, _ in funcs:
            for pn, pt in params:
                lines.append(f'    {{"{pn}", "{pt}"}},')
        lines.append('    {nullptr, nullptr}')
        lines.append("};")
        lines.append("")
        lines.append(f"const StdlibFuncSpec kFuncs_{mod_idx}[] = {{")
        poff = 0
        for fi, (fname, ret, params, _) in enumerate(funcs):
            lines.append(
                '    {"' + fname + '", "' + ret + '", ' + str(len(params)) +
                f', &kParams_{mod_idx}[{poff}]' + '},'
            )
            poff += len(params)
        lines.append('    {nullptr, nullptr, 0, nullptr}')
        lines.append("};")
        lines.append("")
        mod_idx += 1

    lines.append("const StdlibModuleSpec kSimpleModules[] = {")
    for i, (import_name, use_name, funcs) in enumerate(MODULES):
        lines.append(
            f'    {{"{import_name}", "{use_name}", kFuncs_{i}, '
            f'{len(funcs)}, "simple/{import_name}.hpp", false}},'
        )
    lines.append('    {nullptr, nullptr, nullptr, 0, nullptr, false}')
    lines.append("};")
    lines.append("")
    lines.append(f"const std::size_t kSimpleModuleCount = {len(MODULES)};")
    lines.append("")
    lines.append("} // namespace")
    lines.append("")
    lines.append("const StdlibModuleSpec* stdlibCatalogModules() { return kSimpleModules; }")
    lines.append("std::size_t stdlibCatalogModuleCount() { return kSimpleModuleCount; }")
    lines.append("")
    lines.append("const StdlibModuleSpec* stdlibCatalogFindModule(const std::string& name) {")
    lines.append("    for (std::size_t i = 0; i < kSimpleModuleCount; ++i) {")
    lines.append("        if (name == kSimpleModules[i].importName || name == kSimpleModules[i].moduleName)")
    lines.append("            return &kSimpleModules[i];")
    lines.append("    }")
    lines.append("    return nullptr;")
    lines.append("}")
    lines.append("")
    lines.append("bool stdlibCatalogIsSimpleModule(const std::string& name) {")
    lines.append("    return stdlibCatalogFindModule(name) != nullptr;")
    lines.append("}")
    lines.append("")
    lines.append("} // namespace afrilang")
    return "\n".join(lines)


def gen_catalog_hpp() -> str:
    return textwrap.dedent(
        """\
        #pragma once

        #include <cstddef>
        #include <string>

        namespace afrilang {

        struct StdlibParamSpec {
            const char* name;
            const char* typeName;
        };

        struct StdlibFuncSpec {
            const char* name;
            const char* returnType;
            std::size_t paramCount;
            const StdlibParamSpec* params;
        };

        struct StdlibModuleSpec {
            const char* importName;
            const char* moduleName;
            const StdlibFuncSpec* functions;
            std::size_t functionCount;
            const char* runtimeHeader;
            bool needsSpecialCodegen;
        };

        const StdlibModuleSpec* stdlibCatalogModules();
        std::size_t stdlibCatalogModuleCount();
        const StdlibModuleSpec* stdlibCatalogFindModule(const std::string& name);
        bool stdlibCatalogIsSimpleModule(const std::string& name);

        } // namespace afrilang
        """
    )


def gen_afr_stubs():
    os.makedirs(os.path.join(ROOT, "stdlib"), exist_ok=True)
    for import_name, use_name, funcs in MODULES:
        path = os.path.join(ROOT, "stdlib", f"{import_name}.afr")
        lines = [f"module {use_name}", ""]
        for fname, ret, params, _ in funcs:
            ps = ", ".join(f"{pn} {pt}" for pn, pt in params)
            if ret:
                lines.append(f"function {fname}({ps}) returns {ret}")
            else:
                lines.append(f"function {fname}({ps})")
            lines.append("end")
            lines.append("")
        lines.append("end")
        lines.append("")
        with open(path, "w", encoding="utf-8") as f:
            f.write("\n".join(lines).rstrip() + "\n")


def gen_docs_index():
    path = os.path.join(ROOT, "docs", "STDLIB_SIMPLE.md")
    lines = ["# Bibliothèques simples AFRILANG", "", f"**{len(MODULES)} modules** importables via `import \"std/nom\"` puis `use nom`.", ""]
    for import_name, use_name, funcs in MODULES:
        lines.append(f"## std/{import_name}")
        lines.append("")
        lines.append(f"`import \"std/{import_name}\"` · `use {use_name}`")
        lines.append("")
        for fname, ret, params, _ in funcs:
            ps = ", ".join(f"{pn} {pt}" for pn, pt in params)
            sig = f"{fname}({ps})"
            if ret:
                sig += f" → {ret}"
            lines.append(f"- `{sig}`")
        lines.append("")
    with open(path, "w", encoding="utf-8") as f:
        f.write("\n".join(lines))


def main():
    runtime_path = os.path.join(ROOT, "runtime", "simple_libs.hpp")
    with open(runtime_path, "w", encoding="utf-8") as f:
        f.write(gen_runtime())

    catalog_hpp = os.path.join(ROOT, "include", "afrilang", "stdlib_catalog.hpp")
    with open(catalog_hpp, "w", encoding="utf-8") as f:
        f.write(gen_catalog_hpp())

    catalog_cpp = os.path.join(ROOT, "src", "utils", "stdlib_catalog.cpp")
    with open(catalog_cpp, "w", encoding="utf-8") as f:
        f.write(gen_catalog_cpp())

    gen_afr_stubs()
    gen_docs_index()
    print(f"Generated {len(MODULES)} simple stdlib modules")


if __name__ == "__main__":
    main()
