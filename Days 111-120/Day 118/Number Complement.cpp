/*
Author : Shreeraksha R Aithal
Problem name : Number Complement
Problem link : https://leetcode.com/problems/number-complement/
Difficulty : Easy
Tags : Bit Manipulation
*/

class Solution {
public:
    int findComplement(int num) {
        long ans = 0, val = 1;
        while(num>0){
            ans = ans + val*(1 - num%2);
            num /= 2;
            val *= 2;
        }
        return ans;
    }
};