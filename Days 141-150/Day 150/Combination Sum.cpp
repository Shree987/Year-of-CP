/*
Author : Shreeraksha R Aithal
Problem name : Combination Sum
Problem link : https://leetcode.com/problems/combination-sum/
Difficulty : Medium
Tags : Array, Backtracking
*/

class Solution {
public:
    void dfs(vector<vector<int>> &vp, vector<int> &arr, vector<int>& cdts, int index, int sum){
        if(sum == 0){
            vp.push_back(arr);
            return ;
        }
        if(index == cdts.size())    return ;
        if(sum < cdts[index])       return ;
        sum -= cdts[index];
        arr.push_back(cdts[index]);
        dfs(vp, arr, cdts, index, sum);
        arr.pop_back();
        sum += cdts[index];
        dfs(vp, arr, cdts, index+1, sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> vp;
        vector<int> arr;
        dfs(vp, arr, candidates, 0, target);
        return  vp;
    }
};