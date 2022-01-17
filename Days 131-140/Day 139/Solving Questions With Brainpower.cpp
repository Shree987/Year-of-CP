/*
Author : Shreeraksha R Aithal
Problem name : Solving Questions With Brainpower
Problem link : https://leetcode.com/problems/solving-questions-with-brainpower/
Difficulty : Medium
Tags : Array, Dynamic Programming
*/

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int i, j, n = questions.size();
        vector<long long> answer(n, 0L);
        answer[n-1] = questions[n-1][0];
        for(i = n-2; i >= 0; i--){
            long long res = questions[i][0];
            if(i + questions[i][1] + 1 < n)     res += answer[i + questions[i][1] + 1];
            answer[i] = max(answer[i+1], res);
        }
        return answer[0];
    }
};