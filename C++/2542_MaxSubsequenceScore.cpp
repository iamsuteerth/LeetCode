/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/maximum-subsequence-score/
 */
#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
#include <priority_queue>
using namespace std;
class Solution_Recursion_Brute_Force {
public:
    int K,n;
    priority_queue<int, vector<int>, greater<int>> pq;
    void removeFromPQ(int num){
        vector<int> temp;
        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            if(x==num)
                break;
            temp.push_back(x);
        }
        for(int &i : temp){
            pq.push(i);
        }
    }
    long long solve(vector<int>& nums1, vector<int>& nums2, int sum, int min_element, int cidx, int count){
        if(count==K){
            return sum*min_element;
        }
        if(cidx >= n){
            return 0;
        }
        pq.push(nums2[cidx]);
        int take_i = solve(nums1, nums2, sum+nums1[cidx], pq.top(), cidx+1, count+1);
        removeFromPQ(nums2[cidx]);
        int not_take_i = solve(nums1, nums2, sum, min_element, cidx+1, count);
        return max(take_i, not_take_i);
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        K = k;
        n = nums1.size();
        return solve(nums1, nums2, 0, 0, 0, 0);
    }
};
class Solution {
public:
    
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>> vec(n);
        for(int i = 0 ; i < n ; i++){
            vec[i] = {nums1[i], nums2[i]};
        }
        auto lambda = [&](auto &P1, auto &P2){
            return P1.second > P2.second;
        };
        sort(begin(vec), end(vec), lambda);
        priority_queue<int, vector<int>, greater<int>> pq;
        long long ksum = 0;

        for(int i = 0 ; i <= k - 1; i++){
            ksum += vec[i].first;
            pq.push(vec[i].first);
        }
        long long res = ksum * vec[k-1].second;
        for(int i = k ; i < n ; i++){
            // Taking minimum as vec[i].second
            ksum += vec[i].first;
            ksum -= pq.top();
            pq.pop();
            pq.push(vec[i].first);
            res = max(res, ksum*vec[i].second);
        }
        return res;
    }
};
