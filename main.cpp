#include <iostream>
#include <fstream>
#include <vector>
#include "perceptron.h"

void loadTrainingData(const std::string& filename, std::vector<std::vector<double>>& trainingData, std::vector<int>& labels) {
    std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        double value;
        while (inputFile >> value) {
            std::vector<double> input;
            input.push_back(value);

            int label;
            inputFile >> label;
            labels.push_back(label);
            trainingData.push_back(input);
        }
        inputFile.close();
    } else {
        std::cout << "Errore durante l'apertura del file." << std::endl;
    }
}

int main() {
    int numFeatures = 3;
    int numIterations = 100;

    std::vector<std::vector<double>> trainingData;
    std::vector<int> labels;
    loadTrainingData("training_data.txt", trainingData, labels);

    double learningRate = 0.1;  // Dichiarazione della variabile learningRate

    Perceptron perceptron(numFeatures, learningRate);
    perceptron.train(trainingData, labels, numIterations);

    std::vector<double> input = {1.0, 2.0, 3.0};
    int prediction = perceptron.classify(input);
    std::cout << "Classificazione: " << prediction << std::endl;

    return 0;
}
