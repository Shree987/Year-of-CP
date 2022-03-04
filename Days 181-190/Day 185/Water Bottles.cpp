/*
Author : Shreeraksha R Aithal
Problem name : Water Bottles
Problem link : https://leetcode.com/problems/water-bottles/
Difficulty : Easy
Tags : Math, Simulation
*/

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total = 0, extra = 0;
        while(numBottles > 0){
            total += numBottles;
            extra += numBottles;
            numBottles = extra/numExchange;
            extra %= numExchange;
        }
        return total;
    }
};