#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void fillVector(vector<int>& vetor, int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        vetor.push_back(rand() % 100 + 1); // Números de 1 a 100
    }
}

void insertionSort(vector<int>& vetor) {
    int n = vetor.size();
    for (int i = 1; i < n; i++) {
        int key = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > key) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = key;
    }
}

int main() {
    vector<int> sizes = {10, 100, 1000, 10000, 100000, 1000000};

    for (int size : sizes) {
        vector<int> originalVector;
        fillVector(originalVector, size);

        vector<int> insertionSorted = originalVector;

        auto startInsertion = high_resolution_clock::now();
        insertionSort(insertionSorted);
        auto endInsertion = high_resolution_clock::now();
        duration<double> durationInsertion = endInsertion - startInsertion;

        cout << "Tempo de execução (Insertion Sort) para " << size << " elementos: " << fixed << durationInsertion.count() << " segundos" << endl;
    }

    return 0;
}
