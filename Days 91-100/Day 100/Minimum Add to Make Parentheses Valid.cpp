/*
Author : Shreeraksha R Aithal
Problem name : Minimum Add to Make Parentheses Valid
Problem link : https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
Difficulty : Medium
Tags : Greedy, Stack, String
*/

class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0, sum = 0;
        for(auto c : s){
            if(c == '(')    count++;
            else{
                if(count == 0)      sum++;
                else    count--;
            }
        }
        return sum + count;
    }
};