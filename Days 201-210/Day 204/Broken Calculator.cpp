/*
Author : Shreeraksha R Aithal
Problem name : Broken Calculator
Problem link : https://leetcode.com/problems/broken-calculator/
Difficulty : Medium
Tags : Greedy, Math
*/

class Solution {
public:
    int brokenCalc(int startValue, int target) {        
        int count = 0;
        while(target > startValue){
            if(target%2 == 1){
                count++;
                target++;
            }
            count++;
            target /= 2;
        }
        return count+startValue-target;
    }
};