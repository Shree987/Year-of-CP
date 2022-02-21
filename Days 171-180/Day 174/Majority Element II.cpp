/*
Author : Shreeraksha R Aithal
Problem name : Majority Element II
Problem link : https://leetcode.com/problems/majority-element-ii/
Difficulty : Easy
Tags : Array, Counting, Divide and Conquer, Hash Table, Sorting
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> arr;
        int i = 0;
        while(i < nums.size()){
            int j = i+1;
            while(j < nums.size() && nums[i] == nums[j])    j++;
            if(j-i > (nums.size()/3))     arr.push_back(nums[i]);
            i = j;
        }
        return arr;
    }
};