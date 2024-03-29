/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/longest-cycle-in-a-graph/
 * HARD QUESTION
 */
#include <vector>
using namespace std;
class Solution {
public:
    int result = -1;
    // Traditional DFS
    void dfs(int u, vector<int> &edges, vector<bool> &visited, vector<int> &count, vector<bool> &inRecursion){
        if(u != -1){
            visited[u] = true;
            inRecursion[u] = true;
            int v = edges[u];
            if(v != -1 && !visited[v]){
                count[v] = count[u] + 1; // How many nodes visited until v
                dfs(v, edges, visited, count, inRecursion);
            }
            else if(v != -1 && inRecursion[v]){ // Both are true
                result = max(result, count[u] - count[v] + 1);
            }
            inRecursion[u] = false;
        }
    }
    int longestCycle(vector<int>& edges) {
        // NO need to make adj table 
        int n = edges.size();
        vector<bool> visited(n, false);
        vector<bool> inRecursion(n, false);
        vector<int> count(n,1);
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                dfs(i, edges, visited, count, inRecursion);
            }
        }
        return result;
    }
};