/*
Author : Shreeraksha R Aithal
Problem name : Hamming Distance
Problem link : https://leetcode.com/problems/hamming-distance/
Difficulty : Easy
Tags : Bit Manipulation
*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt = 0;
        while(x>0 || y>0){
            if(x%2 != y%2)  cnt++;
            y/=2;
            x/=2;
        }
        return cnt;
    }
};