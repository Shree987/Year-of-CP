/*
Author : Shreeraksha R Aithal
Problem name : Sort Colors
Problem link : https://leetcode.com/problems/sort-colors/
Difficulty : Medium
Tags : Array, Sorting, Two Pointers
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, k = 0, j = nums.size()-1;
        while(k <= j){
            if(nums[k] == 0){
                if(k == i){
                    k++;
                    continue;
                }
                nums[k] = nums[i];
                nums[i] = 0;
                i++;
            }
            else if(nums[k] == 2){
                if(k == j){
                    k++;
                    continue;
                }
                nums[k] = nums[j];
                nums[j] = 2;
                j--;
            }
            else    k++;
        }
    }
};