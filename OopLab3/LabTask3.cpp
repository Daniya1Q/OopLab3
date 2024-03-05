#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float grade;
    Student(int i, string n, float g) : id(i), name(n), grade(g) {}
};

class StudentManager {
private:
    vector<Student*> records;

public:
    void addStudent(int id, string name, float grade) {
        Student* newStudent = new Student(id, name, grade);
        records.push_back(newStudent);
    }

    void updateGrade(int id, float newGrade) {
        for (Student* student : records) {
            if (student->id == id) {
                student->grade = newGrade;
                return;
            }
        }
        cout << "Student ID not found." << endl;
    }

    void displayRecords() const {
        for (const Student* student : records) {
            cout << "ID: " << student->id << ", Name: " << student->name << ", Grade: " << student->grade << endl;
        }
    }

    ~StudentManager() {
        for (Student* student : records) {
            delete student;
        }
    }
};

int main() {
    int newId, updateId;
    string newName;
    float newGrade, updatedGrade;
    char continueOption;

    StudentManager sm;

    sm.addStudent(1, "John Doe", 92.5);
    sm.addStudent(2, "Jane Doe", 88.0);
    sm.displayRecords();
    cout << "----------------" << endl;

    sm.updateGrade(1, 95.0);
    cout << "Updated Grades" << endl;
    sm.displayRecords();
    cout << endl;

    do {
        cout << "Do you want to add a new student? (y/n): ";
        cin >> continueOption;

        if (continueOption == 'y' || continueOption == 'Y') {
            cout << "Enter details for a new student:" << endl;
            cout << "ID: ";
            cin >> newId;
            cout << "Name: ";
            cin.ignore();
            getline(cin, newName);
            cout << "Grade: ";
            cin >> newGrade;

            sm.addStudent(newId, newName, newGrade);

            cout << "After adding a new student:" << endl;
            sm.displayRecords();
            cout << "------------------" << endl;
        }

        cout << "Do you want to update a student's grade? (y/n): ";
        cin >> continueOption;

        if (continueOption == 'y' || continueOption == 'Y') {
            cout << "Enter the ID of the student whose grade you want to update: ";
            cin >> updateId;
            cout << "Enter the new grade: ";
            cin >> updatedGrade;

            sm.updateGrade(updateId, updatedGrade);

            cout << "After updating the grade:" << endl;
            sm.displayRecords();
            cout << "------------------" << endl;
        }

    } while (continueOption == 'y' || continueOption == 'Y');

    return 0;
}
