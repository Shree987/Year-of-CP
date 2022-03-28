/*
Author : Shreeraksha R Aithal
Problem name : Search in Rotated Sorted Array II
Problem link : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
Difficulty : Medium
Tags : Array, Binary Search
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        if(nums[left] == target || nums[right] == target)       return true;
        while(left <= right && nums[left] == nums[0])       left++;
        if(left > right)        return false;
        while(left <= right && nums[right] == nums.back())       right--;
        
        while(left <= right){
            if(left == right || nums[left] == nums[right]){
                return (nums[left] == target);
            }
            if(left+1 == right){
                return ((nums[left] == target) || (nums[right] == target));
            }
            int mid = left + (right-left)/2;
            if(nums[mid] == target || nums[left] == target || nums[right] == target)     return true;
            if(nums[left] < nums[right]){
                if(nums[mid] == target)     return true;
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
        return false;
    }
};