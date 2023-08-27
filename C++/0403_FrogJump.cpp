/*
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/frog-jump/
 * HARD QUESTION
 */
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
// Plain Recursion
/*
bool solve(int idx, vector<int> &stones, int prev, unordered_map<int, int> &umap){
    if(idx == n - 1)
        return true;
    int res = false;
    for(int jump : {prev - 1, prev, prev + 1}){
        if(jump > 0){
            int nextPos = stones[idx] + jump;
            int nextIdx = (umap.find(nextPos) == umap.end()) ? idx : umap.find(nextPos)->second;
            if(nextIdx < n && stones[nextIdx] == nextPos){
                res = res || solve(nextIdx, stones, jump, umap);
            }
        }
    }
    return res;
}
 */
class Solution {
public:
    int n;
    unordered_map<int, int> umap;
    int memo[2000][2001]; // idx, prev
    
    bool solve(vector<int> &stones, int idx, int prev){
        if(idx == n - 1)
            return true;
        
        bool res = false;
        if(memo[idx][prev] != -1)
            return memo[idx][prev];
        
        for(int jump : {prev - 1, prev, prev + 1}){
            if(jump > 0){
                int nextPos = stones[idx] + jump;
                if(umap.find(nextPos) != umap.end()){
                    res = res || solve(stones, umap.find(nextPos)->second, jump);
                }
            }
        }
        return memo[idx][prev] = res;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1)
            return false;

        n = stones.size();
        memset(memo, -1, sizeof(memo));

        for(int i = 0 ; i < n ; i++){
            umap[stones[i]] = i;
        }

        return solve(stones, 0, 0);
    }
};
