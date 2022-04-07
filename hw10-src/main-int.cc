// main.cc
//
// Disjoint sets with integer elements.
//
// HW10 - CPTS 223 - Spring 2022

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "DisjointSet.h"

using namespace std;

int main(int argc, char* argv[]) {
	DisjointSet<int> disjointSet;
	ifstream infile(argv[1]);
	string line;
	while (getline(infile, line)) {
		string command;
		int val1, val2;
		stringstream ss(line);
		ss >> command >> val1;
		cout << command << " " << val1;
		if (command == "insert") {
			disjointSet.insert(val1);
			cout << ":" << endl;
		}
		if (command == "union") {
			ss >> val2;
			cout << " " << val2 << ":" << endl;
			disjointSet.unionSets(val1, val2);
		}
		if (command == "find") {
			val2 = disjointSet.find(val1);
			cout << ": " << val2 << endl;
		}
		cout << endl;
		disjointSet.print();
		cout << endl;
	}
	infile.close();
	return 0;
}
