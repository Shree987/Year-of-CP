/*
Author : Shreeraksha R Aithal
Problem name : Reverse String
Problem link : https://leetcode.com/problems/reverse-string/
Difficulty : Easy
Tags : Recursion, String, Two Pointer
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size()-1;
        while(i<j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};