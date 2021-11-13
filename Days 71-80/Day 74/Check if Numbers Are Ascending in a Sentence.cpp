/*
Author : Shreeraksha R Aithal
Problem name : Check if Numbers Are Ascending in a Sentence
Problem link : https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/
Difficulty : Easy
Tags : String
*/

class Solution {
public:
    bool areNumbersAscending(string s) {
        int val, i, n = s.size(), num = -1;
        for(i = 0; i < n; i++){
            if(!isdigit(s[i]))  continue;
            val = 0;
            while(i<n && isdigit(s[i])){
                val = val*10 + (s[i]-'0');
                i++;
            }
            if(val <= num)      return false;
            num = val;            
        }
        return true;
    }
};