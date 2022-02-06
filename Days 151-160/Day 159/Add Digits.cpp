/*
Author : Shreeraksha R Aithal
Problem name : Add Digits
Problem link : https://leetcode.com/problems/add-digits/
Difficulty : Easy
Tags : Math, Number Theory, Simulation
*/

class Solution {
public:
    int addDigits(int num) {
        if(num < 10)        return num;
        int sum = 0;
        while(num > 0){
            sum += num%10;
            num /= 10;
        }
        return addDigits(sum);
    }
};