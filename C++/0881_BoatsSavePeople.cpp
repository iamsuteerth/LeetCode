/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/boats-to-save-people/
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int ans = 0;
        int left = 0, right = people.size() - 1;
        while(left <= right){
            if(people[right] + people[left] <= limit){
                left++; // If lightest guy and heaviest guy can be paired
            } // If they cannot, then they cannot be paired with anyone else and a new boat is required
            right--; // Processing heaviest guys
            ans++;
        }
        return ans;
    }
};