#include <iostream>
#include <string>
#include "Student.h"
#include "Validation.h"

int main() {
    std::wstring name;
    int age;
    double grade;

    std::wcout << L"Student Grade Reporting System" << std::endl;

    std::wcout << L"Enter student's name: ";
    std::getline(std::wcin, name);

    std::wcout << L"Enter student's age: ";
    if (!(std::wcin >> age)) {
        std::wcerr << L"Invalid input for age. Enter an integer." << std::endl;
        return 1;
    }

    Student* student = new Student(std::string(name.begin(), name.end()), age);

    char addMoreGrades = 'y';
    while (addMoreGrades == 'y' || addMoreGrades == 'Y') {
        bool validGrade = false;
        do {
            std::cout << "Enter a grade for the student (between 0.0 and 10.0): ";
            if (!(std::cin >> grade)) {
                std::cerr << "Invalid input for grade. Enter a number." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else if (!isValidGrade(grade)) {
                std::cerr << "Invalid grade. Enter a grade between 0.0 and 10.0." << std::endl;
            } else {
                validGrade = true;
            }
        } while (!validGrade);

        student->AddGrade(grade);

        std::cout << "Add another grade? (y/n): ";
        std::cin >> addMoreGrades;
    }

    std::cout << std::endl;

    student->DisplayGradeReport();

    delete student;

    return 0;
}
