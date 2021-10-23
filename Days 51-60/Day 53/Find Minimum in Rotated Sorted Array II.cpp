/*
Author : Shreeraksha R Aithal
Problem name : Find Minimum in Rotated Sorted Array II
Problem link : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
Difficulty : Hard
Tags : Array, Binary Search
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int i, j, n = nums.size(), k;
        if(n == 1)      return nums[0];
        if(n == 2)      return min(nums[1], nums[0]);
        i = 0;
        while(i<n && nums[i] == nums[0])    i++;
        if(i == n)  return nums[0];
        i--;
        j = n-1;
        while(j>i && nums[j] == nums[0])    j--;
        n = j+1;
        while(j>i && nums[j] == nums[n-1])    j--;
        j++;
        if(nums[i] < nums[j])   return nums[i];
        if(nums[i] == nums[j])  i++;
        while(i < j){
            if(nums[i] == nums[j])      return nums[i];
            if(i+1 == j)    return min(nums[i], nums[j]);
            k = (j-i)/2 + i;
            if(nums[k] < nums[k+1] && nums[k] < nums[k-1])  return nums[k];
            if(nums[k] > nums[0]){
                i = k+1;
            }
            else j = k;
        }
        return nums[i];
    }
}; 