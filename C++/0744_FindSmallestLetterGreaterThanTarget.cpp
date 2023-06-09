/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/find-smallest-letter-greater-than-target/
 */
#include <iostream>
using namespace std;
class Solution {
public:
    int binarySearch(vector<char>& letters, char target) {
        int n = letters.size();
        int l = 0, r = n-1;
        int position = n;
                                                
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(letters[mid] > target) {
…        if(index == letters.size())
            return letters[0];
        return letters[index];
    }
};
