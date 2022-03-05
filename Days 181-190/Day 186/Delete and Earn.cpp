/*
Author : Shreeraksha R Aithal
Problem name : Delete and Earn
Problem link : https://leetcode.com/problems/delete-and-earn/
Difficulty : Medium
Tags : Array, Dynamic Programming, Hash Table
*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> dp;
        int Max = nums[0];
        for(auto val: nums){
            Max = max(val, Max);
            dp[val] += val;

        }
        for(int val = 2; val <= Max; val++){
            dp[val] = max(dp[val - 2] + dp[val], dp[val - 1]);
        }
        return dp[Max];
    }
};