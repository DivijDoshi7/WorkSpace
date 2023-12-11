
output: Calculator.o main_calculator.o
	g++ Calculator.o main_calculator.o -o output

main_calculator.o: main_calculator.cpp
	g++ -c main_calculator.cpp

Calculator.o: Calculator.cpp
	g++ -c Calculator.cpp

clean:
	rm *.o output
