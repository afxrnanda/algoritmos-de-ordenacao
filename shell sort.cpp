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

void shellSort(vector<int>& vetor) {
    int n = vetor.size();

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = vetor[i];

            int j;
            for (j = i; j >= gap && vetor[j - gap] > temp; j -= gap) {
                vetor[j] = vetor[j - gap];
            }

            vetor[j] = temp;
        }
    }
}

int main() {
    vector<int> sizes = {10, 100, 1000, 10000, 100000, 1000000};

    for (int size : sizes) {
        vector<int> originalVector;
        fillVector(originalVector, size);

        vector<int> shellSorted = originalVector;

        auto startShell = high_resolution_clock::now();
        shellSort(shellSorted);
        auto endShell = high_resolution_clock::now();
        duration<double> durationShell = endShell - startShell;

        cout << "Tempo de execução (Shell Sort) para " << size << " elementos: " << fixed << durationShell.count() << " segundos" << endl;
    }

    return 0;
}
