#include "Student.h"
#include <iostream>
#include "Validation.h" 

// Constructor for Student
Student::Student(const std::string& name, int age) : Name(name), Age(age) {
    // Initialize the Grades vector dynamically
    Grades = new std::vector<double>;
}

// Method to add a grade to the Student's Grades vector
void Student::AddGrade(double grade) {
    Grades->push_back(grade);
}

// Method to calculate the average grade of the Student
double Student::CalculateAverageGrade() const {
    if (Grades->empty()) {
        return 0.0;
    }

    double sum = 0.0;
    for (double grade : *Grades) {
        sum += grade;
    }
    return sum / Grades->size();
}

// Method to display the student's grade report
void Student::DisplayGradeReport() const {
    std::cout << "Name: " << Name << std::endl;
    std::cout << "Age: " << Age << std::endl;
    std::cout << "Grades: ";
    for (size_t i = 0; i < Grades->size(); i++) {
        std::cout << (*Grades)[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Average Grade: " << CalculateAverageGrade() << std::endl;
}

// Destructor for Student to deallocate the dynamically allocated vector
Student::~Student() {
    delete Grades;
}
