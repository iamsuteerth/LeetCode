/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/sort-array-by-parity/
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int emplacer = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] % 2 == 0){
                swap(nums[i], nums[emplacer++]);
            }
        }
        return nums;
    }
};
