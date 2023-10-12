/*
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/number-of-flowers-in-full-bloom/
 * HARD QUESTION
 */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        // Finding upper_bound gives JUST greater than target -> idx returned
        // Finding lower_bound gves greater than or equal to target -> idx returned
        // Use binary search internally
        int m = flowers.size();
        int n = people.size();
        vector<int> ans;
        vector<int> start_time(m);
        vector<int> end_time(m);
        for(int i = 0; i<m; i++) {
            start_time[i] = flowers[i][0];
            end_time[i]   = flowers[i][1];
        }
        sort(begin(start_time), end(start_time));
        sort(begin(end_time), end(end_time));
        for(int i = 0 ; i < n ; i++){
            int x = upper_bound(start_time.begin(), start_time.end(), people[i]) - start_time.begin();
            int y = lower_bound(end_time.begin(), end_time.end(), people[i]) - end_time.begin();
            ans.push_back(x - y);
        }
        return ans;
    }
};
