/*
Author : Shreeraksha R Aithal
Problem name : Remove Covered Intervals
Problem link : https://leetcode.com/problems/remove-covered-intervals/
Difficulty : Medium
Tags : Array, Sorting
*/

bool compare(vector<int>& a, vector<int>& b){
    if(a[0] != b[0])    return (a[0] < b[0]);
    return a[1] >= b[1];
}
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int count = 0, index = 0;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] == intervals[index][0])      count++;
            else if(intervals[i][1] <= intervals[index][1]){
                count++;
            }
            else{
                index = i;
            }
        }
        return intervals.size() - count;
    }
};