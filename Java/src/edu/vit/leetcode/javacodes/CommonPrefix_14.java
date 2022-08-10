package edu.vit.leetcode.javacodes;

public class CommonPrefix_14 {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0){
            return "";
        }
        // We have no string only, so nothing common we can return
        if (strs.length==1){
            return strs[0];
        }
        // We return the entire string since its common to the only string there
        // Now we are going to find the lowest length of the string (for >= 2 strings present)
        int maxLength = strs[0].length();
        String arr = strs[0];
        for(String s : strs){
            if (s.length() < maxLength){
                maxLength = s.length();
            }
        }
        // Finding common substring
        for(String s : strs){
            for(int i = maxLength ; i >=0 ; i--){
                if(arr.indexOf(s.substring(0, i)) == 0){ 
                    arr = s.substring(0,i);
                    break;
                }
            }
        }
        return arr;
    }
}
