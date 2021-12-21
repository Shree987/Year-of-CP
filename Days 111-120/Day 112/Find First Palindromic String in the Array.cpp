/*
Author : Shreeraksha R Aithal
Problem name : Find First Palindromic String in the Array
Problem link : https://leetcode.com/problems/find-first-palindromic-string-in-the-array/
Difficulty : Easy
Tags : String
*/

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto str : words){
            for(int i = 0, j = str.size()-1; i<=j; i++, j--){
                if(str[i] != str[j])        break;
                if(i == j || i+1 == j)      return str;
            }
        }
        return "";
    }
};