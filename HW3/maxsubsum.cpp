#include "maxsubsum.h"

// Constructor
MaxSubSum::MaxSubSum() {
    start = 0;
    end = 0;
}

// Sum of the integers between the start and end indices of the current MSS.
int MaxSubSum::Sum() const {
    int sum = 0;
    for (int i = start; i <= end; i++) {
        sum += MSSv[i];
    }

    return sum;
}

// Overloads << operator that allows a MaxSubSum instance to be printed using 'cout << mss'.
ostream& operator<<(ostream &os, const MaxSubSum &mss) {
 if (mss.start == mss.end) {
        // empty sequence
        os << "[]" << endl;
    }

    else {
        os << "[";
        for (int i = mss.start; i < mss.end; i++) {
            os << mss.MSSv[i] << ","; 
        }
        os << mss.MSSv[mss.end] << "] = " << mss.Sum();
    }

    return os;
}

// Inserts val into the vector at the given index
// Shifting the original elements starting at index to the right.
void MaxSubSum::Insert(int index, int val) {    
    // insert the new value
    // Update() not called:
        // New value inserted immediately before current MSS. 
        // New value inserted immediately after the current MSS. 
    MSSv.insert(MSSv.begin() + index, val);        

    // New value inserted at least one element before current MSS. 
    // New value inserted at least one element after current MSS. 
    if (index < start - 1 || index > end + 1) {
        // update only called if val > 0
        if (val > 0) {
            // update
            Update();
        }
    }

    // New value inserted inside current MSS. Update should be called only if value < 0.
    else if (index > start && index < end) {
        // update only called if val < 0
        if (val < 0) {
            Update();
        }
    }
}

// Recomputes the MSS for the entire vector.
int MaxSubSum::Update() {
    int maxSum = 0, sum = 0;

    for (int i = 0; i < MSSv.size(); i++) {
        sum += MSSv[i];
        if (sum > maxSum) {
            maxSum = sum;
            end = i; // ending index for MSS (so far)
        }
        else if (sum < 0) {
            maxSum = 0;
            start = i + 1; // new starting index for MSS
        }
    }

    return maxSum;  
}