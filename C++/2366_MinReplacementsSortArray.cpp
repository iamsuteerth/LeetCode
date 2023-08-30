/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/container-with-most-water/
 * HARD QUESTION
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        // 1. 12 -> 5,7 -> 3, 4, 5 i.e. 2 Operations or Parts - 1
        // 2. 1,2,11,3 : 11 should be broken
        // Number of parts = 11/3 + 1 = 4
        // Change nums[i] as nums[i] / parts which will give 11 -> 2,2,2,3 -> 2,2,2 ...
        for(int i = n - 2 ; i >= 0 ; i--){
            if(nums[i] <= nums[i + 1])
                continue;
            int parts = nums[i]/nums[i + 1];
            if(nums[i] % nums[i + 1] != 0)
                parts++;
            res += parts - 1;
            nums[i] = nums[i]/parts;
        }
        return res;
    }
};
