#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Worker {
    string firstName;
    string lastName;
    string workPost;
    unsigned godPost;
    unsigned payday;

public:
    Worker() = default;

    Worker(const string& firstName, const string& lastName, const string& workPost, unsigned godPost, unsigned payday)
        : firstName(firstName), lastName(lastName), workPost(workPost), godPost(godPost), payday(payday) {
    };

    ~Worker() {};

    bool operator==(const Worker& other) const {
        return (firstName == other.firstName) &&
            (lastName == other.lastName) &&
            (workPost == other.workPost) &&
            (godPost == other.godPost) &&
            (payday == other.payday);
    }

    bool operator!=(const Worker& other) const {
        return !(*this == other);
    }

    Worker& operator=(const Worker& other) {
        if (this != &other) {
            firstName = other.firstName;
            lastName = other.lastName;
            workPost = other.workPost;
            godPost = other.godPost;
            payday = other.payday;
        }
        return *this;
    }

    string getFullName() const {
        return lastName + " " + firstName[0] + ".";
    }

    string getWorkPost() const {
        return workPost;
    }

    unsigned getGodPost() const {
        return godPost;
    }

    unsigned getPayday() const {
        return payday;
    }

    unsigned getExperience(unsigned currentYear) const {
        return currentYear - godPost;
    }

    // ќбъ€вл€ем Observer другом до его определени€
    friend class Observer;
};

class Observer {
public:
    static string GetInfo(const Worker& worker) {
        return "Name: " + worker.firstName + " " + worker.lastName +
            ", Position: " + worker.workPost +
            ", Year of Employment: " + to_string(worker.godPost) +
            ", Salary: " + to_string(worker.payday);
    }
};

int main() {
    vector<Worker> workers = {
        Worker("Volodya", "Salov", "Rulevoy", 2007, 50000),
        Worker("Semen", "Semenov", "DoS", 1870, 3000000),
        Worker("Rafshan", "Asur", "Bombila", 2000, 100)
    };

    unsigned currentYear = 2023;

    for (const auto& worker : workers) {
        cout << Observer::GetInfo(worker) << endl;
    }

    return 0;
}