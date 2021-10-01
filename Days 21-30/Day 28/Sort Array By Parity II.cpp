/*
Author : Shreeraksha R Aithal
Problem name : Sort Array By Parity II
Problem link : https://leetcode.com/problems/sort-array-by-parity-ii/
Difficulty : Easy
Tags : Array, Sorting, Two Pointers
*/

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i = 0, j = 1;
        while(i<nums.size()){
            while(i<nums.size() && nums[i]%2 == 0)  i+=2;
            while(j<nums.size() && nums[j]%2 == 1)  j+=2;
            if(i<nums.size() && j<nums.size()){
                swap(nums[i], nums[j]);
                i+=2;
                j+=2;
            }
        }
        return nums;
    }
};