/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/combinations/
 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int n;
    int dp[301][5001];
    // Simple Lete Rahenge ya nahi lenge 
    // We have only one order of solution which is 1,1,1,2 NOT 1,2,1,1
    // All the same denominations are taken in ONCE succession
    int solve(int i, int remaining, vector<int>& coins){
        if(remaining == 0)
            return 1;
        if(i == n || remaining < 0)
            return 0;
        if(dp[i][remaining] != -1)
            return dp[i][remaining];
        int take = solve(i, remaining - coins[i], coins);
        int skip = solve(i+1, remaining, coins);
        return dp[i][remaining] = take + skip;
    }
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, amount, coins);
    }
};
