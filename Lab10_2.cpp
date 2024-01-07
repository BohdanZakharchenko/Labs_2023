#include "pch.h"
#include <iostream>
#include <Windows.h>

using namespace std;

// Генерація префікс-функції для слова P
void computePrefixFunction(const char P[], int m, int pi[]) {
    int k = 0;
    pi[0] = 0;

    for (int q = 1; q < m; ++q) {
        while (k > 0 && P[k] != P[q]) {
            k = pi[k - 1];
        }

        if (P[k] == P[q]) {
            ++k;
        }

        pi[q] = k;
    }
}

// Функція для знаходження першого входження слова P у текст S
int findKMP(const char S[], int n, const char P[], int m) {
    int* pi = new int[m];
    computePrefixFunction(P, m, pi);

    int q = 0;

    for (int i = 0; i < n; ++i) {
        while (q > 0 && P[q] != S[i]) {
            q = pi[q - 1];
        }

        if (P[q] == S[i]) {
            ++q;
        }

        if (q == m) {
            delete[] pi;
            return i - m + 1; // Знайдено входження
        }
    }

    delete[] pi;
    return -1; // Не знайдено входження
}

int main() {

    SetConsoleOutputCP(1251);
    
    const char S[] = "BABCABABABCABABC";
    const char P[] = "ABABC";

    int n = sizeof(S) - 1;
    int m = sizeof(P) - 1;

    int result = findKMP(S, n, P, m);

    if (result != -1) {
        cout << "Перше входження P у S знаходиться на позиції " << result << endl;
    }
    else {
        cout << "P не знаходиться в S" << endl;
    }

    return 0;
}