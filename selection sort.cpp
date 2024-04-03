#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void fillVector(vector<int>& vetor, int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        vetor.push_back(rand() % size + 1); // Números de 1 a 100
    }
}

void selectionSort(vector<int>& vetor) {
    int tamanho = vetor.size();
    for (int i = 0; i < tamanho; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[i]) {
                int aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

int main() {
    vector<int> sizes = {10, 100, 1000, 10000, 100000, 1000000};

    for (int size : sizes) {
        vector<int> originalVector;
        fillVector(originalVector, size);

        vector<int> selectionSorted = originalVector;

        auto startSelection = high_resolution_clock::now();
        selectionSort(selectionSorted);
        auto endSelection = high_resolution_clock::now();
        duration<double> durationSelection = endSelection - startSelection;

        cout << "Tempo de execução (Selection Sort) para " << size << " elementos: " << fixed << durationSelection.count() << " segundos" << endl;
    }

    return 0;
}

