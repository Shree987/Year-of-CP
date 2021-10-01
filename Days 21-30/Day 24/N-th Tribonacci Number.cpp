/*
Author : Shreeraksha R Aithal
Problem name : N-th Tribonacci Number
Problem link : https://leetcode.com/problems/n-th-tribonacci-number/
Difficulty : Easy
Tags : Dynamic Programming, Math, Memoization
*/

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0)  return 0;
        if(n <= 2)  return 1;
        int ind, arr[38] = {0};
        arr[0] = 0;
        arr[1] = arr[2] = 1;
        for(ind = 3; ind <= n; ind++){
            arr[ind] = arr[ind-1] + arr[ind-2] + arr[ind-3];            
        }
        return arr[n];
    }
};