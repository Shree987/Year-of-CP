/*
Author : Shreeraksha R Aithal
Problem name : Count Numbers with Unique Digits
Problem link : https://leetcode.com/problems/count-numbers-with-unique-digits/
Difficulty : Medium
Tags : Backtracking, Dynamic programming, Math
*/

class Solution {
    int func(int num){
        int prd = 9, val = 9;
        num--;
        while(num>0){
            prd *= val;
            val--;
            num--;
        }
        return prd;
    }
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)      return 1;
        else if(n == 1)     return 10;
        int count = 10;
        while(n >= 2){
            count += func(n);
            n--;
        }
        return count;
    }
};