/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/number-of-islands/
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        if(numRows == 0){
            return {};
        }
        for(int i = 0 ; i < numRows ; i++){
            pascal.push_back(vector<int> (i + 1, 1));
            pascal[i][0] = 1;
            pascal[i][i] = 1;
            for(int j = 1 ; j < i ; j++){
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
        }
        return pascal;
    }
};
