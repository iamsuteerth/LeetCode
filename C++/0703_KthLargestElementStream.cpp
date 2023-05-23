/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : Kth Largest Element in a Stream - LeetCode
 */
#include <iostream>
#include <priority_queue>
#include <vector>
#include <functional>
using namespace std;
class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq; // Ascending order, container used by pq is vector
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int &i : nums){
            pq.push(i);
        }
    }
    int add(int val) {
        pq.push(val);
        while(pq.size() > k){
            pq.pop();
        }
        return pq.top();
    }
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
