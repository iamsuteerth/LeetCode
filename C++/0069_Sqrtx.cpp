/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/sqrtx/
 */
#include <iostream>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Solution
{
public:
    int mySqrt(int x)
    {
        long start = 0;
        long mid = 0;
        long control = x;

        while (start < control)
        {
            mid = long((start + control) / 2);
            if (mid * mid == x)
            {
                return (int)mid;
            }
            if (x < mid * mid)
            {
                control = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return (x < control * control) ? (int)control - 1 : (int)control; // Ternary Expression
    }
};
