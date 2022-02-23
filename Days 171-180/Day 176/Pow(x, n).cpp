/*
Author : Shreeraksha R Aithal
Problem name : Pow(x, n)
Problem link : https://leetcode.com/problems/powx-n/
Difficulty : Medium
Tags : Math, Recursion
*/

class Solution {
public:
    double myPow(double x, long n) {
        if(x == 0 || n == 1)      return x;
        if(n == 0 || x == 1)      return 1;
        if(x == -1){
            return (abs(n)%2 == 0 ? 1 : -1);
        }
        if(n == -1)     return 1/x;
        if(n < 0)       return myPow(1/x, -n);
        return myPow(x*x, n/2) * (n%2 == 1 ? x : 1);
    }
};