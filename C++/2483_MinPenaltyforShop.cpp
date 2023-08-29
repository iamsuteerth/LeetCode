/*
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/minimum-penalty-for-a-shop/
 */
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        // Brute Force
        // Check penalty at every close hour

        //Optimized
        // TC, SC : O(n), O(n)
        // vector<int> pref_n(n+1);
        // vector<int> suff_y(n+1);

        // pref_n[0] = 0;
        // suff_y[n] = 0;
        // int N = 0, Y = 0;

        // for(int i = 1 ; i <= n ; i++){
        //     if(customers[i - 1] == 'N')
        //         N++;
        //     pref_n[i] = N;
        //     if(customers[n - i] == 'Y')
        //         Y++;
        //     suff_y[n - i] = Y;
        // }

        // int minPenal = suff_y[0];
        // int minHour = 0;
        // int pen;
        // for(int i = 0 ; i <= n ; i++){
        //     pen = pref_n[i] + suff_y[i];
        //     if(pen < minPenal){
        //         minPenal = pen;
        //         minHour = i;
        //     }
        // }
        // return minHour;

        // Best Approach
        // TC, SC : O(n), O(1)

        // Calculating for 0th hour
        int pen = 0;
        char curr;
        for(int i = 0 ; i < n ; i++){
            if(customers[i] == 'Y')
                pen++;
        }  
        int minPen = pen, minHour = 0;
        for(int i = 1 ; i <= n ; i++){
            switch(customers[i - 1]){
                case 'Y':
                    --pen;
                    break;
                case 'N':
                    ++pen;
                    break;
            }
            if(pen < minPen){
                minPen = pen;
                minHour = i;
            }
        }
        return minHour;
    }
}; 
