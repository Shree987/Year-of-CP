/*
Author : Shreeraksha R Aithal
Problem name : Combination Sum IV
Problem link : https://leetcode.com/problems/combination-sum-iv/
Difficulty : Medium
Tags : Array, Dynamic Programming
*/

class Solution {
    map<int, long> mp;
public:
    int recursion(vector<int>& nums, int target){
        if(mp.find(target) != mp.end())     return mp[target];
        int answer = 0;
        for(auto &k : nums){
            if(k > target)      break;
            answer += recursion(nums, target - k);
        }
        return mp[target] = answer;
    }
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        mp[0] = 1;
        return recursion(nums, target);
    }
};