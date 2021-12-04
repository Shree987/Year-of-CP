/*
Author : Shreeraksha R Aithal
Problem name : Minimum Operations to Make a Uni-Value Grid
Problem link : https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/
Difficulty : Medium
Tags : Array, Matrix, Math, Sorting
*/

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size(), m = grid[0].size(), i, j, k, cnt = 0;
        vector<int> arr;
        for(auto &row : grid){
            arr.insert(end(arr), begin(row), end(row));
        }
        k = (m*n)/2;
        sort(arr.begin(), arr.end());
        for(auto num : arr){
            if(abs(num - arr[k])%x != 0)    return -1;
            else    cnt += abs(num - arr[k])/x;
        }
        return cnt;
    }
};