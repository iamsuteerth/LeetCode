/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/equal-row-and-column-pairs/
 */
#include <iostream>
#include <vector>
#incude <unordered_map>
using namespace std;
class Solution {
public:
    typedef long long ll;
    ll hash(vector<int> &vec){
        ll hash_so_far = 0;
        ll p = 31, m = 1e9 + 7;
        ll p_pow = 1;
        ll n = (ll)vec.size();
        for (long long i = 0; i < n; ++i) {
            hash_so_far = (hash_so_far + vec[i] * p_pow) % m;
            p_pow = (p_pow * p) % m;
        }
        return hash_so_far;
    }
    int equalPairs(vector<vector<int>>& grid) {
        int res = 0;
        int row = grid.size();
        int column = grid[0].size();
        ll hashed_col;

        unordered_map<ll, int> umap;

        for(int i = 0 ; i < row ; i++){
            umap[hash(grid[i])]++;
        }
      
        vector<int> col(row);
      
        for(int i = 0 ; i < column ; i++){
            for(int j = 0 ; j < row ; j++){
                col[j] = grid[j][i];
            }
            hashed_col = hash(col);
            if(umap.find(hashed_col) != umap.end()){
                res += umap.at(hashed_col);
            } 
        }
        return res;
    }
};
