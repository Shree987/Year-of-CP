/*
Author : Shreeraksha R Aithal
Problem name : Find All Anagrams in a String
Problem link : https://leetcode.com/problems/find-all-anagrams-in-a-string/
Difficulty : Medium
Tags : Hash Table, Sliding Window, String
*/

class Solution {
    bool check(vector<int> &v){
        for(int i = 0; i < 26; i++){
            if(v[i] != 0)       return false;
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq(26, 0), ans;
        if(p.size() > s.size())     return ans;
        int i, count = 0, k = p.size();
        for(auto c : p){
            freq[c-'a']++;
        }
        for(i = 0; i < p.size(); i++){
            freq[s[i]-'a']--;
        }
        if(check(freq))     ans.push_back(0);
        while(i < s.size()){
            freq[s[i]-'a']--;
            freq[s[i-k]-'a']++;
            if(check(freq)){
                ans.push_back(i-k+1);
            }
            i++;
        }
        return ans;
    }
};