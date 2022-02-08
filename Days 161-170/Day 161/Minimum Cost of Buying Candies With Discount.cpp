/*
Author : Shreeraksha R Aithal
Problem name : Minimum Cost of Buying Candies With Discount
Problem link : https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/
Difficulty : Easy
Tags : Array, Greedy, Sorting
*/

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int i = cost.size() - 1, sum = 0;
        while(i >= 0){
            sum += cost[i];
            if(i-1>=0)   sum += cost[i-1];
            i-=3;
        }
        return sum;
    }
};