#include <cmath>
#include "MeanCovEstimator.h"

OnlineMean::OnlineMean(float mean, float varsum, uint32_t count, bool unbiased_estimation) :
mean_(mean), varsum_(varsum), count_(count), unbiased_estimation_(unbiased_estimation)
{}

OnlineMean::OnlineMean() : OnlineMean(0, 0.f, 0.f, true)
{}

void OnlineMean::Update(float newValue) {
	count_++;
	if (count_ > 1) {
		float delta = newValue - mean_;
		mean_ += delta / count_;
		varsum_ += delta * (newValue - mean_);
	} else {
		mean_ = newValue;
	}
}

float OnlineMean::GetStd() {
	return unbiased_estimation_ ?
			std::sqrt(varsum_ / (count_ - 1)):
			std::sqrt(varsum_ / count_);
}

OnlineMean::~OnlineMean()
{}