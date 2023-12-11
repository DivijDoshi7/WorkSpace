
output: MyLinkedList.o main.o
	g++ MyLinkedList.o main.o -o output

main.o: main.cpp MyLinkedList.h
	g++ -c main.cpp

MyLinkedList.o: MyLinkedList.cpp MyLinkedList.h
	g++ -c MyLinkedList.cpp

clean:
	rm *.o output
