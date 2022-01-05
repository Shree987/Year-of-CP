/*
Author : Shreeraksha R Aithal
Problem name : Excel Sheet Column Number
Problem link : https://leetcode.com/problems/excel-sheet-column-number/
Difficulty : Easy
Tags : Math, String
*/

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int num = 0;
        for(auto c : columnTitle){
            num = num*26 + (c-'A'+1);
        }
        return num;
    }
};