/*
Author : Shreeraksha R Aithal
Problem name : Majority Element
Problem link : https://leetcode.com/problems/majority-element/
Difficulty : Easy
Tags : Array, Counting, Divide and Conquer, Hash Table, Sorting
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i + n/2 < n; i++){
            if(nums[i] == nums[n/2])    return nums[i];
        }
        return -1;
    }
};