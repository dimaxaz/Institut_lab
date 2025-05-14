#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class Set {
private:
    vector<T> elements;

    // �������� �� ������� �������� � ���������
    bool contains(const T& item) const {
        return find(elements.begin(), elements.end(), item) != elements.end();
    }

public:
    // ����������� �� ���������
    Set() = default;

    // ����������� �� ������ �������������
    Set(initializer_list<T> init) {
        for (const auto& item : init) {
            add(item);
        }
    }

    // ���������� �������� (���� ��� ��� ���)
    void add(const T& item) {
        if (!contains(item)) {
            elements.push_back(item);
        }
    }

    // ��������� ������� ���������
    size_t size() const {
        return elements.size();
    }

    // �������� + ��� ���������� �������� (item + set)
    friend Set operator+(const T& item, const Set& s) {
        Set result = s;
        result.add(item);
        return result;
    }

    // �������� + ��� ����������� ��������
    Set operator+(const Set& other) const {
        Set result = *this;
        for (const auto& item : other.elements) {
            result.add(item);
        }
        return result;
    }

    // �������� == ��� �������� �� ���������
    bool operator==(const Set& other) const {
        if (size() != other.size()) return false;
        
        for (const auto& item : elements) {
            if (!other.contains(item)) return false;
        }
        return true;
    }

    // �������� != (������������� ������������ �� ==)
    bool operator!=(const Set& other) const {
        return !(*this == other);
    }

    // ����� ���������
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
    // ������� ���������
    Set<int> s1 = {1, 2, 3};
    Set<int> s2 = {3, 4, 5};

    cout << "Set 1: " << s1 << endl;
    cout << "Set 2: " << s2 << endl;

    // ��������� ������� � ��������� (item + set)
    Set<int> s3 = 6 + s1;
    cout << "6 + Set 1: " << s3 << endl;

    // ����������� ��������
    Set<int> s4 = s1 + s2;
    cout << "Set 1 + Set 2: " << s4 << endl;

    // �������� �� ���������
    Set<int> s5 = {1, 2, 3};
    cout << "Set 1: " << s1 << endl;
    cout << "Set 5: " << s5 << endl;
    cout << "Set 1 == Set 5: " << (s1 == s5 ? "true" : "false") << endl;
    cout << "Set 1 == Set 2: " << (s1 == s2 ? "true" : "false") << endl;

    return 0;
}