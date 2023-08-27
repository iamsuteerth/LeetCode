/*
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/coin-change/
 */
#include <iostream>
#include <vector>
using namespace std;
// Brute Recursion w/o DP
/*
void solve(vector<int> &coins, int amount, int idx, int numCoins){
    if(amount <= 0 || idx < 0){
        if(amount == 0)
            res = min(res, numCoins);
        return;
    }
    solve(coins, amount - coins[idx], idx, numCoins + 1);
    solve(coins, amount, idx - 1, numCoins);
}
*/
class Solution {
public:
    int res;
    int n;
    int memo[13][10001];
    int solve(vector<int> &coins, int amount, int idx){
        if(idx < 0 || amount == 0)
            return (amount == 0) ? 0 : INT_MAX - 1;
        if(memo[idx][amount] != -1)
            return memo[idx][amount];
        if(coins[idx] <= amount){
            return memo[idx][amount] = min(solve(coins, amount, idx - 1), 1 + solve(coins, amount - coins[idx], idx));
        }
        else{
            return memo[idx][amount] = solve(coins, amount, idx - 1);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        res = INT_MAX;
        n = coins.size();
        memset(memo, -1, sizeof(memo));
        res = solve(coins, amount, n - 1);
        return (res == INT_MAX - 1) ? -1 : res;
    }
};
