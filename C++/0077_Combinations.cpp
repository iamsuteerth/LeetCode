/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/combinations/
 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    // unordered_set<int> uset;
    vector<vector<int>> ans;
    // void solve_set(int i, int n, int k, vector<int> &vec){
    //     if(i > n || vec.size() == k){
    //         if(vec.size() == k){
    //             ans.push_back(vec);
    //         }
    //         return;
    //     }
    //     if(uset.find(i) == uset.end()){
    //         vec.push_back(i);
    //         solve(i+1, n, k, vec);
    //         vec.pop_back();
    //     }
    //     solve(i+1, n, k, vec); 
    // }
    void solve(int i, int n, int k, vector<int> &vec){
        // Advantage is that we are not using the find function
        // Traditional Backtracking code is 
        // Take element
        // Call function
        // Backtrack and remove it 
        if(i > n || k == 0){
            if(k == 0){
                ans.push_back(vec);
            }
            return;
        }
        for(int j = i ; j <= n ; j++){
            vec.push_back(j);
            solve(j+1, n, k-1, vec);
            vec.pop_back();
        }
        }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        // solve_set(1, n, k, temp);
        solve(1, n, k, temp);
        return ans; 
    }
};
