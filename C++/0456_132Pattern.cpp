/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/132-pattern/
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // Brute force - 3 for loops i,j,k
        // Slightly better - 2 for loops
        // We cant sort, so best solution is O(n)
        /*
         num_i = nums[0]
         for(int j = 1 ; j < n - 1 ; j++){
             num_i = min(min_i, nums[j]);
             for(int k = j + 1 ; k < n ; k++){
                 if(num_i < nums[k] && nums[k] < nums[j]){
                     return true;
                 }
             }
         }
        return false;
         */
        // Optimal solution
        // Stack hint : i = 0, i < n, i++ and j = i + 1 and so on
        // When a for loop is dependent on another
        // num1, num3, num2 -> Largest is num2
        // We will traverse in opposite direction, so we get largest index first
        int n = nums.size();
        stack<int> s;
        int num1, num2 = INT_MIN, num3 = INT_MIN;
        for(int i = n - 1 ; i >= 0 ; i--){
            if(nums[i] < num3){
                return true;
            }
            while(!s.empty() && s.top() < nums[i]){
                num3 = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};
