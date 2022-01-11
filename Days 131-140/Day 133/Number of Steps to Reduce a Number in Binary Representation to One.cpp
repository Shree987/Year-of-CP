/*
Author : Shreeraksha R Aithal
Problem name : Number of Steps to Reduce a Number in Binary Representation to One
Problem link : https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/
Difficulty : Medium
Tags : Bit Manipulation, String
*/

class Solution {
public:
    int numSteps(string s) {
        int flip = 0, index = s.size()-1, count = 0;
        while(index > 0){
            if(flip%2 == 1){
                s[index] = (s[index] == '0' ? '1' : '0');
                if(s[index] == '1')     flip--;
            }
            if(s[index] == '0'){
                index--;
                count++;
            }
            else{
                flip++;
                count+=2;
                index--;
            }
        }
        return count+flip;
    }
};