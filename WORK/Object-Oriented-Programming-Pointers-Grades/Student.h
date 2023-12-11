// Student.h
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

class Student {
private:
    std::string Name;
    int Age;
    std::vector<double>* Grades;

public:
    Student(const std::string& name, int age);
    void AddGrade(double grade);
    double CalculateAverageGrade() const;
    void DisplayGradeReport() const;
    ~Student();
};

// Function to check if a grade is valid (between 0.0 and 10.0)
bool isValidGrade(double grade);

#endif // STUDENT_H
