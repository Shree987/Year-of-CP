/*
Author : Shreeraksha R Aithal
Problem name : Longest Mountain in Array
Problem link : https://leetcode.com/problems/longest-mountain-in-array/
Difficulty : Medium
Tags : Array, Dynamic Programming, Enumeration, Two Pointers
*/

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int left = 0, right = arr.size()-1, start, itr, Max = 0;
        while(left < right){
            if(arr[left] >= arr[left+1])    left++;
            else    break;
        }
        if(left == right)       return 0;
        while(right > left){
            if(arr[right] >= arr[right-1])      right--;
            else    break;
        }
        itr = left;
        while(itr<right){
            start = itr;
            while(arr[itr] < arr[itr+1])    itr++;
            if(itr == start){
                while(itr < right && arr[itr] >= arr[itr+1])    itr++;
                continue;
            }
            int mid = itr;
            while(itr < right && arr[itr] > arr[itr+1])     itr++;
            if(itr == mid){
                while(itr < right && arr[itr] == arr[itr+1])    itr++;
                continue;
            }
            if(itr - start + 1 >= 3)    Max = max(Max, itr - start + 1);
            while(itr < right && arr[itr] == arr[itr+1])    itr++;
        }
        return Max;
    }
};