/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/dota2-senate/
 */
#include <iostream>
#include <string>
#include <queue>
using namespace std;
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> qrad, qdire;
        int n = senate.length();
        for(int i = 0 ; i < n ; i++){
            if(senate[i] == 'R')
                qrad.push(i);
            else
                qdire.push(i);
        }
        while(!qrad.empty() && !qdire.empty()){
            int r =  qrad.front(), d = qdire.front();
            qrad.pop();
            qdire.pop();
            if(r < d){
                qrad.push(r + n);
            }
            else{
                qdire.push(d + n);
            }
        }
        return (qrad.size() > qdire.size()) ? "Radiant" : "Dire";
    }
};
