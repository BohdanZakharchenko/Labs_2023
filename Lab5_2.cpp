#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    float C;
    cout << "Введіть значення C: ";
    cin >> C;

    // Створюємо чергу для зберігання дійсних чисел
    queue<float> q;

    // Відкриваємо файл для читання
    ifstream inputFile("File.txt");

    // Перевірка на успішне відкриття файлу
    if (!inputFile) {
        cerr << "Не вдалося відкрити файл" << endl;
        return 1;
    }

    float realNumber;

    // Читаємо файл і додаємо елементи до черги відповідно до значення C
    while (inputFile >> realNumber) {
        if (realNumber < C) {
            q.push(realNumber);
        }
    }

    // Повертаємось на початок файлу для другого проходу
    inputFile.clear();
    inputFile.seekg(0);

    // Читаємо файл знову і додаємо елементи до черги відповідно до значення C
    while (inputFile >> realNumber) {
        if (realNumber >= C) {
            q.push(realNumber);
        }
    }

    inputFile.close(); // Закриваємо файл після закінчення читання

    // Виводимо елементи черги та порівнюємо їх із значенням C
    while (!q.empty()) {
        if (q.front() < C) {
            cout << q.front() << " < C" << endl;
        }
        else if (q.front() > C) {
            cout << q.front() << " > C" << endl;
        }
        else {
            cout << q.front() << " = C" << endl;
        }
        q.pop();
    }

    return 0;
}