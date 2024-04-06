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
        qu
