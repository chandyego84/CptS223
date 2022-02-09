output: main.o maxsubsum.o
	g++ main.o maxsubsum.o -o output 

main.o: main.cpp
	g++ -c main.cpp

maxsubsum.o: maxsubsum.cpp
	g++ -c maxsubsum.cpp

clean:
	rm *.o output