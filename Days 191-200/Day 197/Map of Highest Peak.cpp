/*
Author : Shreeraksha R Aithal
Problem name : Map of Highest Peak
Problem link : https://leetcode.com/problems/map-of-highest-peak/
Difficulty : Medium
Tags : Array, Breadth-first Search, Matrix
*/

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int,int>> q;
        int n = isWater.size(), m = isWater[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(isWater[i][j] == 1){
                    q.push({i,j});
                }
                isWater[i][j]--;
            }
        }
        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();
            if(x-1>=0 && isWater[x-1][y] == -1){
                isWater[x-1][y] = isWater[x][y]+1;
                q.push({x-1, y});
            }
            if(y-1>=0 && isWater[x][y-1] == -1){
                isWater[x][y-1] = isWater[x][y]+1;
                q.push({x, y-1});
            }
            if(x+1<n && isWater[x+1][y] == -1){
                isWater[x+1][y] = isWater[x][y]+1;
                q.push({x+1, y});
            }
            if(y+1<m && isWater[x][y+1] == -1){
                isWater[x][y+1] = isWater[x][y]+1;
                q.push({x, y+1});
            }
        }
        return isWater;
    }
};