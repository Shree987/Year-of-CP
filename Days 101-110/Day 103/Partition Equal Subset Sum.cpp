/*
Author : Shreeraksha R Aithal
Problem name : Partition Equal Subset Sum
Problem link : https://leetcode.com/problems/partition-equal-subset-sum/
Difficulty : Medium
Tags : Array, Dynamic Programming
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int i = 0; i < nums.size(); i++){
            total += nums[i];
        }
        if(total%2 == 1)      return false;
        vector<bool> dp(total+1, false);
        dp[0] = true;
        for(int j, i = 0; !dp[total/2] && i < nums.size(); i++){
            for(j = total; !dp[total/2] && j >= nums[i]; j--){
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp[total/2];
    }
};