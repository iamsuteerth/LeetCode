/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/house-robber/
 */
#include <iostream>
using namespace std;
class Solution {
public:
    int max(int a, int b){
        return (a > b) ? a : b;
    }
    // int memo[101];
    // int solve_memo(int idx, vector<int> &nums, int n){
    //     if(idx >= n)
    //         return 0;
    //     if(memo[idx] != -1)
    //         return memo[idx];
    //     int take = nums[idx] + solve(idx+2, nums, n);
    //     int skip = solve(idx+1, nums, n);
    //     return memo[idx] = max(take, skip);
    // }
    int rob(vector<int>& nums) {
        // memset(memo, -1, sizeof(memo)); // For memoization
        int n = nums.size();
        //return solve_memo(0, nums, nums.size());
    }
};
