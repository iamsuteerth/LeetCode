/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/product-of-array-except-self/
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int returner(vector<int> &arr, int i, int n){
        if(i < 0 || i >= n)   
            return 1;
        return arr[i];
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        vector<int> post(n);
        int prod = 1;
        for(int i = 0 ; i < n ; i++){
            prod *= nums[i];
            pre[i] = prod;
        }
        prod = 1;
        for(int i =  n - 1 ; i >= 0 ; i--){
            prod *= nums[i];
            post[i] = prod;
        }
        vector<int> res;
        for(int i = 0 ; i < n ; i++){
            res.push_back(returner(pre, i - 1, n) * returner(post, i + 1, n));
        }
        return res;
    }
};
