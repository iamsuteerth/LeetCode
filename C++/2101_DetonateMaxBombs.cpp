#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;
class Solution {
public:
    typedef long long LL;
    LL distancesq(LL x1, LL y1, LL x2, LL y2){
        return (LL)((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
    }
    int max(int a, int b){
        return a > b ? a : b;
    }
    void dfs(unordered_map<int, vector<int>> &umap, int u,unordered_set<int> & visited){
        visited.insert(u);
        for(int &v : umap[u]){
            if(visited.find(v) == visited.end()){
                dfs(umap, v, visited);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        // r >= d for a bomb to detonate other bomb
        unordered_map<int, vector<int>> umap;
        int count = 0;
        int n = bombs.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j < n ; j++){
                if(i == j)
                    continue;
                LL x1 = bombs[i][0];
                LL x2 = bombs[j][0];
                LL y1 = bombs[i][1];
                LL y2 = bombs[j][1];
                LL centre_dist = distancesq(x1, y1, x2, y2);
                LL r = bombs[i][2];
                if ((r * r) >= centre_dist)
                    umap[i].push_back(j);
            }
        }
        int m = 0;
        unordered_set<int> visited;
        for(int i = 0; i<n; i++) {
            dfs(umap, i, visited);
            m = max(m, visited.size());
            visited.clear();
        }
        return m;
    }
};
