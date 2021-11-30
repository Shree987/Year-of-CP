/*
Author : Shreeraksha R Aithal
Problem name : K Radius Subarray Averages
Problem link : https://leetcode.com/problems/k-radius-subarray-averages/
Difficulty : Medium
Tags : Array, Sliding Window
*/

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int i, n = nums.size();
        long sum = 0;
        vector<int> ans(n, -1);
        if(n <= 2*k)    return ans;
        for(i = 0; i < 2*k; i++)    sum += nums[i];
        for(i = k; i+k < n; i++){
            if(i+k<n)   sum += nums[i+k];
            ans[i] = sum/(2*k + 1);
            if(i-k>=0)  sum -= nums[i-k];
        }
        return ans;
    }
};