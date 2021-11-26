/*
Author : Shreeraksha R Aithal
Problem name : Search Insert Position
Problem link : https://leetcode.com/problems/search-insert-position/
Difficulty : Easy
Tags : Array, Binary Search
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums[0] >= target)   return 0;
        int r = nums.size()-1, l = 0, m;
        if(nums[r] < target)  return r+1;
        while(l < r){
            m = l + (r-l)/2;
            if(nums[m] == target)  return m;
            if(nums[m] < target)  l = m+1;
            else if(nums[m-1] < target)     return m;
            else    r = m-1;
        }
        return r;
    }
};