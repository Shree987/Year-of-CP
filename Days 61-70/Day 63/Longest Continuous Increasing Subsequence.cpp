/*
Author : Shreeraksha R Aithal
Problem name : Longest Continuous Increasing Subsequence
Problem link : https://leetcode.com/problems/longest-continuous-increasing-subsequence/
Difficulty : Easy
Tags : Array
*/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {        
        int m = 1, i = 0;
        while(i < nums.size()){
            int j = i+1;
            while(j<nums.size() && nums[j] > nums[j-1])     j++;
            m = max(m, j-i);
            i = j;
        }
        return m;
    }
};