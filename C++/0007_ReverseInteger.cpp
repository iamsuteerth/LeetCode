/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/reverse-integer/
 */
#include <iostream>
class Solution
{
public:
    int reverse(int x)
    {
        long rem, rev = 0;
        long n = ((long)x > 0) ? x : (-1) * ((long)x);
        while (n != 0)
        {
            rem = n % 10;
            n /= 10;
            rev = rev * 10 + rem;
            if (rev > INT32_MAX || ((-1) * (rev)) < INT32_MIN)
            {
                return 0;
            }
        }
        return ((x > 0) ? (int)rev : (-1) * ((int)rev));
    }
};