/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/check-if-it-is-a-straight-line/
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int twice_area(int x1, int y1, int x2, int y2, int x3, int y3){
        return (x1*(y2-y3))+(x2*(y3-y1))+(x3*(y1 - y2));
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size() <= 2)
            return true;
        int n = coordinates.size();
        int x1,x2,x3,y1,y2,y3;
        x1 = coordinates[0][0];
        x2 = coordinates[1][0];
        y1 = coordinates[0][1];
        y2 = coordinates[1][1];
        for(int i = 2 ; i < n ; i++){
            x3 = coordinates[i][0];
            y3 = coordinates[i][1];
            if(twice_area(x1,y1,x2,y2,x3,y3) == 0)
                continue;
            else
                return false;
        }
        return true;
    }
};
