#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Створюємо тимчасові масиви
    int* left_half = new int[n1];
    int* right_half = new int[n2];

    // Копіюємо дані в тимчасові масиви left_half[] та right_half[]
    for (int i = 0; i < n1; i++)
        left_half[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        right_half[j] = arr[mid + 1 + j];

    // Об'єднуємо тимчасові масиви назад у основний масив arr[]
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (left_half[i] <= right_half[j]) {
            arr[k] = left_half[i];
            i++;
        }
        else {
            arr[k] = right_half[j];
            j++;
        }
        k++;
    }

    // Копіюємо залишок елементів left_half[], якщо вони залишились
    while (i < n1) {
        arr[k] = left_half[i];
        i++;
        k++;
    }

    // Копіюємо залишок елементів right_half[], якщо вони залишились
    while (j < n2) {
        arr[k] = right_half[j];
        j++;
        k++;
    }

    // Звільняємо пам'ять, виділену для тимчасових масивів
    delete[] left_half;
    delete[] right_half;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Знаходимо середину масиву
        int mid = left + (right - left) / 2;

        // Рекурсивно сортуємо ліву та праву половини
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Об'єднуємо відсортовані половини
        merge(arr, left, mid, right);
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

    
    mergeSort(arr, 0, arraySize - 1);

    cout << "Відсортований масив: ";
    for (int i = 0; i < arraySize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}