/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/add-two-numbers/
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0 || n >= k + maxPts)
            return 1.0;
        vector<double> dp(n+1);
        double csum = 1.0;
        double ans = 0.0;
        dp[0] = 1.0;
        for(int i = 1 ; i <= n ; i++){
            dp[i] = csum/maxPts;
            if(i < k)
                csum += dp[i];
            else
                ans += dp[i];
            
            if(i - maxPts >= 0)
                csum -= dp[i - maxPts];
        }
        return ans;
    }
};
