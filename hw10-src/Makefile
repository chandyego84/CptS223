# Makefile

CC = g++ -Wall -std=c++11

all: main-int main-str

main-int: DisjointSet.h main-int.cc
	$(CC) -o main-int main-int.cc

main-str: DisjointSet.h main-str.cc
	$(CC) -o main-str main-str.cc

clean:
	/bin/rm -f *.o main-int main-str
