/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/validate-stack-sequences/
 */
 #include <stack>
 #include <vector>
 using namespace std;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // EACH distinct value
        // Initial empty stack
        // Popped is a permutation of pushed
        // lenghts are same
        int i = 0;
        int j = 0;
        int m = pushed.size();
        stack<int> S;
        while(i <m && j <m){
            S.push(pushed[i]);
            while(!S.empty() && j < m && popped[j] == S.top()){
                S.pop();
                j++;
            }
            i++;
        }
        return S.empty();
    }
};
