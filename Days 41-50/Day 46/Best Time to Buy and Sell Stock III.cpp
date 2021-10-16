/*
Author : Shreeraksha R Aithal
Problem name : Best Time to Buy and Sell Stock III
Problem link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
Difficulty : Hard
Tags : Array, Dynamic Programming
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
 
        int i, n = prices.size(), m, ans = 0;
        vector<int> dp(n+2,0);
        m = prices[n-1];
        for(i = n-2; i>=0;i--){
            dp[i]=max(dp[i+1], max(0, m - prices[i]));
            m = max(m, prices[i]);
        }
        ans = dp[0];
        m = prices[0];
        for(i=1;i<n;i++){
            ans = max(ans, prices[i]-m + dp[i+1]);
            m = min(m, prices[i]);
        }
        return ans;
    }
};