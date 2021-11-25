/*
Author : Shreeraksha R Aithal
Problem name : Maximum Subarray
Problem link : https://leetcode.com/problems/maximum-subarray/
Difficulty : Easy
Tags : Array, Divide and Conquer, 
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0], Max = nums[0], n = nums.size();
        for(int i = 1; i < n; i++){
            sum = nums[i] + max(sum, 0);
            Max = max(sum, Max);
        }
        return Max;
    }
};