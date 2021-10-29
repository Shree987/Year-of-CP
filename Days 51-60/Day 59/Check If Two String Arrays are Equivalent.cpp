/*
Author : Shreeraksha R Aithal
Problem name : Check If Two String Arrays are Equivalent
Problem link : https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
Difficulty : Easy
Tags : Array, String
*/

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
        while(i1 < word1.size() && j1 < word2.size()){
            if(word1[i1][i2] != word2[j1][j2])  return false;
            i2++;
            j2++;
            if(i2 == word1[i1].size()){
                i1++;
                i2 = 0;
            }
            if(j2 == word2[j1].size()){
                j1++;
                j2 = 0;
            }
        }
        return (i1 == word1.size() && j1 == word2.size());
    }
};