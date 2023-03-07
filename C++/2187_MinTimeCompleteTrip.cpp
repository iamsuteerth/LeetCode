/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/minimum-time-to-complete-trips/
 */
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    bool possible(vector<int> &time, long long t, int totalTrips){
        long long trips = 0;
        for(int &i : time){
            trips += t / i;
        }
        return (trips >= totalTrips);
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left = 1, right = *min_element(time.begin(), time.end()) * (long long)totalTrips, mid;
        int n = time.size();
        while(left < right){
            mid = (left + right)/2;
            if(possible(time, mid, totalTrips)){
                right = mid; // Because mid works
            }
            else{
                left = mid + 1; // Because mid doesn't work
            }
        }
        return left;
    }
};