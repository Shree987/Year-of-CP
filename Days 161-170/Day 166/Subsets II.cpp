/*
Author : Shreeraksha R Aithal
Problem name : Subsets II
Problem link : https://leetcode.com/problems/subsets-ii/
Difficulty : Medium
Tags : Array, Backtracking, Bit Manipulation
*/

class Solution {
public:
    vector<vector<int>> result;
    void dfs(vector<pair<int,int>>& nums, int index, vector<int> &arr){
        if(index == nums.size()){
            result.push_back(arr);
            return ;
        }
        for(int i = 1; i <= nums[index].second; i++){
            arr.push_back(nums[index].first);
            dfs(nums, index+1, arr);
        }
        arr.erase(arr.end() - nums[index].second, arr.end());
        dfs(nums, index+1, arr);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<pair<int,int>> vp;
        unordered_map<int, int> mp;
        for(auto &val : nums){
            if(mp.find(val) == mp.end()){
                mp[val] = vp.size();
                vp.push_back({val, 1});
            }
            else{
                vp[mp[val]].second++;
            }
        }
        nums.clear();
        dfs(vp, 0, nums);
        return result;
    }
};