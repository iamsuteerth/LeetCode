/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/decoded-string-at-index/
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    // void repeater(string &res, string rep, int n){
    //     while(n != 0){
    //         res += rep;
    //         n--;
    //     }
    // }
    string decodeAtIndex(string s, int k) {
        // Brute Force, Wont work at all for any test case
        // int j = 0;
        // string res = "";
        // while(j < s.length()){
        //     if(s[j] - '0' <= 9 && s[j] - '0' >= 1)
        //         break;
        //     res += s[j];
        //     j++;
        // }
        // for(int i = j ; i < s.length() ; i++){
        //     if(s[i] - '0' <= 9 && s[i] - '0' >= 0){
        //         repeater(res, res, s[i] - '0' - 1);
        //     }
        //     else{
        //         res += s[i];
        //     }
        //     // leetleetcode
        // }
        // ans += res[k-1];
        // return ans;

        // Calculating total string length
        int n = s.length();
        long long size = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] - '0' <= 9 && s[i] - '0' >= 0){
                size *= s[i] - '0';
            }
            else{
                size++;
            }
        }
        string ans = "";
        for(int i = n - 1 ; i >= 0 ; i--){
            k = k%size;
            // Calculating k for current size
            if(k == 0 && isalpha(s[i])){
                ans += s[i];
                return ans;
            }
            if(s[i] - '0' <= 9 && s[i] - '0' >= 0){
                size /= s[i] - '0';
            }
            else{
                size --;
            }
        }
        return "o";
    }
};
