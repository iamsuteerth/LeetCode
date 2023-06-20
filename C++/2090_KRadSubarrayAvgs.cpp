/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/k-radius-subarray-averages/
 */
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size(); 
        if(k == 0)
            return nums;

        vector<int> res(n, -1);
        int size = 2*k + 1;

        if(n < size)
            return res;
        long long sum = 0, i = 0;

        for( ; i < size ; i++){
            sum += nums[i];    
        }
        res[k] = sum/size;

        int left = 0;
        int right = size;
        i = k+1;

        while(right < n){
            sum = sum - nums[left] + nums[right];
            res[i] = sum/size;
            left++;
            right++;
            i++;
        }
        return res;
    }
};
