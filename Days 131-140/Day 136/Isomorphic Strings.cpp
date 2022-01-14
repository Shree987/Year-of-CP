/*
Author : Shreeraksha R Aithal
Problem name : Isomorphic Strings
Problem link : https://leetcode.com/problems/isomorphic-strings/
Difficulty : Easy
Tags : Hash Table, String
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mp1, mp2;
        for(int i = 0; i < s.size(); i++){
            if((mp1.find(s[i]) == mp1.end()) xor (mp2.find(t[i]) == mp2.end())){
                return false;
            }
            if(mp1.find(s[i]) == mp1.end()){
                mp1[s[i]] = t[i];
                mp2[t[i]] = s[i];
            }
            else{
                if(mp1[s[i]] != t[i] || mp2[t[i]] != s[i])  return false;
            }
        }
        return true;
    }
};