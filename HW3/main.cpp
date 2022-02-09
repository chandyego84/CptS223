#include "maxsubsum.h"

int main(int argc, char* argv[]) {
    MaxSubSum mss;
    ifstream infile(argv[1]); // reads from external file in command line
    string line; 
    while (getline(infile, line)) { 
        int index, val; 
        stringstream ss(line); 
        ss >> index >> val;
        mss.Insert(index, val);
        cout << mss << endl;
    } 
    infile.close(); 

    return 0;
}