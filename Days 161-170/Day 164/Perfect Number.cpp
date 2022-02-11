/*
Author : Shreeraksha R Aithal
Problem name : Perfect Number
Problem link : https://leetcode.com/problems/perfect-number/
Difficulty : Easy
Tags : Math
*/

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 1)    return false;
        int sum = 1, sqt = sqrt(num);
        for(int i = 2; i <= sqt; i++){
            if(num%i == 0)      sum += (i + num/i);
        }
        return (sum == num);
    }
};