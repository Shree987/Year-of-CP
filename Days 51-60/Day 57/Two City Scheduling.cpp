/*
Author : Shreeraksha R Aithal
Problem name : Two City Scheduling
Problem link : https://leetcode.com/problems/two-city-scheduling/
Difficulty : Medium
Tags : Array, Greedy, Sorting
*/

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int i, n = costs.size()/2, m = 0;
        vector<int> arr(2*n);
        for(i = 0; i < 2*n; i++){
            m += costs[i][0];
            arr[i] = costs[i][1] - costs[i][0];
        }
        sort(arr.begin(), arr.end());
        for(i = 0; i < n; i++)      m += arr[i];
        return m;
    }
};