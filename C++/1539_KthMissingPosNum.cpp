/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/kth-missing-positive-number/
 */
#include <vector>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // Number of missing elements from ith index = arr[i] - i - 1
        int mid, left = 0, right = arr.size() - 1;
        while(left <= right){
            mid = (left + right)/2;
            if(arr[mid] - mid - 1 < k){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return left + k;
    }
};