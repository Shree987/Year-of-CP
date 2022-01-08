/*
Author : Shreeraksha R Aithal
Problem name : Smallest Index With Equal Value
Problem link : https://leetcode.com/problems/smallest-index-with-equal-value/
Difficulty : Easy
Tags : Array
*/

class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        for(int j = 0, i = 0; i < nums.size(); i++){
            if(j == nums[i])        return i;
            j++;
            if(j == 10)     j = 0;
        }
        return -1;
    }
};