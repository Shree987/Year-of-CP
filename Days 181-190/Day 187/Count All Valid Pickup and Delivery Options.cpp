/*
Author : Shreeraksha R Aithal
Problem name : Count All Valid Pickup and Delivery Options
Problem link : https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/
Difficulty : Hard
Tags : Combinatorics, Dynamic Programming, Math
*/

#define ll long long
#define m 1000000007
class Solution {
    vector<ll> fact;
public:
    int countOrders(int n) {
        if(n == 1)      return 1;
        fact.resize(n+1);
        ll i, j;
        vector<vector<ll>> dp(n+1, vector<ll> (n+1, 0));
        dp[0][0] = 0;
        dp[0][1] = 1;
        for(i = 2; i <= n; i++){
            dp[0][i] = (i * dp[0][i-1])%m;
        }
        for(i = 1; i <= n; i++){
            for(j = i; j <= n; j++){
                dp[i][j] = ((i*(dp[i-1][j]))%m + ((j-i)*(dp[i][j-1]))%m )%m;
            }
        }
        return dp[n][n];
    }
};