/*
Author : Shreeraksha R Aithal
Problem name : Concatenation of Array
Problem link : https://leetcode.com/problems/concatenation-of-array/
Difficulty : Easy
Tags : Array
*/

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        nums.resize(n+n);
        for(int i = 0; i < n; i++){
            nums[i+n] = nums[i];
        }
        return nums;
    }
};