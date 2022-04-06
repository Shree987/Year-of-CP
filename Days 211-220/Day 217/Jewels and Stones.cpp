/*
Author : Shreeraksha R Aithal
Problem name : Jewels and Stones
Problem link : https://leetcode.com/problems/jewels-and-stones/
Difficulty : Easy
Tags : Hash Table, String
*/

class Solution {
    int hash(char c){
        if(c<='z' && c>='a')        return (c-'a');
        return 26+(c-'A');
    }
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<bool> Jewel (52, false);
        for(auto &c : jewels)       Jewel[hash(c)] = true;
        int count = 0;
        for(auto &c : stones){
            if(Jewel[hash(c)])        count++;
        }
        return count;
    }
};