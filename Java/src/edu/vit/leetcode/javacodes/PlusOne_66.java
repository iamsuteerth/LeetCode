package edu.vit.leetcode.javacodes;

class Solution {
    
    public int[] plusOne(int[] digits) {
        
        // We will implement a simple carry over system
        int carryOver = 1; // Default carry over is 1
        int sum = 0; // Initializing sum
        for (int i = digits.length - 1; i >= 0; i--) { // Starting from end
            sum = digits[i] + carryOver; // this can be either value + 1 (which we want) or it will be a value greater
                                         // than 10
            if (sum >= 10) {
                carryOver = 1;
            } else {
                carryOver = 0;
            }
            digits[i] = sum % 10; // If we are having 9, 9%10 is 9 only, so we retain the value, in case it's 12
                                  // or 11, then it's 1 or 2
        }
        if (carryOver == 1) { // This means that we need to increase array size by one
            int[] plusOneArray = new int[digits.length + 1];
            System.arraycopy(digits, 0, plusOneArray, 1, digits.length); // Source, Source Position, Destination,
                                                                         // Destination Position, length
            plusOneArray[0] = 1; // Best way to understand this statement is by assuming input array to be 9
            return plusOneArray;
        } else {
            return digits;
        }

    }
}
