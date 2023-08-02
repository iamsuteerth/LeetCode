/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/permutations/
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    int N;
    void solve(int start, vector<int> &nums){
        if(start == N - 1){
            ans.push_back(nums);
            return;
        }
        for(int i = start ; i < N ; i++){
            swap(nums[i], nums[start]);
            solve(start + 1, nums);
            swap(nums[i], nums[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        N = nums.size();
        solve(0, nums);
        return ans;
    }
};
      
