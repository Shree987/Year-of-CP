/*
Author : Shreeraksha R Aithal
Problem name : Minimum Number of Arrows to Burst Balloons
Problem link : https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
Difficulty : Medium
Tags : Array, Greedy, Sorting
*/

bool cpr(vector<int> &a, vector<int>&b){
    if(a[1] != b[1])    return a[1] < b[1];
    return a[0]<b[0];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cpr);
        int count = 0, val = 0, i = 0;
        while(i < points.size()){
            count++;
            val = points[i][1];
            while(i < points.size() && (points[i][0] <= val && points[i][1]>=val))  i++;
        }
        return count;
    }
};