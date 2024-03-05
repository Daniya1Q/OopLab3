#include <iostream>
#include <vector>
#include<string>
using namespace std;
int main() {
    vector<string> grades;

    // Adding grades to the vector
    grades.push_back("A");
    grades.push_back("B");
    grades.push_back("B+");


    cout << "Before Resizing" << endl;
    cout << endl;

    // Accessing and printing grades
    for (int i = 0; i < grades.size(); i++) {
        cout << "Grade " << i + 1 << ": " << grades[i] << endl;
    }
    cout << endl;
    cout << "After Resizing" << endl;
    cout << endl;

    // Adding more grades
    grades.push_back("A-");
    grades.push_back("C+");

    // Updated grades
    for (int i = 0; i < grades.size(); i++) {
        cout << "Grade " << i + 1 << ": " << grades[i] << endl;
    }

    return 0;
}