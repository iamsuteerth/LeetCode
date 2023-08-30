/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/reverse-bits/
 */
#include <iostream>
using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i = 0 ; i < 32 ; i++){
            res <<= 1;
            res += (n & 1);
            n >>= 1;
        }
        return res;
    }
};
