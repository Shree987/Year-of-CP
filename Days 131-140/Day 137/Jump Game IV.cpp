/*
Author : Shreeraksha R Aithal
Problem name : Jump Game IV
Problem link : https://leetcode.com/problems/jump-game-iv/
Difficulty : Hard
Tags : Array, Breadth-first Search, Hash Table
*/

class Solution {
public:
    int minJumps(vector<int>& arr) {
        map<int, vector<int>> mp;
        int count, i, n = arr.size();
        count = n-1;
        for(i = 0; i < n; i++){
            mp[arr[i]].push_back(i);
        }
        vector<int> vis(n, -1);
        queue<pair<int, int>> q;
        q.push({0,0});
        vis[0] = 0;
        while(!q.empty()){
            i = q.front().first;            
            count = q.front().second;
            vis[i] = 1;
            q.pop();
            if(i == n-1)    return count;
            for(auto v : mp[arr[i]]){
                if(vis[v] == -1){
                    vis[v] = 0;
                    q.push({v, count+1});
                }
            }
            mp.erase(arr[i]);
            if(i-1>=0 && vis[i-1] == -1){
                vis[i-1] = 0;
                q.push({i-1, count+1});
            }
            if(i+1<n && vis[i+1] == -1){
                vis[i+1] = 0;
                q.push({i+1, count+1});
            }
        }
        return n-1;
    }
};