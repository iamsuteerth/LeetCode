/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/count-subarrays-with-fixed-bounds/
 * HARD QUESTION
 */
#include <vector>
using namespace std;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
       int minIndex = -1;
       int maxIndex = -1;
       int culpritIndex = -1;
       long long res = 0, temp;
       for(int i = 0 ; i < nums.size() ; i++){
           if(nums[i] < minK || nums[i] > maxK){
               culpritIndex = i;
           }
           if(nums[i] == minK){
               minIndex = i;
           }
           if(nums[i] == maxK){
               maxIndex = i;
           }
           temp = min(minIndex, maxIndex) - culpritIndex;
           res += (temp < 0) ? 0 : temp;
       }
       return res;
    }
};