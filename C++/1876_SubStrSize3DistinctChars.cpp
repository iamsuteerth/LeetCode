/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/
 */
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.length();
        int count = 0;
        if(n >= 3){
            for(int i = 0 ; i < n - 2 ; i++){
                if(s[i] != s[i+1] && s[i] != s[i+2] && s[i+1] != s[i+2]){
                    count++;
                }
            }
        }
        return count;
    }
};
