/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/search-a-2d-matrix/
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int start = 0;
        int end   = m*n-1;
        
        while(start <= end) {
            int mid = start + (end-start)/2;
            int row = mid/n;
            int col = mid%n;
            
            if(matrix[row][col] > target) {
                end = mid-1;
            } else if(matrix[row][col] < target) {
                start = mid+1;
            } else {
                return true;
            }
        }
        return false;
        
    }
};