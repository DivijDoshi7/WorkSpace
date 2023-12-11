#include <iostream>
#include <limits>
#include "Student_Admissions.h"

Student::Student(const std::string& name, int age, const std::string& address)
    : Name(name), Age(age), Address(address) {
}

void Student::DisplayStudentInfo() {
    std::cout << "Name: " << Name << std::endl;
    std::cout << "Age: " << Age << std::endl;
    std::cout << "Address: " << Address << std::endl;
    // Display other student information
}

Course::Course(const std::string& name, double fee)
    : CourseName(name), CourseFee(fee) {
    // Initialize other data members
}

std::string Course::GetCourseName() const {
    return CourseName;
}

double Course::GetCourseFee() const {
    return CourseFee;
}

AdmissionProcess::AdmissionProcess() {
    // Initialize available courses
    AvailableCourses.push_back(Course("Computer Science", 15000));
    AvailableCourses.push_back(Course("Economics", 12000));
    AvailableCourses.push_back(Course("Psychology", 13000));
    // Add more courses
}

AdmissionProcess::~AdmissionProcess() {
}

void AdmissionProcess::StartAdmission() {
    std::string name, address;
    int age, courseChoice;

    std::cout << "Welcome to Krea University Admission Process" << std::endl;

    // Input student's name
    std::cout << "Please enter your name: ";
    std::getline(std::cin, name);

    // Input student's age with error handling
    while (true) {
        std::cout << "Please enter your age: ";
        if (std::cin >> age && age > 0) {
            break;
        } else {
            std::cerr << "Invalid age. Please enter a valid age." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    std::cin.ignore(); 
    std::cout << "Please enter your address: ";
    std::getline(std::cin, address);

    //  Student object dynamically
    Student* student = new Student(name, age, address);
    student->DisplayStudentInfo();

    ShowAvailableCourses();

    while (true) {
        std::cout << "Enter the number of the course you want to enroll in: ";
        if (std::cin >> courseChoice && courseChoice >= 1 && courseChoice <= AvailableCourses.size()) {
            break;
        } else {
            std::cerr << "Invalid course choice. Please enter a valid course number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    EnrollStudentInCourse(student, &AvailableCourses[courseChoice - 1]);
}

void AdmissionProcess::ShowAvailableCourses() {
    std::cout << "Available Courses:" << std::endl;
    for (size_t i = 0; i < AvailableCourses.size(); ++i) {
        std::cout << i + 1 << ". " << AvailableCourses[i].GetCourseName() << " - Fee: "
                  << AvailableCourses[i].GetCourseFee() << std::endl;
    }
}

void AdmissionProcess::EnrollStudentInCourse(Student* student, Course* course) {
    double totalFee = course->GetCourseFee();

    std::cout << "Congratulations! You have successfully enrolled in the "
              << course->GetCourseName() << " course." << std::endl;
}
