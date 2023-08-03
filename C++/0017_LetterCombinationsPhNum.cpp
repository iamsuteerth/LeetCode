/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    unordered_map<char, vector<char>> uset;
    vector<string> ans;
    int N;
    void solve(string &digits, string &current, int index){
        if(index >= N || current.length() == N){
            if(current.length() == N)
                ans.push_back(current); 
            return;
        }  
        vector<char> present = uset[digits[index]];;
        for(char &c : present){
            current += c;
            solve(digits,current, index+1);
            current = current.substr(0, current.length() - 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        uset['2'] = {'a', 'b', 'c'};
        uset['3'] = {'d', 'e', 'f'};
        uset['4'] = {'g', 'h', 'i'};
        uset['5'] = {'j', 'k', 'l'};
        uset['6'] = {'m', 'n', 'o'};
        uset['7'] = {'p', 'q', 'r', 's'};
        uset['8'] = {'t', 'u', 'v'};
        uset['9'] = {'w', 'x', 'y', 'z'};
        N = digits.length();
        if (N == 0)
            return {};
        string current = "";
        solve(digits, current, 0);
        return ans;
    }
};
