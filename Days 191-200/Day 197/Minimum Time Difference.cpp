/*
Author : Shreeraksha R Aithal
Problem name : Minimum Time Difference
Problem link : https://leetcode.com/problems/minimum-time-difference/
Difficulty : Medium
Tags : Array, Math, String, Sorting
*/

class Solution {
public:
    int timeDiff(string& t1, string& t2){
        int h1 = (t1[0]-'0')*10 + (t1[1]-'0');
        int h2 = (t2[0]-'0')*10 + (t2[1]-'0');
        int m1 = (t1[3]-'0')*10 + (t1[4]-'0');
        int m2 = (t2[3]-'0')*10 + (t2[4]-'0');
        int diff = 0;
        if(m1 > m2){
            diff = 60-m1+m2;
            m1 = m2;
            h1++;
        }
        diff += (h2-h1)*60 + m2-m1;
        return min(diff, 24*60 - diff);
    }
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int TD = timeDiff(timePoints[0], timePoints[timePoints.size()-1]);
        for(int i = 0; i < timePoints.size()-1; i++){
            TD = min(TD, timeDiff(timePoints[i], timePoints[i+1]));
        }
        return TD;
    }
};