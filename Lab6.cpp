#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

void fillArray(int arr[], int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 91 + 10;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

int main() {
    SetConsoleOutputCP(1251);
    const int size = 30;
    int arr[size];

    fillArray(arr, size);

    cout << "Масив до сортування: ";
    printArray(arr, size);

    // Сортування методом бульбашки
    bubbleSort(arr, size);
    cout << "Масив після сортування (бульбашкою): ";
    printArray(arr, size);

    // Знову заповнюємо масив випадковими числами
    fillArray(arr, size);

    // Сортування методом вставки
    insertionSort(arr, size);
    cout << "Масив після сортування (вставкою): ";
    printArray(arr, size);

    return 0;
}
