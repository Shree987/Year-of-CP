/*
Author : Shreeraksha R Aithal
Problem name : 4Sum
Problem link : https://leetcode.com/problems/4sum/
Difficulty : Medium
Tags : Array, Sorting, Two Pointers
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, long target) {
        vector<vector<int>> vp;
        if(nums.size() < 4)     return vp;
        sort(nums.begin(), nums.end());
        vector<int> ans = {0, 0, 0, 0};
        for(int n = nums.size(), i = 0; i < n; i++){
            ans[0] = nums[i];
            for(int x,y,j = i+1; j < n; j++){
                ans[1] = nums[j];
                x = j+1;
                y = n-1;
                while(x < y){
                    long sum = 0L + nums[i] + nums[j] + nums[x] + nums[y];
                    if(sum > target)    y--;
                    else if(sum < target)   x++;
                    else{
                        ans[2] = nums[x];
                        ans[3] = nums[y];
                        vp.push_back(ans);
                        while(x < y && nums[x] == nums[x+1])    x++;
                        while(x < y && nums[y] == nums[y-1])    y--;
                        x++;
                        y--;
                    }
                }
                while(j+1 < n && nums[j] == nums[j+1])    j++;
            }
            while(i+1 < n && nums[i] == nums[i+1])    i++;
        }
        return vp;
    }
};