/*
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/merge-k-sorted-lists/
 * HARD QUESTION
 */
#include <vector>
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution_Method_One
{
public:
    // Recursive mergeTwoLists
    /*  ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2) {
            if(!l1)
                return l2;
            if(!l2)
                return l1;

            if(l1->val <= l2->val) {
                l1->next = mergeTwoSortedLists(l1->next, l2);
                return l1;
            } else {
                l2->next = mergeTwoSortedLists(l1, l2->next);
                return l2;
            }

            return NULL;
        }
    */
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head = NULL;
        ListNode *tail = NULL;

        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        if (list1->val < list2->val){
            head = list1;
            list1 = list1->next;
        }
        else{
            head = list2;
            list2 = list2->next;
        }
        tail = head;
        while (list1 && list2)
        {
            if (list1->val < list2->val){
                tail->next = list1;
                list1 = list1->next;
            }
            else{
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        if (!list1)
            tail->next = list2;
        else
            tail->next = list1;
        return head;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int k = lists.size();
        if (k == 0){
            return NULL;
        }
        if (k == 1){
            return lists[0];
        }
        ListNode *res = mergeTwoLists(lists[0], lists[1]);
        for (int i = 2; i < k; i++){
            res = mergeTwoLists(res, lists[i]);
        }
        return res;
    }
};

class Solution_Method_Two{
public:
    ListNode *mergeTwoSortedLists(ListNode *l1, ListNode *l2){
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    if (l1->val <= l2->val){
        l1->next = mergeTwoSortedLists(l1->next, l2);
        return l1;
    }
    else{
        l2->next = mergeTwoSortedLists(l1, l2->next);
        return l2;
    }
    return NULL;
    }
    ListNode *partionMerge(int start, int end, vector<ListNode*> &lists){
        if(start == end){
            return lists[start];
        }
        if(start > end){
            return NULL;
        }
        int mid = (start + end)/2;
        ListNode* l1 = partionMerge(start, mid, lists);
        ListNode* l2 = partionMerge(mid+1, end, lists);
        
        return mergeTwoSortedLists(l1, l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n = lists.size();
        
        if(n == 0)
            return NULL;
        
        return partionMerge(0, n-1, lists);
        
    }
};