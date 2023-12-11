// Calculator.cpp
#include "Calculator.h"
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <limits>
#include <cassert>

Calculator::Calculator() : result(0), storedResult(0) {}

void Calculator::displayMenu() {
    std::cout << "Choose an operation:" << std::endl;
    std::cout << "1. Addition (+)" << std::endl;
    std::cout << "2. Subtraction (-)" << std::endl;
    std::cout << "3. Multiplication (*)" << std::endl;
    std::cout << "4. Division (/)" << std::endl;
    std::cout << "5. Modulus (%)" << std::endl;
    std::cout << "6. Square Root (sqrt)" << std::endl;
    std::cout << "7. Square (x^2)" << std::endl;
    std::cout << "8. Exponentiation (x^y)" << std::endl;
    std::cout << "9. Natural Logarithm (ln)" << std::endl;
    std::cout << "10. Logarithm (log)" << std::endl;
    std::cout << "11. Logarithm (Base 10)" << std::endl;
    std::cout << "0. Result " << std::endl;
    std::cout << "Enter your choice: ";
}

bool Calculator::isNumber(const std::string& input) {
    try {
        size_t pos;
        std::stod(input, &pos);
        return pos == input.length();
    } catch (const std::exception&) {
        return false;
    }
}

double Calculator::getValidNumberInput() {
    double num;

    while (true) {
        if (std::cin >> num) {
            // Input is a valid number
            break;
        } else {
            std::cerr << "Error: Please enter a valid number." << std::endl;
            std::cin.clear(); // Clear any error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
        }
    }

    return num;
}

double Calculator::performOperation(int choice, double num) {
    double result = 0;

    try {
        switch (choice) {
            case 1:
                result = storedResult + num;
                break;
            case 2:
                result = storedResult - num;
                break;
            case 3:
                result = storedResult * num;
                break;
            case 4:
                if (num == 0) {
                    throw std::runtime_error("Error: Division by zero!");
                }
                result = storedResult / num;
                break;
            case 5:
                std::cout << "This will percent (divide by 100 as done in every calculator) the stored value from the operations you conducted above";
                result = storedResult / 100;
                break;
            case 6: {
                char operation;
                std::cout << "Do you want to use the stored result for square rooting (currently " << storedResult << ")? (Y/N): ";
                std::cin >> operation;
                if (operation == 'Y' || operation == 'y') {
                    result = sqrt(storedResult);
                } else {
                    std::cout << "Enter the new number you want to square: ";
                    std::cin >> num;
                    result = sqrt(num);
                }
                break;
            }
            case 7: {
                char operation;
                std::cout << "Do you want to use the stored result for squaring (currently " << storedResult << ")? (Y/N): ";
                std::cin >> operation;
                if (operation == 'Y' || operation == 'y') {
                    result = pow(storedResult, 2);
                } else {
                    std::cout << "Enter the new number you want to square: ";
                    std::cin >> num;
                    result = pow(num, 2);
                }
                break;
            }
            case 8: {
                double exponent;
                char operation;
                std::cout << "Do you want to use the stored result as the base (currently " << storedResult << ") for exponentiation? (Y/N): ";
                std::cin >> operation;
                if (operation == 'Y' || operation == 'y') {
                    num = storedResult;
                } else {
                    std::cout << "Enter the base for exponentiation: ";
                    std::cin >> num;
                }
                std::cout << "Enter the exponent: ";
                std::cin >> exponent;
                result = pow(num, exponent);
                break;
            }
            case 9: {
                char operation;
                std::cout << "Do you want to use the stored result as the number (currently " << storedResult << ")? (Y/N):";
                std::cin >> operation;
                if (operation == 'Y' || operation == 'y') {
                    num = storedResult;
                } else {
                    std::cout << "Enter the number for the natural logarithm: ";
                    std::cin >> num;
                }
                if (num > 0) {
                    result = log(num);
                } else {
                    throw std::invalid_argument("Error: Invalid input for natural logarithm!");
                }
                break;
            }
            case 10: {
                double base;
                std::cout << "Enter the base for the logarithm: ";
                std::cin >> base;
                if (base > 0) {
                    char operation;
                    std::cout << "Do you want to use the stored result as the number (currently " << storedResult << ")? (Y/N): ";
                    std::cin >> operation;
                    if (operation == 'Y' || operation == 'y') {
                        num = storedResult;
                    } else {
                        std::cout << "Enter the number for the logarithm: ";
                        std::cin >> num;
                    }
                    result = log(num) / log(base); // Calculate logarithm with a custom base
                } else {
                    throw std::invalid_argument("Error: Invalid input for logarithm base!");
                }
                break;
            }
            case 11: {
                char operation;
                std::cout << "Do you want to use the stored result as the number (currently " << storedResult << ")? (Y/N): ";
                std::cin >> operation;
                if (operation == 'Y' || operation == 'y') {
                    num = storedResult;
                } else {
                    std::cout << "Enter the number for the logarithm: ";
                    std::cin >> num;
                }
                if (num > 0) {
                    result = log(num) / log(10); // Calculate logarithm with a custom base
                } else {
                    throw std::invalid_argument("Error: Invalid input for logarithm base!");
                }
                break;
            }
            default:
                throw std::invalid_argument("Error: Invalid operation choice!");
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        
    }

    assert(!std::isnan(result)); // Assert that the result is not NaN 
    return result;
}

void Calculator::run() {
    int choice;
    double num;

    std::cout << "Calculator is ready. Enter '0' to exit." << std::endl;
    std::cout << "Please start by choosing Option 1 or 2." << std::endl;

    while (true) {
        displayMenu();
        std::cin >> choice;

        if (choice < 0 || choice > 11) {
            std::cerr << "Error: Invalid choice!" << std::endl;
            continue;
        }

        if (choice != 0 && choice != 9 && choice != 10 && choice != 8 && choice != 11 && choice != 7 && choice != 6) {
            std::cout << "Enter a number: ";
            num = getValidNumberInput(); // Use the new function to get a valid number
        }

        if (choice == 0) {
            std::cout << "Final Result: " << result << std::endl;
            break;
        }

        result = performOperation(choice, num);

        storedResult = result; // Store the algebraic result for future use
    }
}

