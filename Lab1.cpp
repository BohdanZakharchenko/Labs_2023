
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <Windows.h>

using namespace std;

const int n = 11;
int firstTask[n];
int secondTask[7][4];

void arrayInput_1() {
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = ";
        cin >> firstTask[i];
    }
}

void arrayOutput_1() {
    cout << "Array elements:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = " << firstTask[i] << endl;
    }
}

int productOfElements_1() {
    int product = 1;
    for (int i = 0; i < n; i++) {
        if (firstTask[i] != 0) {
            product *= firstTask[i];
        }
        else break;
    }
    return product;
}

void arrayInput_2() {
    int inputVariant;
    cout << "Оберіть варінт заповнення масиву:" << endl
        << "1 - заповнення через клавіатуру" << endl
        << "2 - використати рандомні числа" << endl
        <<"Варіант відповіді: ";
    cin >> inputVariant;
    switch (inputVariant)
    {
    case 1:
        cout << "Введіть елементи масиву:" << endl;
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 4; j++) {
                cout << "arr[" << i << "][" << j << "] = ";
                cin >> secondTask[i][j];
            }
        }
        break;
    case 2:
        srand(time(0));
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 4; j++) {
                secondTask[i][j] = rand() % 10;
            }
        }
        break;
    default:
        break;
    }
    
}

void arrayOutput_2() {
    cout << "Задний масив:" << endl;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 4; j++) {
            cout<<"arr[" << i << "][" << j << "] = " << secondTask[i][j] << endl;

        }
    }
}

void quantityAndAmount_2() {
    int quantily = 0;
    int amount = 0;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 4; j++) {
            if (secondTask[i][j] > 1) {
                quantily++;
                amount += secondTask[i][j];
            }
        }
    }
    cout << "Кількість елементів більших за 1 - " << quantily << endl
        << "Сума елементів більших за 1 -" << amount << endl;
}

int main() {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

    // Отримуємо поточні атрибути
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(handle, &bufferInfo);

    // Отримуємо поточний колір фону
    WORD attributes = bufferInfo.wAttributes;

    // Змінюємо атрибути тексту
    WORD newAttributes = (attributes & 0xFFF0) | BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;
    SetConsoleTextAttribute(handle, newAttributes);

    // Отримуємо розміри консолі
    COORD consoleSize = bufferInfo.dwSize;
    DWORD consoleCells = consoleSize.X * consoleSize.Y;

    // Заповнюємо всю консоль білим фоном
    DWORD charsWritten;
    FillConsoleOutputCharacter(handle, ' ', consoleCells, { 0, 0 }, &charsWritten);
    FillConsoleOutputAttribute(handle, newAttributes, consoleCells, { 0, 0 }, &charsWritten);

    SetConsoleOutputCP(1251);

    int task;
    int product;
    cout << "Оберіть один з варіантів: " << endl
        <<"    1 - Завдання по одновимірним масивам №1;" << endl
        <<"    2 - Завдання по двовимірним масивам №2;" << endl
        <<"Обраний варіант: ";
    cin >> task;
    switch (task)
    {
    case 1:
        arrayInput_1();
        arrayOutput_1();
        product = productOfElements_1();
        cout << "Добуток елементів масиву до нульового елемента: " << product;
        break;
    case 2:
        arrayInput_2();
        arrayOutput_2();
        quantityAndAmount_2();
        break;
    default:
        break;
    }
    


    return 0;
}