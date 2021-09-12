/*
Author : Shreeraksha R Aithal
Problem name : Rabbits in Forest
Problem link : https://leetcode.com/problems/rabbits-in-forest/
Difficulty : Medium
Tags : Hash Table, Greedy, Math
*/

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> mp;
        int cnt = 0;
        for(auto num : answers){
            mp[num+1]++;
        }
        for(auto p : mp){
            cnt += p.first*((p.first-1 + p.second)/p.first);
        }
        return cnt;
    }
};