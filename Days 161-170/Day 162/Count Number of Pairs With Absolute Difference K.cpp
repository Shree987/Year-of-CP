/*
Author : Shreeraksha R Aithal
Problem name : Count Number of Pairs With Absolute Difference K
Problem link : https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/
Difficulty : Easy
Tags : Array, Counting, Hash Table
*/

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int cnt = 0;
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            cnt += mp[nums[i]-k] + mp[nums[i]+k];
            mp[nums[i]]++;
        }
        return cnt;
    }
};