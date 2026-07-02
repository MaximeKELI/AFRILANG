#pragma once

#include <memory>
#include <sstream>
#include <string>
#include <vector>

#ifdef AFRILANG_HAS_LIBTORCH
#include <torch/torch.h>
#include <torch/nn/functional.h>
#endif

namespace afrilang {
namespace runtime {
namespace torch {

class Tensor {
public:
    Tensor() = default;

#ifdef AFRILANG_HAS_LIBTORCH
    explicit Tensor(::torch::Tensor data) : data_(std::make_shared<::torch::Tensor>(std::move(data))) {}

    ::torch::Tensor& raw() { return *data_; }
    const ::torch::Tensor& raw() const { return *data_; }

    bool defined() const { return data_ && data_->defined(); }
#else
    bool defined() const { return false; }
#endif

private:
#ifdef AFRILANG_HAS_LIBTORCH
    std::shared_ptr<::torch::Tensor> data_;
#endif
};

#ifdef AFRILANG_HAS_LIBTORCH

inline ::torch::TensorOptions floatOpts() {
    return ::torch::TensorOptions().dtype(::torch::kFloat32);
}

inline ::torch::Device currentDevice(bool preferGpu) {
    if (preferGpu && ::torch::cuda::is_available()) {
        return ::torch::Device(::torch::kCUDA);
    }
    return ::torch::Device(::torch::kCPU);
}

inline void setSeed(double seed) {
    ::torch::manual_seed(static_cast<int64_t>(seed));
    if (::torch::cuda::is_available()) {
        ::torch::cuda::manual_seed(static_cast<int64_t>(seed));
    }
}

inline bool gpuIsReady() {
    return ::torch::cuda::is_available();
}

inline Tensor fromList(const std::vector<double>& values) {
    std::vector<float> data(values.begin(), values.end());
    return Tensor(::torch::tensor(data, floatOpts()));
}

inline Tensor zeros(double rows, double cols) {
    return Tensor(::torch::zeros(
        {static_cast<int64_t>(rows), static_cast<int64_t>(cols)}, floatOpts()));
}

inline Tensor ones(double rows, double cols) {
    return Tensor(::torch::ones(
        {static_cast<int64_t>(rows), static_cast<int64_t>(cols)}, floatOpts()));
}

inline Tensor randTensor(double rows, double cols) {
    return Tensor(::torch::rand(
        {static_cast<int64_t>(rows), static_cast<int64_t>(cols)}, floatOpts()));
}

inline std::vector<int64_t> dimsFromList(const std::vector<double>& dims) {
    std::vector<int64_t> out;
    out.reserve(dims.size());
    for (double d : dims) {
        out.push_back(static_cast<int64_t>(d));
    }
    return out;
}

inline Tensor zerosFromShape(const std::vector<double>& dims) {
    return Tensor(::torch::zeros(dimsFromList(dims), floatOpts()));
}

inline Tensor randomFromShape(const std::vector<double>& dims) {
    return Tensor(::torch::rand(dimsFromList(dims), floatOpts()));
}

inline Tensor add(const Tensor& a, const Tensor& b) {
    return Tensor(a.raw().add(b.raw()));
}

inline Tensor sub(const Tensor& a, const Tensor& b) {
    return Tensor(a.raw().sub(b.raw()));
}

inline Tensor mul(const Tensor& a, const Tensor& b) {
    return Tensor(a.raw().mul(b.raw()));
}

inline Tensor matmul(const Tensor& a, const Tensor& b) {
    return Tensor(a.raw().matmul(b.raw()));
}

inline Tensor relu(const Tensor& t) {
    return Tensor(::torch::relu(t.raw()));
}

inline double sum(const Tensor& t) {
    return t.raw().sum().item<double>();
}

inline Tensor totalOf(const Tensor& t) {
    return Tensor(t.raw().sum());
}

inline double item(const Tensor& t) {
    return t.raw().item<double>();
}

inline double itemAt(const Tensor& t, double index) {
    return t.raw().index({static_cast<int64_t>(index)}).item<double>();
}

inline std::vector<double> shape(const Tensor& t) {
    std::vector<double> dims;
    for (int64_t d : t.raw().sizes()) {
        dims.push_back(static_cast<double>(d));
    }
    return dims;
}

inline std::string toString(const Tensor& t) {
    std::ostringstream out;
    out << t.raw();
    return out.str();
}

inline void freeTensor(const Tensor&) {}

inline bool save(const Tensor& t, const std::string& path) {
    try {
        ::torch::save(t.raw(), path);
        return true;
    } catch (...) {
        return false;
    }
}

inline Tensor load(const std::string& path) {
    ::torch::Tensor data;
    ::torch::load(data, path);
    return Tensor(std::move(data));
}

inline Tensor moveToGpu(const Tensor& t) {
    if (!::torch::cuda::is_available()) return t;
    return Tensor(t.raw().to(::torch::kCUDA));
}

inline Tensor moveToCpu(const Tensor& t) {
    return Tensor(t.raw().to(::torch::kCPU));
}

inline bool isOnGpu(const Tensor& t) {
    return t.raw().device().is_cuda();
}

inline Tensor enableGrad(Tensor t) {
    t.raw().set_requires_grad(true);
    return t;
}

inline bool gradIsEnabled(const Tensor& t) {
    return t.raw().requires_grad();
}

inline void computeGrad(const Tensor& t) {
    if (t.raw().grad().defined()) {
        t.raw().grad().zero_();
    }
    t.raw().backward();
}

inline Tensor gradOf(const Tensor& t) {
    if (!t.raw().grad().defined()) {
        return Tensor(::torch::zeros({1}, floatOpts()));
    }
    return Tensor(t.raw().grad().clone());
}

inline Tensor linear(const Tensor& input, const Tensor& weight, const Tensor& bias) {
    return Tensor(::torch::nn::functional::linear(input.raw(), weight.raw(), bias.raw()));
}

inline Tensor conv2d(const Tensor& input, const Tensor& weight, const Tensor& bias,
                     double stride) {
    return Tensor(::torch::nn::functional::conv2d(
        input.raw(),
        weight.raw(),
        ::torch::nn::functional::Conv2dFuncOptions()
            .stride(static_cast<int64_t>(stride))
            .bias(bias.raw())));
}

inline Tensor flatten(const Tensor& t) {
    return Tensor(t.raw().flatten());
}

#else

inline void setSeed(double) {}
inline bool gpuIsReady() { return false; }
inline Tensor fromList(const std::vector<double>&) { return {}; }
inline Tensor zeros(double, double) { return {}; }
inline Tensor ones(double, double) { return {}; }
inline Tensor randTensor(double, double) { return {}; }
inline Tensor zerosFromShape(const std::vector<double>&) { return {}; }
inline Tensor randomFromShape(const std::vector<double>&) { return {}; }
inline Tensor add(const Tensor&, const Tensor&) { return {}; }
inline Tensor sub(const Tensor&, const Tensor&) { return {}; }
inline Tensor mul(const Tensor&, const Tensor&) { return {}; }
inline Tensor matmul(const Tensor&, const Tensor&) { return {}; }
inline Tensor relu(const Tensor&) { return {}; }
inline double sum(const Tensor&) { return 0; }
inline Tensor totalOf(const Tensor& t) { return t; }
inline double item(const Tensor&) { return 0; }
inline double itemAt(const Tensor&, double) { return 0; }
inline std::vector<double> shape(const Tensor&) { return {0.0, 0.0}; }
inline std::string toString(const Tensor&) {
    return "[torch unavailable: set AFRILANG_TORCH_HOME and install libtorch]";
}
inline void freeTensor(const Tensor&) {}
inline bool save(const Tensor&, const std::string&) { return false; }
inline Tensor load(const std::string&) { return {}; }
inline Tensor moveToGpu(const Tensor& t) { return t; }
inline Tensor moveToCpu(const Tensor& t) { return t; }
inline bool isOnGpu(const Tensor&) { return false; }
inline Tensor enableGrad(Tensor t) { return t; }
inline bool gradIsEnabled(const Tensor&) { return false; }
inline void computeGrad(const Tensor&) {}
inline Tensor gradOf(const Tensor&) { return {}; }
inline Tensor linear(const Tensor&, const Tensor&, const Tensor&) { return {}; }
inline Tensor conv2d(const Tensor&, const Tensor&, const Tensor&, double) { return {}; }
inline Tensor flatten(const Tensor& t) { return t; }

#endif

} // namespace torch
} // namespace runtime
} // namespace afrilang
