/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/evaluate-division/
 */
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;
class Solution {
public:
    void dfs(unordered_map<string, vector<pair<string, double>>> &adj, string &src, string &dest,unordered_set<string> &visited, double prod, double &ans){
        if(visited.find(src) != visited.end()){
            return;
        }
        visited.insert(src); // We have visited src
        if(src == dest){
            ans = prod;
            return;
        }
        for(auto &x : adj[src]){
            string v = x.first;
            double val = x.second;
            dfs(adj, v, dest, visited, prod*val, ans);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // a -> (b,2)
        // b -> (c,3) but c -> (b, 1/3)
        // a - 2 -> b - 3 -> c (Multiply the nums)
        // In querie, for a/b : a is the src and b is the destination
        int n = equations.size();
        unordered_map<string, vector<pair<string, double>>> adj;
        for(int i = 0 ; i < n ; i++){
            string u = equations[i][0]; // 'a'
            string v = equations[i][1]; // 'b
            double value = values[i]; // 'a'/'b'
            adj[u].push_back({v,value});
            adj[v].push_back({u,1.0/value});
        }
        vector<double> res;

        for(auto &q : queries){
            string src = q[0];
            string dest = q[1];

            double ans = -1.0;
            double prod = 1;
            if(adj.find(src) != adj.end()){
                unordered_set<string> visited; // Check if it is here to see if node is visited, creating new visited for every query
                dfs(adj, src, dest, visited, prod, ans);
            }
            res.push_back(ans);
        }
        return res;
    }
};
