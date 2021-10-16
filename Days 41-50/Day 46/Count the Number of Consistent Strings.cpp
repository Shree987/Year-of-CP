/*
Author : Shreeraksha R Aithal
Problem name : Count the Number of Consistent Strings
Problem link : https://leetcode.com/problems/count-the-number-of-consistent-strings/
Difficulty : Easy
Tags : Array, Bit Manipulation, Hash Table, String
*/

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> dp(26, true);
        for(auto c : allowed){
            dp[c-'a'] = false;
        }
        int count = 0, check;
        for(auto s : words){
            check = 1;
            for(auto c : s){
                if(dp[c-'a']){
                    check = 0;
                    break;
                }
            }
            count += check;
        }
        return count;
    }
};