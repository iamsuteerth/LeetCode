/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/find-the-highest-altitude/
 */
#include <vector>
using namespace std;
public:
    int largestAltitude(vector<int>& gain) {
        int highest = 0, prefix = 0;
        for(int i = 0 ; i < gain.size() ; i++){
            prefix += gain[i];
            highest = max(highest, prefix);
        }
        return highest;
    }
};
