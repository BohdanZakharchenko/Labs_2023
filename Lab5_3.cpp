#include "pch.h"
#include <windows.h>
#include <iostream>
using namespace std;

// Структура, що представляє вузол бінарного дерева
struct Node {
    int data;           // Значення вузла
    struct Node* left;  // Вказівник на лівого нащадка
    struct Node* right; // Вказівник на правого нащадка
};

// Функція для створення нового вузла з заданим значенням
Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Функція для пошуку максимального значення в дереві
void findMax(Node* node, int& max_val) {
    if (node == NULL)
        return;

    if (max_val < node->data)
        max_val = node->data;

    findMax(node->left, max_val);
    findMax(node->right, max_val);
}

// Функція для підрахунку кількості повторень максимального значення в дереві
int countMax(Node* node, int max_val) {
    if (node == NULL)
        return 0;

    if (node->data == max_val)
        return 1 + countMax(node->left, max_val) + countMax(node->right, max_val);

    return countMax(node->left, max_val) + countMax(node->right, max_val);
}

// Функція для виводу значень вузлів дерева в порядку інордер
void printInorder(Node* node) {
    if (node == nullptr) {
        return;
    }

    // Рекурсивно виводимо ліве піддерево
    printInorder(node->left);

    // Виводимо значення поточного вузла
    cout << node->data << " ";

    // Рекурсивно виводимо праве піддерево
    printInorder(node->right);
}

int main() {
    SetConsoleOutputCP(1251);  

    // Створюємо бінарне дерево з деякими вузлами
    struct Node* root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(50);

    int max_val = INT_MIN;  // Ініціалізуємо максимальне значення як найменше можливе ціле число
    printInorder(root);     // Виводимо значення вузлів дерева 
    findMax(root, max_val); // Знаходимо максимальне значення

    // Виводимо максимальне значення та кількість його повторень
    cout << "Максимальне значення: " << max_val << endl;
    cout << "Кількість повторень максимального значення: " << countMax(root, max_val) << endl;

    return 0;
}