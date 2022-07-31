/*
 * @author Suteerth Subramaniam
 */
package edu.vit.leetcode.javacodes;

public class Palindrome_9 {
    public boolean isPalindrome(int x) {
        
        if (x < 0) { // A Negative integer cannot be a palindrome, only the positive part can be
            // -1331 reverse is 1331- and both are not equal
            return false;
        }

        int temp = x; // Assigning value of x to a temp variable
        int n = 0, m = 0;

        while (temp != 0) { // Loop executes until temp becomes 0 which it will since 
                            // Integer division of 1234/10 in java gives the quotient 123
            n = temp % 10; // We store the remainder in n 
            temp = temp / 10; // Value reduced by one order of 10
            m = m * 10 + n; // We reconstruct the reverse number using this formula and the loop iterations
        }

        return (x == m); // Better way returning boolean value instead of using lengthier if else statements
    }
}
