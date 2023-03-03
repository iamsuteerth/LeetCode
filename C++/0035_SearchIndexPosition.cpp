/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/search-insert-position/
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size();
        if (nums[right - 1] < target)
            return right;
        int mid;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (target > nums[mid])
            {
                left = mid + 1;
            }
            if (target < nums[mid])
            {
                right = mid - 1;
            }
        }
        return left;
    }
};
