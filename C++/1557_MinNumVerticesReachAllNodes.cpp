/*
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 */
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // InDegree nodes will not be considered at all
        // InDegree == 0 MUST be included
        vector<bool> visited(n, false);
        vector<int> res;
        for(auto &x : edges){
            visited[x[1]] = true;
        }
        for(int i = 0 ; i < n ; i++){
            if(!visited[i])
                res.push_back(i);
        }
        return res;
    }
};
