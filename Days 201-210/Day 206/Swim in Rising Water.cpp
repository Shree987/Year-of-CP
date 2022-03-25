/*
Author : Shreeraksha R Aithal
Problem name : Swim in Rising Water
Problem link : https://leetcode.com/problems/swim-in-rising-water/
Difficulty : Hard
Tags : Array, Binary Search, Breadth-first Search, Depth-first Search, Heap (Priority Queue), Matrix, Union Find
*/

#define pii pair<int,pair<int,int>>
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> timeGrid(n, vector<int>(m, -1));
        timeGrid[0][0] = grid[0][0];
        priority_queue<pii, vector<pii>, greater<pii>> trvsQ;
        trvsQ.push({grid[0][0], {0,0}});
        while(!trvsQ.empty() && timeGrid[n-1][m-1] == -1){
            int t = trvsQ.top().first, x = trvsQ.top().second.first, y = trvsQ.top().second.second;
            trvsQ.pop();
            if(x-1 >= 0 && timeGrid[x-1][y] == -1){
                timeGrid[x-1][y] = max(timeGrid[x][y], grid[x-1][y]);
                trvsQ.push({timeGrid[x-1][y], {x-1, y}});
            }
            if(y-1 >= 0 && timeGrid[x][y-1] == -1){
                timeGrid[x][y-1] = max(timeGrid[x][y], grid[x][y-1]);
                trvsQ.push({timeGrid[x][y-1], {x, y-1}});
            }
            if(x+1 < n && timeGrid[x+1][y] == -1){
                timeGrid[x+1][y] = max(timeGrid[x][y], grid[x+1][y]);
                trvsQ.push({timeGrid[x+1][y], {x+1, y}});
            }
            if(y+1<m && timeGrid[x][y+1] == -1){
                timeGrid[x][y+1] = max(timeGrid[x][y], grid[x][y+1]);
                trvsQ.push({timeGrid[x][y+1], {x, y+1}});
            }
        }
        return timeGrid[n-1][m-1];
    }
};