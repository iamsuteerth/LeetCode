/*
 * @author Suteerth Subramaniam
 */
package edu.vit.leetcode.javacodes;

import java.util.HashMap; // We are using this over map because this is just better :D
import java.util.Map; // Hashmap is part of Map class

public class TwoSum_1 {
    public int[] twoSum(int[] nums, int target) { //Function takes in an integer array and an integer as parameters
        
        Map<Integer, Integer> hmap = new HashMap<>(); // Creating an object named hmap 

        for (int i = 0; i < nums.length; i++) 
        { 
            if (hmap.containsKey(target - nums[i])) 
            { 
                /* 
                 * We are given x + y = target, so x can be writtern as target - y
                 * The Map.get() function gets the corresponding key for the value specified
                 * What we are doing here is, if value x is found in the hashmap, we return the indices of x and y (i is index of y) 
                 * and we get the index of x using Map.get()
                 */
                return (new int[] { hmap.get(target - nums[i]), i }); // Obviously, this won't work for first iteration so the else statemen gets executed
            } 
            else 
            {
                hmap.put(nums[i], i);  // We add key, value pair to hashmap
            }
            /*
             * We are sure to come across a case where x -> y, and the corresponding keys will be thrown as output in the array
             */
        }
        return (new int[] { -69, -69 }); // This is when no values add up to target which is not possible for our problem scenario
        // This solution uses only one for loop and thus its much better in terms of time complexity (an example of the general algorithm is given below)
        // which has TC of 0(n^2)
    }
    // General algorithm using two for loops and TC 0(n^2)
    public int[] twoSum_aliter(int[] nums, int target) {

        int[] ans = new int[2]; // Since only one solution assumption is made, we declare the size as 2

        int i, j;
        for (i = 0; i < nums.length ; i++) { // We want to iterate through the entire array 
            for (j = i + 1; j < nums.length; j++) { // We don't want to re consider the i element 
                if (nums[i] + nums[j] == target) { //Given condition implemented
                    ans[0] = i; // Storing indices in the array
                    ans[1] = j;
                    break;
                }
            }
        }
        return ans; // Returning the array
    }
}
