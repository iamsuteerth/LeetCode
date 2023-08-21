/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/house-robber-ii/
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int memo[101];
    int solve(int idx, vector<int> &nums, int n){
        if(idx >= n)
            return 0;
        if(memo[idx] != -1)
            return memo[idx];
        int take = nums[idx] + solve(idx+2, nums, n);
        int skip = solve(idx+1, nums, n);
        return memo[idx] = max(take, skip);
    }
    int bottum(vector<int> &nums){
        int n = nums.size();
        if(n == 1)
            return nums[0];
        vector<int> t(n+1, 0);
        int not_take = 0, take = 0;

        t[1] = nums[0]; // 0 house taken

        for(int i = 1 ; i <= n - 1 ; i++){
            t[i] = max(t[i - 1], nums[i - 1]+ ((i - 2 >= 0) ? t[i - 2] : 0));
        }
        take =  t[n - 1];
        t.clear();
        t[0] = 0;
        t[1] = 0;
        for(int i = 2 ; i <= n ; i++){
            t[i] = max(t[i - 1] , nums[i - 1]+ ((i - 2 >= 0) ? t[i - 2] : 0));
        }
        not_take = t[n];
        return max(take, not_take);
    }
    int rob(vector<int>& nums) {
        // int n = nums.size();
        // if(n == 1)
        //     return nums[0];
        // if(n == 2)
        //     return max(nums[0], nums[1]);
        // memset(memo, -1, sizeof(memo));
        // int take = solve(0, nums, n - 1);

        // memset(memo, -1, sizeof(memo));
        // int skip = solve(1, nums, n);

        // return max(take, skip);
        return bottum(nums);
    }
};
