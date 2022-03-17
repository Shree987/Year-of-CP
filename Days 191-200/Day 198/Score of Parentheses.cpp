/*
Author : Shreeraksha R Aithal
Problem name : Score of Parentheses
Problem link : https://leetcode.com/problems/score-of-parentheses/
Difficulty : Medium
Tags : Stack, String
*/

class Solution {
public:
    map<pair<int,int>, int> mp;
    int dp(int start, int end, vector<int>& index){
        if(start >= end)        return 1;
        if(start == end-1){
            return mp[{start, end}] = 1;
        }
        int j, i = start, ans = 0;
        while(i < end){
            j = index[i];
            if(mp.find({i,j}) == mp.end()){
                if(i == j-1)    mp[{i, j}] = 1;
                else{
                    dp(i+1, j-1, index);
                    mp[{i, j}] = 2*mp[{i+1, j-1}];
                }
            }
            ans += mp[{i, j}];
            i = j+1;
        }
        return mp[{start, end}] = ans;
    }
    int scoreOfParentheses(string s) {
        int n = s.size()-1;
        vector<int> index(n+1);
        stack<int> st;
        for(int i = 0; i<=n; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                int j = st.top();
                st.pop();
                index[i] = j;
                index[j] = i;
            }
        }
        return dp(0, n, index);
    }
};