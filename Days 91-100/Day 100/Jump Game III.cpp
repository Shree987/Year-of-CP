/*
Author : Shreeraksha R Aithal
Problem name : Jump Game III
Problem link : https://leetcode.com/problems/jump-game-iii/
Difficulty : Medium
Tags : Array, Breadth-fuirst Search, Depth-first Search
*/

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr[start] == 0)    return true;
        int n = arr.size();
        vector<bool> vis(n, false);
        vis[start] = true;
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int k = q.front();
            q.pop();
            if(k - arr[k] >=0 && vis[k - arr[k]] == false){
                if(arr[k - arr[k]] == 0)    return true;
                q.push(k - arr[k]);
                vis[k - arr[k]] = true;
            }            
            if(k + arr[k] < n && vis[k + arr[k]] == false){
                if(arr[k + arr[k]] == 0)    return true;
                q.push(k + arr[k]);
                vis[k + arr[k]] = true;
            }
        }
        return false;
    }
};