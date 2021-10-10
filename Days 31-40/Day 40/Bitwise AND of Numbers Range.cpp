/*
Author : Shreeraksha R Aithal
Problem name : Bitwise AND of Numbers Range
Problem link : https://leetcode.com/problems/bitwise-and-of-numbers-range/
Difficulty : Medium
Tags : Bit Manipulation
*/

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == right)   return left;
        if(floor(log2(left)) != floor(log2(right)))       return 0;
        int answer = left;
        while(left < right){
            left++;
            answer = answer & left;
        }
        return answer;
    }
};