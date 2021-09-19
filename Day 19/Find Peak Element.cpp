/*
Author : Shreeraksha R Aithal
Problem name : Find Peak Element
Problem link : https://leetcode.com/problems/find-peak-element/
Difficulty : Medium
Tags : Array, Binary Search
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1)    return 0;
        int i, j = nums.size()-1, k;
        if(nums[0] > nums[1])   return 0;
        if(nums[j] > nums[j-1])   return j;
        i = 1;
        j--;
        while(i < j){
            k = (i+j)/2;
            if(nums[k] > nums[k-1]  && nums[k] > nums[k+1])     return k;
            if(nums[k] < nums[k+1])     i = k+1;
            else    j = k-1;
        }
        return i;
    }
};