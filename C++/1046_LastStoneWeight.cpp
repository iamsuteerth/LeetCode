/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/last-stone-weight/
 */
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq; //max-heap
        for(int &i:stones)
            pq.push(i);
        while(pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if(a != b)
                pq.push(abs(a-b));
        }
        
        if(pq.size())
            return pq.top();
        return 0;
    }
};
