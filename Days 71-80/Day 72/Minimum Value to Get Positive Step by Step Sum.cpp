/*
Author : Shreeraksha R Aithal
Problem name : Minimum Value to Get Positive Step by Step Sum
Problem link : https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/
Difficulty : Easy
Tags : Array, Prefix Sum
*/

class Solution {
public:
    int minStartValue(vector<int>& nums) {
       int ans = 1, val = 0; 
        for(int i = 0; i < nums.size(); i++){
            val += nums[i];
            if(val < 0)     ans = max(ans, abs(val)+1);
        }
        return ans;
    }
};