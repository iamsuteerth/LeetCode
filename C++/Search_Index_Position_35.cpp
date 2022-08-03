#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    int i; 
    // nums.size() is a function of the class vector which returns an integer corresponding to number of elements filled in the vector 
    for (i = 0 ; i < nums.size() ; i++)
    {
        if (nums[i]>=target) // If the element in vector is = target, we return the index
        {
        // Otherwise, if the element is greater than the target, we need to insert the element at that position 
            return i;
        }
        // In case, there's no match, because i++ is still incremented before for loop condition check, returning I means that the target should be inserted at the end 
    }
    return (i);
}
};
