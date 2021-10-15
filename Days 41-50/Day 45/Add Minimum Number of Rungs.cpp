/*
Author : Shreeraksha R Aithal
Problem name : Add Minimum Number of Rungs
Problem link : https://leetcode.com/problems/add-minimum-number-of-rungs/
Difficulty : Medium
Tags : Array, Greedy
*/

class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int cost = 0, k = 0, i;
        for(i = 0; i < rungs.size(); i++){
            cost += (rungs[i]-k-1)/dist;
            k = rungs[i];
        }
        return cost;
    }
};