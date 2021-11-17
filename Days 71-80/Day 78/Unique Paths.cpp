/*
Author : Shreeraksha R Aithal
Problem name : Unique Paths
Problem link : https://leetcode.com/problems/unique-paths/
Difficulty : Medium
Tags : Combinatorics, Dynamic Programming, Math
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m > n)   swap(n, m);
        vector<int> dp(m, 1);
        while(n>1){
            for(int j = 1; j < m; j++){
                dp[j]+=dp[j-1];
            }
            n--;
        }
        return dp[m-1];
    }
};