/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        ListNode* head = NULL;
        ListNode* tail = NULL;
        
        if(list1==NULL)
            return list2;
        if(list2==NULL)
            return list1;
        
        if(list1->val < list2->val){
            head = list1;
            list1 = list1->next; 
        }
        else{
            head = list2;
            list2 = list2->next;
        }

        tail = head;
        while(list1 && list2){
            if(list1->val < list2->val){
                tail->next = list1;
                list1 = list1->next;
            }
            else{
                tail->next = list2;
                list2=list2->next;
            }
            tail=tail->next;
        }
        if(!list1)
            tail->next=list2;
        else
            tail->next=list1;
        return head;
    }
};