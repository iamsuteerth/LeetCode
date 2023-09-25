/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/find-the-difference/
 */
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
        // Method 1 TC - O(n) SC - O(n)
        unordered_map<char, int> umap;
        for(char &c : t){
            umap[c]++;
        }
        for(char &c : s){
            if(umap.find(c) != umap.end()){
                auto it = umap.find(c);
                umap[c]--;
                if(umap[c] == 0){
                    umap.erase(it);
                }
            }
        }
        return umap.begin()->first;
        // Method 2 - Optimal - TC - O(n) SC - O(1)
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // int n = s.length();
        // int m = t.length();
        // for(int i = 0 ; i < n ; i++){
        //    if(s[i] != t[i])
        //         return t[i];
        // }
        // return t[m - 1];
    }
};

