/*
Author : Shreeraksha R Aithal
Problem name : Check Whether Two Strings are Almost Equivalent
Problem link : https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/
Difficulty : Easy
Tags : String
*/

class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int arr[26] = {0};
        for(int i = 0; i < word1.size(); i++){
            arr[word1[i]-'a']++;
            arr[word2[i]-'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(arr[i] > 3 || arr[i] < -3)   return false;
        }
        return true;
    }
};