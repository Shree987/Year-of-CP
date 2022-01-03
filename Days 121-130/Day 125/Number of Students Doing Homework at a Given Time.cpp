/*
Author : Shreeraksha R Aithal
Problem name : Number of Students Doing Homework at a Given Time
Problem link : https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/
Difficulty : Easy
Tags : Array
*/

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int count = 0;
        for(int i = 0; i < startTime.size(); i++){
            if(startTime[i] <= queryTime && endTime[i] >= queryTime)      count++;
        }
        return count;
    }
};