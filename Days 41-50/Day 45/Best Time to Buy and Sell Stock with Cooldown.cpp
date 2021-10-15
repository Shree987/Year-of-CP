/*
Author : Shreeraksha R Aithal
Problem name : Best Time to Buy and Sell Stock with Cooldown
Problem link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
Difficulty : Medium
Tags : Array, Dynamic Programming
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i, j, k, n = prices.size(), ans = 0, Max = 0;
        vector<int> dp(n+2, 0);
        for(i = n-1; i >= 0; i--){
            dp[i] = dp[i+1];
            dp[i] = max(dp[i], Max - prices[i]);
            ans = max(ans, dp[i]);
            Max = max(Max, prices[i] + dp[i+2]);
        }
        return ans;
    }
};