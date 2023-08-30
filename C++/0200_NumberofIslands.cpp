/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/number-of-islands/
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int m;
    int n;
    void dfs(vector<vector<char>> &grid, int r, int c){
        if(r < 0 || r >= m || c < 0 || c >= n){
            return;
        }
        if(grid[r][c] == '0')
            return;
        grid[r][c] = '0';
        dfs(grid, r, c-1);
        dfs(grid, r, c+1);
        dfs(grid, r-1, c);
        dfs(grid, r+1, c);
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int res = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == '1') {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};
