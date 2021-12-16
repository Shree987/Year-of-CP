/*
Author : Shreeraksha R Aithal
Problem name : Minimum Height Trees
Problem link : https://leetcode.com/problems/minimum-height-trees/
Difficulty : Medium
Tags : Breadth-first Search, Depth-first Search, Graph, Topological Sort
*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n <= 1){
            vector<int> arr(n);
            for(int i = 0; i < n; i++)      arr[i] = i;
            return arr;
        }
        vector<int> degree(n, 0);
        vector<vector<int>> adjList(n);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            degree[u]++;
            degree[v]++;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(degree[i] == 1){
                q.push(i);
                degree[i] = -1;
            }
        }
        int cnt = n;
        while(cnt > 2){
            while(!q.empty()){
                int i = q.front();
                q.pop();
                for(int j = 0; j < adjList[i].size(); j++){
                    int k = adjList[i][j];
                    degree[k]--;
                }
                cnt--;
            }
            for(int i = 0; i < n; i++){
                if(degree[i] == 1 || degree[i] == 0){
                    degree[i] = -1;
                    q.push(i);
                }
            }
        }
        vector<int> arr;
        while(!q.empty()){
            arr.push_back(q.front());
            q.pop();
        }
        return arr;
    }
};