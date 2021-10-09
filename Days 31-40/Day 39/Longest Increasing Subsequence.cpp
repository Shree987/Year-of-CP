/*
Author : Shreeraksha R Aithal
Problem name : Longest Increasing Subsequence
Problem link : https://leetcode.com/problems/longest-increasing-subsequence/
Difficulty : Medium
Tags : Array, Binary Search, Dynamic Programming
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int i, j, n = nums.size(), Max = 1;
        vector<int> dp(n, 1);
        for(i = 1; i < n; i++){
            for(j = 0 ; j < i; j++){
                if(nums[i] > nums[j])     dp[i] = max(dp[j]+1, dp[i]);
            }
            Max = max(Max, dp[i]);
        }
        return Max;
    }
};