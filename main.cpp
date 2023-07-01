#include <iostream>
#include <fstream>
#include <vector>
#include "perceptron.h"

void loadTrainingData(const std::string& filename, std::vector<std::vector<double>>& trainingData, std::vector<int>& labels) {
    std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        double value;
        int numFeatures; // Dichiarazione della variabile numFeatures

        // Leggi il numero di caratteristiche dal file
        inputFile >> numFeatures;

        while (inputFile >> value) {
            std::vector<double> input;
            input.push_back(value); // Aggiungi il valore corrente al vettore di input

            // Ripeti per le altre caratteristiche
            for (int i = 1; i < numFeatures; i++) {
                inputFile >> value;
                input.push_back(value);
            }

            int label;
            inputFile >> label; // Leggi l'etichetta
            labels.push_back(label);
            trainingData.push_back(input);
        }
        inputFile.close();
    } else {
        std::cout << "Errore durante l'apertura del file." << std::endl;
    }
}

int main() {
    // Parametri di configurazione
    int numFeatures = 3; // Numero di caratteristiche (dimensione dei vettori di input)
    double learningRate = 0.1;
    int numIterations = 100;

    // Caricamento dei dati di addestramento
    std::vector<std::vector<double>> trainingData;
    std::vector<int> labels;
    loadTrainingData("training_data.txt", trainingData, labels);

    // Creazione e addestramento del perceptron
    Perceptron perceptron(numFeatures, learningRate);
    perceptron.train(trainingData, labels, numIterations);

    // Esempio di classificazione
    std::vector<double> input = {1.0, 2.0, 3.0}; // Esempio di vettore di input da classificare
    int prediction = perceptron.classify(input);
    std::cout << "Classificazione: " << prediction << std::endl;

    return 0;
}
