/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/group-anagrams/
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> umap;
        vector<string> sorted;
        vector<vector<string>> res;
        for(int i = 0 ; i < n ; i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            sorted.push_back(temp);
        }

        for(int i = 0 ; i < n ; i++){
            umap[sorted[i]].push_back(strs[i]);
        }
        for(auto it = umap.begin(); it != umap.end() ; it = next(it)){
            res.push_back(it->second);
        }
        return res;
    }
};
