/*
Author : Shreeraksha R Aithal
Problem name : Arithmetic Slices
Problem link : https://leetcode.com/problems/arithmetic-slices/
Difficulty : Medium
Tags : Array, Dynamic Programming
*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int i, n = nums.size(), j, cnt = 0;
        for(i = 0; i < n-1; i++){
            nums[i] = nums[i] - nums[i+1];
        }
        i = 0;
        while(i<n-1){
            j = i;
            while(i<n-1 && nums[i]==nums[j])    i++;
            cnt += ((i-j)*(i-j-1))/2;
        }
        return cnt;
    }
};