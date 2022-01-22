/*
Author : Shreeraksha R Aithal
Problem name : Surface Area of 3D Shapes
Problem link : https://leetcode.com/problems/surface-area-of-3d-shapes/
Difficulty : Easy
Tags : Array, Geometry, Math, Matrix
*/

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size(), i, j, sum;
        sum = 2*n*n;
        for(i = 0; i < n; i++){
            sum += grid[0][i] + grid[i][0] + grid[n-1][i] + grid[i][n-1];
        }
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if(grid[i][j] == 0)     sum -= 2;
                if(i+1<n)   sum += abs(grid[i][j] - grid[i+1][j]);
                if(j+1<n)   sum += abs(grid[i][j] - grid[i][j+1]);
            }
        }
        return sum;
    }
};