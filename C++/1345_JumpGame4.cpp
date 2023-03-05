/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/jump-game-iv/
 * HARD QUESTION
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        queue<int> q;
        int steps = 0;
        unordered_map<int,vector<int>> umap;
        for(int i = 0; i < n ; i++){
            umap[arr[i]].push_back(i);
        }
        vector<bool> visited(arr.size(), false);
        q.push(0);
        visited[0] = true;
        
        while(!q.empty()){

            int size = q.size();

            while(size--)
            {
                int front = q.front();
                q.pop();
                if(front == n-1){
                    return steps;
                }
                if(front - 1 >= 0 && !visited[front - 1]){
                    q.push(front - 1);
                    visited[front - 1] = true;
                }
                if(front + 1 <= n-1 && !visited[front + 1]){
                    q.push(front + 1);
                    visited[front + 1] = true;
                } 
                for(int &idx : umap[arr[front]]){
                    if(!visited[idx]){
                        q.push(idx);
                        visited[idx] = true;
                    }
                }
                umap.erase(arr[front]);
            }
            steps++;
        }
        return steps;
    }
};