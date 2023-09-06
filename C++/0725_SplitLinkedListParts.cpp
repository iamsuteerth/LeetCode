/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/split-linked-list-in-parts/
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr){
            n++;
            curr = curr->next;
        }

        int parts = n/k;
        int remainder = n%k;

        vector<ListNode*> res(k, NULL);
        curr = head;

        for(int i = 0; curr && i < k ; i++) {
            res[i] = curr;
            for(int count = 1; count <= parts + (remainder > 0 ? 1 : 0) ; count++) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = NULL;
            remainder--;
        }
        return res;
    }
};
