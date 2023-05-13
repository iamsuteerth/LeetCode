/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/valid-anagram/
 */
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length(), m = t.length();
        if(s.length() != t.length())
            return false;
        unordered_map<char,int> umap;
        // Count array can also be used here
        for(int i = 0 ; i < n ; i++){
            umap[s[i]]++;
        }
        for(int i = 0 ; i < m ; i++){
            if(umap.find(t[i]) != umap.end()){
                umap[t[i]]--;
            }
            else{
                return false;
            }
            if(umap[t[i]] == 0){
                umap.erase(t[i]);
            } 
        }
        return (umap.size() == 0);
    }
};
