#pragma once

#include <memory>
#include <sstream>
#include <string>
#include <vector>

#ifdef AFRILANG_HAS_LIBTORCH
#include <torch/torch.h>
#include <torch/nn/functional.h>
#include <torch/optim.h>
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

class Optimizer {
public:
    Optimizer() = default;

#ifdef AFRILANG_HAS_LIBTORCH
    explicit Optimizer(std::shared_ptr<::torch::optim::Optimizer> impl)
        : impl_(std::move(impl)) {}

    ::torch::optim::Optimizer& raw() { return *impl_; }
    const ::torch::optim::Optimizer& raw() const { return *impl_; }

    bool defined() const { return static_cast<bool>(impl_); }
#else
    bool defined() const { return false; }
#endif

private:
#ifdef AFRILANG_HAS_LIBTORCH
    std::shared_ptr<::torch::optim::Optimizer> impl_;
#endif
};

#ifdef AFRILANG_HAS_LIBTORCH

inline ::torch::TensorOptions floatOpts() {
    return ::torch::TensorOptions().dtype(::torch::kFloat32);
}

inline ::torch::TensorOptions longOpts() {
    return ::torch::TensorOptions().dtype(::torch::kLong);
}

inline bool& trainingModeFlag() {
    static thread_local bool flag = true;
    return flag;
}

inline std::vector<::torch::Tensor> toRawParams(const std::vector<Tensor>& params) {
    std::vector<::torch::Tensor> raw;
    raw.reserve(params.size());
    for (const auto& p : params) {
        raw.push_back(p.raw());
    }
    return raw;
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

inline bool gradModeIsOn() {
    return ::torch::GradMode::is_enabled();
}

inline void setGradMode(bool enabled) {
    ::torch::GradMode::set_enabled(enabled);
}

inline void noGradMode() {
    setGradMode(false);
}

inline void enableGradMode() {
    setGradMode(true);
}

inline void trainMode() {
    trainingModeFlag() = true;
}

inline void evalMode() {
    trainingModeFlag() = false;
}

inline bool isTrainingMode() {
    return trainingModeFlag();
}

inline Tensor fromList(const std::vector<double>& values) {
    std::vector<float> data(values.begin(), values.end());
    return Tensor(::torch::tensor(data, floatOpts()));
}

inline Tensor fromIntList(const std::vector<double>& values) {
    std::vector<int64_t> data;
    data.reserve(values.size());
    for (double v : values) {
        data.push_back(static_cast<int64_t>(v));
    }
    return Tensor(::torch::tensor(data, longOpts()));
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

inline Tensor sigmoid(const Tensor& t) {
    return Tensor(::torch::sigmoid(t.raw()));
}

inline Tensor tanhOf(const Tensor& t) {
    return Tensor(::torch::tanh(t.raw()));
}

inline Tensor softmax(const Tensor& t, double dim) {
    return Tensor(::torch::softmax(t.raw(), static_cast<int64_t>(dim)));
}

inline Tensor logSoftmax(const Tensor& t, double dim) {
    return Tensor(::torch::log_softmax(t.raw(), static_cast<int64_t>(dim)));
}

inline Tensor dropout(const Tensor& t, double p) {
    return Tensor(::torch::dropout(t.raw(), p, trainingModeFlag()));
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

inline void zeroTensorGrad(const Tensor& t) {
    if (t.raw().grad().defined()) {
        t.raw().grad().zero_();
    }
}

inline void computeGrad(const Tensor& t) {
    if (t.raw().grad().defined()) {
        t.raw().grad().zero_();
    }
    t.raw().backward();
}

inline void backward(const Tensor& t) {
    computeGrad(t);
}

inline Tensor gradOf(const Tensor& t) {
    if (!t.raw().grad().defined()) {
        return Tensor(::torch::zeros({1}, floatOpts()));
    }
    return Tensor(t.raw().grad().clone());
}

inline Tensor detach(const Tensor& t) {
    return Tensor(t.raw().detach());
}

inline Tensor cloneTensor(const Tensor& t) {
    return Tensor(t.raw().clone());
}

inline Tensor mseLoss(const Tensor& pred, const Tensor& target) {
    return Tensor(::torch::mse_loss(pred.raw(), target.raw()));
}

inline Tensor crossEntropyLoss(const Tensor& logits, const Tensor& targets) {
    return Tensor(::torch::cross_entropy_loss(logits.raw(), targets.raw()));
}

inline Tensor binaryCrossEntropy(const Tensor& pred, const Tensor& target) {
    return Tensor(::torch::binary_cross_entropy(pred.raw(), target.raw()));
}

inline Tensor nllLoss(const Tensor& logProbs, const Tensor& targets) {
    return Tensor(::torch::nll_loss(logProbs.raw(), targets.raw()));
}

inline Optimizer sgd(const std::vector<Tensor>& params, double lr) {
    return Optimizer(std::make_shared<::torch::optim::SGD>(
        toRawParams(params), ::torch::optim::SGDOptions(lr)));
}

inline Optimizer adam(const std::vector<Tensor>& params, double lr) {
    return Optimizer(std::make_shared<::torch::optim::Adam>(
        toRawParams(params), ::torch::optim::AdamOptions(lr)));
}

inline void zeroOptimizer(Optimizer& opt) {
    opt.raw().zero_grad();
}

inline void optimizerStep(Optimizer& opt) {
    opt.raw().step();
}

inline void trainStep(Optimizer& opt, const Tensor& loss) {
    opt.raw().zero_grad();
    loss.raw().backward();
    opt.raw().step();
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
inline bool gradModeIsOn() { return false; }
inline void setGradMode(bool) {}
inline void noGradMode() {}
inline void enableGradMode() {}
inline void trainMode() {}
inline void evalMode() {}
inline bool isTrainingMode() { return true; }
inline Tensor fromList(const std::vector<double>&) { return {}; }
inline Tensor fromIntList(const std::vector<double>&) { return {}; }
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
inline Tensor sigmoid(const Tensor&) { return {}; }
inline Tensor tanhOf(const Tensor&) { return {}; }
inline Tensor softmax(const Tensor&, double) { return {}; }
inline Tensor logSoftmax(const Tensor&, double) { return {}; }
inline Tensor dropout(const Tensor&, double) { return {}; }
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
inline void zeroTensorGrad(const Tensor&) {}
inline void computeGrad(const Tensor&) {}
inline void backward(const Tensor&) {}
inline Tensor gradOf(const Tensor&) { return {}; }
inline Tensor detach(const Tensor&) { return {}; }
inline Tensor cloneTensor(const Tensor& t) { return t; }
inline Tensor mseLoss(const Tensor&, const Tensor&) { return {}; }
inline Tensor crossEntropyLoss(const Tensor&, const Tensor&) { return {}; }
inline Tensor binaryCrossEntropy(const Tensor&, const Tensor&) { return {}; }
inline Tensor nllLoss(const Tensor&, const Tensor&) { return {}; }
inline Optimizer sgd(const std::vector<Tensor>&, double) { return {}; }
inline Optimizer adam(const std::vector<Tensor>&, double) { return {}; }
inline void zeroOptimizer(Optimizer&) {}
inline void optimizerStep(Optimizer&) {}
inline void trainStep(Optimizer&, const Tensor&) {}
inline Tensor linear(const Tensor&, const Tensor&, const Tensor&) { return {}; }
inline Tensor conv2d(const Tensor&, const Tensor&, const Tensor&, double) { return {}; }
inline Tensor flatten(const Tensor& t) { return t; }

#endif

} // namespace torch
} // namespace runtime
} // namespace afrilang
