/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/buddy-strings/
 */
#include <iostream>
#include <string>
#include <unordered_map>
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.length(), m = goal.length();
        if(n != m)
            return false;
        if(n == 0 && m == 0)
            return true;
        unordered_map<char, vector<int>> umap;
        int mismatch_count = 0, first_mismatch_index = -1, second_mismatch_index = -1; 
        for(int i = 0 ; i < n ; i++){
            umap[goal[i]].push_back(i);
        }
        for(int i = 0 ; i < n ; i++){
            if(umap.find(s[i]) == umap.end()){
                return false;
            }
            if(s[i] == goal[i])
                continue;
            else{
                mismatch_count++;
                if(mismatch_count > 2)
                    return false;
                if (mismatch_count == 1)
                    first_mismatch_index = i;
                else
                    second_mismatch_index = i;
            }
        }
        if(mismatch_count == 0){
            for(const auto &u : umap){
                if(u.second.size() >= 2){
                    return true;
                }
            }
        } // When string is same, if any character frequency is greater than 2
        if (mismatch_count == 2 && 
            s[first_mismatch_index] == goal[second_mismatch_index] &&
            s[second_mismatch_index] == goal[first_mismatch_index]) 
        {
            return true;
        }
        return false;
    }
};
