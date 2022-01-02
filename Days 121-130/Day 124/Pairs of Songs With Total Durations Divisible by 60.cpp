/*
Author : Shreeraksha R Aithal
Problem name : Pairs of Songs With Total Durations Divisible by 60
Problem link : https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
Difficulty : Medium
Tags : Array, Counting, Hash Table
*/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0;
        vector<int> freq(61, 0);
        for(auto k : time){
            count += freq[60 - k%60];
            freq[k%60]++;
            if(k%60 == 0)   freq[60]++;
        }
        return count;
    }
};