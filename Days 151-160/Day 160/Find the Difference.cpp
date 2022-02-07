/*
Author : Shreeraksha R Aithal
Problem name : Find the Difference
Problem link : https://leetcode.com/problems/find-the-difference/
Difficulty : Easy
Tags : Bit Manipulation, Hash Table, Sorting, String
*/

class Solution {
public:
    char findTheDifference(string s, string t) {
        int freq[27] = {0};
        freq[26] = 25;
        for(int i = 0; i < t.size(); i++){
            freq[t[i]-'a']++;
        }
        for(int i = 0; i < s.size(); i++){
            freq[s[i]-'a']--;
            while(freq[freq[26]] == 0)      freq[26]--;
        }
        while(freq[freq[26]] == 0)      freq[26]--;
        return (char)('a' + freq[26]);
    }
};