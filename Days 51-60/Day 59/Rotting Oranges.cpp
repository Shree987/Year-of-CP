/*
Author : Shreeraksha R Aithal
Problem name : Rotting Oranges
Problem link : https://leetcode.com/problems/rotting-oranges/
Difficulty : Medium
Tags : Array, Breadth-first Search, Matrix
*/

#define f first
#define s second
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int cnt = 0, i, j, n = grid.size(), m = grid[0].size(), t = 0;
        queue<pair<int, pair<int,int>>> q;
        for(i = 0 ; i < n ; i++){
            for(j = 0; j < m; j++){
                if(grid[i][j] > 0)      cnt++;
                if(grid[i][j] == 2){
                    q.push({0, {i, j}});
                }
            }
        }
        while(!q.empty() && cnt>0){
            cnt--;
            t = q.front().f;
            i = q.front().s.f;
            j = q.front().s.s;
            q.pop();
            if(i>0 && grid[i-1][j] == 1){
                grid[i-1][j] = 2;
                q.push({t+1, {i-1, j}});
            }
            if(j>0 && grid[i][j-1] == 1){
                grid[i][j-1] = 2;
                q.push({t+1, {i, j-1}});
            }
            if(i+1<n && grid[i+1][j] == 1){
                grid[i+1][j] = 2;
                q.push({t+1, {i+1, j}});
            }
            if(j+1<m && grid[i][j+1] == 1){
                grid[i][j+1] = 2;
                q.push({t+1, {i, j+1}});
            }
        }
        return (cnt == 0 ? t : -1);
    }
};