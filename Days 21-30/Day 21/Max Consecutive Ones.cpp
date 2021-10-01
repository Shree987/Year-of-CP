/*
Author : Shreeraksha R Aithal
Problem name : Max Consecutive Ones
Problem link : https://leetcode.com/problems/max-consecutive-ones/
Difficulty : Easy
Tags : Array
*/

int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 1, answer = 0, i, n = nums.size();
        for(i = 1; i < n; i++){
            if(nums[i] == nums[i-1])    count++;
            else{
                answer = max(answer, count*nums[i-1]);
                count = 1;
            }
        }
        return max(answer, count*nums[n-1]);
    }
};
