/*
Author : Shreeraksha R Aithal
Problem name : Replace All ?'s to Avoid Consecutive Repeating Characters
Problem link : https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/
Difficulty : Medium
Tags : String
*/

class Solution {
public:
    string modifyString(string s) {
        for(int i = 0, n = s.size(); i < n; i++){
            if(s[i] == '?'){                
                if((i == 0 || s[i-1] != 'a') && (i == n-1 || s[i+1] != 'a')){
                    s[i] = 'a';
                }
                else if((i == 0 || s[i-1] != 'b') && (i == n-1 || s[i+1] != 'b')){
                    s[i] = 'b';
                }
                else    s[i] = 'c';
            }
        }
        return s;
    }
};