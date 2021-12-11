/*
Author : Shreeraksha R Aithal
Problem name : Minimum Absolute Difference
Problem link : https://leetcode.com/problems/minimum-absolute-difference/
Difficulty : Easy
Tags : Array, Sorting
*/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> v;
        vector<int> u(2);
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] - arr[i-1] <= diff){
                if(arr[i] - arr[i-1] < diff){
                    diff = arr[i] - arr[i-1];
                    v.clear();
                }
                u[0] = arr[i-1];
                u[1] = arr[i];
                v.push_back(u);
            }
        }
        return v;
    }
};