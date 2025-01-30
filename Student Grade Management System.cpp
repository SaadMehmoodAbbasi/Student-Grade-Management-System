#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // For setting decimal precision

using namespace std;

class Student {
public:
    string name;
    int rollNumber;
    vector<double> grades;

    Student(string studentName, int studentRollNumber, vector<double> studentGrades)
        : name(studentName), rollNumber(studentRollNumber), grades(studentGrades) {}

    double calculateAverage() {
        double sum = 0;
        for (double grade : grades) {
            sum += grade;
        }
        return grades.empty() ? 0.0 : sum / grades.size();
    }

    void displayGrades() {
        cout << "Grades for " << name << " (Roll No: " << rollNumber << "): ";
        for (double grade : grades) {
            cout << grade << " ";
        }
        cout << endl;
    }

    void displayStudentInfo() {
        cout << "Name: " << name << "\nRoll Number: " << rollNumber << "\nGrades: ";
        displayGrades();
        cout << "Average Grade: " << fixed << setprecision(2) << calculateAverage() << endl;
    }
};

class GradeManagementSystem {
private:
    vector<Student> students;

public:
    void addStudent() {
        string name;
        int rollNumber;
        int numGrades;
        vector<double> grades;

        // Get student information
        cout << "\nEnter student's name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter roll number: ";
        cin >> rollNumber;
        cout << "Enter number of grades: ";
        cin >> numGrades;

        // Get grades for the student
        for (int i = 0; i < numGrades; ++i) {
            double grade;
            cout << "Enter grade " << i + 1 << ": ";
            cin >> grade;
            grades.push_back(grade);
        }

        // Add student to the system
        students.push_back(Student(name, rollNumber, grades));
        cout << "\nStudent " << name << " added successfully!\n";
    }

    void displayAllStudents() {
        if (students.empty()) {
            cout << "\nNo students available.\n";
        } else {
            for (Student& student : students) {
                student.displayStudentInfo();
                cout << endl;
            }
        }
    }

    void displayStudentDetails() {
        int rollNumber;
        cout << "\nEnter roll number of the student: ";
        cin >> rollNumber;

        bool found = false;
        for (Student& student : students) {
            if (student.rollNumber == rollNumber) {
                student.displayStudentInfo();
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Student with roll number " << rollNumber << " not found.\n";
        }
    }

    void displayAverageGradeOfAllStudents() {
        if (students.empty()) {
            cout << "\nNo students available.\n";
        } else {
            double totalAverage = 0;
            int totalStudents = students.size();
            for (Student& student : students) {
                totalAverage += student.calculateAverage();
            }
            double average = totalAverage / totalStudents;
            cout << "\nAverage grade of all students: " << fixed << setprecision(2) << average << endl;
        }
    }
};

int main() {
    GradeManagementSystem system;
    int choice;

    while (true) {
        cout << "\nStudent Grade Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Display Student Details by Roll Number\n";
        cout << "4. Display Average Grade of All Students\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.addStudent();
                break;
            case 2:
                system.displayAllStudents();
                break;
            case 3:
                system.displayStudentDetails();
                break;
            case 4:
                system.displayAverageGradeOfAllStudents();
                break;
            case 5:
                cout << "Exiting Student Grade Management System.\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}

