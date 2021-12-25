/*
Author : Shreeraksha R Aithal
Problem name : Contains Duplicate
Problem link : https://leetcode.com/problems/contains-duplicate/
Difficulty : Easy 
Tags : Array, Hash Table, Sorting
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1])    return true;
        }
        return false;
    }
};