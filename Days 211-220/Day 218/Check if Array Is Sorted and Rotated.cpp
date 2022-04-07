/*
Author : Shreeraksha R Aithal
Problem name : Check if Array Is Sorted and Rotated
Problem link : https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
Difficulty : Easy
Tags : Array
*/

class Solution {
public:
    bool check(vector<int>& nums) {
        int index = 1;
        bool rotated = false;
        while(index < nums.size()){
            if(nums[index] < nums[index-1]){
                if(rotated)     return false;
                rotated = true;
            }
            index++;
        }
        return (!rotated || nums[0]>=nums.back());
    }
};