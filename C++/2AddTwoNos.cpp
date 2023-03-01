#include <iostream>
#include <cstring>
#include <stdlib.h>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        ListNode *head = NULL;
        ListNode *temp = NULL;
        int sum = 0;
        while (l1 != NULL || l2 != NULL)
        {
            sum = carry;
            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            ListNode *nnode = new ListNode(sum % 10);
            if (temp == NULL)
                head = temp = nnode;
            else
            {
                temp->next = nnode;
                temp = temp->next;
            }
            if (carry > 0)
                temp->next = new ListNode(carry);
        }
        return head;
    }

    ListNode *addTwoNumbersShorter(ListNode *l1, ListNode *l2)
    {
        int carry = 0, sum = 0;
        ListNode head;
        ListNode *temp = &head;
        while (l1 != NULL || l2 != NULL)
        {
            sum = carry + ((l1 != NULL) ? l1->val : 0) + ((l2 != NULL) ? l2->val : 0);
            carry = sum / 10;
            if (l1 != NULL)
                l1 = l1->next;
            if (l2 != NULL)
                l2 = l2->next;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
            if (carry > 0)
                temp->next = new ListNode(carry);
        }
        return head.next;
    }
};