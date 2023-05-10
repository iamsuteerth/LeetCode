/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/spiral-matrix-ii/
 * Modifying code of https://leetcode.com/problems/spiral-matrix/ makes this very easy!
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n,vector<int>(n));
        int top   = 0;
        int down  = n-1;
        int left  = 0;
        int right = n-1;
        int id = 0;
        //id
        //0   -> left  to right
        //1   -> top   to down
        //2   -> right to left
        //3   -> down  to top
        int val = 0;
        while(top <= down && left <= right) {
            //left to right
            if(id == 0) {
                for(int i = left; i<=right; i++) {
                    mat[top][i] = ++val;
                }
                top++;
            }
            
            //top to down
            if(id == 1) {
                for(int i = top; i<=down; i++) {
                    mat[i][right] = ++val;
                }
                right--;
            }
            
            //right to left
            if(id == 2) {
                for(int i = right; i>=left; i--) {
                    mat[down][i] = ++val;
                }
                down--;
            }
            
            //down to top
            if(id == 3) {
                for(int i = down; i>=top; i--) {
                    mat[i][left] = ++val;
                }
                left++;
            }
            
            id = (id+1)%4;
        }
        return mat;
    }
};
