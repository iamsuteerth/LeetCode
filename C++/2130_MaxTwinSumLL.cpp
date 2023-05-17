/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list
 */
#include <stack>
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    int max(int a, int b){
        return a > b ? a : b;
    }
    int pairSum(ListNode* head) {
        int smax = INT_MIN;
        ListNode* ptr = head;
        int n = 0, sum = 0;
        stack<int> stk;
        while(ptr != NULL){
            n++;
            stk.push(ptr->val);
            ptr = ptr->next;
        }
        ptr = head;
        for(int i = 0 ; i < n/2 ; i++){
            sum = ptr->val + stk.top();
            stk.pop();
            ptr = ptr->next;
            smax = max(sum, smax);
        }
        return smax;
    }
};
