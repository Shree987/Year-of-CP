/*
Author : Shreeraksha R Aithal
Problem name : Word Pattern
Problem link : https://leetcode.com/problems/word-pattern/
Difficulty : Easy
Tags : Hash Table, String
*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> st(26, "");
        map<string, int> mp;
        int i, j = 0;
        for(i = 0; i < pattern.size(); i++){
            int k = j;
            if(j >= s.size())       return false;
            while(k < s.size() && s[k] != ' ')  k++;
            string str = s.substr(j, k-j);
            if(str == "")       return false;
            if(st[pattern[i]-'a'] == ""){
                if(mp.find(str) != mp.end())    return false;
                mp[str] = pattern[i]-'a';
                st[pattern[i]-'a'] = str;
            }
            else{
                if(mp.find(str) == mp.end())    return false;
                if(mp[str] != (pattern[i]-'a'))     return false;                
            }
            j = k+1;
        }
        return (j >= s.size());
    }
};