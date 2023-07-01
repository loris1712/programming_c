#include "perceptron.h"

// Implementazione dei metodi della classe Perceptron

Perceptron::Perceptron(int numFeatures, double learningRate) {
    // Inizializzazione dei pesi a valori casuali o zero
    // Il numero di pesi è uguale al numero di caratteristiche (dimensione dei vettori di input)
    weights.resize(numFeatures, 0.0);
    this->learningRate = learningRate;
}

int Perceptron::classify(const std::vector<double>& input) {
    double sum = 0.0;
    for (int i = 0; i < input.size(); i++) {
        sum += input[i] * weights[i];
    }

    return (sum >= 0) ? 1 : -1;
}

void Perceptron::train(const std::vector<std::vector<double>>& trainingData, const std::vector<int>& labels, int numIterations) {
    for (int iter = 0; iter < numIterations; iter++) {
        for (int i = 0; i < trainingData.size(); i++) {
            std::vector<double> input = trainingData[i];
            int label = labels[i];
            int prediction = classify(input);
            int error = label - prediction;

            for (int j = 0; j < weights.size(); j++) {
                weights[j] += learningRate * error * input[j];
            }
        }
    }
}

// Implementazione dei getter

const std::vector<double>& Perceptron::getWeights() const {
    return weights;
}

double Perceptron::getLearningRate() const {
    return learningRate;
}

