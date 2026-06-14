// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <functional>
#include "simple_libs.hpp"
#include "medium_libs.hpp"
#include "str.hpp"

namespace textstats {
} // namespace textstats

namespace numstats {
} // namespace numstats

namespace uriparse {
} // namespace uriparse

namespace datecalc {
} // namespace datecalc

namespace format {
} // namespace format

namespace textstats {
    double wordCount(std::string s) {
        return afrilang::runtime::med::textstats::wordCount(s);
    }

    double charCount(std::string s) {
        return afrilang::runtime::med::textstats::charCount(s);
    }

    double lineCount(std::string s) {
        return afrilang::runtime::med::textstats::lineCount(s);
    }

    double avgWordLen(std::string s) {
        return afrilang::runtime::med::textstats::avgWordLen(s);
    }

    double digitCount(std::string s) {
        return afrilang::runtime::med::textstats::digitCount(s);
    }

} // namespace textstats

namespace numstats {
    double sum(std::vector<double> v) {
        return afrilang::runtime::med::numstats::sum(v);
    }

    double mean(std::vector<double> v) {
        return afrilang::runtime::med::numstats::mean(v);
    }

    double minVal(std::vector<double> v) {
        return afrilang::runtime::med::numstats::minVal(v);
    }

    double maxVal(std::vector<double> v) {
        return afrilang::runtime::med::numstats::maxVal(v);
    }

    double range(std::vector<double> v) {
        return afrilang::runtime::med::numstats::range(v);
    }

} // namespace numstats

namespace uriparse {
    std::string getScheme(std::string url) {
        return afrilang::runtime::med::uriparse::getScheme(url);
    }

    std::string getHost(std::string url) {
        return afrilang::runtime::med::uriparse::getHost(url);
    }

    std::string getPath(std::string url) {
        return afrilang::runtime::med::uriparse::getPath(url);
    }

    std::string getQuery(std::string url) {
        return afrilang::runtime::med::uriparse::getQuery(url);
    }

    bool hasQuery(std::string url) {
        return afrilang::runtime::med::uriparse::hasQuery(url);
    }

} // namespace uriparse

namespace datecalc {
    double daysBetween(std::string d1, std::string d2) {
        return afrilang::runtime::med::datecalc::daysBetween(d1, d2);
    }

    std::string addDays(std::string date, double days) {
        return afrilang::runtime::med::datecalc::addDays(date, days);
    }

    bool isLeapYear(double year) {
        return afrilang::runtime::med::datecalc::isLeapYear(year);
    }

    double daysInMonth(double year, double month) {
        return afrilang::runtime::med::datecalc::daysInMonth(year, month);
    }

    double weekday(std::string date) {
        return afrilang::runtime::med::datecalc::weekday(date);
    }

} // namespace datecalc

namespace format {
    std::string formatNumber(double n, double decimals) {
        return afrilang::runtime::format::formatNumber(n, decimals);
    }

    std::string formatPercent(double n) {
        return afrilang::runtime::format::formatPercent(n);
    }

} // namespace format

using namespace format;
using namespace datecalc;
using namespace uriparse;
using namespace numstats;
using namespace textstats;

int main() {
    #line 7 "/home/maxime/AFRILANG/build/../examples/medium_libs_demo.afr"
        #line 8 "/home/maxime/AFRILANG/build/../examples/medium_libs_demo.afr"
        #line 9 "/home/maxime/AFRILANG/build/../examples/medium_libs_demo.afr"
        #line 10 "/home/maxime/AFRILANG/build/../examples/medium_libs_demo.afr"
        #line 11 "/home/maxime/AFRILANG/build/../examples/medium_libs_demo.afr"
        #line 13 "/home/maxime/AFRILANG/build/../examples/medium_libs_demo.afr"
    double words = textstats::wordCount("bonjour le monde afrilang");
    #line 14 "/home/maxime/AFRILANG/build/../examples/medium_libs_demo.afr"
    std::cout << format::formatNumber(words, 0) << std::endl;
    #line 16 "/home/maxime/AFRILANG/build/../examples/medium_libs_demo.afr"
    std::vector<double> nums = {3, 7, 2, 9, 4};
    #line 17 "/home/maxime/AFRILANG/build/../examples/medium_libs_demo.afr"
    double avg = numstats::mean(nums);
    #line 18 "/home/maxime/AFRILANG/build/../examples/medium_libs_demo.afr"
    std::cout << format::formatNumber(avg, 2) << std::endl;
    #line 20 "/home/maxime/AFRILANG/build/../examples/medium_libs_demo.afr"
    std::string host = uriparse::getHost("https://example.com/path?q=1");
    #line 21 "/home/maxime/AFRILANG/build/../examples/medium_libs_demo.afr"
    std::cout << host << std::endl;
    #line 23 "/home/maxime/AFRILANG/build/../examples/medium_libs_demo.afr"
    double days = datecalc::daysBetween("2024-01-01", "2024-12-31");
    #line 24 "/home/maxime/AFRILANG/build/../examples/medium_libs_demo.afr"
    std::cout << format::formatNumber(days, 0) << std::endl;
    return 0;
}
