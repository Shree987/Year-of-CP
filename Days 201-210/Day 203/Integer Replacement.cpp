/*
Author : Shreeraksha R Aithal
Problem name : Integer Replacement
Problem link : https://leetcode.com/problems/integer-replacement/
Difficulty : Medium
Tags : Bit Manipulation, Dynamic Programming, Greedy, Memoization
*/

class Solution {
public:
    int integerReplacement(int n) {
        if(n <= 3)      return n-1;
        int sum = 0;
        if(n%2 == 0){
            while(n%2 == 0){
                n /= 2;
                sum++;
            }            
        }
        else if((n-3)%4 == 0){
            n = 1 + (n-3)/4;
            sum = 3;
        }
        else{
            n = (n-1)/4;
            sum = 3;
        }
        return sum + integerReplacement(n);
    }
};