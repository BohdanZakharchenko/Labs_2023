#include "pch.h"
#include <iostream>
#include <Windows.h>
using namespace std;



struct Node {
    int data;
    Node* next;
};

// Функція для додавання нового елементу до списку
void push(Node*& head, int newData) {
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
}

// Функція для виведення списку на екран
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void removeElement(Node*& head, int value) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->data == value) {
            if (prev == nullptr) {
                // Видалення головного елементу
                Node* temp = current;
                current = current->next;
                head = current;
                delete temp;
            }
            else {
                // Видалення елементу в середині списку
                Node* temp = current;
                current = current->next;
                prev->next = current;
                delete temp;
            }
        }
        else {
            prev = current;
            current = current->next;
        }
    }
}


int main() {
    SetConsoleOutputCP(1251);

    // Створення першого списку та заповнення його елементами
    Node* list1 = nullptr;
    int numElements1;
    cout << "Введіть кількість елементів першого списку: ";
    cin >> numElements1;

    for (int i = 0; i < numElements1; i++) {
        int value;
        cout << "Введіть значення елементу " << i + 1 << ": ";
        cin >> value;
        push(list1, value);
    }

    // Створення другого списку та заповнення його елементами через ввід користувача
    Node* list2 = nullptr;
    int numElements2;
    cout << "Введіть кількість елементів другого списку: ";
    cin >> numElements2;

    for (int i = 0; i < numElements2; i++) {
        int value;
        cout << "Введіть значення елементу " << i + 1 << ": ";
        cin >> value;
        push(list2, value);
    }

    // Задане число
    int threshold;
    cout << "Введіть максимально допустиме значення елемента списку: ";
    cin >> threshold;

    bool exit = false; // Змінна для виходу з циклу
    Node* list3 = nullptr; // Ініціалізуємо list3 перед використанням

    Node* current = nullptr; // Оголошуємо current перед switch

    while (!exit) {
        int variantTask;
        cout << "Оберіть варіант завдання:" << endl
            << "1 - Створити та переглянути третій список" << endl
            << "2 - Видалити елемент списку" << endl;
        cin >> variantTask;
        switch (variantTask) {
        case 1:
            // Створення третього списку та заповнення його елементами з першого та другого списку, які менші за задане число
            list3 = nullptr; // Ініціалізуємо list3 

            current = list1;
            while (current != nullptr) {
                if (current->data < threshold) {
                    push(list3, current->data);
                }
                current = current->next;
            }

            current = list2;
            while (current != nullptr) {
                if (current->data < threshold) {
                    push(list3, current->data);
                }
                current = current->next;
            }

            // Виведення списків на екран
            cout << "Перший список: ";
            printList(list1);

            cout << "Другий список: ";
            printList(list2);

            cout << "Третій список (елементи менші за " << threshold << "): ";
            printList(list3);

            // Звільнення пам'яті для list3
            while (list3 != nullptr) {
                Node* temp = list3;
                list3 = list3->next;
                delete temp;
            }
            break;

        case 2:
            int elementToDelete;
            cout << "Введіть значення елемента, який потрібно видалити: ";
            cin >> elementToDelete;
            removeElement(list1, elementToDelete);
            removeElement(list2, elementToDelete);
            break;

        default:
            cout << "Невірний варіант завдання." << endl;
            break;
        }
    }

    // Звільнення пам'яті, що була виділена для списків
    while (list1 != nullptr) {
        Node* temp = list1;
        list1 = list1->next;
        delete temp;
    }

    while (list2 != nullptr) {
        Node* temp = list2;
        list2 = list2->next;
        delete temp;
    }

    return 0;
}