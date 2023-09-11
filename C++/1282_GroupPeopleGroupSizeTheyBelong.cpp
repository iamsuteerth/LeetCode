/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> mp(n + 1);
        vector<vector<int>> res;
        for(int i = 0 ; i < n ; i++){
            int l = groupSizes[i];
            mp[l].push_back(i);
            if(mp[l].size() == l){
                res.push_back(mp[l]);
                mp[l] = {};
            }
        }
        return res;
    }
};
