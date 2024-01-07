#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] <= pivot) {
                i++;

                // Обмін елементів 
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;

        // Рекурсивно сортуємо підмасиви
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {

    SetConsoleOutputCP(1251);

    const int arraySize = 30;
    int arr[arraySize];

    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < arraySize; i++) {
        arr[i] = rand() % 91 + 10;
    }

    std::cout << "Початковий масив: ";
    for (int i = 0; i < arraySize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, arraySize - 1);

    cout << "Відсортований масив: ";
    for (int i = 0; i < arraySize; i++) {
        std::cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}