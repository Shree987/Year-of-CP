/*
Author : Shreeraksha R Aithal
Problem name : Find Minimum in Rotated Sorted Array
Problem link : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
Difficulty : Medium
Tags : Array, Binary Search
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int i, j, n = nums.size();
        if(n == 1)      return nums[0];
        if(n == 2)      return min(nums[0], nums[1]);
        if(nums[0] < nums[n-1])     return nums[0];
        if(nums[n-1] < nums[n-2])     return nums[n-1];
        i = 0;
        j = n-1;
        while(i < j){
            n = (j-i)/2 + i;
            if(nums[n] < nums[n+1] && nums[n] < nums[n-1])      return nums[n];
            if(nums[n] > nums[0])   i = n+1;
            else    j = n;
        }
        return nums[i];
    }
};