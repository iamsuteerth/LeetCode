/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/swap-nodes-in-pairs/
 */
#inlcude <iostream>
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        // head -> ptr (head->next) -> head->next->next
        ListNode* ptr = head->next;
        head->next = swapPairs(head->next->next);
        // ptr -> head -> func
        ptr->next = head;
        return ptr;
    }
};
