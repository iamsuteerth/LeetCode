/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // Longest subarry
        // <left, sum - x, right>
        // left + right = x
        // Ans = n - (sum-x).length
        int sum = 0, n = nums.size();
        unordered_map<int, int> umap;
        umap[0] = -1;
        // for edge case 1,1,4 and target = 6
        // Since zero is not there in map
        // so length = i - (-1) => length = 3
        for(int i = 0 ; i < n ; i++){   
            sum += nums[i];
            umap[sum] = i;
        }
        if(sum < x)
            return -1;
        int target = sum - x;
        int longestSubArray = INT_MIN;
        sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            int findSum = sum - target;
            if(umap.find(findSum) != umap.end()){
                longestSubArray = max(longestSubArray, i - umap[findSum]);
            }
        }
        return (longestSubArray < 0) ? -1 : n - longestSubArray;
    }
};
