/*
Author : Shreeraksha R Aithal
Problem name : Course Schedule
Problem link : https://leetcode.com/problems/course-schedule/
Difficulty : Medium
Tags : Breadth-first Search, Depth-first Search, Graph, Topological Sort
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> degree(numCourses, 0);        
        vector<vector<int>> adjList(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            degree[u]++;
            adjList[v].push_back(u);
        }
        int count = numCourses;
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(degree[i] == 0)      q.push(i);
        }
        while(!q.empty() && numCourses>0){
            int u = q.front();
            q.pop();
            for(int i = 0; i < adjList[u].size(); i++){
                int v = adjList[u][i];
                degree[v]--;
                if(degree[v] == 0)      q.push(v);
            }
            numCourses--;
        }            
        return (numCourses == 0);
    }
};