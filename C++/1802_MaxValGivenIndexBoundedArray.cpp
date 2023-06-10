/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    typedef long long ll;
    ll compute(ll count, ll val){
        return (count*val) - ((count)*(count + 1))/2;
    }
    int maxValue(int n, int index, int maxSum) {
        // for an array (x-4), (x-3), (x-2), (x-1), X, (x+1)  
        ll left, right, mid_val;
        left = 1;
        right = maxSum;
        int res = 0;
        while(left <= right){
            mid_val = (left + right)/2;
            ll left_count = min((ll)index, mid_val - 1);;
            ll left_sum = compute(left_count, mid_val);
            left_sum += max((ll)0, index - mid_val + 1);

            ll right_count = min((ll)n-index-1, mid_val);
            ll right_sum = compute(right_count, mid_val);
            right_sum += max((ll)0, n-index-1 - mid_val + 1);

            ll totalSum = left_sum + right_sum + mid_val;
            if(totalSum <= maxSum){
                res = max((ll)res, mid_val);
                left = mid_val + 1;
            }
            else{
                right = mid_val - 1;
            }
        }
        return res;
    }


};
