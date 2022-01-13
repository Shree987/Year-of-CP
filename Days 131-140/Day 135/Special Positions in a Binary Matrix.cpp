/*
Author : Shreeraksha R Aithal
Problem name : Special Positions in a Binary Matrix
Problem link : https://leetcode.com/problems/special-positions-in-a-binary-matrix/
Difficulty : Easy
Tags : Array, Matrix
*/

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int count = 0, n = mat.size(), m = mat[0].size(), i, j;
        vector<int> row(n, 0), col(m, 0);
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                row[i] += mat[i][j];
                col[j] += mat[i][j];
            }
        }
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                count += mat[i][j]*(row[i] == 1 && col[j] == 1);
            }
        }
        return count;
    }
};