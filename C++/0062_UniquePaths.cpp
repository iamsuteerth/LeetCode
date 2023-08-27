/*
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/unique-paths/
 */
#include <iostream>
using namespace std;
class Solution {
public:
    int memo[100][100];
    int solve(int x, int y, int m, int n){
        if(x == m - 1 && y == n - 1)
            return 1;
        if(x < 0 || x >= m || y < 0 || y >= n)
            return 0;
        if(memo[x][y] != -1)
            return memo[x][y];
        return memo[x][y] = solve(x + 1, y, m, n) + solve(x, y + 1, m, n);
    }
    int uniquePaths(int m, int n) {
        memset(memo, -1, sizeof(memo));
        return solve(0, 0, m, n);
    }
};
