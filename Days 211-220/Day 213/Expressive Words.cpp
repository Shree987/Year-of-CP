/*
Author : Shreeraksha R Aithal
Problem name : Expressive Words
Problem link : https://leetcode.com/problems/expressive-words/
Difficulty : Medium
Tags : Array, String, Two Pointers
*/

class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int count = 0, x, y, j, i;
        for(auto &str : words){
            i = 0, x = 0;
            while(i<s.size() && x<str.size()){
                if(s[i] != str[x])      break;
                j = i;
                while(j<s.size() && s[j] == s[i])       j++;
                y = x;
                while(y<str.size() && str[y] == str[x])       y++;
                j -= i;
                y -= x;
                if((y > j) || (y < j && j == 2))   break;
                i += j;
                x += y;
            }
            if(i == s.size() && x == str.size())         count++;
        }
        return count;
    }
};