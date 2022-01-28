/*
Author : Shreeraksha R Aithal
Problem name : Combination Sum II
Problem link : https://leetcode.com/problems/combination-sum-ii/
Difficulty : Medium
Tags : Array, Backtracking
*/

class Solution {
public:
    void dfs(vector<vector<int>> &vp, vector<int> &arr, vector<pair<int,int>>& cdts, int index, int sum){
        if(sum == 0){
            vp.push_back(arr);
            return ;
        }
        if(index == cdts.size())    return ;
        if(sum < cdts[index].first)       return ;
        for(int cnt = a1; cnt <= cdts[index].second && sum >= cdts[index].first; cnt++){
            sum -= cdts[index].first;
            arr.push_back(cdts[index].first);
            dfs(vp, arr, cdts, index+1, sum);
        }
        while(arr.size() > 0 && arr[arr.size()-1] == cdts[index].first){
            arr.pop_back();
            sum += cdts[index].first;
        }        
        dfs(vp, arr, cdts, index+1, sum);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<pair<int,int>> vpp;
        int i, j = 0;
        while(j < candidates.size()){
            i = j;
            while(j < candidates.size() && candidates[i] == candidates[j])      j++;
            vpp.push_back({candidates[i], j-i});
        }
        vector<vector<int>> vp;
        vector<int> arr;
        dfs(vp, arr, vpp, 0, target);
        return  vp;
    }
};