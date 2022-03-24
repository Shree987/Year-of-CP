/*
Author : Shreeraksha R Aithal
Problem name : Max Increase to Keep City Skyline
Problem link : https://leetcode.com/problems/max-increase-to-keep-city-skyline/
Difficulty : Medium
Tags : Array, Greedy, Matrix
*/

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int IncrSum = 0, len = grid.size(), wdt = grid[0].size();
        vector<int> rowWise(len, 0), colWise(wdt, 0);
        for(int itr1 = 0; itr1 < len; itr1++){
            for(int itr2 = 0; itr2 < wdt; itr2++){
                rowWise[itr1] = max(rowWise[itr1], grid[itr1][itr2]);
                colWise[itr2] = max(colWise[itr2], grid[itr1][itr2]);
            }
        }
        for(int itr1 = 0; itr1 < len; itr1++){
            for(int itr2 = 0; itr2 < wdt; itr2++){
                IncrSum += min(rowWise[itr1], colWise[itr2]) - grid[itr1][itr2];
            }
        }
        return IncrSum;
    }
};