#pragma once

#include "header.h"

/*
Class that maintains the Maximum Subsequenece Sum (MSS)
of an array as you insert integers into the array.
*/
class MaxSubSum
{
public:
    MaxSubSum();
    
    // Returns: The sum of the integers between the start and end indices of the current MSS.
    // --This method should not call the Update method.--
    int Sum() const;

    // Overloads << operator that allows a MaxSubSum instance to be printed using 'cout << mss'.
    // An empty sequence should be output as '[]'.
    // Otherwise, the sequence should be output followed by the sum.
    // E.g., output as '[4,2,-3,5,8] = 16'.
    friend ostream &operator<<(ostream &os, const MaxSubSum &mss);

    // Inserts val into the vector at the given index, shifting the original elements starting at index to the right.
    // If given index is beyond end of vector, val should be inserted at end of vector.
    // Should be maximally-efficient in terms of only calling Update method when necessary.
        // 1. New value inserted at least one element before current MSS. Update called only if value > 0.
        // 2. New value inserted immediately before current MSS. Update to not be called.
        // 3. New value inserted immediately after the current MSS. Update to not be called.
        // 4. New value inserted at least one element after current MSS. Update called only if value > 0.
        // 5. New value inserted inside current MSS. Update should be called only if value < 0.
    void Insert(int index, int val);
    
private:
    // Recomputes the MSS for the entire vector
    // Should follow the MaxSubSum4 algorithm presented in class (see ReadME)
    // Modifications:
        // a. MSS4 does not handle case where MSS is negative, i.e., when vector consists of only
        //    negative integers and so the MSS is the highest negative number. Update should begin by iterating
        //    through any initial negative integers.
        // b. Once a positive integer is found, MSS4 algorithm can begin.
        //    Main change of this phase is the maintenance and update of the start and end indices as
        //    different subsequences are considred.
    int Update();

    // vector of integers
    vector<int> MSSv;
    // start index of current MSS
    int start;
    // end index of current MSS
    int end;
};