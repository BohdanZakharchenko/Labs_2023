#include "pch.h"
#include <iostream>
#include <stack>
#include <string>
#include <Windows.h>

using namespace std;

// Оголошення структури для представлення елементів стеку
typedef struct Element {
	int value;
	struct Element* next;
} Element;

// Функція для додавання елемента до стеку
void push(Element** first, int data) {
	Element* temp;
	temp = (Element*)malloc(sizeof(Element));
	temp->value = data;
	temp->next = (*first);
	(*first) = temp;
}

// Функція для видалення елемента зі стеку та отримання його значення
int pop(Element** first, int* x) {
	Element* temp;
	if (*first == nullptr)
		return 0;
	temp = (*first);
	*x = temp->value;
	(*first) = temp->next;
	free(temp);

	return 1;
}

int main() {
	SetConsoleOutputCP(1251);
	int N;
	cout << "Введіть кількість елементів масиву" << endl;
	cin >> N;
	int* Arr = new int[N];

	// Заповнення масиву Arr значеннями, воденими з клавіатури, і додавання їх у стек
	Element* head = nullptr;
	int i, x;
	for (int i = 0; i < N; i++) {
		cout << "Arr[" << i << "] = ";
		cin >> Arr[i]; // Зчитування елементів масиву з клавіатури
		push(&head, Arr[i]);
	}

	// Витягання і виведення елементів зі стеку в зворотньому порядку
	for (int i = 0; i < N; i++) {
		while (pop(&head, &x)) {
			cout << x << endl;
		}
	}

	// завершення програми
	return 0;
}

	
	
 