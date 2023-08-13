/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int n;
    int memo[100001];
    bool solve(int i, vector<int> &nums){
        if(i >= n)   
            return true; // We have checked all indices

        bool res = false;

        if(memo[i] != -1)
            return memo[i]; // No need to solve if subproblem already solved

        if((i+1 < n) && nums[i] == nums[i+1]) // Rule 1
            res |= solve(i+2, nums); // Result = Result OR func. 
        
        if(res == true)
            return true; // If rule 1 is true, why bother trying rule 2
        
        if((i+2 < n) && nums[i] == nums[i+1] && nums[i+1] == nums[i+2]) // Rule 2
            res |= solve(i+3, nums);

        if(res == true)
            return true; // If rule 2 is true, why bother trying rule 3
        
        if((i+2 < n) && nums[i] - nums[i+1] == -1 && nums[i+1] - nums[i+2] == -1) // Rule 3
            res |= solve(i+3, nums);

        return memo[i] = res;

    }
    bool validPartition(vector<int>& nums) {
        n = nums.size();
        memset(memo, -1, sizeof(memo));
        return solve(0, nums);
    }
};
