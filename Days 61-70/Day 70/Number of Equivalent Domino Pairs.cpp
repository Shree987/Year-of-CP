/*
Author : Shreeraksha R Aithal
Problem name : Number of Equivalent Domino Pairs
Problem link : https://leetcode.com/problems/number-of-equivalent-domino-pairs/
Difficulty : Easy
Tags : Array, Counting, Hash Table
*/

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>, int> mp;
        int answer = 0;
        for(int i = 0; i < dominoes.size(); i++){
            pair p = {dominoes[i][0], dominoes[i][1]};
            if(dominoes[i][0] > dominoes[i][1]){
                swap(p.first, p.second);
            }
            answer += mp[p];
            mp[p]++;
        }
        return answer;
    }
};