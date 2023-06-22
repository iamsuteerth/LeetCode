/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/merge-strings-alternately/
 */
#include <string>
#include <iostream>
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        string res = "";
        int i = 0;
        int min = (l1 < l2) ? l1 : l2;
        while(i < min){
            res = res + word1[i] + word2[i];
            i++;
        }
        if(l1 < l2){
            while(i < l2)
                res += word2[i++];
        }
        else{
            while(i < l1)
                res += word1[i++];
        }
        return res;
    }
};
