/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/combination-sum-iv/
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int n;
    int memo[1001][1001];
    int solve(vector<int> &nums, int idx, int target){
        if(target == 0)
            return 1;
        if(idx >= n || target < 0)
            return 0;
        if(memo[idx][target] != -1)
            return memo[idx][target];
        int res = 0;
        int take = solve(nums, 0, target - nums[idx]);
        int not_take = solve(nums, idx + 1, target);
        return memo[idx][target] = take + not_take;
    }
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        memset(memo, -1, sizeof(memo));
        return solve(nums, 0, target);
    }
};
