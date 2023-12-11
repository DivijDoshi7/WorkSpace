#include <iostream>
#include <string>
#include <vector>
#include <limits>

class Student {
private:
    std::string Name;
    int Age;
    std::string Address;

public:
    Student(std::string name, int age, std::string address)
        : Name(name), Age(age), Address(address) {
        // Initialize other data members
    }

    void DisplayStudentInfo() {
        std::cout << "Name: " << Name << std::endl;
        std::cout << "Age: " << Age << std::endl;
        std::cout << "Address: " << Address << std::endl;
        // Display other student information
    }

    // Other member functions for student operations
};

class Course {
private:
    std::string CourseName;
    double CourseFee;

public:
    Course(std::string name, double fee)
        : CourseName(name), CourseFee(fee) {
        // Initialize other data members
    }

    std::string GetCourseName() const {
        return CourseName;
    }

    double GetCourseFee() const {
        return CourseFee;
    }

    // Other member functions for course operations
};

class AdmissionProcess {
private:
    std::vector<Course> AvailableCourses;

public:
    AdmissionProcess() {
        // Initialize available courses
        AvailableCourses.push_back(Course("Computer Science", 15000));
        AvailableCourses.push_back(Course("Economics", 12000));
        AvailableCourses.push_back(Course("Psychology", 13000));
        // Add more courses
    }

    void StartAdmission() {
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

        std::cin.ignore(); // Clear newline from buffer
        std::cout << "Please enter your address: ";
        std::getline(std::cin, address);

        Student student(name, age, address);
        student.DisplayStudentInfo();

        ShowAvailableCourses();

        // Input course choice with error handling
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

        EnrollStudentInCourse(student, AvailableCourses[courseChoice - 1]);
    }

    void ShowAvailableCourses() {
        std::cout << "Available Courses:" << std::endl;
        for (int i = 0; i < AvailableCourses.size(); ++i) {
            std::cout << i + 1 << ". " << AvailableCourses[i].GetCourseName() << " - Fee: "
                      << AvailableCourses[i].GetCourseFee() << std::endl;
        }
    }

    void EnrollStudentInCourse(Student& student, const Course& course) {
        double totalFee = course.GetCourseFee();
        // Perform fee calculation, payment, and other admission tasks

        std::cout << "Congratulations! You have successfully enrolled in the "
                  << course.GetCourseName() << " course." << std::endl;
    }

    // Other member functions for admission operations
};

int main() {
    AdmissionProcess admission;
    admission.StartAdmission();
    return 0;
}
