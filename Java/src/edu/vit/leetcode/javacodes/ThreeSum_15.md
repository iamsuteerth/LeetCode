# 3Sum #15
## Problem Description
<font size="4">
Given an integer array nums, return all the triplets<br><font color="red">[ nums[i], nums[j], nums[k] ]</font> such that <br><font color="lime">i != j, i != k and j != k </font> and <br><font color="cyan">nums[i] + nums[j] + nums[k] == 0
</font>
<br><br>

***Notice that the solution set must not contain duplicate triplets.***
### Sample Inputs
<p align="center">
<font color="red">Input:</font> nums = [ -1, 0, 1, 2, -1, -4 ]<br>
<font color="lime">Output</font> = [ [-1, -1, 2 ], [ -1, 0, 1] ]
</p>
<p align="center">
<font color="red">Input:</font> nums = [ 0, 1, 1 ]<br>
<font color="lime">Output</font> = [ ]<br>No Possible triplet 
</p>
<p align="center">
<font color="red">Input:</font> nums = [ 0, 0, 0 ]<br>
<font color="lime">Output</font> = [ [ 0, 0, 0 ] ]<br>Only Possible triplet 
</p>