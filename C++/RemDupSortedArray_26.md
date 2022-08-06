# Problem Description
<b>
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.
</b>
<br>
<br>
<font size = "4">
You CANNOT change the array size, i.e. use .erase() or .remove() like functions
</font>

<br>
<br>
<b>
You need to return the index till which the nums array must be read.
</b>

## Sample INPUTS


<p align="center">
<font size=4">
Input: nums = [0,0,1,1,1,2,2,3,3,4]<br>
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]<br>
k = 5
<br><br>
Input: nums = [1,1,2]<br>
Output: 2, nums = [1,2,_]<br>
k = 2
<br><br>
