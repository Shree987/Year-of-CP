/*
Author : Shreeraksha R Aithal
Problem name : Largest Divisible Subset
Problem link : https://leetcode.com/problems/largest-divisible-subset/
Difficulty : Medium
Tags : Array, Dynamic Programming, Math, Sorting
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i, j, n = nums.size(), index = 0;
        vector<pair<int, int>> vp(n, {-1,1});
        for(i = 0; i < n; i++){
            for(j = 0; j < i; j++){
                if(nums[i]%nums[j] == 0){
                    if(vp[j].second+1 > vp[i].second){
                        vp[i] = {j, vp[j].second+1};
                    }
                }
            }
            if(vp[i].second > vp[index].second)     index = i;
        }
        vector<int> res;
        while(index != -1){
            res.push_back(nums[index]);
            index = vp[index].first;
        }
        return res;
    }
};