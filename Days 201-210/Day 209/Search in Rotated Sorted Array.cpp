/*
Author : Shreeraksha R Aithal
Problem name : Search in Rotated Sorted Array
Problem link : https://leetcode.com/problems/search-in-rotated-sorted-array/
Difficulty : Medium
Tags : Array, Binary Search
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        
        while(left <= right){
            if(nums[left] == target)        return left;
            if(nums[right] == target)        return right;
            if(left+1 >= right)       return -1;
            
            int mid = left + (right-left)/2;
            if(nums[mid] == target)     return mid;
            
            if(nums[left] < nums[right]){
                if(nums[mid] == target)     return mid;
                if(nums[mid] > target)      right = mid-1;
                else    left = mid+1;
            }
            else{
                if(nums[mid] > nums[left]){
                    if(nums[mid] < target)      left = mid+1;
                    else if(nums[left] > target)    left = mid+1;
                    else    right = mid-1;
                }
                else{
                    if(nums[mid] > target)      right = mid-1;
                    else if(nums[left] < target)    right = mid-1;
                    else    left = mid+1;
                }
            }
        }
        return -1;
    }
};