#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;

// Функция для вывода содержимого multiset
template<typename T>
void printMultiset(const multiset<T>& ms, const string& name) {
    cout << name << ": { ";
    copy(ms.begin(), ms.end(), ostream_iterator<T>(cout, " "));
    cout << "}" << endl;

    // Подсчёт и вывод количества вхождений каждого элемента
    set<T> unique_elements(ms.begin(), ms.end());
    for (const auto& elem : unique_elements) {
        cout << elem << " appears " << ms.count(elem) << " times" << endl;
    }
    cout << endl;
}

int main() {
    // 1. Создание и заполнение первого контейнера
    multiset<int> ms1 = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
    cout << "Step 1: Initial container created" << endl;
    printMultiset(ms1, "Original multiset");

    // 2. Просмотр контейнера
    cout << "Step 2: Viewing the container" << endl;
    printMultiset(ms1, "Multiset before modifications");

    // 3. Изменение контейнера
    // Удаление всех единиц
    ms1.erase(1);
    // Замена всех троек на восьмёрки
    while (ms1.find(3) != ms1.end()) {
        ms1.erase(ms1.find(3));
        ms1.insert(8);
    }
    cout << "Step 3: Container modified (1s removed, 3s replaced with 8s)" << endl;
    printMultiset(ms1, "Modified multiset");

    // 4. Просмотр с использованием итераторов
    cout << "Step 4: Viewing with iterators" << endl;
    cout << "Multiset elements (using iterators): ";
    for (auto it = ms1.begin(); it != ms1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl << endl;

    // 5. Создание второго контейнера
    multiset<int> ms2 = { 2, 7, 1, 8, 2, 8, 4, 5 };
    cout << "Step 5: Second container created" << endl;
    printMultiset(ms2, "Second multiset");

    // 6. Изменение первого контейнера
    // Удаление 3 элементов после заданного (например, после первого вхождения 5)
    auto pos = ms1.find(5);
    if (pos != ms1.end()) {
        auto start = ++pos; // Следующий элемент после найденной 5
        auto end = start;
        advance(end, 3);    // Перемещаемся на 3 элемента вперёд

        if (end != ms1.end()) {
            ms1.erase(start, end);
        }
        else {
            ms1.erase(start, ms1.end());
        }
    }

    // Добавление всех элементов из второго контейнера
    ms1.insert(ms2.begin(), ms2.end());
    cout << "Step 6: First container modified (3 elements after first 5 removed, all from second multiset added)" << endl;

    // 7. Просмотр обоих контейнеров
    cout << "Step 7: Viewing both containers" << endl;
    printMultiset(ms1, "First multiset (final)");
    printMultiset(ms2, "Second multiset (unchanged)");

    return 0;
}