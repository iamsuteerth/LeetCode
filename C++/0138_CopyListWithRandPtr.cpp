/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/copy-list-with-random-pointer/
 */
#include <iostream>
#include <string>
#include <map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(!head)
            return NULL;

        map<Node*, Node*> mp;

        Node* curr = head;
        Node* newHead = NULL;
        Node* prev = NULL;

        while(curr){
            Node* newCurr = new Node(curr->val);
            mp[curr] = newCurr;
            if(!newHead){
                newHead = newCurr;
                prev = newHead;
            }
            else{
                prev->next = newCurr;
                prev = newCurr;
            }
            curr = curr->next;
        }

        curr = head;
        Node* newCurr = newHead;

        while(curr){
            if(!curr->random)
                newCurr->random = NULL;
            else
                newCurr->random = mp[curr->random];
            newCurr = newCurr->next;
            curr = curr->next;
        }
        return newHead;
    }
};
