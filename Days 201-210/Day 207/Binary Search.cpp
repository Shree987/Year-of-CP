/*
Author : Shreeraksha R Aithal
Problem name : Binary Search
Problem link : https://leetcode.com/problems/binary-search/
Difficulty : Easy
Tags : Array, Binary Search
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
       if(target < nums[0] || target > nums.back())     return -1;
        int left = 0, right = nums.size()-1, mid;
        while(left < right){
            mid = left + (right-left)/2;
            if(nums[mid] == target)         return mid;
            else if(nums[mid] > target)     right = mid-1;
            else    left = mid+1;
        }
        if(left == right && nums[left] == target)       return left;
        return -1;
    }
};