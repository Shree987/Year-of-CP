/*
Author : Shreeraksha R Aithal
Problem name : Length of Last Word
Problem link : https://leetcode.com/problems/length-of-last-word/
Difficulty : Easy
Tags : String
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size()-1, k = 0;
        while(n>=0 && s[n] == ' ')  n--;
        k = n;
        while(n>=0 && s[n] != ' ')  n--;
        return k-n;
    }
};