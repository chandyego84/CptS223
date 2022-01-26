#include "indexEqual.h"

int recursCounter = 0;
int iterCounter = 0;
int recursComps = 0;
int iterComps = 0;

bool IndexEqualRecurs(const vector<int> &A, int i, int j) {
    // using binary search for log(n) efficiency
    if (i <= j) {
        int mid = (i + j) / 2;
        if (A[mid] == mid) {
            recursCounter++;
            recursComps++; 
            return true;
        }
        else if (A[mid] < mid) {
            recursCounter += 2;
            recursComps += 2;
            return IndexEqualRecurs(A, mid+1, j);
        }
        else {
            recursCounter += 3;
            recursComps += 3;
            return IndexEqualRecurs(A, i, mid-1);
        }
    }
    else {
        return false;
    }
}

bool IndexEqualIter(const vector<int> &A, int i, int j) {
    // o(n) efficiency
        while (i<=j) {
            iterCounter++;
            iterComps++;
            if (A[i] == i) {
                return true;
            }
            i++;
        }
        return false;
}