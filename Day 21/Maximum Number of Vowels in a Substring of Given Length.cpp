/*
Author : Shreeraksha R Aithal
Problem name : Maximum Number of Vowels in a Substring of Given Length
Problem link : https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
Difficulty : Medium
Tags : Sliding Window, String
*/

class Solution {
public:
    int isvowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ? 1 : 0;
    }
    int maxVowels(string s, int k) {
        int cnt = 0, sum = 0, ind;
        for(ind = 0; ind < s.size(); ind++){
            if(ind < k){
                sum += isvowel(s[ind]);
            }
            else{
                sum += isvowel(s[ind]) - isvowel(s[ind-k]);
            }
            cnt = max(cnt, sum);
        }
        return cnt;
    }
};