/*
Author : Shreeraksha R Aithal
Problem name : Maximal Square
Problem link : https://leetcode.com/problems/maximal-square/
Difficulty : Medium
Tags : Array, Dynamic Programming, Matrix
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int k, n = matrix.size(), m = matrix[0].size(), ans = 0;
        k = min(m, n);
        vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                dp[i][j] = (matrix[i-1][j-1]-'0') + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }
        for(int i = n; i >= 0; i--){
            for(int j = m; j >= 0; j--){
                for(int x = 0; i-x-1>=0 && j-x-1>=0; x++){
                    int sum1 = dp[i][j] - dp[i-x-1][j] - dp[i][j-x-1] + dp[i-x-1][j-x-1];
                    int sum2 = (x+1)*(x+1);
                    if(sum1 == sum2)    ans = max(sum2, ans);
                    else    break;
                }
            }
        }
        return ans;
    }
};