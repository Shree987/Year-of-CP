/*
Author : Shreeraksha R Aithal
Problem name : Maximum Matrix Sum
Problem link : https://leetcode.com/problems/maximum-matrix-sum/
Difficulty : Medium
Tags : Array, Greedy, Matrix
*/

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0, Min = abs(matrix[0][0]);
        bool even = true; 
        for(auto &v : matrix){
            for(auto &k : v){
                if(k < 0)   even = !even;
                sum += abs(k);
                Min = min(abs(k) + 0LL, Min);
            }
        }
        if(Min > 0 && !even)    sum -= 2*Min;
        return sum;
    }
};