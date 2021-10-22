/*
Author : Shreeraksha R Aithal
Problem name : Coin Change
Problem link : https://leetcode.com/problems/coin-change/
Difficulty : Medium
Tags : Array, Breadth-first Search, Dynamic Programming
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX-1);
        dp[0] = 0;
        sort(coins.begin(), coins.end());
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < coins.size(); j++){
                if(coins[j] > i)    break;
                if(coins[j] == i)   dp[i] = 1;
                else    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
        if(dp[amount] == INT_MAX-1)     return -1;
        return dp[amount];
    }
};