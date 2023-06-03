/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/time-needed-to-inform-all-employees
 */
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    // int maxTime = 0;
    // int max(int a, int b){
    //     return a > b ? a : b; 
    // }
    // void bfs(unordered_map<int,vector<int>> &umap, const vector<int> &informTime, int head){
    //     queue<pair<int, int>> q;
    //     q.push({head,0});
    //     while(!q.empty()){
    //         pair<int, int> f = q.front();
    //         int curr_employee = f.first;
    //         int currTime = f.second;
    //         q.pop();
    //         maxTime = max(maxTime, currTime);
    //         for(int &e : umap[curr_employee]){
    //             q.push({e, currTime + informTime[curr_employee]});
    //         }
    //     }
    // }
    void dfs(unordered_map<int,vector<int>> &umap, const vector<int> &informTime, int head, int currTime, int &maxT){
        maxT = max(maxT, currTime);
        for(int &emp : umap[head]){
            dfs(umap, informTime, emp, currTime + informTime[head], maxT);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // max time is answer. visited not needed in case of 3
        unordered_map<int,vector<int>> umap;
        for(int i = 0 ; i < manager.size(); i++){
            int employee = i;
            int manager_i = manager[employee];
            if(manager_i != -1){
                umap[manager_i].push_back(employee);
            }
        }
        // 0 is curr time
        // bfs(umap, informTime, headID);
        int mt = 0;
        dfs(umap, informTime, headID, 0, mt);
        return mt;
    }
};
