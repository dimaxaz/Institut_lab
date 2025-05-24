#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>

using namespace std;

struct Node {
    int value;      // Значение узла
    int count;      // Счётчик вхождений
    Node* left;     // Левый потомок
    Node* right;    // Правый потомок

    Node(int val) : value(val), count(1), left(nullptr), right(nullptr) {}
};

// Функция добавления элемента в дерево
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    }
    else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    else {
        // Если значение совпадает — увеличиваем счётчик
        root->count++;
    }

    return root;
}

// Функция поиска элемента в дереве
bool search(Node* root, int value) {
    if (root == nullptr) {
        return false;
    }

    if (value < root->value) {
        return search(root->left, value);
    }
    else if (value > root->value) {
        return search(root->right, value);
    }
    else {
        return true; // Найдено
    }
}

// Функция подсчёта количества вхождений элемента
int countOccurrences(Node* root, int value) {
    if (root == nullptr) {
        return 0;
    }

    if (value < root->value) {
        return countOccurrences(root->left, value);
    }
    else if (value > root->value) {
        return countOccurrences(root->right, value);
    }
    else {
        return root->count;
    }
}

// Функция освобождения памяти
void freeTree(Node* root) {
    if (root != nullptr) {
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Node* root = nullptr;

    // Создаём дерево с дубликатами
    int data[] = { 10, 5, 15, 5, 10, 10, 7 };
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); ++i) {
        root = insert(root, data[i]);
    }

    // Ввод значения с клавиатуры
    int key;
    cout << "Введите число для поиска в дереве: ";
    cin >> key;

    // Поиск и подсчёт вхождений
    if (search(root, key)) {
        cout << "Число " << key << " найдено в дереве." << endl;
        cout << "Количество вхождений: " << countOccurrences(root, key) << endl;
    }
    else {
        cout << "Число " << key << " не найдено в дереве." << endl;
    }

    // Освобождаем память
    freeTree(root);

    return 0;
}