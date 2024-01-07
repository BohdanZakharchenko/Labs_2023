#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

// Функція для генерації випадкового числа в заданому діапазоні
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Функція для сортування бульбашкою
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Обмін елементів, якщо вони в неправильному порядку
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Функція для виводу масиву на екран
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Функція для інтерполяційного пошуку ключа
int interpolationSearch(int arr[], int low, int high, int key) {
    while (low <= high && key >= arr[low] && key <= arr[high]) {
        int position = low + ((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low]);

        if (arr[position] == key) {
            return position; // Знайдено ключ
        }

        if (arr[position] < key) {
            low = position + 1; // Пошук в правій частині
        }
        else {
            high = position - 1; // Пошук в лівій частині
        }
    }

    return -1; // Ключ не знайдено
}

int main() {

    SetConsoleOutputCP(1251);

    const int size = 25;
    int arr[size];

    srand(time(0));

    for (int i = 0; i < size; ++i) {
        arr[i] = getRandomNumber(10, 100);
    }

    cout << "Масив до сортування:" << endl;
    printArray(arr, size);

    // Сортування бульбашкою
    bubbleSort(arr, size);

    cout << "Масив після сортування бульбашкою:" << endl;
    printArray(arr, size);


    // Пошук ключа 
    int keyIndex = interpolationSearch(arr, 0, size / 2 - 1, size );

    if (keyIndex != -1) {
        cout << "Знайдено ключ " << arr[keyIndex] << " на позиції " << keyIndex << endl;
    }
    else {
        cout << "Ключ не знайдено" << endl;
    }

    return 0;
}
