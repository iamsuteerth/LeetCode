/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/container-with-most-water/
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int left = 0;
        int right = height.size() - 1;
        int curr;
        while(left < right){
        curr =  min(height[left], height[right]) * (right - left);
            if(curr > area)
                area = curr;
            if(height[right] < height[left])
                right--;
            else
                left++;
            // else if (height[right] >= height[left]) can be avoided as both can be covered by this else stmt.
        }   
        return area;
    }
};
