/*
Author : Shreeraksha R Aithal
Problem name : Break a Palindrome
Problem link : https://leetcode.com/problems/break-a-palindrome/
Difficulty : Medium
Tags : Greedy, String
*/

class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size() == 1)  return "";
        int i = 0, len = palindrome.size();
        while(i < len-i-1){
            if(palindrome[i] == 'a')    i++;
            else{
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[len-1] = 'b';
        return palindrome;
    }
};