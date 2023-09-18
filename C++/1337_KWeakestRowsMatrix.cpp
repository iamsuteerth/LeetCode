/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
 */
#include <iostream>
#include <vector>
#include <priority_queue>
using namespace std;
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) { 
        int n = mat.size();
        int m = mat[0].size();
        vector<int> res;
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0 ; i < n ; i++){
            int hash = 0;
            for(int j = 0 ; j < m ; j++){
                hash += mat[i][j];
            }
            pq.push({hash, i});
        }
        while(!pq.empty() && k != 0){
            auto top = pq.top();
            res.push_back(top.second);
            pq.pop();
            k--;
        }
        return res;
    }
};
