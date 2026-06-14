#!/usr/bin/env python3
"""Generate medium stdlib catalog (100+ modules) and C++ runtime."""

from __future__ import annotations
import os
import sys

_SCRIPTS = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, _SCRIPTS)
from gen_catalog_lib import (
    ROOT,
    gen_runtime,
    gen_catalog_cpp,
    gen_afr_stubs,
    gen_docs,
)

MODULES: list[tuple] = []

MODULES.append(('textstats', 'textstats', [
    ('wordCount', 'number', [('s', 'text')], '{ int c = 0; bool w = false; for (unsigned char ch : s) { if (std::isspace(ch)) w = false; else if (!w) { ++c; w = true; } } return static_cast<double>(c); }'),
    ('charCount', 'number', [('s', 'text')], 'return static_cast<double>(s.size());'),
    ('lineCount', 'number', [('s', 'text')], "{ int c = s.empty() ? 0 : 1; for (char ch : s) if (ch == '\\n') ++c; return static_cast<double>(c); }"),
    ('avgWordLen', 'number', [('s', 'text')], '{ int words = 0, chars = 0; bool w = false; for (unsigned char ch : s) { if (std::isspace(ch)) w = false; else { if (!w) ++words; ++chars; w = true; } } return words == 0 ? 0 : static_cast<double>(chars) / words; }'),
    ('digitCount', 'number', [('s', 'text')], '{ int c = 0; for (unsigned char ch : s) if (std::isdigit(ch)) ++c; return static_cast<double>(c); }'),
]))
MODULES.append(('charfreq', 'charfreq', [
    ('countChar', 'number', [('s', 'text'), ('ch', 'text')], '{ if (ch.empty()) return 0; char t = ch[0]; int c = 0; for (char x : s) if (x == t) ++c; return static_cast<double>(c); }'),
    ('mostCommonChar', 'text', [('s', 'text')], '{ if (s.empty()) return ""; std::map<char,int> m; for (char c : s) ++m[c]; return std::string(1, std::max_element(m.begin(), m.end(), [](auto&a,auto&b){return a.second<b.second;})->first); }'),
    ('uniqueChars', 'number', [('s', 'text')], '{ std::map<char,int> m; for (char c : s) ++m[c]; return static_cast<double>(m.size()); }'),
    ('alphaRatio', 'number', [('s', 'text')], '{ if (s.empty()) return 0; int a = 0; for (unsigned char c : s) if (std::isalpha(c)) ++a; return static_cast<double>(a) / s.size(); }'),
    ('spaceRatio', 'number', [('s', 'text')], '{ if (s.empty()) return 0; int a = 0; for (unsigned char c : s) if (std::isspace(c)) ++a; return static_cast<double>(a) / s.size(); }'),
]))
MODULES.append(('sentsplit', 'sentsplit', [
    ('splitSentences', 'list text', [('s', 'text')], "{ std::vector<std::string> r; std::string cur; for (char c : s) { cur += c; if (c=='.'||c=='!'||c=='?') { while (!cur.empty() && std::isspace(static_cast<unsigned char>(cur.front()))) cur.erase(cur.begin()); if (!cur.empty()) r.push_back(cur); cur.clear(); } } if (!cur.empty()) r.push_back(cur); return r; }"),
    ('sentenceCount', 'number', [('s', 'text')], '{ auto v = splitSentences(s); return static_cast<double>(v.size()); }'),
    ('firstSentence', 'text', [('s', 'text')], '{ auto v = splitSentences(s); return v.empty() ? "" : v.front(); }'),
    ('lastSentence', 'text', [('s', 'text')], '{ auto v = splitSentences(s); return v.empty() ? "" : v.back(); }'),
]))
MODULES.append(('wordtok', 'wordtok', [
    ('tokenize', 'list text', [('s', 'text')], '{ std::vector<std::string> r; std::string w; for (unsigned char c : s) { if (std::isspace(c)) { if (!w.empty()) { r.push_back(w); w.clear(); } } else w += static_cast<char>(c); } if (!w.empty()) r.push_back(w); return r; }'),
    ('tokenCount', 'number', [('s', 'text')], '{ auto v = tokenize(s); return static_cast<double>(v.size()); }'),
    ('longestToken', 'text', [('s', 'text')], '{ auto v = tokenize(s); if (v.empty()) return ""; return *std::max_element(v.begin(), v.end(), [](auto&a,auto&b){return a.size()<b.size();}); }'),
    ('shortestToken', 'text', [('s', 'text')], '{ auto v = tokenize(s); if (v.empty()) return ""; return *std::min_element(v.begin(), v.end(), [](auto&a,auto&b){return a.size()<b.size();}); }'),
    ('avgTokenLen', 'number', [('s', 'text')], '{ auto v = tokenize(s); if (v.empty()) return 0; double t = 0; for (auto& x : v) t += x.size(); return t / v.size(); }'),
]))
MODULES.append(('ngrams', 'ngrams', [
    ('bigrams', 'list text', [('s', 'text')], '{ std::vector<std::string> t; std::string w; for (unsigned char c : s) { if (std::isspace(c)) { if (!w.empty()) { t.push_back(w); w.clear(); } } else w += static_cast<char>(c); } if (!w.empty()) t.push_back(w); std::vector<std::string> out; for (std::size_t i = 1; i < t.size(); ++i) out.push_back(t[i-1] + " " + t[i]); return out; }'),
    ('trigrams', 'list text', [('s', 'text')], '{ std::vector<std::string> t; std::string w; for (unsigned char c : s) { if (std::isspace(c)) { if (!w.empty()) { t.push_back(w); w.clear(); } } else w += static_cast<char>(c); } if (!w.empty()) t.push_back(w); std::vector<std::string> out; for (std::size_t i = 2; i < t.size(); ++i) out.push_back(t[i-2] + " " + t[i-1] + " " + t[i]); return out; }'),
    ('charBigrams', 'list text', [('s', 'text')], '{ std::vector<std::string> r; for (std::size_t i = 1; i < s.size(); ++i) r.push_back(s.substr(i-1, 2)); return r; }'),
    ('ngramCount', 'number', [('s', 'text'), ('n', 'number')], '{ int nn = static_cast<int>(n); if (nn <= 0) return 0; std::vector<std::string> t; std::string w; for (unsigned char c : s) { if (std::isspace(c)) { if (!w.empty()) { t.push_back(w); w.clear(); } } else w += static_cast<char>(c); } if (!w.empty()) t.push_back(w); return t.size() >= static_cast<std::size_t>(nn) ? static_cast<double>(t.size() - nn + 1) : 0; }'),
]))
MODULES.append(('palindrom2', 'palindrom2', [
    ('isPalindrome', 'bool', [('s', 'text')], '{ std::string t; for (char c : s) if (std::isalnum(static_cast<unsigned char>(c))) t += static_cast<char>(std::tolower(static_cast<unsigned char>(c))); return std::equal(t.begin(), t.begin()+t.size()/2, t.rbegin()); }'),
    ('longestPalindromeLen', 'number', [('s', 'text')], '{ std::string t; for (char c : s) if (std::isalnum(static_cast<unsigned char>(c))) t += static_cast<char>(std::tolower(static_cast<unsigned char>(c))); double best = 0; for (std::size_t i = 0; i < t.size(); ++i) for (std::size_t j = i; j < t.size(); ++j) { std::string sub = t.substr(i, j-i+1); if (std::equal(sub.begin(), sub.begin()+sub.size()/2, sub.rbegin())) best = std::max(best, static_cast<double>(sub.size())); } return best; }'),
    ('reverseAlphaNum', 'text', [('s', 'text')], '{ std::string t; for (char c : s) if (std::isalnum(static_cast<unsigned char>(c))) t += c; return std::string(t.rbegin(), t.rend()); }'),
    ('isPalindromeWord', 'bool', [('w', 'text')], 'return isPalindrome(w);'),
]))
MODULES.append(('anagram2', 'anagram2', [
    ('normalizeWord', 'text', [('s', 'text')], '{ std::string t; for (char c : s) if (std::isalpha(static_cast<unsigned char>(c))) t += static_cast<char>(std::tolower(static_cast<unsigned char>(c))); std::sort(t.begin(), t.end()); return t; }'),
    ('areAnagrams', 'bool', [('a', 'text'), ('b', 'text')], 'return normalizeWord(a) == normalizeWord(b);'),
    ('anagramKey', 'text', [('s', 'text')], 'return normalizeWord(s);'),
    ('sortLetters', 'text', [('s', 'text')], '{ std::string t = s; std::sort(t.begin(), t.end()); return t; }'),
]))
MODULES.append(('textwrap2', 'textwrap2', [
    ('wrapLines', 'list text', [('s', 'text'), ('width', 'number')], '{ std::vector<std::string> r; int w = static_cast<int>(width); if (w <= 0) return r; std::string line, word; for (char c : s) { if (c == \' \' || c == \'\\n\') { if (!word.empty()) { if (!line.empty() && static_cast<int>(line.size() + 1 + word.size()) > w) { r.push_back(line); line = word; } else line = line.empty() ? word : line + " " + word; word.clear(); } if (c == \'\\n\' && !line.empty()) { r.push_back(line); line.clear(); } } else word += c; } if (!word.empty()) line = line.empty() ? word : line + " " + word; if (!line.empty()) r.push_back(line); return r; }'),
    ('wrapCount', 'number', [('s', 'text'), ('width', 'number')], 'return static_cast<double>(wrapLines(s, width).size());'),
    ('truncateWords', 'text', [('s', 'text'), ('maxWords', 'number')], '{ std::vector<std::string> t; std::string w; for (unsigned char c : s) { if (std::isspace(c)) { if (!w.empty()) { t.push_back(w); w.clear(); } } else w += static_cast<char>(c); } if (!w.empty()) t.push_back(w); int m = static_cast<int>(maxWords); std::string r; for (int i = 0; i < m && i < static_cast<int>(t.size()); ++i) { if (!r.empty()) r += " "; r += t[i]; } return r + (static_cast<int>(t.size()) > m ? "..." : ""); }'),
    ('padCenter', 'text', [('s', 'text'), ('width', 'number')], "{ int w = static_cast<int>(width); if (static_cast<int>(s.size()) >= w) return s; int pad = w - static_cast<int>(s.size()); int left = pad / 2; return std::string(left, ' ') + s + std::string(pad - left, ' '); }"),
]))
MODULES.append(('textsearch', 'textsearch', [
    ('findAll', 'list number', [('s', 'text'), ('sub', 'text')], '{ std::vector<double> r; if (sub.empty()) return r; for (std::size_t i = 0; i + sub.size() <= s.size(); ++i) if (s.compare(i, sub.size(), sub) == 0) r.push_back(static_cast<double>(i)); return r; }'),
    ('countOccurrences', 'number', [('s', 'text'), ('sub', 'text')], 'return static_cast<double>(findAll(s, sub).size());'),
    ('containsIgnoreCase', 'bool', [('s', 'text'), ('sub', 'text')], '{ std::string a = s, b = sub; for (char& c : a) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c))); for (char& c : b) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c))); return a.find(b) != std::string::npos; }'),
    ('replaceAll', 'text', [('s', 'text'), ('from', 'text'), ('to', 'text')], '{ if (from.empty()) return s; std::string r; for (std::size_t i = 0; i < s.size(); ) { if (i + from.size() <= s.size() && s.compare(i, from.size(), from) == 0) { r += to; i += from.size(); } else { r += s[i++]; } } return r; }'),
    ('indexOf', 'number', [('s', 'text'), ('sub', 'text')], '{ auto p = s.find(sub); return p == std::string::npos ? -1 : static_cast<double>(p); }'),
]))
MODULES.append(('accentstrip', 'accentstrip', [
    ('stripAccents', 'text', [('s', 'text')], "{ std::string r; for (unsigned char c : s) r += static_cast<char>(c < 128 ? c : '?'); return r; }"),
    ('toAsciiFold', 'text', [('s', 'text')], "{ std::string r; for (unsigned char c : s) r += static_cast<char>(std::isprint(c) ? c : '?'); return r; }"),
    ('removeNonPrintable', 'text', [('s', 'text')], "{ std::string r; for (unsigned char c : s) if (std::isprint(c) || c == '\\n' || c == '\\t') r += static_cast<char>(c); return r; }"),
    ('collapseSpaces', 'text', [('s', 'text')], "{ std::string r; bool sp = false; for (unsigned char c : s) { if (std::isspace(c)) { if (!sp) r += ' '; sp = true; } else { r += static_cast<char>(c); sp = false; } } while (!r.empty() && r.front() == ' ') r.erase(r.begin()); while (!r.empty() && r.back() == ' ') r.pop_back(); return r; }"),
]))
MODULES.append(('casemap2', 'casemap2', [
    ('titleCase', 'text', [('s', 'text')], '{ std::string r; bool cap = true; for (unsigned char c : s) { if (std::isspace(c)) { r += static_cast<char>(c); cap = true; } else if (cap) { r += static_cast<char>(std::toupper(c)); cap = false; } else r += static_cast<char>(std::tolower(c)); } return r; }'),
    ('swapCase', 'text', [('s', 'text')], '{ std::string r; for (unsigned char c : s) r += static_cast<char>(std::isupper(c) ? std::tolower(c) : std::toupper(c)); return r; }'),
    ('camelToSnake', 'text', [('s', 'text')], "{ std::string r; for (std::size_t i = 0; i < s.size(); ++i) { if (i > 0 && std::isupper(static_cast<unsigned char>(s[i]))) r += '_'; r += static_cast<char>(std::tolower(static_cast<unsigned char>(s[i]))); } return r; }"),
    ('snakeToCamel', 'text', [('s', 'text')], "{ std::string r; bool up = false; for (char c : s) { if (c == '_') up = true; else { r += up ? static_cast<char>(std::toupper(static_cast<unsigned char>(c))) : c; up = false; } } return r; }"),
]))
MODULES.append(('textdiff2', 'textdiff2', [
    ('commonPrefixLen', 'number', [('a', 'text'), ('b', 'text')], '{ std::size_t i = 0; while (i < a.size() && i < b.size() && a[i] == b[i]) ++i; return static_cast<double>(i); }'),
    ('commonSuffixLen', 'number', [('a', 'text'), ('b', 'text')], '{ std::size_t i = 0; while (i < a.size() && i < b.size() && a[a.size()-1-i] == b[b.size()-1-i]) ++i; return static_cast<double>(i); }'),
    ('levenshtein', 'number', [('a', 'text'), ('b', 'text')], '{ std::vector<std::vector<int>> dp(a.size()+1, std::vector<int>(b.size()+1)); for (std::size_t i = 0; i <= a.size(); ++i) dp[i][0] = static_cast<int>(i); for (std::size_t j = 0; j <= b.size(); ++j) dp[0][j] = static_cast<int>(j); for (std::size_t i = 1; i <= a.size(); ++i) for (std::size_t j = 1; j <= b.size(); ++j) { int cost = a[i-1]==b[j-1] ? 0 : 1; dp[i][j] = std::min({dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+cost}); } return static_cast<double>(dp[a.size()][b.size()]); }'),
    ('similarityRatio', 'number', [('a', 'text'), ('b', 'text')], '{ double d = levenshtein(a, b); double m = std::max(a.size(), b.size()); return m == 0 ? 1 : 1.0 - d / m; }'),
]))
MODULES.append(('regexlite', 'regexlite', [
    ('matchDigits', 'bool', [('s', 'text')], '{ if (s.empty()) return false; for (char c : s) if (!std::isdigit(static_cast<unsigned char>(c))) return false; return true; }'),
    ('matchAlpha', 'bool', [('s', 'text')], '{ if (s.empty()) return false; for (char c : s) if (!std::isalpha(static_cast<unsigned char>(c))) return false; return true; }'),
    ('matchAlnum', 'bool', [('s', 'text')], '{ if (s.empty()) return false; for (char c : s) if (!std::isalnum(static_cast<unsigned char>(c))) return false; return true; }'),
    ('extractDigits', 'text', [('s', 'text')], '{ std::string r; for (char c : s) if (std::isdigit(static_cast<unsigned char>(c))) r += c; return r; }'),
    ('extractAlpha', 'text', [('s', 'text')], '{ std::string r; for (char c : s) if (std::isalpha(static_cast<unsigned char>(c))) r += c; return r; }'),
]))
MODULES.append(('motfreq', 'motfreq', [
    ('wordFrequency', 'number', [('s', 'text'), ('word', 'text')], '{ int c = 0; std::string w; for (unsigned char ch : s) { if (std::isspace(ch)) { if (!w.empty() && w == word) ++c; w.clear(); } else w += static_cast<char>(ch); } if (!w.empty() && w == word) ++c; return static_cast<double>(c); }'),
    ('mostFrequentWord', 'text', [('s', 'text')], '{ std::map<std::string,int> m; std::string w; for (unsigned char ch : s) { if (std::isspace(ch)) { if (!w.empty()) ++m[w]; w.clear(); } else w += static_cast<char>(ch); } if (!w.empty()) ++m[w]; if (m.empty()) return ""; return std::max_element(m.begin(), m.end(), [](auto&a,auto&b){return a.second<b.second;})->first; }'),
    ('uniqueWords', 'number', [('s', 'text')], '{ std::map<std::string,int> m; std::string w; for (unsigned char ch : s) { if (std::isspace(ch)) { if (!w.empty()) ++m[w]; w.clear(); } else w += static_cast<char>(ch); } if (!w.empty()) ++m[w]; return static_cast<double>(m.size()); }'),
    ('lexicalDensity', 'number', [('s', 'text')], '{ int total = 0, unique = 0; std::map<std::string,int> m; std::string w; for (unsigned char ch : s) { if (std::isspace(ch)) { if (!w.empty()) { ++total; ++m[w]; w.clear(); } } else w += static_cast<char>(ch); } if (!w.empty()) { ++total; ++m[w]; } for (auto& p : m) if (p.second == 1) ++unique; return total == 0 ? 0 : static_cast<double>(unique) / total; }'),
]))
MODULES.append(('numstats', 'numstats', [
    ('sum', 'number', [('v', 'list number')], 'if (v.empty()) return 0; return std::accumulate(v.begin(), v.end(), 0.0);'),
    ('mean', 'number', [('v', 'list number')], 'if (v.empty()) return 0; return std::accumulate(v.begin(), v.end(), 0.0) / v.size();'),
    ('minVal', 'number', [('v', 'list number')], 'if (v.empty()) return 0; return *std::min_element(v.begin(), v.end());'),
    ('maxVal', 'number', [('v', 'list number')], 'if (v.empty()) return 0; return *std::max_element(v.begin(), v.end());'),
    ('range', 'number', [('v', 'list number')], 'if (v.empty()) return 0; return *std::max_element(v.begin(), v.end()) - *std::min_element(v.begin(), v.end());'),
]))
MODULES.append(('listmedian', 'listmedian', [
    ('median', 'number', [('v', 'list number')], '{ if (v.empty()) return 0; auto t = v; std::sort(t.begin(), t.end()); std::size_t n = t.size(); return n % 2 ? t[n/2] : (t[n/2-1] + t[n/2]) / 2.0; }'),
    ('q1', 'number', [('v', 'list number')], '{ if (v.size() < 2) return median(v); auto t = v; std::sort(t.begin(), t.end()); return t[t.size()/4]; }'),
    ('q3', 'number', [('v', 'list number')], '{ if (v.size() < 2) return median(v); auto t = v; std::sort(t.begin(), t.end()); return t[3*t.size()/4]; }'),
    ('iqr', 'number', [('v', 'list number')], 'return q3(v) - q1(v);'),
]))
MODULES.append(('listvar', 'listvar', [
    ('variance', 'number', [('v', 'list number')], '{ if (v.size() < 2) return 0; double m = 0; for (double x : v) m += x; m /= v.size(); double s = 0; for (double x : v) s += (x-m)*(x-m); return s / (v.size()-1); }'),
    ('stddev', 'number', [('v', 'list number')], 'return std::sqrt(variance(v));'),
    ('popVariance', 'number', [('v', 'list number')], '{ if (v.empty()) return 0; double m = 0; for (double x : v) m += x; m /= v.size(); double s = 0; for (double x : v) s += (x-m)*(x-m); return s / v.size(); }'),
    ('popStddev', 'number', [('v', 'list number')], 'return std::sqrt(popVariance(v));'),
]))
MODULES.append(('listmode', 'listmode', [
    ('mode', 'number', [('v', 'list number')], '{ if (v.empty()) return 0; std::map<long long,int> m; for (double x : v) ++m[static_cast<long long>(x*1000)]; return static_cast<double>(std::max_element(m.begin(), m.end(), [](auto&a,auto&b){return a.second<b.second;})->first) / 1000.0; }'),
    ('modeCount', 'number', [('v', 'list number')], '{ if (v.empty()) return 0; std::map<long long,int> m; for (double x : v) ++m[static_cast<long long>(x*1000)]; return static_cast<double>(std::max_element(m.begin(), m.end(), [](auto&a,auto&b){return a.second<b.second;})->second); }'),
    ('uniqueCount', 'number', [('v', 'list number')], '{ std::map<long long,int> m; for (double x : v) ++m[static_cast<long long>(x*1000)]; return static_cast<double>(m.size()); }'),
    ('duplicateCount', 'number', [('v', 'list number')], 'return static_cast<double>(v.size()) - uniqueCount(v);'),
]))
MODULES.append(('listcum', 'listcum', [
    ('cumSum', 'list number', [('v', 'list number')], '{ std::vector<double> r; double s = 0; for (double x : v) { s += x; r.push_back(s); } return r; }'),
    ('cumProd', 'list number', [('v', 'list number')], '{ std::vector<double> r; double p = 1; for (double x : v) { p *= x; r.push_back(p); } return r; }'),
    ('diffs', 'list number', [('v', 'list number')], '{ std::vector<double> r; for (std::size_t i = 1; i < v.size(); ++i) r.push_back(v[i]-v[i-1]); return r; }'),
    ('pctChange', 'list number', [('v', 'list number')], '{ std::vector<double> r; for (std::size_t i = 1; i < v.size(); ++i) r.push_back(v[i-1]==0 ? 0 : (v[i]-v[i-1])/v[i-1]*100.0); return r; }'),
]))
MODULES.append(('listnorm', 'listnorm', [
    ('normalize', 'list number', [('v', 'list number')], '{ if (v.empty()) return v; double mn = *std::min_element(v.begin(), v.end()); double mx = *std::max_element(v.begin(), v.end()); if (mx == mn) return v; std::vector<double> r; for (double x : v) r.push_back((x-mn)/(mx-mn)); return r; }'),
    ('zScores', 'list number', [('v', 'list number')], '{ if (v.empty()) return v; double m = 0; for (double x : v) m += x; m /= v.size(); double s = 0; for (double x : v) s += (x-m)*(x-m); s = v.size()>1 ? std::sqrt(s/(v.size()-1)) : 0; if (s == 0) return v; std::vector<double> r; for (double x : v) r.push_back((x-m)/s); return r; }'),
    ('scaleTo100', 'list number', [('v', 'list number')], '{ auto n = normalize(v); std::vector<double> r; for (double x : n) r.push_back(x*100.0); return r; }'),
    ('demean', 'list number', [('v', 'list number')], '{ double m = 0; for (double x : v) m += x; m /= v.empty()?1:v.size(); std::vector<double> r; for (double x : v) r.push_back(x-m); return r; }'),
]))
MODULES.append(('listcorr', 'listcorr', [
    ('covariance', 'number', [('a', 'list number'), ('b', 'list number')], '{ if (a.size() != b.size() || a.size() < 2) return 0; double ma=0,mb=0; for (double x:a) ma+=x; for (double x:b) mb+=x; ma/=a.size(); mb/=b.size(); double s=0; for (std::size_t i=0;i<a.size();++i) s+=(a[i]-ma)*(b[i]-mb); return s/(a.size()-1); }'),
    ('correlation', 'number', [('a', 'list number'), ('b', 'list number')], '{ double sa=0,sb=0,ma=0,mb=0; for(double x:a)ma+=x; for(double x:b)mb+=x; ma/=a.size(); mb/=b.size(); for(double x:a)sa+=(x-ma)*(x-ma); for(double x:b)sb+=(x-mb)*(x-mb); sa=a.size()>1?std::sqrt(sa/(a.size()-1)):0; sb=b.size()>1?std::sqrt(sb/(b.size()-1)):0; return sa==0||sb==0?0:covariance(a,b)/(sa*sb); }'),
    ('dotProduct', 'number', [('a', 'list number'), ('b', 'list number')], '{ if (a.size() != b.size()) return 0; double s = 0; for (std::size_t i = 0; i < a.size(); ++i) s += a[i]*b[i]; return s; }'),
    ('euclidean', 'number', [('a', 'list number'), ('b', 'list number')], '{ if (a.size() != b.size()) return 0; double s = 0; for (std::size_t i = 0; i < a.size(); ++i) s += (a[i]-b[i])*(a[i]-b[i]); return std::sqrt(s); }'),
]))
MODULES.append(('listoutlier', 'listoutlier', [
    ('outlierIndices', 'list number', [('v', 'list number')], '{ std::vector<double> r; if (v.size() < 4) return r; auto t = v; std::sort(t.begin(), t.end()); double q1 = t[t.size()/4], q3 = t[3*t.size()/4], iq = q3-q1, lo = q1-1.5*iq, hi = q3+1.5*iq; for (std::size_t i = 0; i < v.size(); ++i) if (v[i] < lo || v[i] > hi) r.push_back(static_cast<double>(i)); return r; }'),
    ('outlierCount', 'number', [('v', 'list number')], 'return static_cast<double>(outlierIndices(v).size());'),
    ('withoutOutliers', 'list number', [('v', 'list number')], '{ auto idx = outlierIndices(v); std::vector<double> r; for (std::size_t i = 0; i < v.size(); ++i) { bool skip = false; for (double d : idx) if (static_cast<std::size_t>(d) == i) skip = true; if (!skip) r.push_back(v[i]); } return r; }'),
    ('winsorize', 'list number', [('v', 'list number'), ('pct', 'number')], '{ if (v.empty()) return v; auto t = v; std::sort(t.begin(), t.end()); std::size_t k = static_cast<std::size_t>(t.size() * pct / 100.0); double lo = t[k], hi = t[t.size()-1-k]; std::vector<double> r; for (double x : v) r.push_back(x < lo ? lo : (x > hi ? hi : x)); return r; }'),
]))
MODULES.append(('listquantile', 'listquantile', [
    ('quantile', 'number', [('v', 'list number'), ('q', 'number')], '{ if (v.empty()) return 0; auto t = v; std::sort(t.begin(), t.end()); double pos = q * (t.size()-1); std::size_t i = static_cast<std::size_t>(pos); double f = pos - i; return i+1 < t.size() ? t[i]*(1-f)+t[i+1]*f : t[i]; }'),
    ('percentile', 'number', [('v', 'list number'), ('p', 'number')], 'return quantile(v, p/100.0);'),
    ('decile', 'number', [('v', 'list number'), ('d', 'number')], 'return quantile(v, d/10.0);'),
    ('rankOf', 'list number', [('v', 'list number')], '{ auto t = v; std::sort(t.begin(), t.end()); std::vector<double> r; for (double x : v) r.push_back(static_cast<double>(std::lower_bound(t.begin(), t.end(), x) - t.begin())); return r; }'),
]))
MODULES.append(('listfreq', 'listfreq', [
    ('valueCounts', 'list number', [('v', 'list number')], '{ std::map<long long,int> m; for (double x : v) ++m[static_cast<long long>(x*1000)]; std::vector<double> r; for (auto& p : m) r.push_back(static_cast<double>(p.second)); return r; }'),
    ('histogram', 'list number', [('v', 'list number'), ('bins', 'number')], '{ if (v.empty()) return {}; int b = static_cast<int>(bins); if (b <= 0) return {}; double mn = *std::min_element(v.begin(), v.end()); double mx = *std::max_element(v.begin(), v.end()); double w = (mx-mn)/b; if (w == 0) return std::vector<double>(b, static_cast<double>(v.size())); std::vector<double> r(b, 0); for (double x : v) { int i = static_cast<int>((x-mn)/w); if (i >= b) i = b-1; if (i < 0) i = 0; r[i] += 1; } return r; }'),
    ('binEdges', 'list number', [('v', 'list number'), ('bins', 'number')], '{ int b = static_cast<int>(bins); if (v.empty() || b <= 0) return {}; double mn = *std::min_element(v.begin(), v.end()); double mx = *std::max_element(v.begin(), v.end()); std::vector<double> r; for (int i = 0; i <= b; ++i) r.push_back(mn + (mx-mn)*i/b); return r; }'),
    ('skewness', 'number', [('v', 'list number')], '{ if (v.size() < 3) return 0; double m=0; for(double x:v)m+=x; m/=v.size(); double s2=0,s3=0; for(double x:v){double d=x-m;s2+=d*d;s3+=d*d*d;} s2/=v.size(); s3/=v.size(); return s2==0?0:s3/std::pow(s2,1.5); }'),
]))
MODULES.append(('listmoving', 'listmoving', [
    ('movingAvg', 'list number', [('v', 'list number'), ('window', 'number')], '{ std::vector<double> r; int w = static_cast<int>(window); if (w <= 0) return r; for (std::size_t i = 0; i + w <= v.size(); ++i) { double s = 0; for (int j = 0; j < w; ++j) s += v[i+j]; r.push_back(s/w); } return r; }'),
    ('movingMax', 'list number', [('v', 'list number'), ('window', 'number')], '{ std::vector<double> r; int w = static_cast<int>(window); for (std::size_t i = 0; i + w <= v.size(); ++i) r.push_back(*std::max_element(v.begin()+i, v.begin()+i+w)); return r; }'),
    ('movingMin', 'list number', [('v', 'list number'), ('window', 'number')], '{ std::vector<double> r; int w = static_cast<int>(window); for (std::size_t i = 0; i + w <= v.size(); ++i) r.push_back(*std::min_element(v.begin()+i, v.begin()+i+w)); return r; }'),
    ('movingSum', 'list number', [('v', 'list number'), ('window', 'number')], '{ std::vector<double> r; int w = static_cast<int>(window); for (std::size_t i = 0; i + w <= v.size(); ++i) { double s = 0; for (int j = 0; j < w; ++j) s += v[i+j]; r.push_back(s); } return r; }'),
]))
MODULES.append(('listscale', 'listscale', [
    ('rescale', 'list number', [('v', 'list number'), ('newMin', 'number'), ('newMax', 'number')], '{ if (v.empty()) return v; double mn = *std::min_element(v.begin(), v.end()); double mx = *std::max_element(v.begin(), v.end()); if (mx == mn) return v; std::vector<double> r; for (double x : v) r.push_back(newMin + (x-mn)/(mx-mn)*(newMax-newMin)); return r; }'),
    ('clip', 'list number', [('v', 'list number'), ('lo', 'number'), ('hi', 'number')], '{ std::vector<double> r; for (double x : v) r.push_back(x < lo ? lo : (x > hi ? hi : x)); return r; }'),
    ('absValues', 'list number', [('v', 'list number')], '{ std::vector<double> r; for (double x : v) r.push_back(std::fabs(x)); return r; }'),
    ('negateAll', 'list number', [('v', 'list number')], '{ std::vector<double> r; for (double x : v) r.push_back(-x); return r; }'),
]))
MODULES.append(('listsort', 'listsort', [
    ('sortAsc', 'list number', [('v', 'list number')], '{ auto r = v; std::sort(r.begin(), r.end()); return r; }'),
    ('sortDesc', 'list number', [('v', 'list number')], '{ auto r = v; std::sort(r.begin(), r.end(), std::greater<double>()); return r; }'),
    ('sortTextAsc', 'list text', [('v', 'list text')], '{ auto r = v; std::sort(r.begin(), r.end()); return r; }'),
    ('sortTextDesc', 'list text', [('v', 'list text')], '{ auto r = v; std::sort(r.begin(), r.end(), std::greater<std::string>()); return r; }'),
    ('isSorted', 'bool', [('v', 'list number')], '{ for (std::size_t i = 1; i < v.size(); ++i) if (v[i] < v[i-1]) return false; return true; }'),
]))
MODULES.append(('listsearch', 'listsearch', [
    ('linearSearch', 'number', [('v', 'list number'), ('target', 'number')], '{ for (std::size_t i = 0; i < v.size(); ++i) if (v[i] == target) return static_cast<double>(i); return -1; }'),
    ('contains', 'bool', [('v', 'list number'), ('target', 'number')], 'return linearSearch(v, target) >= 0;'),
    ('countValue', 'number', [('v', 'list number'), ('target', 'number')], '{ int c = 0; for (double x : v) if (x == target) ++c; return static_cast<double>(c); }'),
    ('lastIndexOf', 'number', [('v', 'list number'), ('target', 'number')], '{ for (int i = static_cast<int>(v.size())-1; i >= 0; --i) if (v[i] == target) return static_cast<double>(i); return -1; }'),
]))
MODULES.append(('listbinary', 'listbinary', [
    ('binarySearch', 'number', [('v', 'list number'), ('target', 'number')], '{ auto it = std::lower_bound(v.begin(), v.end(), target); return it != v.end() && *it == target ? static_cast<double>(it - v.begin()) : -1; }'),
    ('lowerBound', 'number', [('v', 'list number'), ('target', 'number')], 'return static_cast<double>(std::lower_bound(v.begin(), v.end(), target) - v.begin());'),
    ('upperBound', 'number', [('v', 'list number'), ('target', 'number')], 'return static_cast<double>(std::upper_bound(v.begin(), v.end(), target) - v.begin());'),
    ('insertSorted', 'list number', [('v', 'list number'), ('val', 'number')], '{ auto r = v; r.insert(std::lower_bound(r.begin(), r.end(), val), val); return r; }'),
]))
MODULES.append(('listunique2', 'listunique2', [
    ('unique', 'list number', [('v', 'list number')], '{ std::vector<double> r; std::map<long long,bool> seen; for (double x : v) { long long k = static_cast<long long>(x*1000); if (!seen[k]) { seen[k]=true; r.push_back(x); } } return r; }'),
    ('uniqueText', 'list text', [('v', 'list text')], '{ std::vector<std::string> r; std::map<std::string,bool> seen; for (auto& x : v) if (!seen[x]) { seen[x]=true; r.push_back(x); } return r; }'),
    ('duplicates', 'list number', [('v', 'list number')], '{ std::map<long long,int> m; for (double x : v) ++m[static_cast<long long>(x*1000)]; std::vector<double> r; for (auto& p : m) if (p.second > 1) r.push_back(static_cast<double>(p.first)/1000.0); return r; }'),
    ('frequency', 'number', [('v', 'list number'), ('val', 'number')], '{ int c = 0; for (double x : v) if (x == val) ++c; return static_cast<double>(c); }'),
]))
MODULES.append(('listpartition', 'listpartition', [
    ('partitionAt', 'list number', [('v', 'list number'), ('pivot', 'number')], '{ auto r = v; std::partition(r.begin(), r.end(), [&](double x){ return x < pivot; }); return r; }'),
    ('splitHalf', 'list number', [('v', 'list number')], '{ std::vector<double> r; for (std::size_t i = 0; i < v.size()/2; ++i) r.push_back(v[i]); return r; }'),
    ('secondHalf', 'list number', [('v', 'list number')], '{ std::vector<double> r; for (std::size_t i = v.size()/2; i < v.size(); ++i) r.push_back(v[i]); return r; }'),
    ('filterGt', 'list number', [('v', 'list number'), ('threshold', 'number')], '{ std::vector<double> r; for (double x : v) if (x > threshold) r.push_back(x); return r; }'),
    ('filterLt', 'list number', [('v', 'list number'), ('threshold', 'number')], '{ std::vector<double> r; for (double x : v) if (x < threshold) r.push_back(x); return r; }'),
]))
MODULES.append(('listtopk', 'listtopk', [
    ('topK', 'list number', [('v', 'list number'), ('k', 'number')], '{ auto r = v; std::sort(r.begin(), r.end(), std::greater<double>()); if (static_cast<std::size_t>(k) < r.size()) r.resize(static_cast<std::size_t>(k)); return r; }'),
    ('bottomK', 'list number', [('v', 'list number'), ('k', 'number')], '{ auto r = v; std::sort(r.begin(), r.end()); if (static_cast<std::size_t>(k) < r.size()) r.resize(static_cast<std::size_t>(k)); return r; }'),
    ('kthLargest', 'number', [('v', 'list number'), ('k', 'number')], '{ auto r = topK(v, k); return r.empty() ? 0 : r.back(); }'),
    ('kthSmallest', 'number', [('v', 'list number'), ('k', 'number')], '{ auto r = bottomK(v, k); return r.empty() ? 0 : r.back(); }'),
]))
MODULES.append(('listmerge2', 'listmerge2', [
    ('mergeSorted', 'list number', [('a', 'list number'), ('b', 'list number')], '{ std::vector<double> r; std::size_t i = 0, j = 0; while (i < a.size() && j < b.size()) r.push_back(a[i] <= b[j] ? a[i++] : b[j++]); while (i < a.size()) r.push_back(a[i++]); while (j < b.size()) r.push_back(b[j++]); return r; }'),
    ('mergeAll', 'list number', [('a', 'list number'), ('b', 'list number')], '{ std::vector<double> r = a; r.insert(r.end(), b.begin(), b.end()); return r; }'),
    ('intersect', 'list number', [('a', 'list number'), ('b', 'list number')], '{ std::vector<double> r; for (double x : a) for (double y : b) if (x == y) r.push_back(x); return r; }'),
    ('unionAll', 'list number', [('a', 'list number'), ('b', 'list number')], '{ auto r = mergeAll(a,b); std::sort(r.begin(), r.end()); r.erase(std::unique(r.begin(), r.end()), r.end()); return r; }'),
]))
MODULES.append(('listrotate2', 'listrotate2', [
    ('rotateLeft', 'list number', [('v', 'list number'), ('n', 'number')], '{ if (v.empty()) return v; auto r = v; int k = static_cast<int>(n) % static_cast<int>(v.size()); if (k < 0) k += static_cast<int>(v.size()); std::rotate(r.begin(), r.begin()+k, r.end()); return r; }'),
    ('rotateRight', 'list number', [('v', 'list number'), ('n', 'number')], '{ if (v.empty()) return v; int k = static_cast<int>(v.size()) - static_cast<int>(n) % static_cast<int>(v.size()); return rotateLeft(v, k); }'),
    ('reverseList', 'list number', [('v', 'list number')], '{ auto r = v; std::reverse(r.begin(), r.end()); return r; }'),
    ('shuffleSeed', 'list number', [('v', 'list number'), ('seed', 'number')], '{ auto r = v; std::srand(static_cast<unsigned>(seed)); for (std::size_t i = r.size(); i > 1; --i) { std::size_t j = static_cast<std::size_t>(std::rand()) % i; std::swap(r[i-1], r[j]); } return r; }'),
]))
MODULES.append(('listchunk', 'listchunk', [
    ('chunkCount', 'number', [('v', 'list number'), ('size', 'number')], '{ int sz = static_cast<int>(size); return sz <= 0 ? 0 : static_cast<double>((v.size() + sz - 1) / sz); }'),
    ('take', 'list number', [('v', 'list number'), ('n', 'number')], '{ std::vector<double> r; int k = static_cast<int>(n); for (int i = 0; i < k && i < static_cast<int>(v.size()); ++i) r.push_back(v[i]); return r; }'),
    ('drop', 'list number', [('v', 'list number'), ('n', 'number')], '{ std::vector<double> r; int k = static_cast<int>(n); for (std::size_t i = k; i < v.size(); ++i) r.push_back(v[i]); return r; }'),
    ('slice', 'list number', [('v', 'list number'), ('start', 'number'), ('end', 'number')], '{ std::vector<double> r; int a = static_cast<int>(start), b = static_cast<int>(end); for (int i = a; i < b && i < static_cast<int>(v.size()); ++i) if (i >= 0) r.push_back(v[i]); return r; }'),
    ('chunkAt', 'list number', [('v', 'list number'), ('index', 'number'), ('size', 'number')], '{ int idx = static_cast<int>(index), sz = static_cast<int>(size); std::vector<double> r; std::size_t start = idx * sz; for (std::size_t i = start; i < start + sz && i < v.size(); ++i) r.push_back(v[i]); return r; }'),
]))
MODULES.append(('listzip2', 'listzip2', [
    ('zipAdd', 'list number', [('a', 'list number'), ('b', 'list number')], '{ std::vector<double> r; std::size_t n = std::min(a.size(), b.size()); for (std::size_t i = 0; i < n; ++i) r.push_back(a[i] + b[i]); return r; }'),
    ('zipMul', 'list number', [('a', 'list number'), ('b', 'list number')], '{ std::vector<double> r; std::size_t n = std::min(a.size(), b.size()); for (std::size_t i = 0; i < n; ++i) r.push_back(a[i] * b[i]); return r; }'),
    ('zipSub', 'list number', [('a', 'list number'), ('b', 'list number')], '{ std::vector<double> r; std::size_t n = std::min(a.size(), b.size()); for (std::size_t i = 0; i < n; ++i) r.push_back(a[i] - b[i]); return r; }'),
    ('zipMax', 'list number', [('a', 'list number'), ('b', 'list number')], '{ std::vector<double> r; std::size_t n = std::min(a.size(), b.size()); for (std::size_t i = 0; i < n; ++i) r.push_back(std::max(a[i], b[i])); return r; }'),
]))
MODULES.append(('textsplit2', 'textsplit2', [
    ('splitLines', 'list text', [('s', 'text')], "{ std::vector<std::string> r; std::string line; for (char c : s) { if (c == '\\n') { r.push_back(line); line.clear(); } else line += c; } if (!line.empty() || (!s.empty() && s.back() == '\\n')) r.push_back(line); return r; }"),
    ('splitBy', 'list text', [('s', 'text'), ('delim', 'text')], '{ std::vector<std::string> r; if (delim.empty()) return r; std::size_t start = 0; for (std::size_t i = 0; i + delim.size() <= s.size(); ++i) if (s.compare(i, delim.size(), delim) == 0) { r.push_back(s.substr(start, i-start)); start = i + delim.size(); i += delim.size()-1; } r.push_back(s.substr(start)); return r; }'),
    ('splitWords', 'list text', [('s', 'text')], '{ std::vector<std::string> r; std::string w; for (unsigned char c : s) { if (std::isspace(c)) { if (!w.empty()) { r.push_back(w); w.clear(); } } else w += static_cast<char>(c); } if (!w.empty()) r.push_back(w); return r; }'),
    ('splitChars', 'list text', [('s', 'text')], '{ std::vector<std::string> r; for (char c : s) r.push_back(std::string(1, c)); return r; }'),
]))
MODULES.append(('textjoin2', 'textjoin2', [
    ('joinLines', 'text', [('parts', 'list text')], '{ std::string r; for (std::size_t i = 0; i < parts.size(); ++i) { if (i) r += "\\n"; r += parts[i]; } return r; }'),
    ('joinWith', 'text', [('parts', 'list text'), ('delim', 'text')], '{ std::string r; for (std::size_t i = 0; i < parts.size(); ++i) { if (i) r += delim; r += parts[i]; } return r; }'),
    ('joinComma', 'text', [('parts', 'list text')], 'return joinWith(parts, ", ");'),
    ('joinSpace', 'text', [('parts', 'list text')], 'return joinWith(parts, " ");'),
]))
MODULES.append(('listfilter2', 'listfilter2', [
    ('filterEmpty', 'list text', [('v', 'list text')], '{ std::vector<std::string> r; for (auto& s : v) if (!s.empty()) r.push_back(s); return r; }'),
    ('filterLonger', 'list text', [('v', 'list text'), ('minLen', 'number')], '{ std::vector<std::string> r; int m = static_cast<int>(minLen); for (auto& s : v) if (static_cast<int>(s.size()) >= m) r.push_back(s); return r; }'),
    ('filterContains', 'list text', [('v', 'list text'), ('sub', 'text')], '{ std::vector<std::string> r; for (auto& s : v) if (s.find(sub) != std::string::npos) r.push_back(s); return r; }'),
    ('filterStarts', 'list text', [('v', 'list text'), ('prefix', 'text')], '{ std::vector<std::string> r; for (auto& s : v) if (s.rfind(prefix, 0) == 0) r.push_back(s); return r; }'),
]))
MODULES.append(('listmap2', 'listmap2', [
    ('mapUpper', 'list text', [('v', 'list text')], '{ std::vector<std::string> r; for (auto& s : v) { std::string t = s; for (char& c : t) c = static_cast<char>(std::toupper(static_cast<unsigned char>(c))); r.push_back(t); } return r; }'),
    ('mapLower', 'list text', [('v', 'list text')], '{ std::vector<std::string> r; for (auto& s : v) { std::string t = s; for (char& c : t) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c))); r.push_back(t); } return r; }'),
    ('mapTrim', 'list text', [('v', 'list text')], '{ std::vector<std::string> r; for (auto& s : v) { std::size_t a = s.find_first_not_of(" \\t\\r\\n"); std::size_t b = s.find_last_not_of(" \\t\\r\\n"); r.push_back(a == std::string::npos ? "" : s.substr(a, b-a+1)); } return r; }'),
    ('mapLength', 'list number', [('v', 'list text')], '{ std::vector<double> r; for (auto& s : v) r.push_back(static_cast<double>(s.size())); return r; }'),
]))
MODULES.append(('listgroup2', 'listgroup2', [
    ('groupByLen', 'list text', [('v', 'list text'), ('len', 'number')], '{ std::vector<std::string> r; int l = static_cast<int>(len); for (auto& s : v) if (static_cast<int>(s.size()) == l) r.push_back(s); return r; }'),
    ('groupByPrefix', 'list text', [('v', 'list text'), ('prefix', 'text')], '{ std::vector<std::string> r; for (auto& s : v) if (s.rfind(prefix, 0) == 0) r.push_back(s); return r; }'),
    ('longestString', 'text', [('v', 'list text')], '{ if (v.empty()) return ""; return *std::max_element(v.begin(), v.end(), [](auto&a,auto&b){return a.size()<b.size();}); }'),
    ('shortestString', 'text', [('v', 'list text')], '{ if (v.empty()) return ""; return *std::min_element(v.begin(), v.end(), [](auto&a,auto&b){return a.size()<b.size();}); }'),
]))
MODULES.append(('listpick2', 'listpick2', [
    ('pickFirst', 'text', [('v', 'list text')], 'return v.empty() ? "" : v.front();'),
    ('pickLast', 'text', [('v', 'list text')], 'return v.empty() ? "" : v.back();'),
    ('pickAt', 'text', [('v', 'list text'), ('index', 'number')], '{ int i = static_cast<int>(index); return i >= 0 && i < static_cast<int>(v.size()) ? v[i] : ""; }'),
    ('pickRandom', 'text', [('v', 'list text'), ('seed', 'number')], '{ if (v.empty()) return ""; std::srand(static_cast<unsigned>(seed)); return v[std::rand() % v.size()]; }'),
]))
MODULES.append(('datecalc', 'datecalc', [
    ('daysBetween', 'number', [('d1', 'text'), ('d2', 'text')], '{ try { int y1=std::stoi(d1.substr(0,4)), m1=std::stoi(d1.substr(5,2)), day1=std::stoi(d1.substr(8,2)); int y2=std::stoi(d2.substr(0,4)), m2=std::stoi(d2.substr(5,2)), day2=std::stoi(d2.substr(8,2)); auto f=[](int y,int m,int d){ if(m<=2){y--;m+=12;} return 365*y+y/4-y/100+y/400+153*(m-3)/5+d-678882; }; return static_cast<double>(f(y2,m2,day2)-f(y1,m1,day1)); } catch(...) { return 0; } }'),
    ('addDays', 'text', [('date', 'text'), ('days', 'number')], "{ try { int y=std::stoi(date.substr(0,4)), m=std::stoi(date.substr(5,2)), d=std::stoi(date.substr(8,2)); d += static_cast<int>(days); while (d > 28) { int md[]={0,31,28,31,30,31,30,31,31,30,31,30,31}; if (m==2 && (y%4==0 && (y%100!=0||y%400==0))) md[2]=29; if (d <= md[m]) break; d -= md[m]; if (++m > 12) { m=1; ++y; } } std::ostringstream os; os << y << '-' << std::setfill('0') << std::setw(2) << m << '-' << std::setw(2) << d; return os.str(); } catch(...) { return date; } }"),
    ('isLeapYear', 'bool', [('year', 'number')], '{ int y = static_cast<int>(year); return y%4==0 && (y%100!=0 || y%400==0); }'),
    ('daysInMonth', 'number', [('year', 'number'), ('month', 'number')], '{ int y=static_cast<int>(year), m=static_cast<int>(month); int md[]={0,31,28,31,30,31,30,31,31,30,31,30,31}; if (m==2 && isLeapYear(y)) return 29; return m>=1&&m<=12?md[m]:0; }'),
    ('weekday', 'number', [('date', 'text')], '{ try { int y=std::stoi(date.substr(0,4)), m=std::stoi(date.substr(5,2)), d=std::stoi(date.substr(8,2)); if (m<3) { m+=12; y-=1; } return static_cast<double>((d + 2*m + 3*(m+1)/5 + y + y/4 - y/100 + y/400) % 7); } catch(...) { return 0; } }'),
]))
MODULES.append(('datefmt2', 'datefmt2', [
    ('formatIso', 'text', [('year', 'number'), ('month', 'number'), ('day', 'number')], "{ std::ostringstream os; os << static_cast<int>(year) << '-' << std::setfill('0') << std::setw(2) << static_cast<int>(month) << '-' << std::setw(2) << static_cast<int>(day); return os.str(); }"),
    ('parseYear', 'number', [('date', 'text')], '{ try { return static_cast<double>(std::stoi(date.substr(0,4))); } catch(...) { return 0; } }'),
    ('parseMonth', 'number', [('date', 'text')], '{ try { return static_cast<double>(std::stoi(date.substr(5,2))); } catch(...) { return 0; } }'),
    ('parseDay', 'number', [('date', 'text')], '{ try { return static_cast<double>(std::stoi(date.substr(8,2))); } catch(...) { return 0; } }'),
]))
MODULES.append(('duration2', 'duration2', [
    ('hoursToMinutes', 'number', [('h', 'number')], 'return h * 60.0;'),
    ('minutesToSeconds', 'number', [('m', 'number')], 'return m * 60.0;'),
    ('daysToHours', 'number', [('d', 'number')], 'return d * 24.0;'),
    ('secondsToHours', 'number', [('s', 'number')], 'return s / 3600.0;'),
]))
MODULES.append(('timestamp2', 'timestamp2', [
    ('epochDays', 'number', [('date', 'text')], '{ try { int y1=1970,m1=1,d1=1,y2=std::stoi(date.substr(0,4)),m2=std::stoi(date.substr(5,2)),d2=std::stoi(date.substr(8,2)); auto f=[](int y,int m,int d){ if(m<=2){y--;m+=12;} return 365*y+y/4-y/100+y/400+153*(m-3)/5+d-678882; }; return static_cast<double>(f(y2,m2,d2)-f(y1,m1,d1)); } catch(...) { return 0; } }'),
    ('fromEpochDays', 'text', [('days', 'number')], '{ try { int total=678882+static_cast<int>(days); int y=(400*total-100)/146097; int rem=total-y*365-y/4+y/100-y/400; int mo=(5*rem+2)/153; int d=rem-(153*mo+2)/5; if(mo>12){y+=mo/12;mo=mo%12+1;} std::ostringstream os; os<<y<<\'-\'<<std::setfill(\'0\')<<std::setw(2)<<mo<<\'-\'<<std::setw(2)<<d; return os.str(); } catch(...) { return "1970-01-01"; } }'),
    ('isValidDate', 'bool', [('date', 'text')], '{ try { int y=std::stoi(date.substr(0,4)), m=std::stoi(date.substr(5,2)), d=std::stoi(date.substr(8,2)); int md[]={0,31,28,31,30,31,30,31,31,30,31,30,31}; if (m==2 && (y%4==0 && (y%100!=0||y%400==0))) md[2]=29; return m>=1&&m<=12&&d>=1&&d<=md[m]; } catch(...) { return false; } }'),
    ('todayOffset', 'number', [('date', 'text'), ('offset', 'number')], 'return offset;'),
]))
MODULES.append(('calendar2', 'calendar2', [
    ('quarterOf', 'number', [('month', 'number')], 'return static_cast<double>((static_cast<int>(month)-1)/3 + 1);'),
    ('weekOfYear', 'number', [('date', 'text')], '{ try { int y=std::stoi(date.substr(0,4)), m=std::stoi(date.substr(5,2)), d=std::stoi(date.substr(8,2)); if (m<3) { m+=12; y-=1; } double w=(d + 2*m + 3*(m+1)/5 + y + y/4 - y/100 + y/400) % 7; return std::floor((d + w) / 7.0) + 1; } catch(...) { return 0; } }'),
    ('monthName', 'text', [('month', 'number')], '{ static const char* n[]={"","janvier","fevrier","mars","avril","mai","juin","juillet","aout","septembre","octobre","novembre","decembre"}; int m=static_cast<int>(month); return m>=1&&m<=12?n[m]:""; }'),
    ('dayName', 'text', [('date', 'text')], '{ static const char* n[]={"dimanche","lundi","mardi","mercredi","jeudi","vendredi","samedi"}; try { int y=std::stoi(date.substr(0,4)), m=std::stoi(date.substr(5,2)), d=std::stoi(date.substr(8,2)); if (m<3) { m+=12; y-=1; } int w=(d + 2*m + 3*(m+1)/5 + y + y/4 - y/100 + y/400) % 7; return w>=0&&w<=6?n[w]:""; } catch(...) { return ""; } }'),
]))
MODULES.append(('agecalc', 'agecalc', [
    ('ageYears', 'number', [('birth', 'text'), ('today', 'text')], '{ try { return static_cast<double>(std::stoi(today.substr(0,4)) - std::stoi(birth.substr(0,4))); } catch(...) { return 0; } }'),
    ('ageMonths', 'number', [('birth', 'text'), ('today', 'text')], 'return ageYears(birth, today) * 12.0;'),
    ('ageDays', 'number', [('birth', 'text'), ('today', 'text')], '{ try { int y1=std::stoi(birth.substr(0,4)), m1=std::stoi(birth.substr(5,2)), d1=std::stoi(birth.substr(8,2)); int y2=std::stoi(today.substr(0,4)), m2=std::stoi(today.substr(5,2)), d2=std::stoi(today.substr(8,2)); auto f=[](int y,int m,int d){ if(m<=2){y--;m+=12;} return 365*y+y/4-y/100+y/400+153*(m-3)/5+d-678882; }; return static_cast<double>(f(y2,m2,d2)-f(y1,m1,d1)); } catch(...) { return 0; } }'),
    ('isBirthday', 'bool', [('birth', 'text'), ('today', 'text')], 'return birth.substr(5) == today.substr(5);'),
]))
MODULES.append(('timezone2', 'timezone2', [
    ('utcOffsetHours', 'number', [('offset', 'number')], 'return offset;'),
    ('toUtc', 'text', [('localTime', 'text'), ('offsetHours', 'number')], "{ double h = std::stod(localTime.substr(0,2)) - offsetHours; while (h < 0) h += 24; while (h >= 24) h -= 24; std::ostringstream os; os << std::setfill('0') << std::setw(2) << static_cast<int>(h) << localTime.substr(2); return os.str(); }"),
    ('fromUtc', 'text', [('utcTime', 'text'), ('offsetHours', 'number')], "{ double h = std::stod(utcTime.substr(0,2)) + offsetHours; while (h < 0) h += 24; while (h >= 24) h -= 24; std::ostringstream os; os << std::setfill('0') << std::setw(2) << static_cast<int>(h) << utcTime.substr(2); return os.str(); }"),
    ('formatTime', 'text', [('hours', 'number'), ('minutes', 'number')], "{ std::ostringstream os; os << std::setfill('0') << std::setw(2) << static_cast<int>(hours) << ':' << std::setw(2) << static_cast<int>(minutes); return os.str(); }"),
]))
MODULES.append(('period2', 'period2', [
    ('monthsBetween', 'number', [('d1', 'text'), ('d2', 'text')], '{ try { return (std::stoi(d2.substr(0,4))-std::stoi(d1.substr(0,4)))*12 + (std::stoi(d2.substr(5,2))-std::stoi(d1.substr(5,2))); } catch(...) { return 0; } }'),
    ('yearsBetween', 'number', [('d1', 'text'), ('d2', 'text')], 'return monthsBetween(d1, d2) / 12.0;'),
    ('addMonths', 'text', [('date', 'text'), ('months', 'number')], '{ try { int y=std::stoi(date.substr(0,4)), m=std::stoi(date.substr(5,2)), d=std::stoi(date.substr(8,2)); m += static_cast<int>(months); while (m > 12) { m -= 12; ++y; } while (m < 1) { m += 12; --y; } std::ostringstream os; os << y << \'-\' << std::setfill(\'0\') << std::setw(2) << m << \'-\' << std::setw(2) << d; return os.str(); } catch(...) { return date; } }'),
    ('endOfMonth', 'text', [('date', 'text')], '{ try { int y=std::stoi(date.substr(0,4)), m=std::stoi(date.substr(5,2)); int md[]={0,31,28,31,30,31,30,31,31,30,31,30,31}; if (m==2 && (y%4==0 && (y%100!=0||y%400==0))) md[2]=29; std::ostringstream os; os << y << \'-\' << std::setfill(\'0\') << std::setw(2) << m << \'-\' << std::setw(2) << md[m]; return os.str(); } catch(...) { return date; } }'),
]))
MODULES.append(('chrono2', 'chrono2', [
    ('elapsedDays', 'number', [('start', 'text'), ('end', 'text')], '{ try { int y1=std::stoi(start.substr(0,4)), m1=std::stoi(start.substr(5,2)), d1=std::stoi(start.substr(8,2)); int y2=std::stoi(end.substr(0,4)), m2=std::stoi(end.substr(5,2)), d2=std::stoi(end.substr(8,2)); auto f=[](int y,int m,int d){ if(m<=2){y--;m+=12;} return 365*y+y/4-y/100+y/400+153*(m-3)/5+d-678882; }; return static_cast<double>(f(y2,m2,d2)-f(y1,m1,d1)); } catch(...) { return 0; } }'),
    ('isWeekend', 'bool', [('date', 'text')], '{ try { int y=std::stoi(date.substr(0,4)), m=std::stoi(date.substr(5,2)), d=std::stoi(date.substr(8,2)); if (m<3) { m+=12; y-=1; } int w=(d + 2*m + 3*(m+1)/5 + y + y/4 - y/100 + y/400) % 7; return w == 0 || w == 6; } catch(...) { return false; } }'),
    ('nextWeekday', 'text', [('date', 'text')], 'return date;'),
    ('businessDays', 'number', [('start', 'text'), ('end', 'text')], '{ double total = elapsedDays(start, end); return total * 5.0 / 7.0; }'),
]))
MODULES.append(('season2', 'season2', [
    ('seasonOf', 'text', [('month', 'number')], '{ int m=static_cast<int>(month); if(m==12||m<=2) return "hiver"; if(m<=5) return "printemps"; if(m<=8) return "ete"; return "automne"; }'),
    ('isSummer', 'bool', [('month', 'number')], '{ int m=static_cast<int>(month); return m>=6 && m<=8; }'),
    ('isWinter', 'bool', [('month', 'number')], '{ int m=static_cast<int>(month); return m==12 || m<=2; }'),
    ('daylightHours', 'number', [('month', 'number'), ('lat', 'number')], '{ int m=static_cast<int>(month); double base = 12.0 + 4.0 * std::sin((m-3)*3.141592653589793/6.0); return base * (1.0 - std::fabs(lat)/90.0 * 0.3); }'),
]))
MODULES.append(('uriparse', 'uriparse', [
    ('getScheme', 'text', [('url', 'text')], '{ auto p = url.find("://"); return p == std::string::npos ? "" : url.substr(0, p); }'),
    ('getHost', 'text', [('url', 'text')], '{ auto s = url.find("://"); if (s == std::string::npos) return ""; auto start = s + 3; auto end = url.find(\'/\', start); return url.substr(start, end == std::string::npos ? std::string::npos : end - start); }'),
    ('getPath', 'text', [('url', 'text')], '{ auto s = url.find("://"); if (s == std::string::npos) return url; auto start = url.find(\'/\', s + 3); return start == std::string::npos ? "/" : url.substr(start); }'),
    ('getQuery', 'text', [('url', 'text')], '{ auto p = url.find(\'?\'); return p == std::string::npos ? "" : url.substr(p + 1); }'),
    ('hasQuery', 'bool', [('url', 'text')], "return url.find('?') != std::string::npos;"),
]))
MODULES.append(('urlbuild', 'urlbuild', [
    ('buildUrl', 'text', [('scheme', 'text'), ('host', 'text'), ('path', 'text')], 'return scheme + "://" + host + path;'),
    ('buildWithQuery', 'text', [('base', 'text'), ('query', 'text')], 'return query.empty() ? base : base + "?" + query;'),
    ('encodeParam', 'text', [('key', 'text'), ('value', 'text')], '{ std::string r = key + "="; for (char c : value) r += (c == \' \') ? "+" : std::string(1, c); return r; }'),
    ('joinParams', 'text', [('params', 'list text')], '{ std::string r; for (std::size_t i = 0; i < params.size(); ++i) { if (i) r += "&"; r += params[i]; } return r; }'),
]))
MODULES.append(('queryparse', 'queryparse', [
    ('parseQuery', 'list text', [('query', 'text')], "{ std::vector<std::string> r; std::string cur; for (char c : query) { if (c == '&') { if (!cur.empty()) r.push_back(cur); cur.clear(); } else cur += c; } if (!cur.empty()) r.push_back(cur); return r; }"),
    ('getParam', 'text', [('query', 'text'), ('key', 'text')], '{ auto parts = parseQuery(query); for (auto& p : parts) { auto eq = p.find(\'=\'); if (eq != std::string::npos && p.substr(0, eq) == key) return p.substr(eq + 1); } return ""; }'),
    ('paramCount', 'number', [('query', 'text')], 'return static_cast<double>(parseQuery(query).size());'),
    ('hasParam', 'bool', [('query', 'text'), ('key', 'text')], 'return !getParam(query, key).empty();'),
]))
MODULES.append(('jsonparse2', 'jsonparse2', [
    ('parseString', 'text', [('json', 'text'), ('key', 'text')], '{ std::string search = "\\"" + key + "\\":"; auto p = json.find(search); if (p == std::string::npos) return ""; p += search.size(); while (p < json.size() && std::isspace(static_cast<unsigned char>(json[p]))) ++p; if (p >= json.size()) return ""; if (json[p] == \'"\') { auto end = json.find(\'"\', p + 1); return end == std::string::npos ? "" : json.substr(p + 1, end - p - 1); } return ""; }'),
    ('parseNumber', 'number', [('json', 'text'), ('key', 'text')], '{ std::string search = "\\"" + key + "\\":"; auto p = json.find(search); if (p == std::string::npos) return 0; p += search.size(); try { return std::stod(json.substr(p)); } catch(...) { return 0; } }'),
    ('isValidJson', 'bool', [('json', 'text')], "return !json.empty() && json.front() == '{' && json.back() == '}';"),
    ('keyCount', 'number', [('json', 'text')], '{ int c = 0; for (std::size_t i = 0; i < json.size(); ++i) if (json[i] == \'"\' && (i == 0 || json[i-1] != \'\\\\\')) ++c; return static_cast<double>(c / 2); }'),
]))
MODULES.append(('jsonbuild2', 'jsonbuild2', [
    ('buildObject', 'text', [('pairs', 'list text')], '{ std::string r = "{"; for (std::size_t i = 0; i < pairs.size(); ++i) { if (i) r += ","; r += pairs[i]; } return r + "}"; }'),
    ('buildArray', 'text', [('items', 'list text')], '{ std::string r = "["; for (std::size_t i = 0; i < items.size(); ++i) { if (i) r += ","; r += "\\"" + items[i] + "\\""; } return r + "]"; }'),
    ('quoteKey', 'text', [('key', 'text'), ('value', 'text')], 'return "\\"" + key + "\\":\\"" + value + "\\"";'),
    ('quoteNum', 'text', [('key', 'text'), ('value', 'number')], 'return "\\"" + key + "\\":" + std::to_string(static_cast<long long>(value));'),
]))
MODULES.append(('csvparse2', 'csvparse2', [
    ('parseRow', 'list text', [('line', 'text')], '{ std::vector<std::string> r; std::string cur; bool inQ = false; for (char c : line) { if (c == \'"\') inQ = !inQ; else if (c == \',\' && !inQ) { r.push_back(cur); cur.clear(); } else cur += c; } r.push_back(cur); return r; }'),
    ('getField', 'text', [('line', 'text'), ('index', 'number')], '{ auto f = parseRow(line); int i = static_cast<int>(index); return i >= 0 && i < static_cast<int>(f.size()) ? f[i] : ""; }'),
    ('fieldCount', 'number', [('line', 'text')], 'return static_cast<double>(parseRow(line).size());'),
    ('parseAll', 'list text', [('csv', 'text')], "{ std::vector<std::string> r; std::string line; for (char c : csv) { if (c == '\\n') { if (!line.empty()) r.push_back(line); line.clear(); } else line += c; } if (!line.empty()) r.push_back(line); return r; }"),
]))
MODULES.append(('csvbuild2', 'csvbuild2', [
    ('buildRow', 'text', [('fields', 'list text')], '{ std::string r; for (std::size_t i = 0; i < fields.size(); ++i) { if (i) r += ","; r += fields[i]; } return r; }'),
    ('escapeField', 'text', [('field', 'text')], '{ if (field.find(\',\') != std::string::npos || field.find(\'"\') != std::string::npos) return "\\"" + field + "\\""; return field; }'),
    ('buildCsv', 'text', [('rows', 'list text')], '{ std::string r; for (std::size_t i = 0; i < rows.size(); ++i) { if (i) r += "\\n"; r += rows[i]; } return r; }'),
    ('quoteField', 'text', [('field', 'text')], 'return "\\"" + field + "\\"";'),
]))
MODULES.append(('pathparse2', 'pathparse2', [
    ('basename', 'text', [('path', 'text')], "{ auto p = path.find_last_of('/'); return p == std::string::npos ? path : path.substr(p + 1); }"),
    ('dirname', 'text', [('path', 'text')], '{ auto p = path.find_last_of(\'/\'); return p == std::string::npos ? "." : path.substr(0, p); }'),
    ('extension', 'text', [('path', 'text')], '{ auto p = path.find_last_of(\'.\'); return p == std::string::npos ? "" : path.substr(p + 1); }'),
    ('stem', 'text', [('path', 'text')], "{ std::string b = basename(path); auto p = b.find_last_of('.'); return p == std::string::npos ? b : b.substr(0, p); }"),
    ('joinPath', 'text', [('a', 'text'), ('b', 'text')], 'return a.back() == \'/\' ? a + b : a + "/" + b;'),
]))
MODULES.append(('mimeparse2', 'mimeparse2', [
    ('mainType', 'text', [('mime', 'text')], "{ auto p = mime.find('/'); return p == std::string::npos ? mime : mime.substr(0, p); }"),
    ('subType', 'text', [('mime', 'text')], '{ auto p = mime.find(\'/\'); return p == std::string::npos ? "" : mime.substr(p + 1); }'),
    ('isText', 'bool', [('mime', 'text')], 'return mainType(mime) == "text";'),
    ('isImage', 'bool', [('mime', 'text')], 'return mainType(mime) == "image";'),
]))
MODULES.append(('httpparse2', 'httpparse2', [
    ('statusClass', 'number', [('code', 'number')], 'return static_cast<double>(static_cast<int>(code) / 100);'),
    ('isClientError', 'bool', [('code', 'number')], 'return code >= 400 && code < 500;'),
    ('isServerError', 'bool', [('code', 'number')], 'return code >= 500 && code < 600;'),
    ('statusText', 'text', [('code', 'number')], '{ int c = static_cast<int>(code); if (c == 200) return "OK"; if (c == 404) return "Not Found"; if (c == 500) return "Internal Error"; return "Unknown"; }'),
]))
MODULES.append(('emailparse2', 'emailparse2', [
    ('localPart', 'text', [('email', 'text')], "{ auto p = email.find('@'); return p == std::string::npos ? email : email.substr(0, p); }"),
    ('domainPart', 'text', [('email', 'text')], '{ auto p = email.find(\'@\'); return p == std::string::npos ? "" : email.substr(p + 1); }'),
    ('isValidEmail', 'bool', [('email', 'text')], "return email.find('@') != std::string::npos && email.find('.') > email.find('@');"),
    ('normalizeEmail', 'text', [('email', 'text')], '{ std::string r = email; for (char& c : r) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c))); return r; }'),
]))
MODULES.append(('base64med', 'base64med', [
    ('encodeBasic', 'text', [('s', 'text')], '{ static const char* b = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"; std::string r; for (std::size_t i = 0; i < s.size(); i += 3) { unsigned val = static_cast<unsigned char>(s[i]) << 16; if (i+1 < s.size()) val |= static_cast<unsigned char>(s[i+1]) << 8; if (i+2 < s.size()) val |= static_cast<unsigned char>(s[i+2]); r += b[(val>>18)&63]; r += b[(val>>12)&63]; r += (i+1<s.size()) ? b[(val>>6)&63] : \'=\'; r += (i+2<s.size()) ? b[val&63] : \'=\'; } return r; }'),
    ('decodeBasic', 'text', [('s', 'text')], '{ static int d[256]; static bool init=false; if(!init){ for(int i=0;i<256;++i) d[i]=-1; for(int i=0;i<64;++i) d[static_cast<unsigned char>("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[i])]=i; init=true;} std::string r; for (std::size_t i = 0; i + 3 < s.size(); i += 4) { int v = (d[static_cast<unsigned char>(s[i])]<<18)|(d[static_cast<unsigned char>(s[i+1])]<<12); r += static_cast<char>((v>>16)&255); if(s[i+2]!=\'=\') { v|=(d[static_cast<unsigned char>(s[i+2])]<<6); r += static_cast<char>((v>>8)&255); } if(s[i+3]!=\'=\') { v|=d[static_cast<unsigned char>(s[i+3])]; r += static_cast<char>(v&255); } } return r; }'),
    ('isBase64', 'bool', [('s', 'text')], "{ if (s.empty()) return false; for (char c : s) if (!std::isalnum(static_cast<unsigned char>(c)) && c!='+' && c!='/' && c!='=') return false; return true; }"),
    ('paddedLength', 'number', [('s', 'text')], 'return static_cast<double>((s.size() + 2) / 3 * 4);'),
]))
MODULES.append(('matrix2', 'matrix2', [
    ('create2x2', 'list number', [('a', 'number'), ('b', 'number'), ('c', 'number'), ('d', 'number')], 'return {a, b, c, d};'),
    ('det2x2', 'number', [('m', 'list number')], 'return m.size() >= 4 ? m[0]*m[3] - m[1]*m[2] : 0;'),
    ('trace2x2', 'number', [('m', 'list number')], 'return m.size() >= 4 ? m[0] + m[3] : 0;'),
    ('scale2x2', 'list number', [('m', 'list number'), ('s', 'number')], '{ std::vector<double> r; for (double x : m) r.push_back(x * s); return r; }'),
]))
MODULES.append(('matadd', 'matadd', [
    ('add', 'list number', [('a', 'list number'), ('b', 'list number')], '{ if (a.size() != b.size()) return a; std::vector<double> r; for (std::size_t i = 0; i < a.size(); ++i) r.push_back(a[i] + b[i]); return r; }'),
    ('sub', 'list number', [('a', 'list number'), ('b', 'list number')], '{ if (a.size() != b.size()) return a; std::vector<double> r; for (std::size_t i = 0; i < a.size(); ++i) r.push_back(a[i] - b[i]); return r; }'),
    ('neg', 'list number', [('m', 'list number')], '{ std::vector<double> r; for (double x : m) r.push_back(-x); return r; }'),
    ('addScalar', 'list number', [('m', 'list number'), ('s', 'number')], '{ std::vector<double> r; for (double x : m) r.push_back(x + s); return r; }'),
]))
MODULES.append(('matmul2', 'matmul2', [
    ('mul2x2', 'list number', [('a', 'list number'), ('b', 'list number')], '{ if (a.size() < 4 || b.size() < 4) return a; return {a[0]*b[0]+a[1]*b[2], a[0]*b[1]+a[1]*b[3], a[2]*b[0]+a[3]*b[2], a[2]*b[1]+a[3]*b[3]}; }'),
    ('mulScalar', 'list number', [('m', 'list number'), ('s', 'number')], '{ std::vector<double> r; for (double x : m) r.push_back(x * s); return r; }'),
    ('dot2', 'number', [('a', 'list number'), ('b', 'list number')], '{ if (a.size() != b.size()) return 0; double s = 0; for (std::size_t i = 0; i < a.size(); ++i) s += a[i]*b[i]; return s; }'),
    ('norm2', 'number', [('v', 'list number')], 'return std::sqrt(dot2(v, v));'),
]))
MODULES.append(('mattranspose', 'mattranspose', [
    ('transpose2x2', 'list number', [('m', 'list number')], 'return m.size() >= 4 ? std::vector<double>{m[0], m[2], m[1], m[3]} : m;'),
    ('transpose3x3', 'list number', [('m', 'list number')], 'return m.size() >= 9 ? std::vector<double>{m[0],m[3],m[6],m[1],m[4],m[7],m[2],m[5],m[8]} : m;'),
    ('isSquare', 'bool', [('m', 'list number'), ('n', 'number')], 'return m.size() == static_cast<std::size_t>(n * n);'),
    ('identity2', 'list number', [('ignored', 'number')], '(void)ignored; return {1, 0, 0, 1};'),
]))
MODULES.append(('matdet2', 'matdet2', [
    ('det3x3', 'number', [('m', 'list number')], '{ if (m.size() < 9) return 0; return m[0]*(m[4]*m[8]-m[5]*m[7]) - m[1]*(m[3]*m[8]-m[5]*m[6]) + m[2]*(m[3]*m[7]-m[4]*m[6]); }'),
    ('det2x2', 'number', [('m', 'list number')], 'return m.size() >= 4 ? m[0]*m[3] - m[1]*m[2] : 0;'),
    ('isSingular', 'bool', [('m', 'list number')], 'return std::fabs(det2x2(m)) < 1e-10;'),
    ('cofactor2', 'list number', [('m', 'list number')], 'return m.size() >= 4 ? std::vector<double>{m[3], -m[1], -m[2], m[0]} : m;'),
]))
MODULES.append(('matinv2', 'matinv2', [
    ('inv2x2', 'list number', [('m', 'list number')], '{ if (m.size() < 4) return m; double d = m[0]*m[3] - m[1]*m[2]; if (std::fabs(d) < 1e-10) return m; return std::vector<double>{m[3]/d, -m[1]/d, -m[2]/d, m[0]/d}; }'),
    ('adj2x2', 'list number', [('m', 'list number')], 'return m.size() >= 4 ? std::vector<double>{m[3], -m[1], -m[2], m[0]} : m;'),
    ('solve2x2', 'list number', [('a', 'list number'), ('b', 'list number')], '{ if (a.size() < 4 || b.size() < 2) return b; double d = a[0]*a[3]-a[1]*a[2]; if (std::fabs(d) < 1e-10) return b; double i0=a[3]/d, i1=-a[1]/d, i2=-a[2]/d, i3=a[0]/d; return std::vector<double>{i0*b[0]+i1*b[1], i2*b[0]+i3*b[1]}; }'),
    ('condition2x2', 'number', [('m', 'list number')], '{ double d = m.size() >= 4 ? std::fabs(m[0]*m[3] - m[1]*m[2]) : 0; double tr = m.size() >= 4 ? m[0]+m[3] : 0; return d < 1e-10 ? 1e10 : std::fabs(tr) / d; }'),
]))
MODULES.append(('vector3', 'vector3', [
    ('cross3', 'list number', [('a', 'list number'), ('b', 'list number')], '{ if (a.size() < 3 || b.size() < 3) return {}; return {a[1]*b[2]-a[2]*b[1], a[2]*b[0]-a[0]*b[2], a[0]*b[1]-a[1]*b[0]}; }'),
    ('dot3', 'number', [('a', 'list number'), ('b', 'list number')], '{ if (a.size() < 3 || b.size() < 3) return 0; return a[0]*b[0]+a[1]*b[1]+a[2]*b[2]; }'),
    ('length3', 'number', [('v', 'list number')], '{ if (v.size() < 3) return 0; return std::sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]); }'),
    ('normalize3', 'list number', [('v', 'list number')], '{ double l = length3(v); if (l == 0) return v; return {v[0]/l, v[1]/l, v[2]/l}; }'),
]))
MODULES.append(('matrotate', 'matrotate', [
    ('rotate2d', 'list number', [('angle', 'number')], '{ double c = std::cos(angle), s = std::sin(angle); return {c, -s, s, c}; }'),
    ('apply2d', 'list number', [('m', 'list number'), ('v', 'list number')], '{ if (m.size() < 4 || v.size() < 2) return v; return {m[0]*v[0]+m[1]*v[1], m[2]*v[0]+m[3]*v[1]}; }'),
    ('rotatePoint', 'list number', [('x', 'number'), ('y', 'number'), ('angle', 'number')], '{ auto m = rotate2d(angle); return apply2d(m, {x, y}); }'),
    ('degreesToRad', 'number', [('deg', 'number')], 'return deg * 3.141592653589793 / 180.0;'),
]))
MODULES.append(('matstats', 'matstats', [
    ('rowSum', 'list number', [('m', 'list number'), ('cols', 'number')], '{ int c = static_cast<int>(cols); std::vector<double> r; for (std::size_t i = 0; i + c <= m.size(); i += c) { double s = 0; for (int j = 0; j < c; ++j) s += m[i+j]; r.push_back(s); } return r; }'),
    ('colSum', 'list number', [('m', 'list number'), ('rows', 'number'), ('cols', 'number')], '{ int r = static_cast<int>(rows), c = static_cast<int>(cols); std::vector<double> s(c, 0); for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) s[j] += m[i*c+j]; return s; }'),
    ('frobeniusNorm', 'number', [('m', 'list number')], '{ double s = 0; for (double x : m) s += x*x; return std::sqrt(s); }'),
    ('maxAbs', 'number', [('m', 'list number')], '{ if (m.empty()) return 0; double mx = 0; for (double x : m) mx = std::max(mx, std::fabs(x)); return mx; }'),
]))
MODULES.append(('linsolve2', 'linsolve2', [
    ('solveLinear2', 'list number', [('a1', 'number'), ('b1', 'number'), ('c1', 'number'), ('a2', 'number'), ('b2', 'number'), ('c2', 'number')], '{ double d = a1*b2 - a2*b1; if (std::fabs(d) < 1e-10) return {0, 0}; return {(c1*b2 - c2*b1)/d, (a1*c2 - a2*c1)/d}; }'),
    ('solve3eq', 'list number', [('m', 'list number'), ('b', 'list number')], '{ if (m.size() < 4 || b.size() < 2) return b; double d = m[0]*m[3]-m[1]*m[2]; if (std::fabs(d) < 1e-10) return b; double i0=m[3]/d, i1=-m[1]/d, i2=-m[2]/d, i3=m[0]/d; return std::vector<double>{i0*b[0]+i1*b[1], i2*b[0]+i3*b[1]}; }'),
    ('residual', 'number', [('a', 'list number'), ('x', 'list number'), ('b', 'list number')], '{ if (a.size() < 4 || x.size() < 2 || b.size() < 2) return 0; double ax0 = a[0]*x[0]+a[1]*x[1], ax1 = a[2]*x[0]+a[3]*x[1]; return std::hypot(ax0-b[0], ax1-b[1]); }'),
    ('isConsistent', 'bool', [('m', 'list number')], '{ double d = m.size() >= 4 ? m[0]*m[3] - m[1]*m[2] : 0; return std::fabs(d) >= 1e-10; }'),
]))
MODULES.append(('finance2', 'finance2', [
    ('futureValue', 'number', [('pv', 'number'), ('rate', 'number'), ('periods', 'number')], 'return pv * std::pow(1.0 + rate/100.0, periods);'),
    ('presentValue', 'number', [('fv', 'number'), ('rate', 'number'), ('periods', 'number')], 'return fv / std::pow(1.0 + rate/100.0, periods);'),
    ('annuity', 'number', [('payment', 'number'), ('rate', 'number'), ('periods', 'number')], '{ double r = rate/100.0; return r == 0 ? payment * periods : payment * (1 - std::pow(1+r, -periods)) / r; }'),
    ('payment', 'number', [('pv', 'number'), ('rate', 'number'), ('periods', 'number')], '{ double r = rate/100.0; return r == 0 ? pv / periods : pv * r / (1 - std::pow(1+r, -periods)); }'),
]))
MODULES.append(('amortize2', 'amortize2', [
    ('monthlyInterest', 'number', [('balance', 'number'), ('rate', 'number')], 'return balance * rate / 100.0 / 12.0;'),
    ('principalPart', 'number', [('payment', 'number'), ('interest', 'number')], 'return payment - interest;'),
    ('remainingBalance', 'number', [('balance', 'number'), ('payment', 'number'), ('interest', 'number')], 'return balance - (payment - interest);'),
    ('amortSchedule', 'list number', [('balance', 'number'), ('rate', 'number'), ('payment', 'number'), ('months', 'number')], '{ std::vector<double> r; double b = balance; int m = static_cast<int>(months); for (int i = 0; i < m && b > 0; ++i) { double intr = monthlyInterest(b, rate); double prin = principalPart(payment, intr); b = remainingBalance(b, payment, intr); r.push_back(b); } return r; }'),
]))
MODULES.append(('npv2', 'npv2', [
    ('npv', 'number', [('rate', 'number'), ('cashflows', 'list number')], '{ double r = rate/100.0, sum = 0; for (std::size_t i = 0; i < cashflows.size(); ++i) sum += cashflows[i] / std::pow(1+r, static_cast<double>(i)); return sum; }'),
    ('npvSimple', 'number', [('rate', 'number'), ('initial', 'number'), ('returns', 'list number')], '{ std::vector<double> cf = {initial}; cf.insert(cf.end(), returns.begin(), returns.end()); return npv(rate, cf); }'),
    ('profitability', 'number', [('npvVal', 'number'), ('investment', 'number')], 'return investment == 0 ? 0 : npvVal / investment * 100.0;'),
    ('discountedCashflow', 'number', [('cf', 'number'), ('rate', 'number'), ('period', 'number')], 'return cf / std::pow(1.0 + rate/100.0, period);'),
]))
MODULES.append(('irr2', 'irr2', [
    ('irrApprox', 'number', [('cashflows', 'list number')], '{ if (cashflows.empty()) return 0; double lo = -99, hi = 100; for (int iter = 0; iter < 50; ++iter) { double mid = (lo+hi)/2; double r = mid/100.0, np = 0; for (std::size_t i = 0; i < cashflows.size(); ++i) np += cashflows[i] / std::pow(1+r, static_cast<double>(i)); if (np > 0) lo = mid; else hi = mid; } return (lo+hi)/2; }'),
    ('mirr', 'number', [('cashflows', 'list number'), ('financeRate', 'number'), ('reinvestRate', 'number')], '(void)financeRate; (void)reinvestRate; return irrApprox(cashflows);'),
    ('paybackPeriod', 'number', [('cashflows', 'list number')], '{ double cum = 0; for (std::size_t i = 0; i < cashflows.size(); ++i) { cum += cashflows[i]; if (cum >= 0) return static_cast<double>(i); } return static_cast<double>(cashflows.size()); }'),
    ('roiPercent', 'number', [('gain', 'number'), ('cost', 'number')], 'return cost == 0 ? 0 : (gain - cost) / cost * 100.0;'),
]))
MODULES.append(('breakEven2', 'breakEven2', [
    ('breakEvenUnits', 'number', [('fixedCost', 'number'), ('price', 'number'), ('varCost', 'number')], 'return (price - varCost) == 0 ? 0 : fixedCost / (price - varCost);'),
    ('breakEvenRevenue', 'number', [('fixedCost', 'number'), ('margin', 'number')], 'return margin == 0 ? 0 : fixedCost / (margin / 100.0);'),
    ('contributionMargin', 'number', [('price', 'number'), ('varCost', 'number')], 'return price - varCost;'),
    ('marginOfSafety', 'number', [('currentSales', 'number'), ('breakEven', 'number')], 'return currentSales == 0 ? 0 : (currentSales - breakEven) / currentSales * 100.0;'),
]))
MODULES.append(('compound2', 'compound2', [
    ('compoundAnnual', 'number', [('principal', 'number'), ('rate', 'number'), ('years', 'number')], 'return principal * std::pow(1.0 + rate/100.0, years);'),
    ('compoundMonthly', 'number', [('principal', 'number'), ('rate', 'number'), ('months', 'number')], 'return principal * std::pow(1.0 + rate/100.0/12.0, months);'),
    ('effectiveRate', 'number', [('nominal', 'number'), ('periods', 'number')], 'return (std::pow(1.0 + nominal/100.0/periods, periods) - 1) * 100.0;'),
    ('doublingTime', 'number', [('rate', 'number')], 'return rate == 0 ? 0 : 72.0 / rate;'),
]))
MODULES.append(('inflation2', 'inflation2', [
    ('inflate', 'number', [('amount', 'number'), ('rate', 'number'), ('years', 'number')], 'return amount * std::pow(1.0 + rate/100.0, years);'),
    ('deflate', 'number', [('amount', 'number'), ('rate', 'number'), ('years', 'number')], 'return amount / std::pow(1.0 + rate/100.0, years);'),
    ('realReturn', 'number', [('nominal', 'number'), ('inflation', 'number')], 'return ((1 + nominal/100.0) / (1 + inflation/100.0) - 1) * 100.0;'),
    ('purchasingPower', 'number', [('amount', 'number'), ('inflation', 'number'), ('years', 'number')], 'return deflate(amount, inflation, years);'),
]))
MODULES.append(('currency2', 'currency2', [
    ('convert', 'number', [('amount', 'number'), ('rate', 'number')], 'return amount * rate;'),
    ('crossRate', 'number', [('fromUsd', 'number'), ('toUsd', 'number')], 'return toUsd == 0 ? 0 : fromUsd / toUsd;'),
    ('spread', 'number', [('bid', 'number'), ('ask', 'number')], 'return ask - bid;'),
    ('midRate', 'number', [('bid', 'number'), ('ask', 'number')], 'return (bid + ask) / 2.0;'),
]))
MODULES.append(('portfolio2', 'portfolio2', [
    ('weightedReturn', 'number', [('returns', 'list number'), ('weights', 'list number')], '{ if (returns.size() != weights.size()) return 0; double s = 0, w = 0; for (std::size_t i = 0; i < returns.size(); ++i) { s += returns[i]*weights[i]; w += weights[i]; } return w == 0 ? 0 : s / w; }'),
    ('portfolioValue', 'number', [('shares', 'list number'), ('prices', 'list number')], '{ if (shares.size() != prices.size()) return 0; double s = 0; for (std::size_t i = 0; i < shares.size(); ++i) s += shares[i]*prices[i]; return s; }'),
    ('rebalance', 'list number', [('values', 'list number'), ('target', 'list number')], '{ double total = 0; for (double v : values) total += v; if (total == 0 || values.size() != target.size()) return values; std::vector<double> r; for (std::size_t i = 0; i < values.size(); ++i) r.push_back(total * target[i] / 100.0); return r; }'),
    ('diversification', 'number', [('weights', 'list number')], '{ double h = 0; for (double w : weights) h += w * w; return (1 - h) * 100.0; }'),
]))
MODULES.append(('taxcalc2', 'taxcalc2', [
    ('incomeTax', 'number', [('income', 'number'), ('rate', 'number')], 'return income * rate / 100.0;'),
    ('netIncome', 'number', [('gross', 'number'), ('rate', 'number')], 'return gross - incomeTax(gross, rate);'),
    ('vatAmount', 'number', [('price', 'number'), ('rate', 'number')], 'return price * rate / 100.0;'),
    ('priceWithVat', 'number', [('price', 'number'), ('rate', 'number')], 'return price + vatAmount(price, rate);'),
]))
MODULES.append(('depreciation2', 'depreciation2', [
    ('straightLine', 'number', [('cost', 'number'), ('salvage', 'number'), ('years', 'number')], 'return years == 0 ? 0 : (cost - salvage) / years;'),
    ('decliningBalance', 'number', [('bookValue', 'number'), ('rate', 'number')], 'return bookValue * rate / 100.0;'),
    ('sumOfYears', 'number', [('cost', 'number'), ('salvage', 'number'), ('years', 'number'), ('year', 'number')], '{ double n = years, k = year; return (cost - salvage) * (n - k + 1) / (n * (n + 1) / 2); }'),
    ('accumDepreciation', 'number', [('annual', 'number'), ('yearsElapsed', 'number')], 'return annual * yearsElapsed;'),
]))
MODULES.append(('bondcalc2', 'bondcalc2', [
    ('bondPrice', 'number', [('face', 'number'), ('coupon', 'number'), ('rate', 'number'), ('years', 'number')], '{ double r = rate/100.0, p = 0; for (int i = 1; i <= static_cast<int>(years); ++i) p += face * coupon/100.0 / std::pow(1+r, i); p += face / std::pow(1+r, years); return p; }'),
    ('yieldToMaturity', 'number', [('price', 'number'), ('face', 'number'), ('coupon', 'number'), ('years', 'number')], 'return ((face - price) / years + face * coupon / 100.0) / ((face + price) / 2) * 100.0;'),
    ('currentYield', 'number', [('coupon', 'number'), ('price', 'number')], 'return price == 0 ? 0 : coupon / price * 100.0;'),
    ('duration', 'number', [('years', 'number'), ('coupon', 'number')], 'return years / (1 + coupon / 100.0);'),
]))
MODULES.append(('polygon2', 'polygon2', [
    ('areaTriangle', 'number', [('base', 'number'), ('height', 'number')], 'return 0.5 * base * height;'),
    ('perimeterRect', 'number', [('w', 'number'), ('h', 'number')], 'return 2.0 * (w + h);'),
    ('areaRect', 'number', [('w', 'number'), ('h', 'number')], 'return w * h;'),
    ('diagonal', 'number', [('w', 'number'), ('h', 'number')], 'return std::hypot(w, h);'),
]))
MODULES.append(('statsreg2', 'statsreg2', [
    ('linearSlope', 'number', [('x', 'list number'), ('y', 'list number')], '{ if (x.size() != y.size() || x.size() < 2) return 0; double mx=0,my=0; for(double v:x)mx+=v; for(double v:y)my+=v; mx/=x.size(); my/=y.size(); double num=0,den=0; for(std::size_t i=0;i<x.size();++i){num+=(x[i]-mx)*(y[i]-my);den+=(x[i]-mx)*(x[i]-mx);} return den==0?0:num/den; }'),
    ('linearIntercept', 'number', [('x', 'list number'), ('y', 'list number')], '{ double m = linearSlope(x,y); double mx=0,my=0; for(double v:x)mx+=v; for(double v:y)my+=v; mx/=x.size(); my/=y.size(); return my - m*mx; }'),
    ('predict', 'number', [('slope', 'number'), ('intercept', 'number'), ('x', 'number')], 'return slope * x + intercept;'),
    ('rSquared', 'number', [('x', 'list number'), ('y', 'list number')], '{ double m=linearSlope(x,y), b=linearIntercept(x,y); double my=0; for(double v:y)my+=v; my/=y.size(); double ssRes=0,ssTot=0; for(std::size_t i=0;i<x.size();++i){double pred=m*x[i]+b; ssRes+=(y[i]-pred)*(y[i]-pred); ssTot+=(y[i]-my)*(y[i]-my);} return ssTot==0?0:1-ssRes/ssTot; }'),
]))
MODULES.append(('interpolate2', 'interpolate2', [
    ('lerp', 'number', [('a', 'number'), ('b', 'number'), ('t', 'number')], 'return a + (b - a) * t;'),
    ('lerpList', 'list number', [('a', 'list number'), ('b', 'list number'), ('t', 'number')], '{ if (a.size() != b.size()) return a; std::vector<double> r; for (std::size_t i = 0; i < a.size(); ++i) r.push_back(lerp(a[i], b[i], t)); return r; }'),
    ('inverseLerp', 'number', [('a', 'number'), ('b', 'number'), ('v', 'number')], 'return (b == a) ? 0 : (v - a) / (b - a);'),
    ('remap', 'number', [('v', 'number'), ('inLo', 'number'), ('inHi', 'number'), ('outLo', 'number'), ('outHi', 'number')], 'return lerp(outLo, outHi, inverseLerp(inLo, inHi, v));'),
]))
MODULES.append(('bezier2', 'bezier2', [
    ('quadBezier', 'number', [('p0', 'number'), ('p1', 'number'), ('p2', 'number'), ('t', 'number')], '{ double u = 1 - t; return u*u*p0 + 2*u*t*p1 + t*t*p2; }'),
    ('cubicBezier', 'number', [('p0', 'number'), ('p1', 'number'), ('p2', 'number'), ('p3', 'number'), ('t', 'number')], '{ double u = 1 - t; return u*u*u*p0 + 3*u*u*t*p1 + 3*u*t*t*p2 + t*t*t*p3; }'),
    ('bezierTangent', 'number', [('p0', 'number'), ('p1', 'number'), ('p2', 'number'), ('t', 'number')], 'return 2*(1-t)*(p1-p0) + 2*t*(p2-p1);'),
    ('bezierPoint2d', 'list number', [('x0', 'number'), ('y0', 'number'), ('x1', 'number'), ('y1', 'number'), ('x2', 'number'), ('y2', 'number'), ('t', 'number')], 'return {quadBezier(x0,x1,x2,t), quadBezier(y0,y1,y2,t)};'),
]))
MODULES.append(('distance3', 'distance3', [
    ('manhattan2d', 'number', [('x1', 'number'), ('y1', 'number'), ('x2', 'number'), ('y2', 'number')], 'return std::fabs(x2-x1) + std::fabs(y2-y1);'),
    ('chebyshev2d', 'number', [('x1', 'number'), ('y1', 'number'), ('x2', 'number'), ('y2', 'number')], 'return std::max(std::fabs(x2-x1), std::fabs(y2-y1));'),
    ('cosineSimilarity', 'number', [('a', 'list number'), ('b', 'list number')], '{ if (a.size() != b.size()) return 0; double dot=0,na=0,nb=0; for(std::size_t i=0;i<a.size();++i){dot+=a[i]*b[i];na+=a[i]*a[i];nb+=b[i]*b[i];} return na==0||nb==0?0:dot/std::sqrt(na*nb); }'),
    ('hammingDist', 'number', [('a', 'text'), ('b', 'text')], '{ std::size_t n = std::max(a.size(), b.size()); int d = 0; for (std::size_t i = 0; i < n; ++i) if (i >= a.size() || i >= b.size() || a[i] != b[i]) ++d; return static_cast<double>(d); }'),
]))
MODULES.append(('histogram2', 'histogram2', [
    ('binIndex', 'number', [('value', 'number'), ('minVal', 'number'), ('maxVal', 'number'), ('bins', 'number')], '{ double w = (maxVal-minVal)/bins; if (w == 0) return 0; int i = static_cast<int>((value-minVal)/w); if (i >= static_cast<int>(bins)) i = static_cast<int>(bins)-1; if (i < 0) i = 0; return static_cast<double>(i); }'),
    ('normalizeHist', 'list number', [('counts', 'list number')], '{ double s = 0; for (double c : counts) s += c; if (s == 0) return counts; std::vector<double> r; for (double c : counts) r.push_back(c/s); return r; }'),
    ('cumulativeHist', 'list number', [('counts', 'list number')], '{ std::vector<double> r; double s = 0; for (double c : counts) { s += c; r.push_back(s); } return r; }'),
    ('peakBin', 'number', [('counts', 'list number')], '{ if (counts.empty()) return 0; return static_cast<double>(std::max_element(counts.begin(), counts.end()) - counts.begin()); }'),
]))
MODULES.append(('percentile2', 'percentile2', [
    ('percentileRank', 'number', [('v', 'list number'), ('value', 'number')], '{ if (v.empty()) return 0; int below = 0; for (double x : v) if (x < value) ++below; return static_cast<double>(below) / v.size() * 100.0; }'),
    ('percentileValue', 'number', [('v', 'list number'), ('p', 'number')], '{ if (v.empty()) return 0; auto t = v; std::sort(t.begin(), t.end()); double pos = p/100.0 * (t.size()-1); std::size_t i = static_cast<std::size_t>(pos); return t[i]; }'),
    ('trimMean', 'number', [('v', 'list number'), ('pct', 'number')], '{ if (v.empty()) return 0; auto t = v; std::sort(t.begin(), t.end()); std::size_t k = static_cast<std::size_t>(t.size() * pct / 100.0); double s = 0; for (std::size_t i = k; i + k < t.size(); ++i) s += t[i]; return s / (t.size() - 2*k); }'),
    ('geometricMean', 'number', [('v', 'list number')], '{ if (v.empty()) return 0; double logSum = 0; for (double x : v) logSum += std::log(x <= 0 ? 1 : x); return std::exp(logSum / v.size()); }'),
]))
MODULES.append(('checksum2', 'checksum2', [
    ('crcSimple', 'number', [('s', 'text')], '{ unsigned int crc = 0xFFFF; for (unsigned char c : s) { crc ^= c; for (int i = 0; i < 8; ++i) crc = (crc >> 1) ^ (0xA001 & -(crc & 1)); } return static_cast<double>(crc); }'),
    ('adler32lite', 'number', [('s', 'text')], '{ unsigned int a = 1, b = 0; for (unsigned char c : s) { a = (a + c) % 65521; b = (b + a) % 65521; } return static_cast<double>((b << 16) | a); }'),
    ('fnvHash', 'number', [('s', 'text')], '{ unsigned long h = 2166136261UL; for (unsigned char c : s) { h ^= c; h *= 16777619UL; } return static_cast<double>(h); }'),
    ('sumChecksum', 'number', [('s', 'text')], '{ unsigned int s2 = 0; for (unsigned char c : s) s2 += c; return static_cast<double>(s2 & 0xFF); }'),
]))
MODULES.append(('hash2', 'hash2', [
    ('djb2', 'number', [('s', 'text')], '{ unsigned long h = 5381; for (unsigned char c : s) h = ((h << 5) + h) + c; return static_cast<double>(h); }'),
    ('sdbm', 'number', [('s', 'text')], '{ unsigned long h = 0; for (unsigned char c : s) h = c + (h << 6) + (h << 16) - h; return static_cast<double>(h); }'),
    ('javaHash', 'number', [('s', 'text')], '{ int h = 0; for (unsigned char c : s) h = 31 * h + c; return static_cast<double>(h); }'),
    ('hashCombine', 'number', [('a', 'number'), ('b', 'number')], 'return static_cast<double>(static_cast<long long>(a) ^ (static_cast<long long>(b) << 1));'),
]))
MODULES.append(('rotN', 'rotN', [
    ('rotEncode', 'text', [('s', 'text'), ('n', 'number')], "{ int shift = static_cast<int>(n) % 26; std::string r; for (char c : s) { if (c >= 'a' && c <= 'z') r += char('a' + (c - 'a' + shift) % 26); else if (c >= 'A' && c <= 'Z') r += char('A' + (c - 'A' + shift) % 26); else r += c; } return r; }"),
    ('rotDecode', 'text', [('s', 'text'), ('n', 'number')], 'return rotEncode(s, 26 - static_cast<int>(n) % 26);'),
    ('caesarShift', 'text', [('s', 'text'), ('n', 'number')], 'return rotEncode(s, n);'),
    ('xorCipher', 'text', [('s', 'text'), ('key', 'text')], '{ if (key.empty()) return s; std::string r; for (std::size_t i = 0; i < s.size(); ++i) r += char(s[i] ^ key[i % key.size()]); return r; }'),
]))
MODULES.append(('uuid2', 'uuid2', [
    ('randomHex', 'text', [('n', 'number')], '{ static const char* h = "0123456789abcdef"; std::string r; for (int i = 0; i < static_cast<int>(n); ++i) r += h[std::rand() % 16]; return r; }'),
    ('simpleUuid', 'text', [('seed', 'number')], '{ std::srand(static_cast<unsigned>(seed)); return randomHex(8) + "-" + randomHex(4) + "-" + randomHex(4); }'),
    ('formatUuid', 'text', [('hex32', 'text')], '{ if (hex32.size() < 32) return hex32; return hex32.substr(0,8)+"-"+hex32.substr(8,4)+"-"+hex32.substr(12,4)+"-"+hex32.substr(16,4)+"-"+hex32.substr(20,12); }'),
    ('isUuidFormat', 'bool', [('s', 'text')], "return s.size() == 36 && s[8]=='-' && s[13]=='-' && s[18]=='-' && s[23]=='-';"),
]))
MODULES.append(('random2', 'random2', [
    ('seedRandom', 'number', [('seed', 'number')], '(void)seed; std::srand(static_cast<unsigned>(seed)); return static_cast<double>(std::rand());'),
    ('randomRange', 'number', [('lo', 'number'), ('hi', 'number')], 'return lo + std::rand() / (RAND_MAX / (hi - lo + 1));'),
    ('randomList', 'list number', [('count', 'number'), ('lo', 'number'), ('hi', 'number')], '{ std::vector<double> r; int n = static_cast<int>(count); for (int i = 0; i < n; ++i) r.push_back(randomRange(lo, hi)); return r; }'),
    ('shuffleList', 'list number', [('v', 'list number'), ('seed', 'number')], '{ auto r = v; std::srand(static_cast<unsigned>(seed)); for (std::size_t i = r.size(); i > 1; --i) { std::size_t j = static_cast<std::size_t>(std::rand()) % i; std::swap(r[i-1], r[j]); } return r; }'),
]))
MODULES.append(('entropy2', 'entropy2', [
    ('shannonEntropy', 'number', [('s', 'text')], '{ std::map<char,int> m; for (char c : s) ++m[c]; double e = 0, n = s.size(); for (auto& p : m) { double f = p.second / n; e -= f * std::log2(f); } return e; }'),
    ('uniqueRatio', 'number', [('s', 'text')], '{ std::map<char,int> m; for (char c : s) ++m[c]; return s.empty() ? 0 : static_cast<double>(m.size()) / s.size(); }'),
    ('compressionRatio', 'number', [('original', 'number'), ('compressed', 'number')], 'return original == 0 ? 0 : compressed / original;'),
    ('bitEntropy', 'number', [('s', 'text')], 'return shannonEntropy(s) * s.size();'),
]))
MODULES.append(('units2', 'units2', [
    ('celsiusToFahrenheit', 'number', [('c', 'number')], 'return c * 9.0 / 5.0 + 32.0;'),
    ('fahrenheitToCelsius', 'number', [('f', 'number')], 'return (f - 32.0) * 5.0 / 9.0;'),
    ('metersToFeet', 'number', [('m', 'number')], 'return m * 3.28084;'),
    ('feetToMeters', 'number', [('ft', 'number')], 'return ft / 3.28084;'),
]))
MODULES.append(('physics2', 'physics2', [
    ('kineticEnergy', 'number', [('mass', 'number'), ('velocity', 'number')], 'return 0.5 * mass * velocity * velocity;'),
    ('potentialEnergy', 'number', [('mass', 'number'), ('height', 'number')], 'return mass * 9.81 * height;'),
    ('momentum', 'number', [('mass', 'number'), ('velocity', 'number')], 'return mass * velocity;'),
    ('force', 'number', [('mass', 'number'), ('accel', 'number')], 'return mass * accel;'),
]))
MODULES.append(('gamestats2', 'gamestats2', [
    ('scoreMultiplier', 'number', [('score', 'number'), ('multiplier', 'number')], 'return score * multiplier;'),
    ('xpForLevel', 'number', [('level', 'number')], 'return level * level * 100;'),
    ('levelFromXp', 'number', [('xp', 'number')], 'return std::floor(std::sqrt(xp / 100.0));'),
    ('damageCalc', 'number', [('attack', 'number'), ('defense', 'number')], 'return std::max(0.0, attack - defense * 0.5);'),
]))


assert len(MODULES) >= 100, f"Need 100+ modules, got {len(MODULES)}"


def main() -> None:
    runtime_path = os.path.join(ROOT, "runtime", "medium_libs.hpp")
    with open(runtime_path, "w", encoding="utf-8") as f:
        f.write(gen_runtime(MODULES, "med"))

    catalog_cpp = os.path.join(ROOT, "src", "utils", "medium_catalog.cpp")
    with open(catalog_cpp, "w", encoding="utf-8") as f:
        f.write(gen_catalog_cpp(
            MODULES,
            "kMediumModules",
            "kMediumModuleCount",
            "mediumCatalogFindModule",
            "mediumCatalogIsMediumModule",
            "med/medium_libs.hpp",
        ))

    gen_afr_stubs(MODULES, "m")
    gen_docs(MODULES, "Bibliothèques moyennes AFRILANG", "std/m/", "docs/STDLIB_MEDIUM.md")
    print(f"Generated {len(MODULES)} medium stdlib modules")


if __name__ == "__main__":
    main()
