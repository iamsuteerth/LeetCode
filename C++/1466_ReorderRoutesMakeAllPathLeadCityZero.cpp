/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
 */
#include <unordered_map>
#include <vector>
#include <utility>
using namespace std;
class Solution {
public:
    void dfs(int u, int parent, unordered_map<int,vector<pair<int,int>>> &adj, int &count){
        for(auto &pair : adj[u]){
            int v = pair.first;
            if(v!=parent){
                int c = pair.second;
                if(c == 1 ){
                    count += 1;
                }
                dfs(v, u, adj, count);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        // Real Edge = 1
        // Fake Edge = 0 
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto &vec : connections){
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back({v,1});
            adj[v].push_back({u,0});
        }
        int count = 0;
        dfs(0, -1, adj, count);
        return count;
    }
};