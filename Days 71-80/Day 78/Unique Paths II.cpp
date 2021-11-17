/*
Author : Shreeraksha R Aithal
Problem name : Unique Paths II
Problem link : https://leetcode.com/problems/unique-paths-ii/
Difficulty : Medium
Tags : Array, Dynamic Programming, Matrix
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1)  return 0;
        obstacleGrid[0][0] = 1;
        for(int i = 1; i < m || i < n; i++){
            if(i<m)     obstacleGrid[0][i] = (1 - obstacleGrid[0][i])*obstacleGrid[0][i-1];
            if(i<n)     obstacleGrid[i][0] = (1 - obstacleGrid[i][0])*obstacleGrid[i-1][0];
        }
        for(int j, i = 1; i < n; i++){
            for(j = 1; j < m; j++){
                obstacleGrid[i][j] = (1 - obstacleGrid[i][j])*(obstacleGrid[i][j-1] + obstacleGrid[i-1][j]);
            }
        }
        return obstacleGrid[n-1][m-1];
    }
};