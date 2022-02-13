/*
Author : Shreeraksha R Aithal
Problem name : Subsets
Problem link : https://leetcode.com/problems/subsets/
Difficulty : Medium
Tags : Array, Backtracking, Bit Manipulation
*/

class Solution {
public:
    vector<vector<int>> vp;
    void dfs(vector<int>& nums, int index, vector<int> &arr){
        if(index == nums.size()){
            vp.push_back(arr);
            return ;
        }
        arr.push_back(nums[index]);
        dfs(nums, index+1, arr);
        arr.pop_back();
        dfs(nums, index+1, arr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> arr;
        dfs(nums, 0, arr);
        return vp;
    }
};