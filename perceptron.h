#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <vector>

class Perceptron {
private:
    std::vector<double> weights;
    double learningRate;

public:
    Perceptron(int numFeatures, double learningRate);
    int classify(const std::vector<double>& input);
    void train(const std::vector<std::vector<double>>& trainingData, const std::vector<int>& labels, int numIterations);
};

#endif

