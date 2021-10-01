/*
Author : Shreeraksha R Aithal
Problem name : Longest Turbulent Subarray
Problem link : https://leetcode.com/problems/longest-turbulent-subarray/
Difficulty : Medium
Tags : Array, Dynamic Programming, Sliding Window
*/

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int i, ans = 1, n = arr.size(), a1, a2, b1, b2;
        a1 = b1 = 1;
        for(i = 1; i < n; i++){
            a2 = b2 = 1;
            if(arr[i] > arr[i-1])     a2 = b1 + 1;
            else if(arr[i] < arr[i-1])     b2 = a1 + 1;
            ans = max(ans, max(a2, b2));
            a1 = a2;
            b1 = b2;
        }
        return ans;
    }
};