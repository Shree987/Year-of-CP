/*
Author : Shreeraksha R Aithal
Problem name : Sort Integers by The Number of 1 Bits
Problem link : https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
Difficulty : Easy
Tags : Array, Bit Manipulation, Counting, Sorting
*/

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> vp(n);
        for(int i = 0; i < n; i++){
            vp[i].first = 0;
            vp[i].second = arr[i];
            while(arr[i] > 0){
                vp[i].first += arr[i]%2;
                arr[i]/=2;
            }
        }
        sort(vp.begin(), vp.end());
        for(int i = 0; i <arr.size(); i++){
            arr[i] = vp[i].second;
        }
        return arr;
    }
};