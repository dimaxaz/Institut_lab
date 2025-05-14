#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class Set {
private:
    vector<T> elements;

    // Проверка на наличие элемента в множестве
    bool contains(const T& item) const {
        return find(elements.begin(), elements.end(), item) != elements.end();
    }

public:
    // Конструктор по умолчанию
    Set() = default;

    // Конструктор из списка инициализации
    Set(initializer_list<T> init) {
        for (const auto& item : init) {
            add(item);
        }
    }

    // Добавление элемента (если его еще нет)
    void add(const T& item) {
        if (!contains(item)) {
            elements.push_back(item);
        }
    }

    // Получение размера множества
    size_t size() const {
        return elements.size();
    }

    // Оператор + для добавления элемента (item + set)
    friend Set operator+(const T& item, const Set& s) {
        Set result = s;
        result.add(item);
        return result;
    }

    // Оператор + для объединения множеств
    Set operator+(const Set& other) const {
        Set result = *this;
        for (const auto& item : other.elements) {
            result.add(item);
        }
        return result;
    }

    // Оператор == для проверки на равенство
    bool operator==(const Set& other) const {
        if (size() != other.size()) return false;
        
        for (const auto& item : elements) {
            if (!other.contains(item)) return false;
        }
        return true;
    }

    // Оператор != (автоматически генерируется из ==)
    bool operator!=(const Set& other) const {
        return !(*this == other);
    }

    // Вывод множества
    friend ostream& operator<<(ostream& os, const Set& s) {
        os << "{ ";
        for (size_t i = 0; i < s.elements.size(); ++i) {
            os << s.elements[i];
            if (i != s.elements.size() - 1) os << ", ";
        }
        os << " }";
        return os;
    }
};

int main() {
    // Создаем множества
    Set<int> s1 = {1, 2, 3};
    Set<int> s2 = {3, 4, 5};

    cout << "Set 1: " << s1 << endl;
    cout << "Set 2: " << s2 << endl;

    // Добавляем элемент в множество (item + set)
    Set<int> s3 = 6 + s1;
    cout << "6 + Set 1: " << s3 << endl;

    // Объединение множеств
    Set<int> s4 = s1 + s2;
    cout << "Set 1 + Set 2: " << s4 << endl;

    // Проверка на равенство
    Set<int> s5 = {1, 2, 3};
    cout << "Set 1: " << s1 << endl;
    cout << "Set 5: " << s5 << endl;
    cout << "Set 1 == Set 5: " << (s1 == s5 ? "true" : "false") << endl;
    cout << "Set 1 == Set 2: " << (s1 == s2 ? "true" : "false") << endl;

    return 0;
}