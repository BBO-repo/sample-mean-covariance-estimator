#include <cmath>
#include <cassert>
#include <iostream>
#include "MeanCovEstimator.h"

void Test() {
	constexpr int32_t NSAMPLES{100};
	const float TOLERANCE{1e-7};

	OnlineMean oMean;
	int32_t array[NSAMPLES];

	float sum = 0, var = 0;
	for (int32_t i = 0; i < NSAMPLES; i++) {
		array[i] = i;
		sum += array[i];
		oMean.Update(array[i]);
	}

	float expected_mean = sum / NSAMPLES;
	for (int32_t i = 0; i < NSAMPLES; i++) {
		float delta = array[i] - expected_mean;
		var += delta * delta;
	}
	float expected_std = oMean.unbiased_estimation_ ?
				std::sqrt(var / (NSAMPLES - 1)):
				std::sqrt(var / NSAMPLES);
	
	// check online estimation versus sample estimation
	float std_online = oMean.GetStd();
	assert(std::fabs(expected_mean - oMean.mean_) < TOLERANCE);
	assert(std::fabs(expected_std - std_online) < TOLERANCE);
	std::cout << "estimated mean is: " << oMean.mean_ << std::endl;
	std::cout << "estimated std is: " << std_online << std::endl;
}

int main() {
    Test();
    std::cout << "On-the-fly estimation of mean and standard deviation are correct." << std::endl;
    return 0;
}
