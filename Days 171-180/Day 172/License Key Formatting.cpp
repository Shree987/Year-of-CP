/*
Author : Shreeraksha R Aithal
Problem name : License Key Formatting
Problem link : https://leetcode.com/problems/license-key-formatting/
Difficulty : Easy
Tags : String
*/

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string str = "";
        int m = 0;
        for(int i = s.size()-1; i>=0; i--){
            if(s[i] == '-')     continue;
            str.push_back(toupper(s[i]));
            m++;
            if(m == k){
                str.push_back('-');
                m = 0;
            }
        }
        if(m == 0 && str.size()>0)      str.pop_back();
        reverse(str.begin(), str.end());
        return str;
    }
};