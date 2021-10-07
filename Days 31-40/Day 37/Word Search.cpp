/*
Author : Shreeraksha R Aithal
Problem name : Word Search
Problem link : https://leetcode.com/problems/word-search/
Difficulty : Medium
Tags : Array, Backtracking, Matrix
*/

class Solution {
    int n, m;
    bool ans;
    bool dp[6][6];
    void dfs(int i, int j, vector<vector<char>>& board, string word, int index){
        if(index >= word.size()-1){
            ans = true;
            return ;
        }
        if(word[index] != board[i][j])      return ;
        dp[i][j] = true;
        if(i-1>=0 && word[index+1] == board[i-1][j] && !dp[i-1][j]){
            dfs(i-1,j,board, word, index+1);
        }
        if(ans)     return;
        if(j-1>=0 && word[index+1] == board[i][j-1] && !dp[i][j-1]){
            dfs(i,j-1,board, word, index+1);
        }
        if(ans)     return;
        if(i+1<n && word[index+1] == board[i+1][j] && !dp[i+1][j]){
            dfs(i+1,j,board, word, index+1);
        }
        if(ans)     return;
        if(j+1<m && word[index+1] == board[i][j+1] && !dp[i][j+1]){
            dfs(i,j+1,board, word, index+1);
        }
        dp[i][j] = false;
        return ;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int i, j;
        n = board.size();
        m = board[0].size();
        ans = false;
        memset(dp, false, sizeof(dp));
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                if(board[i][j] == word[0])      dfs(i, j, board, word, 0);       
                if(ans)     return true;
            }
        }
        return false;
    }
};