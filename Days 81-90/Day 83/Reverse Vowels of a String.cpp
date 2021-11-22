/*
Author : Shreeraksha R Aithal
Problem name : Reverse Vowels of a String
Problem link : https://leetcode.com/problems/reverse-vowels-of-a-string/
Difficulty : Easy
Tags : String, Two Pointer
*/

class Solution {
    bool isvowel(char c){
        c = tolower(c);
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size()-1;
        while(i<j){
            while(i<j && !isvowel(s[i]))    i++;
            while(i<j && !isvowel(s[j]))    j--;
            if(i<j){
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};