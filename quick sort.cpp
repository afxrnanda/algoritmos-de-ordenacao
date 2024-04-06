#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void fillVector(vector<int>& vetor, int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        vetor.push_back(rand() % size + 1);
    }
}

int partition(vector<int>& vetor, int low, int high) {
    int pivot = vetor[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (vetor[j] < pivot) {
            i++;
            swap(vetor[i], vetor[j]);
        }
    }
    swap(vetor[i + 1], vetor[high]);
    return i + 1;
}

void quickSort(vector<int>& vetor, int low, int high) {
    if (low < high) {
        int pi = partition(vetor, low, high);
        quickSort(vetor, low, pi - 1);
        quickSort(vetor, pi + 1, high);
    }
}

int main() {
    vector<int> sizes = {10, 100, 1000, 10000, 30000, 50000, 70000, 100000, 300000, 500000, 700000, 1000000};

    for (int size : sizes) {
        vector<int> originalVector;
        fillVector(originalVector, size);

        vector<int> quickSorted = originalVector;

        auto startQuick = high_resolution_clock::now();
        quickSort(quickSorted, 0, size - 1);
        auto endQuick = high_resolution_clock::now();
        duration<double> durationQuick = endQuick - startQuick;

        cout << "Tempo de execucao (Quick Sort) para " << size << " elementos: " << fixed << durationQuick.count() << " segundos" << endl;
    }

    return 0;
}
