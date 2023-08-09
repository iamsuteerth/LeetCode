/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/search-in-rotated-sorted-array/
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int BinSearch(vector<int>& nums, int left, int right, int target){
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target){
                left = mid + 1;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
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
        int res;
        res = BinSearch(nums, 0, pivot - 1, target);
        if(res != -1)
            return res;
        return BinSearch(nums, pivot, nums.size() - 1, target);
    }
};
