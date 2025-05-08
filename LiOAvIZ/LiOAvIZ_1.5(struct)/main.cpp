#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Student {
    string firstName;
    string lastName;
    string faculty;
    int studentId;
};

void searchStudents(Student* students, unsigned studentCount) {
    int searchOption;
    cout << "Choose search criteria:\n"
        << "1. Last Name\n"
        << "2. First Name\n"
        << "3. Faculty\n"
        << "4. Student ID\n"
        << "Enter option (1-4): ";
    cin >> searchOption;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string searchString;
    int searchId;

    switch (searchOption) {
    case 1:
        cout << "\nEnter last name to search: ";
        getline(cin, searchString);
        for (unsigned i = 0; i < studentCount; ++i) {
            if (students[i].lastName == searchString) {
                cout << "\nFound Student:\n"
                    << "Full name: " << students[i].lastName << " " << students[i].firstName << "\n"
                    << "Faculty: " << students[i].faculty << "\n"
                    << "Student ID: " << students[i].studentId << "\n";
            }
        }
        break;
    case 2:
        cout << "\nEnter first name to search: ";
        getline(cin, searchString);
        for (unsigned i = 0; i < studentCount; ++i) {
            if (students[i].firstName == searchString) {
                cout << "\nFound Student:\n"
                    << "Full name: " << students[i].lastName << " " << students[i].firstName << "\n"
                    << "Faculty: " << students[i].faculty << "\n"
                    << "Student ID: " << students[i].studentId << "\n";
            }
        }
        break;
    case 3:
        cout << "\nEnter faculty to search: ";
        getline(cin, searchString);
        for (unsigned i = 0; i < studentCount; ++i) {
            if (students[i].faculty == searchString) {
                cout << "\nFound Student:\n"
                    << "Full name: " << students[i].lastName << " " << students[i].firstName << "\n"
                    << "Faculty: " << students[i].faculty << "\n"
                    << "Student ID: " << students[i].studentId << "\n";
            }
        }
        break;
    case 4:
        cout << "\nEnter student ID to search: ";
        cin >> searchId;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for (unsigned i = 0; i < studentCount; ++i) {
            if (students[i].studentId == searchId) {
                cout << "\nFound Student:\n"
                    << "Full name: " << students[i].lastName << " " << students[i].firstName << "\n"
                    << "Faculty: " << students[i].faculty << "\n"
                    << "Student ID: " << students[i].studentId << "\n";
            }
        }
        break;
    default:
        cout << "\nInvalid option selected.\n";
    }
}

int main() {
    unsigned studentCount;
    cout << "Enter number of students: ";
    cin >> studentCount;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Student* students = new Student[studentCount];

    for (unsigned i = 0; i < studentCount; ++i) {
        cout << "\nEnter student details:\n";

        cout << "First name: ";
        getline(cin, students[i].firstName);

        cout << "Last name: ";
        getline(cin, students[i].lastName);

        cout << "Faculty: ";
        getline(cin, students[i].faculty);

        cout << "Student ID: ";
        cin >> students[i].studentId;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    searchStudents(students, studentCount);

    delete[] students;
    return 0;
}
