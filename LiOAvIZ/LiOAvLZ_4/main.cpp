#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>

using namespace std;

struct Node {
    int value;      // �������� ����
    int count;      // ������� ���������
    Node* left;     // ����� �������
    Node* right;    // ������ �������

    Node(int val) : value(val), count(1), left(nullptr), right(nullptr) {}
};

// ������� ���������� �������� � ������
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
        // ���� �������� ��������� � ����������� �������
        root->count++;
    }

    return root;
}

// ������� ������ �������� � ������
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
        return true; // �������
    }
}

// ������� �������� ���������� ��������� ��������
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

// ������� ������������ ������
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

    // ������ ������ � �����������
    int data[] = { 10, 5, 15, 5, 10, 10, 7 };
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); ++i) {
        root = insert(root, data[i]);
    }

    // ���� �������� � ����������
    int key;
    cout << "������� ����� ��� ������ � ������: ";
    cin >> key;

    // ����� � ������� ���������
    if (search(root, key)) {
        cout << "����� " << key << " ������� � ������." << endl;
        cout << "���������� ���������: " << countOccurrences(root, key) << endl;
    }
    else {
        cout << "����� " << key << " �� ������� � ������." << endl;
    }

    // ����������� ������
    freeTree(root);

    return 0;
}