#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

char* my_strcpy(char* dest, const char* src) {
    char* original_dest = dest;
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return original_dest;
}

struct QueueItem {
    char* data;
    int priority;

    void setData(const char* d) {
        data = new char[strlen(d) + 1];
        my_strcpy(data, d);
    }

    void clear() {
        delete[] data;
    }
};

class PriorityQueue {
private:
    QueueItem* items;
    size_t capacity;
    size_t count;

    void resize() {
        capacity *= 2;
        QueueItem* newItems = new QueueItem[capacity];

        for (size_t i = 0; i < count; ++i) {
            newItems[i] = items[i];
        }

        delete[] items;
        items = newItems;
    }

public:
    PriorityQueue(size_t initialCapacity = 4) {
        capacity = initialCapacity;
        count = 0;
        items = new QueueItem[capacity];
    }

    ~PriorityQueue() {
        for (size_t i = 0; i < count; ++i) {
            items[i].clear();
        }
        delete[] items;
    }

    void enqueue(const char* data, int priority) {
        if (count >= capacity) {
            resize();
        }

        QueueItem item;
        item.priority = priority;
        item.setData(data);

        int i = count - 1;
        while (i >= 0 && items[i].priority < priority) {
            items[i + 1] = items[i];
            --i;
        }

        items[i + 1] = item;
        ++count;
    }

    const char* dequeue() {
        if (isEmpty()) {
            cout << "Ошибка: очередь пуста\n";
            return nullptr;
        }

        const char* result = items[0].data;

        for (size_t i = 0; i < count - 1; ++i) {
            items[i] = items[i + 1];
        }

        --count;
        return result;
    }

    bool isEmpty() const {
        return count == 0;
    }

    void print() const {
        for (size_t i = 0; i < count; ++i) {
            cout << "{" << items[i].data << ", Приоритет: " << items[i].priority << "}\n";
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    PriorityQueue pq;

    pq.enqueue("Задача 1", 2);
    pq.enqueue("Задача 2", 5);
    pq.enqueue("Задача 3", 1);
    pq.enqueue("Задача 4", 4);

    cout << "Текущая очередь:\n";
    pq.print();

    cout << "\nОбработка задач:\n";
    while (!pq.isEmpty()) {
        cout << "Обработано: " << pq.dequeue() << endl;
    }

    return 0;
}