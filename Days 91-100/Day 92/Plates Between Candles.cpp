/*
Author : Shreeraksha R Aithal
Problem name : Plates Between Candles
Problem link : https://leetcode.com/problems/plates-between-candles/
Difficulty : Medium
Tags : Array, Binary Search, Prefix Sum, String
*/

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int i, j = -1, n = s.size(), l, r;
        vector<pair<int,int>> next(n, {-1, -1});
        vector<int> count(n, 0);
        if(s[0] == '*')     count[0] = 1;
        for(i = 1; i < n; i++){
            count[i] = count[i-1];
            if(s[i] == '*')     count[i]++;
        }
        for(i = 0; i < n; i++){
            if(s[i] == '|')     j = i;
            next[i].first = j;
        }
        j = -1;
        for(i = n-1; i >= 0; i--){
            if(s[i] == '|')     j = i;
            next[i].second = j;
        }
        n = queries.size();
        vector<int> ans(n, 0);
        for(i = 0; i < n; i++){
            l = next[queries[i][0]].second;
            r = next[queries[i][1]].first;
            if(l == -1 || r == -1 || l > r) continue;
            ans[i] = count[r]-count[l];
        }
        return ans;
    }
};