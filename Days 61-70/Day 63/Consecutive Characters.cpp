/*
Author : Shreeraksha R Aithal
Problem name : Consecutive Characters
Problem link : https://leetcode.com/problems/consecutive-characters/
Difficulty : Easy
Tags : String
*/

class Solution {
public:
    int maxPower(string s) {
        int m = 0, i = 0;
        while(i < s.size()){
            int j = i;
            while(j<s.size() && s[j]==s[i])     j++;
            m = max(m, j-i);
            i = j;
        }
        return m;
    }
};