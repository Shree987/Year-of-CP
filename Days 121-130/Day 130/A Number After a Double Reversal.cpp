/*
Author : Shreeraksha R Aithal
Problem name : A Number After a Double Reversal
Problem link : https://leetcode.com/problems/a-number-after-a-double-reversal/
Difficulty : Easy
Tags : Math
*/

class Solution {
public:
    bool isSameAfterReversals(int num) {
        return (num == 0 || num%10 > 0);    
    }
};