/*
Author : Shreeraksha R Aithal
Problem name : Maximum Difference Between Increasing Elements
Problem link : https://leetcode.com/problems/maximum-difference-between-increasing-elements/
Difficulty : Easy
Tags : Array
*/

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int answer = -1, val = nums[0];
        for(int i = 1; i < nums.size(); i++){
            answer = max(answer, nums[i] - val);
            val = min(nums[i], val);
        }
        if(answer == 0)     answer = -1;
        return answer;
    }
};