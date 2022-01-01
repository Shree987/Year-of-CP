/*
Author : Shreeraksha R Aithal
Problem name : Maximum Product Difference Between Two Pairs
Problem link : https://leetcode.com/problems/maximum-product-difference-between-two-pairs/
Difficulty : Easy
Tags : Array, Sorting
*/

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return (nums[nums.size()-1]*nums[nums.size()-2] - nums[0]*nums[1]);
    }
};