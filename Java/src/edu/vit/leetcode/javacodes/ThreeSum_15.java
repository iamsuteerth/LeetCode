/*
 * @author Suteerth Subramaniam
 */
package edu.vit.leetcode.javacodes;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;

class Solution {

    public List<List<Integer>> threeSum(int[] nums) {
        
        Arrays.sort(nums); // We sort the given array, NlogN TC

        List<List<Integer>> triplet = new ArrayList<>(); // This list contrains list of integers
        
        for (int i = 0 ; i < nums.length ; i ++){ // i is our fixed element which will be iterated through the loop 
            
            if(i>0 && nums[i]==nums[i-1]){
                continue; // Avoid duplicate values, first condition prevents out of bound scenarios
            }
            
            int j = i + 1; // Fixing i: j and k are control variables, and we obviously don't want i and j to be equal
            int k = nums.length - 1; 
            
            while (j<k){
                if (k < nums.length - 1 && nums[k] == nums[k + 1]) { // Similar to i, we are going to make sure that duplicate values are skipped
                    k--;
                    continue;
                } 
                if( nums[i] + nums[j] + nums[k] == 0){
                    triplet.add(Arrays.asList(nums[i],nums[j],nums[k]));
                    j++; //Standard procedure
                    k--; //Standard procedure
                }
                else if (nums[i]+nums[j]+nums[k] > 0){
                    k--; // We need k controller to use lesser value since sum is positive
                }
                else {
                    j++; // We need j controller to use higher value since sum is negative
                }
            }
        }
        return triplet;
    }
}