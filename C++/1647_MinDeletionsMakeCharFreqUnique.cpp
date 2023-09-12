/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique
 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int usingSet(string s){
        unordered_set<int> st;
        int freq[26] = {0};
        for(char &c : s)
            freq[c - 'a']++;
        int res = 0;
        for(int i = 0 ; i < 26 ; i++){
            while(freq[i] > 0 && st.find(freq[i] != st.end())){ // We have already seen the frequency
                freq[i]--; // Try to reduce it as long as set contains the freq until it becomes 0
                res++;
            }
            st.insert(freq[i]);
        }
        return res;
    }
    int minDeletions(string s) {
        int freq[26];
        for(char &c : s){
            freq[c - 'a']++;
        }
        sort(freq.begin(), freq.end());
        int ans = 0;
        for(int i = 24 ; i >= 0 && freq[i] > 0 ; i--){
            // If frequency of i and i+1 are equal or i < i+1, then problem as this is ascending order
            if(freq[i] >= freq[i+1]) { // i+1 detects the previously modified value
                int prev = freq[i]; 
                freq[i] = max(0, freq[i+1]-1); // freq[i] as freq[i+1] - 1
                ans  += (prev - freq[i]);
                // Ascending order maintained
            }
        }
        return ans;
    }
};
