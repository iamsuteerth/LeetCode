/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/check-if-it-is-a-straight-line/
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        if(arr.size() <= 2)
            return true;
        int diff = arr[1] - arr[0];
        for(int i = 1 ; i < arr.size() - 1 ; i++){
            if(diff == (arr[i+1] - arr[i]))
                continue;
            else
                return false;
        }
        return true;
    }
};
