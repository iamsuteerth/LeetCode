/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/find-the-duplicate-number/
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Brute Force is quite simple, search for the same number again using double for loop
        // Another solution is to sort the array (nlogn) and then check the next element
        // Another solution is to use a MAP which is O(n) SC & O(n) TC using the find function
        // Another solution is to go to an index and mark it negative, if you again go to negative, repeated number
        // KEY POINT Numbers are also valid INDEX
        int slow = nums[0];
        int fast = nums[0];
        slow = nums[slow];
        fast = nums[nums[fast]];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = nums[0];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
