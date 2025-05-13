#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

// Базовый класс Кадры
class Personnel {
protected:
    string firstName;
    string lastName;
    unsigned int yearOfEmployment;
    double salary;

public:
    Personnel(const string& firstName, const string& lastName, unsigned int year, double salary)
        : firstName(firstName), lastName(lastName), yearOfEmployment(year), salary(salary) {
    }

    virtual ~Personnel() {}

    // Виртуальная функция для вывода информации
    virtual void Print() const {
        cout << "Name: " << firstName << " " << lastName << endl;
        cout << "Year of employment: " << yearOfEmployment << endl;
        cout << "Salary: " << salary << endl;
    }

    // Виртуальная функция для строкового представления
    virtual string ToString() const {
        return "Personnel: " + firstName + " " + lastName +
            ", Year: " + to_string(yearOfEmployment) +
            ", Salary: " + to_string(salary);
    }
};

// Производный класс Рабочий
class Worker : public Personnel {
protected:
    string workshop;  // Цех
    string position;  // Должность

public:
    Worker(const string& firstName, const string& lastName, unsigned int year, double salary,
        const string& workshop, const string& position)
        : Personnel(firstName, lastName, year, salary), workshop(workshop), position(position) {
    }

    void Print() const override {
        Personnel::Print();
        cout << "Workshop: " << workshop << endl;
        cout << "Position: " << position << endl;
    }

    string ToString() const override {
        return "Worker: " + firstName + " " + lastName +
            ", Year: " + to_string(yearOfEmployment) +
            ", Salary: " + to_string(salary) +
            ", Workshop: " + workshop +
            ", Position: " + position;
    }
};

// Производный класс Инженер
class Engineer : public Personnel {
protected:
    string department;  // Отдел
    string specialization;  // Специализация

public:
    Engineer(const string& firstName, const string& lastName, unsigned int year, double salary,
        const string& department, const string& specialization)
        : Personnel(firstName, lastName, year, salary), department(department), specialization(specialization) {
    }

    void Print() const override {
        Personnel::Print();
        cout << "Department: " << department << endl;
        cout << "Specialization: " << specialization << endl;
    }

    string ToString() const override {
        return "Engineer: " + firstName + " " + lastName +
            ", Year: " + to_string(yearOfEmployment) +
            ", Salary: " + to_string(salary) +
            ", Department: " + department +
            ", Specialization: " + specialization;
    }
};

// Производный класс Администрация
class Administration : public Personnel {
protected:
    string position;  // Должность (директор, менеджер и т.д.)
    unsigned int subordinates;  // Количество подчинённых

public:
    Administration(const string& firstName, const string& lastName, unsigned int year, double salary,
        const string& position, unsigned int subordinates)
        : Personnel(firstName, lastName, year, salary), position(position), subordinates(subordinates) {
    }

    void Print() const override {
        Personnel::Print();
        cout << "Position: " << position << endl;
        cout << "Subordinates: " << subordinates << endl;
    }

    string ToString() const override {
        return "Administration: " + firstName + " " + lastName +
            ", Year: " + to_string(yearOfEmployment) +
            ", Salary: " + to_string(salary) +
            ", Position: " + position +
            ", Subordinates: " + to_string(subordinates);
    }
};

int main() {
    vector<unique_ptr<Personnel>> employees;

    // Добавляем работников разных типов
    employees.push_back(make_unique<Worker>("Ivan", "Petrov", 2015, 45000, "Workshop #1", "Turner"));
    employees.push_back(make_unique<Engineer>("Anna", "Sidorova", 2010, 80000, "R&D", "Software Engineer"));
    employees.push_back(make_unique<Administration>("Sergey", "Ivanov", 2005, 120000, "Director", 50));

    // Выводим информацию через Print()
    cout << "=== Printing employee info ===" << endl;
    for (const auto& emp : employees) {
        emp->Print();
        cout << "-------------------" << endl;
    }

    // Выводим информацию через ToString()
    cout << "\n=== Converting employees to string ===" << endl;
    for (const auto& emp : employees) {
        cout << emp->ToString() << endl;
    }

    return 0;
}