/*
Author : Shreeraksha R Aithal
Problem name : Distance Between Bus Stops
Problem link : https://leetcode.com/problems/distance-between-bus-stops/
Difficulty : Easy
Tags : Array
*/

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {        
        if(start == destination)        return 0;
        if(start > destination)        swap(start, destination);
        int dir2 = 0, dir1 = 0;
        for(int i = 0; i < distance.size(); i++){
            if(i >= start && i < destination)       dir1 += distance[i];
            else    dir2 += distance[i];
        }
        return min(dir1, dir2);
    }
};