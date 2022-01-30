/*
Author : Shreeraksha R Aithal
Problem name : Contains Duplicate II
Problem link : https://leetcode.com/problems/contains-duplicate-ii/
Difficulty : Easy
Tags : Array, Hash Table, Sliding Window
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int i = 0; i < nums.size(); i++){
            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]] = i;
            }
            else{
                if(i - mp[nums[i]] <= k)    return true;
                mp[nums[i]] = i;
            }
        }
        return false;
    }
};