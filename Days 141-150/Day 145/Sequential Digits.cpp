/*
Author : Shreeraksha R Aithal
Problem name : Sequential Digits
Problem link : https://leetcode.com/problems/sequential-digits/
Difficulty : Medium
Tags : Enumeration
*/

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for(int num, digit, i = 1; i<=9; i++){
            num = 0;
            digit = i;
            while(num <= high && digit<10){
                num = num*10 + digit;
                if(low<=num && high>=num)       res.push_back(num);
                digit++;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};