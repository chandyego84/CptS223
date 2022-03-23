// Chandler Juego
// HW8 - CPTS 223 - Spring 2022
// Due 3/23/22

#include <fstream>
#include <iostream>
#include <vector> // array
#include <set> // balanced BST
#include <unordered_set> // hash table
#include <chrono> // time
#include <algorithm> // searching for VECTOR


using namespace std;

#define NMAX 1000
#define NMAX2 10000

int main(int argc, char **argv) {
    /*Creating the array A*/
    int A[NMAX];

    // init random seed
    srand (time(NULL));
    
    // insert numbers 1 - NMAX into array A;
    for (int i = 0; i < NMAX; i++) {
        A[i] = i + 1;
    }
    // shuffle array A
    for (int i = 0; i < NMAX; i++) {
        int j = rand() & NMAX;
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }

    /*Instantiating each STL DS*/
    vector<int> V;
    set<int> S;
    unordered_set<int> US;

    /*Inserting numbers from A, A[0] -> A[NMAX-1] into each STL DS*/
    for (int i = 0; i < NMAX; i++) {
        V.push_back(A[i]);
        S.insert(A[i]);
        US.insert(A[i]);
    }

    /*For each DS in {V, S, US}, calculate running time for searching for each number in A[0] -> A[NMAX-1]*/
    // FOR ARRAY
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < NMAX; i++) {
        auto found = find(V.begin(), V.end(), A[i]);
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = (end - start) / NMAX;
    cout << "VECTOR: " << duration.count() << " seconds" << endl;

    // FOR BALANCED BST
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < NMAX; i++) {
        S.find(A[i]);
    }
    end = chrono::high_resolution_clock::now();
    duration = (end - start) / NMAX;
    cout << "SET: " << duration.count() << " seconds" << endl;

    // FOR HASH TABLE
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < NMAX; i++) {
        US.find(A[i]);
    }
    end = chrono::high_resolution_clock::now();
    duration = (end - start) / NMAX;
    
    cout << "UNORDERED SET: " << duration.count() << " seconds" << endl;

    return 0;
}