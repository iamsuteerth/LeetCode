/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/
 * HARD QUESTION
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    typedef long long ll;
    ll mod = 1e9 + 7;
    vector<vector<ll>> pascalTriangle;
    ll solve(vector<int> &nums){
        int n = nums.size();
        if(n < 3)
            return (ll)1;
        vector<int> l_arr, r_arr;
        int root = nums[0];
        for(int i = 1 ; i < n ; i++){
            if(nums[i] < root)
                l_arr.push_back(nums[i]);
            else 
                r_arr.push_back(nums[i]);
        }
        ll x = solve(l_arr) % mod;
        ll y = solve(r_arr) % mod;
        ll z = pascalTriangle[n-1][l_arr.size()] % mod; // n-1 C l_arr.size()
        return (((x*y)% mod)*z)% mod;
    }
    
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        /* 
            if we have 4,5,1,2 THEN the relative order of RHS elements and LHS elements should be the same
            for n elements, we have n - 1 slots available where we have to put LHS number of elements 
            Now, RHS = 4,5 which is constructed dynamically and LHS = 1,2 which is again constructed dynamically
            now 4,5 and 1,2 should have the same relative order within itself, so n-1C2 is how they will be placed
        */
        pascalTriangle.resize(n+1, vector<ll>());
        for(int i = 0 ; i <= n ; i++){
            pascalTriangle[i] = vector<ll>(i+1, 1);
            for(int j = 1 ; j < i ; j++){
                pascalTriangle[i][j] = (pascalTriangle[i-1][j] + pascalTriangle[i-1][j-1]) % mod;
            }
        }
        return (solve(nums) - 1) % mod;
    }
};
