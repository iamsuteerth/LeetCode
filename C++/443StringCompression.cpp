/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/string-compression/
 */
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if(n == 1){
            return 1;
        }
        int i = 0, j = 0;
        while(i < n){
            int count = 1;
            while (i < n - 1 && chars[i] == chars[i + 1]) {
                count++;
                i++;
            }
            chars[j++] = chars[i++];
            if(count > 1){
                string temp = to_string(count);
                for (char c : temp) {
                    chars[j++] = c;
                }
            }
        }
        return j;
    }
};