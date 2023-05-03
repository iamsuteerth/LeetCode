/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/find-the-difference-of-two-arrays/
 */
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res(2,vector<int>());
        unordered_map<int, int> umap1;
        unordered_map<int, int> umap2;
        int n1 = nums1.size(), n2 = nums2.size();
        for(int i = 0, j = 0 ; ; i++, j++){
            if(i < n1 && umap1.find(nums1[i]) == umap1.end()){
                umap1.emplace(nums1[i], 1);
            }
            if(j < n2 && umap2.find(nums2[j]) == umap2.end()){
                umap2.emplace(nums2[j], 1);
            }
            if(i >= n1 && j >= n2)
                break;
        }
        for(int i = 0, j = 0; ; i++, j++){
            if(i < n2 && umap1.find(nums2[i]) == umap1.end()){
                res[1].push_back(nums2[i]);
                umap1.emplace(nums2[i], 1);
            }
            if(j < n1 && umap2.find(nums1[j]) == umap2.end()){
                res[0].push_back(nums1[j]);
                umap2.emplace(nums1[j], 1);
            }
            if(i >= n2 && j >= n1)
                break;
        }
        return res;
    }
};
