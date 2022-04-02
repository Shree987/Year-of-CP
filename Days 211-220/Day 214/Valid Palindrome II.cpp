/*
Author : Shreeraksha R Aithal
Problem name : Valid Palindrome II
Problem link : https://leetcode.com/problems/valid-palindrome-ii/
Difficulty : Easy
Tags : Greedy, String, Two Pointers
*/

class Solution {
    map<pair<int,int>, bool> mp;
    bool isPalindrome(string s, int left, int right){
        while(left < right){
            if(s[left] != s[right])     return false;
            left++;
            right--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while(left < right){
            if(s[left] != s[right]){
                return (isPalindrome(s, left, right-1) || isPalindrome(s, left+1, right));
            }
            left++;
            right--;
        }
        return true;
    }
};