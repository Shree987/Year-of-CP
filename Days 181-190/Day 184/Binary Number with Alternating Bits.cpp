/*
Author : Shreeraksha R Aithal
Problem name : Binary Number with Alternating Bits
Problem link : https://leetcode.com/problems/binary-number-with-alternating-bits/
Difficulty : Easy
Tags : Bit Manipulation
*/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int m = 1 - n%2;
        while(n > 0){
            if(m == n%2)    return false;
            m = n%2;
            n /= 2;
        }
        return true;
    }
};