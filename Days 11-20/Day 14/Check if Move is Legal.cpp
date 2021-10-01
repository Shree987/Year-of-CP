/*
Author : Shreeraksha R Aithal
Problem name : Check if Move is Legal
Problem link : https://leetcode.com/problems/check-if-move-is-legal/
Difficulty : Medium
Tags : Array, Enumeration, Matrix
*/

class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        int x,y,i,j;        
        // Vertical
        for(i = rMove+1; i < 8; i++){            
            if(board[i][cMove] == '.'){
                i = 8;
                break;
            }
            if(board[i][cMove] == color)    break;
        }
        if(i > rMove+1 && i < 8)    return true;
        for(i = rMove-1; i >= 0; i--){
            if(board[i][cMove] == '.'){
                i = -1;
                break;
            }
            if(board[i][cMove] == color)    break;
        }
        if(i < rMove-1 && i >= 0)    return true;
        
        // Horizontal
        for(j = cMove+1; j < 8; j++){
            if(board[rMove][j] == '.'){
                j = 8;
                break;
            }
            if(board[rMove][j] == color)    break;
        }
        if(j > cMove+1 && j < 8)    return true;        
        for(j = cMove-1; j >= 0; j--){
            if(board[rMove][j] == '.'){
                j = -1;
                break;
            }
            if(board[rMove][j] == color)    break;
        }
        if(j < cMove-1 && j > -1)    return true;
        
        // Main diagonal
        for(i = rMove+1, j = cMove+1; i < 8 && j<8; i++, j++){
            if(board[i][j] == '.'){
                i = -1;
                break;
            }
            if(board[i][j] == color)    break;
        }
        if(i > rMove+1 && i < 8 && j > cMove+1 && j < 8)    return true;         
        for(i = rMove-1, j = cMove-1; i>=0 && j>=0; i--, j--){
            if(board[i][j] == '.'){
                j = -1;
                break;
            }
            if(board[i][j] == color)    break;
        }
        if(i < rMove-1 && i>=0 && j<cMove-1 && j>=0)    return true;
        
        // Other diagonal
        for(i = rMove+1, j = cMove-1; i < 8 && j>=0; i++, j--){
            if(board[i][j] == '.'){
                j = -1;
                break;
            }
            if(board[i][j] == color)    break;
        }
        if(i > rMove+1 && i < 8 && j < cMove-1 && j>=0)    return true;         
        for(j = cMove+1, i = rMove-1; i>=0 && j<8; i--, j++){
            if(board[i][j] == '.'){
                i = -1;
                break;
            }
            if(board[i][j] == color)    break;
        }
        if(i < rMove-1 && i>=0 && j > cMove+1 && j < 8)    return true; 
        return false;
    }
};