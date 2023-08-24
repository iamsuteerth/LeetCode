/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/excel-sheet-column-title/
 */
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string recursive(string &res, int num){
        if(num == 0)
            return res;
        res = char((--num % 26) + 'A') + res;
        return recursive(res, num/26);
    }
    string convertToTitle(int columnNumber) {
        // Consider HexaDecimal system. Here it is a IsocoHexaDecimal system
        string res = "";
        int i = 1;
        // Since A = 1 and NOT 0, we are subtracting colnum 
        // To get Z by adding 25 to A
        // To handle cases where remainder is 0 and we end up pushing @
        // Essentially making 0 as A
        // while(columnNumber != 0){
        //     char c = char((columnNumber-- % 26) + 'A');
        //     res = c + res;
        //     columnNumber /= 26;
        // }
        // return res;
        return recursive(res, columnNumber);
    }
};
