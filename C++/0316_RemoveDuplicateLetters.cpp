/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/remove-duplicate-letters/
 */
#include <iostream>
#include <string>
#include <vector>
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last_occurrence(26, -1);
        vector<bool> used(26, false); 
        string result = "";
        
        for (int i = 0; i < s.length(); i++) {
            last_occurrence[s[i] - 'a'] = i;
        }
        for (int i = 0; i < s.length(); i++) {
            if (used[s[i] - 'a']) continue;
            while (!result.empty() && s[i] < result.back() && i < last_occurrence[result.back() - 'a']) {
                 used[result.back() - 'a'] = false;
                result.pop_back();
            }
            result += s[i];
            used[s[i] - 'a'] = true;
        }
        return result;
    }
};
