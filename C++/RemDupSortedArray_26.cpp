#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1){
            return 1;
        } // Obvious 
        int k=0;
        int size = nums.size();
        int temp[size]; // Temporary array to store unique elements
        for (int i = 0 ; i < size - 1 ; i++){
            if(nums[i]!=nums[i+1]){
                temp[k]=nums[i]; //If its a duplicate, we won't increase k and move forward with the loop
                k++;
            }
        }
        temp[k++] = nums[size-1]; // To store the last element 

        for (int i = 0 ; i < k ; i++){
            nums[i]=temp[i]; //Changing the elements in nums since that's what the problem will read
        }
        return k;
    }
};