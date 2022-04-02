/*
Author : Shreeraksha R Aithal
Problem name : Minimum Operations to Reduce X to Zero
Problem link : https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
Difficulty : Medium
Tags : Array, Binary Search, Hash Table, Prefix Sum, Two Pointers
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int left = 0, right = nums.size()-1, sum = 0, answer = INT_MAX;
        while(left <= right && sum < x){
            sum += nums[left];
            left++;
        }
        if(sum == x)        return  answer = left;
        if(left > right){
            if(sum == x)       return nums.size();
            return -1;
        }
        left--;
        while(left >= 0){
            sum -= nums[left];
            left--;
            while(right > left && sum < x){
                sum += nums[right];
                right--;
            }
            if(sum == x){
                answer = min(answer + 0UL, left + nums.size() - right);
            }
        }
        if(answer == INT_MAX)       answer = -1;
        return answer;
    }
};