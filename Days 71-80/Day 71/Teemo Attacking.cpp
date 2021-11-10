/*
Author : Shreeraksha R Aithal
Problem name : Teemo Attacking
Problem link : https://leetcode.com/problems/teemo-attacking/
Difficulty :Easy
Tags : Array, Simulation
*/

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int cnt = duration;
        for(int i = 1; i < timeSeries.size(); i++){
            cnt += min(duration, timeSeries[i]-timeSeries[i-1]);
        }
        return cnt;
    }
};
    