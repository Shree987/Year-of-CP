/*
Author : Shreeraksha R Aithal
Problem name : Maximum Sum Obtained of Any Permutation
Problem link : https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/
Difficulty : Medium
Tags : Array, Greedy, refix Sum, Sorting
*/

#define m 1000000007
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        vector<long long> sum(nums.size(), 0);
        for(auto v : requests){
            sum[v[0]]++;
            if(v[1]+1 < nums.size())    sum[v[1]+1]--;
        }
        for(int i = 1; i < nums.size(); i++){
            sum[i] += sum[i-1];
        }
        sort(sum.rbegin(), sum.rend());
        sort(nums.rbegin(), nums.rend());
        long long tot_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(sum[i] == 0)     break;
            tot_sum = ((nums[i]*sum[i])%m + tot_sum)%m;
        }
        return tot_sum;
    }
};