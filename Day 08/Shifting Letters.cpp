/*
Author : Shreeraksha R Aithal
Problem name : Shifting Letters
Problem link : https://leetcode.com/problems/shifting-letters/
Difficulty : Medium
Tags : Array, String
*/

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int diff = 0, index;
        for(index = s.size()-1; index >= 0; index--){
            diff = (diff+shifts[index])%26;
            s[index] = char('a' + (s[index]-'a' + diff)%26);
        }
        return s;
    }
};