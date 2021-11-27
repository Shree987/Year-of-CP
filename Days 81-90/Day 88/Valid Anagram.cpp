/*
Author : Shreeraksha R Aithal
Problem name : Valid Anagram
Problem link : https://leetcode.com/problems/valid-anagram/
Difficulty : Easy
Tags : Hash Table, String, Sorting
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.size() != s.size())    return false;
        vector<int> freq(26, 0);
        for(int i = 0; i < t.size(); i++){
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0)    return false;
        }
        return true;
    }
};