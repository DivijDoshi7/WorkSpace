car_race.exe : Vehicle_Race.o Car.o main.o
	g++ Vehicle_Race.o Car.o main.o -o car.exe


Vehicle_Race.o : Vehicle_Race.cpp
	g++ -c Vehicle_Race.cpp

Car.o : Car.cpp
	g++ -c Car.cpp
main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o output
