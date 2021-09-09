/*
Author : Shreeraksha R Aithal
Problem name : Largest Plus Sign
Problem link : https://leetcode.com/problems/largest-plus-sign/
Difficulty : Medium
Tags : Array, Dynamic Programming
*/

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int i, j, ans = 0, dp[n][n][5];
        memset(dp, 0, sizeof(dp));
        for(auto v : mines){
            dp[v[0]][v[1]][0] = 1;
        }
        // Horizontal
        for(i = 0; i < n; i++){
            // Left
            dp[i][0][1] = 1-dp[i][0][0];
            for(j = 1; j < n; j++){
                dp[i][j][1] = (1-dp[i][j][0])*(1 + dp[i][j-1][1]);
            }
            // Right
            dp[i][n-1][2] = 1-dp[i][n-1][2];
            for(j = n-2; j >= 0; j--){
                dp[i][j][2] = (1-dp[i][j][0])*(1 + dp[i][j+1][2]);
            }
        }
        // Vertical
        for(i = 0; i < n; i++){
            // Up
            dp[0][i][3] = 1-dp[0][i][0];
            for(j = 1; j < n; j++){
                dp[j][i][3] = (1-dp[j][i][0])*(1 + dp[j-1][i][3]);
            }
            // Down
            dp[n-1][i][4] = 1-dp[n-1][i][0];
            for(j = n-2; j >= 0; j--){
                dp[j][i][4] = (1-dp[j][i][0])*(1 + dp[j+1][i][4]);
            }
        }
        for(i = 0; i<n; i++){
            for(j = 0; j < n; j++){
                ans = max(ans, (1 - dp[i][j][0])*min(min(dp[i][j][1], dp[i][j][2]), min(dp[i][j][3], dp[i][j][4])));
                
            }
        }
        return ans;
    }
};