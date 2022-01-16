/*
Author : Shreeraksha R Aithal
Problem name : Maximize Distance to Closest Person
Problem link : https://leetcode.com/problems/maximize-distance-to-closest-person/
Difficulty : Medium
Tags : Array
*/

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        long Max = 1, i = 0, m, n = seats.size();
        while(i < n && seats[i] == 0)    i++;
        Max = i;
        m = i;
        while(i < n){
            if(seats[i] == 1){
                Max = max(Max, (i-m)/2);
                m = i;
            }
            i++;
        }
        Max = max(Max, n-1-m);
        return Max;
    }
};