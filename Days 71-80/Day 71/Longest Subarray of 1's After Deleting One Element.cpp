/*
Author : Shreeraksha R Aithal
Problem name : Longest Subarray of 1's After Deleting One Element
Problem link : https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
Difficulty : Medium
Tags : Dynamic Programming, Math, Sliding Window
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        if(nums.size() == 1)    return 0;
        int n = nums.size(), ans, i, cnt;
        ans = max(0, nums[n-1]);
        vector<int> dp(n, 0);
        dp[n-1] = nums[n-1];
        for(i = n-2; i >= 0; i--){
            dp[i] = (dp[i+1]+1)*nums[i];
            ans = max(dp[i], ans);
        }
        cnt = 0;
        for(i = 1; i < n-1; i++){
            cnt = (nums[i-1] == 0 ? 0 : cnt+1);
            ans = max(ans, cnt + dp[i+1]);
        }
        cnt = (nums[n-1] == 0 ? 0 : cnt+1);
        ans = max(cnt, ans);
        if(ans == n)    ans--;
        return ans;
    }
};