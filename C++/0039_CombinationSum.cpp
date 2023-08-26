/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/combination-sum/
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void solve(int i, vector<int> &candidates, vector<int> &current, vector<vector<int>> &result, int &target, int sum){
        if(i >= candidates.size()){
            return;
        }
        if(sum >= target){
            if(sum == target){
                result.push_back(current);
            }
            return;
        }
        // Take
        current.push_back(candidates[i]);
        solve(i, candidates, current, result, target, sum + candidates[i]);
        // Not Take
        current.pop_back();
        solve(i + 1, candidates, current, result, target, sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> result;
        solve(0, candidates, current, result, target, 0);
        return result;
    }
};
