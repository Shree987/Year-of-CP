/*
Author : Shreeraksha R Aithal
Problem name : Find the Town Judge
Problem link : https://leetcode.com/problems/find-the-town-judge/
Difficulty : Easy
Tags : Array, Graph, Hash Table
*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int,int>> vp(n, {0,0});
        for(int i = 0; i < trust.size(); i++){
            vp[trust[i][0]-1].first++;
            vp[trust[i][1]-1].second++;
        }
        for(int i = 0; i < n; i++){
            if(vp[i].first == 0 && vp[i].second == n-1)    return i+1;
        }
        return -1;
    }
};