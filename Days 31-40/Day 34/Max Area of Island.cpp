/*
Author : Shreeraksha R Aithal
Problem name : Max Area of Island
Problem link : https://leetcode.com/problems/max-area-of-island/
Difficulty : Medium
Tags : Array, Breadth-first Search, Depth-first Search, Matrix, Union Find
*/

#define f first
#define s second 
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int i, j, cnt = 0, answer = 0;
        pair<int, int> p;
        for(i = 0; i < grid.size(); i++){
            for(j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    cnt = 0;
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    while(!q.empty()){
                        p = q.front();
                        cnt++;
                        q.pop();
                        if(p.f-1 >=0 && grid[p.f-1][p.s] == 1){
                            grid[p.f-1][p.s] = 0;
                            q.push({p.f-1, p.s});
                        }
                        if(p.s-1 >=0 && grid[p.f][p.s-1] == 1){
                            grid[p.f][p.s-1] = 0;
                            q.push({p.f, p.s-1});
                        }
                        if(p.f+1 < grid.size() && grid[p.f+1][p.s] == 1){
                            grid[p.f+1][p.s] = 0;
                            q.push({p.f+1, p.s});
                        }
                        if(p.s+1 < grid[0].size() && grid[p.f][p.s+1] == 1){
                            grid[p.f][p.s+1] = 0;
                            q.push({p.f, p.s+1});
                        }
                    }
                    answer = max(answer, cnt);
                }
            }
        }
        return answer;
    }
};