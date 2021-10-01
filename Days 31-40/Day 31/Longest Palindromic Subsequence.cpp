/*
Author : Shreeraksha R Aithal
Problem name : Longest Palindromic Subsequence
Problem link : https://leetcode.com/problems/longest-palindromic-subsequence/
Difficulty : Medium
Tags : Dynamic Programming, String
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // Equivalent to longest common subsequence of the string and its reverse
        int n = s.size(), i, j;
        int dp[n+1][n+1];
        memset(dp, 0, sizeof(dp));
        for(i = 1; i <= n; i++){
            for(j =1; j <= n; j++){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(s[i-1] == s[n-j])    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            }
        }
        return dp[n][n];
    }
};