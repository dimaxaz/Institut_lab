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
};

int main() {
    vector<Worker> workers = {
        Worker("Volodya", "Salov", "Rulevoy", 2007, 50000),
        Worker("Semen", "Semenov", "DoS", 1870, 3000000),
        Worker("Rafshan", "Asur", "Bombila", 2000, 100)
    };

    unsigned currentYear = 2025; // Текущий год

    // а) список работников, стаж работы которых превышает заданное число лет
    unsigned minExperience = 10;
    cout << "Workers with experience more than " << minExperience << " years:" << endl;
    for (const auto& worker : workers) {
        if (worker.getExperience(currentYear) > minExperience) {
            cout << worker.getFullName() << endl;
        }
    }

    // б) список работников, зарплата которых больше заданной
    unsigned minPayday = 50000;
    cout << "\nWorkers with payday more than " << minPayday << ":" << endl;
    for (const auto& worker : workers) {
        if (worker.getPayday() > minPayday) {
            cout << worker.getFullName() << endl;
        }
    }

    // в) список работников, занимающих заданную должность
    string targetWorkPost = "Rulevoy";
    cout << "\nWorkers with work post " << targetWorkPost << ":" << endl;
    for (const auto& worker : workers) {
        if (worker.getWorkPost() == targetWorkPost) {
            cout << worker.getFullName() << endl;
        }
    }

    return 0;
}
