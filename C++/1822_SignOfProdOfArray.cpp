/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/sign-of-the-product-of-an-array/
 */
#incude <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count = 0;
        for(int &i : nums){
            if(i < 0){
                count++;
            }
            if(i == 0){
                return 0;
            }
        }
        return (count%2 == 0) ? 1 : -1;
    }
};
