/*
Author : Shreeraksha R Aithal
Problem name : Product of Array Except Self
Problem link : https://leetcode.com/problems/product-of-array-except-self/
Difficulty : Medium
Tags : Array, Prefix Sum
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int i, n = nums.size(), k = 1;
        vector<int> pre(n, 1);
        for(i = 1; i < n; i++)      pre[i] = pre[i-1]*nums[i-1];
        for(i = n-2; i >= 0; i--){
            k *= nums[i+1];
            pre[i] *= k;
        }
        return pre;
    }
};