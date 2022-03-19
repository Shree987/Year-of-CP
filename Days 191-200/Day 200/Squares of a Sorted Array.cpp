/*
Author : Shreeraksha R Aithal
Problem name : Squares of a Sorted Array
Problem link : https://leetcode.com/problems/squares-of-a-sorted-array/
Difficulty : Easy
Tags : Array, Sorting, Two Pointers
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i, j, n = nums.size(), k;
        for(i = 0; i < n; i++)      nums[i] = nums[i]*nums[i];
        vector<int> arr(n, 0);
        i = 0;
        k = j = n-1;
        while(i <= k){
            if(nums[i] >= nums[k]){
                arr[j--] = nums[i++];
            }
            else{
                arr[j--] = nums[k--];
            }
        }
        return arr;
    }
};