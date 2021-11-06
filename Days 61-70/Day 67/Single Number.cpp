/*
Author : Shreeraksha R Aithal
Problem name : Single Number
Problem link : https://leetcode.com/problems/single-number/
Difficulty : Easy
Tags : Array, Bit Manipulation
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++)    nums[0] = nums[0] xor nums[i];
        return nums[0];
    }
};