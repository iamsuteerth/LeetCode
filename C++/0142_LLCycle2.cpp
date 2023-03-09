/*
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/linked-list-cycle-ii/
 */
#include <set>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Brute force
class Solution {
public:
    // Brute Force
    // ListNode *detectCycle(ListNode *head) {
    //     set<ListNode*> st;
    //     ListNode* node = head;
    //     while(node != NULL){
    //         if(st.find(node) == st.end()){
    //             st.insert(node);
    //         }
    //         else{
    //             return node;
    //         }
    //         node = node->next;
    //     }
    //     return NULL;
    // }
    // Fast and Slow pointers
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* aux = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                while(slow != aux){
                    aux = aux->next;
                    slow = slow->next;
                }
                return aux;
            }
        }
        return NULL;
    }
};