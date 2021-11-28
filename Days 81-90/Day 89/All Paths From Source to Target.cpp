/*
Author : Shreeraksha R Aithal
Problem name : All Paths From Source to Target
Problem link : https://leetcode.com/problems/all-paths-from-source-to-target/
Difficulty : Medium
Tags : Backtracking, Breadth-first Search, Depth-first Search, Graph
*/

class Solution {
public:
    vector<vector<vector<int> > > ans;
    int n;
    void dfs(int m, vector<bool>& vb, vector<vector<int>>& graph){
        vb[m] = true;
        if(m == n-1){
            ans[n-1] = {{n-1}};
            return ;
        }
        for(int i = 0; i < graph[m].size(); i++){
            if(!vb[graph[m][i]])    dfs(graph[m][i], vb, graph);
            for(int j = 0; j < ans[graph[m][i]].size(); j++){
                vector<int> v = ans[graph[m][i]][j];
                v.insert(v.begin(), m);
                ans[m].push_back(v);
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        ans.resize(n);
        vector<bool> vb(n, false);
        dfs(0, vb, graph);
        return ans[0];
    }
};