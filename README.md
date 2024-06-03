# Online estimation of mean and covariance

Quick piece of code to estimate on-the-fly the mean and covariance according to [Welford's Online algorithm](https://en.wikipedia.org/wiki/Algorithms_for_calculating_variance#Welford's_Online_algorithm).

To build and run the quick test executable:
```
g++ MeanCovEstimator.cpp main.cpp -Wall -o main
./main
```
