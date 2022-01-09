/*
Author : Shreeraksha R Aithal
Problem name : Detect Capital
Problem link : https://leetcode.com/problems/detect-capital/
Difficulty : Easy
Tags : String
*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        if(islower(word[0])){
            for(int i = 1; i < word.size(); i++){
                if(isupper(word[i]))    return false;
            }
            return true;
        }
        for(int i = 2;i < word.size(); i++){
            if(isupper(word[i]) != isupper(word[1]))    return false;
        }
        return true;
    }
};