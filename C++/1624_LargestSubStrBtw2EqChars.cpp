/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/largest-substring-between-two-equal-characters/
 */
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> umap;
        int res = -1;
        for(int i = 0 ; i < s.length() ; i++){
            if(umap.find(s[i]) == umap.end()){
                umap[s[i]] = i;
            }
            else{
                res = max(res, i - umap[s[i]] - 1);
            }
        }
        return res;
    }
};
