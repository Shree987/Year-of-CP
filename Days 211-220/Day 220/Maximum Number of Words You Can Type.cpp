/*
Author : Shreeraksha R Aithal
Problem name : Maximum Number of Words You Can Type
Problem link : https://leetcode.com/problems/maximum-number-of-words-you-can-type/
Difficulty : Easy
Tags : Hash Table, String
*/

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int count = 0, i, j;
        bool usesBroken;
        vector<bool> broken(26, false);
        for(auto &ch : brokenLetters){
            broken[ch-'a'] = true;
        }
        i = 0;
        usesBroken = false;
        while(i < text.size()){
            if(text[i] == ' '){
                if(!usesBroken)     count++;
                usesBroken = false;
            }
            else{
                if(broken[text[i]-'a'])     usesBroken = true;
            }
            i++;
        }
        if(!usesBroken)     count++;
        return count;
    }
};