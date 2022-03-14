/*
Author : Shreeraksha R Aithal
Problem name : Find Common Characters
Problem link : https://leetcode.com/problems/find-common-characters/
Difficulty : Easy
Tags : Array, Hash Table, String
*/

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> total(26, INT_MAX);
        for(int j, i = 0; i < words.size(); i++){
            vector<int> cnt(26, 0);
            for(j = 0; j < words[i].size(); j++){
                cnt[words[i][j]-'a']++;
            }
            for(j = 0; j < 26; j++){
                total[j] = min(total[j], cnt[j]);
            }
        }
        vector<string> ans;
        string s = "-";
        for(int i = 0; i < 26; i++){
            s = 'a'+i;
            while(total[i] > 0){
                ans.push_back(s);
                total[i]--;
            }
        }
        return ans;
    }
};