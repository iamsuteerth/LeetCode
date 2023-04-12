/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/removing-stars-from-a-string/
 */
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    string removeStars(string s) {
        stack<char> S;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            char curr = s[i];
            if(curr != '*'){
                S.push(s[i]);
            }
            else{
                S.pop();
            }
        }
        string res = "";
        while(!S.empty()){
            res += S.top();
            S.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
