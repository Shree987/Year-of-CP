/*
Author : Shreeraksha R Aithal
Problem name : Partition to K Equal Sum Subsets
Problem link : https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
Difficulty : Medium
Tags : Array, Backtracking, Bitmask, Bit Manipulation, Dynamic Programming, Memoization
*/

class Solution {
    bool answer;
    void partition(vector<int>& nums, vector<int> &sum, int i, int& k, int& totSum){
        if(answer)  return ;
        if(i == nums.size()){
            answer = true;
            return ;
        }
        for(int j = 0; j < k; j++){
            if(sum[j] == 0){
                sum[j]+=nums[i];
                partition(nums, sum, i+1, k, totSum);
                sum[j] -= nums[i];
                break;
            }
            else if(sum[j] + nums[i] <= totSum){
                sum[j]+=nums[i];
                partition(nums, sum, i+1, k, totSum);
                sum[j] -= nums[i];                
            }
        }
        return ;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        answer = false;
        vector<int> sum(k, 0);
        int totSum = 0;
        for(auto m : nums){
            totSum += m;
        }
        if(totSum%k != 0)    return false;
        for(auto m : nums){
            if(m > totSum/k)    return false;
        }
        totSum /= k;
        partition(nums, sum, 0, k, totSum);
        return answer;
    }
};