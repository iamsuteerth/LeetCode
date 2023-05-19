/*
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/koko-eating-bananas/
 */
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    bool canEatAll(vector<int>& piles, int givenHour, int h) {
        int actualHour = 0;
        
        for(int &x : piles) {
            actualHour += x/givenHour;
            
            if(x%givenHour != 0)
                actualHour++;   
        }
        return actualHour <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        
        int l = 1, r = *max_element(begin(piles), end(piles));
        
        while(l < r) {
            int mid = l + (r-l)/2;
            
            if(canEatAll(piles, mid, h)) {
                r = mid;
            } else {
                l = mid+1;
            }
            
        }
        
        return l;
    }
};
