/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
 */
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find (int x) {
        if (x == parent[x]) 
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union (int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) 
            return;

        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    // DSU Code
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i<n; i++) {
            parent[i] = i;
        }
        // Making Components
        for(auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            Union(u, v);
        }
        unordered_map<int, int> mp;
        
        for(int i = 0; i<n; i++) {
            int parent = find(i);
            mp[parent]++;
        }

        long long result = 0;
        long long remainingNodes = n;
        
        for(auto &it : mp) {
            long long size = it.second;
            result += (size) * (remainingNodes-size);
            remainingNodes -= size;
        }
        
        return result;
    }
};