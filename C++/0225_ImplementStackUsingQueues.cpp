/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/implement-stack-using-queues/
 */
#include <vector>
#include <iostream>
using namespace std;
class MyStack {
public:
    // Double Queue
    // queue<int> q1;
    // queue<int> q2;
    MyStack() {
        
    }
    // void push(int x) {
    //     q2.push(x); // Default que
    //     while(!q1.empty()){ // If q1 is not empty 
    //        q2.push(q1.front()); // Push all elements from q1 into q2
    //        q1.pop(); 
    //     }
    //     swap(q1, q2); // Swap... Making q1 full with updated int x
    // }
     // int pop() {
    //     int res = q1.front();
    //     q1.pop();
    //     return res;
    // }
    // int top() {
    //     return q1.front();
    // }
    // bool empty() {  
    //     return q1.empty();
    // }
    // Single queue
    queue<int> que;
    void push(int x){
        que.push(x);
        for(int i = 0 ; i < que.size() - 1 ; i++){
            que.push(que.front());
            que.pop();
        }
    }
    int pop() {
        int x = que.front();
        que.pop();
        return x;
    }
    int top() {
        return que.front();
    }
    bool empty() {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
