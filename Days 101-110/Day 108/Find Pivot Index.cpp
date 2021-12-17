/*
Author : Shreeraksha R Aithal
Problem name : Find Pivot Index
Problem link : https://leetcode.com/problems/find-pivot-index/
Difficulty : Easy
Tags : Array, Prefix Sum
*/

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int i, n = nums.size(), ans = -1, right = 0;
        vector<int> prefix = nums;
        for(i = 1; i < n; i++){
            prefix[i] += prefix[i-1];
        }
        for(i = n-1; i > 0; i--){
            if(right == prefix[i-1])    ans = i;
            right += nums[i];
        }
        if(right == 0)      return 0;
        return ans;
    }
};