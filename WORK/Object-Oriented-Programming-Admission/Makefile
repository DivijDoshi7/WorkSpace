
output: Admissions.o main.o 
	g++ Admissions.o main.o -o output
main.o: main.cpp
	g++ -c main.cpp
Admissions.o : Admissions.cpp
	g++ -c Admissions.cpp

clean:
	rm *.o output
