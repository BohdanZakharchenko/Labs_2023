#include "pch.h"
#include "pch.h"
#include <Windows.h> 
#include <iostream>

using namespace std;

unsigned long long sequenceTerm(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return sequenceTerm(n - 1) * n;
    }
}

double sequenceSum(int n) {
    if (n == 0) {
        return 1.0;
    }
    else {
        return 1.0 / sequenceTerm(n) + sequenceSum(n - 1);
    }
}

int main() {
    SetConsoleOutputCP(1251);
    int n;
    cout << "Введіть n: ";
    cin >> n;

    double sum = sequenceSum(n);
    unsigned long long nElement = sequenceTerm(n);
    cout << "Сума перших " << n << " членів послідовності: " << sum << std::endl;
    cout << "Значення n-го члена послідовності " << 1.0 / nElement;
    return 0;
}