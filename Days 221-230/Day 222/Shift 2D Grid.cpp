/*
Author : Shreeraksha R Aithal
Problem name : Shift 2D Grid
Problem link : https://leetcode.com/problems/shift-2d-grid/
Difficulty : Easy
Tags : Array, Matrix, Simulation
*/

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int index, m = grid.size(), n = grid[0].size();
        k = k%(m*n);
        if(k == 0)      return grid;
        index = n*m-1;
        stack<int> st;
        while(index >= 0){          
            if((index+k)%(m*n) < index)     st.push(grid[index/n][index%n]);
            else{
                int row = (index+k)/n, col = (index+k)%n;
                grid[row][col] = grid[index/n][index%n];
            }
            index--;
        }
        index = 0;
        while(!st.empty()){
            grid[index/n][index%n] = st.top();
            st.pop();
            index++;
        }
        return grid;
    }
};