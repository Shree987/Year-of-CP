/*
Author : Shreeraksha R Aithal
Problem name : Smallest Subsequence of Distinct Characters
Problem link : https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
Difficulty : Medium
Tags : Greedy, Monotonic Stack, Stack, String
*/

class Solution {
public:
    string smallestSubsequence(string s) {
        string ans;
        int freq[26] = {0}, vis[26] = {0};
        for(int i = 0; i < s.size(); i++){
            freq[s[i]-'a']++;
        }
        ans.push_back(s[0]);
        vis[s[0]-'a'] = 1;
        freq[s[0]-'a']--;
        for(int i = 1; i < s.size(); i++){          
            freq[s[i]-'a']--;
            if(vis[s[i]-'a'] == 0){
                while(ans.size()>0 && ans.back() > s[i] && freq[ans.back()-'a'] > 0){
                    vis[ans.back()-'a']=0;
                    ans.pop_back();
                }
                ans.push_back(s[i]);
                vis[s[i]-'a'] = 1;
            }
        }
        return ans;
    }
};