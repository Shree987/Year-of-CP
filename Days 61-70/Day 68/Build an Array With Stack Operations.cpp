/*
Author : Shreeraksha R Aithal
Problem name : Build an Array With Stack Operations
Problem link : https://leetcode.com/problems/build-an-array-with-stack-operations/
Difficulty : Easy
Tags : Array, Simulation, Stack
*/

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res(2*n);
        int i = 0, j = 0, num = 1;
        while(num <= n && j < target.size()){
            res[i++] = "Push";
            if(target[j] != num){
                res[i++] = "Pop";
            }
            else    j++;
            num++;
        }
        res.resize(i);
        return res;
    }
};