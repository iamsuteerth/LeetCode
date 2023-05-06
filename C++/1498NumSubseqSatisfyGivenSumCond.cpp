/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
 */
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int M = 1e9+7;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = n-1;
        vector<int> power(n);

        power[0] = 1;
        
        for(int i = 1; i<n; i++) {
            power[i] = (power[i-1] * 2) % M;
        }
        long long result = 0;
        while(l <= r){
            if(nums[l] + nums[r] <= target){
                result = (result % M + power[r-l]) % M;
                l++;
            }
            else{
                r--;
            }
        }
        return result;
    }
};
