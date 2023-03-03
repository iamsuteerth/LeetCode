/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/sort-an-array/
 */
#include <vector>
using namespace std;
class Solution {
public:
    void heapify(vector<int> &array, int n, int i)
    {   
        int largest = i;       
        int left = 2 * i + 1; 
        int right = 2 * i + 2; 
        if (left < n && array[left] > array[largest])
            largest = left;
        if (right < n && array[right] > array[largest])
            largest = right;
        if (largest != i)
        {
            int temp = array[i];
            array[i] = array[largest];
            array[largest] = temp;
            heapify(array, n, largest);
        }
    }
    void heapSort(vector<int> &array, int n)
    {
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(array, n, i);
        }

        for (int i = n - 1; i >= 0;)
        {
            int temp = array[0];
            array[0] = array[i];
            array[i] = temp;
            heapify(array, i--, 0);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums, nums.size());
        return nums;
    }
};