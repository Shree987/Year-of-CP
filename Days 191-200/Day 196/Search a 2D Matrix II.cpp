/*
Author : Shreeraksha R Aithal
Problem name : Search a 2D Matrix II
Problem link : https://leetcode.com/problems/search-a-2d-matrix-ii/
Difficulty : Medium
Tags : Array, Binary Search, Divide and Conquer, Matrix
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i, j, n = matrix.size(), m = matrix[0].size();
        if(target < matrix[0][0] || target > matrix[n-1][m-1])      return false;
        i = 0;
        j = m-1;
        while(i < n && j > -1){
            if(target == matrix[i][j])      return true;
            if(target > matrix[i][j])       i++;
            else    j--;
        }
        return false;
    }
};