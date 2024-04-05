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

void merge(vector<int>& vetor, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = vetor[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = vetor[m + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vetor[k] = L[i];
            i++;
        } else {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vetor[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        vetor[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& vetor, int l, int r) {
    if (l >= r) {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(vetor, l, m);
    mergeSort(vetor, m + 1, r);
    merge(vetor, l, m, r);
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
