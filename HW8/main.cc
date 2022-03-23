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

// write to csv fxn
void writeCSV(vector<long double> &V, vector<long double> &S, vector<long double> &US) {
    ofstream outfile("runtimes.csv");

    outfile << "N,ARRAYavg,BSTavg,HASHavg" << endl;
    for (int i =0; i < NMAX; i++) {
        outfile << i + 1 << "," << V[i] << "," << S[i] << "," << US[i] << endl;
    }
}

int main(int argc, char **argv) {
    /*Creating the array A*/
    int A[NMAX];
    /*Instantiating each STL DS*/
    vector<int> V;
    set<int> S;
    unordered_set<int> US;
    /*For storing the runtimes of each DS for each N*/
    vector<long double> V_times;
    vector<long double> S_times;
    vector<long double> US_times;

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

    /*Inserting numbers from A, A[0] -> A[NMAX-1] into each STL DS*/
    for (int i = 0; i < NMAX; i++) {
        V.push_back(A[i]);
        S.insert(A[i]);
        US.insert(A[i]);
    }

    /*For each DS in {V, S, US}, calculate running time for searching for each number in A[0] -> A[NMAX-1]*/
    // FOR ARRAY
    auto end = chrono::high_resolution_clock::now();

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < NMAX; i++) {
        find(V.begin(), V.end(), A[i]);
        end = chrono::high_resolution_clock::now();
        chrono::duration<long double> duration = (end - start) / (long double)(i+1);
        V_times.push_back(duration.count());
    }
    
    // FOR BALANCED BST
    start = chrono::high_resolution_clock::now();

    for (int i = 0; i < NMAX; i++) {
        S.find(A[i]);
        end = chrono::high_resolution_clock::now();
        chrono::duration<long double> duration = (end - start) / (long double)(i+1);
        S_times.push_back(duration.count());
    }

    // FOR HASH TABLE
    start = chrono::high_resolution_clock::now();

    for (int i = 0; i < NMAX; i++) {
        US.find(A[i]);
        end = chrono::high_resolution_clock::now();
        chrono::duration<long double> duration = (end - start) / (long double)(i+1);
        US_times.push_back(duration.count());
    }
    
    /*Remove instances of V, S, and US*/
    V.clear();
    S.clear();
    US.clear();

    /*Writing data to csv file*/
    writeCSV(V_times, S_times, US_times);

    return 0;
}