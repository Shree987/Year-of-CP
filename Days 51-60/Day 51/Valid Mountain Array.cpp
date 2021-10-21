/*
Author : Shreeraksha R Aithal
Problem name : Valid Mountain Array
Problem link : https://leetcode.com/problems/valid-mountain-array/
Difficulty : Easy
Tags : Array
*/

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3 || arr[0]>arr[1] || arr[arr.size()-1] > arr[arr.size()-2])     return false;
        int i = 1, n = arr.size();
        while(i<n && arr[i]>arr[i-1])   i++;
        while(i<n && arr[i]<arr[i-1])   i++;
        return i == n;
    }
};