/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size();
        int m = potions.size();
        int left, right, mid, i = 0;
        vector<int> res(n);
        long temp;
        for(int &spell : spells){
            left = 0;
            right = m - 1;
            while(left <= right){
                mid = (left + right)/2;
                temp = (long)spell* (long)potions[mid];
                if(temp < success){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
            res[i++] = m - left;
        }
        return res;
    }
};