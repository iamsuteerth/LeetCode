/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/maximum-length-of-pair-chain/
 */
#include <iostream>
#include <vector>
class Solution {
public:
    int n;
    int memo[1001];
    int solve(int i, vector<vector<int>> &pairs){
        if(i >= n)
            return 0;
        if(memo[i] != -1)
            return memo[i];
        // Not Take
        int not_take = solve(i+1, pairs);
        // Take
        int take = 1;
        for(int j = i + 1 ; j < n ; j++){
            // Check if we can take next or the ones after that
            // Break loop if we can and call function there
            if(pairs[i][1] < pairs[j][0]){
                take = 1 + solve(j, pairs);
                break;
            }
        }
        memo[i] = max(take, not_take);
        return memo[i];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        n = pairs.size();
        sort(pairs.begin(), pairs.end());
        memset(memo, -1, sizeof(memo));
        return solve(0, pairs);
    }
};
