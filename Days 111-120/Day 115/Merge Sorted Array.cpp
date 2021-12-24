/*
Author : Shreeraksha R Aithal
Problem name :  Merge Sorted Array
Problem link : https://leetcode.com/problems/merge-sorted-array/
Difficulty : Easy
Tags : Array, Sorting, Two Pointers
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m+n-1;
        m--;
        n--;
        while(m>=0 || n>=0){
            if(n == -1)     break;
            else    if(m == -1)     nums1[k--] = nums2[n--];
            else if(nums1[m] > nums2[n]){
                nums1[k--] = nums1[m--];
            }
            else{
                nums1[k--] = nums2[n--];
            }
        }
    }
};