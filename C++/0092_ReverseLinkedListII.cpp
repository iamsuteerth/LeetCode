/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/reverse-linked-list-ii/
 */
#include <iostream>
#include <vector>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
using namespace std;
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        for(int i = 1 ; i < left ; i++){
            prev = prev->next;
        }

        ListNode* curr = prev->next;

        for(int i = 1 ; i<= right-left ; i++) {
            ListNode* temp = prev->next; 
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = temp; 
        }
        return dummy->next;
    }
};
