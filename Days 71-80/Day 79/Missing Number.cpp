/*
Author : Shreeraksha R Aithal
Problem name : Missing Number
Problem link : https://leetcode.com/problems/missing-number/
Difficulty : Easy
Tags : Array, Bit Manipulation, Hash Table, Math, String
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0, n = nums.size();
        for(i = 0; i < n; i++){
            if(nums[i] == i || nums[i] == n)      continue;
            swap(nums[i], nums[nums[i]]);
            i--;
        }
        for(i = 0; i < n; i++){
            if(nums[i] != i)      return i;
        }
        return n;
    }
};