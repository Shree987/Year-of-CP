/*
Author : Shreeraksha R Aithal
Problem name : Number of Provinces
Problem link : https://leetcode.com/problems/number-of-provinces/
Difficulty : Medium
Tags : Breadth-first Search, Depth-first Search, Graph, Union Find
*/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int i, n = isConnected.size(), cnt = 0, j, k;
        vector<bool> vis(n, false);
        queue<int> q;
        for(i = 0; i < n; i++){
            if(!vis[i]){
                vis[i] = true;
                q.push(i);
                cnt++;
                while(!q.empty()){
                    j = q.front();
                    q.pop();
                    for(k = 0; k < n; k++){
                        if(isConnected[j][k] == 1 && !vis[k]){
                            vis[k] = true;
                            q.push(k);
                        }
                    }
                }
            }
        }
        return cnt;
    }
};