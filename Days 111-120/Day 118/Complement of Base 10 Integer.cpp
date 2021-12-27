/*
Author : Shreeraksha R Aithal
Problem name : Complement of Base 10 Integer
Problem link : https://leetcode.com/problems/complement-of-base-10-integer/
Difficulty : Easy
Tags : Bit Manipulation
*/

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0)      return 1;
        long ans = 0, val = 1;
        while(n>0){
            ans = ans + val*(1 - n%2);
            n /= 2;
            val *= 2;
        }
        return ans;
    }
};