/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/optimal-partition-of-string/
 */
#include <string>
class Solution {
public:
    int partitionString(string s) {
        int ans = 0;
        int n = s.length();
        vector<int> lastSeen(26,-1);
        int count = 0;
        int start_curr_ss = 0;
        for(int i = 0 ; i < n ; i++){
            char ch = s[i];
            if(lastSeen[ch - 'a'] >= start_curr_ss){
                ans++;
                start_curr_ss = i;
            }
            lastSeen[ch - 'a'] = i;
        }
        ans++;
        return ans;
    }
};
