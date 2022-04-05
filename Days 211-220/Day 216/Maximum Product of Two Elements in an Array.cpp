/*
Author : Shreeraksha R Aithal
Problem name : Maximum Product of Two Elements in an Array
Problem link : https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
Difficulty : Easy
Tags : Array, Heap (Priority Queue), Sorting
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = nums[1], max2 = nums[0];
        if(max1 < max2)     swap(max1, max2);
        for(int index = 2; index < nums.size(); index++){
            if(nums[index] >= max1){
                max2 = max1;
                max1 = nums[index];
            }
            else{
                max2 = max(nums[index], max2);
            }
        }
        return (max1-1)*(max2-1);
    }
};