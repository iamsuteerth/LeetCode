/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/
 */
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    double average(vector<int>& salary) {
        int max = INT_MIN, min = INT_MAX, sum = 0, n = salary.size();
        for(int &s : salary){
            if(s >= max){
                max = s;
            }
            if(s <= min){
                min = s;
            }
            sum += s;
        }
        return sum <= 0 ? 0 : (double)((double)(sum - (min + max))/(double)(n - 2));
    }
};
