/*
Author : Shreeraksha R Aithal
Problem name : Power of Four
Problem link : https://leetcode.com/problems/power-of-four/
Difficulty : Easy
Tags : Bit Manipulation, Math, Recursion
*/

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0)      return false;
        if(n%16 == 0)       return isPowerOfFour(n/16);
        if(n < 16 && (n == 4 || n == 1))         return true;
        return false;
    }
};