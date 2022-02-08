/*
Author : Shreeraksha R Aithal
Problem name : Sort Even and Odd Indices Independently
Problem link : https://leetcode.com/problems/sort-even-and-odd-indices-independently/
Difficulty : Easy
Tags : Array, Sorting
*/

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int i, j, n = nums.size();
        for(i = 0; i < n; i+=2){
            for(j = 0; j < n; j+=2){
                if(nums[i] < nums[j])       swap(nums[i], nums[j]);
            }
        }
        for(i = 1; i < n; i+=2){
            for(j = 1; j < n; j+=2){
                if(nums[i] > nums[j])       swap(nums[i], nums[j]);
            }
        }
        return nums;
    }
};