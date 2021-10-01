/*
Author : Shreeraksha R Aithal
Problem name : Find the Student that Will Replace the Chalk
Problem link : https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/
Difficulty : Medium
Tags : Array, Binary Search, Prefix Sum, Simulation
*/

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for(auto val : chalk)       sum += val;
        k = k%sum;
        sum = 0;
        while(k>=chalk[sum]){
            k -= chalk[sum];
            sum++;
        }
        return sum;
    }
};