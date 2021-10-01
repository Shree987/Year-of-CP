/*
Author : Shreeraksha R Aithal
Problem name : Longest Common Subsequence
Problem link : https://leetcode.com/problems/longest-common-subsequence/
Difficulty : Medium
Tags : Dynamic Programming, String
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size(), i, j;
        int dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));
        for(i = 1; i <= n; i++){
            for(j =1; j <= m; j++){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(text1[i-1] == text2[j-1])    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            }
        }
        return dp[n][m];
    }
};