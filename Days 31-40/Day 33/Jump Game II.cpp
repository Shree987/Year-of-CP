/*
Author : Shreeraksha R Aithal
Problem name : Jump Game II
Problem link : https://leetcode.com/problems/jump-game-ii/
Difficulty : Medium
Tags : Array, Dynamic Programming, Greedy
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int i, j, n = nums.size();
        vector<int> dp(n, 3*n);
        dp[n-1] = 0;
        for(i = n-2; i >=0; i--){
            for(j = i+1; j<n && j<=i+nums[i]; j++){
                dp[i] = min(dp[i], dp[j]+1);
            }
        }
        return dp[0];
    }
};