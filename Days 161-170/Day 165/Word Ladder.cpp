/*
Author : Shreeraksha R Aithal
Problem name : Word Ladder
Problem link : https://leetcode.com/problems/word-ladder/
Difficulty : Hard
Tags : Breadth-first Search, Hash Table, String
*/

class Solution {
    int diffDist(string &a, string &b){
        int dist = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i]){
                dist++;
            }
        }
        return dist;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size(), ind = -1;
        vector<int> distance(n, 0);
        queue<int> q;
        vector<vector<int>> vp(n);
        for(int j, i = 0; i < n; i++){
            if(wordList[i] == endWord)      ind = i;
            if(diffDist(wordList[i], beginWord) == 1){
                q.push(i);
                distance[i] = 2;
            }
            for(j = i+1; j < n; j++){
                if(diffDist(wordList[i], wordList[j]) == 1){
                    vp[i].push_back(j);
                    vp[j].push_back(i);
                }
            }
        }        
        if(ind == -1){
            return 0;
        }
        while(!q.empty() && distance[ind] == 0){
            int node = q.front();
            q.pop();
            for(auto &m : vp[node]){
                if(distance[m] == 0){
                    distance[m] = distance[node]+1;
                    q.push(m);
                }
            }
        }
        return distance[ind];
    }
};