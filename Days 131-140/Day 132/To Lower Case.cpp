/*
Author : Shreeraksha R Aithal
Problem name : To Lower Case
Problem link : https://leetcode.com/problems/to-lower-case/
Difficulty : Easy
Tags : String
*/

class Solution {
public:
    string toLowerCase(string s) {
        for(int i = 0; i < s.size(); i++){
            if(s[i]>='A' && s[i] <= 'Z')     s[i] = (s[i]-'A'+'a');
        }
        return s;
    };
};