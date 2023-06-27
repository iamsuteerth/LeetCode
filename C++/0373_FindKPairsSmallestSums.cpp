/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
 */
#include <iostream>
#include <vector>
#include <set>
#include <priority_queue>
class Solution {
public:
    typedef pair<int, pair<int,int>> P;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> res;

        priority_queue<P, vector<P>, greater<P>> pq;
        if (n1 == 0 || n2 == 0)
            return res;
        
        int sum = nums1[0] + nums2[0];
        pq.push({sum, {0, 0}});

        set<pair<int,int>> st;
        st.insert({0,0});

        while(k > 0 && !pq.empty()){
            auto temp = pq.top();
            pq.pop();

            int i = temp.second.first;
            int j = temp.second.second;
            res.push_back({nums1[i], nums2[j]});

            if(j + 1 < n2 && st.find({i, j + 1}) == st.end()) {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                st.insert({i, j + 1});
            }
            if(i + 1 < n1 && st.find({i + 1, j}) == st.end()) {
                pq.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                st.insert({i + 1, j});
            }     
            k--;
        }  
        return res;
    }
};
