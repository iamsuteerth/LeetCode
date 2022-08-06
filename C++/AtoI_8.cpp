#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    int myAtoi(string s)
    {
        if (s.length() < 0) //If there is no string, we return 0
        {
            return 0;
        }
        int length = s.length(); // Storing string length in a variable
        double number = 0; // Since our converted number can be > MAX INT or < MIN INT
        bool isNegative = false; // Typer of integer flag
        int i = 0;
        while (s[i] != '\0' && s[i] == ' ')
        {
            i++; //We want to skip whitespaces and get index of character
        }
        // To determine whether integer is positive or negative
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
        // We use previous value of i corresponding to index of character we found earlier
        for (; s[i] != '\0'; i++) //Until the end
        {
            if (s[i] >= '0' && s[i] <= '9') //If the character in sequence is integer, only then we proceed and break otherwise
            {
                number = number * (double) 10 + (double)(s.at(i) - '0');
            }
            else
            {
                break;
            }
        }
        number = isNegative ? (0 - number) : (number); // Ternary operator for assigning negative or positive value
        if (number > (double)INT32_MAX) //If our number is greater than INT 32 MAX
        {
            return INT32_MAX;
        }
        else if (number < (double)INT32_MIN) // if our number is lower than INT 32 MIN
        {
            return INT32_MIN;
        }
        else
        {   
            return (int)number;
        }
    }
};