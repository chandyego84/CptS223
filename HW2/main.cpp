#include "indexEqual.h"

int main() {
    // 100 vectors of size 100
    vector<vector<int>> A(100);
    // initialize each vector 
    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) {
            if (j == i) {
                A[i].push_back(j); // kth element of kth array equals index
                for (j; j < 100; j++) {
                    A[i].push_back(j+2);
                }
            }
            else A[i].push_back(j-1);
        }
    }
    // print each element of A[0]
    for (int x=0; x<100; x++) {
        cout << "index " << x << "element " << A[5][x] << endl;
    }
    

    cout << "k     " << "Recursive     " << "Iterative     " << endl;
    cout << "----  " << "---------     " << "---------     " << endl;
    for (int k=0; k<100; k++) {
        // test indexEqualRecurs on A[k]
        IndexEqualRecurs(A[k], 0, 99);
        cout << k << setw(8) << recursComps;
        // test indexEqualIter on A[k]
        IndexEqualIter(A[k], 0, 99);
        cout << setw(14) << iterComps << endl;
    }
    

    return 0;
}