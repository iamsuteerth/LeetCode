/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/monotonic-array/
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool testForDecreasing(vector<int> &nums, int start, int n){
      for(int i = start + 1 ; i < n ; i++){
        if(nums[i] <= nums[i - 1]){
          continue;
        }
        else{
          return false;
        }
      }
      return true;
    }
    bool testForIncreasing(vector<int> &nums, int start, int n){
      for(int i = start + 1 ; i < n ; i++){
        if(nums[i] >= nums[i - 1]){
          continue;
        }
        else{
           return false;
        }
      }
      return true;
    }
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2){
          return true;
        }
        for(int i = 1 ; i < nums.size() ; i++){
          if(nums[i] < nums[i - 1]){
            return testForDecreasing(nums, i, n);
          }
          else if(nums[i] > nums[i - 1]){
            return testForIncreasing(nums, i, n);
          }
          else{
            continue;
          }
        }
        return true;
    }
};
