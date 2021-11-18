/*
Author : Shreeraksha R Aithal
Problem name : Find All Numbers Disappeared in an Array
Problem link : https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
Difficulty : Easy
Tags : Array, Hash Table
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> v;
        int i = 0, n = nums.size();
        for(i = 0; i < n; i++){
            if(nums[i] == i+1)      continue;
            if(nums[nums[i]-1] == nums[i])  continue;
            swap(nums[i], nums[nums[i]-1]);
            i--;
        }
        for(i = 0; i < n; i++){
            if(nums[i] != i+1)      v.push_back(i+1);
        }
        return v;
    }
};