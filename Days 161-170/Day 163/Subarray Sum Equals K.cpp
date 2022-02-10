/*
Author : Shreeraksha R Aithal
Problem name : Subarray Sum Equals K
Problem link : https://leetcode.com/problems/subarray-sum-equals-k/
Difficulty : Medium
Tags : Array, ?Hash Table, Prefix Sum
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, sum = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(auto &val : nums){
            sum += val;
            count += mp[sum-k];
            mp[sum]++;
        }
        return count;
    }
};