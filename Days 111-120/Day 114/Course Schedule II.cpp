/*
Author : Shreeraksha R Aithal
Problem name : Course Schedule II
Problem link : https://leetcode.com/problems/course-schedule-ii/
Difficulty : Medium
Tags : Breadth-first Search, Depth-first Search, Graph, Topological Sort
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> degree(numCourses, 0), answer(numCourses);        
        vector<vector<int>> adjList(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            degree[u]++;
            adjList[v].push_back(u);
        }
        int count = 0;
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(degree[i] == 0)      q.push(i);
        }
        while(!q.empty() && numCourses>0){
            int u = answer[count] = q.front();
            q.pop();
            for(int i = 0; i < adjList[u].size(); i++){
                int v = adjList[u][i];
                degree[v]--;
                if(degree[v] == 0)      q.push(v);
            }
            numCourses--;
            count++;
        }
        if(numCourses > 0)  answer.clear();   
        return answer;
    }
};