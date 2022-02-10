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
 if (mss.MSSv.empty()) {
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
    if (index > MSSv.size()) {
        //cout << "inserting with index > size" << endl;
        MSSv.push_back(val);
    }
    else {
        //cout << "inserting with index within range" << endl;
        MSSv.insert(MSSv.begin() + index, val);
    }

    // Update() not called:
    // New value inserted immediately before current MSS. 
    // New value inserted immediately after the current MSS. )
    if (index == start) {
        // new value pushes window to right, making it immediately before the start index
        if (val > 0) {
            start = index;
        }

        else {
            start = start + 1;
        }
        if (MSSv.size() > 1) {
            // if vector only has one element, end index is same as start index
            // which means no need to update end index
            end = end + 1;
        }
    }
    else if (index == end + 1) {
        if (val > 0) {
            end = index;
        }
    }

    // New value inserted at least one element before current MSS. 
    // New value inserted at least one element after current MSS. 
    else if(index < start - 1 || index > end + 1) {
        // update only called if val > 0
        if (val > 0) {
            Update();
        }
        if (index < start - 1) {
            // shifting to right, shift the MSS window to the right too
            start = start + 1;
            end = end + 1;
        }
    }

    // New value inserted inside current MSS. Update should be called only if value < 0.
    else if (index > start && index <= end) {
        // update only called if val < 0
        if (val < 0) {
            Update();
        }
    }

    cout << endl;
    cout << "curr arr: ";
    for (int i = 0; i < MSSv.size(); i++) {
        cout << MSSv[i] << " ";
    }
    cout << endl;
    cout << "start: " << start << " end: " << end << endl;

}

// Recomputes the MSS for the entire vector.
void MaxSubSum::Update() {
    int maxSum = 0, sum = 0;

    for (int i = 0; i < MSSv.size(); i++) {
        sum += MSSv[i];
        if (sum > maxSum) {
            maxSum = sum;
            end = i; // ending index for MSS
        }
        else if (sum < 0) {
            maxSum = 0;
            start = i + 1; // new starting index for MSS
        }
    }
}