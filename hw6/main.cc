// main.cc
// Chandler Juego
// HW6 - CPTS 223 - Spring 2022
// Due 2/23/2022

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "BinarySearchTree.h"

using namespace std;

int main(int argc, char* argv[]) {
	BinarySearchTree<int> bst;
	ifstream infile(argv[1]);
	string line;
	while (getline(infile, line)) {
		string command;
		int val;
		stringstream ss(line);
		ss >> command >> val;
		if (command == "insert") {
			bst.insert(val);
		}
		if (command == "remove") {
			bst.remove(val);
		}
		cout << command << " " << val << ":" << endl;
		bst.Traversals();
		bst.DepthEqual();
		cout << endl;
	}
	infile.close();
	return 0;
}
