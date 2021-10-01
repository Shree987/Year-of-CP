/*
Author : Shreeraksha R Aithal
Problem name : Find Winner on a Tic Tac Toe Game
Problem link : https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/
Difficulty : Easy
Tags : Array, Hash Table, Matrix, Simulation
*/

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<string> game(3, "   ");
        int i, j, k;
        for(i = 0; i < moves.size(); i++){
            if(i%2 == 0)    game[moves[i][0]][moves[i][1]] = 'A';
            else    game[moves[i][0]][moves[i][1]] = 'B';
        }
        for(i = 0; i < 3; i++){
            if(game[i][0]!= ' ' && game[i][0] == game[i][1] && game[i][1] == game[i][2])      return game[i].substr(0,1);
            if(game[0][i]!= ' ' && game[0][i] == game[1][i] && game[1][i] == game[2][i])      return game[0].substr(i,1);
        }
        if(game[0][0] != ' ' && game[0][0] == game[1][1] && game[1][1] == game[2][2])      return game[0].substr(0,1);
        if(game[0][2] != ' ' && game[0][2] == game[1][1] && game[1][1] == game[2][0])      return game[0].substr(2,1);
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};