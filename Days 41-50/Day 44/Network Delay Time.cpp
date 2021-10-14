/*
Author : Shreeraksha R Aithal
Problem name : Network Delay Time
Problem link : https://leetcode.com/problems/network-delay-time/
Difficulty : Medium
Tags : Breadth-first Search, Depth-first Search, Graph, Heap (Prioirty Queue), Shortest Path
*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> gp(n, vector<int>(n, -1));
        for(auto p : times){
            gp[p[0]-1][p[1]-1] = p[2];
        }
        vector<int> visited(n, 0);
        k--;
        int m = n, time = 0, t;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0,k});
        while(!q.empty() && m>0){
            t = q.top().first;
            k = q.top().second;
            q.pop();
            if(visited[k] == 2)     continue;
            visited[k] = 2;
            m--;
            time = max(time, t);
            for(auto i = 0; i < n; i++){
                if(i == k)   continue;
                if(visited[i] != 2 && gp[k][i] >= 0){
                    visited[i] = 1;
                    q.push({t+gp[k][i], i});
                }
            }
        }
        return (m > 0) ? -1 : time;
    }
};