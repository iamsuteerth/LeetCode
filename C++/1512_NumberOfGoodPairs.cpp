/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/number-of-good-pairs/
 */
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    // Now since we only need to calculate NC2 which is N!/(N-2!)2! => (N-1)(N)/2
    // This reduces the calculations a LOT as we dont actually need to calculate factorials
    int nc2 (int n){
        if(n <= 0)
            return 0;
        return (n - 1)*(n)/(2);
    }
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, size;
        unordered_map<int, int> umap;
        // Now every time size is updated, we can calculate the new number of combinations by 
        // NC2 - N-1C2, so if N = 3, we have 3 combinations (0,1),(0,2),(1,1)
        // If N becomes 4, we have 4C2 i.e. 6 combinations
        // But adding 6 wont make sense since we already had 3
        // So the new combinations can simply be added by taking a subtraction
        for(int i = 0 ; i < n ; i++){
            umap[nums[i]]++;
            size = umap[nums[i]];
            ans += (nc2(size) - nc2(size - 1));
        }
        return ans;
    }
};
