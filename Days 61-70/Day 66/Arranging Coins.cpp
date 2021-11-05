/*
Author : Shreeraksha R Aithal
Problem name : Arranging Coins
Problem link : https://leetcode.com/problems/arranging-coins/
Difficulty : Easy
Tags : Binary Search, Math
*/

class Solution {
public:
    int arrangeCoins(int n) {
        return floor((-1 + sqrt(1 + 8L*n))/2);
    }
};