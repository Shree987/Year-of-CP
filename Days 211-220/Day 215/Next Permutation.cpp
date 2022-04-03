/*
Author : Shreeraksha R Aithal
Problem name : Next Permutation
Problem link : https://leetcode.com/problems/next-permutation/
Difficulty : Medium
Tags : Array, Two Pointers
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = nums.size()-1;
        while(index > 0 && nums[index] <= nums[index-1]){
            index--;
        }
        if(index == 0){
            reverse(nums.begin(), nums.end());
        }
        else{
            int itr = index-1;
            while(index < nums.size() && nums[itr] < nums[index])      index++;
            swap(nums[index-1], nums[itr]);
            sort(nums.begin()+itr+1, nums.end());
        }
    }
};