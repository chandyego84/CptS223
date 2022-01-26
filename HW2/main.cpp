#include "indexEqual.h"

int main() {
    vector<int> A;
    

    cout << "Recursive Index Equal: " << IndexEqualRecurs(A, 0, 99) << endl;
    cout << "Iterative Index Equal: " << IndexEqualIter(A, 0, 99) << endl;

    return 0;
}