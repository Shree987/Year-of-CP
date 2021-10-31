/*
Author : Shreeraksha R Aithal
Problem name : Valid Perfect Square
Problem link : https://leetcode.com/problems/valid-perfect-square/
Difficulty : Easy
Tags : Binary Search, Math
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1)    return true;
        long lower = 2, upper = num/2, mid, prod;
        while(lower < upper){
            mid = (upper-lower)/2 + lower;
            prod = mid*mid;
            if(prod > num)  upper = mid-1;
            else if(prod == num)    return true;
            else if(prod+mid+mid+1 > num)   return false;
            else    lower = mid+1;
        }
        return lower*lower == num;
    }
};