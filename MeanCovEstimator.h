#ifndef SAMPLE_MEAN_COVARIANCE_ESTIMATOR_
#define SAMPLE_MEAN_COVARIANCE_ESTIMATOR_

#include <cstdint>

struct OnlineMean {
	float mean_;
	float varsum_;  // variance sum
	uint32_t count_;
	bool unbiased_estimation_; // set to true to return unbiased (sample) variance estimation

	OnlineMean(float mean, float varsum, uint32_t count, bool unbiased_estimation);
	OnlineMean();
	void Update(float newValue);
	float GetStd();
	~OnlineMean();
};

#endif /* SAMPLE_MEAN_COVARIANCE_ESTIMATOR_ */
