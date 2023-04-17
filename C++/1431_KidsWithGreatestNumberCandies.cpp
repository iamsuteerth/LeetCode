/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
 */
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = 0;
        int n = candies.size();
        vector<bool> res(n, false);
        for(int i = 0 ; i < n ; i++){
            if(candies[i] >= max){
                max = candies[i];
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(extraCandies + candies[i] >= max){
                res[i] = true;
            }
        }
        return res;
    }
};
