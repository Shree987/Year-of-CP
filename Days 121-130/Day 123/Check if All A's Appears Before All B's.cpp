/*
Author : Shreeraksha R Aithal
Problem name : Check if All A's Appears Before All B's
Problem link : https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/
Difficulty : Easy
Tags : String
*/

class Solution {
public:
    bool checkString(string s) {
        int i = 0;
        while(i < s.size() && s[i] == 'a')      i++;
        while(i < s.size() && s[i] == 'b')      i++;
        return i == s.size();
    }
};