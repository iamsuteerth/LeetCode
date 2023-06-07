/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
 */
#include <iostream>
using namespace std;
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int result = 0;
        
        while( a != 0 || b != 0 || c != 0) {
            
            if( (c & 1) == 1) {
                if((a & 1) == 0 && (b & 1) == 0) {
                    result++;
                }
            } else {
                result += (a & 1) + (b & 1);
            }
            
            a >>= 1;
            b >>= 1;
            c >>= 1;
            
        }
        
        return result;
    }
};
