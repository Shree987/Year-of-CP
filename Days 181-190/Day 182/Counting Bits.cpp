/*
Author : Shreeraksha R Aithal
Problem name : Counting Bits
Problem link : https://leetcode.com/problems/counting-bits/
Difficulty : Easy
Tags : Bit Manipulation, Dynamic Programming
*/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);
        for(int i = 1; i <= n; i++){
            res[i] = res[i/2];
            if(i%2 == 1)    res[i]++;
        }
        return res;
    }
};