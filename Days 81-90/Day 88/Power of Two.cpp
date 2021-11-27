/*
Author : Shreeraksha R Aithal
Problem name : Power of Two
Problem link : https://leetcode.com/problems/power-of-two/
Difficulty : Easy
Tags : Bit Manipulation, Math, Recursion
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n>0 && (n & n-1) == 0);
    }
};