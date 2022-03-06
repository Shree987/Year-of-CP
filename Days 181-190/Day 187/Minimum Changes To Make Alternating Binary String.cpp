/*
Author : Shreeraksha R Aithal
Problem name : Minimum Changes To Make Alternating Binary String
Problem link : https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/
Difficulty : Easy
Tags : String
*/

class Solution {
public:
    int minOperations(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            if(i%2 == s[i]-'0')     count++;
        }
        return min(count + 0UL, s.size()-count);
    }
};