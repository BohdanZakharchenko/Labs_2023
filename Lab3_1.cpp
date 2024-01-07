#include "pch.h"
#include <iostream> // Включення заголовкового файлу для стандартного введення/виведення
#include <cmath> // Включення заголовкового файлу для математичних функцій
#include <Windows.h> // Включення заголовкового файлу для роботи з функціями Windows


using namespace std;
// Рекурсивна функція для обчислення добутку
int calculateProduct(int n) {
    // Якщо n менше або рівне 1, повертається 2
    if (n <= 1) {
         return 2;
    }

    // Рекурсивно обчислюємо добуток для n-1 і множимо на 2n
    return 2 * n * calculateProduct(n - 1);
}

int main() {

    SetConsoleOutputCP(1251);
    int n;
    cout << "Введіть значення n: ";
    cin >> n;

   
        int result = calculateProduct(n);
        cout << "Добуток P для n=" << n << " дорівнює " << result << std::endl;
    

    return 0;
}
