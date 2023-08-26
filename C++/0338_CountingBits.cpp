/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/counting-bits/
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        /*
            FOR O(n) consider this
            1 = 1
            2 = 10
            3 = 11
            6 = 110
            4 = 100
            8 = 1000
            So on so forth
            By calculating for 2,3. We know answer for 6,8,9
         */
        // O(n log n)
        vector<int> res(n + 1);
        // for(int i = 0 ; i <= n ; i++){
        //     int n = i;
        //     int ones = 0;
        //     while(n != 0){
        //         // Essentially converting into binary
        //         ones += n%2;
        //         n /= 2;
        //     }
        //     res[i] = ones;
        // }
        // return res;

        // O(n)
        res[0] = 0;
        for(int i = 1 ; i <= n ; i++)
            res[i] = res[i/2] + i%2;
        return res;
    }
};
