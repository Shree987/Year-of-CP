/*
Author : Shreeraksha R Aithal
Problem name : Keep Multiplying Found Values by Two
Problem link : https://leetcode.com/problems/keep-multiplying-found-values-by-two/
Difficulty : Easy
Tags : Array, Sorting
*/

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > original)      break;
            else if(nums[i] == original)    original*=2;
        }
        return original;
    }
};