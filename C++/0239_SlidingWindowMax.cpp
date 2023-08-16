/*
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/sliding-window-maximum/
 * HARD QUESTION
 */
#include <vector>
#include <iostream>
#include <deque>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();
        if(k > n || n == 0)
            return {};
        
        vector<int> res;
        deque<int> dequ;
         // Deq will be monotically increasing towards front
        for(int i = 0 ; i < n ; i++){
            // Size check : For i, check if the front element index is present in sliding window
            while(!dequ.empty() && dequ.front() <= i - k)
                dequ.pop_front();
            // Remove all smaller elements compared to present element from the dequeue
            while(!dequ.empty() && nums[i] > nums[dequ.back()])
                dequ.pop_back();
            // Push into back
            dequ.push_back(i);
            // The front will always have the largest element, so push the frontal index element
            if(i >= k - 1)
                res.push_back(nums[dequ.front()]);
        }
        return res;
    }
};
