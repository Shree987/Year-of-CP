/*
Author : Shreeraksha R Aithal
Problem name : Find Right Interval
Problem link : https://leetcode.com/problems/find-right-interval/
Difficulty : Medium
Tags : Array, Binary Search, Sorting
*/

class Solution {
    int findIndex(vector<vector<int>>& interval, int i){
        int left = 0, right = interval.size()-1;
        while(left < right){
            int mid = (right-left)/2 + left;
            if(interval[mid][0] >= interval[i][1])      right = mid;
            else    left = mid+1;
        }
        if(left == right)   if(interval[left][0] >= interval[i][1])     return interval[left][2];
        return -1;
        
    }
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> v(n,0);
        for(int i = 0; i < n; i++){
            intervals[i].push_back(i);
        }
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < n-1; i++){
            v[intervals[i][2]] = findIndex(intervals, i);
        }
        v[intervals[n-1][2]] = -1;
        return v;
    }
};