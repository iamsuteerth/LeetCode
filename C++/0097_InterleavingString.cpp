/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/interleaving-string/
 */
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int l1;
    int l2;
    int N;
    // int memo[101][101][201]; // 3D DP -1 Not solved, 0 is F, 1 is T
    int t[101][101]; // 2D DP Optimized
    bool solve_2d(string &s1, string &s2, string &s3, int i, int j){
        if(i == l1 && j == l2 && N == (i + j))  
            return true;
        if((i+j) == N)
            return false;
        if(t[i][j] != -1)
            return t[i][j];
        bool res = false;
        if(s1[i] == s3[i+j])
            res = solve_2d(s1, s2, s3, i+1, j);
        if(res)
            return t[i][j] = true;
        if(s2[j] == s3[i+j])
            res = solve_2d(s1, s2, s3, i, j+1);
        return t[i][j] = res;    
    }
    // bool solve(string &s1, string &s2, string &s3, int i, int j, int k){
    //     if(i == l1 && j == l2 && k == N)
    //         return true;
    //     if(k == N)
    //         return false;
    //     if(memo[i][j][k] != -1)
    //         return memo[i][j][k];
    //     bool res = false;
    //     if(s1[i] == s3[k])
    //         res = solve(s1, s2, s3, i+1, j, k+1);
    //     if(res)
    //         return memo[i][j][k] = true;
    //     if(s2[j] == s3[k])
    //         res = solve(s1, s2, s3, i, j+1, k+1);
    //     return memo[i][j][k] = res;    
    // }
    bool isInterleave(string s1, string s2, string s3) {
        l1 = s1.length();
        l2 = s2.length();
        N = s3.length();

        if(l1+l2 != N)
            return false;

        // memset(memo, -1, sizeof(memo));
        memset(t, -1, sizeof(t));
        // return solve(s1,s2,s3,0,0,0);
        return solve_2d(s1,s2,s3,0,0);
    }
};
