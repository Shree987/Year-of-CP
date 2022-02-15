/*
Author : Shreeraksha R Aithal
Problem name : Removing Minimum Number of Magic Beans
Problem link : https://leetcode.com/problems/removing-minimum-number-of-magic-beans/
Difficulty : Medium
Tags : Array, Prefix Sum, Sorting
*/

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        long long n = beans.size(), total = 0, count = 0, Min;
        vector<long long> dp(n, 0);
        dp[n-1] = beans[n-1];
        for(int i = n-2; i>=0; i--){
            dp[i] = beans[i] + dp[i+1];
        }
        Min = dp[0];
        for(int i = 0; i < n; i++){
            count = total + (dp[i] - (n-i)*beans[i]);
            Min = min(Min, count);
            total += beans[i];
        }
        return Min;
    }
};