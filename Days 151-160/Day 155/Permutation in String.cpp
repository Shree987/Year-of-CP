/*
Author : Shreeraksha R Aithal
Problem name : Permutation in String
Problem link : https://leetcode.com/problems/permutation-in-string/
Difficulty : Medium
Tags : Hash Table, Sliding Window, String, Two Pointers
*/

class Solution {
    bool check(vector<int> &v){
        for(int i = 0; i < 26; i++){
            if(v[i] != 0)       return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26, 0);
        if(s1.size() > s2.size())     return false;
        int i, count = 0, k = s1.size();
        for(auto c : s1){
            freq[c-'a']++;
        }
        for(i = 0; i < s1.size(); i++){
            freq[s2[i]-'a']--;
        }
        if(check(freq))     return true;
        while(i < s2.size()){
            freq[s2[i]-'a']--;
            freq[s2[i-k]-'a']++;
            if(check(freq)){
                return true;
            }
            i++;
        }
        return false;
    }
};