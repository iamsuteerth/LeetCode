/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/number-of-zero-filled-subarrays/
 */
#include <vector>
using namespace std;
class Solution {
public:
    long zeroFilledSubarray(vector<int>& nums) {
        long i=0,j=0;
        long size = nums.size();
        bool state = false;
        long res = 0;
        for( ; i < size ; i++){
            if(state){
                // While our zero subarray is going on, which is indicated by state == true, if we encounter a 0
                if(nums[i] != 0){
                    state = false;
                    res += ( ( (i - j) * (i - j + 1) ) / 2 );
                    j = i; // Updating j
                }
            }
            else{ // Non Zero subarray going on
                if(nums[i] == 0){
                    state = true; // Start of our zero contigous subarray
                    j = i;
                }
            }
        }
        // If we are at the end of the loop, we need to add that last subarrray as well
        if(state){
            res += ( ( (i - j) * (i - j + 1) ) / 2 );
        }
        return res;
    }
};