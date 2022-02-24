/*
Author : Shreeraksha R Aithal
Problem name : 01 Matrix
Problem link : https://leetcode.com/problems/01-matrix/
Difficulty : Medium
Tags : Array, Breadth-first Search, Dynamic Programming, Matrix
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int count, n = mat.size(), m = mat[0].size(), i, j;
        count = m*n;
        queue<pair<int,int>> q;
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    count--;
                }
                else{
                    mat[i][j] = -1;
                }
            }
        }
        while(count > 0){
            i = q.front().first;
            j = q.front().second;
            q.pop();
            if(i-1>=0 && mat[i-1][j] == -1){
                q.push({i-1, j});
                mat[i-1][j] = mat[i][j]+1;
                count--;
            }
            if(i+1<n && mat[i+1][j] == -1){
                q.push({i+1, j});
                mat[i+1][j] = mat[i][j]+1;
                count--;
            }
            if(j-1>=0 && mat[i][j-1] == -1){
                q.push({i, j-1});
                mat[i][j-1] = mat[i][j]+1;
                count--;
            }
            if(j+1<m && mat[i][j+1] == -1){
                q.push({i, j+1});                
                mat[i][j+1] = mat[i][j]+1;
                count--;
            }
        }
        return mat;
    }
};