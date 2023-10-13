/*
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int dp[1001];
    int n;
    int solve(vector<int> &cost, int idx){
        if(idx >= n){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int take_one = cost[idx] + solve(cost, idx + 1);
        int take_two = cost[idx] + solve(cost, idx + 2);
        return dp[idx] = min(take_one, take_two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));
        n = cost.size();
        return min(solve(cost, 0), solve(cost, 1));
    }
};
