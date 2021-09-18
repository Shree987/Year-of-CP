/*
Author : Shreeraksha R Aithal
Problem name : Escape The Ghosts
Problem link : https://leetcode.com/problems/escape-the-ghosts/
Difficulty : Medium
Tags : Array, Math
*/

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int dist = abs(target[0]) + abs(target[1]);
        for(auto coord : ghosts){
            if(abs(coord[0]-target[0]) + abs(coord[1]-target[1]) <= dist)   return false;
        }
        return true;
    }
};