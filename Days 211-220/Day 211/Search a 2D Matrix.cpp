/*
Author : Shreeraksha R Aithal
Problem name : Search a 2D Matrix
Problem link : https://leetcode.com/problems/search-a-2d-matrix/
Difficulty : Medium
Tags : Array, Binary Search, Matrix
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left, right, mid, index = 0, n = matrix.size(), m = matrix[0].size();
        if(target < matrix[0][0] || target > matrix[n-1][m-1])      return false;
        if(matrix[0][m-1] < target){
            left = 0;
            right = n-1;
            while(left < right){
                mid = left + (right-left)/2;
                if(matrix[mid][m-1] == target)       return true;
                else if(matrix[mid][m-1] < target)       left = mid+1;
                else    right = mid;
            }
            index = left;
        }
        left = 0;
        right = m-1;
        while(left < right){
            mid = left + (right-left)/2;
            if(matrix[index][mid] == target)       return true;
            else if(matrix[index][mid] < target)       left = mid+1;
            else    right = mid;
        }
        return (matrix[index][left] == target);
    }
};