/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int left = 0, right = grid.size() - 1, mid,res=0;
        for(int i = 0 ; i < grid.size() ; i++){
            left = 0, right =  grid[i].size();
            while(left < right){
                mid = (left + right)/2;
                if(grid[i][mid] >= 0){
                    left = mid + 1;
                }
                else{
                    right = mid;
                }
            }
            res += grid[i].size() - left;
        }
        return res;
    }
};
