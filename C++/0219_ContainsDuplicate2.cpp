/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/contains-duplicate-ii/
 */
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int abs(int a, int b){
        return (a < b) ? (b - a) : (a - b);
    }
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        for(int i = 0 ; i < nums.size() ; i++){
            if(umap.find(nums[i]) == umap.end()){
                umap[nums[i]] = i;
            }
            else{
                auto it = umap.find(nums[i]);
                int diff = abs(it->second, i);
                if(diff <= k)
                   return true;
                else
                    umap[nums[i]] = i;
            }
        }
        return false;
    }
};
