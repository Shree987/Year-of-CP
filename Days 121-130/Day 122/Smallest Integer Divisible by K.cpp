/*
Author : Shreeraksha R Aithal
Problem name : Smallest Integer Divisible by K
Problem link : https://leetcode.com/problems/smallest-integer-divisible-by-k/
Difficulty : Medium
Tags : Hash Table, Math
*/

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2 == 0)    return -1;
        int num = 0, count = 0;
        while(count <= k){
            num = ((num*10) + 1)%k;
            count++;
            if(num == 0)    break;
        }
        if(num > 0)     count = -1;
        return count;
    }
};