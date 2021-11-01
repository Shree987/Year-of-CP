/*
Author : Shreeraksha R Aithal
Problem name : Surrounded Regions
Problem link : https://leetcode.com/problems/surrounded-regions/
Difficulty : Medium
Tags : Array, Breadth-first Search, Depth-first Search, Matrix, Union Find
*/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> q;
        int x, y, n = board.size(), m = board[0].size();
        for(x = 0; x < n; x++){
            if(board[x][0] == 'O'){
                q.push({x, 0});
                board[x][0] = '*';
            }
            if(board[x][m-1] == 'O'){
                q.push({x, m-1});
                board[x][m-1] = '*';
            }
        }
        for(x = 1; x < m-1; x++){
            if(board[0][x] == 'O'){
                q.push({0, x});
                board[0][x] = '*';
            }
            if(board[n-1][x] == 'O'){
                q.push({n-1, x});
                board[n-1][x] = '*';
            }
        }
        while(!q.empty()){
            x = q.front().first;
            y = q.front().second;
            q.pop();
            if(x>0 && board[x-1][y] == 'O'){
                q.push({x-1, y});
                board[x-1][y] = '*';                
            }
            if(y>0 && board[x][y-1] == 'O'){
                q.push({x, y-1});
                board[x][y-1] = '*';                
            }
            if(x<n-1 && board[x+1][y] == 'O'){
                q.push({x+1, y});
                board[x+1][y] = '*';                
            }
            if(y<m-1 && board[x][y+1] == 'O'){
                q.push({x, y+1});
                board[x][y+1] = '*';                
            }
        }
        for(x = 0;x < n; x++){
            for(y = 0; y < m; y++){
                if(board[x][y] == 'O')      board[x][y] = 'X';
                else if(board[x][y] == '*')     board[x][y] = 'O';
            }
        }
    }
};