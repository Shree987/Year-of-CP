/*
Author : Shreeraksha R Aithal
Problem name : Russian Doll Envelopes
Problem link : https://leetcode.com/problems/russian-doll-envelopes/
Difficulty : Hard
Tags : Array, Binary Search, Dynamic Programming, Sorting
*/

class Solution {
    bool compare(vector<int>& a, vector<int>& b){
        return (a[0]>b[0] && a[1]>b[1]);
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        int i, j, n = envelopes.size(), Max = 1;
        vector<int> dp(n, 1);
        for(i = 1; i < n; i++){
            for(j = 0 ; j < i; j++){
                if(compare(envelopes[i], envelopes[j]))     dp[i] = max(dp[j]+1, dp[i]);
            }
            Max = max(Max, dp[i]);
        }
        return Max;
    }
};