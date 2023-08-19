/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/climbing-stairs/
 */
#include <iostream>
using namespace std;
class Solution {
public:
    // int memo[46];
    int bu[46]; // bu[i] is number of ways to climb i stairs
    // int solve_bruteforce(int n){
    //     if(n < 0)
    //         return 0;
    //     if(n == 0)  
    //         return 1;
    //     int one = solve_bruteforce(n - 1);
    //     int two = solve_bruteforce(n - 2);
    //     return one + two;
    // }
    // int solve_memo(int n){
    //     if(n < 0)
    //         return 0;
    //     if(memo[n] != -1)
    //         return memo[n];
    //     if(n == 0)  
    //         return 1;
        
    //     int one = solve_memo(n - 1);
    //     int two = solve_memo(n - 2);
    //     return memo[n] = one + two;
    // }
    // int bottum_up(int n){
    //     vector<int> bu(n+1);
    //     if(n == 0 || n == 1 || n ==2)
    //         return n;
    //     bu[0] = 0;
    //     bu[1] = 1;
    //     bu[2] = 2;
    //     for(int i = 3 ; i <= n ; i++){
    //         bu[i] = bu[i - 1] + bu[i - 2];
    //     }
    //     return bu[n];
    // }
    int optimal(int n){
        // You need i - 1 and i - 2
        // Bottum up approach needs you to find this dependency on sub problems
        if(n == 0 || n == 1 || n ==2)
            return n;
        int a = 1,b = 2,c = 3;
        for(int i = 3 ; i <= n ; i++){
            c = b + a;
            int temp = b;
            b = c;
            a = temp;
        }
        return c;
    }
    int climbStairs(int n) {
        // memset(memo, -1, sizeof(memo));
        return optimal(n);
    }
};
