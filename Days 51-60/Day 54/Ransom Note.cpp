/*
Author : Shreeraksha R Aithal
Problem name : Ransom Note
Problem link : https://leetcode.com/problems/ransom-note/
Difficulty : Easy
Tags : Counting, Hash Table, String
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freq[26] = {0};
        if(ransomNote.size() > magazine.size())   return false;
        for(int i = 0; i < magazine.size(); i++){
            freq[magazine[i]-'a']++;
            if(i < ransomNote.size())   freq[ransomNote[i]-'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(freq[i] < 0)     return false;
        }
        return true;
    }
};