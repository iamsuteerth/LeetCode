package edu.vit.leetcode.javacodes;

import java.util.Arrays;

public class PlusOne_66 {
    public static long converter(int[] digits) {
        long ans = 0;
        for(int i = 0 ; i < digits.length ; i++){
            ans = ans*10 + (long)digits[i];
        }
        System.out.println(ans);
        return ans;
    }
    public static int sizer(long nums){
        String temp = Long.toString(nums);
        int size = temp.length();
        return size;
    }
    public static int[] plusOne(int[] digits) {
        long num = converter(digits);
        num++;
        int size = sizer(num);
        System.out.println(size);
        String arr = Long.toString(num); 
        int[] array = new int[size];
        for(int i = 0 ; i < size; i++){
            array[i] = (int)(arr.charAt(i)-'0');
        }
        return array;
    }
    public static void main(String[] args) {
        int[] digits = new int[]{9,8,7,6,5,4,3,2,1,0};
        int[] ans = plusOne(digits);
        System.out.println(Arrays.toString(ans));
    }
}
