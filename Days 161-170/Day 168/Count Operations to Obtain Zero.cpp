/*
Author : Shreeraksha R Aithal
Problem name : Count Operations to Obtain Zero
Problem link : https://leetcode.com/problems/count-operations-to-obtain-zero/
Difficulty : Easy
Tags : Math, Simulation
*/

class Solution {
public:
    int countOperations(int num1, int num2) {
        if(num1 == 0 || num2 == 0)      return 0;
        else if(num1 == num2)   return 1;
        if(num1 < num2)     swap(num1, num2);
        return num1/num2 + countOperations(num2, num1%num2);
    }
};