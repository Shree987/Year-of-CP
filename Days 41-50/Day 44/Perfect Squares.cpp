/*
Author : Shreeraksha R Aithal
Problem name : Perfect Squares
Problem link : https://leetcode.com/problems/perfect-squares/
Difficulty : Medium
Tags : Breadth-first Search, Dynamic Programming, Math
*/

class Solution {
public:
    int numSquares(int n) {
        vector<int> nums, dp(n+1, INT_MAX);
        int k = 1;
        while(k*k <= n){
            nums.push_back(k*k);
            k++;
        }
        k--;
        if(k*k == n)    return 1;
        dp[0] = 0;
        dp[1] = 1;
        for(k = 2; k <= n; k++){
            for(auto m : nums){
                if(m > k)   break;
                dp[k] = min(dp[k], 1 + dp[k-m]);
            }
        }
        return dp[n];
    }
};