/*
Author : Shreeraksha R Aithal
Problem name : Maximize Sum Of Array After K Negations
Problem link : https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/
Difficulty : Easy
Tags : Array, Greedy, Sorting
*/

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i  = 0, n = nums.size(), m, sum = 0;
        while(i < n && k > 0){
            if(nums[i] < 0){
                nums[i] *= -1;
                i++;
                k--;
            }
            else    break;
        }
        m = nums[0];
        for(i = 0; i < n; i++){
            sum += nums[i];
            if(nums[i]>=0 && nums[i]<m)     m = nums[i];
        }
        if(k%2 == 1){
            sum -= 2*m;
        }
        return sum;
    }
};