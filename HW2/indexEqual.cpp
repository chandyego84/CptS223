#include "indexEqual.h"

/*
 * Function: indexEqual
 * Usage: indexEqual(arr, start range, end range);
 * ---------------------------------
 * This function returns true if there exists an index x (i <= x <= j)
 * such that arr[x] == value.
 * Assume A i sorted integer array in which every element is unique.
 */
bool IndexEqualRecurs(const vector<int> &A, int i, int j) {
    if (i>j) return false;
    else if (A[i] == A[j]) return true;
    else return IndexEqualRecurs(A, i+1, j);
}