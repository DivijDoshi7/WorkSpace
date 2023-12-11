#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>

class Calculator {
public:
    Calculator();
    void run();

private:
    double result, storedResult;
    void displayMenu();
    bool isNumber(const std::string& input);
    double getValidNumberInput();
    double performOperation(int choice, double num);
};

#endif // CALCULATOR_H