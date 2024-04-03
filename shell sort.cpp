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

        vector<int> mergeSorted = originalVector;

        auto startMerge = high_resolution_clock::now();
        mergeSort(mergeSorted, 0, size - 1);
        auto endMerge = high_resolution_clock::now();
        duration<double> durationMerge = endMerge - startMerge;

        cout << "Tempo de execução (Merge Sort) para " << size << " elementos: " << fixed << durationMerge.count() << " segundos" << endl;
    }

    return 0;
}

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
