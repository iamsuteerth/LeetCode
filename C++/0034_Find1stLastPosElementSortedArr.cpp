 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 */
#include <iostream>
#include <vector>
class Solution {
public:
    int binSearch(vector<int> &nums, int target, int left, int right, bool is_left){
        int idx = -1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] < target){
                left = mid + 1;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
            else{
                idx = mid;
                if(is_left)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return idx;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        vector<int> result = {binSearch(nums, target, left, right, true), binSearch(nums, target, left, right, false)};
        return result;
    }
};
