/*
Author : Shreeraksha R Aithal
Problem name : Third Maximum Number
Problem link : https://leetcode.com/problems/third-maximum-number/
Difficulty : Easy
Tags : Array, Sorting
*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int first = nums[0], second = nums[0], third = nums[0], i = 1;
        while(i < nums.size() && nums[i] == nums[0])    i++;
        if(i == nums.size())        return nums[0];
        second = nums[i];
        if(second > first)      swap(first, second);
        while(i < nums.size() && ((nums[i] == first) || (nums[i] == second)))    i++;
        if(i == nums.size())        return first;
        third = nums[i];
        if(third > second)      swap(third, second);
        if(second > first)      swap(first, second);
        for(; i < nums.size(); i++){
            if(nums[i] > first){
                third = second;
                second = first;
                first = nums[i];
            }
            else if(nums[i] > second && nums[i] < first){                
                third = second;
                second = nums[i];
            }
            else if(nums[i] > third && nums[i] < second){                
                third = nums[i];
            }
        }
        return third;
    }
};