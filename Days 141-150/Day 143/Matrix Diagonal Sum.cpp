/*
Author : Shreeraksha R Aithal
Problem name : Matrix Diagonal Sum
Problem link : https://leetcode.com/problems/matrix-diagonal-sum/
Difficulty : Easy
Tags : Array, Matrix
*/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = (n%2 == 0 ? 0 : -mat[n/2][n/2]);
        for(int n = mat.size(), i = 0; i < n; i++){
            sum += mat[i][i] + mat[n-i-1][i];
        }
        return sum;
    }
};
