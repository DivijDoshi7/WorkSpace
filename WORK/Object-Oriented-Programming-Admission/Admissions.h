// Admissions.h
#ifndef STUDENT_ADMISSIONS_H
#define STUDENT_ADMISSIONS_H

#include <string>
#include <vector>

class Student {
private:
    std::string Name;
    int Age;
    std::string Address;

public:
    Student(std::string name, int age, std::string address);
    void DisplayStudentInfo();
    // Other member function declarations for student operations
};

class Course {
private:
    std::string CourseName;
    double CourseFee;

public:
    Course(std::string name, double fee);
    std::string GetCourseName() const;
    double GetCourseFee() const;
    // Other member function declarations for course operations
};

class AdmissionProcess {
private:
    std::vector<Course> AvailableCourses;

public:
    AdmissionProcess();
    void StartAdmission();
    void ShowAvailableCourses();
    void EnrollStudentInCourse(Student& student, const Course& course);
    // Other member function declarations for admission operations
};

#endif // STUDENT_ADMISSIONS_H
