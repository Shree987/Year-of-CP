/*
Author : Shreeraksha R Aithal
Problem name : Array Partition I
Problem link : https://leetcode.com/problems/array-partition-i/
Difficulty : Easy
Tags : Array, Couting Sort, Greedy, Sorting
*/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int sum = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i+=2)       sum += nums[i];
        return sum;
    }
};

