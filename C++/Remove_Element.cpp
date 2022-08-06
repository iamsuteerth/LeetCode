#include<iostream>
#include<vector>
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        // j is the control variable
        for(int i = 0; i< nums.size() ; i++){
            if(nums[i]!=val){ // We iterate through the vector and if the corresponding index value in the array is not equal to our provided target
                nums[j]=nums[i]; // We simple put that element in j index (starting from 0) and increment it
                j++;
            }
        }
        return j;
    }
};