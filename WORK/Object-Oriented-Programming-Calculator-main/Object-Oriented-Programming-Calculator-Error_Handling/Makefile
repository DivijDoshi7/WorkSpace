
output: Calculator_Error_Handling.o main_calculator.o
	g++ Calculator_Error_Handling.o main_calculator.o -o output

main_calculator.o: main_calculator.cpp
	g++ -c main_calculator.cpp

Calculator_Error_Handling.o: Calculator_Error_Handling.cpp
	g++ -c Calculator_Error_Handling.cpp

clean:
	rm *.o output
