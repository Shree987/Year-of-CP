/*
Author : Shreeraksha R Aithal
Problem name : Spiral Matrix II
Problem link : https://leetcode.com/problems/spiral-matrix-ii/
Difficulty : Medium
Tags : 
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int i, j, k, index = 1;
        vector<vector<int>> arr(n, vector<int>(n, 0));
        for(k = 0; index < n*n; k++){
            for(j = k; j < n-k-1; j++){
                arr[k][j] = index;
                index++;
            }
            for(i = k; i < n-k-1; i++){
                arr[i][n-k-1] = index;
                index++;
            }
            for(j = n-k-1; j > k; j--){
                arr[n-k-1][j] = index;
                index++;
            }
            for(i = n-k-1; i > k; i--){
                arr[i][k] = index;
                index++;
            }
        }
        if(index == n*n)          arr[k][k] = n*n;
        return arr;
    }
};