#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

void generateRandomArray(int arr[], int size, int lowerBound, int upperBound) {
    // Ініціалізація генератора випадкових чисел
    srand(std::time(0));

    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % (upperBound - lowerBound + 1) + lowerBound;
    }
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void shellSort(int arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {

    SetConsoleOutputCP(1251);

    const int size = 30;
    int array[size];

    // Заповнення масиву випадковими числами
    generateRandomArray(array, size, 10, 100);

    cout << "Масив до сортування: ";
    printArray(array, size);

    // Сортування методом Шелла
    shellSort(array, size);

    cout << "Масив після сортування: ";
    printArray(array, size);

    return 0;
}