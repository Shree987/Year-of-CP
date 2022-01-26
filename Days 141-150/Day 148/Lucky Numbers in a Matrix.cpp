/*
Author : Shreeraksha R Aithal
Problem name : Lucky Numbers in a Matrix
Problem link : https://leetcode.com/problems/lucky-numbers-in-a-matrix/
Difficulty : Easy
Tags : Array, Matrix
*/

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int i, j, n = matrix.size(), m = matrix[0].size();
        vector<int> row(n, INT_MAX), col(m, INT_MIN), arr;
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                row[i] = min(row[i], matrix[i][j]);
                col[j] = max(col[j], matrix[i][j]);
            }
        }
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                if(row[i] == matrix[i][j] && col[j]== matrix[i][j])     arr.push_back(matrix[i][j]);
            }
        }
        return arr;
    }
};