/*
Author : Shreeraksha R Aithal
Problem name : 4Sum II
Problem link : https://leetcode.com/problems/4sum-ii/
Difficulty : Medium
Tags : Array, Hash Table
*/

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<long, int> mp;
        int i, j, n = nums1.size(), cnt = 0;
        for(int j, i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                mp[nums1[i] + nums2[j]]++;
            }
        }
        for(int j, i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                cnt += mp[-nums3[i] - nums4[j]];
            }
        }
        return cnt;
    }
};