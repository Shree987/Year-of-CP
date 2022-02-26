/*
Author : Shreeraksha R Aithal
Problem name : Minimum Path Sum
Problem link : https://leetcode.com/problems/minimum-path-sum/
Difficulty : Medium
Tags : Array, Dynamic Programming, Matrix
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(i-1 >= 0 && j-1 >= 0){
                    grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
                }
                else if(i-1 >= 0){
                    grid[i][j] += grid[i-1][j];
                }
                else if(j-1 >= 0){
                    grid[i][j] += grid[i][j-1];
                }
            }        
        }
        return grid[grid.size()-1][grid[0].size()-1];
    }
};