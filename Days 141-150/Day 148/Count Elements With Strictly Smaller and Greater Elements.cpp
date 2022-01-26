/*
Author : Shreeraksha R Aithal
Problem name : Count Elements With Strictly Smaller and Greater Elements
Problem link : https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/
Difficulty : Easy
Tags : Array, Sorting
*/

class Solution {
public:
    int countElements(vector<int>& nums) {
        int Min = nums[0], cntMin = 1, Max = nums[0], cntMax = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < Min){
                Min = nums[i];
                cntMin = 1;
            }
            else if(nums[i] == Min){
                cntMin++;
            }
            if(nums[i] == Max){
                cntMax++;
            }
            else if(nums[i] > Max){
                Max = nums[i];
                cntMax = 1;
            }
        }
        if(Min == Max)      return 0;
        return nums.size() - cntMin - cntMax;
    }
};