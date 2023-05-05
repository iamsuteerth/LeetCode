/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
 */
#include <iostream>
#include <string>
#include <unordered_map>
class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        unordered_map<char,int> umap;
        umap['a']++;
        umap['e']++;
        umap['i']++;
        umap['o']++;
        umap['u']++;
        int count = 0;
        int maxV = 0;
        int i = 0, j = 0;
        while(j < n){
            if(umap.find(s[j]) != umap.end())
                count++;
            if(j-i+1 == k) {
                maxV = max(maxV, count);
                if(umap.find(s[i]) != umap.end())
                    count--;
                i++;
            }
            j++;
        }
        return maxV;
    }
};
