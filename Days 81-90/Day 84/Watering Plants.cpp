/*
Author : Shreeraksha R Aithal
Problem name : Watering Plants
Problem link : https://leetcode.com/problems/watering-plants/
Difficulty : Medium
Tags : Array
*/

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int total = capacity, steps = 0;
        for(int i = 0; i < plants.size(); i++){
            steps+=1;
            total -= plants[i];
            if(i+1<plants.size() && total<plants[i+1]){
                total = capacity;
                steps += 2*(i+1);
            }
        }
        return steps;
    }
};