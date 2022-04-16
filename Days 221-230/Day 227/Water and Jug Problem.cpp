/*
Author : Shreeraksha R Aithal
Problem name : Water and Jug Problem
Problem link : https://leetcode.com/problems/water-and-jug-problem/
Difficulty : Medium
Tags : Breadth-first Search, Depth-first Search, Math
*/

class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int gcd = __gcd(jug1Capacity, jug2Capacity);
        return (targetCapacity%gcd == 0 && (jug1Capacity+jug2Capacity>=targetCapacity));
    }
};