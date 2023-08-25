/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/reverse-linked-list/
 */
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
    void recursive(ListNode* head, ListNode* curr, ListNode* prev){
        if(!curr){
            head = prev;
            return;
        }
        recursive(head, curr->next, curr);
        curr->next = prev;
    }
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* prev = head;
        ListNode* curr = prev->next;
        head->next = NULL;
        while(curr && prev){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
}; 
