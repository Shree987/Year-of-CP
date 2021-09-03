/*
Author : Shreeraksha R Aithal
Problem name : Custom Sort String
Problem link : https://leetcode.com/problems/custom-sort-string/
Difficulty : Medium
Tags : Hash Table, Sorting, String
*/

class Solution {
public:
    string customSortString(string order, string s) {
        int index = 0, freq[26] = {0};
        for(auto c : s)     freq[c-'a']++;
        for(auto c : order){
            while(freq[c-'a'] > 0){
                s[index++] = c;
                freq[c-'a']--;
            }
        }
        for(char c = 'a'; c <= 'z'; c++){
            while(freq[c-'a'] > 0){
                s[index++] = c;
                freq[c-'a']--;
            }
        }
        return s;
    }
};