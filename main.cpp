#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Função para preencher o vetor com valores aleatórios
void fillVector(vector<int>& vetor, int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        vetor.push_back(rand() % 100 + 1); // Números de 1 a 100
    }
}

// Algoritmo Bubble Sort
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

// Algoritmo Selection Sort
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

// Algoritmo Insertion Sort
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

// Algoritmo Shell Sort
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

// Algoritmo Quick Sort
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

// Algoritmo Merge Sort
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
    // Quantidades de elementos do vetor
    int size = 10;

    vector<int> originalVector;
    fillVector(originalVector, size);

    // Criar cópias do vetor original
    vector<int> bubbleSorted = originalVector;
    vector<int> selectionSorted = originalVector;
    vector<int> insertionSorted = originalVector;
    vector<int> shellSorted = originalVector;
    vector<int> quickSorted = originalVector;
    vector<int> mergeSorted = originalVector;

    // Medir o tempo para Bubble Sort
    auto startBubble = high_resolution_clock::now();
    bubbleSort(bubbleSorted);
    auto endBubble = high_resolution_clock::now();
    duration<double> durationBubble = endBubble - startBubble;

    // Medir o tempo para Selection Sort
    auto startSelection = high_resolution_clock::now();
    selectionSort(selectionSorted);
    auto endSelection = high_resolution_clock::now();
    duration<double> durationSelection = endSelection - startSelection;

    // Medir o tempo para Insertion Sort
    auto startInsertion = high_resolution_clock::now();
    insertionSort(insertionSorted);
    auto endInsertion = high_resolution_clock::now();
    duration<double> durationInsertion = endInsertion - startInsertion;

    // Medir o tempo para Shell Sort
    auto startShell = high_resolution_clock::now();
    shellSort(shellSorted);
    auto endShell = high_resolution_clock::now();
    duration<double> durationShell = endShell - startShell;

    // Medir o tempo para Quick Sort
    auto startQuick = high_resolution_clock::now();
    quickSort(quickSorted, 0, size - 1);
    auto endQuick = high_resolution_clock::now();
    duration<double> durationQuick = endQuick - startQuick;

    // Medir o tempo para Merge Sort
    auto startMerge = high_resolution_clock::now();
    mergeSort(mergeSorted, 0, size - 1);
    auto endMerge = high_resolution_clock::now();
    duration<double> durationMerge = endMerge - startMerge;

    // Imprimir os tempos de execução
    cout << "Tempo de execução (Bubble Sort): " << fixed << durationBubble.count() << " segundos" << endl;
    cout << "Tempo de execução (Selection Sort): " << fixed << durationSelection.count() << " segundos" << endl;
    cout << "Tempo de execução (Insertion Sort): " << fixed << durationInsertion.count() << " segundos" << endl;
    cout << "Tempo de execução (Shell Sort): " << fixed << durationShell.count() << " segundos" << endl;
    cout << "Tempo de execução (Quick Sort): " << fixed << durationQuick.count() << " segundos" << endl;
    cout << "Tempo de execução (Merge Sort): " << fixed << durationMerge.count() << " segundos" << endl;

    return 0;
}
