/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/word-break/
 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int N;
    unordered_set<string> uset;
    int memo[301];
    bool solve(int index, string &s){
        if(index >= N){
            return memo[index] = true; 
            // if index is increasing, that means all parts were true
        }
        if(memo[index] != -1)
            return memo[index];
        if(uset.find(s) != uset.end())
            return memo[index] = true;
        for(int i = 1 ; i <= N ; i++){
            // Breaking the string one by one
            string temp = s.substr(index, i);
            if( uset.find(temp) != uset.end() && solve(index + i, s) ){
                return memo[index] = true;
            }
        }
        return memo[index] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        N = s.length();
        memset(memo, -1, sizeof(memo)); // Direct initialization
        for(string &str : wordDict)
            uset.insert(str);
        return solve(0, s);
    }
};
