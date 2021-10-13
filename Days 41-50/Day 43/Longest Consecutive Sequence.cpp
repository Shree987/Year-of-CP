/*
Author : Shreeraksha R Aithal
Problem name : Longest Consecutive Sequence
Problem link : https://leetcode.com/problems/longest-consecutive-sequence/
Difficulty : Medium
Tags : Array, Hash Table, Union Find
*/

class Solution {
    map<int, pair<int,int>> mp;
    pair<int,int> p;
    
    int findParent(int num){
        if(mp[num].second == num)    return num;
        return mp[num].second = findParent(mp[num].second);
    }
    
public:
    int longestConsecutive(vector<int>& nums) {
        int answer = 0;
        for(auto k : nums){
            if(mp.find(k) == mp.end()){
                p = {1, k};
                if(mp.find(k-1) != mp.end()){
                    p.first += mp[k-1].first;
                    mp[findParent(k-1)].second = k;
                }
                if(mp.find(k+1) != mp.end()){
                    p.second = findParent(k+1);
                    mp[p.second].first += p.first;
                }
                mp[k] = p;
            }
        }
        for(auto m : mp){
            answer = max(answer, m.second.first);
        }
        return answer;
    }
};