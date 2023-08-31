/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/pascals-triangle-ii/
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0)
            return {1};
        else if(rowIndex == 1)
            return {1,1};
        
        vector<int> prev = {1,1};
        vector<int> res(prev.size() + 1, 1);
        
        for(int i = 2 ; i <= rowIndex ; i++){
            res.resize(prev.size() + 1, 1);
            for(int j = 1 ; j < i ; j++){
                res[j] = prev[j - 1] + prev[j];
            }
            prev = res;
        }    
        return res;
    }
};
