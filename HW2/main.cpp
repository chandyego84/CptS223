#include "indexEqual.h"

int main() {
    // 100 vectors of size 100
    vector<vector<int>> A(100);
    // initialize each vector
    for (int i=0; i<100; i++) {
        for (int j=-1; j<99; j++) {
            if (j == 98) A[i].push_back(j+1); // kth element of kth array equals index
            else A[i].push_back(j);
        }
    }

    //cout << "Recursive Index Equal: " << IndexEqualRecurs(A, 0, 99) << endl;
    //cout << "Iterative Index Equal: " << IndexEqualIter(A, 0, 99) << endl;

    return 0;
}