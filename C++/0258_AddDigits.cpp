/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/add-digits/
 */
#include <iostream>
using namespace std;
class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        while(num != 0){
            sum += (num%10);
            num /= 10;
        }
        if(sum >= 10){
            return addDigits(sum);
        }
        else{
            return sum;
        }
    }
};
