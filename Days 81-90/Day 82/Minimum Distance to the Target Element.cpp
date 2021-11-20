/*
Author : Shreeraksha R Aithal
Problem name : Minimum Distance to the Target Element
Problem link : https://leetcode.com/problems/minimum-distance-to-the-target-element/
Difficulty : Easy
Tags : Array
*/

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int i = start, j = start;
        while(i>=0 || j<nums.size()){
            if(i>=0 && nums[i] == target)   return start-i;
            if(j<nums.size() && nums[j] == target)      return j-start;
            i--;
            j++;
        }
        return 0;
    }
};