/*
Author : Shreeraksha R Aithal
Problem name : Power of Three
Problem link : https://leetcode.com/problems/power-of-three/
Difficulty : Easy
Tags : Math, Recursion
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0)      return false;
        if(n%9 == 0)       return isPowerOfThree(n/9);
        if(n < 9 && (n == 3 || n == 1))         return true;
        return false;
    }
};