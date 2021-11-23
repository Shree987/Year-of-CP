/*
Author : Shreeraksha R Aithal
Problem name : Vowels of All Substrings
Problem link : https://leetcode.com/problems/vowels-of-all-substrings/
Difficulty : Medium
Tags : Combinatorics, Dynamic Programming, Math, String
*/

class Solution {
public:
    long long countVowels(string word) {
        long long ind, sum = 0;
        for(int i = 0; i < word.size(); i++){
            if(!(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u')) continue;
            ind = i+1;
            sum += ind*(word.size()-ind+1);
        }
        return sum;
    }
};