/*
Author : Shreeraksha R Aithal
Problem name : Merge Intervals
Problem link : https://leetcode.com/problems/merge-intervals/
Difficulty : Medium
Tags : Array, Sorting
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int i = 1;
        while(i < intervals.size()){
            if(intervals[i][0] <= intervals[i-1][1]){
                intervals[i][1] = max(intervals[i][1], intervals[i-1][1]);
                intervals[i][0] = intervals[i-1][0];
                intervals[i-1][0] = intervals[i-1][1] = -1;
            }
            i++;
        }
        i = intervals.size()-1;
        while(i >= 0){
            if(intervals[i][0] == -1){
                intervals.erase(intervals.begin() + i);
            }
            else    i--;
        }
        return intervals;
    }
};