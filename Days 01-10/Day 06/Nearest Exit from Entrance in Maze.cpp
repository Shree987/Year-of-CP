/*
Author : Shreeraksha R Aithal
Problem name : Nearest Exit from Entrance in Maze
Problem link : https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
Difficulty : Medium
Tags : Array, Breadth-first Search, Matrix
*/

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>> Q;
        int x = entrance[0], y = entrance[1], dist;
        maze[x][y] = '+';
        Q.push({1000*x + y, 0});
        while(!Q.empty()){
            x = Q.front().first;
            dist = Q.front().second;
            Q.pop();
            y = x%1000;
            x = x/1000;
            if(x == 0 || y == 0 || x == maze.size()-1 || y == maze[0].size()-1){
                if(dist > 0)    return dist;
            }
            if(x-1>=0 && maze[x-1][y] == '.'){
                maze[x-1][y] = '+';
                Q.push({1000*x + y - 1000, dist+1});
            }
            if(y-1>=0 && maze[x][y-1] == '.'){
                maze[x][y-1] = '+';
                Q.push({1000*x + y - 1, dist+1});
            }
            if(x+1<maze.size() && maze[x+1][y] == '.'){
                maze[x+1][y] = '+';
                Q.push({1000*x + y + 1000, dist+1});
            }
            if(y+1<maze[0].size() && maze[x][y+1] == '.'){
                maze[x][y+1] = '+';
                Q.push({1000*x + y + 1, dist+1});
            }
        }
        return -1;
    }
};