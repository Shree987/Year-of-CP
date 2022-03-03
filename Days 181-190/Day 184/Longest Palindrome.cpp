/*
Author : Shreeraksha R Aithal
Problem name : Longest Palindrome
Problem link : https://leetcode.com/problems/longest-palindrome/
Difficulty : Easy
Tags : Greedy, Hash Table, String
*/

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> st;
        int count = 0, sum = 0;
        for(auto &k : s){
            if(st.find(k) == st.end()){
                count++;
                st.insert(k);
            }
            else{
                st.erase(k);
                count--;
                sum+=2;
            }
        }
        if(count > 0)       sum++;
        return sum;
    }
};