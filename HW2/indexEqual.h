#include "header.h"

// global variables to count number of k and A[k] comparisons in each algorithm
extern int recursComps;
extern int iterComps;

/*
 * Function: indexEqualRecurs
 * Usage: indexEqual(arr, start range, end range);
 * ---------------------------------
 * This function returns true if there exists an index x (i <= x <= j)
 * such that arr[x] == value.
 * Assume A i sorted integer array in which every element is unique.
 * Done recursively.
 */
bool IndexEqualRecurs(const vector<int> &A, int i, int j);

/*
* Function: indexEqualIter
* Usage: indexEqual(arr, start range, end range);
* ---------------------------------
* This function returns true if there exists an index x (i <= x <= j)
* such that arr[x] == value.
* Assume A i sorted integer array in which every element is unique.
* Done iteratively.
*/
bool IndexEqualIter(const vector<int> &A, int i, int j);
