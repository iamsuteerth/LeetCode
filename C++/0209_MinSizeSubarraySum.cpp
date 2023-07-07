/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/minimum-size-subarray-sum/
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int minSubArrayLenNlogN(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int i = 0, j = 0, sum = 0;
        while(j < nums.size()){
            sum += nums[j];
            while(sum >= target){
                ans = min(ans, j-i+1);
                sum -= nums[i++];
            }
            j++;
        }
        return (ans == INT_MAX) ? 0 : ans;
    }
};
