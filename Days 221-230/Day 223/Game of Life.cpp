/*
Author : Shreeraksha R Aithal
Problem name : Game of Life
Problem link : https://leetcode.com/problems/game-of-life/
Difficulty : Medium
Tags : Array, Matrix, Simulation
*/

class Solution {
    /*
        0 turned 1 : 2
        1 turned 0 : 3
    */
public:
    void gameOfLife(vector<vector<int>>& board) {
        int cnt = 0, i, j, n = board.size(), m = board[0].size();
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                cnt = 0;
                if(i-1>=0 && (board[i-1][j] == 1 || board[i-1][j] == 3))        cnt++;
                if(j-1>=0 && (board[i][j-1] == 1 || board[i][j-1] == 3))        cnt++;
                if(i+1<n && (board[i+1][j] == 1 || board[i+1][j] == 3))        cnt++;
                if(j+1<m && (board[i][j+1] == 1 || board[i][j+1] == 3))        cnt++;
                if(i-1>=0 && j-1>=0 && (board[i-1][j-1] == 1 || board[i-1][j-1] == 3))        cnt++;
                if(j-1>=0 && i+1<n && (board[i+1][j-1] == 1 || board[i+1][j-1] == 3))        cnt++;
                if(i+1<n && j+1<m && (board[i+1][j+1] == 1 || board[i+1][j+1] == 3))        cnt++;
                if(j+1<m && i-1>=0 && (board[i-1][j+1] == 1 || board[i-1][j+1] == 3))        cnt++;
                if(board[i][j] == 0 && cnt == 3)        board[i][j] = 2;
                else if(board[i][j] == 1 && (cnt < 2 || cnt > 3))      board[i][j] = 3;
            }
        }
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                if(board[i][j] == 2)        board[i][j] = 1;
                else if(board[i][j] == 3)   board[i][j] = 0;
            }
        }
    }
};