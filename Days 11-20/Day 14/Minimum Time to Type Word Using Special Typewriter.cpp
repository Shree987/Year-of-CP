/*
Author : Shreeraksha R Aithal
Problem name : Minimum Time to Type Word Using Special Typewriter
Problem link : https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/
Difficulty : Easy
Tags : Greedy, String
*/

class Solution {
public:
    int minTimeToType(string word) {
        char start = 'a';
        int count = 0;
        for(auto c : word){
            int temp = abs(c - start);
            count += min(temp, 26-temp) + 1;
            start = c;
        }
        return count;
    }
};