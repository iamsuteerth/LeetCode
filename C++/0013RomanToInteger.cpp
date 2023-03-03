/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/roman-to-integer/
 */
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    int charToValue(char c)
    {
        // Self explanatory switch control structure
        switch (c)
        {
        case 'I':
            return 1;
            break;
        case 'V':
            return 5;
            break;
        case 'X':
            return 10;
            break;
        case 'L':
            return 50;
            break;
        case 'C':
            return 100;
            break;
        case 'D':
            return 500;
            break;
        case 'M':
            return 1000;
            break;
        default:
            return (-1);
            break;
        }
    }
    int romanToInt(string s)
    {
        int ans = 0;
        int symbol_1, symbol_2;
        for (int i = 0; i < s.length(); i++)
        {                                 // We iterate through the string
            symbol_1 = charToValue(s[i]); // We call our function and convert it into integer
            if (i + 1 < s.length())
            { // This control structure is for i+1 symbol, and we make sure its in bounds
                symbol_2 = charToValue(s[i + 1]);
                if (symbol_1 >= symbol_2)
                { // LHS symbol is greater than RHS, like DC which means 600, we simply add the value to our answer
                    ans += symbol_1;
                }
                else
                {
                    ans += (symbol_2 - symbol_1); // In contrast to the case above, we can't simply add, instead we need to add the difference
                    i++;                          // And we skip the i+1 symbol going to i+2
                }
            }
            else
            {
                ans += symbol_1; // For the last character since i+1 is now out of range
            }
        }
        return ans;
    }
};