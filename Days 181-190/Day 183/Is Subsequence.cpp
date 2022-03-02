/*
Author : Shreeraksha R Aithal
Problem name : Is Subsequence
Problem link : https://leetcode.com/problems/is-subsequence/
Difficulty : Easy
Tags : Dynamic Programming, String, Two Pointers
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ind1 = 0, ind2 = 0;
        while(ind1 < s.size() && ind2 < t.size()){
            if(s[ind1] == t[ind2])      ind1++;
            ind2++;
        }
        return (ind1 == s.size());
    }
};