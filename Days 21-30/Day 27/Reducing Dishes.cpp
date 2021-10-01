/*
Author : Shreeraksha R Aithal
Problem name : Reducing Dishes
Problem link : https://leetcode.com/problems/reducing-dishes/
Difficulty : Hard
Tags : Array, Dynamic Programming, Greedy, Sorting
*/

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int temp, answer = max(0, satisfaction[0]), n = satisfaction.size(), j, k, i;
        int dp[n+1][n+1];
        dp[1][1] = satisfaction[0];        
        for(i = 2; i <= n; i++){
            dp[i][1] = satisfaction[i-1];
            answer = max(answer, dp[i][1]);
            for(j = 2; j <= i; j++){
                dp[i][j] = INT_MIN;
                for(k = j-1; k < i; k++){
                    dp[i][j] = max(dp[i][j], j*satisfaction[i-1] + dp[k][j-1]);
                }
                answer = max(dp[i][j], answer);
            }
        }
        return answer;
    }
};