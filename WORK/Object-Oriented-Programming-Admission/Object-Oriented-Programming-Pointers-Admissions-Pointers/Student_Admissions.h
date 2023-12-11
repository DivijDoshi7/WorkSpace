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
    Student(const std::string& name, int age, const std::string& address);
    void DisplayStudentInfo();
    // Other member function declarations for student operations
};

class Course {
private:
    std::string CourseName;
    double CourseFee;

public:
    Course(const std::string& name, double fee);
    std::string GetCourseName() const;
    double GetCourseFee() const;
    // Other member function declarations for course operations
};

class AdmissionProcess {
private:
    std::vector<Course> AvailableCourses;

public:
    AdmissionProcess();
    ~AdmissionProcess(); // Destructor to release dynamic memory
    void StartAdmission();
    void ShowAvailableCourses();
    void EnrollStudentInCourse(Student* student, Course* course); // Use pointers
    // Other member function declarations for admission operations
};

#endif // STUDENT_ADMISSIONS_H
