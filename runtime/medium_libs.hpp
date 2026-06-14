#pragma once

#include <algorithm>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

namespace afrilang::runtime::med::textstats {
inline double wordCount(std::string s) { { int c = 0; bool w = false; for (unsigned char ch : s) { if (std::isspace(ch)) w = false; else if (!w) { ++c; w = true; } } return static_cast<double>(c); } }
inline double charCount(std::string s) { return static_cast<double>(s.size()); }
inline double lineCount(std::string s) { { int c = s.empty() ? 0 : 1; for (char ch : s) if (ch == '\n') ++c; return static_cast<double>(c); } }
inline double avgWordLen(std::string s) { { int words = 0, chars = 0; bool w = false; for (unsigned char ch : s) { if (std::isspace(ch)) w = false; else { if (!w) ++words; ++chars; w = true; } } return words == 0 ? 0 : static_cast<double>(chars) / words; } }
inline double digitCount(std::string s) { { int c = 0; for (unsigned char ch : s) if (std::isdigit(ch)) ++c; return static_cast<double>(c); } }
} // namespace

namespace afrilang::runtime::med::charfreq {
inline double countChar(std::string s, std::string ch) { { if (ch.empty()) return 0; char t = ch[0]; int c = 0; for (char x : s) if (x == t) ++c; return static_cast<double>(c); } }
inline std::string mostCommonChar(std::string s) { { if (s.empty()) return ""; std::map<char,int> m; for (char c : s) ++m[c]; return std::string(1, std::max_element(m.begin(), m.end(), [](auto&a,auto&b){return a.second<b.second;})->first); } }
inline double uniqueChars(std::string s) { { std::map<char,int> m; for (char c : s) ++m[c]; return static_cast<double>(m.size()); } }
inline double alphaRatio(std::string s) { { if (s.empty()) return 0; int a = 0; for (unsigned char c : s) if (std::isalpha(c)) ++a; return static_cast<double>(a) / s.size(); } }
inline double spaceRatio(std::string s) { { if (s.empty()) return 0; int a = 0; for (unsigned char c : s) if (std::isspace(c)) ++a; return static_cast<double>(a) / s.size(); } }
} // namespace

namespace afrilang::runtime::med::sentsplit {
inline std::vector<std::string> splitSentences(std::string s) { { std::vector<std::string> r; std::string cur; for (char c : s) { cur += c; if (c=='.'||c=='!'||c=='?') { while (!cur.empty() && std::isspace(static_cast<unsigned char>(cur.front()))) cur.erase(cur.begin()); if (!cur.empty()) r.push_back(cur); cur.clear(); } } if (!cur.empty()) r.push_back(cur); return r; } }
inline double sentenceCount(std::string s) { { auto v = splitSentences(s); return static_cast<double>(v.size()); } }
inline std::string firstSentence(std::string s) { { auto v = splitSentences(s); return v.empty() ? "" : v.front(); } }
inline std::string lastSentence(std::string s) { { auto v = splitSentences(s); return v.empty() ? "" : v.back(); } }
} // namespace

namespace afrilang::runtime::med::wordtok {
inline std::vector<std::string> tokenize(std::string s) { { std::vector<std::string> r; std::string w; for (unsigned char c : s) { if (std::isspace(c)) { if (!w.empty()) { r.push_back(w); w.clear(); } } else w += static_cast<char>(c); } if (!w.empty()) r.push_back(w); return r; } }
inline double tokenCount(std::string s) { { auto v = tokenize(s); return static_cast<double>(v.size()); } }
inline std::string longestToken(std::string s) { { auto v = tokenize(s); if (v.empty()) return ""; return *std::max_element(v.begin(), v.end(), [](auto&a,auto&b){return a.size()<b.size();}); } }
inline std::string shortestToken(std::string s) { { auto v = tokenize(s); if (v.empty()) return ""; return *std::min_element(v.begin(), v.end(), [](auto&a,auto&b){return a.size()<b.size();}); } }
inline double avgTokenLen(std::string s) { { auto v = tokenize(s); if (v.empty()) return 0; double t = 0; for (auto& x : v) t += x.size(); return t / v.size(); } }
} // namespace

namespace afrilang::runtime::med::ngrams {
inline std::vector<std::string> bigrams(std::string s) { { std::vector<std::string> t; std::string w; for (unsigned char c : s) { if (std::isspace(c)) { if (!w.empty()) { t.push_back(w); w.clear(); } } else w += static_cast<char>(c); } if (!w.empty()) t.push_back(w); std::vector<std::string> out; for (std::size_t i = 1; i < t.size(); ++i) out.push_back(t[i-1] + " " + t[i]); return out; } }
inline std::vector<std::string> trigrams(std::string s) { { std::vector<std::string> t; std::string w; for (unsigned char c : s) { if (std::isspace(c)) { if (!w.empty()) { t.push_back(w); w.clear(); } } else w += static_cast<char>(c); } if (!w.empty()) t.push_back(w); std::vector<std::string> out; for (std::size_t i = 2; i < t.size(); ++i) out.push_back(t[i-2] + " " + t[i-1] + " " + t[i]); return out; } }
inline std::vector<std::string> charBigrams(std::string s) { { std::vector<std::string> r; for (std::size_t i = 1; i < s.size(); ++i) r.push_back(s.substr(i-1, 2)); return r; } }
inline double ngramCount(std::string s, double n) { { int nn = static_cast<int>(n); if (nn <= 0) return 0; auto t = tokenize(s); return t.size() >= static_cast<std::size_t>(nn) ? static_cast<double>(t.size() - nn + 1) : 0; } }
} // namespace

namespace afrilang::runtime::med::palindrom2 {
inline bool isPalindrome(std::string s) { { std::string t; for (char c : s) if (std::isalnum(static_cast<unsigned char>(c))) t += static_cast<char>(std::tolower(static_cast<unsigned char>(c))); return std::equal(t.begin(), t.begin()+t.size()/2, t.rbegin()); } }
inline double longestPalindromeLen(std::string s) { { std::string t; for (char c : s) if (std::isalnum(static_cast<unsigned char>(c))) t += static_cast<char>(std::tolower(static_cast<unsigned char>(c))); double best = 0; for (std::size_t i = 0; i < t.size(); ++i) for (std::size_t j = i; j < t.size(); ++j) { std::string sub = t.substr(i, j-i+1); if (std::equal(sub.begin(), sub.begin()+sub.size()/2, sub.rbegin())) best = std::max(best, static_cast<double>(sub.size())); } return best; } }
inline std::string reverseAlphaNum(std::string s) { { std::string t; for (char c : s) if (std::isalnum(static_cast<unsigned char>(c))) t += c; return std::string(t.rbegin(), t.rend()); } }
inline bool isPalindromeWord(std::string w) { return isPalindrome(w); }
} // namespace

namespace afrilang::runtime::med::anagram2 {
inline std::string normalizeWord(std::string s) { { std::string t; for (char c : s) if (std::isalpha(static_cast<unsigned char>(c))) t += static_cast<char>(std::tolower(static_cast<unsigned char>(c))); std::sort(t.begin(), t.end()); return t; } }
inline bool areAnagrams(std::string a, std::string b) { return normalizeWord(a) == normalizeWord(b); }
inline std::string anagramKey(std::string s) { return normalizeWord(s); }
inline std::string sortLetters(std::string s) { { std::string t = s; std::sort(t.begin(), t.end()); return t; } }
} // namespace

namespace afrilang::runtime::med::textwrap2 {
inline std::vector<std::string> wrapLines(std::string s, double width) { { std::vector<std::string> r; int w = static_cast<int>(width); if (w <= 0) return r; std::string line, word; for (char c : s) { if (c == ' ' || c == '\n') { if (!word.empty()) { if (!line.empty() && static_cast<int>(line.size() + 1 + word.size()) > w) { r.push_back(line); line = word; } else line = line.empty() ? word : line + " " + word; word.clear(); } if (c == '\n' && !line.empty()) { r.push_back(line); line.clear(); } } else word += c; } if (!word.empty()) line = line.empty() ? word : line + " " + word; if (!line.empty()) r.push_back(line); return r; } }
inline double wrapCount(std::string s, double width) { return static_cast<double>(wrapLines(s, width).size()); }
inline std::string truncateWords(std::string s, double maxWords) { { std::vector<std::string> t; std::string w; for (unsigned char c : s) { if (std::isspace(c)) { if (!w.empty()) { t.push_back(w); w.clear(); } } else w += static_cast<char>(c); } if (!w.empty()) t.push_back(w); int m = static_cast<int>(maxWords); std::string r; for (int i = 0; i < m && i < static_cast<int>(t.size()); ++i) { if (!r.empty()) r += " "; r += t[i]; } return r + (static_cast<int>(t.size()) > m ? "..." : ""); } }
inline std::string padCenter(std::string s, double width) { { int w = static_cast<int>(width); if (static_cast<int>(s.size()) >= w) return s; int pad = w - static_cast<int>(s.size()); int left = pad / 2; return std::string(left, ' ') + s + std::string(pad - left, ' '); } }
} // namespace

namespace afrilang::runtime::med::textsearch {
inline std::vector<double> findAll(std::string s, std::string sub) { { std::vector<double> r; if (sub.empty()) return r; for (std::size_t i = 0; i + sub.size() <= s.size(); ++i) if (s.compare(i, sub.size(), sub) == 0) r.push_back(static_cast<double>(i)); return r; } }
inline double countOccurrences(std::string s, std::string sub) { return static_cast<double>(findAll(s, sub).size()); }
inline bool containsIgnoreCase(std::string s, std::string sub) { { std::string a = s, b = sub; for (char& c : a) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c))); for (char& c : b) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c))); return a.find(b) != std::string::npos; } }
inline std::string replaceAll(std::string s, std::string from, std::string to) { { if (from.empty()) return s; std::string r; for (std::size_t i = 0; i < s.size(); ) { if (i + from.size() <= s.size() && s.compare(i, from.size(), from) == 0) { r += to; i += from.size(); } else { r += s[i++]; } } return r; } }
inline double indexOf(std::string s, std::string sub) { { auto p = s.find(sub); return p == std::string::npos ? -1 : static_cast<double>(p); } }
} // namespace

namespace afrilang::runtime::med::accentstrip {
inline std::string stripAccents(std::string s) { { std::string r; for (unsigned char c : s) r += static_cast<char>(c < 128 ? c : '?'); return r; } }
inline std::string toAsciiFold(std::string s) { { std::string r; for (unsigned char c : s) r += static_cast<char>(std::isprint(c) ? c : '?'); return r; } }
inline std::string removeNonPrintable(std::string s) { { std::string r; for (unsigned char c : s) if (std::isprint(c) || c == '\n' || c == '\t') r += static_cast<char>(c); return r; } }
inline std::string collapseSpaces(std::string s) { { std::string r; bool sp = false; for (unsigned char c : s) { if (std::isspace(c)) { if (!sp) r += ' '; sp = true; } else { r += static_cast<char>(c); sp = false; } } while (!r.empty() && r.front() == ' ') r.erase(r.begin()); while (!r.empty() && r.back() == ' ') r.pop_back(); return r; } }
} // namespace

namespace afrilang::runtime::med::casemap2 {
inline std::string titleCase(std::string s) { { std::string r; bool cap = true; for (unsigned char c : s) { if (std::isspace(c)) { r += static_cast<char>(c); cap = true; } else if (cap) { r += static_cast<char>(std::toupper(c)); cap = false; } else r += static_cast<char>(std::tolower(c)); } return r; } }
inline std::string swapCase(std::string s) { { std::string r; for (unsigned char c : s) r += static_cast<char>(std::isupper(c) ? std::tolower(c) : std::toupper(c)); return r; } }
inline std::string camelToSnake(std::string s) { { std::string r; for (std::size_t i = 0; i < s.size(); ++i) { if (i > 0 && std::isupper(static_cast<unsigned char>(s[i]))) r += '_'; r += static_cast<char>(std::tolower(static_cast<unsigned char>(s[i]))); } return r; } }
inline std::string snakeToCamel(std::string s) { { std::string r; bool up = false; for (char c : s) { if (c == '_') up = true; else { r += up ? static_cast<char>(std::toupper(static_cast<unsigned char>(c))) : c; up = false; } } return r; } }
} // namespace

namespace afrilang::runtime::med::textdiff2 {
inline double commonPrefixLen(std::string a, std::string b) { { std::size_t i = 0; while (i < a.size() && i < b.size() && a[i] == b[i]) ++i; return static_cast<double>(i); } }
inline double commonSuffixLen(std::string a, std::string b) { { std::size_t i = 0; while (i < a.size() && i < b.size() && a[a.size()-1-i] == b[b.size()-1-i]) ++i; return static_cast<double>(i); } }
inline double levenshtein(std::string a, std::string b) { { std::vector<std::vector<int>> dp(a.size()+1, std::vector<int>(b.size()+1)); for (std::size_t i = 0; i <= a.size(); ++i) dp[i][0] = static_cast<int>(i); for (std::size_t j = 0; j <= b.size(); ++j) dp[0][j] = static_cast<int>(j); for (std::size_t i = 1; i <= a.size(); ++i) for (std::size_t j = 1; j <= b.size(); ++j) { int cost = a[i-1]==b[j-1] ? 0 : 1; dp[i][j] = std::min({dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+cost}); } return static_cast<double>(dp[a.size()][b.size()]); } }
inline double similarityRatio(std::string a, std::string b) { { double d = levenshtein(a, b); double m = std::max(a.size(), b.size()); return m == 0 ? 1 : 1.0 - d / m; } }
} // namespace

namespace afrilang::runtime::med::regexlite {
inline bool matchDigits(std::string s) { { if (s.empty()) return false; for (char c : s) if (!std::isdigit(static_cast<unsigned char>(c))) return false; return true; } }
inline bool matchAlpha(std::string s) { { if (s.empty()) return false; for (char c : s) if (!std::isalpha(static_cast<unsigned char>(c))) return false; return true; } }
inline bool matchAlnum(std::string s) { { if (s.empty()) return false; for (char c : s) if (!std::isalnum(static_cast<unsigned char>(c))) return false; return true; } }
inline std::string extractDigits(std::string s) { { std::string r; for (char c : s) if (std::isdigit(static_cast<unsigned char>(c))) r += c; return r; } }
inline std::string extractAlpha(std::string s) { { std::string r; for (char c : s) if (std::isalpha(static_cast<unsigned char>(c))) r += c; return r; } }
} // namespace

namespace afrilang::runtime::med::motfreq {
inline double wordFrequency(std::string s, std::string word) { { int c = 0; std::string w; for (unsigned char ch : s) { if (std::isspace(ch)) { if (!w.empty() && w == word) ++c; w.clear(); } else w += static_cast<char>(ch); } if (!w.empty() && w == word) ++c; return static_cast<double>(c); } }
inline std::string mostFrequentWord(std::string s) { { std::map<std::string,int> m; std::string w; for (unsigned char ch : s) { if (std::isspace(ch)) { if (!w.empty()) ++m[w]; w.clear(); } else w += static_cast<char>(ch); } if (!w.empty()) ++m[w]; if (m.empty()) return ""; return std::max_element(m.begin(), m.end(), [](auto&a,auto&b){return a.second<b.second;})->first; } }
inline double uniqueWords(std::string s) { { std::map<std::string,int> m; std::string w; for (unsigned char ch : s) { if (std::isspace(ch)) { if (!w.empty()) ++m[w]; w.clear(); } else w += static_cast<char>(ch); } if (!w.empty()) ++m[w]; return static_cast<double>(m.size()); } }
inline double lexicalDensity(std::string s) { { int total = 0, unique = 0; std::map<std::string,int> m; std::string w; for (unsigned char ch : s) { if (std::isspace(ch)) { if (!w.empty()) { ++total; ++m[w]; w.clear(); } } else w += static_cast<char>(ch); } if (!w.empty()) { ++total; ++m[w]; } for (auto& p : m) if (p.second == 1) ++unique; return total == 0 ? 0 : static_cast<double>(unique) / total; } }
} // namespace

namespace afrilang::runtime::med::numstats {
inline double sum(std::vector<double> v) { if (v.empty()) return 0; return std::accumulate(v.begin(), v.end(), 0.0); }
inline double mean(std::vector<double> v) { if (v.empty()) return 0; return std::accumulate(v.begin(), v.end(), 0.0) / v.size(); }
inline double minVal(std::vector<double> v) { if (v.empty()) return 0; return *std::min_element(v.begin(), v.end()); }
inline double maxVal(std::vector<double> v) { if (v.empty()) return 0; return *std::max_element(v.begin(), v.end()); }
inline double range(std::vector<double> v) { if (v.empty()) return 0; return *std::max_element(v.begin(), v.end()) - *std::min_element(v.begin(), v.end()); }
} // namespace

namespace afrilang::runtime::med::listmedian {
inline double median(std::vector<double> v) { { if (v.empty()) return 0; auto t = v; std::sort(t.begin(), t.end()); std::size_t n = t.size(); return n % 2 ? t[n/2] : (t[n/2-1] + t[n/2]) / 2.0; } }
inline double q1(std::vector<double> v) { { if (v.size() < 2) return median(v); auto t = v; std::sort(t.begin(), t.end()); return t[t.size()/4]; } }
inline double q3(std::vector<double> v) { { if (v.size() < 2) return median(v); auto t = v; std::sort(t.begin(), t.end()); return t[3*t.size()/4]; } }
inline double iqr(std::vector<double> v) { return q3(v) - q1(v); }
} // namespace

namespace afrilang::runtime::med::listvar {
inline double variance(std::vector<double> v) { { if (v.size() < 2) return 0; double m = 0; for (double x : v) m += x; m /= v.size(); double s = 0; for (double x : v) s += (x-m)*(x-m); return s / (v.size()-1); } }
inline double stddev(std::vector<double> v) { return std::sqrt(variance(v)); }
inline double popVariance(std::vector<double> v) { { if (v.empty()) return 0; double m = 0; for (double x : v) m += x; m /= v.size(); double s = 0; for (double x : v) s += (x-m)*(x-m); return s / v.size(); } }
inline double popStddev(std::vector<double> v) { return std::sqrt(popVariance(v)); }
} // namespace

namespace afrilang::runtime::med::listmode {
inline double mode(std::vector<double> v) { { if (v.empty()) return 0; std::map<long long,int> m; for (double x : v) ++m[static_cast<long long>(x*1000)]; return static_cast<double>(std::max_element(m.begin(), m.end(), [](auto&a,auto&b){return a.second<b.second;})->first) / 1000.0; } }
inline double modeCount(std::vector<double> v) { { if (v.empty()) return 0; std::map<long long,int> m; for (double x : v) ++m[static_cast<long long>(x*1000)]; return static_cast<double>(std::max_element(m.begin(), m.end(), [](auto&a,auto&b){return a.second<b.second;})->second); } }
inline double uniqueCount(std::vector<double> v) { { std::map<long long,int> m; for (double x : v) ++m[static_cast<long long>(x*1000)]; return static_cast<double>(m.size()); } }
inline double duplicateCount(std::vector<double> v) { return static_cast<double>(v.size()) - uniqueCount(v); }
} // namespace

namespace afrilang::runtime::med::listcum {
inline std::vector<double> cumSum(std::vector<double> v) { { std::vector<double> r; double s = 0; for (double x : v) { s += x; r.push_back(s); } return r; } }
inline std::vector<double> cumProd(std::vector<double> v) { { std::vector<double> r; double p = 1; for (double x : v) { p *= x; r.push_back(p); } return r; } }
inline std::vector<double> diffs(std::vector<double> v) { { std::vector<double> r; for (std::size_t i = 1; i < v.size(); ++i) r.push_back(v[i]-v[i-1]); return r; } }
inline std::vector<double> pctChange(std::vector<double> v) { { std::vector<double> r; for (std::size_t i = 1; i < v.size(); ++i) r.push_back(v[i-1]==0 ? 0 : (v[i]-v[i-1])/v[i-1]*100.0); return r; } }
} // namespace

namespace afrilang::runtime::med::listnorm {
inline std::vector<double> normalize(std::vector<double> v) { { if (v.empty()) return v; double mn = *std::min_element(v.begin(), v.end()); double mx = *std::max_element(v.begin(), v.end()); if (mx == mn) return v; std::vector<double> r; for (double x : v) r.push_back((x-mn)/(mx-mn)); return r; } }
inline std::vector<double> zScores(std::vector<double> v) { { if (v.empty()) return v; double m = 0; for (double x : v) m += x; m /= v.size(); double s = 0; for (double x : v) s += (x-m)*(x-m); s = v.size()>1 ? std::sqrt(s/(v.size()-1)) : 0; if (s == 0) return v; std::vector<double> r; for (double x : v) r.push_back((x-m)/s); return r; } }
inline std::vector<double> scaleTo100(std::vector<double> v) { { auto n = normalize(v); std::vector<double> r; for (double x : n) r.push_back(x*100.0); return r; } }
inline std::vector<double> demean(std::vector<double> v) { { double m = 0; for (double x : v) m += x; m /= v.empty()?1:v.size(); std::vector<double> r; for (double x : v) r.push_back(x-m); return r; } }
} // namespace

namespace afrilang::runtime::med::listcorr {
inline double covariance(std::vector<double> a, std::vector<double> b) { { if (a.size() != b.size() || a.size() < 2) return 0; double ma=0,mb=0; for (double x:a) ma+=x; for (double x:b) mb+=x; ma/=a.size(); mb/=b.size(); double s=0; for (std::size_t i=0;i<a.size();++i) s+=(a[i]-ma)*(b[i]-mb); return s/(a.size()-1); } }
inline double correlation(std::vector<double> a, std::vector<double> b) { { double sa=0,sb=0,ma=0,mb=0; for(double x:a)ma+=x; for(double x:b)mb+=x; ma/=a.size(); mb/=b.size(); for(double x:a)sa+=(x-ma)*(x-ma); for(double x:b)sb+=(x-mb)*(x-mb); sa=a.size()>1?std::sqrt(sa/(a.size()-1)):0; sb=b.size()>1?std::sqrt(sb/(b.size()-1)):0; return sa==0||sb==0?0:covariance(a,b)/(sa*sb); } }
inline double dotProduct(std::vector<double> a, std::vector<double> b) { { if (a.size() != b.size()) return 0; double s = 0; for (std::size_t i = 0; i < a.size(); ++i) s += a[i]*b[i]; return s; } }
inline double euclidean(std::vector<double> a, std::vector<double> b) { { if (a.size() != b.size()) return 0; double s = 0; for (std::size_t i = 0; i < a.size(); ++i) s += (a[i]-b[i])*(a[i]-b[i]); return std::sqrt(s); } }
} // namespace

namespace afrilang::runtime::med::listoutlier {
inline std::vector<double> outlierIndices(std::vector<double> v) { { std::vector<double> r; if (v.size() < 4) return r; auto t = v; std::sort(t.begin(), t.end()); double q1 = t[t.size()/4], q3 = t[3*t.size()/4], iq = q3-q1, lo = q1-1.5*iq, hi = q3+1.5*iq; for (std::size_t i = 0; i < v.size(); ++i) if (v[i] < lo || v[i] > hi) r.push_back(static_cast<double>(i)); return r; } }
inline double outlierCount(std::vector<double> v) { return static_cast<double>(outlierIndices(v).size()); }
inline std::vector<double> withoutOutliers(std::vector<double> v) { { auto idx = outlierIndices(v); std::vector<double> r; for (std::size_t i = 0; i < v.size(); ++i) { bool skip = false; for (double d : idx) if (static_cast<std::size_t>(d) == i) skip = true; if (!skip) r.push_back(v[i]); } return r; } }
inline std::vector<double> winsorize(std::vector<double> v, double pct) { { if (v.empty()) return v; auto t = v; std::sort(t.begin(), t.end()); std::size_t k = static_cast<std::size_t>(t.size() * pct / 100.0); double lo = t[k], hi = t[t.size()-1-k]; std::vector<double> r; for (double x : v) r.push_back(x < lo ? lo : (x > hi ? hi : x)); return r; } }
} // namespace

namespace afrilang::runtime::med::listquantile {
inline double quantile(std::vector<double> v, double q) { { if (v.empty()) return 0; auto t = v; std::sort(t.begin(), t.end()); double pos = q * (t.size()-1); std::size_t i = static_cast<std::size_t>(pos); double f = pos - i; return i+1 < t.size() ? t[i]*(1-f)+t[i+1]*f : t[i]; } }
inline double percentile(std::vector<double> v, double p) { return quantile(v, p/100.0); }
inline double decile(std::vector<double> v, double d) { return quantile(v, d/10.0); }
inline std::vector<double> rankOf(std::vector<double> v) { { auto t = v; std::sort(t.begin(), t.end()); std::vector<double> r; for (double x : v) r.push_back(static_cast<double>(std::lower_bound(t.begin(), t.end(), x) - t.begin())); return r; } }
} // namespace

namespace afrilang::runtime::med::listfreq {
inline std::vector<double> valueCounts(std::vector<double> v) { { std::map<long long,int> m; for (double x : v) ++m[static_cast<long long>(x*1000)]; std::vector<double> r; for (auto& p : m) r.push_back(static_cast<double>(p.second)); return r; } }
inline std::vector<double> histogram(std::vector<double> v, double bins) { { if (v.empty()) return {}; int b = static_cast<int>(bins); if (b <= 0) return {}; double mn = *std::min_element(v.begin(), v.end()); double mx = *std::max_element(v.begin(), v.end()); double w = (mx-mn)/b; if (w == 0) return std::vector<double>(b, static_cast<double>(v.size())); std::vector<double> r(b, 0); for (double x : v) { int i = static_cast<int>((x-mn)/w); if (i >= b) i = b-1; if (i < 0) i = 0; r[i] += 1; } return r; } }
inline std::vector<double> binEdges(std::vector<double> v, double bins) { { int b = static_cast<int>(bins); if (v.empty() || b <= 0) return {}; double mn = *std::min_element(v.begin(), v.end()); double mx = *std::max_element(v.begin(), v.end()); std::vector<double> r; for (int i = 0; i <= b; ++i) r.push_back(mn + (mx-mn)*i/b); return r; } }
inline double skewness(std::vector<double> v) { { if (v.size() < 3) return 0; double m=0; for(double x:v)m+=x; m/=v.size(); double s2=0,s3=0; for(double x:v){double d=x-m;s2+=d*d;s3+=d*d*d;} s2/=v.size(); s3/=v.size(); return s2==0?0:s3/std::pow(s2,1.5); } }
} // namespace

namespace afrilang::runtime::med::listmoving {
inline std::vector<double> movingAvg(std::vector<double> v, double window) { { std::vector<double> r; int w = static_cast<int>(window); if (w <= 0) return r; for (std::size_t i = 0; i + w <= v.size(); ++i) { double s = 0; for (int j = 0; j < w; ++j) s += v[i+j]; r.push_back(s/w); } return r; } }
inline std::vector<double> movingMax(std::vector<double> v, double window) { { std::vector<double> r; int w = static_cast<int>(window); for (std::size_t i = 0; i + w <= v.size(); ++i) r.push_back(*std::max_element(v.begin()+i, v.begin()+i+w)); return r; } }
inline std::vector<double> movingMin(std::vector<double> v, double window) { { std::vector<double> r; int w = static_cast<int>(window); for (std::size_t i = 0; i + w <= v.size(); ++i) r.push_back(*std::min_element(v.begin()+i, v.begin()+i+w)); return r; } }
inline std::vector<double> movingSum(std::vector<double> v, double window) { { std::vector<double> r; int w = static_cast<int>(window); for (std::size_t i = 0; i + w <= v.size(); ++i) { double s = 0; for (int j = 0; j < w; ++j) s += v[i+j]; r.push_back(s); } return r; } }
} // namespace

namespace afrilang::runtime::med::listscale {
inline std::vector<double> rescale(std::vector<double> v, double newMin, double newMax) { { if (v.empty()) return v; double mn = *std::min_element(v.begin(), v.end()); double mx = *std::max_element(v.begin(), v.end()); if (mx == mn) return v; std::vector<double> r; for (double x : v) r.push_back(newMin + (x-mn)/(mx-mn)*(newMax-newMin)); return r; } }
inline std::vector<double> clip(std::vector<double> v, double lo, double hi) { { std::vector<double> r; for (double x : v) r.push_back(x < lo ? lo : (x > hi ? hi : x)); return r; } }
inline std::vector<double> absValues(std::vector<double> v) { { std::vector<double> r; for (double x : v) r.push_back(std::fabs(x)); return r; } }
inline std::vector<double> negateAll(std::vector<double> v) { { std::vector<double> r; for (double x : v) r.push_back(-x); return r; } }
} // namespace

namespace afrilang::runtime::med::listsort {
inline std::vector<double> sortAsc(std::vector<double> v) { { auto r = v; std::sort(r.begin(), r.end()); return r; } }
inline std::vector<double> sortDesc(std::vector<double> v) { { auto r = v; std::sort(r.begin(), r.end(), std::greater<double>()); return r; } }
inline std::vector<std::string> sortTextAsc(std::vector<std::string> v) { { auto r = v; std::sort(r.begin(), r.end()); return r; } }
inline std::vector<std::string> sortTextDesc(std::vector<std::string> v) { { auto r = v; std::sort(r.begin(), r.end(), std::greater<std::string>()); return r; } }
inline bool isSorted(std::vector<double> v) { { for (std::size_t i = 1; i < v.size(); ++i) if (v[i] < v[i-1]) return false; return true; } }
} // namespace

namespace afrilang::runtime::med::listsearch {
inline double linearSearch(std::vector<double> v, double target) { { for (std::size_t i = 0; i < v.size(); ++i) if (v[i] == target) return static_cast<double>(i); return -1; } }
inline bool contains(std::vector<double> v, double target) { return linearSearch(v, target) >= 0; }
inline double countValue(std::vector<double> v, double target) { { int c = 0; for (double x : v) if (x == target) ++c; return static_cast<double>(c); } }
inline double lastIndexOf(std::vector<double> v, double target) { { for (int i = static_cast<int>(v.size())-1; i >= 0; --i) if (v[i] == target) return static_cast<double>(i); return -1; } }
} // namespace

namespace afrilang::runtime::med::listbinary {
inline double binarySearch(std::vector<double> v, double target) { { auto it = std::lower_bound(v.begin(), v.end(), target); return it != v.end() && *it == target ? static_cast<double>(it - v.begin()) : -1; } }
inline double lowerBound(std::vector<double> v, double target) { return static_cast<double>(std::lower_bound(v.begin(), v.end(), target) - v.begin()); }
inline double upperBound(std::vector<double> v, double target) { return static_cast<double>(std::upper_bound(v.begin(), v.end(), target) - v.begin()); }
inline std::vector<double> insertSorted(std::vector<double> v, double val) { { auto r = v; r.insert(std::lower_bound(r.begin(), r.end(), val), val); return r; } }
} // namespace

namespace afrilang::runtime::med::listunique2 {
inline std::vector<double> unique(std::vector<double> v) { { std::vector<double> r; std::map<long long,bool> seen; for (double x : v) { long long k = static_cast<long long>(x*1000); if (!seen[k]) { seen[k]=true; r.push_back(x); } } return r; } }
inline std::vector<std::string> uniqueText(std::vector<std::string> v) { { std::vector<std::string> r; std::map<std::string,bool> seen; for (auto& x : v) if (!seen[x]) { seen[x]=true; r.push_back(x); } return r; } }
inline std::vector<double> duplicates(std::vector<double> v) { { std::map<long long,int> m; for (double x : v) ++m[static_cast<long long>(x*1000)]; std::vector<double> r; for (auto& p : m) if (p.second > 1) r.push_back(static_cast<double>(p.first)/1000.0); return r; } }
inline double frequency(std::vector<double> v, double val) { { int c = 0; for (double x : v) if (x == val) ++c; return static_cast<double>(c); } }
} // namespace

namespace afrilang::runtime::med::listpartition {
inline std::vector<double> partitionAt(std::vector<double> v, double pivot) { { auto r = v; std::partition(r.begin(), r.end(), [&](double x){ return x < pivot; }); return r; } }
inline std::vector<double> splitHalf(std::vector<double> v) { { std::vector<double> r; for (std::size_t i = 0; i < v.size()/2; ++i) r.push_back(v[i]); return r; } }
inline std::vector<double> secondHalf(std::vector<double> v) { { std::vector<double> r; for (std::size_t i = v.size()/2; i < v.size(); ++i) r.push_back(v[i]); return r; } }
inline std::vector<double> filterGt(std::vector<double> v, double threshold) { { std::vector<double> r; for (double x : v) if (x > threshold) r.push_back(x); return r; } }
inline std::vector<double> filterLt(std::vector<double> v, double threshold) { { std::vector<double> r; for (double x : v) if (x < threshold) r.push_back(x); return r; } }
} // namespace

namespace afrilang::runtime::med::listtopk {
inline std::vector<double> topK(std::vector<double> v, double k) { { auto r = v; std::sort(r.begin(), r.end(), std::greater<double>()); if (static_cast<std::size_t>(k) < r.size()) r.resize(static_cast<std::size_t>(k)); return r; } }
inline std::vector<double> bottomK(std::vector<double> v, double k) { { auto r = v; std::sort(r.begin(), r.end()); if (static_cast<std::size_t>(k) < r.size()) r.resize(static_cast<std::size_t>(k)); return r; } }
inline double kthLargest(std::vector<double> v, double k) { { auto r = topK(v, k); return r.empty() ? 0 : r.back(); } }
inline double kthSmallest(std::vector<double> v, double k) { { auto r = bottomK(v, k); return r.empty() ? 0 : r.back(); } }
} // namespace

namespace afrilang::runtime::med::listmerge2 {
inline std::vector<double> mergeSorted(std::vector<double> a, std::vector<double> b) { { std::vector<double> r; std::size_t i = 0, j = 0; while (i < a.size() && j < b.size()) r.push_back(a[i] <= b[j] ? a[i++] : b[j++]); while (i < a.size()) r.push_back(a[i++]); while (j < b.size()) r.push_back(b[j++]); return r; } }
inline std::vector<double> mergeAll(std::vector<double> a, std::vector<double> b) { { std::vector<double> r = a; r.insert(r.end(), b.begin(), b.end()); return r; } }
inline std::vector<double> intersect(std::vector<double> a, std::vector<double> b) { { std::vector<double> r; for (double x : a) for (double y : b) if (x == y) r.push_back(x); return r; } }
inline std::vector<double> unionAll(std::vector<double> a, std::vector<double> b) { { auto r = mergeAll(a,b); std::sort(r.begin(), r.end()); r.erase(std::unique(r.begin(), r.end()), r.end()); return r; } }
} // namespace

namespace afrilang::runtime::med::listrotate2 {
inline std::vector<double> rotateLeft(std::vector<double> v, double n) { { if (v.empty()) return v; auto r = v; int k = static_cast<int>(n) % static_cast<int>(v.size()); if (k < 0) k += static_cast<int>(v.size()); std::rotate(r.begin(), r.begin()+k, r.end()); return r; } }
inline std::vector<double> rotateRight(std::vector<double> v, double n) { { if (v.empty()) return v; int k = static_cast<int>(v.size()) - static_cast<int>(n) % static_cast<int>(v.size()); return rotateLeft(v, k); } }
inline std::vector<double> reverseList(std::vector<double> v) { { auto r = v; std::reverse(r.begin(), r.end()); return r; } }
inline std::vector<double> shuffleSeed(std::vector<double> v, double seed) { { auto r = v; std::srand(static_cast<unsigned>(seed)); std::shuffle(r.begin(), r.end(), [](int n){ return std::rand() % (n+1); }); return r; } }
} // namespace

namespace afrilang::runtime::med::listchunk {
inline double chunkCount(std::vector<double> v, double size) { { int sz = static_cast<int>(size); return sz <= 0 ? 0 : static_cast<double>((v.size() + sz - 1) / sz); } }
inline std::vector<double> take(std::vector<double> v, double n) { { std::vector<double> r; int k = static_cast<int>(n); for (int i = 0; i < k && i < static_cast<int>(v.size()); ++i) r.push_back(v[i]); return r; } }
inline std::vector<double> drop(std::vector<double> v, double n) { { std::vector<double> r; int k = static_cast<int>(n); for (std::size_t i = k; i < v.size(); ++i) r.push_back(v[i]); return r; } }
inline std::vector<double> slice(std::vector<double> v, double start, double end) { { std::vector<double> r; int a = static_cast<int>(start), b = static_cast<int>(end); for (int i = a; i < b && i < static_cast<int>(v.size()); ++i) if (i >= 0) r.push_back(v[i]); return r; } }
inline std::vector<double> chunkAt(std::vector<double> v, double index, double size) { { int idx = static_cast<int>(index), sz = static_cast<int>(size); std::vector<double> r; std::size_t start = idx * sz; for (std::size_t i = start; i < start + sz && i < v.size(); ++i) r.push_back(v[i]); return r; } }
} // namespace

namespace afrilang::runtime::med::listzip2 {
inline std::vector<double> zipAdd(std::vector<double> a, std::vector<double> b) { { std::vector<double> r; std::size_t n = std::min(a.size(), b.size()); for (std::size_t i = 0; i < n; ++i) r.push_back(a[i] + b[i]); return r; } }
inline std::vector<double> zipMul(std::vector<double> a, std::vector<double> b) { { std::vector<double> r; std::size_t n = std::min(a.size(), b.size()); for (std::size_t i = 0; i < n; ++i) r.push_back(a[i] * b[i]); return r; } }
inline std::vector<double> zipSub(std::vector<double> a, std::vector<double> b) { { std::vector<double> r; std::size_t n = std::min(a.size(), b.size()); for (std::size_t i = 0; i < n; ++i) r.push_back(a[i] - b[i]); return r; } }
inline std::vector<double> zipMax(std::vector<double> a, std::vector<double> b) { { std::vector<double> r; std::size_t n = std::min(a.size(), b.size()); for (std::size_t i = 0; i < n; ++i) r.push_back(std::max(a[i], b[i])); return r; } }
} // namespace

namespace afrilang::runtime::med::textsplit2 {
inline std::vector<std::string> splitLines(std::string s) { { std::vector<std::string> r; std::string line; for (char c : s) { if (c == '\n') { r.push_back(line); line.clear(); } else line += c; } if (!line.empty() || (!s.empty() && s.back() == '\n')) r.push_back(line); return r; } }
inline std::vector<std::string> splitBy(std::string s, std::string delim) { { std::vector<std::string> r; if (delim.empty()) return r; std::size_t start = 0; for (std::size_t i = 0; i + delim.size() <= s.size(); ++i) if (s.compare(i, delim.size(), delim) == 0) { r.push_back(s.substr(start, i-start)); start = i + delim.size(); i += delim.size()-1; } r.push_back(s.substr(start)); return r; } }
inline std::vector<std::string> splitWords(std::string s) { { std::vector<std::string> r; std::string w; for (unsigned char c : s) { if (std::isspace(c)) { if (!w.empty()) { r.push_back(w); w.clear(); } } else w += static_cast<char>(c); } if (!w.empty()) r.push_back(w); return r; } }
inline std::vector<std::string> splitChars(std::string s) { { std::vector<std::string> r; for (char c : s) r.push_back(std::string(1, c)); return r; } }
} // namespace

namespace afrilang::runtime::med::textjoin2 {
inline std::string joinLines(std::vector<std::string> parts) { { std::string r; for (std::size_t i = 0; i < parts.size(); ++i) { if (i) r += "\n"; r += parts[i]; } return r; } }
inline std::string joinWith(std::vector<std::string> parts, std::string delim) { { std::string r; for (std::size_t i = 0; i < parts.size(); ++i) { if (i) r += delim; r += parts[i]; } return r; } }
inline std::string joinComma(std::vector<std::string> parts) { return joinWith(parts, ", "); }
inline std::string joinSpace(std::vector<std::string> parts) { return joinWith(parts, " "); }
} // namespace

namespace afrilang::runtime::med::listfilter2 {
inline std::vector<std::string> filterEmpty(std::vector<std::string> v) { { std::vector<std::string> r; for (auto& s : v) if (!s.empty()) r.push_back(s); return r; } }
inline std::vector<std::string> filterLonger(std::vector<std::string> v, double minLen) { { std::vector<std::string> r; int m = static_cast<int>(minLen); for (auto& s : v) if (static_cast<int>(s.size()) >= m) r.push_back(s); return r; } }
inline std::vector<std::string> filterContains(std::vector<std::string> v, std::string sub) { { std::vector<std::string> r; for (auto& s : v) if (s.find(sub) != std::string::npos) r.push_back(s); return r; } }
inline std::vector<std::string> filterStarts(std::vector<std::string> v, std::string prefix) { { std::vector<std::string> r; for (auto& s : v) if (s.rfind(prefix, 0) == 0) r.push_back(s); return r; } }
} // namespace

namespace afrilang::runtime::med::listmap2 {
inline std::vector<std::string> mapUpper(std::vector<std::string> v) { { std::vector<std::string> r; for (auto& s : v) { std::string t = s; for (char& c : t) c = static_cast<char>(std::toupper(static_cast<unsigned char>(c))); r.push_back(t); } return r; } }
inline std::vector<std::string> mapLower(std::vector<std::string> v) { { std::vector<std::string> r; for (auto& s : v) { std::string t = s; for (char& c : t) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c))); r.push_back(t); } return r; } }
inline std::vector<std::string> mapTrim(std::vector<std::string> v) { { std::vector<std::string> r; for (auto& s : v) { std::size_t a = s.find_first_not_of(" \t\r\n"); std::size_t b = s.find_last_not_of(" \t\r\n"); r.push_back(a == std::string::npos ? "" : s.substr(a, b-a+1)); } return r; } }
inline std::vector<double> mapLength(std::vector<std::string> v) { { std::vector<double> r; for (auto& s : v) r.push_back(static_cast<double>(s.size())); return r; } }
} // namespace

namespace afrilang::runtime::med::listgroup2 {
inline std::vector<std::string> groupByLen(std::vector<std::string> v, double len) { { std::vector<std::string> r; int l = static_cast<int>(len); for (auto& s : v) if (static_cast<int>(s.size()) == l) r.push_back(s); return r; } }
inline std::vector<std::string> groupByPrefix(std::vector<std::string> v, std::string prefix) { { std::vector<std::string> r; for (auto& s : v) if (s.rfind(prefix, 0) == 0) r.push_back(s); return r; } }
inline std::string longestString(std::vector<std::string> v) { { if (v.empty()) return ""; return *std::max_element(v.begin(), v.end(), [](auto&a,auto&b){return a.size()<b.size();}); } }
inline std::string shortestString(std::vector<std::string> v) { { if (v.empty()) return ""; return *std::min_element(v.begin(), v.end(), [](auto&a,auto&b){return a.size()<b.size();}); } }
} // namespace

namespace afrilang::runtime::med::listpick2 {
inline std::string pickFirst(std::vector<std::string> v) { return v.empty() ? "" : v.front(); }
inline std::string pickLast(std::vector<std::string> v) { return v.empty() ? "" : v.back(); }
inline std::string pickAt(std::vector<std::string> v, double index) { { int i = static_cast<int>(index); return i >= 0 && i < static_cast<int>(v.size()) ? v[i] : ""; } }
inline std::string pickRandom(std::vector<std::string> v, double seed) { { if (v.empty()) return ""; std::srand(static_cast<unsigned>(seed)); return v[std::rand() % v.size()]; } }
} // namespace

namespace afrilang::runtime::med::datecalc {
inline double daysBetween(std::string d1, std::string d2) { { try { int y1=std::stoi(d1.substr(0,4)), m1=std::stoi(d1.substr(5,2)), day1=std::stoi(d1.substr(8,2)); int y2=std::stoi(d2.substr(0,4)), m2=std::stoi(d2.substr(5,2)), day2=std::stoi(d2.substr(8,2)); auto f=[](int y,int m,int d){ if(m<=2){y--;m+=12;} return 365*y+y/4-y/100+y/400+153*(m-3)/5+d-678882; }; return static_cast<double>(f(y2,m2,day2)-f(y1,m1,day1)); } catch(...) { return 0; } } }
inline std::string addDays(std::string date, double days) { { try { int y=std::stoi(date.substr(0,4)), m=std::stoi(date.substr(5,2)), d=std::stoi(date.substr(8,2)); d += static_cast<int>(days); while (d > 28) { int md[]={0,31,28,31,30,31,30,31,31,30,31,30,31}; if (m==2 && (y%4==0 && (y%100!=0||y%400==0))) md[2]=29; if (d <= md[m]) break; d -= md[m]; if (++m > 12) { m=1; ++y; } } std::ostringstream os; os << y << '-' << std::setfill('0') << std::setw(2) << m << '-' << std::setw(2) << d; return os.str(); } catch(...) { return date; } } }
inline bool isLeapYear(double year) { { int y = static_cast<int>(year); return y%4==0 && (y%100!=0 || y%400==0); } }
inline double daysInMonth(double year, double month) { { int y=static_cast<int>(year), m=static_cast<int>(month); int md[]={0,31,28,31,30,31,30,31,31,30,31,30,31}; if (m==2 && isLeapYear(y)) return 29; return m>=1&&m<=12?md[m]:0; } }
inline double weekday(std::string date) { { try { int y=std::stoi(date.substr(0,4)), m=std::stoi(date.substr(5,2)), d=std::stoi(date.substr(8,2)); if (m<3) { m+=12; y-=1; } return static_cast<double>((d + 2*m + 3*(m+1)/5 + y + y/4 - y/100 + y/400) % 7); } catch(...) { return 0; } } }
} // namespace

namespace afrilang::runtime::med::datefmt2 {
inline std::string formatIso(double year, double month, double day) { { std::ostringstream os; os << static_cast<int>(year) << '-' << std::setfill('0') << std::setw(2) << static_cast<int>(month) << '-' << std::setw(2) << static_cast<int>(day); return os.str(); } }
inline double parseYear(std::string date) { { try { return static_cast<double>(std::stoi(date.substr(0,4))); } catch(...) { return 0; } } }
inline double parseMonth(std::string date) { { try { return static_cast<double>(std::stoi(date.substr(5,2))); } catch(...) { return 0; } } }
inline double parseDay(std::string date) { { try { return static_cast<double>(std::stoi(date.substr(8,2))); } catch(...) { return 0; } } }
} // namespace

namespace afrilang::runtime::med::duration2 {
inline double hoursToMinutes(double h) { return h * 60.0; }
inline double minutesToSeconds(double m) { return m * 60.0; }
inline double daysToHours(double d) { return d * 24.0; }
inline double secondsToHours(double s) { return s / 3600.0; }
} // namespace

namespace afrilang::runtime::med::timestamp2 {
inline double epochDays(std::string date) { { try { int y1=1970,m1=1,d1=1,y2=std::stoi(date.substr(0,4)),m2=std::stoi(date.substr(5,2)),d2=std::stoi(date.substr(8,2)); auto f=[](int y,int m,int d){ if(m<=2){y--;m+=12;} return 365*y+y/4-y/100+y/400+153*(m-3)/5+d-678882; }; return static_cast<double>(f(y2,m2,d2)-f(y1,m1,d1)); } catch(...) { return 0; } } }
inline std::string fromEpochDays(double days) { { try { int total=678882+static_cast<int>(days); int y=(400*total-100)/146097; int rem=total-y*365-y/4+y/100-y/400; int mo=(5*rem+2)/153; int d=rem-(153*mo+2)/5; if(mo>12){y+=mo/12;mo=mo%12+1;} std::ostringstream os; os<<y<<'-'<<std::setfill('0')<<std::setw(2)<<mo<<'-'<<std::setw(2)<<d; return os.str(); } catch(...) { return "1970-01-01"; } } }
inline bool isValidDate(std::string date) { { try { int y=std::stoi(date.substr(0,4)), m=std::stoi(date.substr(5,2)), d=std::stoi(date.substr(8,2)); int md[]={0,31,28,31,30,31,30,31,31,30,31,30,31}; if (m==2 && (y%4==0 && (y%100!=0||y%400==0))) md[2]=29; return m>=1&&m<=12&&d>=1&&d<=md[m]; } catch(...) { return false; } } }
inline double todayOffset(std::string date, double offset) { return offset; }
} // namespace

namespace afrilang::runtime::med::calendar2 {
inline double quarterOf(double month) { return static_cast<double>((static_cast<int>(month)-1)/3 + 1); }
inline double weekOfYear(std::string date) { { try { int y=std::stoi(date.substr(0,4)), m=std::stoi(date.substr(5,2)), d=std::stoi(date.substr(8,2)); if (m<3) { m+=12; y-=1; } double w=(d + 2*m + 3*(m+1)/5 + y + y/4 - y/100 + y/400) % 7; return std::floor((d + w) / 7.0) + 1; } catch(...) { return 0; } } }
inline std::string monthName(double month) { { static const char* n[]={"","janvier","fevrier","mars","avril","mai","juin","juillet","aout","septembre","octobre","novembre","decembre"}; int m=static_cast<int>(month); return m>=1&&m<=12?n[m]:""; } }
inline std::string dayName(std::string date) { { static const char* n[]={"dimanche","lundi","mardi","mercredi","jeudi","vendredi","samedi"}; try { int y=std::stoi(date.substr(0,4)), m=std::stoi(date.substr(5,2)), d=std::stoi(date.substr(8,2)); if (m<3) { m+=12; y-=1; } int w=(d + 2*m + 3*(m+1)/5 + y + y/4 - y/100 + y/400) % 7; return w>=0&&w<=6?n[w]:""; } catch(...) { return ""; } } }
} // namespace

namespace afrilang::runtime::med::agecalc {
inline double ageYears(std::string birth, std::string today) { { try { return static_cast<double>(std::stoi(today.substr(0,4)) - std::stoi(birth.substr(0,4))); } catch(...) { return 0; } } }
inline double ageMonths(std::string birth, std::string today) { return ageYears(birth, today) * 12.0; }
inline double ageDays(std::string birth, std::string today) { { try { int y1=std::stoi(birth.substr(0,4)), m1=std::stoi(birth.substr(5,2)), d1=std::stoi(birth.substr(8,2)); int y2=std::stoi(today.substr(0,4)), m2=std::stoi(today.substr(5,2)), d2=std::stoi(today.substr(8,2)); auto f=[](int y,int m,int d){ if(m<=2){y--;m+=12;} return 365*y+y/4-y/100+y/400+153*(m-3)/5+d-678882; }; return static_cast<double>(f(y2,m2,d2)-f(y1,m1,d1)); } catch(...) { return 0; } } }
inline bool isBirthday(std::string birth, std::string today) { return birth.substr(5) == today.substr(5); }
} // namespace

namespace afrilang::runtime::med::timezone2 {
inline double utcOffsetHours(double offset) { return offset; }
inline std::string toUtc(std::string localTime, double offsetHours) { { double h = std::stod(localTime.substr(0,2)) - offsetHours; while (h < 0) h += 24; while (h >= 24) h -= 24; std::ostringstream os; os << std::setfill('0') << std::setw(2) << static_cast<int>(h) << localTime.substr(2); return os.str(); } }
inline std::string fromUtc(std::string utcTime, double offsetHours) { { double h = std::stod(utcTime.substr(0,2)) + offsetHours; while (h < 0) h += 24; while (h >= 24) h -= 24; std::ostringstream os; os << std::setfill('0') << std::setw(2) << static_cast<int>(h) << utcTime.substr(2); return os.str(); } }
inline std::string formatTime(double hours, double minutes) { { std::ostringstream os; os << std::setfill('0') << std::setw(2) << static_cast<int>(hours) << ':' << std::setw(2) << static_cast<int>(minutes); return os.str(); } }
} // namespace

namespace afrilang::runtime::med::period2 {
inline double monthsBetween(std::string d1, std::string d2) { { try { return (std::stoi(d2.substr(0,4))-std::stoi(d1.substr(0,4)))*12 + (std::stoi(d2.substr(5,2))-std::stoi(d1.substr(5,2))); } catch(...) { return 0; } } }
inline double yearsBetween(std::string d1, std::string d2) { return monthsBetween(d1, d2) / 12.0; }
inline std::string addMonths(std::string date, double months) { { try { int y=std::stoi(date.substr(0,4)), m=std::stoi(date.substr(5,2)), d=std::stoi(date.substr(8,2)); m += static_cast<int>(months); while (m > 12) { m -= 12; ++y; } while (m < 1) { m += 12; --y; } std::ostringstream os; os << y << '-' << std::setfill('0') << std::setw(2) << m << '-' << std::setw(2) << d; return os.str(); } catch(...) { return date; } } }
inline std::string endOfMonth(std::string date) { { try { int y=std::stoi(date.substr(0,4)), m=std::stoi(date.substr(5,2)); int md[]={0,31,28,31,30,31,30,31,31,30,31,30,31}; if (m==2 && (y%4==0 && (y%100!=0||y%400==0))) md[2]=29; std::ostringstream os; os << y << '-' << std::setfill('0') << std::setw(2) << m << '-' << std::setw(2) << md[m]; return os.str(); } catch(...) { return date; } } }
} // namespace

namespace afrilang::runtime::med::chrono2 {
inline double elapsedDays(std::string start, std::string end) { { try { int y1=std::stoi(start.substr(0,4)), m1=std::stoi(start.substr(5,2)), d1=std::stoi(start.substr(8,2)); int y2=std::stoi(end.substr(0,4)), m2=std::stoi(end.substr(5,2)), d2=std::stoi(end.substr(8,2)); auto f=[](int y,int m,int d){ if(m<=2){y--;m+=12;} return 365*y+y/4-y/100+y/400+153*(m-3)/5+d-678882; }; return static_cast<double>(f(y2,m2,d2)-f(y1,m1,d1)); } catch(...) { return 0; } } }
inline bool isWeekend(std::string date) { { try { int y=std::stoi(date.substr(0,4)), m=std::stoi(date.substr(5,2)), d=std::stoi(date.substr(8,2)); if (m<3) { m+=12; y-=1; } int w=(d + 2*m + 3*(m+1)/5 + y + y/4 - y/100 + y/400) % 7; return w == 0 || w == 6; } catch(...) { return false; } } }
inline std::string nextWeekday(std::string date) { return date; }
inline double businessDays(std::string start, std::string end) { { double total = elapsedDays(start, end); return total * 5.0 / 7.0; } }
} // namespace

namespace afrilang::runtime::med::season2 {
inline std::string seasonOf(double month) { { int m=static_cast<int>(month); if(m==12||m<=2) return "hiver"; if(m<=5) return "printemps"; if(m<=8) return "ete"; return "automne"; } }
inline bool isSummer(double month) { { int m=static_cast<int>(month); return m>=6 && m<=8; } }
inline bool isWinter(double month) { { int m=static_cast<int>(month); return m==12 || m<=2; } }
inline double daylightHours(double month, double lat) { { int m=static_cast<int>(month); double base = 12.0 + 4.0 * std::sin((m-3)*3.141592653589793/6.0); return base * (1.0 - std::fabs(lat)/90.0 * 0.3); } }
} // namespace

namespace afrilang::runtime::med::uriparse {
inline std::string getScheme(std::string url) { { auto p = url.find("://"); return p == std::string::npos ? "" : url.substr(0, p); } }
inline std::string getHost(std::string url) { { auto s = url.find("://"); if (s == std::string::npos) return ""; auto start = s + 3; auto end = url.find('/', start); return url.substr(start, end == std::string::npos ? std::string::npos : end - start); } }
inline std::string getPath(std::string url) { { auto s = url.find("://"); if (s == std::string::npos) return url; auto start = url.find('/', s + 3); return start == std::string::npos ? "/" : url.substr(start); } }
inline std::string getQuery(std::string url) { { auto p = url.find('?'); return p == std::string::npos ? "" : url.substr(p + 1); } }
inline bool hasQuery(std::string url) { return url.find('?') != std::string::npos; }
} // namespace

namespace afrilang::runtime::med::urlbuild {
inline std::string buildUrl(std::string scheme, std::string host, std::string path) { return scheme + "://" + host + path; }
inline std::string buildWithQuery(std::string base, std::string query) { return query.empty() ? base : base + "?" + query; }
inline std::string encodeParam(std::string key, std::string value) { { std::string r = key + "="; for (char c : value) r += (c == ' ') ? "+" : std::string(1, c); return r; } }
inline std::string joinParams(std::vector<std::string> params) { { std::string r; for (std::size_t i = 0; i < params.size(); ++i) { if (i) r += "&"; r += params[i]; } return r; } }
} // namespace

namespace afrilang::runtime::med::queryparse {
inline std::vector<std::string> parseQuery(std::string query) { { std::vector<std::string> r; std::string cur; for (char c : query) { if (c == '&') { if (!cur.empty()) r.push_back(cur); cur.clear(); } else cur += c; } if (!cur.empty()) r.push_back(cur); return r; } }
inline std::string getParam(std::string query, std::string key) { { auto parts = parseQuery(query); for (auto& p : parts) { auto eq = p.find('='); if (eq != std::string::npos && p.substr(0, eq) == key) return p.substr(eq + 1); } return ""; } }
inline double paramCount(std::string query) { return static_cast<double>(parseQuery(query).size()); }
inline bool hasParam(std::string query, std::string key) { return !getParam(query, key).empty(); }
} // namespace

namespace afrilang::runtime::med::jsonparse2 {
inline std::string parseString(std::string json, std::string key) { { std::string search = "\"" + key + "\":"; auto p = json.find(search); if (p == std::string::npos) return ""; p += search.size(); while (p < json.size() && std::isspace(static_cast<unsigned char>(json[p]))) ++p; if (p >= json.size()) return ""; if (json[p] == '"') { auto end = json.find('"', p + 1); return end == std::string::npos ? "" : json.substr(p + 1, end - p - 1); } return ""; } }
inline double parseNumber(std::string json, std::string key) { { std::string search = "\"" + key + "\":"; auto p = json.find(search); if (p == std::string::npos) return 0; p += search.size(); try { return std::stod(json.substr(p)); } catch(...) { return 0; } } }
inline bool isValidJson(std::string json) { return !json.empty() && json.front() == '{' && json.back() == '}'; }
inline double keyCount(std::string json) { { int c = 0; for (std::size_t i = 0; i < json.size(); ++i) if (json[i] == '"' && (i == 0 || json[i-1] != '\\')) ++c; return static_cast<double>(c / 2); } }
} // namespace

namespace afrilang::runtime::med::jsonbuild2 {
inline std::string buildObject(std::vector<std::string> pairs) { { std::string r = "{"; for (std::size_t i = 0; i < pairs.size(); ++i) { if (i) r += ","; r += pairs[i]; } return r + "}"; } }
inline std::string buildArray(std::vector<std::string> items) { { std::string r = "["; for (std::size_t i = 0; i < items.size(); ++i) { if (i) r += ","; r += "\"" + items[i] + "\""; } return r + "]"; } }
inline std::string quoteKey(std::string key, std::string value) { return "\"" + key + "\":\"" + value + "\""; }
inline std::string quoteNum(std::string key, double value) { return "\"" + key + "\":" + std::to_string(static_cast<long long>(value)); }
} // namespace

namespace afrilang::runtime::med::csvparse2 {
inline std::vector<std::string> parseRow(std::string line) { { std::vector<std::string> r; std::string cur; bool inQ = false; for (char c : line) { if (c == '"') inQ = !inQ; else if (c == ',' && !inQ) { r.push_back(cur); cur.clear(); } else cur += c; } r.push_back(cur); return r; } }
inline std::string getField(std::string line, double index) { { auto f = parseRow(line); int i = static_cast<int>(index); return i >= 0 && i < static_cast<int>(f.size()) ? f[i] : ""; } }
inline double fieldCount(std::string line) { return static_cast<double>(parseRow(line).size()); }
inline std::vector<std::string> parseAll(std::string csv) { { std::vector<std::string> r; std::string line; for (char c : csv) { if (c == '\n') { if (!line.empty()) r.push_back(line); line.clear(); } else line += c; } if (!line.empty()) r.push_back(line); return r; } }
} // namespace

namespace afrilang::runtime::med::csvbuild2 {
inline std::string buildRow(std::vector<std::string> fields) { { std::string r; for (std::size_t i = 0; i < fields.size(); ++i) { if (i) r += ","; r += fields[i]; } return r; } }
inline std::string escapeField(std::string field) { { if (field.find(',') != std::string::npos || field.find('"') != std::string::npos) return "\"" + field + "\""; return field; } }
inline std::string buildCsv(std::vector<std::string> rows) { { std::string r; for (std::size_t i = 0; i < rows.size(); ++i) { if (i) r += "\n"; r += rows[i]; } return r; } }
inline std::string quoteField(std::string field) { return "\"" + field + "\""; }
} // namespace

namespace afrilang::runtime::med::pathparse2 {
inline std::string basename(std::string path) { { auto p = path.find_last_of('/'); return p == std::string::npos ? path : path.substr(p + 1); } }
inline std::string dirname(std::string path) { { auto p = path.find_last_of('/'); return p == std::string::npos ? "." : path.substr(0, p); } }
inline std::string extension(std::string path) { { auto p = path.find_last_of('.'); return p == std::string::npos ? "" : path.substr(p + 1); } }
inline std::string stem(std::string path) { { std::string b = basename(path); auto p = b.find_last_of('.'); return p == std::string::npos ? b : b.substr(0, p); } }
inline std::string joinPath(std::string a, std::string b) { return a.back() == '/' ? a + b : a + "/" + b; }
} // namespace

namespace afrilang::runtime::med::mimeparse2 {
inline std::string mainType(std::string mime) { { auto p = mime.find('/'); return p == std::string::npos ? mime : mime.substr(0, p); } }
inline std::string subType(std::string mime) { { auto p = mime.find('/'); return p == std::string::npos ? "" : mime.substr(p + 1); } }
inline bool isText(std::string mime) { return mainType(mime) == "text"; }
inline bool isImage(std::string mime) { return mainType(mime) == "image"; }
} // namespace

namespace afrilang::runtime::med::httpparse2 {
inline double statusClass(double code) { return static_cast<double>(static_cast<int>(code) / 100); }
inline bool isClientError(double code) { return code >= 400 && code < 500; }
inline bool isServerError(double code) { return code >= 500 && code < 600; }
inline std::string statusText(double code) { { int c = static_cast<int>(code); if (c == 200) return "OK"; if (c == 404) return "Not Found"; if (c == 500) return "Internal Error"; return "Unknown"; } }
} // namespace

namespace afrilang::runtime::med::emailparse2 {
inline std::string localPart(std::string email) { { auto p = email.find('@'); return p == std::string::npos ? email : email.substr(0, p); } }
inline std::string domainPart(std::string email) { { auto p = email.find('@'); return p == std::string::npos ? "" : email.substr(p + 1); } }
inline bool isValidEmail(std::string email) { return email.find('@') != std::string::npos && email.find('.') > email.find('@'); }
inline std::string normalizeEmail(std::string email) { { std::string r = email; for (char& c : r) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c))); return r; } }
} // namespace

namespace afrilang::runtime::med::base64med {
inline std::string encodeBasic(std::string s) { { static const char* b = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"; std::string r; for (std::size_t i = 0; i < s.size(); i += 3) { unsigned val = static_cast<unsigned char>(s[i]) << 16; if (i+1 < s.size()) val |= static_cast<unsigned char>(s[i+1]) << 8; if (i+2 < s.size()) val |= static_cast<unsigned char>(s[i+2]); r += b[(val>>18)&63]; r += b[(val>>12)&63]; r += (i+1<s.size()) ? b[(val>>6)&63] : '='; r += (i+2<s.size()) ? b[val&63] : '='; } return r; } }
inline std::string decodeBasic(std::string s) { { static const int d[256]={-1}; static bool init=false; if(!init){ for(int i=0;i<64;++i) d["ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[i]]=i; init=true;} std::string r; for (std::size_t i = 0; i < s.size(); i += 4) { int v = (d[static_cast<unsigned char>(s[i])]<<18)|(d[static_cast<unsigned char>(s[i+1])]<<12); r += static_cast<char>((v>>16)&255); if(s[i+2]!='=') { v|=(d[static_cast<unsigned char>(s[i+2])]<<6); r += static_cast<char>((v>>8)&255); } if(s[i+3]!='=') { v|=d[static_cast<unsigned char>(s[i+3])]; r += static_cast<char>(v&255); } } return r; } }
inline bool isBase64(std::string s) { { if (s.empty()) return false; for (char c : s) if (!std::isalnum(static_cast<unsigned char>(c)) && c!='+' && c!='/' && c!='=') return false; return true; } }
inline double paddedLength(std::string s) { return static_cast<double>((s.size() + 2) / 3 * 4); }
} // namespace

namespace afrilang::runtime::med::matrix2 {
inline std::vector<double> create2x2(double a, double b, double c, double d) { return {a, b, c, d}; }
inline double det2x2(std::vector<double> m) { return m.size() >= 4 ? m[0]*m[3] - m[1]*m[2] : 0; }
inline double trace2x2(std::vector<double> m) { return m.size() >= 4 ? m[0] + m[3] : 0; }
inline std::vector<double> scale2x2(std::vector<double> m, double s) { { std::vector<double> r; for (double x : m) r.push_back(x * s); return r; } }
} // namespace

namespace afrilang::runtime::med::matadd {
inline std::vector<double> add(std::vector<double> a, std::vector<double> b) { { if (a.size() != b.size()) return a; std::vector<double> r; for (std::size_t i = 0; i < a.size(); ++i) r.push_back(a[i] + b[i]); return r; } }
inline std::vector<double> sub(std::vector<double> a, std::vector<double> b) { { if (a.size() != b.size()) return a; std::vector<double> r; for (std::size_t i = 0; i < a.size(); ++i) r.push_back(a[i] - b[i]); return r; } }
inline std::vector<double> neg(std::vector<double> m) { { std::vector<double> r; for (double x : m) r.push_back(-x); return r; } }
inline std::vector<double> addScalar(std::vector<double> m, double s) { { std::vector<double> r; for (double x : m) r.push_back(x + s); return r; } }
} // namespace

namespace afrilang::runtime::med::matmul2 {
inline std::vector<double> mul2x2(std::vector<double> a, std::vector<double> b) { { if (a.size() < 4 || b.size() < 4) return a; return {a[0]*b[0]+a[1]*b[2], a[0]*b[1]+a[1]*b[3], a[2]*b[0]+a[3]*b[2], a[2]*b[1]+a[3]*b[3]}; } }
inline std::vector<double> mulScalar(std::vector<double> m, double s) { { std::vector<double> r; for (double x : m) r.push_back(x * s); return r; } }
inline double dot2(std::vector<double> a, std::vector<double> b) { { if (a.size() != b.size()) return 0; double s = 0; for (std::size_t i = 0; i < a.size(); ++i) s += a[i]*b[i]; return s; } }
inline double norm2(std::vector<double> v) { return std::sqrt(dot2(v, v)); }
} // namespace

namespace afrilang::runtime::med::mattranspose {
inline std::vector<double> transpose2x2(std::vector<double> m) { return m.size() >= 4 ? std::vector<double>{m[0], m[2], m[1], m[3]} : m; }
inline std::vector<double> transpose3x3(std::vector<double> m) { return m.size() >= 9 ? std::vector<double>{m[0],m[3],m[6],m[1],m[4],m[7],m[2],m[5],m[8]} : m; }
inline bool isSquare(std::vector<double> m, double n) { return m.size() == static_cast<std::size_t>(n * n); }
inline std::vector<double> identity2(double ignored) { (void)ignored; return {1, 0, 0, 1}; }
} // namespace

namespace afrilang::runtime::med::matdet2 {
inline std::vector<double> det3x3(std::vector<double> m) { { if (m.size() < 9) return 0; return m[0]*(m[4]*m[8]-m[5]*m[7]) - m[1]*(m[3]*m[8]-m[5]*m[6]) + m[2]*(m[3]*m[7]-m[4]*m[6]); } }
inline double det2x2(std::vector<double> m) { return m.size() >= 4 ? m[0]*m[3] - m[1]*m[2] : 0; }
inline bool isSingular(std::vector<double> m) { return std::fabs(det2x2(m)) < 1e-10; }
inline std::vector<double> cofactor2(std::vector<double> m) { return m.size() >= 4 ? std::vector<double>{m[3], -m[1], -m[2], m[0]} : m; }
} // namespace

namespace afrilang::runtime::med::matinv2 {
inline std::vector<double> inv2x2(std::vector<double> m) { { double d = det2x2(m); if (std::fabs(d) < 1e-10) return m; return {m[3]/d, -m[1]/d, -m[2]/d, m[0]/d}; } }
inline std::vector<double> adj2x2(std::vector<double> m) { return m.size() >= 4 ? std::vector<double>{m[3], -m[1], -m[2], m[0]} : m; }
inline std::vector<double> solve2x2(std::vector<double> a, std::vector<double> b) { { auto inv = inv2x2(a); if (inv.size() < 4 || b.size() < 2) return b; return {inv[0]*b[0]+inv[1]*b[1], inv[2]*b[0]+inv[3]*b[1]}; } }
inline double condition2x2(std::vector<double> m) { { double d = m.size() >= 4 ? std::fabs(m[0]*m[3] - m[1]*m[2]) : 0; double tr = m.size() >= 4 ? m[0]+m[3] : 0; return d < 1e-10 ? 1e10 : std::fabs(tr) / d; } }
} // namespace

namespace afrilang::runtime::med::vector3 {
inline std::vector<double> cross3(std::vector<double> a, std::vector<double> b) { { if (a.size() < 3 || b.size() < 3) return {}; return {a[1]*b[2]-a[2]*b[1], a[2]*b[0]-a[0]*b[2], a[0]*b[1]-a[1]*b[0]}; } }
inline double dot3(std::vector<double> a, std::vector<double> b) { { if (a.size() < 3 || b.size() < 3) return 0; return a[0]*b[0]+a[1]*b[1]+a[2]*b[2]; } }
inline double length3(std::vector<double> v) { { if (v.size() < 3) return 0; return std::sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]); } }
inline std::vector<double> normalize3(std::vector<double> v) { { double l = length3(v); if (l == 0) return v; return {v[0]/l, v[1]/l, v[2]/l}; } }
} // namespace

namespace afrilang::runtime::med::matrotate {
inline std::vector<double> rotate2d(double angle) { { double c = std::cos(angle), s = std::sin(angle); return {c, -s, s, c}; } }
inline std::vector<double> apply2d(std::vector<double> m, std::vector<double> v) { { if (m.size() < 4 || v.size() < 2) return v; return {m[0]*v[0]+m[1]*v[1], m[2]*v[0]+m[3]*v[1]}; } }
inline std::vector<double> rotatePoint(double x, double y, double angle) { { auto m = rotate2d(angle); return apply2d(m, {x, y}); } }
inline double degreesToRad(double deg) { return deg * 3.141592653589793 / 180.0; }
} // namespace

namespace afrilang::runtime::med::matstats {
inline std::vector<double> rowSum(std::vector<double> m, double cols) { { int c = static_cast<int>(cols); std::vector<double> r; for (std::size_t i = 0; i + c <= m.size(); i += c) { double s = 0; for (int j = 0; j < c; ++j) s += m[i+j]; r.push_back(s); } return r; } }
inline std::vector<double> colSum(std::vector<double> m, double rows, double cols) { { int r = static_cast<int>(rows), c = static_cast<int>(cols); std::vector<double> s(c, 0); for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) s[j] += m[i*c+j]; return s; } }
inline double frobeniusNorm(std::vector<double> m) { { double s = 0; for (double x : m) s += x*x; return std::sqrt(s); } }
inline double maxAbs(std::vector<double> m) { { if (m.empty()) return 0; double mx = 0; for (double x : m) mx = std::max(mx, std::fabs(x)); return mx; } }
} // namespace

namespace afrilang::runtime::med::linsolve2 {
inline std::vector<double> solveLinear2(double a1, double b1, double c1, double a2, double b2, double c2) { { double d = a1*b2 - a2*b1; if (std::fabs(d) < 1e-10) return {0, 0}; return {(c1*b2 - c2*b1)/d, (a1*c2 - a2*c1)/d}; } }
inline std::vector<double> solve3eq(std::vector<double> m, std::vector<double> b) { { auto inv = inv2x2(m); if (inv.size() < 4 || b.size() < 2) return b; return {inv[0]*b[0]+inv[1]*b[1], inv[2]*b[0]+inv[3]*b[1]}; } }
inline double residual(std::vector<double> a, std::vector<double> x, std::vector<double> b) { { if (a.size() < 4 || x.size() < 2 || b.size() < 2) return 0; double ax0 = a[0]*x[0]+a[1]*x[1], ax1 = a[2]*x[0]+a[3]*x[1]; return std::hypot(ax0-b[0], ax1-b[1]); } }
inline bool isConsistent(std::vector<double> m) { { double d = m.size() >= 4 ? m[0]*m[3] - m[1]*m[2] : 0; return std::fabs(d) >= 1e-10; } }
} // namespace

namespace afrilang::runtime::med::finance2 {
inline double futureValue(double pv, double rate, double periods) { return pv * std::pow(1.0 + rate/100.0, periods); }
inline double presentValue(double fv, double rate, double periods) { return fv / std::pow(1.0 + rate/100.0, periods); }
inline double annuity(double payment, double rate, double periods) { { double r = rate/100.0; return r == 0 ? payment * periods : payment * (1 - std::pow(1+r, -periods)) / r; } }
inline double payment(double pv, double rate, double periods) { { double r = rate/100.0; return r == 0 ? pv / periods : pv * r / (1 - std::pow(1+r, -periods)); } }
} // namespace

namespace afrilang::runtime::med::amortize2 {
inline double monthlyInterest(double balance, double rate) { return balance * rate / 100.0 / 12.0; }
inline double principalPart(double payment, double interest) { return payment - interest; }
inline double remainingBalance(double balance, double payment, double interest) { return balance - (payment - interest); }
inline std::vector<double> amortSchedule(double balance, double rate, double payment, double months) { { std::vector<double> r; double b = balance; int m = static_cast<int>(months); for (int i = 0; i < m && b > 0; ++i) { double intr = monthlyInterest(b, rate); double prin = principalPart(payment, intr); b = remainingBalance(b, payment, intr); r.push_back(b); } return r; } }
} // namespace

namespace afrilang::runtime::med::npv2 {
inline double npv(double rate, std::vector<double> cashflows) { { double r = rate/100.0, sum = 0; for (std::size_t i = 0; i < cashflows.size(); ++i) sum += cashflows[i] / std::pow(1+r, static_cast<double>(i)); return sum; } }
inline double npvSimple(double rate, double initial, std::vector<double> returns) { { std::vector<double> cf = {initial}; cf.insert(cf.end(), returns.begin(), returns.end()); return npv(rate, cf); } }
inline double profitability(double npvVal, double investment) { return investment == 0 ? 0 : npvVal / investment * 100.0; }
inline double discountedCashflow(double cf, double rate, double period) { return cf / std::pow(1.0 + rate/100.0, period); }
} // namespace

namespace afrilang::runtime::med::irr2 {
inline double irrApprox(std::vector<double> cashflows) { { if (cashflows.empty()) return 0; double lo = -99, hi = 100; for (int iter = 0; iter < 50; ++iter) { double mid = (lo+hi)/2; double r = mid/100.0, np = 0; for (std::size_t i = 0; i < cashflows.size(); ++i) np += cashflows[i] / std::pow(1+r, static_cast<double>(i)); if (np > 0) lo = mid; else hi = mid; } return (lo+hi)/2; } }
inline double mirr(std::vector<double> cashflows, double financeRate, double reinvestRate) { (void)financeRate; (void)reinvestRate; return irrApprox(cashflows); }
inline double paybackPeriod(std::vector<double> cashflows) { { double cum = 0; for (std::size_t i = 0; i < cashflows.size(); ++i) { cum += cashflows[i]; if (cum >= 0) return static_cast<double>(i); } return static_cast<double>(cashflows.size()); } }
inline double roiPercent(double gain, double cost) { return cost == 0 ? 0 : (gain - cost) / cost * 100.0; }
} // namespace

namespace afrilang::runtime::med::breakEven2 {
inline double breakEvenUnits(double fixedCost, double price, double varCost) { return (price - varCost) == 0 ? 0 : fixedCost / (price - varCost); }
inline double breakEvenRevenue(double fixedCost, double margin) { return margin == 0 ? 0 : fixedCost / (margin / 100.0); }
inline double contributionMargin(double price, double varCost) { return price - varCost; }
inline double marginOfSafety(double currentSales, double breakEven) { return currentSales == 0 ? 0 : (currentSales - breakEven) / currentSales * 100.0; }
} // namespace

namespace afrilang::runtime::med::compound2 {
inline double compoundAnnual(double principal, double rate, double years) { return principal * std::pow(1.0 + rate/100.0, years); }
inline double compoundMonthly(double principal, double rate, double months) { return principal * std::pow(1.0 + rate/100.0/12.0, months); }
inline double effectiveRate(double nominal, double periods) { return (std::pow(1.0 + nominal/100.0/periods, periods) - 1) * 100.0; }
inline double doublingTime(double rate) { return rate == 0 ? 0 : 72.0 / rate; }
} // namespace

namespace afrilang::runtime::med::inflation2 {
inline double inflate(double amount, double rate, double years) { return amount * std::pow(1.0 + rate/100.0, years); }
inline double deflate(double amount, double rate, double years) { return amount / std::pow(1.0 + rate/100.0, years); }
inline double realReturn(double nominal, double inflation) { return ((1 + nominal/100.0) / (1 + inflation/100.0) - 1) * 100.0; }
inline double purchasingPower(double amount, double inflation, double years) { return deflate(amount, inflation, years); }
} // namespace

namespace afrilang::runtime::med::currency2 {
inline double convert(double amount, double rate) { return amount * rate; }
inline double crossRate(double fromUsd, double toUsd) { return toUsd == 0 ? 0 : fromUsd / toUsd; }
inline double spread(double bid, double ask) { return ask - bid; }
inline double midRate(double bid, double ask) { return (bid + ask) / 2.0; }
} // namespace

namespace afrilang::runtime::med::portfolio2 {
inline double weightedReturn(std::vector<double> returns, std::vector<double> weights) { { if (returns.size() != weights.size()) return 0; double s = 0, w = 0; for (std::size_t i = 0; i < returns.size(); ++i) { s += returns[i]*weights[i]; w += weights[i]; } return w == 0 ? 0 : s / w; } }
inline double portfolioValue(std::vector<double> shares, std::vector<double> prices) { { if (shares.size() != prices.size()) return 0; double s = 0; for (std::size_t i = 0; i < shares.size(); ++i) s += shares[i]*prices[i]; return s; } }
inline std::vector<double> rebalance(std::vector<double> values, std::vector<double> target) { { double total = 0; for (double v : values) total += v; if (total == 0) return values; std::vector<double> r; for (double v : values) r.push_back(total * target / 100.0 / values.size()); return r; } }
inline double diversification(std::vector<double> weights) { { double h = 0; for (double w : weights) h += w * w; return (1 - h) * 100.0; } }
} // namespace

namespace afrilang::runtime::med::taxcalc2 {
inline double incomeTax(double income, double rate) { return income * rate / 100.0; }
inline double netIncome(double gross, double rate) { return gross - incomeTax(gross, rate); }
inline double vatAmount(double price, double rate) { return price * rate / 100.0; }
inline double priceWithVat(double price, double rate) { return price + vatAmount(price, rate); }
} // namespace

namespace afrilang::runtime::med::depreciation2 {
inline double straightLine(double cost, double salvage, double years) { return years == 0 ? 0 : (cost - salvage) / years; }
inline double decliningBalance(double bookValue, double rate) { return bookValue * rate / 100.0; }
inline double sumOfYears(double cost, double salvage, double years, double year) { { double n = years, k = year; return (cost - salvage) * (n - k + 1) / (n * (n + 1) / 2); } }
inline double accumDepreciation(double annual, double yearsElapsed) { return annual * yearsElapsed; }
} // namespace

namespace afrilang::runtime::med::bondcalc2 {
inline double bondPrice(double face, double coupon, double rate, double years) { { double r = rate/100.0, p = 0; for (int i = 1; i <= static_cast<int>(years); ++i) p += face * coupon/100.0 / std::pow(1+r, i); p += face / std::pow(1+r, years); return p; } }
inline double yieldToMaturity(double price, double face, double coupon, double years) { return ((face - price) / years + face * coupon / 100.0) / ((face + price) / 2) * 100.0; }
inline double currentYield(double coupon, double price) { return price == 0 ? 0 : coupon / price * 100.0; }
inline double duration(double years, double coupon) { return years / (1 + coupon / 100.0); }
} // namespace

namespace afrilang::runtime::med::polygon2 {
inline double areaTriangle(double base, double height) { return 0.5 * base * height; }
inline double perimeterRect(double w, double h) { return 2.0 * (w + h); }
inline double areaRect(double w, double h) { return w * h; }
inline double diagonal(double w, double h) { return std::hypot(w, h); }
} // namespace

namespace afrilang::runtime::med::statsreg2 {
inline double linearSlope(std::vector<double> x, std::vector<double> y) { { if (x.size() != y.size() || x.size() < 2) return 0; double mx=0,my=0; for(double v:x)mx+=v; for(double v:y)my+=v; mx/=x.size(); my/=y.size(); double num=0,den=0; for(std::size_t i=0;i<x.size();++i){num+=(x[i]-mx)*(y[i]-my);den+=(x[i]-mx)*(x[i]-mx);} return den==0?0:num/den; } }
inline double linearIntercept(std::vector<double> x, std::vector<double> y) { { double m = linearSlope(x,y); double mx=0,my=0; for(double v:x)mx+=v; for(double v:y)my+=v; mx/=x.size(); my/=y.size(); return my - m*mx; } }
inline double predict(double slope, double intercept, double x) { return slope * x + intercept; }
inline double rSquared(std::vector<double> x, std::vector<double> y) { { double m=linearSlope(x,y), b=linearIntercept(x,y); double my=0; for(double v:y)my+=v; my/=y.size(); double ssRes=0,ssTot=0; for(std::size_t i=0;i<x.size();++i){double pred=m*x[i]+b; ssRes+=(y[i]-pred)*(y[i]-pred); ssTot+=(y[i]-my)*(y[i]-my);} return ssTot==0?0:1-ssRes/ssTot; } }
} // namespace

namespace afrilang::runtime::med::interpolate2 {
inline double lerp(double a, double b, double t) { return a + (b - a) * t; }
inline std::vector<double> lerpList(std::vector<double> a, std::vector<double> b, double t) { { if (a.size() != b.size()) return a; std::vector<double> r; for (std::size_t i = 0; i < a.size(); ++i) r.push_back(lerp(a[i], b[i], t)); return r; } }
inline double inverseLerp(double a, double b, double v) { return (b == a) ? 0 : (v - a) / (b - a); }
inline double remap(double v, double inLo, double inHi, double outLo, double outHi) { return lerp(outLo, outHi, inverseLerp(inLo, inHi, v)); }
} // namespace

namespace afrilang::runtime::med::bezier2 {
inline double quadBezier(double p0, double p1, double p2, double t) { { double u = 1 - t; return u*u*p0 + 2*u*t*p1 + t*t*p2; } }
inline double cubicBezier(double p0, double p1, double p2, double p3, double t) { { double u = 1 - t; return u*u*u*p0 + 3*u*u*t*p1 + 3*u*t*t*p2 + t*t*t*p3; } }
inline double bezierTangent(double p0, double p1, double p2, double t) { return 2*(1-t)*(p1-p0) + 2*t*(p2-p1); }
inline std::vector<double> bezierPoint2d(double x0, double y0, double x1, double y1, double x2, double y2, double t) { return {quadBezier(x0,x1,x2,t), quadBezier(y0,y1,y2,t)}; }
} // namespace

namespace afrilang::runtime::med::distance3 {
inline double manhattan2d(double x1, double y1, double x2, double y2) { return std::fabs(x2-x1) + std::fabs(y2-y1); }
inline double chebyshev2d(double x1, double y1, double x2, double y2) { return std::max(std::fabs(x2-x1), std::fabs(y2-y1)); }
inline double cosineSimilarity(std::vector<double> a, std::vector<double> b) { { if (a.size() != b.size()) return 0; double dot=0,na=0,nb=0; for(std::size_t i=0;i<a.size();++i){dot+=a[i]*b[i];na+=a[i]*a[i];nb+=b[i]*b[i];} return na==0||nb==0?0:dot/std::sqrt(na*nb); } }
inline double hammingDist(std::string a, std::string b) { { std::size_t n = std::max(a.size(), b.size()); int d = 0; for (std::size_t i = 0; i < n; ++i) if (i >= a.size() || i >= b.size() || a[i] != b[i]) ++d; return static_cast<double>(d); } }
} // namespace

namespace afrilang::runtime::med::histogram2 {
inline double binIndex(double value, double minVal, double maxVal, double bins) { { double w = (maxVal-minVal)/bins; if (w == 0) return 0; int i = static_cast<int>((value-minVal)/w); if (i >= static_cast<int>(bins)) i = static_cast<int>(bins)-1; if (i < 0) i = 0; return static_cast<double>(i); } }
inline std::vector<double> normalizeHist(std::vector<double> counts) { { double s = 0; for (double c : counts) s += c; if (s == 0) return counts; std::vector<double> r; for (double c : counts) r.push_back(c/s); return r; } }
inline std::vector<double> cumulativeHist(std::vector<double> counts) { { std::vector<double> r; double s = 0; for (double c : counts) { s += c; r.push_back(s); } return r; } }
inline double peakBin(std::vector<double> counts) { { if (counts.empty()) return 0; return static_cast<double>(std::max_element(counts.begin(), counts.end()) - counts.begin()); } }
} // namespace

namespace afrilang::runtime::med::percentile2 {
inline double percentileRank(std::vector<double> v, double value) { { if (v.empty()) return 0; int below = 0; for (double x : v) if (x < value) ++below; return static_cast<double>(below) / v.size() * 100.0; } }
inline double percentileValue(std::vector<double> v, double p) { { if (v.empty()) return 0; auto t = v; std::sort(t.begin(), t.end()); double pos = p/100.0 * (t.size()-1); std::size_t i = static_cast<std::size_t>(pos); return t[i]; } }
inline double trimMean(std::vector<double> v, double pct) { { if (v.empty()) return 0; auto t = v; std::sort(t.begin(), t.end()); std::size_t k = static_cast<std::size_t>(t.size() * pct / 100.0); double s = 0; for (std::size_t i = k; i + k < t.size(); ++i) s += t[i]; return s / (t.size() - 2*k); } }
inline double geometricMean(std::vector<double> v) { { if (v.empty()) return 0; double logSum = 0; for (double x : v) logSum += std::log(x <= 0 ? 1 : x); return std::exp(logSum / v.size()); } }
} // namespace

namespace afrilang::runtime::med::checksum2 {
inline double crcSimple(std::string s) { { unsigned int crc = 0xFFFF; for (unsigned char c : s) { crc ^= c; for (int i = 0; i < 8; ++i) crc = (crc >> 1) ^ (0xA001 & -(crc & 1)); } return static_cast<double>(crc); } }
inline double adler32lite(std::string s) { { unsigned int a = 1, b = 0; for (unsigned char c : s) { a = (a + c) % 65521; b = (b + a) % 65521; } return static_cast<double>((b << 16) | a); } }
inline double fnvHash(std::string s) { { unsigned long h = 2166136261UL; for (unsigned char c : s) { h ^= c; h *= 16777619UL; } return static_cast<double>(h); } }
inline double sumChecksum(std::string s) { { unsigned int s2 = 0; for (unsigned char c : s) s2 += c; return static_cast<double>(s2 & 0xFF); } }
} // namespace

namespace afrilang::runtime::med::hash2 {
inline double djb2(std::string s) { { unsigned long h = 5381; for (unsigned char c : s) h = ((h << 5) + h) + c; return static_cast<double>(h); } }
inline double sdbm(std::string s) { { unsigned long h = 0; for (unsigned char c : s) h = c + (h << 6) + (h << 16) - h; return static_cast<double>(h); } }
inline double javaHash(std::string s) { { int h = 0; for (unsigned char c : s) h = 31 * h + c; return static_cast<double>(h); } }
inline double hashCombine(double a, double b) { return static_cast<double>(static_cast<long long>(a) ^ (static_cast<long long>(b) << 1)); }
} // namespace

namespace afrilang::runtime::med::rotN {
inline std::string rotEncode(std::string s, double n) { { int shift = static_cast<int>(n) % 26; std::string r; for (char c : s) { if (c >= 'a' && c <= 'z') r += char('a' + (c - 'a' + shift) % 26); else if (c >= 'A' && c <= 'Z') r += char('A' + (c - 'A' + shift) % 26); else r += c; } return r; } }
inline std::string rotDecode(std::string s, double n) { return rotEncode(s, 26 - static_cast<int>(n) % 26); }
inline std::string caesarShift(std::string s, double n) { return rotEncode(s, n); }
inline std::string xorCipher(std::string s, std::string key) { { if (key.empty()) return s; std::string r; for (std::size_t i = 0; i < s.size(); ++i) r += char(s[i] ^ key[i % key.size()]); return r; } }
} // namespace

namespace afrilang::runtime::med::uuid2 {
inline std::string randomHex(double n) { { static const char* h = "0123456789abcdef"; std::string r; for (int i = 0; i < static_cast<int>(n); ++i) r += h[std::rand() % 16]; return r; } }
inline std::string simpleUuid(double seed) { { std::srand(static_cast<unsigned>(seed)); return randomHex(8) + "-" + randomHex(4) + "-" + randomHex(4); } }
inline std::string formatUuid(std::string hex32) { { if (hex32.size() < 32) return hex32; return hex32.substr(0,8)+"-"+hex32.substr(8,4)+"-"+hex32.substr(12,4)+"-"+hex32.substr(16,4)+"-"+hex32.substr(20,12); } }
inline bool isUuidFormat(std::string s) { return s.size() == 36 && s[8]=='-' && s[13]=='-' && s[18]=='-' && s[23]=='-'; }
} // namespace

namespace afrilang::runtime::med::random2 {
inline double seedRandom(double seed) { (void)seed; std::srand(static_cast<unsigned>(seed)); return static_cast<double>(std::rand()); }
inline double randomRange(double lo, double hi) { return lo + std::rand() / (RAND_MAX / (hi - lo + 1)); }
inline std::vector<double> randomList(double count, double lo, double hi) { { std::vector<double> r; int n = static_cast<int>(count); for (int i = 0; i < n; ++i) r.push_back(randomRange(lo, hi)); return r; } }
inline std::vector<double> shuffleList(std::vector<double> v, double seed) { { auto r = v; std::srand(static_cast<unsigned>(seed)); std::shuffle(r.begin(), r.end(), [](int n){ return std::rand() % (n+1); }); return r; } }
} // namespace

namespace afrilang::runtime::med::entropy2 {
inline double shannonEntropy(std::string s) { { std::map<char,int> m; for (char c : s) ++m[c]; double e = 0, n = s.size(); for (auto& p : m) { double f = p.second / n; e -= f * std::log2(f); } return e; } }
inline double uniqueRatio(std::string s) { { std::map<char,int> m; for (char c : s) ++m[c]; return s.empty() ? 0 : static_cast<double>(m.size()) / s.size(); } }
inline double compressionRatio(double original, double compressed) { return original == 0 ? 0 : compressed / original; }
inline double bitEntropy(std::string s) { return shannonEntropy(s) * s.size(); }
} // namespace

namespace afrilang::runtime::med::units2 {
inline double celsiusToFahrenheit(double c) { return c * 9.0 / 5.0 + 32.0; }
inline double fahrenheitToCelsius(double f) { return (f - 32.0) * 5.0 / 9.0; }
inline double metersToFeet(double m) { return m * 3.28084; }
inline double feetToMeters(double ft) { return ft / 3.28084; }
} // namespace

namespace afrilang::runtime::med::physics2 {
inline double kineticEnergy(double mass, double velocity) { return 0.5 * mass * velocity * velocity; }
inline double potentialEnergy(double mass, double height) { return mass * 9.81 * height; }
inline double momentum(double mass, double velocity) { return mass * velocity; }
inline double force(double mass, double accel) { return mass * accel; }
} // namespace

namespace afrilang::runtime::med::gamestats2 {
inline double scoreMultiplier(double score, double multiplier) { return score * multiplier; }
inline double xpForLevel(double level) { return level * level * 100; }
inline double levelFromXp(double xp) { return std::floor(std::sqrt(xp / 100.0)); }
inline double damageCalc(double attack, double defense) { return std::max(0.0, attack - defense * 0.5); }
} // namespace
