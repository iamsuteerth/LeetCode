/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/is-subsequence/
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int n, m;
    int memo[101][10001];
    bool solve(string &s, string&t, int i, int j){
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        if(i == n){
            return memo[i][j] = true;
        }
        if(j >= m){
            return memo[i][j] = false;
        }
        if(s[i] == t[j]){
            return memo[i][j] = true && solve(s, t, i + 1, j + 1);
        }
        return solve(s, t, i, j+1);
    }
    bool isSubsequence(string s, string t) {
        n = s.length();
        m = t.length();
        memset(memo, -1, sizeof(memo));
        return solve(s,t,0,0);
    }
};
