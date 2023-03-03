/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
 * Standard string matching problem
 */
#include <string>
using namespace std;
// Brute Force Method
class Solution {
public:
    bool status = false;
    int strStr(string haystack, string needle) {
        for(int i = 0 ; i < haystack.length() ; i++){
            for(int j = 0 ; j < needle.length(); j++){
                if(haystack[i+j] == needle[j]){
                    status = true;
                    continue;
                }
                else{
                    status = false;
                    break;
                }
            }
            if(status){
                return i;
            }
        }
        return -1;
    }
};