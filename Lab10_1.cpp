#include "pch.h"
#include <iostream>
#include <Windows.h>

using namespace std;

// Функція для знаходження першого входження масиву P у масив S
int findFirstOccurrence(int S[], int n, int P[], int m) {
    for (int i = 0; i <= n - m; ++i) {
        int j;
        for (j = 0; j < m; ++j) {
            if ( S[i + j]!= P[j]) {
                break;
            }
        }
        if (j == m) {
            return i;
        }
    }
    return -1;
}

int main() {

    SetConsoleOutputCP(1251);

    // Приклад використання
    int S[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int P[] = { 4, 5, 6 };

    int n = sizeof(S) / sizeof(S[0]);
    int m = sizeof(P) / sizeof(P[0]);

    int result = findFirstOccurrence(S, n, P, m);

    if (result != -1) {
        cout << "Перше входження P у S знаходиться на позиції " << result << endl;
    }
    else {
        cout << "P не знаходиться в S" << endl;
    }

    return 0;
}