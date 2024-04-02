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

void bubbleSort(vector<int>& vetor) {
    int n = vetor.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                swap(vetor[j], vetor[j + 1]);
            }
        }
    }
}

int main() {
    vector<int> sizes = {10, 100, 1000, 10000, 100000, 1000000};

    for (int size : sizes) {
        vector<int> originalVector;
        fillVector(originalVector, size);

        vector<int> bubbleSorted = originalVector;

        auto startBubble = high_resolution_clock::now();
        bubbleSort(bubbleSorted);
        auto endBubble = high_resolution_clock::now();
        duration<double> durationBubble = endBubble - startBubble;

        cout << "Tempo de execução (Bubble Sort) para " << size << " elementos: " << fixed << durationBubble.count() << " segundos" << endl;
    }

    return 0;
}
