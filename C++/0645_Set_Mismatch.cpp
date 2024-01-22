/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/set-mismatch/
 */
#include <vector>
#include <iostream>
uisng namespace std;
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n+1, 0);
        for(int &i : nums){
            count[i]++;
        }
        int a, b;
        for(int i = 1 ; i <= n ; i++){
            if(count[i] == 0){
                b = i;
            }
            if(count[i] == 2){
                a = i;
            }
        }
        vector<int> ans;
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};
