/*
Author : Shreeraksha R Aithal
Problem name : Three Divisors
Problem link : https://leetcode.com/problems/three-divisors/
Difficulty : Easy
Tags : Math
*/

class Solution {
public:
    bool isThree(int n) {
        if(n == 1)      return false;
        int num = sqrt(n);
        if(num*num != n)    return false;
        for(num = num-1; num >= 2; num--){
            if(n%num == 0)  return false;
        }
        return true;
    }
};