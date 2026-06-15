// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <stdexcept>
#include <functional>
#include "simple_libs.hpp"
#include "complex_libs.hpp"
#include "str.hpp"

namespace nlplevenshtein {
    double distance(std::string a, std::string b) {
        return afrilang::runtime::cx::nlplevenshtein::distance(a, b);
    }

    double similarity(std::string a, std::string b) {
        return afrilang::runtime::cx::nlplevenshtein::similarity(a, b);
    }

    double ratio(std::string a, std::string b) {
        return afrilang::runtime::cx::nlplevenshtein::ratio(a, b);
    }

    bool isClose(std::string a, std::string b, double maxDist) {
        return afrilang::runtime::cx::nlplevenshtein::isClose(a, b, maxDist);
    }

    double normalizedDist(std::string a, std::string b) {
        return afrilang::runtime::cx::nlplevenshtein::normalizedDist(a, b);
    }

    double longestCommon(std::string a, std::string b) {
        return afrilang::runtime::cx::nlplevenshtein::longestCommon(a, b);
    }

} // namespace nlplevenshtein

namespace statcorrel {
    double pearson(std::vector<double> a, std::vector<double> b) {
        return afrilang::runtime::cx::statcorrel::pearson(a, b);
    }

    double covariance(std::vector<double> a, std::vector<double> b) {
        return afrilang::runtime::cx::statcorrel::covariance(a, b);
    }

    double crossCorr(std::vector<double> a, std::vector<double> b, double lag) {
        return afrilang::runtime::cx::statcorrel::crossCorr(a, b, lag);
    }

    double autocorr1(std::vector<double> v) {
        return afrilang::runtime::cx::statcorrel::autocorr1(v);
    }

    double partialCorr(std::vector<double> a, std::vector<double> b, std::vector<double> c) {
        return afrilang::runtime::cx::statcorrel::partialCorr(a, b, c);
    }

    std::vector<double> corrMatrix2(std::vector<double> a, std::vector<double> b) {
        return afrilang::runtime::cx::statcorrel::corrMatrix2(a, b);
    }

    double rankCorr(std::vector<double> a, std::vector<double> b) {
        return afrilang::runtime::cx::statcorrel::rankCorr(a, b);
    }

} // namespace statcorrel

namespace mlcosine {
    double cosineSim(std::vector<double> a, std::vector<double> b) {
        return afrilang::runtime::cx::mlcosine::cosineSim(a, b);
    }

    double cosineDist(std::vector<double> a, std::vector<double> b) {
        return afrilang::runtime::cx::mlcosine::cosineDist(a, b);
    }

    std::vector<double> normalize(std::vector<double> v) {
        return afrilang::runtime::cx::mlcosine::normalize(v);
    }

    double angularDist(std::vector<double> a, std::vector<double> b) {
        return afrilang::runtime::cx::mlcosine::angularDist(a, b);
    }

    std::vector<double> batchCosine(std::vector<double> query, std::vector<double> matrix, double dims) {
        return afrilang::runtime::cx::mlcosine::batchCosine(query, matrix, dims);
    }

    double mostSimilar(std::vector<double> query, std::vector<double> matrix, double dims) {
        return afrilang::runtime::cx::mlcosine::mostSimilar(query, matrix, dims);
    }

} // namespace mlcosine

namespace format {
    std::string formatNumber(double n, double decimals) {
        return afrilang::runtime::format::formatNumber(n, decimals);
    }

    std::string formatPercent(double n) {
        return afrilang::runtime::format::formatPercent(n);
    }

} // namespace format

using namespace format;
using namespace mlcosine;
using namespace statcorrel;
using namespace nlplevenshtein;

int main() {
    #line 6 "/home/maxime/AFRILANG/build/../examples/complex_libs_demo.afr"
        #line 7 "/home/maxime/AFRILANG/build/../examples/complex_libs_demo.afr"
        #line 8 "/home/maxime/AFRILANG/build/../examples/complex_libs_demo.afr"
        #line 9 "/home/maxime/AFRILANG/build/../examples/complex_libs_demo.afr"
        #line 11 "/home/maxime/AFRILANG/build/../examples/complex_libs_demo.afr"
    double dist = nlplevenshtein::distance("kitten", "sitting");
    #line 12 "/home/maxime/AFRILANG/build/../examples/complex_libs_demo.afr"
    std::cout << format::formatNumber(dist, 0LL) << std::endl;
    #line 14 "/home/maxime/AFRILANG/build/../examples/complex_libs_demo.afr"
    double sim = nlplevenshtein::similarity("hello", "hallo");
    #line 15 "/home/maxime/AFRILANG/build/../examples/complex_libs_demo.afr"
    std::cout << format::formatNumber(sim, 3LL) << std::endl;
    #line 17 "/home/maxime/AFRILANG/build/../examples/complex_libs_demo.afr"
    std::vector<double> numsA = {1LL, 2LL, 3LL, 4LL, 5LL};
    #line 18 "/home/maxime/AFRILANG/build/../examples/complex_libs_demo.afr"
    std::vector<double> numsB = {2LL, 4LL, 6LL, 8LL, 10LL};
    #line 19 "/home/maxime/AFRILANG/build/../examples/complex_libs_demo.afr"
    double corr = statcorrel::pearson(numsA, numsB);
    #line 20 "/home/maxime/AFRILANG/build/../examples/complex_libs_demo.afr"
    std::cout << format::formatNumber(corr, 3LL) << std::endl;
    #line 22 "/home/maxime/AFRILANG/build/../examples/complex_libs_demo.afr"
    std::vector<double> vecA = {1LL, 0LL, 1LL};
    #line 23 "/home/maxime/AFRILANG/build/../examples/complex_libs_demo.afr"
    std::vector<double> vecB = {1LL, 1LL, 0LL};
    #line 24 "/home/maxime/AFRILANG/build/../examples/complex_libs_demo.afr"
    double cos = mlcosine::cosineSim(vecA, vecB);
    #line 25 "/home/maxime/AFRILANG/build/../examples/complex_libs_demo.afr"
    std::cout << format::formatNumber(cos, 3LL) << std::endl;
    return 0;
}
