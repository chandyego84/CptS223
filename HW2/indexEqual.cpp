#include "indexEqual.h"

bool IndexEqualRecurs(const vector<int> &A, int i, int j) {
    if (i>j) return false;
    else if (A[i] == i) return true;
    else return IndexEqualRecurs(A, i+1, j);
}

bool IndexEqualIter(const vector<int> &A, int i, int j) {
        while (i<=j) {
            if (A[i] == i) return true;
            i++;
        }
        return false;
}