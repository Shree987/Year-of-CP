/*
Author : Shreeraksha R Aithal
Problem name : Minimize Maximum Pair Sum in Array
Problem link : https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
Difficulty : Medium
Tags : Array, Greedy, Sorting, Two Pointers
*/

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i, n = nums.size(), ans = nums[0];
        ans += nums[n-1];
        for(i = 1; i < n-i; i++){
            ans = max(ans, nums[i] + nums[n-i-1]);
        }
        return ans;
    }
};