#include "Calculator.h"
#include <iostream>

int main() {
    try {
        Calculator* calculator = new Calculator(); 
        calculator->run();
        delete calculator; 
    } catch (const std::bad_alloc& e) {
        std::cerr << "Error: Failed to allocate memory for Calculator object: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
