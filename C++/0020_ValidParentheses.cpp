/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/valid-parentheses/
 */
class Solution {
public:
    bool isValid(string s)
    {
        vector<char> stack;
        for (int i = 0; i < s.length(); i++)
        {
            if (s.at(i) == '(' || s.at(i) == '{' || s.at(i) == '[')
            {
                stack.push_back(s.at(i));
            }
            else
            {
                switch (s.at(i))
                {
                case ')':
                    if (!stack.empty() && stack.back() == '(')
                        stack.pop_back();
                    else
                        return false;
                    break;
                case ']':
                    if (!stack.empty() && stack.back() == '[')
                        stack.pop_back();
                    else
                        return false;
                    break;
                case '}':
                    if (!stack.empty() && stack.back() == '{')
                        stack.pop_back();
                    else
                        return false;
                    break;
                default:
                    return false;
                }
            }
        }
        return stack.empty() ? true : false;
    }
};
