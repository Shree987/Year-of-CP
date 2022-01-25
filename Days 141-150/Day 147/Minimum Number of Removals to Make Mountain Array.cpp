/*
Author : Shreeraksha R Aithal
Problem name : Minimum Number of Removals to Make Mountain Array
Problem link : https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
Difficulty : Hard
Tags : Array, Binary Search, Dynamic Programming, Greedy
*/

class Solution {
public:
    int minimumMountainRemovals(vector<int>& arr) {
        int i, j, n = arr.size();
        vector<int> inc(n, 1), dec(n, 1);
        for(i = 1; i < n; i++){
            for(j = 0; j < i; j++){
                if(arr[i] > arr[j])     inc[i] = max(inc[i], inc[j]+1);
            }
        }
        for(i = n-2; i >= 0; i--){
            for(j = i+1; j < n; j++){
                if(arr[i] > arr[j])     dec[i] = max(dec[i], dec[j]+1);
            }
        }
        j = 0;
        for(i = 1; i < n-1; i++){
            if(inc[i] > 1 && dec[i] > 1){
                j = max(j, inc[i]+dec[i]-1);
            }
        }
        return n - j;
    }
};