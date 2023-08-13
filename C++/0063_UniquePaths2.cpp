/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/unique-paths-ii/
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int m, n;
    // Classic DP problem
    int memo[101][101];
    int solve(int x, int y, vector<vector<int>> &grid){
        if(x >= m || y >= n) // Ignore if out of bounds
            return 0;
        if(grid[x][y] == 1) // Ignore if it is a wall
            return 0;
        if(x == m - 1 && y == n - 1){
            return 1; // Reached end of grid
        }
        if(memo[x][y] != -1)
            return memo[x][y];
        return memo[x][y] = solve(x+1, y, grid) + solve(x, y+1, grid); // Check for right and down
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        memset(memo, -1, sizeof(memo));
        return solve(0,0,obstacleGrid);
    }
};
