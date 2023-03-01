#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int chars = s.length() - 1;
        int i = chars;
        int word = 0;
        while (s.at(i) == ' ')
            i--;
        for (int j = 0; j <= i; j++)
        {
            if (s.at(j) == ' ')
                word = 0;
            else
            {
                word++;
            }
        }
        return word;
    }
};