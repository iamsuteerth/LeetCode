/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // Similar to 33. Search in Rotated Sorted Array
    int findMin(vector<int>& nums) {
        int pivot;
        int left = 0, right = nums.size() - 1;
        int mid;
        while(left < right){
            mid = (left + right) / 2;
            if(nums[mid] > nums[right]){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        pivot = left;
        return nums[(pivot)%nums.size()];
    }
};
