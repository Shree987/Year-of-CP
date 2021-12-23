/*
Author : Shreeraksha R Aithal
Problem name : Largest Number At Least Twice of Others
Problem link : https://leetcode.com/problems/largest-number-at-least-twice-of-others/
Difficulty : Easy
Tags : Array, Sorting
*/

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int index = 0;
        bool max = true;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[index]){
                max = (nums[i] >= 2*nums[index]);
                index = i;
            }
            else{
                max = max && (nums[index] >= 2*nums[i]);
            }
        }
        if(!max)    index = -1;
        return index;
    }
};