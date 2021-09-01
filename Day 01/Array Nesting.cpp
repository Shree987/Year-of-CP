/*
Author : Shreeraksha R Aithal
Problem name : Array Nesting
Problem link : https://leetcode.com/problems/array-nesting/
Difficulty : Medium
Tags : Array, Depth-first Search
*/

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int i, j, k, n = nums.size(), Max = 0, count = 0;
        i = 0;
        while(i<n){
            while(i<n && nums[i]==-1)    i++;
            count = 0;
            k = i;
            while(nums[i]>-1){
                j = nums[i];
                count++;
                nums[i] = -1;
                i = j;
            }
            i = k+1;
            Max = max(Max, count);
        }
        return Max;
    }
};