/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> left(nums.size(), 0);
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i-1] == 1){
                left[i] = left[i-1] + 1;
            }
        }
        vector<int> right(nums.size(), 0);
        for(int i = nums.size() - 2 ; i >= 0 ; i--){
            if(nums[i+1] == 1){
                right[i] = right[i+1] + 1; 
            }
        }
        int res = 0;
        for(int i = 0; i < nums.size() ; i++){
            res = max(res, left[i] + right[i]);
        }
        // for(int &i : left)
        //     cout << i;
        // cout << endl;
        // for(int &i : right)
        //         cout << i;
        return res;
    }
};
