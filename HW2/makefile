
output: main.o indexEqual.o
	g++ main.o indexEqual.o -o output

main.o: main.cpp
	g++ -c main.cpp

indexEqual.o: indexEqual.cpp
	g++ -c indexEqual.cpp

clean:
	rm -f main.o indexEqual.o output