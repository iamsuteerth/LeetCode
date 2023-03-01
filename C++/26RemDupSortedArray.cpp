#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return 1;
        }
        int k = 0;
        int size = nums.size();
        int temp[nums.size()];
        for (int i = 0; i < size - 1; i++)
        {
            if (nums[i] != nums[i + 1])
            {
                temp[k] = nums[i];
                k++;
            }
        }
        temp[k++] = nums[size - 1];
        for (int i = 0; i < k; i++)
        {
            nums[i] = temp[i];
        }
        return k;
    }
};