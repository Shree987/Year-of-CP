/*
Author : Shreeraksha R Aithal
Problem name : Valid Sudoku
Problem link : https://leetcode.com/problems/valid-sudoku/
Difficulty : Medium
Tags : Array, Hash Table, Matrix
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int i, j, x, y, m, k;
        for(i = 0; i < 9; i++){
            m = 0;
            for(j = 0; j < 9; j++){
                if(board[i][j] == '.')      continue;
                k = 1 << (board[i][j]-'0');
                if(m & k)   return false;
                m = m | k;
            }
        }
        for(i = 0; i < 9; i++){
            m = 0;
            for(j = 0; j < 9; j++){
                if(board[j][i] == '.')      continue;
                k = 1 << (board[j][i]-'0');
                if(m & k)   return false;
                m = m | k;
            }
        }
        for(x = 0; x < 9; x+=3){
            for(y = 0; y < 9; y+=3){
                m = 0;
                for(i = x; i < x+3; i++){
                    for(j = y; j < y+3; j++){
                        if(board[i][j] == '.')      continue;
                        k = 1 << (board[i][j]-'0');
                        if(m & k)   return false;
                        m = m | k;
                    }
                }
            }
        }
        return true;
    }
};