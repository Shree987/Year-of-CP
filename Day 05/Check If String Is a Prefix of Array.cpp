/*
Author : Shreeraksha R Aithal
Problem name : Check If String Is a Prefix of Array
Problem link : https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/
Difficulty : Easy
Tags : Array, String
*/

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int i = 0, j = 0, k = 0;
        while(i < s.size() && k < words.size()){
            while(i<s.size() && j < words[k].size()){
                if(words[k][j] != s[i])     return false;
                j++;
                i++;
            }
            if(j < words[k].size())     return false;
            j = 0;
            k++;
        }
        return j == 0 && i == s.size();
    }
};