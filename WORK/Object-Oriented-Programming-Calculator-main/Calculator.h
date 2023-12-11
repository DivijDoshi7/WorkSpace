#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
public:
    Calculator();
    void run();
    
private:
    double result, storedResult;
    void displayMenu();
    double performOperation(int choice, double num);
};

#endif // CALCULATOR_H
