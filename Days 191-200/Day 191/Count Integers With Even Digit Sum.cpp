/*
Author : Shreeraksha R Aithal
Problem name : Count Integers With Even Digit Sum
Problem link : https://leetcode.com/problems/count-integers-with-even-digit-sum/
Difficulty : Easy
Tags : Math, Simulation
*/

class Solution {
public:
    int countEven(int num) {
        int count = 0;
        for(int i = 1; i <= num; i++){
            int sum = 0, m = i;
            while(m > 0){
                sum += m%10;
                m /= 10;
            }
            if(sum%2 == 0)      count++;
        }
        return count;
    }
};