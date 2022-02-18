/*
Author : Shreeraksha R Aithal
Problem name : Coloring A Border
Problem link : https://leetcode.com/problems/coloring-a-border/
Difficulty : Medium
Tags : Array, Breadth-first Search, Depth-first Search, Matrix
*/

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        queue<pair<int,int>> q;
        int i, j, n = grid.size(), m = grid[0].size(), clr = grid[row][col];
        q.push({row, col});
        grid[row][col] = 0;
        while(!q.empty()){
            row = q.front().first;
            col = q.front().second;
            q.pop();
            if(row == 0 || row == n-1 || col == 0 || col == m-1){
                grid[row][col] = -2;
            }
            else if((grid[row-1][col] != clr && grid[row-1][col] > 0) || (grid[row+1][col] != clr && grid[row+1][col] > 0) ||
                    (grid[row][col-1] != clr && grid[row][col-1] > 0) || (grid[row][col+1] != clr && grid[row][col+1] > 0)){
                grid[row][col] = -2;
            }
            else{
                grid[row][col] = -1;
            }
            if(row-1>=0 && grid[row-1][col] == clr){
                grid[row-1][col] = 0;
                q.push({row-1, col});
            }
            if(row+1<n && grid[row+1][col] == clr){
                grid[row+1][col] = 0;
                q.push({row+1, col});
            }
            if(col-1>=0 && grid[row][col-1] == clr){
                grid[row][col-1] = 0;
                q.push({row, col-1});
            }
            if(col+1<m && grid[row][col+1] == clr){
                grid[row][col+1] = 0;
                q.push({row, col+1});
            }
        }
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                if(grid[i][j] == -2)    grid[i][j] = color;
                if(grid[i][j] == -1)    grid[i][j] = clr;
            }
        }
        return grid;
    }
};