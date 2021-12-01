/*
Author : Shreeraksha R Aithal
Problem name : House Robber
Problem link : https://leetcode.com/problems/house-robber/
Difficulty : Medium
Tags : Array, Dynamic Programming
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)      return nums[0];
        else if(n == 2)     return max(nums[1], nums[0]);
        int dp1, dp2, k;
        dp1 = max(nums[1], nums[0]);
        dp2 = nums[0];
        int ans = dp1;
        for(int i = 2; i < n; i++){
            k = max(dp1, dp2 + nums[i]);
            ans = max(ans, k);
            dp2 = dp1;
            dp1 = k;
        }
        return ans;
    }
};