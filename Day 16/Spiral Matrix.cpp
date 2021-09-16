/*
Author : Shreeraksha R Aithal
Problem name : Spiral Matrix
Problem link : https://leetcode.com/problems/spiral-matrix/
Difficulty : Medium
Tags : Array, Matrix, Simulation
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i, j, k, x, y, ind = 0, n = matrix.size(), m = matrix[0].size(), K;
        vector<int> ans(n*m);
        K = min(n, m);
        for(k = 0; k < K-k; k++){
            for(j = k; ind < n*m && j < m-k; j++){
                ans[ind++] = matrix[k][j];
            }
            for(i = k+1; ind < n*m && i < n-k; i++){
                ans[ind++] = matrix[i][m-k-1];
            }
            for(j = m-k-2; ind < n*m && j >= k; j--){
                ans[ind++] = matrix[n-k-1][j];
            }
            for(i = n-k-2; ind < n*m && i > k; i--){
                ans[ind++] = matrix[i][k];
            }
        }
        return ans;
    }
};