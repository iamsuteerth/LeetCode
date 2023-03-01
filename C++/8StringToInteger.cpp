/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/string-to-integer-atoi/
 */
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    int myAtoi(string s)
    {
        if (s.length() < 0)
        {
            return 0;
        }
        int length = s.length();
        double number = 0;
        bool isNegative = false;
        int i = 0;
        while (s[i] != '\0' && s[i] == ' ')
        {
            i++;
        }
        if (s[i] == '-')
        {
            isNegative = true;
            i++;
        }
        else if (s[i] == '+')
        {
            isNegative = false;
            i++;
        }
        for (; s[i] != '\0'; i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                number = number * (double)10 + (double)(s.at(i) - '0');
            }
            else
            {
                break;
            }
        }
        number = isNegative ? (0 - number) : (number);
        if (number > (double)INT32_MAX)
        {
            return INT32_MAX;
        }
        else if (number < (double)INT32_MIN)
        {
            return INT32_MIN;
        }
        else
        {
            return (int)number;
        }
    }
};