#include "perceptron.h"

// Implementazione dei metodi della classe Perceptron

Perceptron::Perceptron(int numFeatures, double learningRate) {
    // Inizializzazione dei pesi a valori casuali o zero
    // Il numero di pesi è uguale al numero di caratteristiche (dimensione dei vettori di input)
    weights.resize(numFeatures, 0.0);
    this->learningRate = learningRate;
}

int Perceptron::classify(const std::vector<double>& input) {
    // Calcolo dell'output del perceptron (1 o -1) basato sui pesi e l'input
    double sum = 0.0;
    for (int i = 0; i < input.size(); i++) {
        sum += input[i] * weights[i];
    }

    if (sum >= 0) {
        return 1;
    } else {
        return -1;
    }
}

void Perceptron::train(const std::vector<std::vector<double>>& trainingData, const std::vector<int>& labels, int numIterations) {
    for (int iter = 0; iter < numIterations; iter++) {
        for (int i = 0; i < trainingData.size(); i++) {
            std::vector<double> input = trainingData[i];
            int label = labels[i];
            int prediction = classify(input);
            int error = label - prediction;

            // Aggiornamento dei pesi basato sull'errore e il tasso di apprendimento
            for (int j = 0; j < weights.size(); j++) {
                weights[j] += learningRate * error * input[j];
            }
        }
    }
}

